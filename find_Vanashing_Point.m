
%%   Estimate the VP using a filter %%

function VanishingPt = find_Vanashing_Point(VanishingPt)



%% Required Interface

    global LANE_WIDTH 
   
    global VP_LANE_RATIO CM_TO_PIXEL
    
    global LANE_WIDTH_DIFF_NORMA LANE_WIDTH_DIFF_NOMIN OBS_NEG_NORMA OBS_NEG_NOMIN
    
    global HORIZON_HISTOGRAM_STEP HORIZON_HISTOGRAM_BINS 
    
    global VP_FILTER_OFFSET_V VP_BINS_V VP_BINS_H  
    
    global LANE_BOUNDARIES  INT_HIST_VP_PROB_int32
    
    global VP_TRANSITION VP_PRIOR
    
    global CrossCheck Path
    

    
    %% Provided/Updated Interface    
    global VP_FILTER 

   
    %% Predict Step
    
      %% APEX PROCESS %%
      TEMP = imfilter( VP_FILTER, VP_TRANSITION, 'Replicate' );
      TEMP = int32( (single(TEMP) / single(sum(sum(TEMP))) ) *2^16);
      VP_FILTER_TRANSITIONED = TEMP + VP_PRIOR ; 

    
      
      
      
      
      

    %% Update Step %%
      %% ARM LOOP %%
    
    best  = 0;
    NegBoundaryVPModel= struct;
    
    for nv = 1:size(VP_BINS_V,2)
        for nh = 1:size(VP_BINS_H,2)


            %% Get Expected VP
            TMP_VP_V = -VP_BINS_V(nv); %% V axis is reversed for VP coordinate system 
            TMP_VP_H =  VP_BINS_H(nh);
            nbBins = size(HORIZON_HISTOGRAM_BINS,2);


            %% Left Index
            L  = (LANE_BOUNDARIES(1,1) + LANE_BOUNDARIES(2,1))/2; %% in VP coordiante system
            DX = TMP_VP_H - L;
            DY = TMP_VP_V + 240;
            IL = (DX/DY) * (VP_FILTER_OFFSET_V - TMP_VP_V) + TMP_VP_H;
            IL   = HORIZON_HISTOGRAM_STEP * round( IL/HORIZON_HISTOGRAM_STEP );

            IdxLeft  = ( (IL - HORIZON_HISTOGRAM_BINS(1,1) )/HORIZON_HISTOGRAM_STEP ) +1;

            %% Right Index

            R  = (LANE_BOUNDARIES(1,2) + LANE_BOUNDARIES(2,2))/2; %% in VP coordiante system 
            DX = TMP_VP_H - R;
            DY = TMP_VP_V + 240;
            IR = (DX/DY) * (VP_FILTER_OFFSET_V - TMP_VP_V) + TMP_VP_H; 
            IR   = HORIZON_HISTOGRAM_STEP * round( IR/HORIZON_HISTOGRAM_STEP );

            IdxRight  = ( (HORIZON_HISTOGRAM_BINS(1,nbBins) - IR)/HORIZON_HISTOGRAM_STEP );
            IdxRight  = nbBins- IdxRight;


            %% Mid Index
            
            idxM  = round((IdxLeft+IdxRight)/2);
            nbLeftNonBoundaryBins  = (idxM-3) - (IdxLeft+2) ;        
            nbRightNonBoundaryBins = (IdxRight-2) - (idxM+3); 
            nbNonBoundaryBins      = nbLeftNonBoundaryBins + nbRightNonBoundaryBins;


       


            %% Valid Bins Only
            if 2 <= IdxLeft && IdxRight <= nbBins-1

                
                
                
                %% Construct NegBoundary Model for VP 
                
                NegBoundaryVPModel.BinID = ones(1, nbNonBoundaryBins);
                for i= 0: nbLeftNonBoundaryBins-1
                  NegBoundaryVPModel.BinID(i+1)= (IdxLeft +2) +i;
                end

                for i= 0: nbRightNonBoundaryBins-1
                  NegBoundaryVPModel.BinID(nbLeftNonBoundaryBins+i+1)= (idxM + 4) +i;
                end

                
                %% Probability of VP from Lane Width'
                
                Width = (1/VP_LANE_RATIO) * single(IR-IL) * (1/CM_TO_PIXEL);
                WidthProb_float   = LANE_WIDTH_DIFF_NORMA * exp( -(LANE_WIDTH-Width)^2 / LANE_WIDTH_DIFF_NOMIN );
                
                
                
                %% Probability of VP from Boundary Segments of the Lane

                likelihoodLeftLaneVP =    single( INT_HIST_VP_PROB_int32(IdxLeft-1) )*0.25 ...
                                        + single( INT_HIST_VP_PROB_int32(IdxLeft)   )...
                                        + single( INT_HIST_VP_PROB_int32(IdxLeft+1) )*0.25;

                likelihoodLeftLaneVP_int32 = int32(likelihoodLeftLaneVP);



                likelihoodRightLaneVP =   single( INT_HIST_VP_PROB_int32(IdxRight-1) )*0.25 ...
                                        + single( INT_HIST_VP_PROB_int32(IdxRight) )      ...
                                        + single( INT_HIST_VP_PROB_int32(IdxRight+1) )*0.25;

                likelihoodRightLaneVP_int32 = int32(likelihoodRightLaneVP);   


                
                
                %% Probability of VP from Non-Boundary Segments of the Lane

                NegBoundaryCorrelation_int32 =0;

                for idx=1:size(NegBoundaryVPModel.BinID,2)
                     ID           = NegBoundaryVPModel.BinID(idx);
                     NegBoundaryCorrelation_int32   = NegBoundaryCorrelation_int32 + INT_HIST_VP_PROB_int32(ID);                      
                end

                 x = single(NegBoundaryCorrelation_int32)/2^16;  


                likelihoodNegBoundaryVP_float  = OBS_NEG_NORMA * exp( -x^2/OBS_NEG_NOMIN );


                %% Combined Conditional Probabability
                conditional_prob          =  likelihoodLeftLaneVP_int32 * likelihoodRightLaneVP_int32; 
                conditional_prob_float    =  single(conditional_prob) *2^-16;
                conditional_prob_float    =  conditional_prob_float*WidthProb_float;
                conditional_prob_float    =  (conditional_prob_float * likelihoodNegBoundaryVP_float);

                

                %% Update the Filter
                posterior_prob_int32 = int32( conditional_prob_float*  single(VP_FILTER_TRANSITIONED(nv,nh)) );
                VP_FILTER(nv,nh) = posterior_prob_int32;

                %% Already keep Track of Max Probable State

                if best < posterior_prob_int32

                    UPD_VP_V  = -TMP_VP_V;      %% to center image coordinate system
                    UPD_VP_H  =  TMP_VP_H;      %% to center image coordinate system
                    best = posterior_prob_int32;

                end

            end   
            

        end
    end

    
    %% Assign the new VP %%
    VanishingPt.V_prev = VanishingPt.V;
    VanishingPt.H_prev = VanishingPt.H;
    VanishingPt.V = UPD_VP_V;
    VanishingPt.H = UPD_VP_H;
    
    VanishPt = [VanishingPt.V; VanishingPt.H];
    
       if CrossCheck==true
        
        dlmwrite(strcat(Path,    'TransitionedVP.csv'),  VP_FILTER_TRANSITIONED,  'delimiter',   ',', 'precision', 9);
        dlmwrite(strcat(Path, 'UpdatedVPFilter.csv'), VP_FILTER,   'delimiter',   ',', 'precision', 9);
        dlmwrite(strcat(Path,      'VanishingPt.csv'), VanishPt,   'delimiter',   ',', 'precision', 9);

       end


end

