%%
%%
%%
%% create the prior over lanes
%% expressed as histograms
%%
%%



function [ Prior, Trans] = createLanePrior( bins, pix_to_cm, meanL, minL, maxL, sigmaL  )



    
    %% fill histogram
    nHalfBins  = size(bins,2);
    Prior  = ones( nHalfBins, nHalfBins );
    hmean  = meanL/2;  %% half lane width
    bins   = bins * pix_to_cm;
    
    
validRightOffsets =cell(nHalfBins,1);    
    
    
    for leftOffset = 1:nHalfBins
             
        validRigthOffsets{leftOffset,1} =[];
        
        for rightOffset = 1:nHalfBins
            
                    %% prior on location
                        pL = exp( -(hmean-bins(leftOffset))^2 / (2*(8*sigmaL)^2) ) / ( sqrt(2*pi)*8*sigmaL );     
                        pR = exp( -(hmean-bins(rightOffset))^2 / (2*(8*sigmaL)^2) ) / ( sqrt(2*pi)*8*sigmaL );     

                        %% prior on lane width
                        width = bins(leftOffset)+bins(rightOffset);


                        if minL <= width && width <= maxL            
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