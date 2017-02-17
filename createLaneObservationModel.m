%%
%%
%%
%% create the probability of lane observations given the state
%%
%%
function [ ObsL ObsR ObsNeg ] = createLaneObservationModel( binsCM, binsPX, MIN_LANE_WIDTH, MAX_LANE_WIDTH, LANE_FILTER_BINS_H, CM_TO_PIXEL )



    %% default
    nBCM   = size(binsCM,2);
    nBPX   = size(binsPX,2);
    ObsL   = zeros( nBCM , nBPX, nBCM );
    ObsR   = zeros( nBCM , nBPX, nBCM );
    ObsNeg = zeros( nBCM , nBPX, nBCM ); 

    %% loop over all states
    for left = 1:size(binsCM,2)
        for right = 1:size(binsCM,2)
    
            %% allowed state
            width = (LANE_FILTER_BINS_H(left)+LANE_FILTER_BINS_H(right)) * 1/CM_TO_PIXEL;
            if MIN_LANE_WIDTH <= width && width <= MAX_LANE_WIDTH
                          
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                %% get lane offset in pixels %%
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                left_offset  = binsCM(left);
                right_offset = binsCM(right);

                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                %% create the observation model (i.e. lane observation probs) %%
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                
                %% If bounded by the pixel limits ---> binCM is actually bins in pixels
              %if left_offset >= binsPX(1) && binsPX(end) >= right_offset
                    [tempL, tempR, tempN] = fillLaneObservationModel( binsCM, binsPX, left, right ); 
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
function [ ObsL ObsR ObsNeg ] = fillLaneObservationModel( binsCM, binsPX, leftIdx, rightIdx )    
    
    %% default
    nBPX   = size(binsPX,2);
    ObsL   = zeros( 1, nBPX );
    ObsR   = zeros( 1, nBPX );
    ObsNeg = zeros( 1, nBPX ); 
    
    %% get lane offset in pixels in steps of 10;
    left_offset  = -binsCM(leftIdx);
    right_offset =  binsCM(rightIdx);
    
    %% find where they are in the hist
    idxL = find( binsPX == left_offset );
    idxR = find( binsPX == right_offset );
        
    %% set using Gaussian pdf
    if( 2 <= idxL && idxR <= nBPX-1 )
        ObsL(idxL+[-1:1])     = [ 0.25 1 0.25 ];
        ObsR(idxR+[-1:1])     = [ 0.25 1 0.25 ];
        ObsNeg(idxL+2:idxR-2) = 1;
        idxM = round((idxL+idxR)/2);
        ObsNeg(idxM+[-4:4])   = 0;        
    end
    
end


