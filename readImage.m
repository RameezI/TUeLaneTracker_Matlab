function[RGB] = readImage( nimage )

    
    %%Required Globals%%
    global   RES_VH   IMAGE_FILES   N_IMAGE

   
    
    %%
    %% Load the Image and Resize %%
    
    disp(['[MESSAGE] READING IMAGE ',num2str(nimage)])
    IMG     = [IMAGE_FILES(nimage).folder,'/',IMAGE_FILES(nimage).name]
    IMG     = imread(IMG);   
    RGB = imresize( IMG, [RES_VH(1) RES_VH(2)] );
    %RGB  = im2single(RGB);
         
    
    %%
    %% Pre-process %%
   
%    GRAD_SIGMA = 1.5; %% can be swept           
%    RGB = imfilter( RGB, fspecial('gaussian',11,GRAD_SIGMA), 'replicate' );
         
     N_IMAGE = N_IMAGE+1;
end