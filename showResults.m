
%%
%% show results
%% use to get movie: avconv -r 60 -i %06d.png LaneTUE.mp4
function [] = showResults( nimage, message )             
        
    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %% all required globals %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%    
    global LOGO VP_BINS_HST C_V C_H LANE_BINS_H INT_HIST_LANE_PROB INT_HIST_VP_PROB FILLING_BUFFERS STATE_COUNTER RES_VH DETECTING_EGO_LANE TRACKING_EGO_LANE_STABLE TRACKING_EGO_LANE CURRENT_STATE VP_V VP_H GT_VP START_END_FRAMES RGB OLD_VP_V OLD_VP_H MASK_FOC_TOT_P IMAGE_FILES DATASET LANE_BOUNDARIES STATE_ERROR
    
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     %% show estimated curvature %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     SEGMENT = shiftImage( SEGMENT, DEPTH_P, Radius, 240-VP_V, 0 );


%     %%%%%%%%%%%%%%%%%%%%%%%%%%%
%     %% when filter is stable %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%
%     if CURRENT_STATE == TRACKING_EGO_STABLE


%     %%%%%%%%%%%%%%%%%%%%%%%
%     %% compute the error %%
%     %%%%%%%%%%%%%%%%%%%%%%%
%     if nimage == END
%         ERROR = [ERROR [(GT_VP(1) - (320-PRED_VP_H)); (GT_VP(2) - (240-PRED_VP_V)); (GT_VP(1) - (320-UPD_VP_H)); (GT_VP(2) - (240-UPD_VP_V))] ]
%     end


    %%%%%%%%%%%%%%%%%%%
    %% show in image %%
    %%%%%%%%%%%%%%%%%%%
    sfigure(10);
    clf

    %%%%%%%%%%%%%%%%%
    %% when stable %%
    %%%%%%%%%%%%%%%%%
