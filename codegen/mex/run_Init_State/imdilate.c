/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imdilate.c
 *
 * Code generation for function 'imdilate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_Init_State.h"
#include "imdilate.h"
#include "run_Init_State_emxutil.h"
#include "libmwmorphop_flat_tbb.h"

/* Variable Definitions */
static emlrtRSInfo lb_emlrtRSI = { 135,/* lineNo */
  "imdilate",                          /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/images/images/imdilate.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 17, /* lineNo */
  "morphop",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/images/images/+images/+internal/morphop.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 20, /* lineNo */
  "morphop",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/images/images/+images/+internal/+coder/morphop.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 379,/* lineNo */
  "morphop",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/images/images/+images/+internal/+coder/morphop.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 19, /* lineNo */
  "morphop",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/images/images/+images/+internal/+coder/morphop.m"/* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "imdilate",                          /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/images/images/imdilate.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 171,/* lineNo */
  28,                                  /* colNo */
  "validateattributes",                /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/lang/validateattributes.m"/* pName */
};

/* Function Definitions */
void imdilate(const emlrtStack *sp, const emxArray_real_T *A, emxArray_real_T *B)
{
  boolean_T p;
  int32_T i4;
  int32_T k;
  boolean_T exitg1;
  real_T asize[2];
  boolean_T nhood[9];
  real_T nsize[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &mb_emlrtRSI;
  c_st.site = &pb_emlrtRSI;
  c_st.site = &nb_emlrtRSI;
  p = true;
  i4 = A->size[0] * A->size[1];
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i4 - 1)) {
    if (!muDoubleScalarIsNaN(A->data[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrMsgIdAndExplicitTxt(&c_st, &u_emlrtRTEI,
      "MATLAB:imdilate:expectedNonNaN", 43,
      "Expected input number 1, IM, to be non-NaN.");
  }

  for (i4 = 0; i4 < 2; i4++) {
    k = B->size[0] * B->size[1];
    B->size[i4] = A->size[i4];
    emxEnsureCapacity(&b_st, (emxArray__common *)B, k, (int32_T)sizeof(real_T),
                      &h_emlrtRTEI);
  }

  c_st.site = &ob_emlrtRSI;
  for (i4 = 0; i4 < 2; i4++) {
    asize[i4] = A->size[i4];
  }

  for (i4 = 0; i4 < 9; i4++) {
    nhood[i4] = true;
  }

  for (i4 = 0; i4 < 2; i4++) {
    nsize[i4] = 3.0;
  }

  dilate_flat_real64_tbb(&A->data[0], asize, 2.0, nhood, nsize, 2.0, &B->data[0]);
}

/* End of code generation (imdilate.c) */
