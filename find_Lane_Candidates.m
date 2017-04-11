
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




    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    global STATE_READY STATE_ERROR
    global LANE_CONF_THRESHOLD C_V C_H RES_VH
    global OBS_NEG_NOMIN OBS_NEG_NORMA OBS_L OBS_R OBS_N
    global VP_BINS_HST VP_STEP_HST PX_STEP VP_RANGE_H LANE_BINS_H LANE_FILTER LANE_TRANSITION LANE_PRIOR LANE_FILTER_BINS_H LANE_FILTER_OFFSET_V VP_FILTER_OFFSET_V 
    global CM_TO_PIXEL MIN_LANE_WIDTH MAX_LANE_WIDTH   LANE_WIDTH INT_HIST_LANE_PROB INT_HIST_VP_PROB %% the Lane intersection observations histograms
    global LANE_BOUNDARIES    
    
    
    %% the 5XN lane boundary model
                               %% 1,n left intersection with bottom wrt VP
                               %% 2,n right intersection with bottom wrt VP (not used)
                               %% 3,n intersection with horizon wrt VP left-side
                               %% 4,n intersection with horizon wrt VP right-side (not used)
                               %% 5,n total prob of peak
    
    
    %%
    %% Get All Active Pixles %%
    % tuned for high recall %
    
    IDX_LANE_PIX = IDX_FOC_TOT_P;
    rows = C_V + Mask.VP_RANGE_V - Mask.Margin;
    
    [VC, HC] = ind2sub([rows RES_VH(2)],IDX_LANE_PIX);
    VC = VC + ( RES_VH(1)-rows) +1;

    
    
    %%
    % Tranformation to VP Coordinate System
    %
    %              ^ + V (2nd dim)
    %              |   
    %              |
    %             VP --> + H (1st dim)
    %
    
    O_V = C_V; %%+ VP_V; %% VP to image coordinate system
    O_H = C_H; %%+ VP_H; %% VP to image coordinate system
    
    
    Lane_Points     = [ HC-(O_H) -( VC-(O_V) ) ]; %% lane pixels to VP coordinate system
    
    Lane_Props      = Likelihoods.TOT_MAX_FOCUSED(IDX_LANE_PIX);
    
    Lane_Depth      = Templates.DEPTH(IDX_LANE_PIX);
    
%     Lane_Angle      = Likelihoods.GRADIENT_DIR_TOT_MAX(IDX_LANE_PIX);
%     
%     idx             = find(Lane_Angle==90);
%     
%     Lane_Angle(idx) = Lane_Angle(idx)-1; % Adjust to avoid tan(90)
%     
%     Tan_Lane_Angle = tand(Lane_Angle);

      Tan_Lane_Angle= Likelihoods.GRADIENT_DIR_TOT_MAX(IDX_LANE_PIX);

             
    bottom  = LANE_FILTER_OFFSET_V; %% keep fixed regardless of the FOV or use, keeps the cm-to-pixel ratio more stable
    
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
        
        if ( Lane_Int_Bottom_tmp(i)>LANE_BINS_H(1)-(PX_STEP/2)            &&           Lane_Int_Bottom_tmp(i) < LANE_BINS_H(end)+(PX_STEP/2))
        
            
            if (  Lane_Int_Horizon_tmp(i) > -VP_RANGE_H-VP_STEP_HST/2     &&           Lane_Int_Horizon_tmp(i) < VP_RANGE_H+VP_STEP_HST/2  )
                
                
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


    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Weighted Histogram over both Intersections                              %%
    %% the weight is pixel surface (i.e. depth squared) times per-pixel probability %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    firstDim  = ceil( (Lane_Int_Horizon - VP_BINS_HST(1)  + (VP_STEP_HST/2)) / VP_STEP_HST  );  %% horizon intersection
    secondDim = ceil( (Lane_Int_Bottom  - LANE_BINS_H(1)  + (PX_STEP/2)) / PX_STEP  );          %% bottom  intersection
    
    firstDim(size(firstDim)+1)      = size(VP_BINS_HST,2);
    secondDim(size(secondDim)+1)    = size(LANE_BINS_H,2);
    
    
    
    INT_HIST_LANE_PROB =   accumarray( secondDim, [Lane_Scaled_Props_Int; 0] );
    
    INT_HIST_VP_PROB   =   accumarray( firstDim,  [Lane_Scaled_Props_Int; 0] );
  
    
    
    
    
    
