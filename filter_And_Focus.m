%%
%% Temporal Filter over Input Data
%%
function [IDX_FOC_TOT_P, Likelihoods] = filter_And_Focus(Likelihoods, MASKS)

    %%
    %% Required Global Variables %%
    global  NBUFFER 
    
    
    %%
    %% Temporal MaxPooling %%
    MAX_P         = Likelihoods.TOT_ALL(:,:,1);
    DIR_MAX_P =     Likelihoods.GRADIENT_DIR_ALL(:,:,1); 
    
    for ni = 2:NBUFFER
        
        tempP               = Likelihoods.TOT_ALL(:,:,ni);
        tempD               = Likelihoods.GRADIENT_DIR_ALL(:,:,ni);
        
        mask                = MAX_P < tempP; 
        MAX_P(mask)         = tempP(mask);                
        DIR_MAX_P(mask)     = tempD(mask);  
        
    end

    Likelihoods.TOT_MAX              = MAX_P;
    Likelihoods.GRADIENT_DIR_TOT_MAX = DIR_MAX_P;
        
    %%
    %% Apply the focus maks to the probs %%
    % Masks out certain distances %
    Likelihoods.TOT_MAX_FOCUSED = MASKS.FOCUS .* Likelihoods.TOT_MAX;
    
    Likelihoods.TOT_MAX_FOCUSED = floor((Likelihoods.TOT_MAX_FOCUSED+1)/256);
    

    %%
    %% Get the Active Pixels %%
    IDX_FOC_TOT_P  = find( 0 <  Likelihoods.TOT_MAX_FOCUSED );
    
end


