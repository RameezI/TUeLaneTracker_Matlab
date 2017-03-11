function  [] = startStateMachine()

global  N_IMAGE RES_VH LANE_FILTER LANE_PRIOR VP_FILTER VP_PRIOR  CENTER_OFFSET NBUFFER IMAGE_FILES INIT_STATE  STATE_READY  STEP_SIZE CURRENT_STATE PREV_INO STATE_COUNTER  FILLING_BUFFERS DETECTING_EGO_LANE RESET_STATE START_END_FRAMES STATE_ERROR 
       
NBUFFER       = 3;
CENTER_OFFSET = 0.5;



%% 
%%  Obtain the number of Images, Start and End Index %%
Number_Of_Images = size(IMAGE_FILES,1);
        
                START = 4600;
                END   = Number_Of_Images;

START_END_FRAMES = [START END];

 

%% 
%% Instantiate laneFilter and vpFilter structures %% 
 LANE_FILTER = single(LANE_FILTER);
 LANE_PRIOR  = single(LANE_PRIOR);
 VP_FILTER   = single(VP_FILTER);
 VP_PRIOR    = single(VP_PRIOR);    
                    
%  laneFilter=struct;
%     laneFilter.mFilter =  LANE_FILTER;
%     laneFilter.mPrior  =  LANE_PRIOR;
%                     
%                     
%  vpFilter =struct;
%     vpFilter.mFilter =  VP_FILTER;
%     vpFilter.mPrior  =  VP_PRIOR;

    
%%
%%  Statrt From the InitState %%
 
CURRENT_STATE = INIT_STATE;
N_IMAGE       = START;
PREV_INO      = 0;
STEP_SIZE     = 1;




while N_IMAGE < END
           
                        
     switch CURRENT_STATE
         
         case INIT_STATE
%%
% coder.cstructname(laneFilter, 'LaneFilter');
% coder.cstructname(vpFilter,   'VanishingPtFilter');
%%

%                 global TOT_P_ALL       %% the NBUFFER-frame probaility p(pixel|lane)
%                 global DIR_ALL         %% the NBUFFER-frame combine gradient direction
%                 global MASK_FOC_TOT_P  %% the single-frame binaray mask of all selected pixels (computed over NBUFFER frames)
%                 global TOT_P           %% the single-frame probaility p(pixel|lane) (computed over NBUFFER frames)
%                 global FOC_TOT_P       %% TOT_P multiplied by MASK_FOC_TOT_P
%                 global AVG_DIR_TOT_P   %% the single-frame gradient direction p(pixel|lane) (computed over NBUFFER frames)
%                 global IDX_LANE_PIX    %% the linear indices of pixels a priori likely to be lane markings
%                 global TOT_P_ALL_BACK_UP
%                 global DIR_ALL_BACK_UP 
%                 global ROOT_DIR_TEMPLATE ROOT_FOCUS_TEMPLATE ROOT_IDEPTH_TEMPLATE VP_V VP_H OLD_VP_V OLD_VP_H
       
            
            STATE_COUNTER = STATE_COUNTER + 1;
            disp(['[STATE] INIT: ',num2str(STATE_COUNTER)])
            RES_VH = int32(RES_VH);
            NBUFFER = int32(NBUFFER);
            [likelihoods, templates, vanishingPt, masks] = run_Init_State(RES_VH, NBUFFER);
            
            likelihoods_Backup = likelihoods;
            templates_Backup  = templates;
            vanishingPt_Backup = vanishingPt;
            masks_Backup       = masks;
            
            RES_VH = single(RES_VH);
                      

            %%Transition
            CURRENT_STATE = FILLING_BUFFERS;
            STATE_COUNTER = 0;
                    
                    
                    
        case FILLING_BUFFERS
                
             [msg, templates, likelihoods, masks ]= run_Filling_Buffers_State(vanishingPt, templates, likelihoods, masks );
             
            %%Transition
                     if msg == STATE_READY
                         CURRENT_STATE = DETECTING_EGO_LANE;
                         STATE_COUNTER = 0;
                     end
                     
%%                     
        case DETECTING_EGO_LANE
                 
             N_IMAGE       = N_IMAGE + 1;
             disp(['[STATE] DETECTING EGO LANE: ',num2str(STATE_COUNTER)])
             
             [msg, vanishingPt,templates, likelihoods, masks]        = run_Detecting_Ego_Lane_State(vanishingPt, templates, likelihoods, masks );

             disp(['[STATE] DETECTING EGO LANE: ',num2str(STATE_COUNTER)])
                       
                      
             
                     
             %%Transition
             if msg == STATE_ERROR
                 CURRENT_STATE = RESET_STATE;
                 STATE_COUNTER = 0;
             end
             
             
             
         case RESET_STATE
                                
                     
                     %% perform state function
                     STATE_COUNTER = STATE_COUNTER + 1;
                     disp(['[STATE] RESET STATE: ',num2str(STATE_COUNTER)])
                     %[msg, vanishingPt, likelihoods, templates, masks] = run_Reset_State(likelihoods_Backup, templates_Backup, vanishingPt_Backup, masks_Backup);
                      
                     msg= STATE_READY;
                     %% check on transition
                     if msg == STATE_READY
                         CURRENT_STATE = DETECTING_EGO_LANE;
                         STATE_COUNTER = 0;
                     end
                  
            end
             
        
     end %% end dataset loop
   
end