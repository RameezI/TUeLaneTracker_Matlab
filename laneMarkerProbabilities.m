  function [PROB, PROB_BACK_UP] = laneMarkerProbabilities( NGRAY, NMAG, NDIR, I, MAG, DIR, DIR_TEMPLATE, DIR_TEMPLATE_BACK_UP)
    
  
     
     
  
     GRAY_P = 1./(1 + exp(-NGRAY(1)*(I-NGRAY(2))));
     

     MAG_P = 1./(1 + exp(-NMAG(1)*(MAG-NMAG(2))));
     

     DIR_P = 1./(1 + exp(-NDIR(1)*(abs(DIR-DIR_TEMPLATE)-NDIR(2))));
  
     DIR_P_BACK_UP = 1./(1 + exp(-NDIR(1)*(abs(DIR-DIR_TEMPLATE_BACK_UP)-NDIR(2))));
    
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% compute total lane marker probability %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    PROB         = GRAY_P .* MAG_P .* DIR_P;         %% prob with dir
    PROB_BACK_UP = GRAY_P .* MAG_P .* DIR_P_BACK_UP; %% prob with dir back-up
    
 end