          
           
%%
%% load an image
%% pre-process it
%% compute gradient
%% do filtering over time
%%            
function [ADDED] = add_Image_To_Buffer( arg_RGB )

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    global  DIR_KEY PROB_KEY PROB_KEY_BACK_UP PREV_INO STEP_SIZE NBUFFER NGRAY NYELL NSAT NMAG NDIR TOT_P_ALL DIR_ALL RES_VH IDEPTH_TEMPLATE  FOCUS_TEMPLATE  DIR_TEMPLATE  VP_V VP_H ROOT_IDEPTH_TEMPLATE ROOT_DIR_TEMPLATE ROOT_FOCUS_TEMPLATE RGB TOT_P_ALL_BACK_UP DIR_ALL_BACK_UP

    
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% SELF-CODE-SECTION-STARTS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   
    
%%
%% RGB Image Recived %%
    
    RGB=arg_RGB;


%%
%% Get Channels %%
    
    I       = rgb2gray(RGB);
    %HSV     = rgb2hsv(RGB);
    %H       = HSV(:,:,1);
    %S       = HSV(:,:,2);
    %V       = HSV(:,:,3);
    %SH      = S.*H;
    
    %%
%% Pre-process %%
    GRAD_SIGMA = 1.5; %% can be swept           
    I = imfilter( I, fspecial('gaussian',11,GRAD_SIGMA), 'replicate' );
    
%%
%% Get Gradients %%
    
[MAGI, DIRI]   = getGradientInfo( I  );
%[MAGSH, DIRSH] = getGradientInfo( SH ); 
%[MAGS, DIRS]   = getGradientInfo( S  ); 
%[MAGV, DIRV]   = getGradientInfo( V  );                
    
   

%%
%% Extract Templates %%

DIR_TEMPLATE         = ROOT_DIR_TEMPLATE(  (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, (RES_VH(2)-VP_H+1)-320:RES_VH(2)-VP_H+320 );
FOCUS_TEMPLATE        = ROOT_FOCUS_TEMPLATE( (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, : );
IDEPTH_TEMPLATE      = ROOT_IDEPTH_TEMPLATE( (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, : ); 
DIR_TEMPLATE_BACK_UP = ROOT_DIR_TEMPLATE(  (RES_VH(1)+1)-240:RES_VH(1)+240, (RES_VH(2)+1)-320:RES_VH(2)+320 );
    

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% SELF-CODE-SECTION-ENDS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                                                    %%%%%%%%%%%%%%%%%%%%
    
    
    
%%
%%MAX POOLING %%
  
%[MAG, DIR] = maxPool_Gradients(MAGI, MAGSH, MAGS, MAGV, DIRI, DIRSH, DIRS, DIRV );

%%Without Max Pooling
MAG = MAGI;    
DIR = DIRI;

%%
%% Compute lane marker probabilities %% 


%%Temporary modifications by Rameez
 %[PROB, PROB_BACK_UP] = laneMarkerProbabilities( NGRAY, NYELL, NSAT, NMAG, NDIR, S, H, V, MAG, DIR, DIR_TEMPLATE, DIR_TEMPLATE_BACK_UP);
 
 [PROB, PROB_BACK_UP] = laneMarkerProbabilities( NGRAY, NYELL, NSAT, NMAG, NDIR, I,  MAG, DIR, DIR_TEMPLATE, DIR_TEMPLATE_BACK_UP);
    
      
 
if STEP_SIZE == 1
    
    PROB_KEY = PROB;
    DIR_KEY  = DIR;
    PROB_KEY_BACK_UP = PROB_BACK_UP;  
    
end

    
    innovation = autoKeyFraming(TOT_P_ALL(:,:,end), PROB);

    %%
    %% No longer increase in innovation %%
    if innovation <= PREV_INO             

            %Update_Likelihoods(TOT_P_ALL, DIR_ALL, TOT_P_ALL_BACK_UP )
            [TOT_P_ALL, DIR_ALL,TOT_P_ALL_BACK_UP, DIR_ALL_BACK_UP] = updateLaneLikelihoods(NBUFFER, PROB_KEY,  DIR_KEY, PROB_KEY_BACK_UP, TOT_P_ALL, DIR_ALL,TOT_P_ALL_BACK_UP, DIR_ALL_BACK_UP );

%             TOT_P_ALL(:,:,1:NBUFFER-1) = TOT_P_ALL(:,:,2:NBUFFER);
%             TOT_P_ALL(:,:,NBUFFER)     = PROB_KEY;
%             DIR_ALL(:,:,1:NBUFFER-1)   = DIR_ALL(:,:,2:NBUFFER);
%             DIR_ALL(:,:,NBUFFER)       = DIR_KEY;
% 
%             TOT_P_ALL_BACK_UP(:,:,1:NBUFFER-1) = TOT_P_ALL_BACK_UP(:,:,2:NBUFFER);
%             TOT_P_ALL_BACK_UP(:,:,NBUFFER)     = PROB_KEY_BACK_UP;
%             DIR_ALL_BACK_UP(:,:,1:NBUFFER-1)   = DIR_ALL_BACK_UP(:,:,2:NBUFFER);
%             DIR_ALL_BACK_UP(:,:,NBUFFER)       = DIR_KEY;


            PREV_INO  = 0;
            STEP_SIZE = 1;
            ADDED     = 1;        
            disp(['[MESSAGE] ADDING KEY FRAME'])
    %%
    %% Innovation is good enough OR step size is large enough
    elseif 0.75 <= innovation || 10 <= STEP_SIZE 
            
        
           PROB_KEY= PROB;
          [TOT_P_ALL, DIR_ALL,TOT_P_ALL_BACK_UP, DIR_ALL_BACK_UP] = updateLaneLikelihoods(NBUFFER, PROB_KEY,  DIR_KEY, PROB_KEY_BACK_UP, TOT_P_ALL, DIR_ALL,TOT_P_ALL_BACK_UP, DIR_ALL_BACK_UP );

            
%             TOT_P_ALL(:,:,1:NBUFFER-1) = TOT_P_ALL(:,:,2:NBUFFER);
%             TOT_P_ALL(:,:,NBUFFER)     = PROB_KEY;
%             DIR_ALL(:,:,1:NBUFFER-1)   = DIR_ALL(:,:,2:NBUFFER);
%             DIR_ALL(:,:,NBUFFER)       = DIR_KEY;
% 
% 
%             TOT_P_ALL_BACK_UP(:,:,1:NBUFFER-1) = TOT_P_ALL_BACK_UP(:,:,2:NBUFFER);
%             TOT_P_ALL_BACK_UP(:,:,NBUFFER)     = PROB_KEY_BACK_UP;
%             DIR_ALL_BACK_UP(:,:,1:NBUFFER-1)   = DIR_ALL_BACK_UP(:,:,2:NBUFFER);
%             DIR_ALL_BACK_UP(:,:,NBUFFER)       = DIR_KEY;


            PREV_INO  = 0;
            STEP_SIZE = 1;
            ADDED     = 1;        
            disp(['[MESSAGE] ADDING KEY FRAME'])

    %%
    %% Otherwise
    else
            PROB_KEY         = PROB;
            DIR_KEY          = DIR;
            PROB_KEY_BACK_UP = PROB_BACK_UP;
            PREV_INO         = innovation;
            STEP_SIZE = STEP_SIZE + 1;
            ADDED     = 0;

    end

        
end
