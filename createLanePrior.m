%%
%%
%%
%% create the prior over lanes
%% expressed as histograms
%%
%%



function [ Prior, Trans, LaneBoundaryModels, NegLaneBoundaryModels] = createLanePrior( binsLaneOffsets,binsBaseHistogram, Pix_To_Cm, MeanL, MinL, MaxL, SigmaL  )
 

% Lane OffSet Bins

        nbOffsetBins             = size(binsLaneOffsets,2);
        nbBaseHistogramBins      = size(binsBaseHistogram,2);
        
        
        Prior         = zeros(nbOffsetBins, nbOffsetBins );
       
        
        hmean  = MeanL/2;  %% half lane width
        binsLaneOffsets_cm   = binsLaneOffsets * Pix_To_Cm;
    
        
        
% laneBoundaryModel Structure:
                              %leftOffsetIdx
                              %rightOffsetIdx
                              %histogramBinIDs_LeftBoundary
                              %histogramBinIDs_RightBoundary
                              %histogramWeights_LeftBoundary
                              %histogramWeights_RightBoundary

% negLaneBoundaryModel Structure:
                              %
                              %HistogramBinIDs
                              

        
        
        LaneBoundaryModels    = struct;    % This is an array of structures
        NegLaneBoundaryModels = struct;         
            
        ModelsCount = 0;
        
    
    for leftOffsetIdx = 1:nbOffsetBins
        for rightOffsetIdx = 1:nbOffsetBins
            
            

                 % Prior on Location
                    pL = exp( -(hmean-binsLaneOffsets_cm(leftOffsetIdx))^2 / (2*(8*SigmaL)^2) ) / ( sqrt(2*pi)*8*SigmaL );     
                    pR = exp( -(hmean-binsLaneOffsets_cm(rightOffsetIdx))^2 / (2*(8*SigmaL)^2) ) / ( sqrt(2*pi)*8*SigmaL );
                    
                    

                 %Prior on Lane Width
                    width = binsLaneOffsets_cm(leftOffsetIdx)+binsLaneOffsets_cm(rightOffsetIdx);

                              

                 % Eligibility for  a valid State
                 
                    if MinL <= width && width <= MaxL           
                        
                        
                        
                        
                        % To Histogram Bins-ID
                        idxL  = nbOffsetBins-(leftOffsetIdx-1);
                        idxR  = nbOffsetBins+(rightOffsetIdx-1) ;
                        
                        idxM  = round((idxL+idxR)/2);
                        
                        nbLeftNonBoundaryBins  = (idxM-3) - (idxL+2) ;         
                        nbRightNonBoundaryBins = (idxR-2) - (idxM+3); 
                        

                              if( 2 <= idxL && idxR <= nbBaseHistogramBins-1 )

                                  ModelsCount= ModelsCount + 1;

                                % Fill In LaneBoundaryModel
                                  LaneBoundaryModels(ModelsCount).leftOffsetIdx = leftOffsetIdx;
                                  LaneBoundaryModels(ModelsCount).rightOffsetIdx= rightOffsetIdx;                         

                                  LaneBoundaryModels(ModelsCount).histogramBinIDs_leftBoundary   =[ idxL-1, idxL, idxL+1 ] ;
                                  LaneBoundaryModels(ModelsCount).histogramBinIDs_rightBoundary  =[ idxR-1, idxR, idxR+1 ];                         

                                  LaneBoundaryModels(ModelsCount).histogramWeights_leftBoundary  = [0.25 1 0.25];
                                  LaneBoundaryModels(ModelsCount).histogramWeights_rightBoundary = [0.25 1 0.25];



                                  for i= 0: nbLeftNonBoundaryBins-1
                                            NegLaneBoundaryModels(ModelsCount).histogramBinsID(i+1)= (idxL +2) +i;
                                  end

                                  for i= 0: nbRightNonBoundaryBins-1
                                            NegLaneBoundaryModels(ModelsCount).histogramBinsID(nbLeftNonBoundaryBins+i+1)= (idxM + 4) +i;
                                  end
                                  
                                  Prior(leftOffsetIdx,rightOffsetIdx) = pL*pR;


                              end  
                                  

                    %else
                        
                        %Prior(leftOffsetIdx,rightOffsetIdx) = 0;                
                    
                    end


        end

    end
    
    % Normalize
    Prior = Prior / sum(sum(Prior));

    
    % Transition
    Trans = ones(10);
    
end