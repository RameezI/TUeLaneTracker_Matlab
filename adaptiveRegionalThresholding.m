%%
%%
%% Do regeional adaptive thresholding and mask accordingly
%%
%%
%%
%%
function [MASK_P] = adaptiveRegionalThresholding(  P, acceptance_level, TOT_T )


    %%%%%%%%%%%%%%%%%%%%%%%%%
    %% min threshord level %%
    %%%%%%%%%%%%%%%%%%%%%%%%%
    TOT_T_MAX = 10*TOT_T;
    TOT_T_MIN = TOT_T^2;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% for three bands in the image %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    width        = 320;
    bands        = 1:width/2:640-width/2;
    bands        = [bands; bands+width-1];
    threshLevels = zeros(1,size(bands,2));
    acceptance_level = acceptance_level/size(bands,2);
    for b = 1:size(bands,2)
    
        %%%%%%%%%%%%%%%%%%%%%%%%
        %% loop untill enough %%
        %%%%%%%%%%%%%%%%%%%%%%%%
        for T = TOT_T_MAX:-0.01:TOT_T_MIN

            %%%%%%%%%%%%%%%%%%%
            %% enough passes %%
            %%%%%%%%%%%%%%%%%%%
%             idx = find( T <= P(:,bands(1,b):bands(2,b)) );
%             if acceptance_level <= size(idx,1)
            idx = T <= P(:,bands(1,b):bands(2,b));
            if acceptance_level <= sum( idx(:), 1)              
               threshLevels(b) = T;
               break; 
            end            
        end
    end
    
    
    
    %%%%%%%%%%%%%%%%%
    %% interpolate %%
    %%%%%%%%%%%%%%%%%    
    supps        = [1 sum(bands,1)/2 640];
    threshLevels = [threshLevels(1) threshLevels threshLevels(end)];
    coeffs  = polyfit( supps, threshLevels, 3 );
    ALL_T   = polyval( coeffs, 10:640-10 );
    ALL_T( TOT_T_MAX < ALL_T ) = TOT_T_MAX; %% cap between max and min
    ALL_T( ALL_T < TOT_T_MIN ) = TOT_T_MIN;   
        
%     sfigure(283);
%     clf
%     hold on
%     plot( 10:640-10, ALL_T );
%     plot( [1 640], [TOT_T_MIN TOT_T_MIN], '--b' );
%     plot( [1 640], [TOT_T_MAX TOT_T_MAX], '--b' );
%     plot( supps, threshLevels, 'x' );
                
    %%%%%%%%%%%%%%%%%%%%%%%%
    %% over several bands %%
    %%%%%%%%%%%%%%%%%%%%%%%%
    t = 1;
    for np = 10:640-10
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% the inerpolated thresh %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
        T = polyval(coeffs,np);
        
        %%%%%%%%%%%
        %% apply %%
        %%%%%%%%%%%
        MASK_P( :, np-9:np+10 ) = ALL_T(t) < P( :, np-9:np+10 );
        t = t + 1;
        
    end
    
end