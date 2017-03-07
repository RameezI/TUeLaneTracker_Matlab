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
        
        % Filter %
    
        tempP               = Likelihoods.TOT_ALL(:,:,ni);
        tempD               = Likelihoods.GRADIENT_DIR_ALL(:,:,ni);
        
        mask                = MAX_P < tempP;                
        MAX_P(mask)         = tempP(mask);                
        DIR_MAX_P(mask)     = tempD(mask);  %%^TODO: SOMETHING FISHY WITH THIS AVERAGE
        
    end

    
    Likelihoods.TOT_MAX              = round(MAX_P*255);
    Likelihoods.GRADIENT_DIR_TOT_MAX = round(DIR_MAX_P);
    MASKS.FOCUS = round(MASKS.FOCUS*255);
        
    %%
    %% Apply the focus maks to the probs %%
    % Masks out certain distances %
    Likelihoods.TOT_MAX_FOCUSED = MASKS.FOCUS .* Likelihoods.TOT_MAX;
    
    Likelihoods.TOT_MAX_FOCUSED = Likelihoods.TOT_MAX_FOCUSED/255;
        
    %%
    %% Get the Active Pixels %%
    IDX_FOC_TOT_P  = find( 0 <  Likelihoods.TOT_MAX_FOCUSED );
    
end