%     if CURRENT_STATE == DETECTING_EGO_LANE || CURRENT_STATE == TRACKING_EGO_LANE || CURRENT_STATE == TRACKING_EGO_LANE_STABLE
%        
%         %%%%%%%%%%%%%%%%%%%%%%%%%%%
%         %% show lanes over image %%
%         %%%%%%%%%%%%%%%%%%%%%%%%%%%
%         SEGMENT_RGB = ones( RES_VH(1), RES_VH(2), 3);
%         if CURRENT_STATE == DETECTING_EGO_LANE
%             SEGMENT_RGB(:,:,1) = SEGMENT_RGB(:,:,1) .* (1 * SEGMENT);
%             SEGMENT_RGB(:,:,2) = SEGMENT_RGB(:,:,2) .* (0 * SEGMENT);
%             SEGMENT_RGB(:,:,3) = SEGMENT_RGB(:,:,3) .* (0 * SEGMENT);
%         elseif CURRENT_STATE == TRACKING_EGO_LANE
%             SEGMENT_RGB(:,:,1) = SEGMENT_RGB(:,:,1) .* (0 * SEGMENT);
%             SEGMENT_RGB(:,:,2) = SEGMENT_RGB(:,:,2) .* (0 * SEGMENT);
%             SEGMENT_RGB(:,:,3) = SEGMENT_RGB(:,:,3) .* (1 * SEGMENT);                   
%         elseif CURRENT_STATE == TRACKING_EGO_LANE_STABLE
%             SEGMENT_RGB(:,:,1) = SEGMENT_RGB(:,:,1) .* (0 * SEGMENT);
%             SEGMENT_RGB(:,:,2) = SEGMENT_RGB(:,:,2) .* (1 * SEGMENT);
%             SEGMENT_RGB(:,:,3) = SEGMENT_RGB(:,:,3) .* (0 * SEGMENT);                            
%         end
%         mask = 0 < SEGMENT;
%         R  = RGB(:,:,1);
%         G  = RGB(:,:,2);
%         B  = RGB(:,:,3);
%         SR = SEGMENT_RGB(:,:,1);
%         SG = SEGMENT_RGB(:,:,2);
%         SB = SEGMENT_RGB(:,:,3);                    
%         R(mask) = 0.6*R(mask)+0.4*SR(mask);
%         G(mask) = 0.6*G(mask)+0.4*SG(mask);
%         B(mask) = 0.6*B(mask)+0.4*SB(mask);                    
%         RGB(:,:,1) = R;
%         RGB(:,:,2) = G;
%         RGB(:,:,3) = B;
%     end
    
    %%%%%%%%%%%%%%%%%%%%    
    %% show the image %%
    %%%%%%%%%%%%%%%%%%%%
    RGB(1:75,end-74:end,:) = LOGO;
    imshow(RGB)
    axis([LANE_BINS_H(1)+320 LANE_BINS_H(end)+320 0 480] )
    hold on

    %%%%%%%%%%%%%%%%%%%%%
    %% print the state %%
    %%%%%%%%%%%%%%%%%%%%%
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
        text( 50, 100, ['VP ',num2str(VP_V),',',num2str(VP_H),' L ',num2str((LANE_BOUNDARIES(1,1)+LANE_BOUNDARIES(2,1))/2),',',num2str((LANE_BOUNDARIES(1,2)+LANE_BOUNDARIES(2,2))/2),' S ',num2str(round(LANE_BOUNDARIES(5,1))),',',num2str(round(LANE_BOUNDARIES(5,2)))], 'FontSize', 18, 'BackgroundColor', 'w'  )
    end
    
    

    %%%%%%%%%%%%%%%%%
    %% when stable %%
    %%%%%%%%%%%%%%%%%
    if CURRENT_STATE == DETECTING_EGO_LANE
        
        for nl = 1:size(LANE_BOUNDARIES,2)

           %%%%%%%%%%%%%%%%%%%%%%
           %% the lane marking %%
           %%%%%%%%%%%%%%%%%%%%%%
           lane_start = LANE_BOUNDARIES(1,nl);
           lane_end   = LANE_BOUNDARIES(2,nl);

           VP_HV    = [VP_H+C_H, C_V+VP_V];
           START_HV = [lane_start+C_H, RES_VH(1)];
           END_HV   = [lane_end+C_H, RES_VH(1)];
           
           START_SLOPE = (VP_HV(2)-START_HV(2))/(VP_HV(1)-START_HV(1));
           VP_START_HV = START_HV + [ -(RES_VH(1)*0.35)/START_SLOPE -RES_VH(1)*0.35 ];
                      
           plot( [START_HV(1) VP_START_HV(1)], [START_HV(2) VP_START_HV(2)], clr, 'LineWidth', 2 );
           plot( [END_HV(1)   VP_START_HV(1)], [END_HV(2)   VP_START_HV(2)], clr, 'LineWidth', 2  );

           %%%%%%%%%%%%%%%%%%%%%
           %% the center lane %%
           %%%%%%%%%%%%%%%%%%%%%
           lane_start = LANE_BOUNDARIES(3,nl);

           VP_HV    = [VP_H+C_H, C_V+VP_V];
           START_HV = [lane_start+C_H, RES_VH(1)];
           
           START_SLOPE = (VP_HV(2)-START_HV(2))/(VP_HV(1)-START_HV(1));
           VP_START_HV = START_HV + [ -(RES_VH(1)*0.35)/START_SLOPE -RES_VH(1)*0.35 ];
                      
           plot( [START_HV(1) VP_START_HV(1)], [START_HV(2) VP_START_HV(2)], clr, 'LineWidth', 2 );

        end
    end
    
    
