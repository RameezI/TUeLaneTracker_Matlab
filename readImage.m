function[RGB] = readImage( nimage )

    
    %%Required Globals%%
    global   RES_VH   IMAGE_FILES

   
    
    %%
    %% Load the Image and Resize %%
    
    disp(['[MESSAGE] READING IMAGE ',num2str(nimage)])
    IMG     = [IMAGE_FILES(nimage).folder,'/',IMAGE_FILES(nimage).name]
    IMG     = imread(IMG);   
    RGB = imresize( IMG, [RES_VH(1) RES_VH(2)] );
    %RGB  = im2single(RGB);
    
end