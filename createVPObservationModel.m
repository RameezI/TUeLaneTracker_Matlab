%%
%%
%%
%% create the probability of lane observations given the state
%% All in the VP coordinate system
%%
%%
function [LaneBoundaryModel, NegLaneBoundaryModel, Width ] = createVPObservationModel( LANE_BOUNDARIES, TMP_VP_H, TMP_VP_V, HORIZON_HISTOGRAM_STEP, HORIZON_HISTOGRAM_BINS, VP_FILTER_OFFSET_V )
       

    nbBins = size(HORIZON_HISTOGRAM_BINS,2);

%%
    L  = (LANE_BOUNDARIES(1,1) + LANE_BOUNDARIES(2,1))/2; %% in VP coordiante system
    DX = TMP_VP_H - L;
    DY = TMP_VP_V + 240;
    IL = (DX/DY) * (VP_FILTER_OFFSET_V - TMP_VP_V) + TMP_VP_H;
    IL   = HORIZON_HISTOGRAM_STEP * round( IL/HORIZON_HISTOGRAM_STEP );
    
    idxL  = ( (IL - HORIZON_HISTOGRAM_BINS(1,1) )/HORIZON_HISTOGRAM_STEP ) +1;
    
    %% Use Asynch to prarrelise the two computations
    
    R  = (LANE_BOUNDARIES(1,2) + LANE_BOUNDARIES(2,2))/2; %% in VP coordiante system 
    DX = TMP_VP_H - R;
    DY = TMP_VP_V + 240;
    IR = (DX/DY) * (VP_FILTER_OFFSET_V - TMP_VP_V) + TMP_VP_H; 
    IR   = HORIZON_HISTOGRAM_STEP * round( IR/HORIZON_HISTOGRAM_STEP );
    
    idxR  = ( (HORIZON_HISTOGRAM_BINS(1,nbBins) - IR)/HORIZON_HISTOGRAM_STEP );
    idxR  = nbBins- idxR;

    
  %%
    
    idxM  = round((idxL+idxR)/2);
    nbLeftNonBoundaryBins  = (idxM-3) - (idxL+2) ;        
    nbRightNonBoundaryBins = (idxR-2) - (idxM+3); 
    nbNonBoundaryBins      = nbLeftNonBoundaryBins + nbRightNonBoundaryBins;


    Width = IR-IL;

    LaneBoundaryModel= struct;
        LaneBoundaryModel.BinID = ones(1,6);
        LaneBoundaryModel.Value = zeros(1,6);   
    
    %Note Value member is needed only for the Lane Boundary Model
    %     This is because in case of illegitimate intersections the lane
    %     boundary probability will become 'zero' and so does the overall
    %     probability.
    
    NegLaneBoundaryModel= struct;
        NegLaneBoundaryModel.BinID = ones(1, nbNonBoundaryBins);


    if 2 <= idxL && idxR <= nbBins-1
        
          LaneBoundaryModel.BinID = [idxL-1, idxL, idxL+1, idxR-1, idxR, idxR+1];


          LaneBoundaryModel.Value = [0.25, 1, 0.25, 0.25, 1, 0.25];



         for i= 0: nbLeftNonBoundaryBins-1
              NegLaneBoundaryModel.BinID(i+1)= (idxL +2) +i;
         end

         for i= 0: nbRightNonBoundaryBins-1
              NegLaneBoundaryModel.BinID(nbLeftNonBoundaryBins+i+1)= (idxM + 4) +i;
         end
      
 
         
    end
    
end
