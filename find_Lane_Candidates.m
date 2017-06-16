
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
    global INT_HIST_LANE_PROB_int32 INT_HIST_VP_PROB_int32 
    
    SCALE_EXP_10 = int32(2^10);
    
    %% Provided Interface 
    %%  ARM LOOP %%
    global LANE_BOUNDARIES    
     

    halfImage       = int16(RES_VH(1)/2);
                 
    bottom          = int16(LANE_FILTER_OFFSET_V);     %% keep fixed regardless of the FOV or use, keeps the cm-to-pixel ratio more stable
    
    horizon         = int16(VP_FILTER_OFFSET_V);       %% use an offest from horizon to make intersections more pronounced
   
    Focussed_TOT_P  =  Likelihoods.TOT_MAX_FOCUSED;

   %%In center coordinate System
    start_row   =   halfImage - size(Focussed_TOT_P,1);
    start_col   =   int16(-320);
    

    Lane_Int_Base     = int32( zeros(size(Focussed_TOT_P,1)*size(Focussed_TOT_P,2),1) );
    
    Lane_Int_Purview  = int32( zeros(size(Focussed_TOT_P,1)*size(Focussed_TOT_P,2),1) );
    
    Lane_Int_Weights  = zeros(size(Focussed_TOT_P,1)*size(Focussed_TOT_P,2),1);
   
    Index =0;
    	
    
    
    for row_current = 0: (size(Focussed_TOT_P,1)-1)

        for col_current = 0: (size(Focussed_TOT_P,2)-1)
            
            prob        =  Focussed_TOT_P(row_current+1, col_current+1);
            tanGradient = Likelihoods.GRADIENT_DIR_TOT_MAX(row_current+1, col_current+1);
        	
            if(prob>0 && tanGradient~=0)
                
                x        =  int16(start_col +col_current);
                y        = -int16(start_row +row_current);
       
                depthSqr    =  Templates.DEPTH(row_current+1, col_current+1);

                Lane_Int_Base_tmp     =  idivide( int32(bottom- y) *2^7 * SCALE_EXP_10, int32(tanGradient) ) +  int32(x)*SCALE_EXP_10;
                Lane_Int_Purview_tmp  =  idivide( int32(horizon-y) *2^7 * SCALE_EXP_10, int32(tanGradient) ) +  int32(x)*SCALE_EXP_10;                
                
                Lane_Int_Weights_tmp  =   (int32(prob)* int32(depthSqr) );
                
                
                if (     Lane_Int_Base_tmp > SCALE_EXP_10*int32( BASE_HISTOGRAM_BINS(1) )   - idivide(SCALE_EXP_10*int32(BASE_HISTOGRAM_STEP), 2) ...
                   &&    Lane_Int_Base_tmp < SCALE_EXP_10*int32( BASE_HISTOGRAM_BINS(end) ) + idivide(SCALE_EXP_10*int32(BASE_HISTOGRAM_STEP), 2)  ...  
                   )
                 
                if (    Lane_Int_Purview_tmp > SCALE_EXP_10*int32(-VP_RANGE_H)  - idivide(SCALE_EXP_10*int32(HORIZON_HISTOGRAM_STEP) , 2) ...   
                   &&   Lane_Int_Purview_tmp < SCALE_EXP_10*int32(VP_RANGE_H)   + idivide(SCALE_EXP_10*int32(HORIZON_HISTOGRAM_STEP) , 2) ...
                   )                
                             Index = Index+1;
                             
                             Lane_Int_Base(Index)      = Lane_Int_Base_tmp;                        
                             Lane_Int_Purview(Index)   = Lane_Int_Purview_tmp;
                             Lane_Int_Weights(Index)   = Lane_Int_Weights_tmp;

                                           
                end
                end  
               
            end
            
            
        end
    end
  
    
    
    % Keep only valid Intersections
    Lane_Int_Purview   = int32(Lane_Int_Purview(1:Index));
    Lane_Int_Base      = int32(Lane_Int_Base(1:Index));
    Lane_Int_Weights   = int32(Lane_Int_Weights(1:Index));

    

    %% Weighted Histogram over both dicretised Intersections
    %% APEX Process %%
    
    
    %Purview intersection discretised
    firstDim_N  =  Lane_Int_Purview - SCALE_EXP_10*int32( HORIZON_HISTOGRAM_BINS(1) )  + idivide( SCALE_EXP_10*int32(HORIZON_HISTOGRAM_STEP), 2) ;
    firstDim_D   =  SCALE_EXP_10*int32(HORIZON_HISTOGRAM_STEP);
    firstDim     = idivide(firstDim_N, firstDim_D);
    
    %Bottom intersection discretised
    secondDim_N =  Lane_Int_Base -  SCALE_EXP_10*int32(BASE_HISTOGRAM_BINS(1)) + idivide( SCALE_EXP_10*int32(BASE_HISTOGRAM_STEP), 2) ;
    secondDim_D =  SCALE_EXP_10*int32(BASE_HISTOGRAM_STEP);
    secondDim   =  idivide(secondDim_N, secondDim_D);
    
    firstDim   = firstDim + 1;
    secondDim  = secondDim +1; 

    firstDim(end+1)      = size(HORIZON_HISTOGRAM_BINS,2);
    secondDim(end+1)    = size(BASE_HISTOGRAM_BINS,2);
    
    INT_HIST_LANE_PROB =   accumarray( secondDim, [Lane_Int_Weights; 0] );
    
    INT_HIST_VP_PROB   =   accumarray( firstDim,  [Lane_Int_Weights; 0] );
    
    
    

    %% Normalize for Further Computation %%
    %% APEX Process %%
    
     INT_HIST_LANE_PROB = INT_HIST_LANE_PROB';
     INT_HIST_VP_PROB   = INT_HIST_VP_PROB';   

    %% Predict Step %%
    %% APEX Process %%
      TEMP = imfilter( LANE_FILTER, LANE_TRANSITION, 'replicate' );
      TEMP = int64(TEMP);
      TEMP = int32( (TEMP*2^16) /sum(sum(TEMP) ) );
      LANE_FILTER_TRANSITIONED = TEMP + LANE_PRIOR ; 
      
    
      

      

    %% Update Step %%
    %% ARM LOOP %%      
     
     INT_HIST_LANE_PROB_int32 = int32( (int64(INT_HIST_LANE_PROB)*2^16) / sum(int64(INT_HIST_LANE_PROB),2) );        
     INT_HIST_VP_PROB_int32   = int32( (int64(INT_HIST_VP_PROB)  *2^16) / sum(int64(INT_HIST_VP_PROB),2)   );     
     
    
     INT_HIST_LANE_PROB = INT_HIST_LANE_PROB / sum(INT_HIST_LANE_PROB,2);        
     INT_HIST_VP_PROB   = INT_HIST_VP_PROB   / sum(INT_HIST_VP_PROB,2);
     
    best  = 0;
    
    for modelIdx = 1:size(LaneBoundaryModels,2)
        
              left  = LaneBoundaryModels(modelIdx).leftOffsetIdx;
              right = LaneBoundaryModels(modelIdx).rightOffsetIdx;
              width = (LANE_OFFSETS_BINS(left)+LANE_OFFSETS_BINS(right)) * 1/CM_TO_PIXEL;


              left_offset  = LANE_OFFSETS_BINS(left);
              right_offset = LANE_OFFSETS_BINS(right);



                    ID           = LaneBoundaryModels(modelIdx).histogramBinIDs_leftBoundary(2);
                    
                    likelihood_leftLaneBoundary = single( INT_HIST_LANE_PROB_int32(ID-1) )*0.25 ...
                                                + single( INT_HIST_LANE_PROB_int32(ID)   )       ...
                                                + single( INT_HIST_LANE_PROB_int32(ID+1) )*0.25;
               
                   
                   likelihood_leftLaneBoundary_int32 = int32(likelihood_leftLaneBoundary);
                   
                
                    ID           = LaneBoundaryModels(modelIdx).histogramBinIDs_rightBoundary(2);
                   
                    likelihood_rightLaneBoundary = single( INT_HIST_LANE_PROB_int32(ID-1) )*0.25 ...
                                                + single( INT_HIST_LANE_PROB_int32(ID)   )       ...
                                                + single( INT_HIST_LANE_PROB_int32(ID+1) )*0.25;
                    
                    likelihood_rightLaneBoundary_int32 = int32(likelihood_rightLaneBoundary);


                    NegLaneCorrelation_int32= 0;

                
                for idx=1:size(NegLaneBoundaryModel(modelIdx).histogramBinsID,2)
                     
                    ID  = NegLaneBoundaryModel(modelIdx).histogramBinsID(idx);
                    
                    NegLaneCorrelation_int32   = NegLaneCorrelation_int32 + INT_HIST_LANE_PROB_int32(ID);
                
                end
                
                
                x = single(NegLaneCorrelation_int32)/2^16;     
                likelihood_NegLaneBoundary_float =   2^16*OBS_NEG_NORMA * exp( - x^2/OBS_NEG_NOMIN );
                
                conditional_prob_float =  single(likelihood_leftLaneBoundary_int32);
                conditional_prob_float =  conditional_prob_float * single(likelihood_rightLaneBoundary_int32) *2^-16;
                conditional_prob_float =  conditional_prob_float * likelihood_NegLaneBoundary_float*2^-16;
               
                
              
                posterior_prob_int32 = int32( conditional_prob_float*  single(LANE_FILTER_TRANSITIONED(left,right)) );
                               
    
                % Already keep Track of Max Probable State

                  if best < posterior_prob_int32
                            
                     best       = posterior_prob_int32;
                     LANE_MODEL = [left_offset right_offset likelihood_leftLaneBoundary likelihood_rightLaneBoundary];
                     LANE_WIDTH = width;
                               
                  end
                  
                  LANE_FILTER(left,right) = posterior_prob_int32;
                  
                  
    end
     
    LANE_MODEL
    LANE_WIDTH
      
    
    %% Normalize Lane Filter
       %% APEX PROCESS %%
  


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
