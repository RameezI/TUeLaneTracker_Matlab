/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_run_Init_State_api.c
 *
 * Code generation for function '_coder_run_Init_State_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_Init_State.h"
#include "_coder_run_Init_State_api.h"
#include "run_Init_State_emxutil.h"
#include "run_Init_State_data.h"

/* Variable Definitions */
static emlrtRTEInfo i_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_run_Init_State_api",         /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static int32_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[2];
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static int32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *NBUFFER,
  const char_T *identifier);
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static int32_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *d_emlrt_marshallOut(const MatlabStruct_templates u);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *laneFilter,
  const char_T *identifier, struct0_T *y);
static const mxArray *e_emlrt_marshallOut(const MatlabStruct_vanishingPt u);
static int32_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *RES_VH,
  const char_T *identifier))[2];
static const mxArray *emlrt_marshallOut(const MatlabStruct_likelihoods u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static const mxArray *f_emlrt_marshallOut(const MatlabStruct_focusMask u);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[5929]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *vpFilter,
  const char_T *identifier, struct1_T *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[366]);
static int32_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2];
static int32_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[5929]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[366]);

/* Function Definitions */
static int32_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[2]
{
  int32_T (*y)[2];
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  real_T *pData;
  int32_T i5;
  int32_T i;
  int32_T b_i;
  int32_T c_i;
  y = NULL;
  m0 = emlrtCreateNumericArray(3, *(int32_T (*)[3])u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = (real_T *)mxGetPr(m0);
  i5 = 0;
  for (i = 0; i < u->size[2]; i++) {
    for (b_i = 0; b_i < u->size[1]; b_i++) {
      for (c_i = 0; c_i < u->size[0]; c_i++) {
        pData[i5] = u->data[(c_i + u->size[0] * b_i) + u->size[0] * u->size[1] *
          i];
        i5++;
      }
    }
  }

  emlrtAssign(&y, m0);
  return y;
}

static int32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *NBUFFER,
  const char_T *identifier)
{
  int32_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(NBUFFER), &thisId);
  emlrtDestroyArray(&NBUFFER);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m1;
  real_T *pData;
  int32_T i6;
  int32_T i;
  int32_T b_i;
  y = NULL;
  m1 = emlrtCreateNumericArray(2, *(int32_T (*)[3])u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = (real_T *)mxGetPr(m1);
  i6 = 0;
  for (i = 0; i < u->size[1]; i++) {
    for (b_i = 0; b_i < u->size[0]; b_i++) {
      pData[i6] = u->data[b_i + u->size[0] * i];
      i6++;
    }
  }

  emlrtAssign(&y, m1);
  return y;
}

static int32_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *d_emlrt_marshallOut(const MatlabStruct_templates u)
{
  const mxArray *y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  emlrtAddField(y, c_emlrt_marshallOut(u.GRADIENT_DIR_ROOT), "GRADIENT_DIR_ROOT",
                0);
  emlrtAddField(y, c_emlrt_marshallOut(u.PROB_ROOT), "PROB_ROOT", 0);
  emlrtAddField(y, c_emlrt_marshallOut(u.DEPTH_ROOT), "DEPTH_ROOT", 0);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *laneFilter,
  const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(laneFilter), &thisId, y);
  emlrtDestroyArray(&laneFilter);
}

static const mxArray *e_emlrt_marshallOut(const MatlabStruct_vanishingPt u)
{
  const mxArray *y;
  const mxArray *b_y;
  const mxArray *m2;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(u.V);
  emlrtAssign(&b_y, m2);
  emlrtAddField(y, b_y, "V", 0);
  c_y = NULL;
  m2 = emlrtCreateDoubleScalar(u.H);
  emlrtAssign(&c_y, m2);
  emlrtAddField(y, c_y, "H", 0);
  d_y = NULL;
  m2 = emlrtCreateDoubleScalar(u.V_prev);
  emlrtAssign(&d_y, m2);
  emlrtAddField(y, d_y, "V_prev", 0);
  e_y = NULL;
  m2 = emlrtCreateDoubleScalar(u.H_prev);
  emlrtAssign(&e_y, m2);
  emlrtAddField(y, e_y, "H_prev", 0);
  return y;
}

