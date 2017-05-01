%%
%%
%%
%% create the probability of lane observations given the state
%%
%%
function [ LaneBoundaryModel_Left,LaneBoundaryModel_Right,laneBoundaryModel, NegLaneBoundaryModel ] = createLaneObservationModel( binsLaneOffset, binsBaseHistogram, MIN_LANE_WIDTH, MAX_LANE_WIDTH, CM_TO_PIXEL )



    %% default
    NbOffsetsBins            = size(binsLaneOffset,2);
    NbLaneHistogramBins      = size(binsBaseHistogram,2);
    
   
    
    LaneBoundaryModel_Left                 = zeros( NbOffsetsBins , NbLaneHistogramBins, NbOffsetsBins );
    LaneBoundaryModel_Right                = zeros( NbOffsetsBins , NbLaneHistogramBins, NbOffsetsBins );    
    NegLaneBoundaryModel                   = zeros( NbOffsetsBins , NbLaneHistogramBins, NbOffsetsBins ); 
    
    
    
    laneBoundaryModel= struct;
    negLaneBoundaryModel= struct;
    

    


    for left = 1:size(binsLaneOffset,2)
        
        for right = 1:size(binsLaneOffset,2)
    
            
            
            laneBoundaryModel(left,right).LeftBinID  = ones(3,1);
            laneBoundaryModel(left,right).LeftValue  = zeros(3,1);
            laneBoundaryModel(left,right).RightBinID = ones(3,1);
            laneBoundaryModel(left,right).RightValue = zeros(3,1);
            
            negLaneBoundaryModel(left,right).BinID = [];
            
           
            
            width = (binsLaneOffset(left)+binsLaneOffset(right)) * 1/CM_TO_PIXEL;
   
            % Only Allowed States
              
            if MIN_LANE_WIDTH <= width && width <= MAX_LANE_WIDTH

          
            % To Histogram Bins-ID
                 idxL  = NbOffsetsBins-(left-1);
                 idxR  = NbOffsetsBins+(right-1) ;
                 idxM  = round((idxL+idxR)/2);
                        
                 nbLeftNonBoundaryBins  = (idxM-3) - (idxL+2) ;         
                 nbRightNonBoundaryBins = (idxR-2) - (idxM+3);     
                 nbNonBoundaryBins      = nbLeftNonBoundaryBins + nbRightNonBoundaryBins;
   
                  negLaneBoundaryModel(left,right).BinID = ones(nbNonBoundaryBins,  1);
        
        
                 % Set using Gaussian pdf
                 if( 2 <= idxL && idxR <= NbLaneHistogramBins-1 )
  
                      laneBoundaryModel(left,right).LeftBinID(1,1) = idxL-1;
                      laneBoundaryModel(left,right).LeftBinID(2,1) = idxL;
                      laneBoundaryModel(left,right).LeftBinID(3,1) = idxL+1;

                      laneBoundaryModel(left,right).RightBinID(1,1) = idxR-1;
                      laneBoundaryModel(left,right).RightBinID(2,1) = idxR;
                      laneBoundaryModel(left,right).RightBinID(3,1) = idxR+1;



                      laneBoundaryModel(left,right).LeftValue(1,1) = 0.25;
                      laneBoundaryModel(left,right).LeftValue(2,1) = 1;
                      laneBoundaryModel(left,right).LeftValue(3,1) = 0.25;

                      laneBoundaryModel(left,right).RightValue(1,1) = 0.25;
                      laneBoundaryModel(left,right).RightValue(2,1) = 1;
                      laneBoundaryModel(left,right).RightValue(3,1) = 0.25;
                 end
%                 
                
                 
                [tempL, tempR, tempN] = fillLaneObservationModel( binsLaneOffset, binsBaseHistogram, left, right ); 
                LaneBoundaryModel_Left (left, :, right ) = tempL;
                LaneBoundaryModel_Right(left, :, right ) = tempR;
                NegLaneBoundaryModel   (left, :, right ) = tempN;
              
            
            end                    
            
        end
        
    end
    
end
    
    

%%
%% create the observation model for a single state
%%
function [ ObsL,ObsR, ObsNeg ] = fillLaneObservationModel( binsLaneOffset, binsBaseHistogram, leftIdx, rightIdx )    
    
    %% default
    NbLaneBins   = size(binsBaseHistogram,2);
    
    ObsL   = zeros( 1, NbLaneBins );
    ObsR   = zeros( 1, NbLaneBins );
    ObsNeg = zeros( 1, NbLaneBins ); 
    
    %% Location of the left and right Offset bins in the LaneBins;
    left  = -binsLaneOffset(leftIdx);
    right =  binsLaneOffset(rightIdx);
    
    idxL = find( binsBaseHistogram == left);
    idxR = find( binsBaseHistogram == right);
        
    %% set using Gaussian pdf
    if( 2 <= idxL && idxR <= NbLaneBins-1 )
        ObsL(idxL+[-1:1])     = [ 0.25 1 0.25 ];
        ObsR(idxR+[-1:1])     = [ 0.25 1 0.25 ];
        ObsNeg(idxL+2:idxR-2) = 1;
        idxM = round((idxL+idxR)/2);
        ObsNeg(idxM+[-4:4])   = 0;
    end
    
end


