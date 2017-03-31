%%
%%
%%
%% create the probability of lane observations given the state
%% All in the VP coordinate system
%%
%%
function [ Obs, ObsN, Width ] = createVPObservationModel( LANE_BOUNDARIES, TMP_VP_H, TMP_VP_V, VP_STEP_HST, VP_BINS_HST, OFFSET )
       
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% compute intersection with current horizon %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    L  = (LANE_BOUNDARIES(1,1) + LANE_BOUNDARIES(2,1))/2; %% in VP coordiante system
    DX = TMP_VP_H - L;
    DY = TMP_VP_V + 240;
    IL = (DX/DY) * (OFFSET - TMP_VP_V) + TMP_VP_H;
    
    R  = (LANE_BOUNDARIES(1,2) + LANE_BOUNDARIES(2,2))/2; %% in VP coordiante system
    DX = TMP_VP_H - R;
    DY = TMP_VP_V + 240;
    IR = (DX/DY) * (OFFSET - TMP_VP_V) + TMP_VP_H;
    
%     figure(800)
%     clf
%     hold on
%     plot( [L TMP_VP_H], [-240 TMP_VP_V], 'b' )
%     plot( [TMP_VP_H TMP_VP_H], [TMP_VP_V TMP_VP_V], 'ob' )
%     plot( [TMP_VP_H R], [TMP_VP_V -240], 'r' )
%     plot( [TMP_VP_H TMP_VP_H], [TMP_VP_V TMP_VP_V], 'xr' )
%     plot( [-320 320], [OFFSET OFFSET], 'k' )
%     plot( [-320 320], [-240 -240], 'k' )
%     plot( [IL IL], [OFFSET OFFSET], 'ob' )
%     plot( [IR IR], [OFFSET OFFSET], 'xr' )
%     axis([-320 320 -240 240]);
%     axis equal    
%     grid on
%     drawnow
%     pause
    
    
    %%%%%%%%%%%%%%%%%%%%%%%
    %% to histogram bins %%
    %%%%%%%%%%%%%%%%%%%%%%%
    IL   = VP_STEP_HST * round( IL/VP_STEP_HST );
    IR   = VP_STEP_HST * round( IR/VP_STEP_HST );
    idxL = find( IL == VP_BINS_HST );
    idxR = find( IR == VP_BINS_HST );
        
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% create the observation model %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    nBPX = size(VP_BINS_HST,2);
    ObsL = zeros( nBPX, 1 );
    ObsR = zeros( nBPX, 1 );
    ObsN = zeros( nBPX, 1 );
    
    %%%%%%%%%
    %% set %%
    %%%%%%%%%
    if ~isempty(idxL) && ~isempty(idxR) && 2 <= idxL && idxR <= nBPX-1
        ObsL(idxL+[-1:1])= [0.25 1 0.25];
        ObsR(idxR+[-1:1])= [0.25 1 0.25];
        ObsN(idxL+2:idxR-2) = 1;
        idxM                = round((idxL+idxR)/2);
        ObsN(idxM+[-4:4])   = 0; 
    end
    Obs   = ObsL+ObsR;
    Width = IR-IL; 
    
end
