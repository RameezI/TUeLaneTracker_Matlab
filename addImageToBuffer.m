          
           
%%
%% load an image
%% pre-process it
%% compute gradient
%% do filtering over time
%%            
function [ADDED, PROB_KEY] = addImageToBuffer( arg_RGB, PROB_KEY )

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    global  DIR_KEY PROB_KEY_BACK_UP PREV_INO STEP_SIZE NBUFFER NGRAY NYELL NSAT NMAG NDIR TOT_P_ALL DIR_ALL RES_VH IDEPTH_TEMPLATE DIR_TEMPLATE PROB_TEMPLATE VP_V VP_H ROOT_IDEPTH_TEMPLATE ROOT_DIR_TEMPLATE ROOT_PROB_TEMPLATE  RGB TOT_P_ALL_BACK_UP DIR_ALL_BACK_UP

%    global PROB_KEY
    
    RGB=arg_RGB;
    
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% load the image and resize %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     disp(['[MESSAGE] READING IMAGE ',num2str(nimage)])
%     IMG     = [IMAGE_FILES(nimage).folder,'/',IMAGE_FILES(nimage).name]
%     IMG     = imread(IMG);
%     imsz    = size(IMG);
% 
%     %%%%%%%%%%%%%%%%%%%%%%%%%%
%     %% already an RGB image %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%
% %%    if size(imsz, 2) == 3        
% 
% 
% %% Matlab RGB2Gray works only with unint8 --> resize do the conversion
% %  ^TODO: These two steps can be done using RGB-Gray filter that keeps it in double format. 
% 
%          RGB = imresize( IMG, [RES_VH(1) RES_VH(2)] );
%          RGB = im2double(RGB);
% 
% % %     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
% % %     %% probably raw Bumblebee frame %%
% % %     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% % %     else
% % % 
% % %        %%%%%%%%%%%%%%%%%%%%%%%%%
% % %        %% take top image only %%
% % %        %%%%%%%%%%%%%%%%%%%%%%%%%
% % %        IMG = IMG(1:imsz(1)/2,:);
% % % 
% % %        %%%%%%%%%%%%%
% % %        %% debayer %%
% % %        %%%%%%%%%%%%%
% % %        RGB = demosaic( IMG, 'grbg'); 
% % %        RGB = imresize( RGB, [RES_VH(1) RES_VH(2)] );
% % %        RGB = im2double(RGB);
% % %     end
% 
%     
%     
%     %%%%%%%%%%%%%%%%%
%     %% pre-process %%
%     %% what else?  %%
%     %%             %%
%     %%%%%%%%%%%%%%%%%
% % %     GRAD_SIGMA = 1.5; %% can be swept           
% % %     RGB = imfilter( RGB, fspecial('gaussian',11,GRAD_SIGMA), 'replicate' );


    
    %%
    %%
    %%
    %% create new prob and dir masks
    %%
    %%
