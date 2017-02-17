%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%%
%% Test the use of steerable filtere
function [] = gradientTest()

    %% make sure plot data is clean
    clear all
    close all

    %% TUE
    global DATASET IMAGE_FILES
%     DATASET = '/data2/datasets/binocular/prius/images';
%     DATASET = '/media/gijs/51581ef4-87a3-4aa5-834e-2c9a1f8321ed';
    DATASET = 'I:\datasets\binocular\prius\images\eindhoven-20150819-123327-417';
    
    %%%%%%%%%%%%%%%%%%%%
    %% get all images %%
    %%%%%%%%%%%%%%%%%%%%
    DATASET
    IMAGE_FILES = dir([DATASET,'\*.png']);
    if 0 == size(IMAGE_FILES,1)
        IMAGE_FILES = dir([DATASET,'\*.ppm']);        
    end
    Number_Of_Images = size(IMAGE_FILES,1)
                          
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    %% for each dataset that is labeled %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
    for nimg = 1:Number_Of_Images
                         
        add_Image_To_Buffer( nimg );            
       
    end %% end dataset loop
    
    
end %% end funciton
            
    




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%%
%%           
%%          
%%           HIGH-LEVEL FUNCTIONS  
%%       
%%
%% 
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    
    

           
           
%%
%% load an image
%% pre-process it
%% compute gradient
%% do filtering over time
%%            
function [ADDED] = add_Image_To_Buffer( nimage )

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    global DATASET IMAGE_FILES

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% load the image and resize %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    disp(['[MESSAGE] READING IMAGE ',num2str(nimage)])
    IMG     = [DATASET,'/',IMAGE_FILES(nimage).name]
    IMG     = imread(IMG);
    imsz    = size(IMG);

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% already an RGB image %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    if size(imsz,2) == 3        

        RGB = im2double(RGB);

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    %% probably raw Bumblebee frame %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    else

       %%%%%%%%%%%%%%%%%%%%%%%%%
       %% take top image only %%
       %%%%%%%%%%%%%%%%%%%%%%%%%
       IMG = IMG(1:imsz(1)/2,:);

       %%%%%%%%%%%%%
       %% debayer %%
       %%%%%%%%%%%%%
       RGB = demosaic( IMG, 'grbg'); 
       RGB = im2double(RGB);
    end

    %%%%%%%%%%%%%%
    %% gradient %%
    %%%%%%%%%%%%%%
    GRAD_SIGMA = 1.5; %% can be swept           
    I             = imfilter( RGB, fspecial('gaussian',11,GRAD_SIGMA), 'replicate' );
    I             = rgb2gray(I);
    [MAGI  DIRI]  = getGradientInfo( I,  0 );
 
    %%%%%%%%%%
    %% show %%
    %%%%%%%%%%
    figure(1)
    imshow(RGB)
    drawnow
        
    figure(2)
    imshow(DIRI,[0 180])
    colormap jet
    drawnow
    
    %%%%%%%%%%%%%%%%%%%%%%
    %% steerable filter %%
    %%%%%%%%%%%%%%%%%%%%%%
    I             = rgb2gray(RGB);
    [MAGI  DIRI]  = getGradientInfoSteerableFilter( I,  0 );
    
    %%%%%%%%%%
    %% show %%
    %%%%%%%%%%        
    figure(3)
    imshow(DIRI,[-90 90])
    colormap jet
    drawnow
    pause
    
end




