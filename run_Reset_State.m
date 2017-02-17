%%
%% reset all important variables back to default
%%
function [msg] = run_Reset_State()
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%    
    global CENTER_OFFSET RES_VH STATE_READY LANE_FILTER LANE_PRIOR VP_FILTER VP_PRIOR TOT_P_ALL_BACK_UP DIR_ALL_BACK_UP 
    
    

    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% (re)start the filters %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    LANE_FILTER = LANE_PRIOR;
    VP_FILTER   = VP_PRIOR;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% the lane markers map %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    global TOT_P_ALL       %% the NBUFFER-frame probaility p(pixel|lane)
    global DIR_ALL         %% the NBUFFER-frame combine gradient direction
    global MASK_FOC_TOT_P  %% the single-frame binaray mask of all selected pixels (computed over NBUFFER frames)
    global TOT_P           %% the single-frame probaility p(pixel|lane) (computed over NBUFFER frames)
    global FOC_TOT_P       %% TOT_P multiplied by MASK_FOC_TOT_P
    global AVG_DIR_TOT_P   %% the single-frame gradient direction p(pixel|lane) (computed over NBUFFER frames)
    global IDX_LANE_PIX    %% the linear indices of pixels a priori likely to be lane markings
    TOT_P_ALL      = TOT_P_ALL_BACK_UP;
    DIR_ALL        = DIR_ALL_BACK_UP;
    MASK_FOC_TOT_P = ones(  RES_VH(1), RES_VH(2));
    FOC_TOT_P      = zeros( RES_VH(1), RES_VH(2));
    TOT_P          = zeros( RES_VH(1), RES_VH(2));
    AVG_DIR_TOT_P  = zeros( RES_VH(1), RES_VH(2));
    IDX_LANE_PIX   = [];
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% create the gradient template %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    global SEGMENT ROOT_DIR_TEMPLATE
    ROOT_DIR_TEMPLATE = createTemplate(RES_VH(1),RES_VH(2));       
    SEGMENT           = zeros(RES_VH(1),RES_VH(2));
    
    
   

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% create the depth template              %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    global ROOT_IDEPTH_TEMPLATE
    ROOT_IDEPTH_TEMPLATE = zeros(2*RES_VH(1)+1,RES_VH(2));
    step  = 45/RES_VH(1);
    angle = 90-step;
    for n = RES_VH(1)+1:2*RES_VH(1)+1
        ROOT_IDEPTH_TEMPLATE(n,:) = 1.75*tand(angle);
        angle                     = angle-step;
    end
    ROOT_IDEPTH_TEMPLATE( 100 < ROOT_IDEPTH_TEMPLATE ) = 100;
    

    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% create the prob template               %%
    %% masks out parts above horizon + margin %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    global ROOT_PROB_TEMPLATE
    Margin          = 100; %% Note: Should be fitted using sweeps
    ROOT_PROB_TEMPLATE = zeros(2*RES_VH(1)+1,RES_VH(2));
    ROOT_PROB_TEMPLATE(RES_VH(1)+Margin:end,:) = 1;
    for n = 481:RES_VH(1)+Margin
      ROOT_PROB_TEMPLATE(n,:) = ((n-RES_VH(1))/Margin)^3;
    end
   % ROOT_PROB_TEMPLATE( 100 < ROOT_PROB_TEMPLATE ) = 100;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% reset the center lane filter %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    CENTER_OFFSET = 0.5;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% reset the vp and templates %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    global VP_V VP_H OLD_VP_V OLD_VP_H
    VP_V     = 0; %% the VP in the center image coordinate system
    VP_H     = 0; %% the VP in the center image coordinate system
    OLD_VP_V = 0; %% the old VP in the center image coordinate system
    OLD_VP_H = 0; %% the old VP in the center image coordinate system
             
    %%%%%%%%%%%%%%%%%%%%%%%%
    %% this state is done %%
    %%%%%%%%%%%%%%%%%%%%%%%%
    msg = STATE_READY;
    
    
end

