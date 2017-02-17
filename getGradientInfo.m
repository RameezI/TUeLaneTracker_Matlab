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
    
    %% get mangitude
    magnitude = sqrt(dX.^2 + dY.^2);

    %% get direction
    dX( 0 < abs(dX) ) = dX( 0 < abs(dX) ) ./ magnitude( 0 < abs(dX) );
    dY( 0 < abs(dY) ) = dY( 0 < abs(dY) ) ./ magnitude( 0 < abs(dY) );
    angle = (0 < magnitude) .* rad2deg( real(acos(dY)) ) .* sign( (0 <= dX) - 0.5 );
    angle( angle <  0 ) = angle( angle <  0 ) + 180;

    %% return
    STRENGHT = magnitude;
    DIR      = angle;
    
end