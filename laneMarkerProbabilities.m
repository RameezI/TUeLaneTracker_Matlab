  function [PROB] = laneMarkerProbabilities( NGRAY, NMAG, NDIR, I, MAG, DIR, DIR_TEMPLATE)
    
   % x =  
   
     NGRAY(2)= floor(NGRAY(2)*256);
     %NGRAY(1)= NGRAY(1)*1/256;
    % I = im2single(I);
    NGRAY(1)= 0.1;
     
     %NGRAY= uint8(NGRAY);
     
  
    GRAY_P = 1./(1 + exp(single(-NGRAY(1)* (single(I)-NGRAY(2))) ));
    %Sigmoid Memebership with rate NGRAY(1) and reaching half value (=0.5) at NGRAY(2)    
    
    
%     
     NMAG(2)= floor(NMAG(2)*256);
     NMAG(1)= 0.1;
    
    MAG_P = 1./(1 + exp(single(-NMAG(1)*(single(MAG)-NMAG(2)))));
     
    
    
    %DIR_TEMPLATE = uint8(round(DIR_TEMPLATE));
     
    DIR_P = 1./(1 + exp(single(-NDIR(1)*(abs(DIR-DIR_TEMPLATE)-NDIR(2)))));
  
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% compute total lane marker probability %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    PROB         = GRAY_P .* MAG_P .* DIR_P;         %% prob with dir
    
 end