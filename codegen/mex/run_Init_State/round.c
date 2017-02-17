/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * round.c
 *
 * Code generation for function 'round'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_Init_State.h"
#include "round.h"
#include "eml_int_forloop_overflow_check.h"

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = { 20,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 10, /* lineNo */
  "round",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elfun/round.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 24, /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

/* Function Definitions */
void b_round(const emlrtStack *sp, emxArray_real32_T *x)
{
  int32_T nx;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[1] << 1;
  b_st.site = &hb_emlrtRSI;
  if ((!(1 > nx)) && (nx > 2147483646)) {
    c_st.site = &v_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = muSingleScalarRound(x->data[k]);
  }
}

/* End of code generation (round.c) */
