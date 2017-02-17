/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_VerifyLikelihoods_api.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 01-Feb-2017 21:08:45
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_VerifyLikelihoods_api.h"
#include "_coder_VerifyLikelihoods_mex.h"

/* Type Definitions */
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

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131435U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "VerifyLikelihoods",                 /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[307200]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[921600]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *likelihoods,
  const char_T *identifier, struct0_T *y);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct0_T *u);
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
  boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[307200]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[921600]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct0_T *y
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[7] = { "TOT_ALL", "TOT_MAX", "GRADIENT_DIR_ALL",
    "GRADIENT_DIR_AVG", "TOT_ALL_BACK_UP", "GRADIENT_DIR_ALL_BACK_UP",
    "TOT_FOCUSED" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 7, fieldNames, 0U, &dims);
  thisId.fIdentifier = "TOT_ALL";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "TOT_ALL")),
                     &thisId, y->TOT_ALL);
  thisId.fIdentifier = "TOT_MAX";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "TOT_MAX")),
                     &thisId, y->TOT_MAX);
  thisId.fIdentifier = "GRADIENT_DIR_ALL";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "GRADIENT_DIR_ALL")), &thisId, y->GRADIENT_DIR_ALL);
  thisId.fIdentifier = "GRADIENT_DIR_AVG";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "GRADIENT_DIR_AVG")), &thisId, y->GRADIENT_DIR_AVG);
  thisId.fIdentifier = "TOT_ALL_BACK_UP";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "TOT_ALL_BACK_UP")), &thisId, y->TOT_ALL_BACK_UP);
  thisId.fIdentifier = "GRADIENT_DIR_ALL_BACK_UP";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "GRADIENT_DIR_ALL_BACK_UP")), &thisId, y->GRADIENT_DIR_ALL_BACK_UP);
  thisId.fIdentifier = "TOT_FOCUSED";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "TOT_FOCUSED")),
                     &thisId, y->TOT_FOCUSED);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[307200]
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[307200])
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[921600]
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[921600])
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *likelihoods
 *                const char_T *identifier
 *                struct0_T *y
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *likelihoods,
  const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(likelihoods), &thisId, y);
  emlrtDestroyArray(&likelihoods);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const struct0_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct0_T *u)
{
  const mxArray *y;
  emxArray_real_T *b_u;
  int32_T i0;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m0;
  real_T *pData;
  int32_T i;
  const mxArray *c_y;
  static const int32_T iv0[2] = { 480, 640 };

  int32_T b_i;
  const mxArray *d_y;
  static const int32_T iv1[3] = { 480, 640, 3 };

  const mxArray *e_y;
  static const int32_T iv2[2] = { 480, 640 };

  const mxArray *f_y;
  static const int32_T iv3[3] = { 480, 640, 3 };

  const mxArray *g_y;
  static const int32_T iv4[3] = { 480, 640, 3 };

  const mxArray *h_y;
  static const int32_T iv5[2] = { 480, 640 };

  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_u, 3, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  i0 = b_u->size[0] * b_u->size[1] * b_u->size[2];
  b_u->size[0] = u->TOT_ALL->size[0];
  b_u->size[1] = u->TOT_ALL->size[1];
  b_u->size[2] = u->TOT_ALL->size[2];
  emxEnsureCapacity((emxArray__common *)b_u, i0, (int32_T)sizeof(real_T));
  loop_ub = u->TOT_ALL->size[0] * u->TOT_ALL->size[1] * u->TOT_ALL->size[2];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_u->data[i0] = u->TOT_ALL->data[i0];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(3, *(int32_T (*)[2])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = (real_T *)mxGetPr(m0);
  i0 = 0;
  for (loop_ub = 0; loop_ub < b_u->size[2]; loop_ub++) {
    for (i = 0; i < b_u->size[1]; i++) {
      for (b_i = 0; b_i < b_u->size[0]; b_i++) {
        pData[i0] = b_u->data[(b_i + b_u->size[0] * i) + b_u->size[0] *
          b_u->size[1] * loop_ub];
        i0++;
      }
    }
  }

  emlrtAssign(&b_y, m0);
  emlrtAddField(y, b_y, "TOT_ALL", 0);
  c_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (loop_ub = 0; loop_ub < 307200; loop_ub++) {
    pData[loop_ub] = u->TOT_MAX[loop_ub];
  }

  emlrtAssign(&c_y, m0);
  emlrtAddField(y, c_y, "TOT_MAX", 0);
  d_y = NULL;
  m0 = emlrtCreateNumericArray(3, iv1, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (loop_ub = 0; loop_ub < 921600; loop_ub++) {
    pData[loop_ub] = u->GRADIENT_DIR_ALL[loop_ub];
  }

  emlrtAssign(&d_y, m0);
  emlrtAddField(y, d_y, "GRADIENT_DIR_ALL", 0);
  e_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv2, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (loop_ub = 0; loop_ub < 307200; loop_ub++) {
    pData[loop_ub] = u->GRADIENT_DIR_AVG[loop_ub];
  }

  emlrtAssign(&e_y, m0);
  emlrtAddField(y, e_y, "GRADIENT_DIR_AVG", 0);
  f_y = NULL;
  m0 = emlrtCreateNumericArray(3, iv3, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (loop_ub = 0; loop_ub < 921600; loop_ub++) {
    pData[loop_ub] = u->TOT_ALL_BACK_UP[loop_ub];
  }

  emlrtAssign(&f_y, m0);
  emlrtAddField(y, f_y, "TOT_ALL_BACK_UP", 0);
  g_y = NULL;
  m0 = emlrtCreateNumericArray(3, iv4, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (loop_ub = 0; loop_ub < 921600; loop_ub++) {
    pData[loop_ub] = u->GRADIENT_DIR_ALL_BACK_UP[loop_ub];
  }

  emlrtAssign(&g_y, m0);
  emlrtAddField(y, g_y, "GRADIENT_DIR_ALL_BACK_UP", 0);
  h_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv5, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (loop_ub = 0; loop_ub < 307200; loop_ub++) {
    pData[loop_ub] = u->TOT_FOCUSED[loop_ub];
  }

  emlrtAssign(&h_y, m0);
  emlrtAddField(y, h_y, "TOT_FOCUSED", 0);
  emxFree_real_T(&b_u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

/*
 * Arguments    : emxArray__common *emxArray
 *                int32_T oldNumel
 *                int32_T elementSize
 * Return Type  : void
 */
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, (uint32_T)elementSize);
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, (uint32_T)(elementSize * oldNumel));
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : struct0_T *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_real_T(&pStruct->TOT_ALL);
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct0_T *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->TOT_ALL, 3, doPush);
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[3] = { -1, -1, -1 };

  boolean_T bv0[3] = { true, true, true };

  int32_T iv6[3];
  int32_T i1;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 3U, dims, &bv0[0],
    iv6);
  i1 = ret->size[0] * ret->size[1] * ret->size[2];
  ret->size[0] = iv6[0];
  ret->size[1] = iv6[1];
  ret->size[2] = iv6[2];
  emxEnsureCapacity((emxArray__common *)ret, i1, (int32_T)sizeof(real_T));
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[307200]
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[307200])
{
  static const int32_T dims[2] = { 480, 640 };

  int32_T i2;
  int32_T i3;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i2 = 0; i2 < 640; i2++) {
    for (i3 = 0; i3 < 480; i3++) {
      ret[i3 + 480 * i2] = (*(real_T (*)[307200])mxGetData(src))[i3 + 480 * i2];
    }
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[921600]
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[921600])
{
  static const int32_T dims[3] = { 480, 640, 3 };

  int32_T i4;
  int32_T i5;
  int32_T i6;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 3U, dims);
  for (i4 = 0; i4 < 3; i4++) {
    for (i5 = 0; i5 < 640; i5++) {
      for (i6 = 0; i6 < 480; i6++) {
        ret[(i6 + 480 * i5) + 307200 * i4] = (*(real_T (*)[921600])mxGetData(src))
          [(i6 + 480 * i5) + 307200 * i4];
      }
    }
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray * const prhs[1]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void VerifyLikelihoods_api(const mxArray * const prhs[1], const mxArray *plhs[1])
{
  static struct0_T likelihoods;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInitStruct_struct0_T(&st, &likelihoods, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[0]), "likelihoods",
                   &likelihoods);

  /* Invoke the target function */
  VerifyLikelihoods(&likelihoods);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, &likelihoods);
  emxFreeStruct_struct0_T(&likelihoods);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void VerifyLikelihoods_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  VerifyLikelihoods_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void VerifyLikelihoods_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void VerifyLikelihoods_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_VerifyLikelihoods_api.c
 *
 * [EOF]
 */
