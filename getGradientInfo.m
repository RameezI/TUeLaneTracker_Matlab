%%
%%
%% 
%% Create the gradient template
%%
%%
%%
function [ STRENGHT, DIR ] = getGradientInfo( IN )
      
%     %% sobel
    sobel = [ -1 -2 -1; 0 0 0; 1 2 1];
        
%     %% First-order derivative of Gaussian
%     k         = 5;
%     sigma     = 1.5;
%     G1        = fspecial('gauss',[round(k*sigma), round(k*sigma)], sigma);
%     [Gx,Gy]   = gradient(G1);
       
 


%% compute gradient
    dX = imfilter( IN, sobel' );
    dY = imfilter( IN, sobel  );
%     dX = imfilter( IN, Gx, 'conv' );
%     dY = imfilter( IN, Gy, 'conv' );
 



 dY=single(dY)*256;
 dX=single(dX)*256;
 
 dY( dY > 256 ) =  256;
 dX( dX > 256 ) =  256;
  
  %% get mangitude
  magnitude = sqrt(dX.^2 + dY.^2);
  magnitude= magnitude;  
    
    %magnitude = abs(dX) + abs(dY);

%       %% get direction
%        dX( 0 < abs(dX) ) = dX( 0 < abs(dX) ) ./ magnitude( 0 < abs(dX) );
%        dY( 0 < abs(dY) ) = dY( 0 < abs(dY) ) ./ magnitude( 0 < abs(dY) );
%        angle = (0 < magnitude) .* rad2deg( real(acos(dX)) ) .* sign( (0 <= dY) - 0.5 );
%        angle( angle < -270 ) = 360-angle( angle <  -270 );
%        angle( angle <  0 ) =   angle( angle <  0 ) + 180;
       

  %angle= cordicatan2(dY,dX);
  angle= atan2(dX,dY);
  angle= angle * (180/pi);
  angle = round(angle);
  %angle = ceil(angle);
  
% 
%    angle(angle<=45) = 45;
%    angle(angle>45 & angle<=90) = 90;
% %   

    %% return
    STRENGHT = magnitude;
    DIR      = angle;
    
end