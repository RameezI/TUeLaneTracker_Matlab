/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_Init_State_emxutil.h
 *
 * Code generation for function 'run_Init_State_emxutil'
 *
 */

#ifndef RUN_INIT_STATE_EMXUTIL_H
#define RUN_INIT_STATE_EMXUTIL_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "run_Init_State_types.h"

/* Function Declarations */
extern void c_emxFreeStruct_MatlabStruct_fo(MatlabStruct_focusMask *pStruct);
extern void c_emxFreeStruct_MatlabStruct_li(MatlabStruct_likelihoods *pStruct);
extern void c_emxFreeStruct_MatlabStruct_te(MatlabStruct_templates *pStruct);
extern void c_emxInitStruct_MatlabStruct_fo(const emlrtStack *sp,
  MatlabStruct_focusMask *pStruct, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
extern void c_emxInitStruct_MatlabStruct_li(const emlrtStack *sp,
  MatlabStruct_likelihoods *pStruct, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
extern void c_emxInitStruct_MatlabStruct_te(const emlrtStack *sp,
  MatlabStruct_templates *pStruct, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
extern void emxEnsureCapacity(const emlrtStack *sp, emxArray__common *emxArray,
  int32_T oldNumel, int32_T elementSize, const emlrtRTEInfo *srcLocation);
extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real32_T(emxArray_real32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
extern void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_int32_T1(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_real32_T(const emlrtStack *sp, emxArray_real32_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);

#endif

/* End of code generation (run_Init_State_emxutil.h) */
