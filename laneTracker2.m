
%% Detect and Track Lanes (Scaled Integers Verision)                                          
% The Ego-lane is parametrized with 
% - The Vanishing Point (VP)
% - The left and right horizontal pixel offsets wrt. the VP at the bottom of the image
%%
%% Information considered by approach
% - Pixel-level: gradient strength and direction, intensity, color
% - Segment-level: accumulated from pixel-level and spatial length of lane boundary
% - Object-level: accumlated from segent-level and inner lane uniformity
% - Scene-level: none but can be extended to eploit lane adjacency and road layouts
%   
%


%% The Image Coordinate System (suffix _VH)
%              O -----> + H (2nd dim)
%              |
%              | 
%              |
%              v + V (1st dim)
% 
%


%% The VP Coordinate System (suffix _VP)
%              ^ + V (2nd dim)
%              |
%              |
%              |   
%              |
%             VP-----> + H (1st dim)



%% The Center Image Coordinate System (suffix _CVH)
%            
%              
%             C --> + H (2nd dim)
%              |
%              |
%              |
%              v + V (1st dim)

    

%%
function [] = laneTracker2()




%% TUe DATASET %%
    global DATASET IMAGE_FILES NBUFFER ImageOutCount STEP_SIZE CENTER_OFFSET
   
    
    DATASET = '/media/rameez/Linux-Extended/DataSet/eindhoven/PNG_imgs/';
    
    DATASET
    
    IMAGE_FILES= dir([DATASET,'*.png']); 
    ImageOutCount =0;
    NBUFFER = 3;  
    STEP_SIZE = 2;
    CENTER_OFFSET = 0.5; %% ?? 
    
    
    
%% System States %%
    
    global INIT_STATE FILLING_BUFFERS DETECTING_EGO_LANE RESET_STATE   
    INIT_STATE               = -1; %% this acts like a #define as in C/C++
    FILLING_BUFFERS          =  1;  %% this acts like a #define as in C/C++
    DETECTING_EGO_LANE       =  2;  %% this acts like a #define as in C/C++
    RESET_STATE              =  3;  %% this acts like a #define as in C/C++
    
    
    
%% State Messages %
    
    global STATE_BUSY STATE_READY STATE_ERROR
    STATE_BUSY  = 0;                %% this acts like a #define as in C/C++
    STATE_READY = 1;                %% this acts like a #define as in C/C++
    STATE_ERROR = 2;                %% this acts like a #define as in C/C++
    
    global STATE_COUNTER
    STATE_COUNTER  = 0;
    
    
    
%% Camera Properties %%

    global CM_TO_PIXEL RES_VH C_V C_H 
    
    RES_VH          = [480 640];         %% resolution of camera
    FOV             = [45 60];           %% field of view of camera
    CAM_HEIGHT      = 1.5;               %% camera height in meters
    CAM_FOCUS       = 6e-3;              %% camera focal length in meters
    
    
    
    
%% Car Properties %%

    global CAR_WIDTH
    CAR_WIDTH = 170; %% cm - average according to Bovag
    
    
    
%% Camera Properties Automatically Computed %%

    H_FOV_V     = FOV(1)/2;     %% half vertical field of view
    H_RES_V     = RES_VH(1)/2;  %% half vertical resolution
    H_FOV_H     = FOV(2)/2;     %% half horizontal field of view
    H_RES_H     = RES_VH(2)/2;  %% half horizontal resolution
    
    
    PX_SIZE     = (tand(H_FOV_V)*CAM_FOCUS)/H_RES_V;                   %% (vertical) size of the pixels
    PX_ANG      = atand( PX_SIZE * [1:(2*H_RES_V)]/CAM_FOCUS );        %% angles of each (virtual) pixel below middle line
    DEPTH_P     = CAM_HEIGHT *tand( 90-PX_ANG );                       %% the depth at each (virtual) pixel below middle line
    
    CM_TO_PIXEL = H_RES_H/(100*tand(H_FOV_H)*DEPTH_P(H_RES_V-1));      %% the horizontal pixel to cm ratio at the bottom line of the image
    C_V         = RES_VH(1)/2;                                         %% verticel image center in image coordinate system
    C_H         = RES_VH(2)/2;                                         %% horizontal image center in image coordinate system

    