%     %%%%%%%%%%%%%%%%%
%     %% show old VP %%
%     %%%%%%%%%%%%%%%%%    
%     plot( [1 RES_VH(2)], [C_V+OLD_VP_V C_V+OLD_VP_V],'r');
%     plot( [C_H+OLD_VP_H C_H+OLD_VP_H], [1 C_V+OLD_VP_V],'r');  
    
    
    %%%%%%%%%%%%%%%%%
    %% show new VP %%
    %%%%%%%%%%%%%%%%%
    plot( [1 RES_VH(2)], [C_V+VP_V C_V+VP_V],'m');
    plot( [C_H+VP_H C_H+VP_H], [1 C_V+VP_V],'m');

    
    
    
     %% Commented out by Rameez, No labels available
    %labelFiles = dir([DATASET,'/labels/training/*.txt']);
    %Number_Of_Labels = size(labelFiles,1)
    %
    

    %%%%%%%%%%%%%%%%
    %% show GT VP %%
    %%%%%%%%%%%%%%%%
    %if nimage == START_END_FRAMES(2)
    %    plot( [GT_VP(1)-50 GT_VP(1)+50], [GT_VP(2) GT_VP(2)], 'g' );
    %    plot( [GT_VP(1) GT_VP(1)], [GT_VP(2)-50 GT_VP(2)+50], 'g' );
    % else
    %    plot( [C_H-50 C_H+50], [C_V C_V], 'y' );
    %    plot( [C_H C_H], [C_V-50 C_V+50], 'y' );
    % end
    
    %%}
    

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% plot the observation histogram %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if ~isempty(INT_HIST_LANE_PROB) && ~isempty(INT_HIST_VP_PROB)
        plot( [[320+(LANE_BINS_H)]; [320+(LANE_BINS_H)]], [[240+240-(INT_HIST_LANE_PROB*600)]; [240+240-(INT_HIST_LANE_PROB*0)]], ['-',clr] )
        plot( 320+(LANE_BINS_H), 240+240-(INT_HIST_LANE_PROB*0), ['x',clr] )  
        
        plot( [VP_BINS_HST+320; VP_BINS_HST+320], [[240+120-(INT_HIST_VP_PROB*600)]; 240+120-(INT_HIST_VP_PROB*0)], ['-',clr] )
        plot( VP_BINS_HST+320, 240+120-(INT_HIST_VP_PROB*0), ['x',clr] )
    end
    
    
    
    %%%%%%%%%%%%%%%%%%%%%%
    %% save this figure %%
    %%%%%%%%%%%%%%%%%%%%%%
    drawnow
    set(gcf,'units','pixels')
    set(gcf,'position',[500 500 LANE_BINS_H(end)-LANE_BINS_H(1) 480])
    set(gcf,'PaperPositionMode','auto')
    SAV = [DATASET,'/result_imgs/',sprintf('%06d',nimage-START_END_FRAMES(1)-1),'.png'];
%     SAV = ['tempa.png'];
    saveas(gcf,SAV)
%     print(SAV,'-dpng');


