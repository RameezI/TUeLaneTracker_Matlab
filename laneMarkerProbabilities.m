  function [PROB] = laneMarkerProbabilities(tippingPoint_gray, tippingPoint_gradMag, I, gradMAG , gradDIRTangent, gradDirTanget_template)


  % This function computes the per pixel probability for a lane boundary
% pixel. The result is a Probability Map of the focussed region. The
% computed Proability MAP is represented by scaled integer in range [0 255]  

%% GrayScale Probabilities %%
    x= int16(I)-int16(tippingPoint_gray);
    x(x<0)=0; % All values below the tippingPoint will have zero probability.
    GRAY_P= (255*x)./(1+ x);
    
    
   
    
%%    

%% GradientMagnitude Probabilities %%
     x= int16(gradMAG)-int16(tippingPoint_gradMag);
     MAG_P= (255*x)./(1 + abs(x)); 


     
%% Intermediate Combined Probabilities
    %Low gradient will even have a negative penalty
     tempProb = 1*MAG_P + 0*GRAY_P;
     tempProb(tempProb<0)=0;
     tempProb = uint8(tempProb);

    
%% Gradient Direction Probbaility Map    
%Remmeber the DIR_tangents and DIR_TEMPLATE_tangent are scaled by 2^7 factor.
    x= abs(int32(gradDIRTangent)-int32(gradDirTanget_template));  
    DIR_P = 255-( (255*x)./(2^7 + x));
    DIR_P= uint8(DIR_P);
    

%% Compute Total Lane Marker Probability %
      PROB =  (uint16(tempProb) .* uint16(DIR_P)) /255;  %% prob with dir
      
        
%     
%     figure(220);
%     imshow(PROB, [0, 1]);
  end