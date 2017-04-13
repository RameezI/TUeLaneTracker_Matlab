

%%
%% state function
%%
function [msg, VanishingPt, Templates, Likelihoods, Mask] = run_Detecting_Ego_Lane_State( VanishingPt, Templates, Likelihoods, Mask )

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%    
    global STATE_READY STATE_BUSY STATE_ERROR STATE_COUNTER N_IMAGE
    
    global PROB_KeyFrame
    
    %%
    %% Add an Image to the Buffer 
    RGB = readImage( N_IMAGE );
    [Templates, Likelihoods, Mask] = add_Image_To_Buffer(RGB, VanishingPt, Templates, Likelihoods, Mask );
    
    % If this is a KeyFrame or if its the first run.
    % Process only frames that contributes something new 
  %  if 1 == added || STATE_COUNTER == 0
               
        STATE_COUNTER = STATE_COUNTER + 1;
          
        %%
        %% Filter out Horizon based on Focus Mask %
        [IDX_FOC_TOT_P, Likelihoods] = filter_And_Focus(Likelihoods,Mask); 
        
                
        %%
        %% Find Lane Candidatae in the ROI %%
        [msg, VanishingPt] = find_Lane_Candidates( VanishingPt, IDX_FOC_TOT_P, Likelihoods, Templates, Mask);
        
       
        %%
        %% Update the center lane %%
        find_Center_Lane();        
     
        showResults( RGB, VanishingPt, msg );
                    
        %%
        %% State Staus Update %%
        if msg ~= STATE_ERROR
            
                msg = STATE_READY;
           
        end
        
        
end
            
  



