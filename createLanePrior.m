%%
%%
%%
%% create the prior over lanes
%% expressed as histograms
%%
%%



function [ Prior, Trans] = createLanePrior( LANE_OFFSETS_BINS, Pix_To_Cm, MeanL, MinL, MaxL, SigmaL  )



    
    %% Fill Histogram
    
        nbOffsetBins  = size(LANE_OFFSETS_BINS,2);
        Prior         = ones(nbOffsetBins, nbOffsetBins );
       
        
        hmean  = MeanL/2;  %% half lane width
        LANE_OFFSETS_BINS   = LANE_OFFSETS_BINS * Pix_To_Cm;
    
    
        validRightOffsets =cell(nbOffsetBins,1);    
    
    
    for leftOffset = 1:nbOffsetBins
        
        %An Array of Vectors on C side
        validRightOffsets{leftOffset,1} =[];
        
        for rightOffset = 1:nbOffsetBins
            
             %% prior on location
                pL = exp( -(hmean-LANE_OFFSETS_BINS(leftOffset))^2 / (2*(8*SigmaL)^2) ) / ( sqrt(2*pi)*8*SigmaL );     
                pR = exp( -(hmean-LANE_OFFSETS_BINS(rightOffset))^2 / (2*(8*SigmaL)^2) ) / ( sqrt(2*pi)*8*SigmaL );     

             %% prior on lane width
                width = LANE_OFFSETS_BINS(leftOffset)+LANE_OFFSETS_BINS(rightOffset);


                if MinL <= width && width <= MaxL            
                    Prior(leftOffset,rightOffset) = pL*pR;
                    validRightOffsets{leftOffset,1}= [validRightOffsets{leftOffset,1}, rightOffset];          

                else
                            Prior(leftOffset,rightOffset) = 0;                
                end

            
        end
        
    end
    
    %% normalize
    Prior = Prior / sum(sum(Prior));

    
    %% Transition
    Trans = ones(10);
end