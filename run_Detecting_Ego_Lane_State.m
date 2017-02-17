

%%
%% state function
%%
function [msg] = run_Detecting_Ego_Lane_State( nimage )

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%    
    global STATE_READY STATE_BUSY STATE_ERROR STATE_COUNTER
    
    global PROB_KeyFrame
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% add an image to the buffer %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
     RGB = readImage( nimage );
     added = add_Image_To_Buffer( RGB);
    if 1 == added || STATE_COUNTER == 0
        STATE_COUNTER = STATE_COUNTER + 1;
    
        %%%%%%%%%%%%%%%%%
        %% other steps %%
        %%%%%%%%%%%%%%%%%
        filter_And_Focus();
        msg = find_Lane_Candidates( nimage );

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% find a new vanshing point %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        find_Vanashing_Point();
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% update the center lane %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
        find_Center_Lane();
            
        %%%%%%%%%%%%%%
        %% no error %%
        %%%%%%%%%%%%%%
        if msg ~= STATE_ERROR
            
            %%%%%%%%%%%%%%%%
            % are we done %%
            %%%%%%%%%%%%%%%%
            if  2 <= STATE_COUNTER
                msg = STATE_READY;
            else
                msg = STATE_BUSY;
            end

        end
        
    else
        msg = STATE_BUSY;
    end
        
end
            
  



