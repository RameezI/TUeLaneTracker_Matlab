function [Likelihoods] = updateLaneLikelihoods(NBUFFER, PROB_KEY, DIR_KEY, PROB_KEY_BACK_UP, Likelihoods )

 Likelihoods.TOT_ALL(:,:,1:NBUFFER-1) = Likelihoods.TOT_ALL(:,:,2:NBUFFER);
 Likelihoods.TOT_ALL(:,:,NBUFFER)     = PROB_KEY;
 
 Likelihoods.GRADIENT_DIR_ALL(:,:,1:NBUFFER-1)   = Likelihoods.GRADIENT_DIR_ALL(:,:,2:NBUFFER);
 Likelihoods.GRADIENT_DIR_ALL(:,:,NBUFFER)       = DIR_KEY;

 Likelihoods.TOT_ALL_BACKUP(:,:,1:NBUFFER-1) = Likelihoods.TOT_ALL_BACKUP(:,:,2:NBUFFER);
 Likelihoods.TOT_ALL_BACKUP(:,:,NBUFFER)     = PROB_KEY_BACK_UP;
            
 Likelihoods.GRADIENT_DIR_ALL_BACKUP(:,:,1:NBUFFER-1)   = Likelihoods.GRADIENT_DIR_ALL_BACKUP(:,:,2:NBUFFER);
 Likelihoods.GRADIENT_DIR_ALL_BACKUP(:,:,NBUFFER)       = DIR_KEY;


end