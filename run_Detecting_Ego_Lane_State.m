

%%
%% state function
%%
function [msg, VanishingPt, Templates, Likelihoods, Mask] = run_Detecting_Ego_Lane_State(N_IMAGE, VanishingPt, Templates, Likelihoods, Mask )

  
    global STATE_READY STATE_ERROR STATE_COUNTER 
    
    
    %% Add an Image to the Buffer 
    
        RGB = readImage( N_IMAGE );
        [Templates, Likelihoods, Mask] = add_Image_To_Buffer(RGB, VanishingPt, Templates, Likelihoods, Mask );
    
               
       
          
    %% Filter out Horizon based on Focus Maaccumarraysk %
       Likelihoods = filter_And_Focus(Likelihoods,Mask, VanishingPt); 
        
                
    %% Find Lane Candidatae in the ROI %%
        msg = find_Lane_Candidates(Likelihoods, Templates);
        

    %% Update Vanishing Point %%
       VanishingPt=find_Vanashing_Point(VanishingPt);     
        
        
        
    %% State Staus Update %%

        if msg ~= STATE_ERROR
            msg = STATE_READY;             
        end
                

        
    %% Update the center lane %%
        find_Center_Lane();             
        showResultsSimple( RGB, VanishingPt, msg );
        
        

        
        
end
            
  



