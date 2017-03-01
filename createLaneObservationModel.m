%%
%%
%%
%% create the probability of lane observations given the state
%%
%%
function [ ObsL ObsR ObsNeg ] = createLaneObservationModel( binsLaneOffset, binsLane, MIN_LANE_WIDTH, MAX_LANE_WIDTH, LANE_FILTER_BINS_H, CM_TO_PIXEL )



    %% default
    NbOffsetsBins   = size(binsLaneOffset,2);
    NbLaneBins      = size(binsLane,2);
    ObsL   = zeros( NbOffsetsBins , NbLaneBins, NbOffsetsBins );
    ObsR   = zeros( NbOffsetsBins , NbLaneBins, NbOffsetsBins );
    ObsNeg = zeros( NbOffsetsBins , NbLaneBins, NbOffsetsBins ); 

    %% loop over all states
    for left = 1:size(binsLaneOffset,2)
        for right = 1:size(binsLaneOffset,2)
    
            %% allowed state
            width = (LANE_FILTER_BINS_H(left)+LANE_FILTER_BINS_H(right)) * 1/CM_TO_PIXEL;
            if MIN_LANE_WIDTH <= width && width <= MAX_LANE_WIDTH
                          
%                 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                 %% get lane offset in pixels %%
%                 % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                 left_offset  = binsLaneOffset(left);
%                 right_offset = binsLaneOffset(right);

                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                %% create the observation model (i.e. lane observation probs) %%
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                
              %if left_offset >= binsPX(1) && binsPX(end) >= right_offset
                    [tempL, tempR, tempN] = fillLaneObservationModel( binsLaneOffset, binsLane, left, right ); 
                    ObsL(   left, :, right ) = tempL;
                    ObsR(   left, :, right ) = tempR;
                    ObsNeg( left, :, right ) = tempN;
              
             
              %end
                
            end                    
            
        end
        
    end
    
end
    
    

%%
%% create the observation model for a single state
%%
function [ ObsL,ObsR, ObsNeg ] = fillLaneObservationModel( binsLaneOffset, binsLane, leftIdx, rightIdx )    
    
    %% default
    NbLaneBins   = size(binsLane,2);
    
    ObsL   = zeros( 1, NbLaneBins );
    ObsR   = zeros( 1, NbLaneBins );
    ObsNeg = zeros( 1, NbLaneBins ); 
    
    %% Location of the left and right Offset bins in the LaneBins;
    left  = -binsLaneOffset(leftIdx);
    right =  binsLaneOffset(rightIdx);
    
    idxL = find( binsLane == left);
    idxR = find( binsLane == right);
        
    %% set using Gaussian pdf
    if( 2 <= idxL && idxR <= NbLaneBins-1 )
        ObsL(idxL+[-1:1])     = [ 0.25 1 0.25 ];
        ObsR(idxR+[-1:1])     = [ 0.25 1 0.25 ];
        ObsNeg(idxL+2:idxR-2) = 1;
        idxM = round((idxL+idxR)/2);
        ObsNeg(idxM+[-4:4])   = 0;        
    end
    
end


