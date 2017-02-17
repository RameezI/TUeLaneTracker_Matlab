%%
%%
%% Create a lane mask
%%
%%
%%
function [SEGMENT] = createLaneMask( LANE_BOUNDARIES,VP_X, VP_Y )

    %%%%%%%%%%%%%%%%%%%%%%%%%
    %% compute line params %%
    %%%%%%%%%%%%%%%%%%%%%%%%%
    LINES = zeros(4,size(LANE_BOUNDARIES,2));
    for nl = 1:size(LANE_BOUNDARIES,2)

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% start of lane left to right %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% compute slope (add some boundary) %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        LINES(1,nl) = 240 / (LANE_BOUNDARIES(3,nl)-LANE_BOUNDARIES(1,nl));

        %%%%%%%%%%%%%%%%%%%%%%%
        %% compute intercept %%
        %%%%%%%%%%%%%%%%%%%%%%%
        LINES(2,nl) = -LINES(1,nl)*(LANE_BOUNDARIES(3,nl)-5); %% see the -5

        %%%%%%%%%
        %% end %%
        %%%%%%%%%

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% compute slope (add some boundary) %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        LINES(3,nl) = 240 / (LANE_BOUNDARIES(4,nl)-LANE_BOUNDARIES(2,nl));

        %%%%%%%%%%%%%%%%%%%%%%%
        %% compute intercept %%
        %%%%%%%%%%%%%%%%%%%%%%%
        LINES(4,nl) = -LINES(3,nl)*(LANE_BOUNDARIES(4,nl)+5); %% see the +5

    end


    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% create a segment mask %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    offset  = 240-VP_X;
    SEGMENT = zeros( 480, 640 );
    for n = -(240+VP_X):-1

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% for each lane compute intersection with current line %% 
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        for nl = 1:size(LANE_BOUNDARIES,2)

            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %% start end end columns of line %%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            lane_start = round( (n-LINES(2,nl)) / LINES(1,nl) ) + (320-VP_Y);
            lane_end   = round( (n-LINES(4,nl)) / LINES(3,nl) ) + (320-VP_Y);

            %%%%%%%%%%%%%%%%%%%%%%%%%
            %% check on boundaries %%
            %%%%%%%%%%%%%%%%%%%%%%%%%
            if lane_start < 640 & 0 < lane_end

                %%%%%%%%%%%%%%
                %% clean up %%
                %%%%%%%%%%%%%%
                if lane_start < 1
                    lane_start = 1;
                end
                if 640 < lane_end
                    lane_end = 640;
                end

                %%%%%%%%%%%%%%%%%%%
                %% mark in image %%
                %%%%%%%%%%%%%%%%%%%
                SEGMENT( offset-n, lane_start:lane_end ) = nl;
            end                                    
        end

    end
end