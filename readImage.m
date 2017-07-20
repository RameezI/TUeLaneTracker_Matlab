function[RGB, GRAY_OPENCV] = readImage( nimage )

    
    %%Required Globals%%
    global   RES_VH   IMAGE_FILES IMAGE_FILES_OPENCV

   
    
    %%
    %% Load the Image and Resize %%
    
    disp(['[MESSAGE] READING IMAGE ',num2str(nimage)])
    IMG     = [IMAGE_FILES(nimage).folder,'/',IMAGE_FILES(nimage).name]
    RGB     = imread(IMG);   
    RGB = imresize( RGB, [RES_VH(1) RES_VH(2)] );
    
    IMG     = [IMAGE_FILES_OPENCV(nimage).folder,'/',IMAGE_FILES_OPENCV(nimage).name]
    GRAY_OPENCV  = imread(IMG);

    
end