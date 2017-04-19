%%
%% state function
%%
function [msg, Templates, Likelihoods, Masks] = run_Filling_Buffers_State(N_IMAGE, NBUFFER, VanishingPt, Templates, Likelihoods, Mask)


global STATE_READY STATE_BUSY STATE_COUNTER   

msg = STATE_BUSY;


while msg ~= STATE_READY  
    

 
%% Add Image Buffer %% 
    
   RGB = readImage( N_IMAGE );
   
   [Templates, Likelihoods, Masks] = add_Image_To_Buffer(RGB, VanishingPt, Templates, Likelihoods, Mask);
     
   STATE_COUNTER = STATE_COUNTER + 1;
                
    if  NBUFFER <= STATE_COUNTER
        msg = STATE_READY;
    else
        msg = STATE_BUSY;
    end
    
end
    
end
            