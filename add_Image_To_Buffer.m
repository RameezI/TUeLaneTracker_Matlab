          
function [Templates, Likelihoods, Mask] = add_Image_To_Buffer( RGB, VanishingPt, Templates, Likelihoods, Mask)




%%Required Global Variables %%
global   NBUFFER NGRAY NMAG NDIR  RES_VH  tippingPoint_gradMag tippingPoint_gray          

 
%%Local Variables Extracted from Arguments%%
VP_V = VanishingPt.V;
VP_H = VanishingPt.H;


%%
%% Get Channels %%

    I       = rgb2gray(RGB);
%     HSV     = rgb2hsv(RGB);
%     H       = HSV(:,:,1);
%     S       = HSV(:,:,2);
%     V       = HSV(:,:,3);
    
    I  = im2single(I);
%     V  = im2single(V);
    
%%
%% PreProcessing %%
    
    GRAD_SIGMA = 1.5; %% can be swept               
    I = imfilter( I, fspecial('gaussian',5,GRAD_SIGMA), 'replicate' );
    
%      V = imfilter( V, fspecial('gaussian',5,GRAD_SIGMA), 'replicate' );
%      S = imfilter( S, fspecial('gaussian',5,GRAD_SIGMA), 'replicate' );
% %     H = imfilter( H, fspecial('gaussian',5,GRAD_SIGMA), 'replicate' );    

    I_uint8 = im2uint8(I);


%%
%% Get Gradients %%    
%[MAGI, tanDIRI]   =  getGradientInfo( I_uint8  );
 [MAGI, tanDIRI]   =  getGradientInfo( I_uint8  );

% % MAGI= single(MAGI).*BW;
% MAGI =uint8(MAGI);

% [MAGH, DIRH]    =  getGradientInfo(H_uint8); 

% MAGI= BW.*single(MAGI);
 
%    figure(220);
%    imshow(MAGI , [0, 255]);


%[MAGS, DIRS]   = getGradientInfo( S  ); 
%[MAGV, DIRV]   = getGradientInfo( V  ); 


%%
%% Extract From Templates %%

start= Mask.VP_RANGE_V-VP_V;
span= floor(RES_VH(1)/2)-Mask.Margin + Mask.VP_RANGE_V;

Mask.FOCUS              = Templates.FOCUS_ROOT( start +1: start + span, : );



Templates.GRADIENT_DIR  = Templates.GRADIENT_DIR_ROOT(  (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, (RES_VH(2)-VP_H+1)-320:RES_VH(2)-VP_H+320 );
TemplateGradientDir_tangent = imcrop(Templates.GRADIENT_DIR, [1,RES_VH(1)-span+1,RES_VH(2), span]);

Templates.DEPTH     = Templates.DEPTH_ROOT( (RES_VH(1)-VP_V+1)-240:RES_VH(1)-VP_V+240, : ); 
Templates.DEPTH     = imcrop(Templates.DEPTH,        [1,RES_VH(1)-span+1,RES_VH(2), span]);   


I_uint8  = imcrop (I_uint8,     [1,RES_VH(1)-span+1,RES_VH(2), span]);
MAG      = imcrop (MAGI,        [1,RES_VH(1)-span+1,RES_VH(2), span]);    
tanDIR   = imcrop  (tanDIRI,     [1,RES_VH(1)-span+1,RES_VH(2), span]);






%     figure(100)
%     imshow(TemplateGradientDir,[0 pi])
%     pause


%%
%% Compute Lane Marker Probabilities %% 


 PROB = laneMarkerProbabilities( tippingPoint_gray, tippingPoint_gradMag, I_uint8, MAG, tanDIR, TemplateGradientDir_tangent);
    
 [Likelihoods] = updateLaneLikelihoods(NBUFFER, PROB,  tanDIR, Likelihoods);
     
        
end