static int32_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *RES_VH,
  const char_T *identifier))[2]
{
  int32_T (*y)[2];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(RES_VH), &thisId);
  emlrtDestroyArray(&RES_VH);
  return y;
}
  static const mxArray *emlrt_marshallOut(const MatlabStruct_likelihoods u)
{
  const mxArray *y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  emlrtAddField(y, b_emlrt_marshallOut(u.TOT_ALL), "TOT_ALL", 0);
  emlrtAddField(y, c_emlrt_marshallOut(u.TOT_MAX), "TOT_MAX", 0);
  emlrtAddField(y, b_emlrt_marshallOut(u.GRADIENT_DIR_ALL), "GRADIENT_DIR_ALL",
                0);
  emlrtAddField(y, c_emlrt_marshallOut(u.GRADIENT_DIR_AVG), "GRADIENT_DIR_AVG",
                0);
  emlrtAddField(y, b_emlrt_marshallOut(u.TOT_ALL_BACK_UP), "TOT_ALL_BACK_UP", 0);
  emlrtAddField(y, b_emlrt_marshallOut(u.GRADIENT_DIR_ALL_BACK_UP),
                "GRADIENT_DIR_ALL_BACK_UP", 0);
  emlrtAddField(y, c_emlrt_marshallOut(u.TOT_FOCUSED), "TOT_FOCUSED", 0);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[2] = { "mFilter", "mPrior" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 2, fieldNames, 0U, &dims);
  thisId.fIdentifier = "mFilter";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "mFilter")),
                     &thisId, y->mFilter);
  thisId.fIdentifier = "mPrior";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "mPrior")),
                     &thisId, y->mPrior);
  emlrtDestroyArray(&u);
}

static const mxArray *f_emlrt_marshallOut(const MatlabStruct_focusMask u)
{
  const mxArray *y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  emlrtAddField(y, c_emlrt_marshallOut(u.FOCUS), "FOCUS", 0);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[5929])
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *vpFilter,
  const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  i_emlrt_marshallIn(sp, emlrtAlias(vpFilter), &thisId, y);
  emlrtDestroyArray(&vpFilter);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[2] = { "mFilter", "mPrior" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 2, fieldNames, 0U, &dims);
  thisId.fIdentifier = "mFilter";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "mFilter")),
                     &thisId, y->mFilter);
  thisId.fIdentifier = "mPrior";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "mPrior")),
                     &thisId, y->mPrior);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[366])
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static int32_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2]
{
  int32_T (*ret)[2];
  static const int32_T dims[2] = { 1, 2 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "int32", false, 2U, dims);
  ret = (int32_T (*)[2])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static int32_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  int32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "int32", false, 0U, &dims);
  ret = *(int32_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[5929])
{
  static const int32_T dims[2] = { 77, 77 };

  int32_T i7;
  int32_T i8;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "single", false, 2U, dims);
  for (i7 = 0; i7 < 77; i7++) {
    for (i8 = 0; i8 < 77; i8++) {
      ret[i8 + 77 * i7] = (*(real32_T (*)[5929])mxGetData(src))[i8 + 77 * i7];
    }
  }

  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[366])
{
  static const int32_T dims[2] = { 6, 61 };

  int32_T i9;
  int32_T i10;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "single", false, 2U, dims);
  for (i9 = 0; i9 < 61; i9++) {
    for (i10 = 0; i10 < 6; i10++) {
      ret[i10 + 6 * i9] = (*(real32_T (*)[366])mxGetData(src))[i10 + 6 * i9];
    }
  }

  emlrtDestroyArray(&src);
}

void run_Init_State_api(const mxArray * const prhs[4], const mxArray *plhs[4])
{
  MatlabStruct_likelihoods likelihoods;
  MatlabStruct_templates templates;
  MatlabStruct_focusMask masks;
  int32_T (*RES_VH)[2];
  int32_T NBUFFER;
  struct0_T laneFilter;
  struct1_T vpFilter;
  MatlabStruct_vanishingPt vanishingPt;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  c_emxInitStruct_MatlabStruct_li(&st, &likelihoods, &i_emlrtRTEI, true);
  c_emxInitStruct_MatlabStruct_te(&st, &templates, &i_emlrtRTEI, true);
  c_emxInitStruct_MatlabStruct_fo(&st, &masks, &i_emlrtRTEI, true);

  /* Marshall function inputs */
  RES_VH = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "RES_VH");
  NBUFFER = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "NBUFFER");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "laneFilter", &laneFilter);
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "vpFilter", &vpFilter);

  /* Invoke the target function */
  run_Init_State(&st, *RES_VH, NBUFFER, &laneFilter, &vpFilter, &likelihoods,
                 &templates, &vanishingPt, &masks);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(likelihoods);
  plhs[1] = d_emlrt_marshallOut(templates);
  plhs[2] = e_emlrt_marshallOut(vanishingPt);
  plhs[3] = f_emlrt_marshallOut(masks);
  c_emxFreeStruct_MatlabStruct_fo(&masks);
  c_emxFreeStruct_MatlabStruct_te(&templates);
  c_emxFreeStruct_MatlabStruct_li(&likelihoods);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_run_Init_State_api.c) */
