function [likelihoods, templates, vanishingPt, masks] = run_Init_State(RES_VH, NBUFFER, VP_RANGE_V)
    

    Margin = 80; %% Note: Should be fitted using sweeps
    span   = floor(RES_VH(1)/2)-Margin + VP_RANGE_V; %best activation of pixels i.e. VP= -25


    TOT_P_ALL           = uint8(zeros( span, RES_VH(2), NBUFFER));
    DIR_ALL             = int16(zeros( span, RES_VH(2), NBUFFER));   
    MASK_FOC_TOT_P      = uint8(zeros( span, RES_VH(2)));
    FOC_TOT_P           = uint8(zeros( span, RES_VH(2)));
                        
    
    TOT_P               = uint8(zeros( span, RES_VH(2)));
    AVG_DIR_TOT_P       = int16(zeros( span, RES_VH(2)));


    
    %%
    %% Create Gradient Direction Template %%
    RES_VH              = single(RES_VH);
    ROOT_DIR_TEMPLATE   = single(createTemplate(RES_VH(1),RES_VH(2)));  %%^TODO: Verify this on C side
    ROOT_DIR_TEMPLATE   = tan(ROOT_DIR_TEMPLATE);
    
    ROOT_DIR_TEMPLATE(ROOT_DIR_TEMPLATE>256)= 255;
    ROOT_DIR_TEMPLATE(ROOT_DIR_TEMPLATE<-256)= -255;
    ROOT_DIR_TEMPLATE = ROOT_DIR_TEMPLATE *2^7;
    ROOT_DIR_TEMPLATE = int16(ROOT_DIR_TEMPLATE);
    
    
%       figure(100)
%       imshow(ROOT_DIR_TEMPLATE,[0 pi])
%       colormap jet
%       pause
    
    
    %%
    %% Create Focus Template %%
    %%Masks out parts above horizon + margin%%    
        ROOT_FOCUS_TEMPLATE     = single(zeros(span + 2*VP_RANGE_V, RES_VH(2)));
        ROOT_FOCUS_TEMPLATE(2*VP_RANGE_V +1:end,:) = 255;        
        ROOT_FOCUS_TEMPLATE = uint8(ROOT_FOCUS_TEMPLATE);
        
   
    %%
    %% Create Depth Template %%

       ROOT_IDEPTH_TEMPLATE = single(zeros(2*RES_VH(1)+1,RES_VH(2)));
        step  = 45/RES_VH(1);
        angle = 90-step;
        for n = RES_VH(1)+1:2*RES_VH(1)+1
            x=  1.75*tand(angle);
            if x > 100
                x=100;
            end
            ROOT_IDEPTH_TEMPLATE(n,:) =x;
            
            angle = angle-step;
        end
        
        ROOT_IDEPTH_TEMPLATE = int16(ROOT_IDEPTH_TEMPLATE);

         
         
    %%  
    %% Assign Matrices to corresponding structures %%


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

                              likelihoods.TOT_ALL                      = TOT_P_ALL;
                              likelihoods.GRADIENT_DIR_ALL             = DIR_ALL;
                              likelihoods.TOT_MAX                      = TOT_P;
                              likelihoods.GRADIENT_DIR_TOT_MAX         = AVG_DIR_TOT_P;
                              likelihoods.TOT_MAX_FOCUSED              = FOC_TOT_P;


                            masks =struct;
                            masks.FOCUS                             = MASK_FOC_TOT_P;
                            masks.Margin                            = Margin;
                            masks.VP_RANGE_V                        = VP_RANGE_V;

                                
                                
    %%                                                  
        coder.cstructname(templates, 'MatlabStruct_templates');
        coder.cstructname(vanishingPt, 'MatlabStruct_vanishingPt');
        coder.cstructname(likelihoods, 'MatlabStruct_likelihoods');
        coder.cstructname(masks, 'MatlabStruct_focusMask');
        
end