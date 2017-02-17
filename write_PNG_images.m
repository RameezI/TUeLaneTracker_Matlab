function []= write_PNG_images(nimage)


global START_END_FRAMES DATASET IMAGE_FILES RES_VH
 

IMG     = [DATASET,'/images/',IMAGE_FILES(nimage).name]
    IMG     = imread(IMG);
    imsz    = size(IMG)

%%%%%%%%%%%%%%%%%%%%%%%%%
       %% take top image only %%
       %%%%%%%%%%%%%%%%%%%%%%%%%       
       IMG = IMG(1:imsz(1)/2,:);

       %%%%%%%%%%%%%
       %% debayer %%
       %%%%%%%%%%%%%
       RGB = demosaic( IMG, 'grbg'); 
       RGB = imresize( RGB, [RES_VH(1) RES_VH(2)] );
       RGB = im2double(RGB);
 %%

SAV = [DATASET,'/PNG_imgs/',sprintf('%06d',nimage-START_END_FRAMES(1)-1),'.png'];
imwrite(RGB, SAV);

end