%% Lane Properties %%    
    
    global MIN_LANE_WIDTH MAX_LANE_WIDTH AVG_LANE_WIDTH STD_LANE_WIDTH
    AVG_LANE_WIDTH = 300; %% cm
    STD_LANE_WIDTH = 50;  %% cm
    MIN_LANE_WIDTH = 250; %% cm
    MAX_LANE_WIDTH = 500; %% cm
    CM_STEP        = 5;   %% make histogram bins with a width of 5 cm
    


    global tippingPoint_gray tippingPoint_gradMag;
    tippingPoint_gray    = uint8(100);
    tippingPoint_gradMag = uint8(40);
    
    
    
     global LANE_WIDTH_DIFF_NORMA LANE_WIDTH_DIFF_NOMIN
    
    LANE_WIDTH_DIFF_SIGMA = 15; % Lane Width Standard Deviation
    
    LANE_WIDTH_DIFF_NORMA = 1/(sqrt(2*pi*LANE_WIDTH_DIFF_SIGMA^2)); 
    LANE_WIDTH_DIFF_NOMIN = 2*LANE_WIDTH_DIFF_SIGMA^2;
    
    

    global  OBS_NEG_NOMIN OBS_NEG_NORMA
    
    OBS_NEG_SIFMA = 0.2;
    OBS_NEG_NOMIN = 2*OBS_NEG_SIFMA^2;
    OBS_NEG_NORMA = 2/(sqrt(2*pi*OBS_NEG_SIFMA^2)); %% only positive side of x-axis, so half a Gaussian
    
     
    
%% The Lane Filter Expressed in the VP Coordinate System %% 
   

    global  LaneBoundaryModels NegLaneBoundaryModel 
    global  BASE_HISTOGRAM_BINS  LANE_OFFSETS_BINS LANE_PRIOR LANE_TRANSITION LANE_FILTER 
    global  BASE_HISTOGRAM_STEP LANE_CONF_THRESHOLD LANE_FILTER_OFFSET_V
    
    
    % CM_STEP translated to pixels at the bottom line of the Image    
    BASE_HISTOGRAM_STEP           = ceil((CM_STEP*CM_TO_PIXEL)/10)*10;   
    PX_MAX                        = round((MAX_LANE_WIDTH*CM_TO_PIXEL)/BASE_HISTOGRAM_STEP)*BASE_HISTOGRAM_STEP;
    LANE_OFFSETS_BINS             = round([0:BASE_HISTOGRAM_STEP:PX_MAX]);
      
     
    BASE_HISTOGRAM_BINS           = -PX_MAX:BASE_HISTOGRAM_STEP:PX_MAX;    %% Histogram bins for the lane observation model
      
    [LANE_PRIOR, LANE_TRANSITION, LaneBoundaryModels, NegLaneBoundaryModel] = createLanePrior( LANE_OFFSETS_BINS, BASE_HISTOGRAM_BINS, 1/CM_TO_PIXEL, AVG_LANE_WIDTH, MIN_LANE_WIDTH, MAX_LANE_WIDTH, STD_LANE_WIDTH );
    
    LANE_FILTER  = LANE_PRIOR;
       
    
    LANE_FILTER_OFFSET_V  = -240;
    LANE_CONF_THRESHOLD   =  1;      %% the minumum confidence required for a lane boundary. 
    
    
    
   
%% The VP Filter  %%
    
    
    global VP_LANE_RATIO VP_RANGE_H VP_RANGE_V  VP_FILTER_OFFSET_V HORIZON_HISTOGRAM_STEP
    
    global  VP_BINS_V VP_BINS_H  VP_PRIOR VP_FILTER  VP_TRANSITION  HORIZON_HISTOGRAM_BINS 
    
    VP_RANGE_V  = 25;                                                               %% the vertical   +/- search range wrt image center for the VP
    VP_RANGE_H  = 300;                                                              %% the horizontal +/- search range wrt image center for the VP
    VP_STEP     = 10;                                                               %% the search step size
    
    
    
    VP_BINS_V   = -VP_RANGE_V:VP_STEP:VP_RANGE_V;                                   %% the VP vertical filter bins
    VP_BINS_H   = -VP_RANGE_H:VP_STEP:VP_RANGE_H;                                   %% the VP horizontal filter bins

    
    [VP_PRIOR, VP_TRANSITION] = createVPPrior( VP_BINS_V, VP_BINS_H, 5*VP_RANGE_V/VP_STEP );
    VP_FILTER   = VP_PRIOR;
    
    
    % OFFSET from Horizon
    VP_FILTER_OFFSET_V = -120;
    VP_LANE_RATIO      = VP_FILTER_OFFSET_V / LANE_FILTER_OFFSET_V;
    HORIZON_HISTOGRAM_BINS        = round(BASE_HISTOGRAM_BINS * VP_LANE_RATIO);
    HORIZON_HISTOGRAM_STEP        = HORIZON_HISTOGRAM_BINS(2)-HORIZON_HISTOGRAM_BINS(1);
    

%%
%% Start the State Machine%%

   startStateMachine ();    
    
end 
            