%     %%%%%%%%%%%%%%%%%%%%%%%%%%%
%     %% show tracked prob map %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%
%     sfigure(11);
%     clf  
% %     imshow( FOC_TOT_P.*MASK_FOC_TOT_P, [0 max(FOC_TOT_P(:),[],1)] )
%     imshow( MASK_FOC_TOT_P ) 
% %     colormap jet
%     hold on
%     
%     %%%%%%%%%%%%%%%%%
%     %% when stable %%
%     %%%%%%%%%%%%%%%%%
%     if CURRENT_STATE == DETECTING_EGO_LANE || CURRENT_STATE == TRACKING_EGO_LANE || CURRENT_STATE == TRACKING_EGO_LANE_STABLE
%         
%         color = ['g' 'g' 'g' 'g' 'g' 'g'];
%         clr   = 1;
%         for nl = 1:size(LANE_BOUNDARIES,2)
% 
%            lane_start = LANE_BOUNDARIES(1,nl);
%            lane_end   = LANE_BOUNDARIES(2,nl);
% 
%            plot( [VP_H lane_start]+C_H, [C_V+VP_V RES_VH(1)], color(clr) );
%            plot( [VP_H lane_end]+C_H,   [C_V+VP_V RES_VH(1)], color(clr) );
% 
%            clr = clr + 1;
%            if 6 < clr
%               clr = 1; 
%            end
% 
%         end
%     end
%     
%     
%     %%%%%%%%%%%%%%%%%
%     %% show old VP %%
%     %%%%%%%%%%%%%%%%%    
%     plot( [1 RES_VH(2)], [C_V+OLD_VP_V C_V+OLD_VP_V],'r');
%     plot( [C_H+OLD_VP_H C_H+OLD_VP_H], [1 C_V+OLD_VP_V],'r');  
%     
%     
%     %%%%%%%%%%%%%%%%%
%     %% show new VP %%
%     %%%%%%%%%%%%%%%%%
%     plot( [1 RES_VH(2)], [C_V+VP_V C_V+VP_V],'--m');
%     plot( [C_H+VP_H C_H+VP_H], [1 C_V+VP_V],'--m');
%     
%     %%%%%%%%%%%%%%%%
%     %% show GT VP %%
%     %%%%%%%%%%%%%%%%
%     if nimage == START_END_FRAMES(2)
%         plot( [GT_VP(1)-50 GT_VP(1)+50], [GT_VP(2) GT_VP(2)], 'g' );
%         plot( [GT_VP(1) GT_VP(1)], [GT_VP(2)-50 GT_VP(2)+50], 'g' );
%     else
%         plot( [C_H-50 C_H+50], [C_V C_V], 'y' );
%         plot( [C_H C_H], [C_V-50 C_V+50], 'y' );
%     end    
%     
%     
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     %% plot the observation histogram %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     if ~isempty(INT_HIST_LANE_PROB) && ~isempty(INT_HIST_VP_PROB)
%         plot( [[320+(LANE_BINS_H)]; [320+(LANE_BINS_H)]], [[240+240-(INT_HIST_LANE_PROB*600)]; [240+240-(INT_HIST_LANE_PROB*0)]], '-g' )
%         plot( 320+(LANE_BINS_H), 240+240-(INT_HIST_LANE_PROB*0), 'xg' )  
%         
%         plot( [VP_BINS_HST+320; VP_BINS_HST+320], [[240+120-(INT_HIST_VP_PROB*600)]; 240+120-(INT_HIST_VP_PROB*0)], '-g' )
%         plot( VP_BINS_HST+320, 240+120-(INT_HIST_VP_PROB*0), 'xg' )
%     end
%     
%     
%     %%%%%%%%%%%%%%%%%%%%%%
%     %% save this figure %%
%     %%%%%%%%%%%%%%%%%%%%%%
%     drawnow
%     set(gca,'position',[0 0 1 1],'units','pixels')
%     SAV = ['tempb.png'];
%     saveas(gcf,SAV)


