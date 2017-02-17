%%
%%
%%
%% non linearly shift image according to turning radius
%%
%%
%%
function [new] = shiftImage( I, depths, radius, horizon, default )

    %% default
    new = zeros( size(I) );
    
    %% the angle of the lane intercpets
    angles  = atand( depths / radius );
    
    %% the offsets wrt VP
    offsets = tand(angles)*depths(1);                                                         
    
    %% for each line under horizon
    for nt = 1:(480-horizon)

       %% off-set for this line
       offset = round(offsets(nt));

       %% positive offset
       if 0 < offset

           %% shift
           if 639 < offset
               offset = 639;
           end
           new( horizon+(nt-1), [1:640-offset] ) = I( horizon+(nt-1), [offset+1:640] );
           if default ~= Inf
               new( horizon+(nt-1), [640-offset:end] ) = default;
           else
               new( horizon+(nt-1), [640-offset:end] ) = new( horizon+(nt-1), 640-offset );
           end
           
       %% negative offset
       else

           %% shift
           if offset < -639 
               offset = -639;
           end
           new( horizon+(nt-1), [-offset+1:end] ) = I( horizon+(nt-1), [1:640+offset] );
           if default ~= Inf
               new( horizon+(nt-1), [1:-offset] ) = default;
           else
               new( horizon+(nt-1), [1:-offset] ) = new( horizon+(nt-1), -offset+1 );
           end
       end
    end
    
end