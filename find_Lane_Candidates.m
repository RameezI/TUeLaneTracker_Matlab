
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
function [ msg ] = find_Lane_Candidates( IDX_FOC_TOT_P, Likelihoods, Templates, Mask)
    
    
    %% Required Interface
    global STATE_READY STATE_ERROR
    global LANE_CONF_THRESHOLD C_V C_H RES_VH CM_TO_PIXEL 
    global OBS_NEG_NOMIN OBS_NEG_NORMA LaneBoundaryModels NegLaneBoundaryModel   
    global HORIZON_HISTOGRAM_STEP HORIZON_HISTOGRAM_BINS  
    global BASE_HISTOGRAM_STEP    BASE_HISTOGRAM_BINS
    global VP_RANGE_H LANE_OFFSETS_BINS LANE_FILTER_OFFSET_V VP_FILTER_OFFSET_V
    global LANE_FILTER LANE_TRANSITION LANE_PRIOR  
    global LANE_WIDTH INT_HIST_LANE_PROB INT_HIST_VP_PROB %% the Lane intersection observations histograms
    
    
    
    %% Provided Interface
    global LANE_BOUNDARIES    
    
    

    

    %% Get All Active Pixles and Transform to VP Coordinate System %%
  
    IDX_LANE_PIX = IDX_FOC_TOT_P;
    rows = C_V + Mask.VP_RANGE_V - Mask.Margin;
    
    [VC, HC] = ind2sub([rows RES_VH(2)],IDX_LANE_PIX);
    VC = VC + ( RES_VH(1)-rows) +1;


    % Tranformation to VP Coordinate System
    O_V = C_V; %%+ VP_V; %% VP to image coordinate system
    O_H = C_H; %%+ VP_H; %% VP to image coordinate system
    
    
    % Structure Required to Extract same (location wise)information from different sources using a for example using a for loop
    
    
    Lane_Points     = [ HC-(O_H) -( VC-(O_V) ) ]; %% lane pixels to VP coordinate system
    
    Lane_Props      = Likelihoods.TOT_MAX_FOCUSED(IDX_LANE_PIX);
    
    Lane_Depth      = Templates.DEPTH(IDX_LANE_PIX);

    Tan_Lane_Angle= Likelihoods.GRADIENT_DIR_TOT_MAX(IDX_LANE_PIX);

             
    bottom  = LANE_FILTER_OFFSET_V ; %% keep fixed regardless of the FOV or use, keeps the cm-to-pixel ratio more stable
    
    horizon = VP_FILTER_OFFSET_V; %% use an offest from horizon to make intersections more pronounced

   
      
    %%
    %% Compute Intersections with Offseted Horizon  and Botton%%
    
    Lane_Int_Bottom_tmp   = floor(  ((bottom-Lane_Points(:,2)) *2^7  )./Tan_Lane_Angle) + Lane_Points(:,1);                            
    Lane_Int_Horizon_tmp  = floor(  ((horizon-Lane_Points(:,2))*2^7  )./Tan_Lane_Angle) + Lane_Points(:,1);    

    
 
    
    
     Lane_Int_Bottom  = single(zeros(size(Lane_Int_Bottom_tmp,1),1));
     Lane_Int_Horizon = single(zeros(size(Lane_Int_Horizon_tmp,1),1));
     Lane_Props_Int   = single(zeros(size(IDX_LANE_PIX,1),1));
     Lane_Depth_Int   = single(zeros(size(IDX_LANE_PIX,1),1));
     
     
     
     
    Index =1;     
    for i= 1: size(IDX_LANE_PIX)
        
      if ( Lane_Int_Bottom_tmp(i) > BASE_HISTOGRAM_BINS(1)-BASE_HISTOGRAM_STEP/2    &&   Lane_Int_Bottom_tmp(i) < BASE_HISTOGRAM_BINS(end)+ BASE_HISTOGRAM_STEP/2)
        
            
      if (  Lane_Int_Horizon_tmp(i) > -VP_RANGE_H-HORIZON_HISTOGRAM_STEP/2          &&   Lane_Int_Horizon_tmp(i) < VP_RANGE_H+HORIZON_HISTOGRAM_STEP/2  )                
                
                        Lane_Int_Bottom(Index)    = Lane_Int_Bottom_tmp(i);
                        Lane_Int_Horizon(Index)   = Lane_Int_Horizon_tmp(i);
                        Lane_Props_Int(Index)     = Lane_Props(i);
                        Lane_Depth_Int(Index)     = Lane_Depth(i);
                        
                        Index = Index+1;               
      end
               
      end
    
    end

    
    
    Lane_Int_Horizon   = Lane_Int_Horizon(1:Index);
    Lane_Int_Bottom    = Lane_Int_Bottom(1:Index);
    Lane_Props_Int     = Lane_Props_Int(1:Index);
    Lane_Depth_Int     = Lane_Depth_Int(1:Index);
    
    Lane_Scaled_Props_Int =  ((Lane_Props_Int+1).*(Lane_Depth_Int.^2)) * 2^-8;
    Lane_Scaled_Props_Int =  floor(Lane_Scaled_Props_Int);

    
    
    
    

    %% Weighted Histogram over both Intersections   
    % The weight is pixel surface (i.e. depth squared) times per-pixel probability 
    
    
    firstDim  = ceil( (Lane_Int_Horizon - HORIZON_HISTOGRAM_BINS(1)  + (HORIZON_HISTOGRAM_STEP/2)) / HORIZON_HISTOGRAM_STEP  );  %% horizon intersection
    
    secondDim = ceil( (Lane_Int_Bottom  - BASE_HISTOGRAM_BINS(1)  + (BASE_HISTOGRAM_STEP/2)) / BASE_HISTOGRAM_STEP  );          %% bottom  intersection
    
    firstDim(size(firstDim)+1)      = size(HORIZON_HISTOGRAM_BINS,2);
    secondDim(size(secondDim)+1)    = size(BASE_HISTOGRAM_BINS,2);
    
    
    
    INT_HIST_LANE_PROB =   accumarray( secondDim, [Lane_Scaled_Props_Int; 0] );
    
    INT_HIST_VP_PROB   =   accumarray( firstDim,  [Lane_Scaled_Props_Int; 0] );
  
    

    
    %% Normalize for Further Computation %%
   
     INT_HIST_LANE_PROB = INT_HIST_LANE_PROB';
     INT_HIST_VP_PROB   = INT_HIST_VP_PROB';
     
     INT_HIST_LANE_PROB = INT_HIST_LANE_PROB / sum(INT_HIST_LANE_PROB,2);        
     INT_HIST_VP_PROB   = INT_HIST_VP_PROB   / sum(INT_HIST_VP_PROB,2);
    



    
    %% Predict Step %%
    
      TEMP = imfilter( LANE_FILTER, LANE_TRANSITION, 'Replicate' );
      TEMP = int32( (single(TEMP) / single(sum(sum(TEMP))) ) *2^15);
      LANE_FILTER_TRANSITIONED = 0.5*TEMP +0.5*LANE_PRIOR ; 
      
    

    % Update Step %%
 
    best  = 0;
    for modelIdx = 1:size(LaneBoundaryModels,2)
        

        
              left  = LaneBoundaryModels(modelIdx).leftOffsetIdx;
              right = LaneBoundaryModels(modelIdx).rightOffsetIdx;
              
              
              
                if left == 50
                    a= 3;
                end

              width = (LANE_OFFSETS_BINS(left)+LANE_OFFSETS_BINS(right)) * 1/CM_TO_PIXEL;

              %  if MIN_LANE_WIDTH <= width && width <= MAX_LANE_WIDTH

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
      
      
      

    