%     %%%%%%%%%%%%%%%%%%%%%%%%%%
%     %% combine in one image %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%
%     A = imread('tempa.png');
%     B = imread('tempb.png');
%     C = [A B];                        
%     SAV = [DATASET,'/result_imgs/',sprintf('%06d',nimage-START_END_FRAMES(1)-1),'.png'];
%     imwrite( A, SAV );    

    
%     %%%%%%%%%%%%%%%%%%%%%%%%%
%     %% draw the edge image %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%
%     fig = sfigure(12);    
%     clf
%     TEMP = -1*ones(RES_VH(1),RES_VH(2));
%     TEMP( IDX_LANE_PIX ) = AVG_DIR_TOT_P( IDX_LANE_PIX );
%     imshow(TEMP,[0 180])
%     colormap gray
%     hold on
%     
%     %%%%%%%%%%%%%%%%%
%     %% when stable %%
%     %%%%%%%%%%%%%%%%%
%     if CURRENT_STATE == DETECTING_EGO_LANE || CURRENT_STATE == TRACKING_EGO_LANE || CURRENT_STATE == TRACKING_EGO_LANE_STABLE
%         
%         color = ['g' 'g' 'g' 'g' 'g' 'g'];
%         clr   = 1;
%         for nl = 1:size(LANE_BOUNDARIES,2)
% 
%            lane_start = LANE_BOUNDARIES(1,nl);
%            lane_end   = LANE_BOUNDARIES(2,nl);
% 
%            plot( [VP_H lane_start]+C_H, [C_V+VP_V RES_VH(1)], color(clr) );
%            plot( [VP_H lane_end]+C_H,   [C_V+VP_V RES_VH(1)], color(clr) );
% 
%            clr = clr + 1;
%            if 6 < clr
%               clr = 1; 
%            end
% 
%         end
%     end
%     
%     
%     %%%%%%%%%%%%%%%%%
%     %% show old VP %%
%     %%%%%%%%%%%%%%%%%    
%     plot( [1 RES_VH(2)], [C_V+OLD_VP_V C_V+OLD_VP_V],'r');
%     plot( [C_H+OLD_VP_H C_H+OLD_VP_H], [1 C_V+OLD_VP_V],'r');  
%     
%     
%     %%%%%%%%%%%%%%%%%
%     %% show new VP %%
%     %%%%%%%%%%%%%%%%%
%     plot( [1 RES_VH(2)], [C_V+VP_V C_V+VP_V],'--m');
%     plot( [C_H+VP_H C_H+VP_H], [1 C_V+VP_V],'--m');
% 
% 
%     %%%%%%%%%%%%%%%%
%     %% show GT VP %%
%     %%%%%%%%%%%%%%%%
%     if nimage == START_END_FRAMES(2)
%         plot( [GT_VP(1)-50 GT_VP(1)+50], [GT_VP(2) GT_VP(2)], 'g' );
%         plot( [GT_VP(1) GT_VP(1)], [GT_VP(2)-50 GT_VP(2)+50], 'g' );
%     else
%         plot( [C_H-50 C_H+50], [C_V C_V], 'y' );
%         plot( [C_H C_H], [C_V-50 C_V+50], 'y' );
%     end
%  
%     
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     %% set the custom data cursor %%
%     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     dcm_obj = datacursormode(fig);
%     set(dcm_obj,'UpdateFcn',{@myupdatefcn,TEMP})
% 
%     %%%%%%%%%%%%%%%%%%%%%%
%     %% drae this figure %%
%     %%%%%%%%%%%%%%%%%%%%%%
%     axis([1 RES_VH(2) 1 RES_VH(1)]);
%     axis tight
%     drawnow
%        
%         %%%%%%%%%%%%%%%%%%%%
%         %% plot the error %%
%         %%%%%%%%%%%%%%%%%%%%
%         sfigure(444);
%         clf
%         hold on
%         mx = max( abs(ERROR(:)), [], 1)+1;
%         
%         plot( ERROR(1,:), ERROR(2,:), 'xr' )
%         for nt = 1:size(ERROR,2)
%             text(ERROR(1,nt),ERROR(2,nt),num2str(nt))
%         end
%         
%         plot( ERROR(3,:), ERROR(4,:), 'om' )
%         for nt = 1:size(ERROR,2)
%             text(ERROR(3,nt),ERROR(4,nt),num2str(nt))
%         end
%         
%         axis([-mx mx -mx mx]);
%         grid on
%         axis equal
%         
%         
%         
%         %%%%%%%%%%%%%%%%
%         %% some stats %%
%         %%%%%%%%%%%%%%%%  
%         MEAN   = mean( ERROR, 2 )
%         MEDIAN = median( ERROR, 2 )
%         
%         
%         
%         %%%%%%%%%%%%%%%%
%         %% wait a sec %%
%         %%%%%%%%%%%%%%%%
%         drawnow
%         pause(0.1)
% %         pause
%         
%         
%     end
%     
%                       
%     end

end

