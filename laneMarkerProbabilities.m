  function [PROB, PROB_BACK_UP] = laneMarkerProbabilities( NGRAY, NYELL, NSAT, NMAG, NDIR, I, MAG, DIR, DIR_TEMPLATE, DIR_TEMPLATE_BACK_UP)
    
  %Backup
  %%laneMarkerProbabilities( NGRAY, NYELL, NSAT, NMAG, NDIR, S, H, V, MAG, DIR, DIR_TEMPLATE, DIR_TEMPLATE_BACK_UP)
  
  %%GRAY_P = sigmf( V, NGRAY);
  
  %%
    % Temp modify by Rameez
    %GRAY_P = 1./(1 + exp(-NGRAY(1)*(V-NGRAY(2))));
    GRAY_P = 1./(1 + exp(-NGRAY(1)*(I-NGRAY(2))));

    %%
    %YELL_P originally with dsigmf---->relpacing it with sigmf
    %^TODO: check the effect of replacing dsigmf with sigmf
    %YELL_P = dsigmf( H, [100 0.33]) .* sigmf( S, NSAT);
    
     %YELL_P = dsigmf( H, NYELL) .* sigmf( S, NSAT);
     %%
     % temp close by Rameez : 
     %Is expected to improve performance in presence of yellow lanes
     %YELL_P = (   (1./(1 + exp(-NYELL(1)*(H-NYELL(2))))) - (1./(1 + exp(-NYELL(3)*(H-NYELL(4)))))  ) .* (1./(1 + exp(-NSAT(1)*(S-NSAT(2))))) ;
 %%   
    %MAG_P  = sigmf( MAG, NMAG);
    
    
    MAG_P = 1./(1 + exp(-NMAG(1)*(MAG-NMAG(2))));
    
    %DIR_P         = sigmf( abs(DIR-DIR_TEMPLATE),         NDIR );
    DIR_P = 1./(1 + exp(-NDIR(1)*(abs(DIR-DIR_TEMPLATE)-NDIR(2))));
    
    %DIR_P_BACK_UP = sigmf( abs(DIR-DIR_TEMPLATE_BACK_UP), NDIR );
    DIR_P_BACK_UP = 1./(1 + exp(-NDIR(1)*(abs(DIR-DIR_TEMPLATE_BACK_UP)-NDIR(2))));
    
    
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% compute total lane marker probability %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
%%Temporarily modifying only for gray images    
    %PROB         = max(GRAY_P,YELL_P) .* MAG_P .* DIR_P;         %% prob with dir
    %PROB_BACK_UP = max(GRAY_P,YELL_P) .* MAG_P .* DIR_P_BACK_UP; %% prob with dir back-up
    
    PROB         = GRAY_P .* MAG_P .* DIR_P;         %% prob with dir
    PROB_BACK_UP = GRAY_P .* MAG_P .* DIR_P_BACK_UP; %% prob with dir back-up
    
 end