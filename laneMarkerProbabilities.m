  function [PROB] = laneMarkerProbabilities( NGRAY, NMAG, NDIR, I, MAG, DIR, DIR_TEMPLATE)
    

  
    GRAY_P = 1./(1 + exp(single(-NGRAY(1)* (single(I)-NGRAY(2))) ));
    
    %Sigmoid Memebership with rate NGRAY(1) and reaching half value (=0.5) at NGRAY(2)    
      
   
    MAG_P = 1./(1 + exp(single(-NMAG(1)*(single(MAG)-NMAG(2)))));
     
    
    
    %DIR_TEMPLATE = uint8(round(DIR_TEMPLATE));
     
    %[e(540) .. e(-540)]
    DIR_P = 1./(1 + exp(single(-NDIR(1)*(abs(DIR-DIR_TEMPLATE)-NDIR(2)))));
  
    GRAY_P= floor(GRAY_P*255);
    MAG_P = floor(MAG_P*255);
    DIR_P = floor(DIR_P*255);
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% compute total lane marker probability %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    PROB         = floor((GRAY_P .* MAG_P .* DIR_P)/255^2);         %% prob with dir
    
  end