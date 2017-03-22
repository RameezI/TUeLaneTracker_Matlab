%%
%%
%%
%% create the prior over lanes
%% expressed as histograms
%%
%%
function [ Prior, Trans ] = createLanePrior( bins, pix_to_cm, meanL, minL, maxL, sigmaL  )
    
    %% fill histogram
    nbins  = size(bins,2);
    Prior  = ones( nbins, nbins );
    hmean  = meanL/2;  %% half lane width
    bins   = bins * pix_to_cm;
    for x = 1:nbins
        for y = 1:nbins
            
            %% prior on location
            pL = exp( -(hmean-bins(x))^2 / (2*(8*sigmaL)^2) ) / ( sqrt(2*pi)*8*sigmaL );     
            pR = exp( -(hmean-bins(y))^2 / (2*(8*sigmaL)^2) ) / ( sqrt(2*pi)*8*sigmaL );     
            
            %% prior on lane width
            width = bins(x)+bins(y);
            if minL <= width && width <= maxL
                Prior(x,y) = pL*pR;
            else
                Prior(x,y) = 0;                
            end
            
        end
    end
    
    %% normalize
    Prior = Prior / sum(sum(Prior));
    
    %% Transition
    Trans = ones(7,7);
end