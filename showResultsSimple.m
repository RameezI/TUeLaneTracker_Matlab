
%%
%% show results
%% use to get movie: avconv -r 60 -i %06d.png LaneTUE.mp4
function [] = showResultsSimple( RGB, VanishingPt, message )             
        
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%    
    global   C_V C_H  FILLING_BUFFERS STATE_COUNTER RES_VH DETECTING_EGO_LANE CURRENT_STATE LANE_BOUNDARIES STATE_ERROR

    global   LANE_BINS_H VP_BINS_HST INT_HIST_LANE_PROB INT_HIST_VP_PROB 
    

    %%%%%%%%%%%%%%%%%%%
    %% show in image %%
    %%%%%%%%%%%%%%%%%%%
    sfigure(10);
    clf
    
    %%   
    %% show the image 
    imshow(RGB)     
    axis([LANE_BINS_H(1)+320 LANE_BINS_H(end)+320 0 480] )
    hold on

%% Print the State 
    
    clr = 'r';
    if CURRENT_STATE == FILLING_BUFFERS
        txt = ['FILLING BUFFERS ',num2str(STATE_COUNTER)];
    elseif CURRENT_STATE == DETECTING_EGO_LANE
        txt = ['DETECTING EGO LANE ',num2str(STATE_COUNTER)];
        if message ~= STATE_ERROR
            clr = 'g';
        end      
    end
    
    text( 50, 50, txt, 'FontSize', 12, 'BackgroundColor', 'w' )
    
    if CURRENT_STATE == DETECTING_EGO_LANE
        text( 50, 100, ['VP ',num2str(VanishingPt.V),',',num2str(VanishingPt.H),' L ',num2str((LANE_BOUNDARIES(1,1)+LANE_BOUNDARIES(2,1))/2),',',num2str((LANE_BOUNDARIES(1,2)+LANE_BOUNDARIES(2,2))/2),' S ',num2str(round(LANE_BOUNDARIES(5,1))),',',num2str(round(LANE_BOUNDARIES(5,2)))], 'FontSize', 12, 'BackgroundColor', 'w'  )
    end
    
%%  Transforming Back to Image Coordinates
    VP_VH    = [VanishingPt.V+C_V, C_H+VanishingPt.H];
    
    

%% When Detecting Ego Lane

    if CURRENT_STATE == DETECTING_EGO_LANE
        
        for nl = 1:size(LANE_BOUNDARIES,2)

        %Lane Markings 
            laneStart = LANE_BOUNDARIES(1,nl);
            laneEnd   = LANE_BOUNDARIES(2,nl);


            laneStart_VH = [RES_VH(1) , laneStart+C_H];
            laneEnd_VH   = [RES_VH(1),  laneEnd+C_H];

            slope = (VP_VH(1)-laneStart_VH(1))/(VP_VH(2)-laneStart_VH(2));
            trimmedVP_VH = laneStart_VH + [-RES_VH(1)*0.35 -(RES_VH(1)*0.35)/slope];

            plot( [laneStart_VH(2) trimmedVP_VH(2)], [laneStart_VH(1) trimmedVP_VH(1)], clr, 'LineWidth', 2 );
            plot( [laneEnd_VH(2)   trimmedVP_VH(2)], [laneEnd_VH(1)   trimmedVP_VH(1)], clr, 'LineWidth', 2  );

            %%
            %% The Center Lane %%

            laneStart = LANE_BOUNDARIES(3,nl);

            laneStart_VH = [RES_VH(1), laneStart+C_H];

            slope = (VP_VH(1)-laneStart_VH(1))/(VP_VH(2)-laneStart_VH(2));
            trimmedVP_VH = laneStart_VH + [-RES_VH(1)*0.35 -(RES_VH(1)*0.35)/slope];

            plot( [laneStart_VH(2) trimmedVP_VH(2)], [laneStart_VH(1) trimmedVP_VH(1)], clr, 'LineWidth', 2 );

        end
    end
    

    %%
    %% show new VP %%

    plot( [1 RES_VH(2)], [VP_VH(1,1) VP_VH(1,1)],'m');
    plot( [VP_VH(1,2) VP_VH(1,2)], [1 VP_VH(1,1)],'m');



    %%
    %% plot the observation histogram %%

    if ~isempty(INT_HIST_LANE_PROB) && ~isempty(INT_HIST_VP_PROB)
        plot( [[320+(LANE_BINS_H)]; [320+(LANE_BINS_H)]], [[240+240-(INT_HIST_LANE_PROB*600)]; [240+240-(INT_HIST_LANE_PROB*0)]], ['-',clr] )
        plot( 320+(LANE_BINS_H), 240+240-(INT_HIST_LANE_PROB*0), ['x',clr] )  

        plot( [VP_BINS_HST+320; VP_BINS_HST+320], [[240+120-(INT_HIST_VP_PROB*600)]; 240+120-(INT_HIST_VP_PROB*0)], ['-',clr] )
        plot( VP_BINS_HST+320, 240+120-(INT_HIST_VP_PROB*0), ['x',clr] )
    end



     %%
     %% save this figure %%
global DisplayNumber;

        drawnow
        %pause(1);
%         set(gcf,'units','pixels')
%         set(gcf,'position',[500 500 LANE_BINS_H(end)-LANE_BINS_H(1) 480])
%         set(gcf,'PaperPositionMode','auto')
%         SAV = ['/home/rameez/Desktop/result_imgs/',sprintf('%06d',DisplayNumber),'.png'];
%         saveas(gcf,SAV)
DisplayNumber = DisplayNumber+1;

end

