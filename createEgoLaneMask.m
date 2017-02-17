%%
%%
%% Create a lane mask
%%
%%
%%
function [SEGMENT, SEGMENT_TIGHT, SEGMENT_VERY_TIGHT, SEGMENT_WIDE] = createEgoLaneMask( LANE_BOUNDARIES, O_V, O_H, VP_V, VP_H )
    
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
        LINES(2,nl) = -LINES(1,nl)*(LANE_BOUNDARIES(3,nl));
        
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
        LINES(4,nl) = -LINES(3,nl)*(LANE_BOUNDARIES(4,nl));

    end

    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% create a segment mask %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    offset             = O_V+VP_V;
    SEGMENT            = zeros( 480, 640 );
    SEGMENT_TIGHT      = zeros( 480, 640 );
    SEGMENT_VERY_TIGHT = zeros( 480, 640 );
    SEGMENT_WIDE       = zeros( 480, 640 );
    for n = -(O_V-VP_V):-1

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% start end end columns of line %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        lane_start = round( (n-LINES(2,1)) / LINES(1,1) ) + (O_H+VP_H);
        lane_end   = round( (n-LINES(4,end)) / LINES(3,end) ) + (O_H+VP_H);

        %%%%%%%%%%%%%%%%%%%%%%%%%
        %% check on boundaries %%
        %%%%%%%%%%%%%%%%%%%%%%%%%
        if lane_start < 640 && 0 < lane_end

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
            SEGMENT( offset-n, lane_start:lane_end ) = 1;
        end  
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% start and end columns of line %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        lane_start = round( (n-LINES(4,1)) / LINES(3,1) ) + (O_H+VP_H);
        lane_end   = round( (n-LINES(2,end)) / LINES(1,end) ) + (O_H+VP_H);

        %%%%%%%%%%%%%%%%%%%%%%%%%
        %% check on boundaries %%
        %%%%%%%%%%%%%%%%%%%%%%%%%
        if lane_start < 640 && 0 < lane_end

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
            SEGMENT_TIGHT( offset-n, lane_start:lane_end ) = 1;
        end 
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% start end end columns of line %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        lane_start = round( (n-LINES(4,1)+25) / LINES(3,1) ) + (O_H+VP_H);
        lane_end   = round( (n-LINES(2,end)+25) / LINES(1,end) ) + (O_H+VP_H);

        %%%%%%%%%%%%%%%%%%%%%%%%%
        %% check on boundaries %%
        %%%%%%%%%%%%%%%%%%%%%%%%%
        if lane_start < 640 && 0 < lane_end

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
            SEGMENT_VERY_TIGHT( offset-n, lane_start:lane_end ) = 1;
        end 
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% start end end columns of line %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        lane_start = round( (n-LINES(2,1)-25) / LINES(1,1) ) + (O_H+VP_H);
        lane_end   = round( (n-LINES(4,end)-25) / LINES(3,end) ) + (O_H+VP_H);

        %%%%%%%%%%%%%%%%%%%%%%%%%
        %% check on boundaries %%
        %%%%%%%%%%%%%%%%%%%%%%%%%
        if lane_start < 640 && 0 < lane_end

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
            SEGMENT_WIDE( offset-n, lane_start:lane_end ) = 1;
        end 
        
    end
    
end
