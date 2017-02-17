

%%
%% state function
%%
function [msg] = run_Detecting_Ego_Lane_State( nimage )

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%    
    global STATE_READY STATE_BUSY STATE_ERROR STATE_COUNTER
    
    global PROB_KeyFrame
    
    %%
    %% Add an Image to the Buffer 
    RGB = readImage( nimage );
    added = add_Image_To_Buffer( RGB);
    
    % If this is a KeyFrame or if its the first run.
    % Process only frames that contributes something new 
    if 1 == added || STATE_COUNTER == 0
               
        STATE_COUNTER = STATE_COUNTER + 1;
          
        %%
        %% Filter out Horizo based on Focus Mask %
        filter_And_Focus(); 
        
        %%
        %% Find Lane Candidatae in the ROI %%
        msg = find_Lane_Candidates( nimage );
        

        %%
        %% Update Vanishing Point %%
        find_Vanashing_Point();
        
        
        %%
        %% Update the center lane %%
        find_Center_Lane();
        
                    
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
            
  



