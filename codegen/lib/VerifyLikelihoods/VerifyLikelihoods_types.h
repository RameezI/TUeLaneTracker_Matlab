//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: VerifyLikelihoods_types.h
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 01-Feb-2017 21:08:45
//
#ifndef VERIFYLIKELIHOODS_TYPES_H
#define VERIFYLIKELIHOODS_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray__common

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_int32_T

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_real_T

typedef struct {
  emxArray_real_T *TOT_ALL;
  double TOT_MAX[307200];
  double GRADIENT_DIR_ALL[921600];
  double GRADIENT_DIR_AVG[307200];
  double TOT_ALL_BACK_UP[921600];
  double GRADIENT_DIR_ALL_BACK_UP[921600];
  double TOT_FOCUSED[307200];
} struct0_T;

#endif

//
// File trailer for VerifyLikelihoods_types.h
//
// [EOF]
//
