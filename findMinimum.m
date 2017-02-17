%%
%%
%% 1-D sub-interval fit using parabolic fitting
%% all for difactic reasons (can be made more efficient)
%%
function [Fit A B C] = findMinimum( Costs, Values )

    %% fit parabola
    x1 = Values(1);
    y1 = Costs(1);
    x2 = Values(2);
    y2 = Costs(2);
    x3 = Values(3);
    y3 = Costs(3);
    
    %% params of parabola y = aX^2 + bX + C
    denom = (x1 - x2)*(x1 - x3)*(x2 - x3);
    A = (x3 * (y2 - y1) + x2 * (y1 - y3) + x1 * (y3 - y2)) / denom;
    B = (x3^2 * (y1 - y2) + x2^2 * (y3 - y1) + x1^2 * (y2 - y3)) / denom;
    C = (x2 * x3 * (x2 - x3) * y1 + x3 * x1 * (x3 - x1) * y2 + x1 * x2 * (x1 - x2) * y3) / denom;

    %% minimum
    Fit = -B/(2*A);

end