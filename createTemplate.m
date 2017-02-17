%%
%%
%%
%% create edge template
%%
%%
%%
function [TEMPLATE] = createTemplate( H ,W )

    %% empty template
    TEMPLATE = -180 * ones( 2*H+1, 2*W+1 );
    pix      = [-2*W:2*W;zeros(1,4*W+1)];
    
    %% left border
    for h = H+1:2*H+1

        %% angle
        an = atan( (h-(H+1)) / W );

        %% draw in template
        cs     = cos(-an); 
        sn     = sin(-an);
        rot    = [cs -sn; sn cs];
        pixrot = rot*pix;
        pixrot(1,:) = pixrot(1,:) + W+1;
        pixrot(2,:) = pixrot(2,:) + H+1;             
        pixrot      = pixrot(:, (1 <= pixrot(1,:)) & (pixrot(1,:) <= 2*W+1) & (1 <= pixrot(2,:)) & (pixrot(2,:) <= 2*H+1) );
        pixrot      = round(pixrot);
        
        %% get indices of the vanashing line
        index = sub2ind([2*H+1, 2*W+1], pixrot(2,:), pixrot(1,:) );

        %% draw
        TEMPLATE(index) = rad2deg(an);          
    end
   
    %% bottom border left part
    for w = W:-1:0
       
        %% angle
        an = pi/2-atan( w / H );
        
        %% draw in template
        cs     = cos(-an); 
        sn     = sin(-an);
        rot    = [cs -sn; sn cs];
        pixrot = rot*pix;
        pixrot(1,:) = pixrot(1,:) + W+1;
        pixrot(2,:) = pixrot(2,:) + H+1;             
        pixrot      = pixrot(:, (1 <= pixrot(1,:)) & (pixrot(1,:) <= 2*W+1) & (1 <= pixrot(2,:)) & (pixrot(2,:) <= 2*H+1) );
        pixrot      = round(pixrot);
        
        %% get indices of the vanashing line
        index = sub2ind([2*H+1, 2*W+1], pixrot(2,:), pixrot(1,:) );

        %% draw
        TEMPLATE(index) = rad2deg(an);         
    end

    %% bottom border rithg part
    for w = W:-1:0
       
        %% angle
        an = pi/2+atan( w / H );
        
        %% draw in template
        cs     = cos(-an); 
        sn     = sin(-an);
        rot    = [cs -sn; sn cs];
        pixrot = rot*pix;
        pixrot(1,:) = pixrot(1,:) + W+1;
        pixrot(2,:) = pixrot(2,:) + H+1;             
        pixrot      = pixrot(:, (1 <= pixrot(1,:)) & (pixrot(1,:) <= 2*W+1) & (1 <= pixrot(2,:)) & (pixrot(2,:) <= 2*H+1) );
        pixrot      = round(pixrot);
        
        %% get indices of the vanashing line
        index = sub2ind([2*H+1, 2*W+1], pixrot(2,:), pixrot(1,:) );

        %% draw
        TEMPLATE(index) = rad2deg(an);         
    end

    %% right border
    pix = [-2*W:2*W;zeros(1,4*W+1)];
    for h = H+1:2*H+1

        %% angle
        an = pi-atan( (h-(H+1)) / W );

        %% draw in template
        cs     = cos(-an); 
        sn     = sin(-an);
        rot    = [cs -sn; sn cs];
        pixrot = rot*pix;
        pixrot(1,:) = pixrot(1,:) + W+1;
        pixrot(2,:) = pixrot(2,:) + H+1;             
        pixrot      = pixrot(:, (1 <= pixrot(1,:)) & (pixrot(1,:) <= 2*W+1) & (1 <= pixrot(2,:)) & (pixrot(2,:) <= 2*H+1) );
        pixrot      = round(pixrot);
        
        %% get indices of the vanashing line
        index = sub2ind([2*H+1, 2*W+1], pixrot(2,:), pixrot(1,:) );     
        
        %% draw
        TEMPLATE(index) = rad2deg(an);          
    end
    
    %% fill in holes
    TEMPLATE = imdilate( TEMPLATE, ones(3,3) );
    TEMPLATE(1:H+2,:) = -180;    
        
end
