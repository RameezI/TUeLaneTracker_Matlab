%%
%%
%% 
%% Create the gradient template
%%
%%
%%
function [ STRENGHT, DIR ] = getGradientInfoSteerableFilter( IN, Big )

    %% Gaussian
    k         = 10;
    sigma     = 1.5;
    G1        = fspecial('gauss',[round(k*sigma), round(k*sigma)], sigma);
    [Gx,Gy]   = gradient(G1);
    [Gxx,Gxy] = gradient(Gx);
    [Gyx,Gyy] = gradient(Gy);
    
    figure(100)
    M = [Gx, Gy, Gxx, Gyy, Gxy, Gyx];
    imshow( M, [min(M(:),[],1) max(M(:),[],1)] )
    
    %% compute gradient
    dX  = imfilter( IN, Gx, 'conv' );
    dY  = imfilter( IN, Gy, 'conv' );
%     dXX = imfilter( IN, Gxx, 'conv' );
%     dYY = imfilter( IN, Gyy, 'conv' );
%     dXY = imfilter( IN, Gxy, 'conv' );
    
    
    %% get angle
    A      = dXX.^2 - 2*dXX.*dYY + dYY.^2 + 4*dXY;
    A(A<0) = 0;
    Angle  = atan((dXX - dYY + sqrt(A)) ./ (2*dXY));
    
    %% count edges
    STRENGHT = sqrt(dX.^2 + dY.^2);
    DIR      = rad2deg(Angle);

end