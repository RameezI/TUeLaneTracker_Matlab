/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_Init_State_types.h
 *
 * Code generation for function 'run_Init_State'
 *
 */

#ifndef RUN_INIT_STATE_TYPES_H
#define RUN_INIT_STATE_TYPES_H

/* Include files */
#include "rtwtypes.h"

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

#ifndef typedef_MatlabStruct_focusMask
#define typedef_MatlabStruct_focusMask

typedef struct {
  emxArray_real_T *FOCUS;
} MatlabStruct_focusMask;

#endif                                 /*typedef_MatlabStruct_focusMask*/

#ifndef typedef_MatlabStruct_likelihoods
#define typedef_MatlabStruct_likelihoods

typedef struct {
  emxArray_real_T *TOT_ALL;
  emxArray_real_T *TOT_MAX;
  emxArray_real_T *GRADIENT_DIR_ALL;
  emxArray_real_T *GRADIENT_DIR_AVG;
  emxArray_real_T *TOT_ALL_BACK_UP;
  emxArray_real_T *GRADIENT_DIR_ALL_BACK_UP;
  emxArray_real_T *TOT_FOCUSED;
} MatlabStruct_likelihoods;

#endif                                 /*typedef_MatlabStruct_likelihoods*/

#ifndef typedef_MatlabStruct_templates
#define typedef_MatlabStruct_templates

typedef struct {
  emxArray_real_T *GRADIENT_DIR_ROOT;
  emxArray_real_T *PROB_ROOT;
  emxArray_real_T *DEPTH_ROOT;
} MatlabStruct_templates;

#endif                                 /*typedef_MatlabStruct_templates*/

#ifndef typedef_MatlabStruct_vanishingPt
#define typedef_MatlabStruct_vanishingPt

typedef struct {
  real_T V;
  real_T H;
  real_T V_prev;
  real_T H_prev;
} MatlabStruct_vanishingPt;

#endif                                 /*typedef_MatlabStruct_vanishingPt*/

#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T

struct emxArray_real32_T
{
  real32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real32_T*/

#ifndef typedef_emxArray_real32_T
#define typedef_emxArray_real32_T

typedef struct emxArray_real32_T emxArray_real32_T;

#endif                                 /*typedef_emxArray_real32_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real32_T mFilter[5929];
  real32_T mPrior[5929];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real32_T mFilter[366];
  real32_T mPrior[366];
} struct1_T;

#endif                                 /*typedef_struct1_T*/
#endif

/* End of code generation (run_Init_State_types.h) */
