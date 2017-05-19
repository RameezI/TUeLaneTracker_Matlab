
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%% FIND LANE CANDITATES BY MAKING A HISTORGRAM WITH PER_PIXEL
%% GRADIENT AND INTERCEPT AND THEN FIND PEAKS
%% USE VP COORDINATE SYSTEM
%%       
%%
%% 
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [ msg ] = find_Lane_Candidates(Likelihoods, Templates)
    
    
    %% Required Interface
    global STATE_READY STATE_ERROR
    global LANE_CONF_THRESHOLD RES_VH CM_TO_PIXEL 
    global OBS_NEG_NOMIN OBS_NEG_NORMA LaneBoundaryModels NegLaneBoundaryModel   
    global HORIZON_HISTOGRAM_STEP HORIZON_HISTOGRAM_BINS  
    global BASE_HISTOGRAM_STEP    BASE_HISTOGRAM_BINS
    global VP_RANGE_H LANE_OFFSETS_BINS LANE_FILTER_OFFSET_V VP_FILTER_OFFSET_V
    global LANE_FILTER LANE_TRANSITION LANE_PRIOR  
    global LANE_WIDTH INT_HIST_LANE_PROB INT_HIST_VP_PROB %% the Lane intersection observations histograms
    
    
    
    %% Provided Interface 
    %%  ARM LOOP %%
    global LANE_BOUNDARIES    
     
    
    halfImage = int16(RES_VH(1)/2);
                 
    bottom  = int16(LANE_FILTER_OFFSET_V);     %% keep fixed regardless of the FOV or use, keeps the cm-to-pixel ratio more stable
    
    horizon = int16(VP_FILTER_OFFSET_V);       %% use an offest from horizon to make intersections more pronounced
   
   Focussed_TOT_P=  Likelihoods.TOT_MAX_FOCUSED;

   %%In center coordinate System
    start_row =   halfImage - size(Focussed_TOT_P,1);
    start_col  = int16(-320);
    

    Lane_Int_Base     = zeros(size(Focussed_TOT_P,1)*size(Focussed_TOT_P,2),1);
    
    Lane_Int_Purview  = zeros(size(Focussed_TOT_P,1)*size(Focussed_TOT_P,2),1);
    
    Lane_Int_Weights  = zeros(size(Focussed_TOT_P,1)*size(Focussed_TOT_P,2),1);
     
    Templates.DEPTHSqr= Templates.DEPTH.^2;
   
    Index =1;
    
    
    
    for row_current = 0: (size(Focussed_TOT_P,1)-1)

        for col_current = 0: (size(Focussed_TOT_P,2)-1)
            
            prob        =  Focussed_TOT_P(row_current+1, col_current+1);
        
            if(prob>0)

                x        =  int16(start_col +col_current);
                y        = -int16(start_row +row_current);
       
                depthSqr    =  Templates.DEPTHSqr(row_current+1, col_current+1);

                tanGradient = Likelihoods.GRADIENT_DIR_TOT_MAX(row_current+1, col_current+1);
                
                Lane_Int_Base_tmp     =  ( double(bottom- y) *2^7  )./single(tanGradient)  +  single(x);
                Lane_Int_Purview_tmp  =  ( double(horizon-y) *2^7  )./single(tanGradient)  +  single(x);                
                Lane_Int_Weights_tmp  =   single(prob)*depthSqr* 2^-7;
                
                
                if ( Lane_Int_Base_tmp > BASE_HISTOGRAM_BINS(1)-BASE_HISTOGRAM_STEP/2    &&   Lane_Int_Base_tmp < BASE_HISTOGRAM_BINS(end)+ BASE_HISTOGRAM_STEP/2)
                 
                    if (  Lane_Int_Purview_tmp > -VP_RANGE_H-HORIZON_HISTOGRAM_STEP/2    &&   Lane_Int_Purview_tmp < VP_RANGE_H+HORIZON_HISTOGRAM_STEP/2  )                

                             Lane_Int_Base(Index)      = Lane_Int_Base_tmp;                        
                             Lane_Int_Purview(Index)   = Lane_Int_Purview_tmp;
                             Lane_Int_Weights(Index)   = Lane_Int_Weights_tmp;

                             Index = Index+1;               
                    end
                end  
               
            end
            
            
        end
    end
    
    % Keep only valid Intersections
    Lane_Int_Purview   = Lane_Int_Purview(1:Index);
    Lane_Int_Base      = Lane_Int_Base(1:Index);
    Lane_Int_Weights   = Lane_Int_Weights(1:Index);

    

    %% Weighted Histogram over both dicretised Intersections
    %% APEX Process %%
    
    firstDim  = ceil( (Lane_Int_Purview - HORIZON_HISTOGRAM_BINS(1)  + (HORIZON_HISTOGRAM_STEP/2)) / HORIZON_HISTOGRAM_STEP  );  %% Purvew intersection discretised
    
    secondDim = ceil( (Lane_Int_Base  - BASE_HISTOGRAM_BINS(1)  + (BASE_HISTOGRAM_STEP/2)) / BASE_HISTOGRAM_STEP  );             %% Bottom intersection discretised

    firstDim(size(firstDim)+1)      = size(HORIZON_HISTOGRAM_BINS,2);
    secondDim(size(secondDim)+1)    = size(BASE_HISTOGRAM_BINS,2);
    
    INT_HIST_LANE_PROB =   accumarray( secondDim, [Lane_Int_Weights; 0] );
    
    INT_HIST_VP_PROB   =   accumarray( firstDim,  [Lane_Int_Weights; 0] );
    
    
    

    %% Normalize for Further Computation %%
    %% APEX Process %%
    
     INT_HIST_LANE_PROB = INT_HIST_LANE_PROB';
     INT_HIST_VP_PROB   = INT_HIST_VP_PROB';
     
     INT_HIST_LANE_PROB = INT_HIST_LANE_PROB / sum(INT_HIST_LANE_PROB,2);        
     INT_HIST_VP_PROB   = INT_HIST_VP_PROB   / sum(INT_HIST_VP_PROB,2);
     
     
     
     

    %% Predict Step %%
    %% APEX Process %%
      TEMP = imfilter( LANE_FILTER, LANE_TRANSITION, 'Replicate' );
      TEMP = int32( (single(TEMP) / single(sum(sum(TEMP))) ) *2^15);
      LANE_FILTER_TRANSITIONED = 0.5*TEMP +0.5*LANE_PRIOR ; 
      
    

    %% Update Step %%
    %% ARM LOOP %%
    
    best  = 0;
    for modelIdx = 1:size(LaneBoundaryModels,2)
        
              left  = LaneBoundaryModels(modelIdx).leftOffsetIdx;
              right = LaneBoundaryModels(modelIdx).rightOffsetIdx;
              width = (LANE_OFFSETS_BINS(left)+LANE_OFFSETS_BINS(right)) * 1/CM_TO_PIXEL;


              left_offset  = LANE_OFFSETS_BINS(left);
              right_offset = LANE_OFFSETS_BINS(right);


              likelihood_leftLaneBoundary =0;

                for idx=1:  size(LaneBoundaryModels(modelIdx).histogramBinIDs_leftBoundary,2)

                    ID           = LaneBoundaryModels(modelIdx).histogramBinIDs_leftBoundary(idx);
                    Value        = LaneBoundaryModels(modelIdx).histogramWeights_leftBoundary(idx);
                    likelihood_leftLaneBoundary = likelihood_leftLaneBoundary + INT_HIST_LANE_PROB(ID)*Value;               

                end
                
                
               likelihood_rightLaneBoundary =0;

                for idx=1:size(LaneBoundaryModels(modelIdx).histogramBinIDs_rightBoundary,2)

                    ID           = LaneBoundaryModels(modelIdx).histogramBinIDs_rightBoundary(idx);
                    Value        = LaneBoundaryModels(modelIdx).histogramWeights_rightBoundary(idx);
                    likelihood_rightLaneBoundary = likelihood_rightLaneBoundary + INT_HIST_LANE_PROB(ID)*Value;
                end
                
                NegLaneCorrelation= 0; 

                for idx=1:size(NegLaneBoundaryModel(modelIdx).histogramBinsID,2)
                     ID  = NegLaneBoundaryModel(modelIdx).histogramBinsID(idx);
                     NegLaneCorrelation = NegLaneCorrelation + INT_HIST_LANE_PROB(ID);                  
                end
                
                
                likelihood_NegLaneBoundary    =     OBS_NEG_NORMA * exp( -NegLaneCorrelation^2/OBS_NEG_NOMIN );
                conditional_prob              =    int32(likelihood_leftLaneBoundary * likelihood_rightLaneBoundary* likelihood_NegLaneBoundary * 2^15);

                % Update Lane Filter (only legitimate states)

                  LANE_FILTER(left,right) = LANE_FILTER_TRANSITIONED(left,right) * conditional_prob;
    
                % Already keep Track of Max Probable State

                  if best < LANE_FILTER(left,right)
                            
                     best       = LANE_FILTER(left,right);
                     LANE_MODEL = [left_offset right_offset likelihood_leftLaneBoundary likelihood_rightLaneBoundary];
                     LANE_WIDTH = width;
                               
                  end
    end
     
    LANE_MODEL
    LANE_WIDTH
      
    
    %% Normalize Lane Filter
       %% APEX PROCESS %%
        LANE_FILTER = int32( (single(LANE_FILTER) / single( sum(sum(LANE_FILTER)) )   )*2^15);


    %% Find the Lane Boundaries
       %% ARM %%
        LANE_BOUNDARIES = [ -LANE_MODEL(1)-BASE_HISTOGRAM_STEP/2 LANE_MODEL(2)-BASE_HISTOGRAM_STEP/2; -LANE_MODEL(1)+BASE_HISTOGRAM_STEP/2 LANE_MODEL(2)+BASE_HISTOGRAM_STEP/2; 0 0; 0 0; 100*LANE_MODEL(3) 100*LANE_MODEL(4)];
        LANE_BOUNDARIES(3,1) = (LANE_BOUNDARIES(1,1)+LANE_BOUNDARIES(2,2))/2;
        LANE_BOUNDARIES(3,2) = LANE_BOUNDARIES(3,1);
    
    
        
    
    %% Unstable Track ?
       %% ARM %%
    
    LANE_BOUNDARIES
    
    if LANE_BOUNDARIES(5,1) < LANE_CONF_THRESHOLD  || LANE_BOUNDARIES(5,2) < LANE_CONF_THRESHOLD
        msg = STATE_ERROR;
    else
        msg = STATE_READY;    
    end
    
    
end
