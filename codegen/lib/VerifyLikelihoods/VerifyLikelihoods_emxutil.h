//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: VerifyLikelihoods_emxutil.h
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 01-Feb-2017 21:08:45
//
#ifndef VERIFYLIKELIHOODS_EMXUTIL_H
#define VERIFYLIKELIHOODS_EMXUTIL_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "VerifyLikelihoods_types.h"

// Function Declarations
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, int
  elementSize);
extern void emxFreeStruct_struct0_T(struct0_T *pStruct);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInitStruct_struct0_T(struct0_T *pStruct);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for VerifyLikelihoods_emxutil.h
//
// [EOF]
//
