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
#include "createTemplate.h"
#include "imdilate.h"
#include "createTemplate_emxutil.h"
#include "libmwmorphop_ipp.h"

/* Variable Definitions */
static emlrtRSInfo nb_emlrtRSI = { 135,/* lineNo */
  "imdilate",                          /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/images/images/imdilate.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 17, /* lineNo */
  "morphop",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/images/images/+images/+internal/morphop.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 20, /* lineNo */
  "morphop",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/images/images/+images/+internal/+coder/morphop.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 376,/* lineNo */
  "morphop",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/images/images/+images/+internal/+coder/morphop.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 19, /* lineNo */
  "morphop",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/images/images/+images/+internal/+coder/morphop.m"/* pathName */
};

static emlrtRTEInfo d_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "imdilate",                          /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/images/images/imdilate.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 171,/* lineNo */
  28,                                  /* colNo */
  "validateattributes",                /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/lang/validateattributes.m"/* pName */
};

/* Function Definitions */
void imdilate(const emlrtStack *sp, const emxArray_real32_T *A,
              emxArray_real32_T *B)
{
  boolean_T p;
  int32_T i2;
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
  st.site = &nb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &ob_emlrtRSI;
  c_st.site = &rb_emlrtRSI;
  c_st.site = &pb_emlrtRSI;
  p = true;
  i2 = A->size[0] * A->size[1];
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i2 - 1)) {
    if (!muSingleScalarIsNaN(A->data[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrMsgIdAndExplicitTxt(&c_st, &o_emlrtRTEI,
      "MATLAB:imdilate:expectedNonNaN", 43,
      "Expected input number 1, IM, to be non-NaN.");
  }

  for (i2 = 0; i2 < 2; i2++) {
    k = B->size[0] * B->size[1];
    B->size[i2] = A->size[i2];
    emxEnsureCapacity(&b_st, (emxArray__common *)B, k, (int32_T)sizeof(real32_T),
                      &d_emlrtRTEI);
  }

  c_st.site = &qb_emlrtRSI;
  for (i2 = 0; i2 < 2; i2++) {
    asize[i2] = A->size[i2];
  }

  for (i2 = 0; i2 < 9; i2++) {
    nhood[i2] = true;
  }

  for (i2 = 0; i2 < 2; i2++) {
    nsize[i2] = 3.0;
  }

  dilate_real32_ipp(&A->data[0], asize, nhood, nsize, &B->data[0]);
}

/* End of code generation (imdilate.c) */
