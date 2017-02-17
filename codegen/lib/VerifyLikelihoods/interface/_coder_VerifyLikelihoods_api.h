/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_VerifyLikelihoods_api.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 01-Feb-2017 21:08:45
 */

#ifndef _CODER_VERIFYLIKELIHOODS_API_H
#define _CODER_VERIFYLIKELIHOODS_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_VerifyLikelihoods_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  emxArray_real_T *TOT_ALL;
  real_T TOT_MAX[307200];
  real_T GRADIENT_DIR_ALL[921600];
  real_T GRADIENT_DIR_AVG[307200];
  real_T TOT_ALL_BACK_UP[921600];
  real_T GRADIENT_DIR_ALL_BACK_UP[921600];
  real_T TOT_FOCUSED[307200];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void VerifyLikelihoods(struct0_T *likelihoods);
extern void VerifyLikelihoods_api(const mxArray * const prhs[1], const mxArray
  *plhs[1]);
extern void VerifyLikelihoods_atexit(void);
extern void VerifyLikelihoods_initialize(void);
extern void VerifyLikelihoods_terminate(void);
extern void VerifyLikelihoods_xil_terminate(void);

#endif

/*
 * File trailer for _coder_VerifyLikelihoods_api.h
 *
 * [EOF]
 */
