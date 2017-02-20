
%%
%% show results
%% use to get movie: avconv -r 60 -i %06d.png LaneTUE.mp4
function [] = showResults( RGB, VanishingPt, message )             
        
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%    
    global DATASET START_END_FRAMES N_IMAGE LOGO VP_BINS_HST C_V C_H LANE_BINS_H INT_HIST_LANE_PROB INT_HIST_VP_PROB FILLING_BUFFERS STATE_COUNTER RES_VH DETECTING_EGO_LANE TRACKING_EGO_LANE_STABLE TRACKING_EGO_LANE CURRENT_STATE LANE_BOUNDARIES STATE_ERROR
    

    %%%%%%%%%%%%%%%%%%%
    %% show in image %%
    %%%%%%%%%%%%%%%%%%%
    sfigure(10);
    clf
    
    %%   
    %% show the image 
    
    RGB(1:75,end-74:end,:) = LOGO;
    imshow(RGB)
    axis([LANE_BINS_H(1)+320 LANE_BINS_H(end)+320 0 480] )
    hold on

    %%
    %% Print the State 
    
    clr = 'r';
    if CURRENT_STATE == FILLING_BUFFERS
        txt = ['FILLING BUFFERS ',num2str(STATE_COUNTER)];
    elseif CURRENT_STATE == DETECTING_EGO_LANE
        txt = ['DETECTING EGO LANE ',num2str(STATE_COUNTER)];
        if 1 < STATE_COUNTER && message ~= STATE_ERROR
            clr = 'g';
        end      
    elseif CURRENT_STATE == TRACKING_EGO_LANE
        txt = ['TRACKING EGO LANE ',num2str(STATE_COUNTER)];
    elseif CURRENT_STATE == TRACKING_EGO_LANE_STABLE
        txt = ['TRACKING EGO LANE STABLE ',num2str(STATE_COUNTER)];
    end
    text( 50, 50, txt, 'FontSize', 18, 'BackgroundColor', 'w' )
    if CURRENT_STATE == DETECTING_EGO_LANE
        text( 50, 100, ['VP ',num2str(VanishingPt.V),',',num2str(VanishingPt.H),' L ',num2str((LANE_BOUNDARIES(1,1)+LANE_BOUNDARIES(2,1))/2),',',num2str((LANE_BOUNDARIES(1,2)+LANE_BOUNDARIES(2,2))/2),' S ',num2str(round(LANE_BOUNDARIES(5,1))),',',num2str(round(LANE_BOUNDARIES(5,2)))], 'FontSize', 18, 'BackgroundColor', 'w'  )
    end
    
    

    %%
    %% When Stable 
    if CURRENT_STATE == DETECTING_EGO_LANE
        
        for nl = 1:size(LANE_BOUNDARIES,2)

            %%
            %% Lane Markings 
            lane_start = LANE_BOUNDARIES(1,nl);
            lane_end   = LANE_BOUNDARIES(2,nl);

            VP_HV    = [VanishingPt.H+C_H, C_V+VanishingPt.V];
            START_HV = [lane_start+C_H, RES_VH(1)];
            END_HV   = [lane_end+C_H, RES_VH(1)];

            START_SLOPE = (VP_HV(2)-START_HV(2))/(VP_HV(1)-START_HV(1));
            VP_START_HV = START_HV + [ -(RES_VH(1)*0.35)/START_SLOPE -RES_VH(1)*0.35 ];

            plot( [START_HV(1) VP_START_HV(1)], [START_HV(2) VP_START_HV(2)], clr, 'LineWidth', 2 );
            plot( [END_HV(1)   VP_START_HV(1)], [END_HV(2)   VP_START_HV(2)], clr, 'LineWidth', 2  );

            %%
            %% The Center Lane %%

            lane_start = LANE_BOUNDARIES(3,nl);

            VP_HV    = [VanishingPt.H+C_H, C_V+VanishingPt.V];
            START_HV = [lane_start+C_H, RES_VH(1)];

            START_SLOPE = (VP_HV(2)-START_HV(2))/(VP_HV(1)-START_HV(1));
            VP_START_HV = START_HV + [ -(RES_VH(1)*0.35)/START_SLOPE -RES_VH(1)*0.35 ];

            plot( [START_HV(1) VP_START_HV(1)], [START_HV(2) VP_START_HV(2)], clr, 'LineWidth', 2 );

        end
    end
    
%     
%     %%
%     %% show old VP %%
%   
%     plot( [1 RES_VH(2)], [C_V+OLD_VP_V C_V+OLD_VP_V],'r');
%     plot( [C_H+OLD_VP_H C_H+OLD_VP_H], [1 C_V+OLD_VP_V],'r');  


    %%
    %% show new VP %%

    plot( [1 RES_VH(2)], [C_V+VanishingPt.V C_V+VanishingPt.V],'m');
    plot( [C_H+VanishingPt.H C_H+VanishingPt.H], [1 C_V+VanishingPt.V],'m');



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

        drawnow
        set(gcf,'units','pixels')
        set(gcf,'position',[500 500 LANE_BINS_H(end)-LANE_BINS_H(1) 480])
        set(gcf,'PaperPositionMode','auto')
        SAV = [DATASET,'/result_imgs/',sprintf('%06d',N_IMAGE-START_END_FRAMES(1)-1),'.png'];
        saveas(gcf,SAV)


end

