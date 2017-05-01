%%
%%
%%
%% create the probability of lane observations given the state
%% All in the VP coordinate system
%%
%%
function [LaneBoundaryModel, NegLaneBoundaryModel, Width ] = createVPObservationModel( LANE_BOUNDARIES, TMP_VP_H, TMP_VP_V, HORIZON_HISTOGRAM_STEP, HORIZON_HISTOGRAM_BINS, VP_FILTER_OFFSET_V )
       


    %% Compute Intersection With Current Horizon %%
    
    L  = (LANE_BOUNDARIES(1,1) + LANE_BOUNDARIES(2,1))/2; %% in VP coordiante system
     
   
    
    DX = TMP_VP_H - L;
    DY = TMP_VP_V + 240;
    IL = (DX/DY) * (VP_FILTER_OFFSET_V - TMP_VP_V) + TMP_VP_H;
    
    R  = (LANE_BOUNDARIES(1,2) + LANE_BOUNDARIES(2,2))/2; %% in VP coordiante system
    

    
    DX = TMP_VP_H - R;
    DY = TMP_VP_V + 240;
    IR = (DX/DY) * (VP_FILTER_OFFSET_V - TMP_VP_V) + TMP_VP_H;
    

 
    %% To Histogram Bins %%
    
    IL   = HORIZON_HISTOGRAM_STEP * round( IL/HORIZON_HISTOGRAM_STEP );
    IR   = HORIZON_HISTOGRAM_STEP * round( IR/HORIZON_HISTOGRAM_STEP );
    nbBins = size(HORIZON_HISTOGRAM_BINS,2);
    
    
    
    %% To Histogram Bins-ID
    idxL  = ( (IL - HORIZON_HISTOGRAM_BINS(1,1) )/HORIZON_HISTOGRAM_STEP ) +1;
    
    idxR  = ( (HORIZON_HISTOGRAM_BINS(1,nbBins) - IR)/HORIZON_HISTOGRAM_STEP );
    idxR  = nbBins- idxR;
    
    idxM  = round((idxL+idxR)/2);
    

    nbLeftNonBoundaryBins  = (idxM-3) - (idxL+2) ;    
    
    nbRightNonBoundaryBins = (idxR-2) - (idxM+3);
    
    nbNonBoundaryBins      = nbLeftNonBoundaryBins + nbRightNonBoundaryBins;

        
    
%% Create Expected Models %%


    Width = IR-IL;

    LaneBoundaryModel= struct;
        LaneBoundaryModel.BinID = ones(6,1);
        LaneBoundaryModel.Value = zeros(6,1);   
    
    %Note Value member is needed only for the Lane Boundary Model
    %     This is because in case of illegitimate intersections the lane
    %     boundary probability will become 'zero' and so does the overall
    %     probability.
    
    NegLaneBoundaryModel= struct;
        NegLaneBoundaryModel.BinID = ones(nbNonBoundaryBins,  1);


    if 2 <= idxL && idxR <= nbBins-1
        
          LaneBoundaryModel.BinID(1,1) = idxL-1;
          LaneBoundaryModel.BinID(2,1) = idxL;
          LaneBoundaryModel.BinID(3,1) = idxL+1;

          LaneBoundaryModel.BinID(4,1) = idxR-1;
          LaneBoundaryModel.BinID(5,1) = idxR;
          LaneBoundaryModel.BinID(6,1) = idxR+1;



          LaneBoundaryModel.Value(1,1) = 0.25;
          LaneBoundaryModel.Value(2,1) = 1;
          LaneBoundaryModel.Value(3,1) = 0.25;

          LaneBoundaryModel.Value(4,1) = 0.25;
          LaneBoundaryModel.Value(5,1) = 1;
          LaneBoundaryModel.Value(6,1) = 0.25;


         for i= 0: nbLeftNonBoundaryBins-1
              NegLaneBoundaryModel.BinID(i+1)= (idxL +2) +i;
         end

         for i= 0: nbRightNonBoundaryBins-1
              NegLaneBoundaryModel.BinID(nbLeftNonBoundaryBins+i+1)= (idxM + 4) +i;
         end
      
 
         
    end
    
end
