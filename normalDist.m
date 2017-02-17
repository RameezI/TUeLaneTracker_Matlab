%%
%%
%%
%% Normals dist
%%
%%
%%
function [prob] = normalDist( map, mean, sigma )

    prob = 1/sqrt(2*sigma^2*pi) * exp( -0.5*((map-mean).^2 / sigma.^2) );

end