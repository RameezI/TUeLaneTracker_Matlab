
function [ magnitude, tanDIR] = getGradientInfo( IN )

global Path CrossCheck

% Sobel Filter
    sobel = [ -1 -2 -1; 0 0 0; 1 2 1];
    

    
%% compute gradient
    dX = imfilter( int16(IN), sobel', 'replicate' );
    dY = imfilter( int16(IN), sobel , 'replicate'  );

 
%% Apply saturation

 dY( dY > 255 ) =  255;
 dX( dX > 255 ) =  255;
 
 dY( dY < -255 ) =  -255;
 dX( dX < -255 ) =  -255;
 dY(dY==0)= 1;

  
  %% get mangitude
  
  %magnitude = sqrt(dX.^2 + dY.^2); 
  magnitude = abs(dX)+ abs(dY);
  magnitude(magnitude>255) = 255;
  magnitude = uint8(magnitude);

tanDIR= dX*2^7./dY;

%% Writing to CSV file, to verify against Opencv Code
    if CrossCheck==true
        dlmwrite(strcat(Path, 'GradientX.csv'), dX , 'delimiter', ',', 'precision', 9);
        dlmwrite(strcat(Path, 'GradientY.csv'), dY , 'delimiter', ',', 'precision', 9);

    end
end