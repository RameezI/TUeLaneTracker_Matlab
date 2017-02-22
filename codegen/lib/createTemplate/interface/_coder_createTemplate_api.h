/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_createTemplate_api.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 21-Feb-2017 22:59:58
 */

#ifndef _CODER_CREATETEMPLATE_API_H
#define _CODER_CREATETEMPLATE_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_createTemplate_api.h"

/* Type Definitions */
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

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void createTemplate(real32_T H, real32_T W, emxArray_real32_T *TEMPLATE);
extern void createTemplate_api(const mxArray * const prhs[2], const mxArray
  *plhs[1]);
extern void createTemplate_atexit(void);
extern void createTemplate_initialize(void);
extern void createTemplate_terminate(void);
extern void createTemplate_xil_terminate(void);

#endif

/*
 * File trailer for _coder_createTemplate_api.h
 *
 * [EOF]
 */
