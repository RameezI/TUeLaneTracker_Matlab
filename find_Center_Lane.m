

%%
%% the center lane filter
%%
function [ msg ] = find_Center_Lane( )             
        
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%    
    global CENTER_OFFSET LANE_BOUNDARIES CM_TO_PIXEL CAR_WIDTH
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% save distance from lane in bottom-line pixels %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    DIST = CAR_WIDTH*CM_TO_PIXEL; %% use twice the half width of a car to include safety margin
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% the outer left and right boundaries %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    LEFT_BOUNDARY  = LANE_BOUNDARIES(1,1)+DIST;
    RIGHT_BOUNDARY = LANE_BOUNDARIES(2,2)-DIST;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% check if left < right %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    if LEFT_BOUNDARY < RIGHT_BOUNDARY
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% weight the center according to lane strength %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% the weight between the left and right boundaries %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        WEIGHT = LANE_BOUNDARIES(5,2) / ( LANE_BOUNDARIES(5,2) + LANE_BOUNDARIES(5,1) );
        CENTER_OFFSET = (CENTER_OFFSET + WEIGHT)/2; %% low-pass filter
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% compute the center lane %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        CENTER_LANE = LEFT_BOUNDARY + CENTER_OFFSET*(RIGHT_BOUNDARY-LEFT_BOUNDARY);
    
    else
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% simply take the middle %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
        CENTER_OFFSET = (CENTER_OFFSET + 0.5)/2; %% low-pass filter
        CENTER_LANE   = (LANE_BOUNDARIES(1,1)+LANE_BOUNDARIES(2,2))/2;
        
    end
        
    %%%%%%%%%
    %% set %%
    %%%%%%%%%
    LANE_BOUNDARIES(3,1) = CENTER_LANE;
    LANE_BOUNDARIES(3,2) = CENTER_LANE;
    LANE_BOUNDARIES
    
end
    
    


