%%
%% state function
%%
function [msg] = run_Filling_Buffers_State( nimage)



%%%%%%%%%%%%%%%%%%%%%%%%%%
%% all required globals %%
%%%%%%%%%%%%%%%%%%%%%%%%%%    
global STATE_READY STATE_BUSY STATE_COUNTER NBUFFER  N_IMAGE

msg = STATE_BUSY;

while msg ~= STATE_READY  
    

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% add an image to the buffer %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
    RGB = readImage( N_IMAGE );

    
    
    
    added = add_Image_To_Buffer( RGB);
     
    showResults( N_IMAGE, msg );
       
       
    
    if added==1
        STATE_COUNTER = STATE_COUNTER + 1;
    end
                
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
            