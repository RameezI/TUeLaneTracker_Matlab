//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: VerifyLikelihoods_emxAPI.h
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 01-Feb-2017 21:08:45
//
#ifndef VERIFYLIKELIHOODS_EMXAPI_H
#define VERIFYLIKELIHOODS_EMXAPI_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "VerifyLikelihoods_types.h"

// Function Declarations
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxDestroy_struct0_T(struct0_T emxArray);
extern void emxInit_struct0_T(struct0_T *pStruct);

#endif

//
// File trailer for VerifyLikelihoods_emxAPI.h
//
// [EOF]
//