%     Max_Lane_Depth =100;
%     
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
%     %% go from per-pixel probs to segment (lane boundary) probs    %% 
%     %% use the std of depth per lane bin                           %%
%     %% higher std means that lane is detected over larger distance %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     covCount = sum(INT_HIST_LANE_PROB,2); %% sum coverage
%     maskVC   = 0 < INT_HIST_LANE_PROB;
%     covVC    = maskVC .* repmat([1:Max_Lane_Depth],size(LANE_BINS_H,2),1);    
%     covVCCnt = sum( maskVC, 2);
%     covMean  = sum(covVC,2)./covVCCnt;
%     covStd   = sqrt(sum( maskVC .* (covVC-repmat(covMean,1,Max_Lane_Depth)).^2, 2 )./covVCCnt); 
%     covStd( isnan(covStd) ) = 0;    
%     INT_HIST_LANE_PROB = (covCount.*covStd)'; %% final prob is per-pixel prob times lane boundary prob
%     
%  
%     
%     
%     %%%%%%%%%%%%%%%%%%%%%
%     % same for VP prob %%
%     %%%%%%%%%%%%%%%%%%%%%
%     covCount = sum(INT_HIST_VP_PROB,2); %% sum coverage
%     maskVC   = 0 < INT_HIST_VP_PROB;
%     covVC    = maskVC .* repmat([1:Max_Lane_Depth],size(VP_BINS_HST,2),1);    
%     covVCCnt = sum( maskVC, 2);
%     covMean  = sum(covVC,2)./covVCCnt;
%     covStd   = sqrt(sum( maskVC .* (covVC-repmat(covMean,1,Max_Lane_Depth)).^2, 2 )./covVCCnt); 
%     covStd( isnan(covStd) ) = 0;    
%     INT_HIST_VP_PROB = (covCount.*covStd)'; %% final prob is per-pixel prob times lane boundary prob

         
    
    
    %%
    %% Normalize for Further Computation %%
   
     INT_HIST_LANE_PROB = INT_HIST_LANE_PROB';
     INT_HIST_VP_PROB   = INT_HIST_VP_PROB';
     
     INT_HIST_LANE_PROB = INT_HIST_LANE_PROB / sum(INT_HIST_LANE_PROB,2);        
     INT_HIST_VP_PROB   = INT_HIST_VP_PROB   / sum(INT_HIST_VP_PROB,2);
    



    %%
    %% Predict Step %%
    
      TEMP = imfilter( LANE_FILTER, LANE_TRANSITION, 'Replicate' );
      TEMP = TEMP / sum(sum(TEMP));
      LANE_FILTER = TEMP;
%       LANE_FILTER = 0.5*TEMP +0.5*LANE_PRIOR ; 

    
    %+ 0.1*LANE_PRIOR; %% change the 0.5 to make filter more strict or loose


    

    %%
    %% Update Step %%
 
    best  = 0;
    for left = 1:size(LANE_FILTER_BINS_H,2)
        for right = 1:size(LANE_FILTER_BINS_H,2)


            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %% widht of lane must be in range %%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%     
            
            width = (LANE_FILTER_BINS_H(left)+LANE_FILTER_BINS_H(right)) * 1/CM_TO_PIXEL;
            if MIN_LANE_WIDTH <= width && width <= MAX_LANE_WIDTH
                
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                %% get lane offset in pixels %%
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                left_offset  = LANE_FILTER_BINS_H(left);
                right_offset = LANE_FILTER_BINS_H(right);



                    %%%%%%%%%%%%%%%%%%%%%%%
                    %% create that model %%
                    %%%%%%%%%%%%%%%%%%%%%%%                           
                    modelL = OBS_L(left,:,right);  
                    modelR = OBS_R(left,:,right);  
                    obsNeg = OBS_N(left,:,right);  
                    
                    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                    %% the likelihood of the observations given %% 
                    %% te model                                 %%                                  
                    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                    
                    
                    likelihood_left  = sum( modelL.*INT_HIST_LANE_PROB, 2 ); 
                    likelihood_right = sum( modelR.*INT_HIST_LANE_PROB, 2 );
                    
                  
                    likelihood_Neg    = OBS_NEG_NORMA * exp( -sum( obsNeg.*INT_HIST_LANE_PROB, 2 )^2/OBS_NEG_NOMIN );
                    conditional_prob  = likelihood_left * likelihood_right * likelihood_Neg;
                                             


            else

                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                %% this lane configuration is not supported %%
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                conditional_prob = 0;

            end

            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %% update the probability of the state %%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            LANE_FILTER(left,right) = LANE_FILTER(left,right) * conditional_prob;                        

            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %% already keep track of max %%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            if best < LANE_FILTER(left,right);
                best       = LANE_FILTER(left,right);
                LANE_MODEL = [left_offset right_offset likelihood_left likelihood_right];
                LANE_WIDTH = width;
            end

        end
    end
    LANE_MODEL
    LANE_WIDTH

    
    
    %%%%%%%%%%%%%%%%%%%%%%%%
    %% normalize as usual %%
    %%%%%%%%%%%%%%%%%%%%%%%%
    LANE_FILTER = LANE_FILTER / sum(sum(LANE_FILTER));



%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     %% show histogram and model %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%     sfigure(135);
%     clf           
%     h = bar3( LANE_FILTER );               
%     hold on    
%     set(h,'EdgeColor','none');
%     axis vis3d
%     view(135,35);
%     title('LANE FILTER UPDATE')
%     drawnow



    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% find the lane boundaries %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    LANE_BOUNDARIES = [ -LANE_MODEL(1)-PX_STEP/2 LANE_MODEL(2)-PX_STEP/2; -LANE_MODEL(1)+PX_STEP/2 LANE_MODEL(2)+PX_STEP/2; 0 0; 0 0; 100*LANE_MODEL(3) 100*LANE_MODEL(4)];
    LANE_BOUNDARIES(3,1) = (LANE_BOUNDARIES(1,1)+LANE_BOUNDARIES(2,2))/2;
    LANE_BOUNDARIES(3,2) = LANE_BOUNDARIES(3,1);
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% unstable track ?            %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    LANE_BOUNDARIES
    if LANE_BOUNDARIES(5,1) < LANE_CONF_THRESHOLD  || LANE_BOUNDARIES(5,2) < LANE_CONF_THRESHOLD
        msg = STATE_ERROR;
    else
        msg = STATE_READY;    
    end
    
    
end
