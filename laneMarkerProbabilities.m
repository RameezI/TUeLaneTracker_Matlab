  function [PROB] = laneMarkerProbabilities(tippingPoint_gray, tippingPoint_gradMag, I, gradMAG , gradDIRTangent, gradDirTanget_template)

global Path CrossCheck
  % This function computes the per pixel probability for a lane boundary
% pixel. The result is a Probability Map of the focussed region. The
% computed Proability MAP is represented by scaled integer in range [0 255]  

%% GrayScale Probabilities %%
    x= int32(I)-int32(tippingPoint_gray);
    x(x<0)=0; % All values below the tippingPoint will have zero probability.
    GRAY_P = (255*x)./(10+x);
    

%% GradientMagnitude Probabilities %%
     x= int32(gradMAG)-int32(tippingPoint_gradMag);
     MAG_P= (255*x)./(10 + abs(x));


     
%% Intermediate Combined Probabilities
    %Low gradient will even have a negative penalty
     tempProb = MAG_P + GRAY_P;
     tempProb(tempProb<0)=0;

    
%% Gradient Direction Probbaility Map    
%Remmeber the DIR_tangents and DIR_TEMPLATE_tangent are scaled by 2^7 factor.
    x= abs(int32(gradDIRTangent)-int32(gradDirTanget_template));  
    DIR_P = 255-( (255*x)./(60+ x));

    

%% Compute Total Lane Marker Probability %
      PROB =  (tempProb .* DIR_P) /255;  %% prob with dir

      PROB = uint8(PROB);
      
%% Writing to CSV file, to verify against Opencv Code
    if CrossCheck==true
        dlmwrite(strcat(Path,  'PROB_GRAY.csv'),GRAY_P, 'delimiter' , ',' , 'precision', 9);
        dlmwrite(strcat(Path,  'PROB_MAG.csv'), MAG_P , 'delimiter' , ',' , 'precision', 9);
        dlmwrite(strcat(Path,  'PROB_DIR.csv'), DIR_P , 'delimiter' , ',' , 'precision', 9);
    end
end