%%
%% state function
%%
function [msg, Templates, Likelihoods, Masks] = run_Filling_Buffers_State(VanishingPt, Templates, Likelihoods, Masks )



%%%%%%%%%%%%%%%%%%%%%%%%%%
%% all required globals %%
%%%%%%%%%%%%%%%%%%%%%%%%%%    
global STATE_READY STATE_BUSY STATE_COUNTER NBUFFER  N_IMAGE

msg = STATE_BUSY;

while msg ~= STATE_READY  
    

    %%
    %% Add Image Buffer %% 
    RGB = readImage( N_IMAGE );
   
    
    [Templates, Likelihoods, Masks] = add_Image_To_Buffer(RGB, VanishingPt, Templates, Likelihoods, Masks );
     

    showResults( RGB, VanishingPt, msg );

    STATE_COUNTER = STATE_COUNTER + 1;
                
    %%%%%%%%%%%%%%%%%
    %% are we done %%
    %%%%%%%%%%%%%%%%%
    if  NBUFFER <= STATE_COUNTER
        msg = STATE_READY;
    else
        msg = STATE_BUSY;
    end
    
    
    
end
    
end
            