function [] = verifyData(nimage)


N =1;
while N<nimage  
RES_VH     = [480 640]; %% resolution of camera

DATASET = '/media/rameez/Linux-Extended/DataSet/eindhoven/';   
IMAGE_FILES= dir([DATASET,'/PNG_imgs/*.png']);


DATASET
disp(['[MESSAGE] READING IMAGE ',num2str(N)])



IMG     = [IMAGE_FILES(N).folder,'/',IMAGE_FILES(N).name]
IMG     = imread(IMG);

RGB = imresize( IMG, [RES_VH(1) RES_VH(2)] );
RGB  = im2single(RGB);
         
         
 GRAD_SIGMA = 1.5; %% can be swept           
 RGB = imfilter( RGB, fspecial('gaussian',11,GRAD_SIGMA), 'replicate' );
 
 
 %%
%% Get Channels %%
    
    I       = rgb2gray(RGB);
    HSV     = rgb2hsv(RGB);
    H       = HSV(:,:,1);
    S       = HSV(:,:,2);
    V       = HSV(:,:,3);       
    SH      = S.*H;
    
%%
%% Get Gradients %%
    
 [MAGI, DIRI]   = getGradientInfo( I  );
 [MAGSH, DIRSH] = getGradientInfo( SH ); 
 [MAGS, DIRS]   = getGradientInfo( S  ); 
 [MAGV, DIRV]   = getGradientInfo( V  );     
 
N=N+1;
imshow(H);
end
end