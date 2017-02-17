

%%
%% temporal filter over input data
%%
function [] = filter_And_Focus()

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    global TOT_P_ALL DIR_ALL  TOT_P AVG_DIR_TOT_P FOC_TOT_P MASK_FOC_TOT_P NBUFFER RES_VH  FOCUS_TEMPLATE
    global IDX_FOC_TOT_P %% the computed adaptive thresholds
    
    
    
    
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% create the prob template               %%
    %% masks out parts above horizon + margin %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    Margin          = 100; %% Note: Should be fitted using sweeps
    ROOT_PROB_TEMPLATE_NEW = zeros(2*RES_VH(1)+1,RES_VH(2));

    ROOT_PROB_TEMPLATE_NEW(RES_VH(1)+Margin:end,:) = 1;
        
    for n = 481:RES_VH(1)+Margin
      ROOT_PROB_TEMPLATE_NEW(n,:) = ((n-RES_VH(1))/Margin)^3;
    end
    
    
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% temporal max pooling %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    MAX_P         = TOT_P_ALL(:,:,3);
    AVG_DIR_MAX_P = DIR_ALL(:,:,3); 
    for ni = 2:NBUFFER
        
        %%%%%%%%%%%%
        %% filter %%
        %%%%%%%%%%%%
        tempP               = TOT_P_ALL(:,:,ni);
        tempD               = DIR_ALL(:,:,ni);
        
        %%%%%%%%%%%%%%%%%%%%%%
        %% where is the max %%
        %%%%%%%%%%%%%%%%%%%%%%
        mask                = MAX_P < tempP;                
        MAX_P(mask)         = tempP(mask);                
        AVG_DIR_MAX_P(mask) = tempD(mask);
    end
    TOT_P         = MAX_P;
    AVG_DIR_TOT_P = AVG_DIR_MAX_P;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% apply the focus maks to the probs %%
    %% masks out from certain distance   %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
    
    FOC_TOT_P = FOCUS_TEMPLATE .* TOT_P;
        
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% get the active pixels %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    MASK_FOC_TOT_P = FOCUS_TEMPLATE;
    
    IDX_FOC_TOT_P  = find( 0 < MASK_FOC_TOT_P );
    
end