%VP is in center-Image coordinate system---> convert to Image coordinate system
% Dir__Temp= ROOT_DIR_TEMPLATE (VP_imgcordinates : VP_imgcordinates+240)


    DIR_TEMPLATE         = ROOT_DIR_TEMPLATE(  (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, (RES_VH(2)-VP_H+1)-320:RES_VH(2)-VP_H+320 );
    PROB_TEMPLATE        = ROOT_PROB_TEMPLATE( (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, : ); 
    IDEPTH_TEMPLATE      = ROOT_IDEPTH_TEMPLATE( (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, : ); 
    DIR_TEMPLATE_BACK_UP = ROOT_DIR_TEMPLATE(  (RES_VH(1)+1)-240:RES_VH(1)+240, (RES_VH(2)+1)-320:RES_VH(2)+320 );
    
    
    
    %%
    %%
    %%
    %% GRADIENT COMPUTATION AND MAX POOLING
    %%
    %%
    %%



    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% get gradient by max pooling over I, S, V and SH %%
    %% other channels to pool over?                    %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    I   = rgb2gray(RGB);
    HSV = rgb2hsv(RGB);
    H   = HSV(:,:,1);
    S   = HSV(:,:,2);
    V   = HSV(:,:,3);       
    SH  = S.*H;
    
    %%%%%%%%%%%%%%
    %% gradient %%
    %%%%%%%%%%%%%%
    [MAGI  DIRI]  = getGradientInfo( I  );
    [MAGSH DIRSH] = getGradientInfo( SH ); 
    [MAGS  DIRS]  = getGradientInfo( S  ); 
    [MAGV  DIRV]  = getGradientInfo( V  );                
    MAG  = MAGI;
    DIR  = DIRI;  
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% max pooling over gradient strength %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    mask      = MAG < MAGSH;
    MAG(mask) = MAGSH(mask);
    DIR(mask) = DIRSH(mask);            
    mask      = MAG < MAGS;
    MAG(mask) = MAGS(mask);
    DIR(mask) = DIRS(mask);
    mask      = MAG < MAGV;
    MAG(mask) = MAGV(mask);
    DIR(mask) = DIRV(mask);



    %%
    %%
    %%
    %% PER-PIXEL LANE PROBABILITY
    %% PROBABILITY IS APPROX. USING MEMBERSHIP FUNCTIONS
    %%
    %%
    %%



    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% compute lane marker probabilities %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%GRAY_P = sigmf( V, NGRAY);
    
    GRAY_P = 1./(1 + exp(-NGRAY(1)*(V-NGRAY(2))));
 
    %YELL_P originally with dsigmf---->relpacing it with sigmf
    %^TODO: check the effect of replacing dsigmf with sigmf
    %YELL_P = dsigmf( H, [100 0.33]) .* sigmf( S, NSAT);
    
     %YELL_P = dsigmf( H, NYELL) .* sigmf( S, NSAT);
     YELL_P = (   (1./(1 + exp(-NYELL(1)*(H-NYELL(2))))) - (1./(1 + exp(-NYELL(3)*(H-NYELL(4)))))  ) .* (1./(1 + exp(-NSAT(1)*(S-NSAT(2))))) ;
    
    %MAG_P  = sigmf( MAG, NMAG);
    MAG_P = 1./(1 + exp(-NMAG(1)*(MAG-NMAG(2))));
    
    %DIR_P         = sigmf( abs(DIR-DIR_TEMPLATE),         NDIR );
    DIR_P = 1./(1 + exp(-NDIR(1)*(abs(DIR-DIR_TEMPLATE)-NDIR(2))));
    
    %DIR_P_BACK_UP = sigmf( abs(DIR-DIR_TEMPLATE_BACK_UP), NDIR );
    DIR_P_BACK_UP = 1./(1 + exp(-NDIR(1)*(abs(DIR-DIR_TEMPLATE_BACK_UP)-NDIR(2))));
    
    
    
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% compute total lane marker probability %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    PROB         = max(GRAY_P,YELL_P) .* MAG_P .* DIR_P;         %% prob with dir
    PROB_BACK_UP = max(GRAY_P,YELL_P) .* MAG_P .* DIR_P_BACK_UP; %% prob with dir back-up
    
    
    
      
    %%%%%%%%%%%%%%%%%%%%%%%
    %% compute threshold %%
    %%%%%%%%%%%%%%%%%%%%%%%
    GRAY_T = 0.5; %% 0.5 is the value of the "tipping" point of the membership functions
    YELL_T = 0.5.* 0.5;
    MAG_T  = 0.5;
    DIR_T  = 0.5;
    TOT_T  = min(GRAY_T,YELL_T).*MAG_T.*DIR_T;

   
    
    
%     %%%%%%%%%%%%%%%%%%%%
%     %% show prob maps %%.
%     %%%%%%%%%%%%%%%%%%%%
%     sfigure(123);
%     hold on
%     imshow([GRAY_P max(GRAY_P,YELL_P) MAG_P; DIR_P PROB TOT_T<=PROB]);
%     colormap jet
%     title('GRAY +YELL+GREEN MAG DIR TOTAL MASK')
%     drawnow
    


    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% only for first image in key frame segment %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    if 1 == STEP_SIZE
        PROB_KEY = PROB;
        DIR_KEY  = DIR;
        PROB_KEY_BACK_UP = PROB_BACK_UP;                
    end
    
    
    %%
    %%
    %% AUTO KEY-FRAMING
    %% does this frame add information
    %%
    %%
    %%
    mask1 = TOT_T < TOT_P_ALL(:,:,end); %% all pixels in the last image of the buffer above the threshold
    mask2 = TOT_T < PROB;               %% all pixels in the new image above the threshold
    mask3 = 0 < abs(mask2-mask1);       %% all pixels that chnaged in the new image wrt. the last image
    innovation = sum(mask3(:),1) / sum(mask1(:),1); %% as a percentage of all set pixels in the last image
    
    
    %disp(['[MESSAGE] INNOVATION ',num2str(innovation)])
    if innovation <= PREV_INO 
        
             %%%%%%%%%%%%%%%%%%%%%%%%%%
        %% track probs and dirs %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%
        TOT_P_ALL(:,:,1:NBUFFER-1) = TOT_P_ALL(:,:,2:NBUFFER);
        TOT_P_ALL(:,:,NBUFFER)     = PROB_KEY;
        DIR_ALL(:,:,1:NBUFFER-1)   = DIR_ALL(:,:,2:NBUFFER);
        DIR_ALL(:,:,NBUFFER)       = DIR_KEY;

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% track back-up probs and dirs %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        TOT_P_ALL_BACK_UP(:,:,1:NBUFFER-1) = TOT_P_ALL_BACK_UP(:,:,2:NBUFFER);
        TOT_P_ALL_BACK_UP(:,:,NBUFFER)     = PROB_KEY_BACK_UP;
        DIR_ALL_BACK_UP(:,:,1:NBUFFER-1)   = DIR_ALL_BACK_UP(:,:,2:NBUFFER);
        DIR_ALL_BACK_UP(:,:,NBUFFER)       = DIR_KEY;
    
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% flag indicating to continue %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        PREV_INO  = 0;
        STEP_SIZE = 1;
        ADDED     = 1;        
        disp(['[MESSAGE] ADDING KEY FRAME'])
        
    elseif 0.75 <= innovation || 10 <= STEP_SIZE %% no longer in increase in innovation OR innovation in good enough OR step size is large enough
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%
        %% track probs and dirs %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%
        PROB_KEY= PROB;
        TOT_P_ALL(:,:,1:NBUFFER-1) = TOT_P_ALL(:,:,2:NBUFFER);
        TOT_P_ALL(:,:,NBUFFER)     = PROB_KEY;
        DIR_ALL(:,:,1:NBUFFER-1)   = DIR_ALL(:,:,2:NBUFFER);
        DIR_ALL(:,:,NBUFFER)       = DIR_KEY;

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% track back-up probs and dirs %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        TOT_P_ALL_BACK_UP(:,:,1:NBUFFER-1) = TOT_P_ALL_BACK_UP(:,:,2:NBUFFER);
        TOT_P_ALL_BACK_UP(:,:,NBUFFER)     = PROB_KEY_BACK_UP;
        DIR_ALL_BACK_UP(:,:,1:NBUFFER-1)   = DIR_ALL_BACK_UP(:,:,2:NBUFFER);
        DIR_ALL_BACK_UP(:,:,NBUFFER)       = DIR_KEY;
    
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% flag indicating to continue %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        PREV_INO  = 0;
        STEP_SIZE = 1;
        ADDED     = 1;        
        disp(['[MESSAGE] ADDING KEY FRAME'])
                 
   
        
    else

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% flag indicating keep searching for key-frame %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        PROB_KEY         = PROB;
        DIR_KEY          = DIR;
        PROB_KEY_BACK_UP = PROB_BACK_UP;
        PREV_INO         = innovation;
        STEP_SIZE = STEP_SIZE + 1;
        ADDED     = 0;
        
    end
        
end
