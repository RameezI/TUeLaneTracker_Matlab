/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_createTemplate_api.c
 *
 * Code generation for function '_coder_createTemplate_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "createTemplate.h"
#include "_coder_createTemplate_api.h"
#include "createTemplate_emxutil.h"
#include "createTemplate_data.h"

/* Variable Definitions */
static emlrtRTEInfo e_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_createTemplate_api",         /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static real32_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static real32_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *H, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const emxArray_real32_T *u);

/* Function Definitions */
static real32_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real32_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 0U, &dims);
  emlrtImportArrayR2015b(sp, src, &ret, 4, false);
  emlrtDestroyArray(&src);
  return ret;
}

static real32_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *H, const
  char_T *identifier)
{
  real32_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(H), &thisId);
  emlrtDestroyArray(&H);
  return y;
}

static const mxArray *emlrt_marshallOut(const emxArray_real32_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  real32_T *pData;
  int32_T i3;
  int32_T i;
  int32_T b_i;
  y = NULL;
  m0 = emlrtCreateNumericArray(2, *(int32_T (*)[2])u->size, mxSINGLE_CLASS,
    mxREAL);
  pData = (real32_T *)mxGetData(m0);
  i3 = 0;
  for (i = 0; i < u->size[1]; i++) {
    for (b_i = 0; b_i < u->size[0]; b_i++) {
      pData[i3] = u->data[b_i + u->size[0] * i];
      i3++;
    }
  }

  emlrtAssign(&y, m0);
  return y;
}

void createTemplate_api(const mxArray * const prhs[2], const mxArray *plhs[1])
{
  emxArray_real32_T *TEMPLATE;
  real32_T H;
  real32_T W;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real32_T(&st, &TEMPLATE, 2, &e_emlrtRTEI, true);

  /* Marshall function inputs */
  H = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "H");
  W = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "W");

  /* Invoke the target function */
  createTemplate(&st, H, W, TEMPLATE);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(TEMPLATE);
  emxFree_real32_T(&TEMPLATE);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_createTemplate_api.c) */
