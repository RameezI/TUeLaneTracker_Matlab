%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%%
%% detect and track the ego-lane
%%
%% The Ego-lane is parametrized with 
%% - its Vanishing Point (VP)
%% - The left and right horizontal pixel offsets wrt. the VP at the bottom of the image
%% So, in total 4 degrees of freedom.
%% - the VP is fitted under a weigthed L1 norm using template fitting by image convolution 
%% - the offsets are obtained using a weighted histogram filter 
%% All weights are based on lane likelihoods, exploiting simple normal distributions over intensity,color,gradient, and lane width 
%%
%% Ego-lane Boudary Detection and Classification
%%
%% Information considered by approach
%% - Pixel-level: gradient strength and direction, intensity, color
%% - Segment-level: accumulated from pixel-level and spatial length of lane boundary
%% - Object-level: accumlated from segent-level and inner lane uniformity
%% - Scene-level: none but can be extended to eploit lane adjacency and road layouts
%%
function [] = laneTracker2()

    %%
    %% TUe DATASET %%
    global DATASET IMAGE_FILES LOGO DisplayNumber
    DATASET = '/media/rameez/Linux-Extended/DataSet/eindhoven/PNG_imgs/';
    LOGO = im2double(imread('tue.png'));
    DATASET
    IMAGE_FILES= dir([DATASET,'*.png']); 
    DisplayNumber =0;
    
    %%
    %% States of the system %%
    global INIT_STATE FILLING_BUFFERS DETECTING_EGO_LANE TRACKING_EGO_LANE TRACKING_EGO_LANE_STABLE CURRENT_STATE RESET_STATE   
    INIT_STATE               = -1; %% this acts like a #define as in C/C++
    FILLING_BUFFERS          = 1;  %% this acts like a #define as in C/C++
    DETECTING_EGO_LANE       = 2;  %% this acts like a #define as in C/C++
    TRACKING_EGO_LANE        = 3;  %% this acts like a #define as in C/C++
    TRACKING_EGO_LANE_STABLE = 4;  %% this acts like a #define as in C/C++
    RESET_STATE              = 5;  %% this acts like a #define as in C/C++
    CURRENT_STATE            = INIT_STATE;
    
    
    
    %%%%%%%%%%%%%%%%%%%%
    %% state messages %%
    %%%%%%%%%%%%%%%%%%%%
    global STATE_BUSY STATE_READY STATE_ERROR
    STATE_BUSY  = 0; %% this acts like a #define as in C/C++
    STATE_READY = 1; %% this acts like a #define as in C/C++
    STATE_ERROR = 2; %% this acts like a #define as in C/C++
    
    
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% state counter (how many itterations are we in the current state) %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    global STATE_COUNTER
    STATE_COUNTER  = 0;
    
    
    %%
    % The Image Coordinate System
    %            
    %              
    %              O -----> + H (2nd dim)
    %              |
    %              | 
    %              |
    %              v + V (1st dim)
    
    
    %% 
    %% Camera Properties %%
    global CM_TO_PIXEL RES_VH C_V C_H RGB
    RES_VH     = [480 640]; %% resolution of camera
    FOV        = [45 60];   %% field of view of camera
    CAM_H      = 1.5;       %% camera height in meters
    CAM_F      = 6e-3;      %% camera focal length in meters
    RGB        = zeros( RES_VH ); %% buffer for the rgb image data
    
    
    
    %%
    %% Car Properties %%
    global CAR_WIDTH
    CAR_WIDTH = 170; %% cm - average according to Bovag
    
    
    
    %%
    %% Camera Properties Automatically Computed %%
    
    H_FOV_V     = FOV(1)/2;     %% half vertical field of view
    H_RES_V     = RES_VH(1)/2;  %% half vertical resolution
    H_FOV_H     = FOV(2)/2;     %% half horizontal field of view
    H_RES_H     = RES_VH(2)/2;  %% half horizontal resolution
    PX_SIZE     = (tand(H_FOV_V)*CAM_F)/H_RES_V;                  %% (vertical) size of the pixels
    PX_ANG      = atand( PX_SIZE * [1:(2*H_RES_V)]/CAM_F );       %% angles of each (virtual) pixel below middle line
    DEPTH_P     = CAM_H *tand( 90-PX_ANG );                       %% the depth at each (virtual) pixel below middle line
    CM_TO_PIXEL = H_RES_H/(100*tand(H_FOV_H)*DEPTH_P(H_RES_V-1)); %% the horizontal pixel to cm ratio at the bottom line of the image
    C_V         = RES_VH(1)/2;  %% verticel image center in image coordinate system
    C_H         = RES_VH(2)/2;  %% horizontal image center in image coordinate system
    

    
    %%
    %% Lane Properties %%
    
    global MIN_LANE_WIDTH MAX_LANE_WIDTH
    AVG_LANE_WIDTH = 300; %% cm
    STD_LANE_WIDTH = 50;  %% cm
    MIN_LANE_WIDTH = 250; %% cm
    MAX_LANE_WIDTH = 500; %% cm
    CM_STEP        = 5;   %% make histogram bins with a width of 5 cm
    
    
    
    %%
    %% Lane Normal Distributions %%
    
%      global NGRAY NMAG NDIR  
     

%      NGRAY = [ 2^0    100];      %% sigmoid membership: white is more likely to be a lane boundary
%      NMAG  = [ 2^0     50];      %% Sobel edge filter - sigmoid membership: strong edge magnitude is more likelely to be a lane boundary
% %      NDIR  = [ 2^0   0.26];       %% sigmoid membership: direction according to the template is more likely to be a lane boundary