%     % Update Step %%
%  
%     best  = 0;
%     for left = 1:size(LANE_OFFSETS_BINS,2)
%         
%         for right = 1:size(LANE_OFFSETS_BINS,2)
% 
% 
%             width = (LANE_OFFSETS_BINS(left)+LANE_OFFSETS_BINS(right)) * 1/CM_TO_PIXEL;
%             if MIN_LANE_WIDTH <= width && width <= MAX_LANE_WIDTH
%                 
%                 left_offset  = LANE_OFFSETS_BINS(left);
%                 right_offset = LANE_OFFSETS_BINS(right);
% 
%                   
%                   likelihood_leftLaneBoundary =0;
% 
%                    for idx=1:  size(laneBoundaryModel(left,right).LeftBinID,1)
%                        
%                      ID           = laneBoundaryModel(left,right).LeftBinID(idx);
%                      Value        = laneBoundaryModel(left,right).LeftValue(idx);
%                      likelihood_leftLaneBoundary = likelihood_leftLaneBoundary + INT_HIST_LANE_PROB(ID)*Value;               
%                    
%                    end
%                                                       
%                         
%                   likelihood_rightLaneBoundary =0;
% 
%                    for idx=1:size(laneBoundaryModel(left,right).RightBinID,1)
%                    
%                        ID           = laneBoundaryModel(left,right).RightBinID(idx);
%                        Value        = laneBoundaryModel(left,right).RightValue(idx);
%                        likelihood_rightLaneBoundary = likelihood_rightLaneBoundary + INT_HIST_LANE_PROB(ID)*Value;
%                      
%                    end
%                    
% 
%                   NegLaneCorrelation= 0; 
%                   
%                   for idx=1:size(negLaneBoundaryModel(left,right).BinID,1)
%                       ID  = negLaneBoundaryModel(left,right).BinID(idx);
%                       NegLaneCorrelation = NegLaneCorrelation + INT_HIST_LANE_PROB(ID);                  
%                   end
% 
%                   likelihood_NegLaneBoundary    =     OBS_NEG_NORMA * exp( -NegLaneCorrelation^2/OBS_NEG_NOMIN );
%                   
%                   
%                   conditional_prob              =    likelihood_leftLaneBoundary * likelihood_rightLaneBoundary* likelihood_NegLaneBoundary;
% 
%                                              
% 
% 
%             else
% 
%                   conditional_prob = 0;
% 
%             end
%             
%             
%             LANE_FILTER(left,right) = LANE_FILTER(left,right) * conditional_prob;
% 
%            
%             % Already keep Track of Max Probable State
%            
%             if best < LANE_FILTER(left,right)
%                 bestState = [left right];
%                 best       = LANE_FILTER(left,right);
%                 LANE_MODEL = [left_offset right_offset likelihood_leftLaneBoundary likelihood_rightLaneBoundary];
%                 LANE_WIDTH = width;
%             end
% 
%         end
%     end
%     
%     LANE_MODEL
%     LANE_WIDTH

    
%     if (LANE_MODEL ~=  LANE_MODEL_new)  || (LANE_WIDTH ~= LANE_WIDTH_new) || (LANE_FILTER ~= LANE_FILTER_new)
%         
% 
%         a =3;   
%         
%     end

    %% Normalize Lane Filter
    LANE_FILTER = int32( (single(LANE_FILTER) / single( sum(sum(LANE_FILTER)) )   )*2^15);


    %% Find the Lane Boundaries
    
    LANE_BOUNDARIES = [ -LANE_MODEL(1)-BASE_HISTOGRAM_STEP/2 LANE_MODEL(2)-BASE_HISTOGRAM_STEP/2; -LANE_MODEL(1)+BASE_HISTOGRAM_STEP/2 LANE_MODEL(2)+BASE_HISTOGRAM_STEP/2; 0 0; 0 0; 100*LANE_MODEL(3) 100*LANE_MODEL(4)];
    LANE_BOUNDARIES(3,1) = (LANE_BOUNDARIES(1,1)+LANE_BOUNDARIES(2,2))/2;
    LANE_BOUNDARIES(3,2) = LANE_BOUNDARIES(3,1);
    
    
        
    
    %% Unstable Track ?
    
    LANE_BOUNDARIES
    if LANE_BOUNDARIES(5,1) < LANE_CONF_THRESHOLD  || LANE_BOUNDARIES(5,2) < LANE_CONF_THRESHOLD
        msg = STATE_ERROR;
    else
        msg = STATE_READY;    
    end
    
    
end
