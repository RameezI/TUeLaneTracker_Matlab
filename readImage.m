function[RGB] = readImage( nimage )

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    global   RES_VH   IMAGE_FILES   N_IMAGE

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% load the image and resize %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    disp(['[MESSAGE] READING IMAGE ',num2str(nimage)])
    IMG     = [IMAGE_FILES(nimage).folder,'/',IMAGE_FILES(nimage).name]
    IMG     = imread(IMG);

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% already an RGB image %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%
%%    if size(imsz, 2) == 3        


%% Matlab RGB2Gray works only with unint8 --> resize do the conversion
%  ^TODO: These two steps can be done using RGB-Gray filter that keeps it in double format. 

         RGB = imresize( IMG, [RES_VH(1) RES_VH(2)] );
         %RGB = im2double(RGB);
         RGB  = im2single(RGB);
         
%%
%% Pre-process %%
%%    GRAD_SIGMA = 1.5; %% can be swept           
%%    RGB = imfilter( RGB, fspecial('gaussian',11,GRAD_SIGMA), 'replicate' );
         
         N_IMAGE = N_IMAGE+1;
end