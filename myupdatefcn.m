

%%
%% show vector when clicking on gradient image
%%
function txt = myupdatefcn(obj,event_obj,DIR)

    % Customizes text of data tips
    pos   = get(event_obj,'Position');
    angle = DIR( pos(2), pos(1) );
    txt   = [ num2str( angle ) ]; 
    x     =  cosd(angle)*500;
    y     = -sind(angle)*500;
    if 0 <= angle
        quiver( pos(1), pos(2), -x, -y, 'r', 'LineWidth', 2)
        quiver( pos(1), pos(2),  x,  y, 'r', 'LineWidth', 2)
    end
    
end