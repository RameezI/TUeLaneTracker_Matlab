%%
%%
%% 
%% Create the gradient template
%%
%%
%%
function [ magnitude, tanDIR] = getGradientInfo( IN )
      
% Sobel Filter
    sobel = [ -1 -2 -1; 0 0 0; 1 2 1];
    

    
%% compute gradient
    dX = imfilter( int16(IN), sobel' );
    dY = imfilter( int16(IN), sobel  );

 
%% Apply saturation

 dY( dY > 255 ) =  255;
 dX( dX > 255 ) =  255;
 
 dY( dY < -255 ) =  -255;
 dX( dX < -255 ) =  -255;
 

  
  %% get mangitude
  
  %magnitude = sqrt(dX.^2 + dY.^2); 
  magnitude = abs(dX)*0.5+ abs(dY)*0.5;
  magnitude(magnitude>255) = 255;
  magnitude = uint8(magnitude);
  

  
%% get angle
      %angle= atan2(single(dX),single(dY));
      %angle= angle * (180/pi);
%       angle = floor(angle);


dY(dY==0)= 1;
tanDIR= dX*2^7./dY;

tanDIR(tanDIR>255*2^7) =  255*2^7;
tanDIR(tanDIR<-255*2^7)= -255*2^7;
%tanDIR = tanDIR *2^7;
tanDIR= floor(tanDIR);    
end