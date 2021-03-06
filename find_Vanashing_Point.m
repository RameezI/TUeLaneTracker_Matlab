
%%   Estimate the VP using a filter %%

function VanishingPt = find_Vanashing_Point(VanishingPt)



%% Required Interface

    global VP_LANE_RATIO CM_TO_PIXEL LANE_WIDTH C_V C_H 
    
    global LANE_WIDTH_DIFF_NORMA LANE_WIDTH_DIFF_NOMIN OBS_NEG_NORMA OBS_NEG_NOMIN
    
    global HORIZON_HISTOGRAM_STEP HORIZON_HISTOGRAM_BINS 
    
    global VP_FILTER_OFFSET_V VP_BINS_V VP_BINS_H  
    
    global LANE_BOUNDARIES INT_HIST_VP_PROB
    
    global VP_TRANSITION VP_PRIOR
    
    

    
    %% Provided/Updated Interface    
    global VP_FILTER 

   
    %% Predict Step
    
      %% APEX PROCESS %%
      TEMP = imfilter( VP_FILTER, VP_TRANSITION, 'Replicate' );
      TEMP = int32( (single(TEMP) / single(sum(sum(TEMP))) ) *2^15);
      VP_FILTER_TRANSITIONED = 0.5*TEMP +0.5*VP_PRIOR ; 

    

    %% Update Step %%
      %% ARM LOOP %%
    
    best  = 0;
    
    for nv = 1:size(VP_BINS_V,2)
        for nh = 1:size(VP_BINS_H,2)


         %Get Expected VP%
            TMP_VP_V = -VP_BINS_V(nv); %% V axis is reversed for VP coordinate system 
            TMP_VP_H =  VP_BINS_H(nh);
            
            
          [LaneBoundaryModel,NegLaneBoundaryModel, WidthPx] = createVPObservationModel( LANE_BOUNDARIES, TMP_VP_H, TMP_VP_V, HORIZON_HISTOGRAM_STEP, HORIZON_HISTOGRAM_BINS, VP_FILTER_OFFSET_V );
            
            
         % Probability of the Lane according to Lane Widith
            
            Width       = (1/VP_LANE_RATIO) * WidthPx * (1/CM_TO_PIXEL);
            WidhtProb   = LANE_WIDTH_DIFF_NORMA * exp( -(LANE_WIDTH-Width)^2 / LANE_WIDTH_DIFF_NOMIN );
            

          % Probability of Boundary Segments of the Lane
                BoundaryProb     = 0;
                
                ObservedHistogramHorizon = INT_HIST_VP_PROB';

                for idx=1:size(LaneBoundaryModel.BinID,2)
                     ID           = LaneBoundaryModel.BinID(idx);
                     Value        = LaneBoundaryModel.Value(idx);
                     BoundaryProb = BoundaryProb + ObservedHistogramHorizon(ID)*Value;               
                end
            

            
            % Probability of Non-Boundary Segments of the Lane
                x= 0;

                for idx=1:size(NegLaneBoundaryModel.BinID,2)
                     ID           = NegLaneBoundaryModel.BinID(idx);
                     x = x+ ObservedHistogramHorizon(ID);               
                end

                NegBoundaryProb        = OBS_NEG_NORMA * exp( -x^2/OBS_NEG_NOMIN );
                
                
                
            % Combined Conditional Probabability
                conditional_prob = int32(BoundaryProb * NegBoundaryProb * WidhtProb * 2^15 );
                

            
            %Update the Filter %%

                VP_FILTER(nv,nh) = VP_FILTER_TRANSITIONED(nv,nh) * conditional_prob;
            
            
            
            % Already keep Track of Max Probable State
           
            if best < VP_FILTER(nv,nh)
                UPD_VP_V  = -TMP_VP_V;  %% to center image coordinate system
                UPD_VP_H  =  TMP_VP_H;   %% to center image coordinate system
                best = VP_FILTER(nv,nh);
            end
            
            

        end
    end


    %% Normalize %%
        %% APEX Process %%
    VP_FILTER = int32( (single(VP_FILTER) / single( sum(sum(VP_FILTER)) )   )*2^15);

    
    %% Assign the new VP %%
    VanishingPt.V_prev = VanishingPt.V;
    VanishingPt.H_prev = VanishingPt.H;
    VanishingPt.V = UPD_VP_V;
    VanishingPt.H = UPD_VP_H;

end

