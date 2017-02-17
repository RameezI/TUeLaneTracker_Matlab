function [likelihoods, templates, vanishingPt, masks] = run_Init_State(RES_VH, NBUFFER, laneFilter, vpFilter)
    


  
  %coder.cstructname(laneFilter, 'MatlabStruct_laneFilter');
  %coder.cstructname(vpFilter, 'MatlabStruct_vpFilter');
        
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% (re)start the filters %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
   laneFilter.mFilter = laneFilter.mPrior;
   vpFilter.mFilter    = vpFilter.mPrior;
    
    
    TOT_P_ALL           = zeros( RES_VH(1), RES_VH(2), NBUFFER);
    DIR_ALL             = zeros( RES_VH(1), RES_VH(2), NBUFFER);
    TOT_P_ALL_BACK_UP   = zeros( RES_VH(1), RES_VH(2), NBUFFER);
    DIR_ALL_BACK_UP     = zeros( RES_VH(1), RES_VH(2), NBUFFER);
    MASK_FOC_TOT_P      = ones(  RES_VH(1), RES_VH(2));
    FOC_TOT_P           = zeros( RES_VH(1), RES_VH(2));
    TOT_P               = zeros( RES_VH(1), RES_VH(2));
    AVG_DIR_TOT_P       = zeros( RES_VH(1), RES_VH(2));
%    IDX_LANE_PIX   = [];
    
    




%% 
%% Create Segment Mask %%
% % 
% %     SEGMENT            = zeros( RES_VH(1),RES_VH(2));
% %     SEGMENT_TIGHT      = zeros( RES_VH(1),RES_VH(2) );
% %     SEGMENT_VERY_TIGHT = zeros( RES_VH(1),RES_VH(2) );
% %     SEGMENT_WIDE       = zeros( RES_VH(1),RES_VH(2) );
    
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% create the gradient template %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    RES_VH              = single(RES_VH);
    ROOT_DIR_TEMPLATE   = createTemplate(RES_VH(1),RES_VH(2));
    
    
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% create the Focus template               %%
    %% masks out parts above horizon + margin %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    Margin                  = 100; %% Note: Should be fitted using sweeps
    ROOT_FOCUS_TEMPLATE     = zeros(2*RES_VH(1)+1,RES_VH(2));

    ROOT_FOCUS_TEMPLATE(RES_VH(1)+Margin:end,:) = 1;
        
    for n = 481:RES_VH(1)+Margin
      ROOT_FOCUS_TEMPLATE(n,:) = ((n-RES_VH(1))/Margin)^3;
    end
   
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% create the depth template              %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    ROOT_IDEPTH_TEMPLATE = zeros(2*RES_VH(1)+1,RES_VH(2));
    step  = 45/RES_VH(1);
    angle = 90-step;
    for n = RES_VH(1)+1:2*RES_VH(1)+1
        ROOT_IDEPTH_TEMPLATE(n,:) = 1.75*tand(angle);
        angle                     = angle-step;
    end
    ROOT_IDEPTH_TEMPLATE( 100 < ROOT_IDEPTH_TEMPLATE ) = 100;
    
%     figure(234)
%     imshow(ROOT_IDEPTH_TEMPLATE,[0 100])
%     colormap jet
%     drawnow
%     pause
    
    

    %%%%%%%%%%%%%%%%%%%%%%%%
    %% this state is done %%
    %%%%%%%%%%%%%%%%%%%%%%%%
    
                      
                     templates = struct;
                          templates.GRADIENT_DIR_ROOT  = ROOT_DIR_TEMPLATE;
                          templates.FOCUS_ROOT         = ROOT_FOCUS_TEMPLATE;
                          templates.DEPTH_ROOT         = ROOT_IDEPTH_TEMPLATE;
                      
                     
                     vanishingPt = struct;
                         vanishingPt.V = 0;
                         vanishingPt.H = 0;
                         vanishingPt.V_prev = 0;
                         vanishingPt.H_prev = 0;

                         
                         

                    likelihoods =struct;
                          likelihoods.TOT_ALL                       = TOT_P_ALL;
                          likelihoods.TOT_MAX                       = TOT_P;
                          
                          likelihoods.GRADIENT_DIR_ALL              = DIR_ALL;
                          likelihoods.GRADIENT_DIR_AVG              = AVG_DIR_TOT_P;
                          
                          likelihoods.TOT_ALL_BACK_UP              = TOT_P_ALL_BACK_UP;
                          likelihoods.GRADIENT_DIR_ALL_BACK_UP     = DIR_ALL_BACK_UP;
                          
                          likelihoods.TOT_FOCUSED                  = FOC_TOT_P;

                          
                            masks =struct;
                            masks.FOCUS                             = MASK_FOC_TOT_P;
                        

                        
%%Redifinition in createEGOLaneMask()                        
% %                        segmentMask =struct;     
% %                         SEGMENT            = zeros( 480, 640 );
% %                         SEGMENT_TIGHT      = zeros( 480, 640 );
% %                         SEGMENT_VERY_TIGHT = zeros( 480, 640 );
% %                         SEGMENT_WIDE       = zeros( 480, 640 );    
% %                         






%% Verification Functions

    %VerifyLikelihoods(likelihoods);




                        
                          
    coder.cstructname(templates, 'MatlabStruct_templates');
    coder.cstructname(vanishingPt, 'MatlabStruct_vanishingPt');
    coder.cstructname(likelihoods, 'MatlabStruct_likelihoods');
    coder.cstructname(masks, 'MatlabStruct_focusMask');
    
end