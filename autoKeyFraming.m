function [innovation] = autoKeyFraming(TOT_P_LAST_FRAME, PROB)

%%
%% Thresholds %%

    GRAY_T = 0.5; %% 0.5 is the value of the "tipping" point of the membership functions
    YELL_T = 0.5.* 0.5;
    MAG_T  = 0.5;
    DIR_T  = 0.5;
    TOT_T  = min(GRAY_T,YELL_T).*MAG_T.*DIR_T;

%% 
%% INNOVATION %%

    mask1 = TOT_T < TOT_P_LAST_FRAME;   %% all pixels in the last image of the buffer above the threshold
    mask2 = TOT_T < PROB;               %% all pixels in the new image above the threshold
    mask3 = 0 < abs(mask2-mask1);       %% all pixels that chnaged in the new image wrt. the last image
    innovation = sum(mask3(:),1) / sum(mask1(:),1); %% as a percentage of all set pixels in the last image

end