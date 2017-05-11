%%
%% create the probability of lane observations given the state

function [ laneBoundaryModel, negLaneBoundaryModel ] = createLaneObservationModel( binsLaneOffset, binsBaseHistogram, MIN_LANE_WIDTH, MAX_LANE_WIDTH, CM_TO_PIXEL )


    NbOffsetsBins            = size(binsLaneOffset,2);
    NbLaneHistogramBins      = size(binsBaseHistogram,2);
         
    
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
                      
                      
                       for i= 0: nbLeftNonBoundaryBins-1
                            negLaneBoundaryModel(left,right).BinID(i+1)= (idxL +2) +i;
                       end

                       for i= 0: nbRightNonBoundaryBins-1
                            negLaneBoundaryModel(left,right).BinID(nbLeftNonBoundaryBins+i+1)= (idxM + 4) +i;
                       end
                      
                      
                 end

              
            
            end                    
            
        end
        
    end
    
end
    



