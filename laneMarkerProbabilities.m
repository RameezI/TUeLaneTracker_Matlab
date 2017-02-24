  function [PROB] = laneMarkerProbabilities( NGRAY, NMAG, NDIR, I, MAG, DIR, DIR_TEMPLATE)
    
   % x =  
  
    GRAY_P = 1./(1 + exp(-NGRAY(1)*(I-NGRAY(2))));
    %Sigmoid Memebership with rate NGRAY(1) and reaching half value (=0.5) at NGRAY(2)    
    
    
    MAG_P = 1./(1 + exp(-NMAG(1)*(MAG-NMAG(2))));
     
     
    DIR_P = 1./(1 + exp(-NDIR(1)*(abs(DIR-DIR_TEMPLATE)-NDIR(2))));
  
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% compute total lane marker probability %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    PROB         = GRAY_P .* MAG_P .* DIR_P;         %% prob with dir
    
 end