%%
%%
%% 
%% Create the gradient template
%%
%%
%%
function [ STRENGHT, DIR ] = getGradientInfo( IN )
      
% Sobel Filter
    sobel = [ -1 -2 -1; 0 0 0; 1 2 1];

IN= int16(IN);
    
%% compute gradient
    dX = imfilter( IN, sobel' );
    dY = imfilter( IN, sobel  );
%     dX = imfilter( IN, Gx, 'conv' );
%     dY = imfilter( IN, Gy, 'conv' );
 



 %dY=single(dY)*256;
 %dX=single(dX)*256;
 
%  %Apply saturation
%  dY( dY > 255 ) =  255;
%  dX( dX > 255 ) =  255;
%  
%  dY( dY < -255 ) =  -255;
%  dX( dX < -255 ) =  -255;
 
 
 %Apply saturation
 dY( dY > 255 ) =  255;
 dX( dX > 255 ) =  255;
 
 dY( dY < -255 ) =  -255;
 dX( dX < -255 ) =  -255;
 
% 
%  dX =  round(dX);
%  dY =  round(dY);
  
  %% get mangitude
  
  %magnitude = sqrt(dX.^2 + dY.^2); 
  magnitude = abs(dX)+ abs(dY);
  magnitude(magnitude>255) = 255;

%% get angle

      angle= atan2(single(dX),single(dY));
      angle= angle * (180/pi);
      angle = floor(angle);


%% return
    STRENGHT = magnitude;
    DIR      = angle;
    
end