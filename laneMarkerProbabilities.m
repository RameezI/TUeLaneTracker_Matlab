  function [PROB] = laneMarkerProbabilities(tippingPoint_gray, tippingPoint_gradMag, I, MAG,DIR_tangent, DIR, DIR_TEMPLATE)
    
  
  
  
    x= single(I)-tippingPoint_gray;
    %GRAY_P = 1./(1 + exp(   single(-NGRAY(1)*x) ));
    
    
    %Sigmoid Approximation
    x(x<0)=0;  % All negative values are set to Zero (Negative range will have zero probability)
    GRAY_P= x./(1 + abs(x)); 
  

    
    %x= single(MAG)-NMAG(2);    
    %%Sigmoid Memebership with rate NGRAY(1) and reaching half value (=0.5) at NGRAY(2)    
    %MAG_P = 1./(1 + exp(single(-NMAG(1)*(single(MAG)-NMAG(2)))));
    
    
    x= single(MAG)-tippingPoint_gradMag;
    MAG_P= x./(1 + abs(x)); 
    
    %White is more probabale, but low gradient will even have a negative
    %penalty
    tempProb = 0.5*MAG_P +0.5*GRAY_P; 
    tempProb(tempProb<0)=0;
    

    
    DIR= DIR.*pi/180; %conversion to radians
    % DIR_P = 1./(1 + exp(single(NDIR(1)*( abs(tan(DIR)-tan(DIR_TEMPLATE))) -NDIR(2) )));
    %% Sigmoid Membership: Probability is high(>0.5) when the error is below
    % NDIR(2)..at NDIR(2) probablity becomes 0.5 and then decreases with a
    % exponential rate: NDIR(1).
  
    

    
    x= abs(DIR_tangent-tan(DIR_TEMPLATE));
    DIR_P = x./(1 + x); 
    DIR_P= 1-DIR_P;
    
%   
%     GRAY_P = floor(GRAY_P*255);
%   MAG_P  = floor(MAG_P*255);

    
    DIR_P    = floor(DIR_P*255);
    tempProb = floor(tempProb*255);

    
    
    
%      figure(220);
%     imshow(DIR_P, [0, 255]);
    
    %%
    %% compute total lane marker probability %
    
    PROB         = floor(((tempProb+1) .* (DIR_P+1)) /256);  %% prob with dir
    
    
    
%     figure(220);
%     imshow(PROB, [0, 255]);
  end