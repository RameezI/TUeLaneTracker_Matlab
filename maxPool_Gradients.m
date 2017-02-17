function [MAG, DIR]   = maxPool_Gradients (MAG, MAGSH, MAGS, MAGV, DIR, DIRSH, DIRS, DIRV )
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% max pooling over gradient strength %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    mask      = MAG < MAGSH;
    MAG(mask) = MAGSH(mask);
    DIR(mask) = DIRSH(mask);            
    mask      = MAG < MAGS;
    MAG(mask) = MAGS(mask);
    DIR(mask) = DIRS(mask);
    mask      = MAG < MAGV;
    MAG(mask) = MAGV(mask);
    DIR(mask) = DIRV(mask);
    
end