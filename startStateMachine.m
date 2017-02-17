function  [] = startStateMachine()

global  N_IMAGE CENTER_OFFSET NBUFFER IMAGE_FILES INIT_STATE  STATE_READY  STEP_SIZE CURRENT_STATE PREV_INO STATE_COUNTER  FILLING_BUFFERS DETECTING_EGO_LANE RESET_STATE START_END_FRAMES STATE_ERROR 
       
NBUFFER       = 3;
CENTER_OFFSET = 0.5;



Number_Of_Images = size(IMAGE_FILES,1);
        
                START = 1500;
                END   = Number_Of_Images;

 START_END_FRAMES = [START END];
        
                           
        %%%%%%%%%%%%%%%%%%%%%%%%%
        %% start in init state %%
        %%%%%%%%%%%%%%%%%%%%%%%%%
        CURRENT_STATE = INIT_STATE;
        N_IMAGE       = START;
        PREV_INO      = 0;
        STEP_SIZE     = 1;
        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% for this number of images file %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
while N_IMAGE < START+1500
           
                        
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %% the master state contoller %%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            switch CURRENT_STATE
            
                case INIT_STATE
                    
                    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                    %% Prepare Inputs  %%
                    
                    global RES_VH LANE_FILTER LANE_PRIOR VP_FILTER VP_PRIOR
                    
                    
                    LANE_FILTER = single(LANE_FILTER);
                    LANE_PRIOR  = single(LANE_PRIOR);
                    VP_FILTER   = single(VP_FILTER);
                    VP_PRIOR    = single(VP_PRIOR);
                    
                    
                    
                    
                    laneFilter=struct;
                    laneFilter.mFilter =  LANE_FILTER;
                    laneFilter.mPrior  =  LANE_PRIOR;
                    
                    
                    vpFilter =struct;
                    vpFilter.mFilter =  VP_FILTER;
                    vpFilter.mPrior  =  VP_PRIOR;
                    
                    coder.cstructname(laneFilter, 'LaneFilter');
                    coder.cstructname(vpFilter,   'VanishingPtFilter');
                    
                    
                    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                    %%
                    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                
                     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                    %% Global variables : the lane markers map %%
                    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                    global TOT_P_ALL       %% the NBUFFER-frame probaility p(pixel|lane)
                    global DIR_ALL         %% the NBUFFER-frame combine gradient direction
                    global MASK_FOC_TOT_P  %% the single-frame binaray mask of all selected pixels (computed over NBUFFER frames)
                    global TOT_P           %% the single-frame probaility p(pixel|lane) (computed over NBUFFER frames)
                    global FOC_TOT_P       %% TOT_P multiplied by MASK_FOC_TOT_P
                    global AVG_DIR_TOT_P   %% the single-frame gradient direction p(pixel|lane) (computed over NBUFFER frames)
                    global IDX_LANE_PIX    %% the linear indices of pixels a priori likely to be lane markings
                    global TOT_P_ALL_BACK_UP
                    global DIR_ALL_BACK_UP 
                    global ROOT_DIR_TEMPLATE ROOT_FOCUS_TEMPLATE ROOT_IDEPTH_TEMPLATE VP_V VP_H OLD_VP_V OLD_VP_H
                    
                    %% perform state function
                    STATE_COUNTER = STATE_COUNTER + 1;
                    disp(['[STATE] INIT: ',num2str(STATE_COUNTER)])
                    RES_VH = int32(RES_VH);
                    NBUFFER = int32(NBUFFER);
                    [likelihoods, templates, vanishingPt, masks] = run_Init_State(RES_VH, NBUFFER, laneFilter, vpFilter );
                    RES_VH = single(RES_VH);
                    
                    
                    
                    %% Assign back to globals (Required for compatibility purpose)
                    
                    TOT_P_ALL       =    likelihoods.TOT_ALL;
                    DIR_ALL         =    likelihoods.GRADIENT_DIR_ALL;
        
                    FOC_TOT_P       =    likelihoods.TOT_FOCUSED;
                    
                    TOT_P           =    likelihoods.TOT_MAX;
                    
                    AVG_DIR_TOT_P   =    likelihoods.GRADIENT_DIR_AVG;
                    TOT_P_ALL_BACK_UP =  likelihoods.TOT_ALL_BACK_UP;
                    DIR_ALL_BACK_UP   =  likelihoods.GRADIENT_DIR_ALL_BACK_UP;
                    
        
                    MASK_FOC_TOT_P  =    masks.FOCUS; 
                    
                    IDX_LANE_PIX   = [];
                    
                    

                    ROOT_DIR_TEMPLATE       =    templates.GRADIENT_DIR_ROOT;
                    ROOT_FOCUS_TEMPLATE      =    templates.FOCUS_ROOT;
                    ROOT_IDEPTH_TEMPLATE    =    templates.DEPTH_ROOT;
                    
                    VP_V =        vanishingPt.V ;       
                    VP_H =        vanishingPt.H;
                    OLD_VP_V =    vanishingPt.V_prev;
                    OLD_VP_H =    vanishingPt.H_prev;
                  
                    

                     %% Take the Transition
                        CURRENT_STATE = FILLING_BUFFERS;
                        STATE_COUNTER = 0;
                    
                    
                     
                    case FILLING_BUFFERS
                
                     %% perform state function                    
                     disp(['[STATE] FILLING BUFFERS: ',num2str(STATE_COUNTER)])
                     msg           = run_Filling_Buffers_State( N_IMAGE );
             
                     %% check on transition
                     if msg == STATE_READY
                         CURRENT_STATE = DETECTING_EGO_LANE;
                         STATE_COUNTER = 0;
                     end
                     
                     
                 case DETECTING_EGO_LANE
                 
 
                     %% perform state function
                     N_IMAGE       = N_IMAGE + 1;
                     disp(['[STATE] DETECTING EGO LANE: ',num2str(STATE_COUNTER)])
                     msg           = run_Detecting_Ego_Lane_State( N_IMAGE );
                     
                     disp(['[STATE] DETECTING EGO LANE: ',num2str(STATE_COUNTER)])
                       
                     %% make a visualization 
                     showResults( N_IMAGE, msg );
                     
                     %% check on transition
                     if msg == STATE_ERROR
                         CURRENT_STATE = RESET_STATE;
                         STATE_COUNTER = 0;
                     end                    
                     
                 case RESET_STATE
                                
                     
                     %% perform state function
                     STATE_COUNTER = STATE_COUNTER + 1;
                     disp(['[STATE] RESET STATE: ',num2str(STATE_COUNTER)])
                     msg = run_Reset_State();
                                                     
                     %% check on transition
                     if msg == STATE_READY
                         CURRENT_STATE = DETECTING_EGO_LANE;
                         STATE_COUNTER = 0;
                     end
                  
            end
             
        
     end %% end dataset loop
   
end