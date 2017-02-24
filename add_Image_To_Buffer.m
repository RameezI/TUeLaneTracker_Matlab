          
function [ADDED, Templates, Likelihoods, Masks] = add_Image_To_Buffer( RGB, VanishingPt, Templates, Likelihoods, Masks  )


%%Required Global Variables %%
global  DIR_KEY PROB_KEY  PREV_INO STEP_SIZE NBUFFER NGRAY NMAG NDIR  RES_VH              

 
%%Local Variables Extracted from Arguments%%
VP_V = VanishingPt.V;
VP_H = VanishingPt.H;


%%
%% Get Channels %%

    I       = rgb2gray(RGB);
    %HSV     = rgb2hsv(RGB);
    %H       = HSV(:,:,1);
    %S       = HSV(:,:,2);
    %V       = HSV(:,:,3);
    %SH      = S.*H;
    
    I  = im2single(I);
    
    
%%
%% PreProcessing %%
    GRAD_SIGMA = 1.5; %% can be swept           
    I = imfilter( I, fspecial('gaussian',11,GRAD_SIGMA), 'replicate' );
    
    
    
%%
%% Get Gradients %%
    
[MAGI, DIRI]   =  getGradientInfo( I  );
%[MAGSH, DIRSH] = getGradientInfo( SH ); 
%[MAGS, DIRS]   = getGradientInfo( S  ); 
%[MAGV, DIRV]   = getGradientInfo( V  );                
    
   

%%
%% Extract From Templates %%


Masks.FOCUS             = Templates.FOCUS_ROOT( (RES_VH(1)-VP_V+1)-240 : RES_VH(1)-VP_V+240, : );

Templates.GRADIENT_DIR  = Templates.GRADIENT_DIR_ROOT(  (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, (RES_VH(2)-VP_H+1)-320:RES_VH(2)-VP_H+320 );
Templates.DEPTH         = Templates.DEPTH_ROOT( (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, : ); 


    



%%
%% MAX POOLING %%
  
%[MAG, DIR] = maxPool_Gradients(MAGI, MAGSH, MAGS, MAGV, DIRI, DIRSH, DIRS, DIRV );

% Without Max Pooling
MAG = MAGI;    
DIR = DIRI;




%%
%% Compute Lane Marker Probabilities %% 



%[PROB, PROB_BACK_UP] = laneMarkerProbabilities( NGRAY, NYELL, NSAT, NMAG, NDIR, S, H, V, MAG, DIR, DIR_TEMPLATE, DIR_TEMPLATE_BACK_UP);

% Without HSV Channels
 PROB = laneMarkerProbabilities( NGRAY, NMAG, NDIR, I,  MAG, DIR, Templates.GRADIENT_DIR);
    
      
 
if STEP_SIZE == 1
    
    PROB_KEY = PROB;
    DIR_KEY  = DIR;
    
end

    
    innovation = autoKeyFraming(Likelihoods.TOT_ALL(:,:,end), PROB);

    
    % No longer increase in innovation %%
    if innovation <= PREV_INO             

            [Likelihoods] = updateLaneLikelihoods(NBUFFER, PROB_KEY,  DIR_KEY, Likelihoods);

            PREV_INO  = 0;
            STEP_SIZE = 1;
            ADDED     = 1;        
            disp(['[MESSAGE] ADDING KEY FRAME'])
    
    % Innovation is good enough OR step size is large enough
    elseif 0.75 <= innovation || 10 <= STEP_SIZE 
            
        
           PROB_KEY= PROB;
          [Likelihoods] = updateLaneLikelihoods(NBUFFER, PROB_KEY,  DIR_KEY, Likelihoods);
          
            PREV_INO  = 0;
            STEP_SIZE = 1;
            ADDED     = 1;        
            disp(['[MESSAGE] ADDING KEY FRAME'])

    
    % Otherwise
    else
            PROB_KEY         = PROB;
            DIR_KEY          = DIR;
            PREV_INO         = innovation;
            STEP_SIZE = STEP_SIZE + 1;
            ADDED     = 0;

    end

        
end
