%%
%% reset all important variables back to default
%%
function [msg, Likelihoods, Templates, VanishingPt, Masks] = run_Reset_State(Likelihoods_Backup, Templates_Backup, VanishingPt_Backup, Masks_Backup)
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% All Required Globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%    
    global CENTER_OFFSET STATE_READY 
    global LANE_FILTER VP_FILTER LANE_PRIOR VP_PRIOR
    
    

    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% (re)start the filters %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    LANE_FILTER = LANE_PRIOR;
    VP_FILTER   = VP_PRIOR;
    
   
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% reset the center lane filter %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    CENTER_OFFSET = 0.5;
    
    
    Likelihoods  = Likelihoods_Backup;
    Templates    = Templates_Backup;
    VanishingPt  = VanishingPt_Backup;
    Masks        = Masks_Backup;
    
    %%%%%%%%%%%%%%%%%%%%%%%%
    %% this state is done %%
    %%%%%%%%%%%%%%%%%%%%%%%%
    msg = STATE_READY;
    
    
end

