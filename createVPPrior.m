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
            Prior(v,h) = int32(exp(-((v-sv/2)^2)/(Sigma^2) ) * exp(-((h-sh/2)^2)/(Sigma^2) ) *2^15);
        end
    end        
    Prior = int32(( single(Prior) /  single(sum(sum(Prior))) )*2^15);
    
    %% uniform over 3x3 bin grid
    Trans = ones(3,3);
    
end