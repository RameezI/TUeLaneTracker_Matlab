%%
%%
%%
%% create the prior over lanes
%% expressed as histograms
%%
%%
function [ Prior, Trans ] = createVPPrior( VP_BINS_V, VP_BINS_H, Sigma  )
    
    %% fill histogram
    sv    = size(VP_BINS_V,2);
    sh    = size(VP_BINS_H,2);
    Prior = ones(sv,sh);
    
    for v = 1:sv
        for h = 1:sh 
            pv=  exp(-((v-sv/2)^2)/(Sigma^2) ) *2^7;
            ph=  exp(-((h-sh/2)^2)/(Sigma^2) ) *2^7;
            
            Prior(v,h) = int32( pv*ph);
            
        end
    end
    
    Prior = (Prior*2^16)/sum(sum(Prior));
    Prior = int32(Prior);
    
    %% uniform over 3x3 bin grid
    Trans = ones(3,3);
    
end