global tippingPoint_gray tippingPoint_gradMag;
tippingPoint_gray= 100;
tippingPoint_gradMag= 50;
     
    
    %%
    %% The VP Coordinate System %%^TODO: Is the column first dimension herer?
    %
    %              ^ + V (2nd dim)
    %              |
    %              |
    %              |   
    %              |
    %             VP-----> + H (1st dim)

    
    
    
   %%
   %% The lane filter expressed in the VP coordinate system %%
   
    global  LANE_CONF_THRESHOLD OBS_L OBS_R OBS_N LANE_BINS_H LANE_INFO LANE_FILTER_BINS_H PX_STEP LANE_PRIOR LANE_TRANSITION LANE_FILTER PX_MAX LANE_FILTER_OFFSET_V
    PX_STEP            = ceil((CM_STEP*CM_TO_PIXEL)/10)*10;                        %% the CM_STEP translated to pixels at the bottom line of the image (i.e. according to CM_TO_PIXEL)
    PX_MAX             = round((MAX_LANE_WIDTH*CM_TO_PIXEL)/PX_STEP)*PX_STEP;      %% te maximum lane width in pixels at the bottom line of the image (i.e. according to CM_TO_PIXEL)
    LANE_BINS_H        = -PX_MAX:PX_STEP:PX_MAX;                                   %% the histogram bins for the lane observation model
    LANE_FILTER_BINS_H = round([0:PX_STEP:PX_MAX]);                                %% the histogram bins for the 2D lane filter (bins are used for the left and right lane)
    LANE_INFO          = [0 0 0 1 1];                                              %% ?
    [LANE_PRIOR, LANE_TRANSITION] = createLanePrior( LANE_FILTER_BINS_H, 1/CM_TO_PIXEL, AVG_LANE_WIDTH, MIN_LANE_WIDTH, MAX_LANE_WIDTH, STD_LANE_WIDTH );
    LANE_FILTER        = LANE_PRIOR;                                               %% the lane filter histogram bins
    
    
    
    
    
   %% 
   %% The Lane Observation Histograms 
    [OBS_L, OBS_R, OBS_N] = createLaneObservationModel( LANE_FILTER_BINS_H, LANE_BINS_H, MIN_LANE_WIDTH, MAX_LANE_WIDTH, LANE_FILTER_BINS_H, CM_TO_PIXEL );
    LANE_FILTER_OFFSET_V  = -240;
    LANE_CONF_THRESHOLD   = 1; %% the minumum confidence required for a lane boundary. Expressed in percentage of total lande boundary observation pdf.
    
    
    
    %%
    %% the center image coordinate system
    %            
    %              
    %             C --> + H (2nd dim)
    %              |
    %              |
    %              |
    %              v + V (1st dim)
    %
    %%
    %% the VP filter expressed in the center image coordinate system %%
    
    global LANE_WIDTH_DIFF_NORMA LANE_WIDTH_DIFF_NOMIN VP_LANE_RATIO VP_RANGE_H VP_RANGE_V VP_STEP VP_PRIOR VP_FILTER VP_BINS_V VP_BINS_H VP_FILTER_OFFSET_V VP_TRANSITION VP_STEP_HST VP_BINS_HST
    VP_RANGE_V  = 25;  %% the vertical +/- search range wrt image center for the VP
    VP_RANGE_H  = 300; %% the horizontal +/- search range wrt image center for the VP
    VP_STEP     = 10;  %% the search step size
    VP_BINS_V   = [-VP_RANGE_V:VP_STEP:VP_RANGE_V] + C_V; %% the VP vertical filter bins
    VP_BINS_H   = [-VP_RANGE_H:VP_STEP:VP_RANGE_H] + C_H; %% the VP horizontal filter bins
    [VP_PRIOR, VP_TRANSITION] = createVPPrior( VP_BINS_V, VP_BINS_H, 5*VP_RANGE_V/VP_STEP );
    VP_FILTER   = VP_PRIOR; %% the VP filter
    VP_FILTER_OFFSET_V = -120;
    VP_LANE_RATIO      = VP_FILTER_OFFSET_V / LANE_FILTER_OFFSET_V;
    VP_BINS_HST        = round(LANE_BINS_H * VP_LANE_RATIO);
    VP_STEP_HST        = VP_BINS_HST(2)-VP_BINS_HST(1);
    LANE_WIDTH_DIFF_SIGMA = 15; %% sigma in cm of difference in lane width between lane and vp filter
    LANE_WIDTH_DIFF_NORMA = 1/(sqrt(2*pi*LANE_WIDTH_DIFF_SIGMA^2));
    LANE_WIDTH_DIFF_NOMIN = 2*LANE_WIDTH_DIFF_SIGMA^2;
    
    %%
    %% The sigma on the lane observation probability mass between the lane markings %%
    
    global OBS_NEG_SIFMA OBS_NEG_NOMIN OBS_NEG_NORMA
    OBS_NEG_SIFMA = 0.2;
    OBS_NEG_NOMIN = 2*OBS_NEG_SIFMA^2;
    OBS_NEG_NORMA = 2/(sqrt(2*pi*OBS_NEG_SIFMA^2)); %% only positive side of x-axis, so half a Gaussian
    

%%
%% Start the State Machine%%

   startStateMachine ();    
    
end 
            




