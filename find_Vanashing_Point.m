
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%%   Estimate the VP using a filter
%%   This is not yet that advanced        
%%          
%%              
%%       
%%
%% 
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function VanishingPt = find_Vanashing_Point(VanishingPt)

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    global LANE_WIDTH_DIFF_NORMA LANE_WIDTH_DIFF_NOMIN LANE_WIDTH VP_LANE_RATIO CM_TO_PIXEL OBS_NEG_NORMA OBS_NEG_NOMIN VP_BINS_HST VP_STEP_HST VP_TRANSITION VP_FILTER_OFFSET_V VP_PRIOR VP_BINS_V VP_BINS_H LANE_BOUNDARIES INT_HIST_VP_PROB VP_FILTER SEGMENT_EDGE SEGMENT C_V C_H

        
    
    %%%%%%%%%%%%%%%%%%
    %% predict step %%
    %%%%%%%%%%%%%%%%%%
    VP_FILTER = imfilter( VP_FILTER, VP_TRANSITION, 'Replicate' );
    VP_FILTER = VP_FILTER / sum(VP_FILTER(:),1);
    VP_FILTER = 0.5*VP_FILTER + 0.5*VP_PRIOR;

    
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     %% show histogram and model %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%     sfigure(136);
%     clf           
%     h = bar3( VP_FILTER );               
%     hold on    
%     set(h,'EdgeColor','none');
%     axis vis3d
%     view(135,35);
%     title('VP FILTER PREDICT')
%     drawnow
    
    
    
    %%%%%%%%%%%%
    %% update %%
    %%%%%%%%%%%%
    O_V = C_V; %% + VP_V; %% center is VP in image coordinates
    O_H = C_H; %% + VP_H; %% center is VP in image coordinates
    for nv = 1:size(VP_BINS_V,2)
        for nh = 1:size(VP_BINS_H,2)

            %%%%%%%%%%%%%%%%%%%%%
            %% get expected VP %%
            %%%%%%%%%%%%%%%%%%%%%
            TMP_VP_V = VP_BINS_V(nv); 
            TMP_VP_H = VP_BINS_H(nh);
            
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %% to current VP coordinate system %%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            TMP_VP_V = -(TMP_VP_V - O_V); %% V axis is reversed for VP coordinate system 
            TMP_VP_H =  TMP_VP_H - O_H; %% H axis has the same orientation
            
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %% create the observation model %%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            [model, modelN, width] = createVPObservationModel( LANE_BOUNDARIES, TMP_VP_H, TMP_VP_V, VP_STEP_HST, VP_BINS_HST, VP_FILTER_OFFSET_V );
            width = (1/VP_LANE_RATIO) * width * (1/CM_TO_PIXEL);
            
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %% the likelihood of the observations given %% 
            %% te model                                 %%                                  
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            negP        = OBS_NEG_NORMA * exp( -sum( modelN.*INT_HIST_VP_PROB', 1 )^2/OBS_NEG_NOMIN );
            widhtP      = LANE_WIDTH_DIFF_NORMA * exp( -(LANE_WIDTH-width)^2 / LANE_WIDTH_DIFF_NOMIN );
            update_prob = sum( INT_HIST_VP_PROB' .* model, 1) * negP * widhtP;
                       
%             sfigure(562);
%             bar([1:size(model,1)],model)
%             drawnow
            
            %%%%%%%%%%%%%%%%%%%%%%%
            %% update the filter %%
            %%%%%%%%%%%%%%%%%%%%%%%
            VP_FILTER(nv,nh) = VP_FILTER(nv,nh) * update_prob;

        end
    end



    %%%%%%%%%%%%%%%
    %% normalize %%
    %%%%%%%%%%%%%%%
    VP_FILTER = VP_FILTER / sum( sum(VP_FILTER) );



%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     %% show histogram and model %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%     sfigure(137);
%     clf           
%     h = bar3( VP_FILTER );               
%     hold on    
%     set(h,'EdgeColor','none');
%     axis vis3d
%     view(135,35);
%     title('VP FILTER UPDATE')
%     drawnow

        
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% get the max probable state %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    [mx idx]    = max(VP_FILTER(:),[],1);
    [idxV idxH] = ind2sub( size(VP_FILTER), idx );
    TMP_VP_V    = VP_BINS_V(idxV); %% from index to bin in center coordinate system
    TMP_VP_H    = VP_BINS_H(idxH); %% from index to bin in center coordinate system
    TMP_VP_V    = -C_V + TMP_VP_V; %% to center image coordinate system
    TMP_VP_H    = -C_H + TMP_VP_H; %% to center image coordinate system
    UPD_VP_V    = TMP_VP_V;
    UPD_VP_H    = TMP_VP_H;
    
    

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% contract solution                                   %%
    %% here we use the VP to get back to image coordinates %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   % [SEGMENT SEGMENT_TIGHT SEGMENT_VERY_TIGHT SEGMENT_WIDE] = createEgoLaneMask( LANE_BOUNDARIES, C_V, C_H, VanishingPt.V, VanishingPt.H );
    
    
    
    %%%%%%%%%%%%%%
    %% get mask %%
    %%%%%%%%%%%%%%                        
   % SEGMENT_EDGE = SEGMENT_WIDE - SEGMENT_VERY_TIGHT;
    
    
    
    %%%%%%%%%%%%%%%%%%%%%%
    %% asign the new VP %%
    %%%%%%%%%%%%%%%%%%%%%%
    VanishingPt.V_prev = VanishingPt.V;
    VanishingPt.H_prev = VanishingPt.H;
    VanishingPt.V = UPD_VP_V;
    VanishingPt.H = UPD_VP_H;

end

