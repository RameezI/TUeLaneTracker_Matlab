
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
function [ msg ] = find_Lane_Candidates( IDX_FOC_TOT_P, Likelihoods, Templates)




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
    [VC, HC] = ind2sub([RES_VH(1) RES_VH(2)],IDX_LANE_PIX);



    %%
    % Tranformation to VP Coordinate System
    %
    %              ^ + V (2nd dim)
    %              |   
    %              |
    %             VP --> + H (1st dim)
    %
    
    %%Random Access Operations--> Compute on Arm
    
    O_V = C_V; %%+ VP_V; %% VP to image coordinate system
    O_H = C_H; %%+ VP_H; %% VP to image coordinate system
    Lane_Points    = [ HC-(O_H) -( VC-(O_V) ) ]; %% lane pixels to VP coordinate system
    Lane_Props     = Likelihoods.TOT_MAX_FOCUSED(IDX_LANE_PIX);
    Lane_Depth     = Templates.DEPTH(IDX_LANE_PIX);
    Max_Lane_Depth = max( Templates.DEPTH(:), [], 1 )+1; %% RES_VH(1);
    Lane_Angle     = round(Likelihoods.GRADIENT_DIR_TOT_MAX(IDX_LANE_PIX));
    idx                   = find(Lane_Angle==90);
    Lane_Angle(idx)       = Lane_Angle(idx)-0.1; % Add small amount to avoid tan(90)
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% bottom in VP coordinate system %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%             
    bottom  = LANE_FILTER_OFFSET_V; %% keep fixed regardless of the FOV or use, keeps the cm-to-pixel ratio more stable
    horizon = VP_FILTER_OFFSET_V; %% use an offest from horizon to make intersections more pronounced


    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% compute intersection with offseted horizon %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    Tan_Lane_Angle        = tand(Lane_Angle);                        
    Lane_Int_Horizon      = ((horizon-Lane_Points(:,2))./Tan_Lane_Angle) + Lane_Points(:,1);    
     
    %Lane_Int_Horizon(idx) = Lane_Points(idx,1);


    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% only keep point in range %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    keep = find(  -VP_RANGE_H-VP_STEP_HST/2 < Lane_Int_Horizon & Lane_Int_Horizon < VP_RANGE_H+VP_STEP_HST/2  );
    Lane_Int_Horizon = Lane_Int_Horizon(keep);
    Lane_Props       = Lane_Props(keep);
    Lane_Depth       = Lane_Depth(keep);
    VC               = ceil(Lane_Depth)+1; %% used for weighting pixels


    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% compute intersection with bottom image %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    Lane_Int_Bottom      = ((bottom-Lane_Points(:,2))./Tan_Lane_Angle) + Lane_Points(:,1);
    idx                  = find(Lane_Angle==90); 
    Lane_Int_Bottom(idx) = Lane_Points(idx,1);    
    Lane_Int_Bottom      = Lane_Int_Bottom(keep); %% from previous keep
    
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% only keep point in range %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    keep = find( LANE_BINS_H(1)-(PX_STEP/2) < Lane_Int_Bottom & Lane_Int_Bottom < LANE_BINS_H(end)+(PX_STEP/2) ); %% new keep
    Lane_Int_Bottom  = Lane_Int_Bottom(keep);
    Lane_Int_Horizon = Lane_Int_Horizon(keep); 
    Lane_Props       = Lane_Props(keep);
    Lane_Depth       = Lane_Depth(keep);
    VC               = VC(keep);

    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% make weighted histogram over both intersections                              %%
    %% the weight is pixel surface (i.e. depth squared) times per-pixel probability %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    firstDim  = ceil( (Lane_Int_Horizon - VP_BINS_HST(1)  + (VP_STEP_HST/2)) / VP_STEP_HST  );  %% horizon intersection
    secondDim = ceil( (Lane_Int_Bottom  - LANE_BINS_H(1)  + (PX_STEP/2)) / PX_STEP  );          %% bottom intersection
    INT_HIST_LANE_PROB = accumarray( [[secondDim; size(LANE_BINS_H,2)] [VC; Max_Lane_Depth]], [(Lane_Depth.^2).*Lane_Props; 0] );
    

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% do the same but only use surface as weight %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    INT_HIST_VP_PROB = accumarray( [[firstDim; size(VP_BINS_HST,2)] [VC; Max_Lane_Depth]], [(Lane_Depth.^2).*Lane_Props; 0] );
  

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
    %% go from per-pixel probs to segment (lane boundary) probs    %% 
    %% use the std of depth per lane bin                           %%
    %% higher std means that lane is detected over larger distance %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    covCount = sum(INT_HIST_LANE_PROB,2); %% sum coverage
    maskVC   = 0 < INT_HIST_LANE_PROB;
    covVC    = maskVC .* repmat([1:Max_Lane_Depth],size(LANE_BINS_H,2),1);    
    covVCCnt = sum( maskVC, 2);
    covMean  = sum(covVC,2)./covVCCnt;
    covStd   = sqrt(sum( maskVC .* (covVC-repmat(covMean,1,Max_Lane_Depth)).^2, 2 )./covVCCnt); 
    covStd( isnan(covStd) ) = 0;    
    INT_HIST_LANE_PROB = (covCount.*covStd)'; %% final prob is per-pixel prob times lane boundary prob        
    
    
    %%%%%%%%%%%%%%%%%%%%%%
    %% same for VP prob %%
    %%%%%%%%%%%%%%%%%%%%%%
    covCount = sum(INT_HIST_VP_PROB,2); %% sum coverage
    maskVC   = 0 < INT_HIST_VP_PROB;
    covVC    = maskVC .* repmat([1:Max_Lane_Depth],size(VP_BINS_HST,2),1);    
    covVCCnt = sum( maskVC, 2);
    covMean  = sum(covVC,2)./covVCCnt;
    covStd   = sqrt(sum( maskVC .* (covVC-repmat(covMean,1,Max_Lane_Depth)).^2, 2 )./covVCCnt); 
    covStd( isnan(covStd) ) = 0;    
    INT_HIST_VP_PROB = (covCount.*covStd)'; %% final prob is per-pixel prob times lane boundary prob    
         
    
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% normalize for further computation %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    INT_HIST_LANE_PROB = INT_HIST_LANE_PROB / sum(INT_HIST_LANE_PROB,2);        
    INT_HIST_VP_PROB   = INT_HIST_VP_PROB   / sum(INT_HIST_VP_PROB,2);
    
    
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     %% plot the observation histogram %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     sfigure(456);
%     clf
%     hold on
%     bar( LANE_BINS_H, INT_HIST_LANE_PROB' )  
%     grid on
%     drawnow
%     
%     sfigure(457); 
%     clf
%     hold on
%     bar( VP_BINS_HST, INT_HIST_VP_PROB' )  
%     grid on
%     drawnow

    

    %%
    %%
    %%
    %%
    %% Histogram Bayes filter for bottom lane intersections
    %% This brings the solution to object-level (object = lane = 2 lane boundaries)
    %% Lane prob = Left_boundary_prob * Right_boundary_prob * Inner_lane_Uniformity
    %%
    %%



    %%%%%%%%%%%%%%%%%%
    %% predict step %%
    %%%%%%%%%%%%%%%%%%
    TEMP = imfilter( LANE_FILTER, LANE_TRANSITION, 'Replicate' );
    TEMP = TEMP / sum(TEMP(:),1);
    LANE_FILTER = 0.5*TEMP + 0.5*LANE_PRIOR; %% change the 0.5 to make filter more strict or loose


    

    %%%%%%%%%%%%%%%%%
    %% update step %%
    %%%%%%%%%%%%%%%%%



%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     %% show histogram and model %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%     sfigure(134);
%     clf           
%     h = bar3( LANE_FILTER );               
%     hold on    
%     set(h,'EdgeColor','none');
%     axis vis3d
%     view(135,35);
%     title('LANE FILTER PREDICT')
%     drawnow
    

    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% for each possible state %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    best  = 0;
    for left = 1:size(LANE_FILTER_BINS_H,2)
        for right = 1:size(LANE_FILTER_BINS_H,2)


            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %% widht of lane must be in range %%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            width = round((LANE_FILTER_BINS_H(left)+LANE_FILTER_BINS_H(right)) * 1/CM_TO_PIXEL);
            if MIN_LANE_WIDTH <= width && width <= MAX_LANE_WIDTH
            
                
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                %% get lane offset in pixels %%
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                left_offset  = LANE_FILTER_BINS_H(left);
                right_offset = LANE_FILTER_BINS_H(right);

                %%%%%%%%%%%%%%%%%%%%%%
                %% must be in range %%
                %%%%%%%%%%%%%%%%%%%%%% 
                if left_offset < LANE_BINS_H(1)  %%Unnecessary check!

                    update_prob = 0;

                %%%%%%%%%%%%%%%%%%%%%%    
                %% must be in range %%
                %%%%%%%%%%%%%%%%%%%%%%
                elseif LANE_BINS_H(end) <= right_offset

                     update_prob = 0;

                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                %% create the observation model (i.e. lane observation probs) %%
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                else

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
                    update_mask_left  = sum( modelL.*INT_HIST_LANE_PROB, 2 ); 
                    update_mask_right = sum( modelR.*INT_HIST_LANE_PROB, 2 );
                    update_prob       = update_mask_left * update_mask_right * OBS_NEG_NORMA * exp( -sum( obsNeg.*INT_HIST_LANE_PROB, 2 )^2/OBS_NEG_NOMIN );
                                             
%                     sfigure(562);
%                     bar( LANE_BINS_H, [obsNeg'] )
%                     drawnow
%                     grid on

                end

            else

                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                %% this lane configuration is not supported %%
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                update_prob = 0;

            end

            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %% update the probability of the state %%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            LANE_FILTER(left,right) = LANE_FILTER(left,right) * update_prob;                        

            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %% already keep track of max %%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            if best < LANE_FILTER(left,right);
                best       = LANE_FILTER(left,right);
                LANE_MODEL = [left_offset right_offset update_mask_left update_mask_right];
                LANE_WIDTH = width;
            end

        end
    end
    LANE_MODEL
    LANE_WIDTH

    
    
    %%%%%%%%%%%%%%%%%%%%%%%%
    %% normalize as usual %%
    %%%%%%%%%%%%%%%%%%%%%%%%
    LANE_FILTER = LANE_FILTER / sum(LANE_FILTER(:),1);



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
    if LANE_BOUNDARIES(5,1) < LANE_CONF_THRESHOLD || LANE_BOUNDARIES(5,2) < LANE_CONF_THRESHOLD
        msg = STATE_ERROR;
    else
        msg = STATE_READY;    
    end
    
    
end
