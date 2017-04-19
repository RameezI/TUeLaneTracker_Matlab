%%
%% state function
%%
function [msg, Templates, Likelihoods, Masks] = run_Filling_Buffers_State(N_IMAGE, NBUFFER, VanishingPt, Templates, Likelihoods, Mask)


global STATE_READY STATE_BUSY STATE_COUNTER   

msg = STATE_BUSY;

  
%% Add Image Buffer %% 
    
   RGB = readImage( N_IMAGE );
   
   [Templates, Likelihoods, Masks] = add_Image_To_Buffer(RGB, VanishingPt, Templates, Likelihoods, Mask);
                     
   if  NBUFFER <= STATE_COUNTER
        msg = STATE_READY;
   else
        msg = STATE_BUSY;
   end
    
end
            