%%
%%
%%
%% compute the vp from two lanes
%%
%%
%%
function [vp] = computeVP( posLeft, posRight )
 
    %% line params
    xLeft      = posLeft(1,1);
    yLeft      = posLeft(2,1);
    xRight     = posRight(1,1);
    yRight     = posRight(2,1);
    slopeLeft  = ( posLeft(2,2)  - posLeft(2,1)  ) /  (posLeft(1,2)  - posLeft(1,1)  );
    slopeRight = ( posRight(2,2) - posRight(2,1) ) /  (posRight(1,2) - posRight(1,1) );
    
    %% compute intersection
    x = (yRight-yLeft+slopeLeft*xLeft-slopeRight*xRight) / (slopeLeft-slopeRight);
    y = slopeLeft  * (x-xLeft)  + yRight;
    y = slopeRight * (x-xRight) + yRight;
    
    %% assign vp
    vp = [x;y];
    
end
