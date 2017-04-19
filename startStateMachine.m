function  [] = startStateMachine()

global LANE_FILTER LANE_PRIOR VP_FILTER VP_PRIOR  CENTER_OFFSET NBUFFER IMAGE_FILES INIT_STATE  STATE_READY  STEP_SIZE CURRENT_STATE PREV_INO STATE_COUNTER  FILLING_BUFFERS DETECTING_EGO_LANE RESET_STATE START_END_FRAMES STATE_ERROR 
global VP_RANGE_V;
global RES_VH

NBUFFER       = 3;
CENTER_OFFSET = 0.5;



%% 
%%  Obtain the number of Images, Start and End Index %%
Number_Of_Images = size(IMAGE_FILES,1);
        
                START = 500;
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
       
        %% Booting %%
        
             case INIT_STATE
                 
                STATE_COUNTER = STATE_COUNTER + 1;
                disp(['[STATE] INIT: ',num2str(STATE_COUNTER)])
                RES_VH = int32(RES_VH);
                NBUFFER = int32(NBUFFER);
                [likelihoods, templates, vanishingPt, FocusMask] = run_Init_State(RES_VH, NBUFFER, VP_RANGE_V);
                RES_VH = single(RES_VH);

                %%Transition
                CURRENT_STATE = FILLING_BUFFERS;
                STATE_COUNTER = 0;

        %% Filling Buffers
        
            case FILLING_BUFFERS

               STATE_COUNTER = STATE_COUNTER + 1;
               disp(['[STATE] FILLING_BUFFERS: ',num2str(STATE_COUNTER)])
                
               [msg, templates, likelihoods, FocusMask ]= run_Filling_Buffers_State(N_IMAGE, NBUFFER, vanishingPt, templates, likelihoods, FocusMask);
             
               %%Transition
               
                if msg == STATE_READY
                    
                 CURRENT_STATE = DETECTING_EGO_LANE;
                 STATE_COUNTER = 0;
                
                else
                    
                 N_IMAGE =   N_IMAGE +1;
                 STATE_COUNTER = STATE_COUNTER +1;
                 
                end

        %% Detecting Ego-Lane                     
            case DETECTING_EGO_LANE
                
                 STATE_COUNTER = STATE_COUNTER + 1;
                 disp(['[STATE] DETECTING EGO LANE: ',num2str(STATE_COUNTER)])

                 [msg, vanishingPt,templates, likelihoods, FocusMask] = run_Detecting_Ego_Lane_State(N_IMAGE, vanishingPt, templates, likelihoods, FocusMask);

                 %%Transition
                 if msg == STATE_ERROR
                     
                     CURRENT_STATE = RESET_STATE;
                     STATE_COUNTER = 0;
                     
                 else
                         N_IMAGE =   N_IMAGE +1;
                         STATE_COUNTER = STATE_COUNTER +1;
                     
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