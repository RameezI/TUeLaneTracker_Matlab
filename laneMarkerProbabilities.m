  function [PROB] = laneMarkerProbabilities(tippingPoint_gray, tippingPoint_gradMag, I, MAG,DIR_tangent, DIR_TEMPLATE_tanget)

  
  
% Scale Template according to DIR_tangent
  DIR_TEMPLATE_tanget = DIR_TEMPLATE_tanget *2^7; 
  
    
%% GrayScale Probabilities %%

    x= int16(I)-int16(tippingPoint_gray);
    x(x<0)=0; % All values below tippingPoint will have zero probability.
    GRAY_P= (255*x)./(1+ x); 

%% GradientMagnitude Probabilities %%

     x= int16(MAG)-int16(tippingPoint_gradMag);
     MAG_P= x*255./(1 + abs(x)); 

%% Intermediate Combined Probabilities
    
    %Low gradient will even have a negative penalty
    tempProb = 0.5*MAG_P + 0.5*GRAY_P; 
    tempProb(tempProb<0)=0;
    tempProb = uint8(tempProb);

    
%        figure(220);
%        imshow(tempProb, [0, 255]);
    
%% Gradient Direction Probbaility Map    

%Remmeber the DIR_tangents and DIR_TEMPLATE_tangent are scaled by 2^7 factor.
    x= abs(int32(DIR_tangent)-int32(DIR_TEMPLATE_tanget));  
    DIR_P = 255-( 255*x*4./(2^7 + 4*x));
    DIR_P= uint8(DIR_P);
    
    
%       figure(220);
%      imshow(DIR_P, [0, 255]);
    
    %%
    %% compute total lane marker probability %
    
%     PROB         = floor( ((tempProb+1) .* (DIR_P+1)) /256);  %% prob with dir
      PROB         =  (uint16(tempProb) .* uint16(DIR_P)) /255;  %% prob with dir
    
    
    
%     figure(220);
%     imshow(PROB, [0, 255]);
  end