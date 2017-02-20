

%%
%% state function
%%
function [msg, VanishingPt, Templates, Likelihoods, Masks] = run_Detecting_Ego_Lane_State( VanishingPt, Templates, Likelihoods, Masks )

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%    
    global STATE_READY STATE_BUSY STATE_ERROR STATE_COUNTER N_IMAGE
    
    global PROB_KeyFrame
    
    %%
    %% Add an Image to the Buffer 
    RGB = readImage( N_IMAGE );
    [added, Templates, Likelihoods, Masks] = add_Image_To_Buffer(RGB, VanishingPt, Templates, Likelihoods, Masks );
    
    % If this is a KeyFrame or if its the first run.
    % Process only frames that contributes something new 
    if 1 == added || STATE_COUNTER == 0
               
        STATE_COUNTER = STATE_COUNTER + 1;
          
        %%
        %% Filter out Horizon based on Focus Mask %
        [IDX_FOC_TOT_P, Likelihoods] = filter_And_Focus(Likelihoods,Masks); 
        
        %%
        %% Find Lane Candidatae in the ROI %%
        msg = find_Lane_Candidates( IDX_FOC_TOT_P, Likelihoods, Templates, Masks );
        

        %%
        %% Update Vanishing Point %%
        VanishingPt=find_Vanashing_Point(VanishingPt);
        
        
        %%
        %% Update the center lane %%
        find_Center_Lane();
        
        
        showResults( RGB, VanishingPt, msg );
                    
        %%
        %% State Staus Update %%
        if msg ~= STATE_ERROR
            
            if  1 <= STATE_COUNTER
                msg = STATE_READY;
            else
                msg = STATE_BUSY;
            end

        end
        
    else
        msg = STATE_BUSY;
    end
        
end
            
  



