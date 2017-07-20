
function [] = showResultsSimple( RGB, VanishingPt, message )             
        
 
%% Required globals
   
    global   C_V C_H  RES_VH DETECTING_EGO_LANE CURRENT_STATE LANE_BOUNDARIES 

    global   BASE_HISTOGRAM_BINS HORIZON_HISTOGRAM_BINS INT_HIST_LANE_PROB INT_HIST_VP_PROB 
    
    clr = 'g';


%% Show Image

    figure(10);
    clf
    
    imshow(RGB)     
    
  %  axis([BASE_HISTOGRAM_BINS(1)+320 BASE_HISTOGRAM_BINS(end)+320 0 480] )
    hold on

    
    %% Transforming Back to Image Coordinates
    VP_VH    = [VanishingPt.V+C_V, C_H+VanishingPt.H];
    
    
        
    for nl = 1:size(LANE_BOUNDARIES,2)


        laneLeftEdge    = LANE_BOUNDARIES(1,nl);
        laneRightEdge   = LANE_BOUNDARIES(2,nl);


        leftEdgeStart_VH    = [RES_VH(1) , laneLeftEdge+C_H];        
        rightEdgeStart_VH   = [RES_VH(1),  laneRightEdge+C_H];
        
        slope = (VP_VH(1)-leftEdgeStart_VH(1))/(VP_VH(2)-leftEdgeStart_VH(2));
        
        
        %% Plot Boundary Line 
        
        trimmedVP_VH = leftEdgeStart_VH + [-RES_VH(1)*0.35 -(RES_VH(1)*0.35)/slope];

        plot( [leftEdgeStart_VH(2) trimmedVP_VH(2)], [leftEdgeStart_VH(1) trimmedVP_VH(1)], clr,        'LineWidth', 2 );
        plot( [rightEdgeStart_VH(2)   trimmedVP_VH(2)], [rightEdgeStart_VH(1)   trimmedVP_VH(1)], clr,  'LineWidth', 2  );

            
        %% Plot Center Line %%

        laneCenter = LANE_BOUNDARIES(3,nl);

        laneCenterStart_VH = [RES_VH(1), laneCenter+C_H];

        slope = (VP_VH(1)-laneCenterStart_VH(1))/(VP_VH(2)-laneCenterStart_VH(2));
         
        trimmedVP_VH = laneCenterStart_VH + [-RES_VH(1)*0.35 -(RES_VH(1)*0.35)/slope];

        plot( [laneCenterStart_VH(2) trimmedVP_VH(2)], [laneCenterStart_VH(1) trimmedVP_VH(1)], clr, 'LineWidth', 2 );

        
    end
    

  
    %% Show VP %%

    plot( [1 RES_VH(2)], [VP_VH(1,1) VP_VH(1,1)],'m');
    
    plot( [VP_VH(1,2) VP_VH(1,2)], [1 VP_VH(1,1)],'m');


    

%     %% plot the observation histogram %%
% 
%     if ~isempty(INT_HIST_LANE_PROB) && ~isempty(INT_HIST_VP_PROB)
%         
%         plot( [[320+(BASE_HISTOGRAM_BINS)]; [320+(BASE_HISTOGRAM_BINS)]], [[240+240-(INT_HIST_LANE_PROB*600)]; [240+240-(INT_HIST_LANE_PROB*0)]], ['-',clr] )
%        
%         plot( 320+(BASE_HISTOGRAM_BINS), 240+240-(INT_HIST_LANE_PROB*0), ['x',clr] )  
% 
%         plot( [HORIZON_HISTOGRAM_BINS+320; HORIZON_HISTOGRAM_BINS+320], [[240+120-(INT_HIST_VP_PROB*600)]; 240+120-(INT_HIST_VP_PROB*0)], ['-',clr] )
%         plot( HORIZON_HISTOGRAM_BINS+320, 240+120-(INT_HIST_VP_PROB*0), ['x',clr] )
%    
%     end

    drawnow


    %% Save this Figure %%
    
%    global DisplayNumber;
%    
%    drawnow
%        
%         %pause(1);
%         set(gcf,'units','pixels')
%         set(gcf,'position',[500 500 BASE_HISTOGRAM_BINS(end)-BASE_HISTOGRAM_BINS(1) 480])
%         set(gcf,'PaperPositionMode','auto')
%         SAV = ['/home/rameez/Desktop/result_imgs/',sprintf('%06d',DisplayNumber),'.png'];
%         saveas(gcf,SAV)
%   DisplayNumber = DisplayNumber+1;

end

