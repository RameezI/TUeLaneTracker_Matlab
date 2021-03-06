          
function [Templates, Likelihoods, Mask] = add_Image_To_Buffer( RGB, VanishingPt, Templates, Likelihoods, Mask)




%%Required Global Variables %%
global  NBUFFER RES_VH  tippingPoint_gradMag tippingPoint_gray          
 
%%Local Variables Extracted from Arguments%%
VP_V = VanishingPt.V;
VP_H = VanishingPt.H;



    I = rgb2gray(RGB);   
    I  = im2single(I);

    
%%
%% PreProcessing %%
    
    GRAD_SIGMA = 1.5; %% can be swept               
    I = imfilter( I, fspecial('gaussian',5,GRAD_SIGMA), 'replicate' );
    I_uint8 = im2uint8(I);



% %% Get Gradients %%    
%     [MAGI, tanDIRI]   =  getGradientInfo( I_uint8  );


%%
%% Extract From Templates %%


    % By Changing the sigh 0f VP_V, the logic for selecting less or more
    % pixels could be altereed.The - signs implies that if VP moves up,
    % more pixels will be activated.
    
    %Note: VP is -ve when moved up
    
    start= Mask.VP_RANGE_V-VP_V; %% VP_V must be in center coordinate system
    
    span= floor(RES_VH(1)/2)-Mask.Margin + Mask.VP_RANGE_V;

    Mask.FOCUS                  = Templates.FOCUS_ROOT( start +1: start + span, : );

     
    Templates.GRADIENT_DIR      = Templates.GRADIENT_DIR_ROOT(  (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, (RES_VH(2)-VP_H+1)-320:RES_VH(2)-VP_H+320 );
    TemplateGradientDir_tangent = imcrop(Templates.GRADIENT_DIR, [1,RES_VH(1)-span+1,RES_VH(2), span]);
    
    
    Templates.DEPTH     = Templates.DEPTH_ROOT( (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, : ); 
    Templates.DEPTH     = imcrop(Templates.DEPTH,        [1,RES_VH(1)-span+1,RES_VH(2), span]);  

        
    %Templates.DEPTH         = Templates.DEPTH_ROOT( (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, : ); 
    %Templates.DEPTH          = imcrop(Templates.DEPTH_ROOT, [1,RES_VH(1)-span+1,RES_VH(2), span]);   

    I_uint8                  = imcrop  (I_uint8,     [1,RES_VH(1)-span+1,RES_VH(2), span]);
 
    %% Get Gradients %%    
    [MAG, tanDIR]            =  getGradientInfo( I_uint8  );
    %MAG                      = imcrop  (MAGI,        [1,RES_VH(1)-span+1,RES_VH(2), span]);    
    %tanDIR                   = imcrop  (tanDIRI,     [1,RES_VH(1)-span+1,RES_VH(2), span]);





%%
%% Compute Lane Marker Probabilities %% 

 PROB = laneMarkerProbabilities( tippingPoint_gray, tippingPoint_gradMag, I_uint8, MAG, tanDIR, TemplateGradientDir_tangent);
    
 [Likelihoods] = updateLaneLikelihoods(NBUFFER, PROB,  tanDIR, Likelihoods);
     
        
end
