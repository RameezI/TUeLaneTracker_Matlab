/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * createTemplate.c
 *
 * Code generation for function 'createTemplate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "createTemplate.h"
#include "createTemplate_emxutil.h"
#include "sub2ind.h"
#include "round.h"
#include "imdilate.h"
#include "createTemplate_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7,     /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 8,   /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 20,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 24,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 27,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 43,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 47,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 50,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 66,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 70,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 73,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 80,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 90,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 94,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 97,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 104, /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 6,   /* lineNo */
  "ReplaceOperators.cpp:195",          /* fcnName */
  "src/ReplaceOperators.cpp:195"       /* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 1,   /* lineNo */
  "dts_colon",                         /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/coder/float2fixed/dtslib/dts_colon.p"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 98,  /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 275, /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 283, /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 20,  /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 100, /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 6,   /* lineNo */
  "ReplaceOperators.cpp:118",          /* fcnName */
  "src/ReplaceOperators.cpp:118"       /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 1,  /* lineNo */
  "dts_binary_op",                     /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/coder/float2fixed/dtslib/dts_binary_op.p"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 68, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 87, /* lineNo */
  "xgemm",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 89, /* lineNo */
  "xgemm",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 90, /* lineNo */
  "xgemm",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 92, /* lineNo */
  "xgemm",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 85, /* lineNo */
  "xgemm",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 16, /* lineNo */
  "sub2ind",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 39, /* lineNo */
  "sub2ind",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 71, /* lineNo */
  "sub2ind",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 4,   /* lineNo */
  23,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 8, /* lineNo */
  5,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 20,/* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 11,/* lineNo */
  13,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  21,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  22,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { 2,   /* nDims */
  23,                                  /* lineNo */
  33,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 34,/* lineNo */
  13,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  44,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  45,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo f_emlrtECI = { 2,   /* nDims */
  46,                                  /* lineNo */
  33,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 57,/* lineNo */
  13,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  67,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  68,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { 2,   /* nDims */
  69,                                  /* lineNo */
  33,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 81,/* lineNo */
  13,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  91,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo k_emlrtECI = { -1,  /* nDims */
  92,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { 2,   /* nDims */
  93,                                  /* lineNo */
  33,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  14,                                  /* colNo */
  "TEMPLATE",                          /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 105,   /* lineNo */
  14,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 1,   /* lineNo */
  1,                                   /* colNo */
  "dts_ones",                          /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/coder/float2fixed/dtslib/dts_ones.p",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 1,   /* lineNo */
  1,                                   /* colNo */
  "dts_ones",                          /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/coder/float2fixed/dtslib/dts_ones.p",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo j_emlrtRTEI = { 381,/* lineNo */
  15,                                  /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtDCInfo d_emlrtDCI = { 1,   /* lineNo */
  1,                                   /* colNo */
  "dts_zeros",                         /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/coder/float2fixed/dtslib/dts_zeros.p",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 1,   /* lineNo */
  1,                                   /* colNo */
  "dts_zeros",                         /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/coder/float2fixed/dtslib/dts_zeros.p",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo k_emlrtRTEI = { 281,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 41,/* lineNo */
  19,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 31,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  33,                                  /* colNo */
  "pixrot",                            /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  9,                                   /* colNo */
  "TEMPLATE",                          /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  33,                                  /* colNo */
  "pixrot",                            /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  9,                                   /* colNo */
  "TEMPLATE",                          /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  33,                                  /* colNo */
  "pixrot",                            /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  9,                                   /* colNo */
  "TEMPLATE",                          /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  33,                                  /* colNo */
  "pixrot",                            /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  9,                                   /* colNo */
  "TEMPLATE",                          /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void createTemplate(const emlrtStack *sp, real32_T H, real32_T W,
                    emxArray_real32_T *TEMPLATE)
{
  real32_T c;
  real32_T b_c;
  real_T ndbl;
  int32_T i0;
  int32_T loop_ub;
  real32_T varargin_3;
  emxArray_real32_T *varargin_1;
  real_T apnd;
  real_T cdiff;
  emxArray_real32_T *varargin_2;
  real_T absa;
  real_T absb;
  int32_T n;
  int32_T nm1d2;
  boolean_T p;
  int32_T k;
  emxArray_real32_T *pix;
  int32_T h;
  emxArray_real32_T *pixrot;
  emxArray_int32_T *r0;
  emxArray_boolean_T *r1;
  emxArray_boolean_T *r2;
  emxArray_int32_T *r3;
  emxArray_real32_T *value;
  emxArray_real32_T *b_pixrot;
  emxArray_real32_T *b_value;
  emxArray_real32_T *c_value;
  real32_T x;
  real32_T rot[4];
  emxArray_real32_T *c_pixrot;
  emxArray_real32_T *d_value;
  emxArray_real32_T *e_value;
  uint32_T unnamed_idx_1;
  int32_T i1;
  emxArray_real32_T *d_pixrot;
  emxArray_real32_T *f_value;
  emxArray_real32_T *g_value;
  int32_T iv0[2];
  int32_T iv1[2];
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  int32_T iv2[2];
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  int32_T iv3[2];
  int32_T iv4[2];
  int32_T iv5[2];
  int32_T iv6[2];
  emxArray_real32_T *e_pixrot;
  int32_T iv7[2];
  emxArray_real32_T *h_value;
  emxArray_real32_T *i_value;
  int32_T iv8[2];
  int32_T iv9[2];
  emxArray_real32_T *j_value;
  int32_T iv10[2];
  int32_T iv11[2];
  int32_T iv12[2];
  int32_T iv13[2];
  int32_T iv14[2];
  int32_T iv15[2];
  int32_T iv16[2];
  int32_T iv17[2];
  int32_T iv18[2];
  int32_T iv19[2];
  int32_T iv20[2];
  int32_T iv21[2];
  int32_T iv22[2];
  int32_T iv23[2];
  int32_T iv24[2];
  int32_T iv25[2];
  int32_T iv26[2];
  int32_T iv27[2];
  int32_T iv28[2];
  uint32_T b_varargin_1[2];
  int32_T iv29[2];
  uint32_T b_varargin_2[2];
  boolean_T b_p;
  boolean_T exitg4;
  int32_T iv30[2];
  int32_T iv31[2];
  boolean_T exitg3;
  boolean_T exitg2;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /*  */
  /*  create edge template%% */
  /*     %% empty template */
  c = 2.0F * H;
  b_c = 2.0F * W;
  st.site = &emlrtRSI;
  ndbl = c + 1.0F;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &b_emlrtDCI, &st);
  }

  ndbl = (real32_T)ndbl;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &c_emlrtDCI, &st);
  }

  ndbl = b_c + 1.0F;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &b_emlrtDCI, &st);
  }

  ndbl = (real32_T)ndbl;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &c_emlrtDCI, &st);
  }

  i0 = TEMPLATE->size[0] * TEMPLATE->size[1];
  TEMPLATE->size[0] = (int32_T)(c + 1.0F);
  TEMPLATE->size[1] = (int32_T)(b_c + 1.0F);
  emxEnsureCapacity(sp, (emxArray__common *)TEMPLATE, i0, (int32_T)sizeof
                    (real32_T), &emlrtRTEI);
  loop_ub = (int32_T)(c + 1.0F) * (int32_T)(b_c + 1.0F);
  for (i0 = 0; i0 < loop_ub; i0++) {
    TEMPLATE->data[i0] = -180.0F;
  }

  b_c = -2.0F * W;
  varargin_3 = 2.0F * W;
  c = 4.0F * W;
  st.site = &b_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  c_st.site = &r_emlrtRSI;
  emxInit_real32_T(&c_st, &varargin_1, 2, &emlrtRTEI, true);
  if (muSingleScalarIsNaN(b_c) || muSingleScalarIsNaN(varargin_3)) {
    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i0, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    varargin_1->data[0] = ((real32_T)rtNaN);
  } else if (varargin_3 < b_c) {
    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = 0;
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i0, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
  } else if ((muSingleScalarIsInf(b_c) || muSingleScalarIsInf(varargin_3)) &&
             (b_c == varargin_3)) {
    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i0, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    varargin_1->data[0] = ((real32_T)rtNaN);
  } else if (muSingleScalarFloor(b_c) == b_c) {
    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = (int32_T)muSingleScalarFloor(varargin_3 - b_c) + 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i0, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = (int32_T)muSingleScalarFloor(varargin_3 - b_c);
    for (i0 = 0; i0 <= loop_ub; i0++) {
      varargin_1->data[varargin_1->size[0] * i0] = b_c + (real32_T)i0;
    }
  } else {
    d_st.site = &s_emlrtRSI;
    ndbl = muDoubleScalarFloor(((real_T)varargin_3 - b_c) + 0.5);
    apnd = b_c + ndbl;
    cdiff = apnd - varargin_3;
    absa = muDoubleScalarAbs(b_c);
    absb = muDoubleScalarAbs(varargin_3);
    if (muDoubleScalarAbs(cdiff) < 2.38418579E-7F * (real32_T)muDoubleScalarMax
        (absa, absb)) {
      ndbl++;
    } else if (cdiff > 0.0) {
      varargin_3 = (real32_T)(b_c + (ndbl - 1.0));
    } else {
      ndbl++;
      varargin_3 = (real32_T)apnd;
    }

    if (ndbl >= 0.0) {
      n = (int32_T)ndbl;
    } else {
      n = 0;
    }

    e_st.site = &t_emlrtRSI;
    if (2.147483647E+9 < ndbl) {
      emlrtErrorWithMessageIdR2012b(&e_st, &j_emlrtRTEI, "Coder:MATLAB:pmaxsize",
        0);
    }

    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = n;
    emxEnsureCapacity(&d_st, (emxArray__common *)varargin_1, i0, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    if (n > 0) {
      varargin_1->data[0] = b_c;
      if (n > 1) {
        varargin_1->data[n - 1] = varargin_3;
        nm1d2 = (n - 1) / 2;
        e_st.site = &u_emlrtRSI;
        for (k = 1; k < nm1d2; k++) {
          varargin_1->data[k] = b_c + (real32_T)k;
          varargin_1->data[(n - k) - 1] = varargin_3 - (real32_T)k;
        }

        if (nm1d2 << 1 == n - 1) {
          varargin_1->data[nm1d2] = (b_c + varargin_3) / 2.0F;
        } else {
          varargin_1->data[nm1d2] = b_c + (real32_T)nm1d2;
          varargin_1->data[nm1d2 + 1] = varargin_3 - (real32_T)nm1d2;
        }
      }
    }
  }

  emxInit_real32_T(&c_st, &varargin_2, 2, &emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  ndbl = c + 1.0F;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &d_emlrtDCI, &st);
  }

  ndbl = (real32_T)ndbl;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &e_emlrtDCI, &st);
  }

  i0 = varargin_2->size[0] * varargin_2->size[1];
  varargin_2->size[0] = 1;
  varargin_2->size[1] = (int32_T)(c + 1.0F);
  emxEnsureCapacity(&st, (emxArray__common *)varargin_2, i0, (int32_T)sizeof
                    (real32_T), &emlrtRTEI);
  loop_ub = (int32_T)(c + 1.0F);
  for (i0 = 0; i0 < loop_ub; i0++) {
    varargin_2->data[i0] = 0.0F;
  }

  st.site = &b_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  p = true;
  if (varargin_1->size[1] != varargin_2->size[1]) {
    p = false;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(&c_st, &k_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real32_T(&c_st, &pix, 2, &b_emlrtRTEI, true);
  i0 = pix->size[0] * pix->size[1];
  pix->size[0] = 2;
  pix->size[1] = varargin_1->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)pix, i0, (int32_T)sizeof(real32_T),
                    &emlrtRTEI);
  loop_ub = varargin_1->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    pix->data[pix->size[0] * i0] = varargin_1->data[varargin_1->size[0] * i0];
  }

  loop_ub = varargin_2->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    pix->data[1 + pix->size[0] * i0] = varargin_2->data[varargin_2->size[0] * i0];
  }

  /*     %% left border */
  c = 2.0F * H;
  i0 = (int32_T)((c + 1.0F) + (1.0F - (H + 1.0F)));
  emlrtForLoopVectorCheckR2012b(H + 1.0F, 1.0, c + 1.0F, mxSINGLE_CLASS, i0,
    &f_emlrtRTEI, sp);
  h = 0;
  emxInit_real32_T(sp, &pixrot, 2, &c_emlrtRTEI, true);
  emxInit_int32_T(sp, &r0, 1, &emlrtRTEI, true);
  emxInit_boolean_T(sp, &r1, 2, &emlrtRTEI, true);
  emxInit_boolean_T(sp, &r2, 2, &emlrtRTEI, true);
  emxInit_int32_T1(sp, &r3, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &value, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &b_pixrot, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &b_value, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &c_value, 2, &emlrtRTEI, true);
  while (h <= i0 - 1) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);

    /*         %% angle */
    x = muSingleScalarAtan((((H + 1.0F) + (real32_T)h) - (H + 1.0F)) / W);

    /*         %% draw in template */
    b_c = muSingleScalarCos(-x);
    varargin_3 = muSingleScalarSin(-x);
    rot[0] = b_c;
    rot[2] = -varargin_3;
    rot[1] = varargin_3;
    rot[3] = b_c;
    st.site = &c_emlrtRSI;
    b_st.site = &y_emlrtRSI;
    c_st.site = &ab_emlrtRSI;
    unnamed_idx_1 = (uint32_T)pix->size[1];
    i1 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = (int32_T)unnamed_idx_1;
    pixrot->size[0] = 2;
    emxEnsureCapacity(&c_st, (emxArray__common *)pixrot, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = pixrot->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i1] = 0.0F;
      }
    }

    d_st.site = &bb_emlrtRSI;
    if (!(pix->size[1] < 1)) {
      e_st.site = &cb_emlrtRSI;
      e_st.site = &cb_emlrtRSI;
      e_st.site = &cb_emlrtRSI;
      e_st.site = &db_emlrtRSI;
      e_st.site = &eb_emlrtRSI;
      e_st.site = &fb_emlrtRSI;
      e_st.site = &gb_emlrtRSI;
      b_c = 1.0F;
      varargin_3 = 0.0F;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)2;
      n_t = (ptrdiff_t)pix->size[1];
      k_t = (ptrdiff_t)2;
      lda_t = (ptrdiff_t)2;
      ldb_t = (ptrdiff_t)2;
      ldc_t = (ptrdiff_t)2;
      sgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &b_c, &rot[0], &lda_t,
            &pix->data[0], &ldb_t, &varargin_3, &pixrot->data[0], &ldc_t);
    }

    loop_ub = pixrot->size[1];
    i1 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r0->data[i1] = i1;
    }

    loop_ub = pixrot->size[1];
    i1 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)varargin_1, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1->data[varargin_1->size[0] * i1] = (pixrot->data[pixrot->size[0]
        * i1] + W) + 1.0F;
    }

    iv0[0] = 1;
    iv0[1] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(iv0, 2, *(int32_T (*)[2])varargin_1->size, 2,
      &emlrtECI, sp);
    loop_ub = varargin_1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      pixrot->data[pixrot->size[0] * r0->data[i1]] = varargin_1->data
        [varargin_1->size[0] * i1];
    }

    loop_ub = pixrot->size[1];
    i1 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r0->data[i1] = i1;
    }

    loop_ub = pixrot->size[1];
    i1 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)varargin_1, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1->data[varargin_1->size[0] * i1] = (pixrot->data[1 +
        pixrot->size[0] * i1] + H) + 1.0F;
    }

    iv2[0] = 1;
    iv2[1] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(iv2, 2, *(int32_T (*)[2])varargin_1->size, 2,
      &b_emlrtECI, sp);
    loop_ub = varargin_1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      pixrot->data[1 + pixrot->size[0] * r0->data[i1]] = varargin_1->
        data[varargin_1->size[0] * i1];
    }

    loop_ub = pixrot->size[1];
    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[r1->size[0] * i1] = (1.0F <= pixrot->data[pixrot->size[0] * i1]);
    }

    c = 2.0F * W;
    loop_ub = pixrot->size[1];
    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[r2->size[0] * i1] = (pixrot->data[pixrot->size[0] * i1] <= c +
        1.0F);
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv5[i1] = r1->size[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv6[i1] = r2->size[i1];
    }

    if ((iv5[0] != iv6[0]) || (iv5[1] != iv6[1])) {
      emlrtSizeEqCheckNDR2012b(&iv5[0], &iv6[0], &c_emlrtECI, sp);
    }

    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    i1 = r1->size[0];
    k = r1->size[1];
    loop_ub = i1 * k;
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[i1] = (r1->data[i1] && r2->data[i1]);
    }

    loop_ub = pixrot->size[1];
    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[r2->size[0] * i1] = (1.0F <= pixrot->data[1 + pixrot->size[0] *
        i1]);
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv10[i1] = r1->size[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv12[i1] = r2->size[i1];
    }

    if ((iv10[0] != iv12[0]) || (iv10[1] != iv12[1])) {
      emlrtSizeEqCheckNDR2012b(&iv10[0], &iv12[0], &c_emlrtECI, sp);
    }

    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    i1 = r1->size[0];
    k = r1->size[1];
    loop_ub = i1 * k;
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[i1] = (r1->data[i1] && r2->data[i1]);
    }

    c = 2.0F * H;
    loop_ub = pixrot->size[1];
    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[r2->size[0] * i1] = (pixrot->data[1 + pixrot->size[0] * i1] <= c
        + 1.0F);
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv16[i1] = r1->size[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv18[i1] = r2->size[i1];
    }

    if ((iv16[0] != iv18[0]) || (iv16[1] != iv18[1])) {
      emlrtSizeEqCheckNDR2012b(&iv16[0], &iv18[0], &c_emlrtECI, sp);
    }

    k = r1->size[1] - 1;
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        nm1d2++;
      }
    }

    i1 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)r3, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        r3->data[nm1d2] = n + 1;
        nm1d2++;
      }
    }

    nm1d2 = pixrot->size[1];
    i1 = b_pixrot->size[0] * b_pixrot->size[1];
    b_pixrot->size[0] = 2;
    b_pixrot->size[1] = r3->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)b_pixrot, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = r3->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (k = 0; k < 2; k++) {
        n = r3->data[r3->size[0] * i1];
        if (!((n >= 1) && (n <= nm1d2))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, nm1d2, &h_emlrtBCI, sp);
        }

        b_pixrot->data[k + b_pixrot->size[0] * i1] = pixrot->data[k +
          pixrot->size[0] * (n - 1)];
      }
    }

    i1 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = b_pixrot->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)pixrot, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = b_pixrot->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i1] = b_pixrot->data[k +
          b_pixrot->size[0] * i1];
      }
    }

    i1 = value->size[0] * value->size[1];
    value->size[0] = 2;
    value->size[1] = pixrot->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)value, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = pixrot->size[0] * pixrot->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      value->data[i1] = pixrot->data[i1];
    }

    st.site = &d_emlrtRSI;
    b_round(&st, value);

    /*         %% get indices of the vanashing line */
    st.site = &e_emlrtRSI;
    loop_ub = value->size[1];
    i1 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_1, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1->data[varargin_1->size[0] * i1] = value->data[1 + value->size[0]
        * i1];
    }

    loop_ub = value->size[1];
    i1 = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_2, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_2->data[varargin_2->size[0] * i1] = value->data[value->size[0] *
        i1];
    }

    b_st.site = &kb_emlrtRSI;
    n = (int32_T)(2.0F * H + 1.0F);
    if (!allinrange(varargin_1, n)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    loop_ub = value->size[1];
    i1 = b_value->size[0] * b_value->size[1];
    b_value->size[0] = 1;
    b_value->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)b_value, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_value->data[b_value->size[0] * i1] = value->data[1 + value->size[0] * i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      b_varargin_1[i1] = (uint32_T)b_value->size[i1];
    }

    loop_ub = value->size[1];
    i1 = c_value->size[0] * c_value->size[1];
    c_value->size[0] = 1;
    c_value->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)c_value, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_value->data[c_value->size[0] * i1] = value->data[value->size[0] * i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      b_varargin_2[i1] = (uint32_T)c_value->size[i1];
    }

    p = false;
    b_p = true;
    k = 0;
    exitg4 = false;
    while ((!exitg4) && (k < 2)) {
      if (!((int32_T)b_varargin_1[k] == (int32_T)b_varargin_2[k])) {
        b_p = false;
        exitg4 = true;
      } else {
        k++;
      }
    }

    if (b_p) {
      p = true;
    }

    if (!p) {
      emlrtErrorWithMessageIdR2012b(&b_st, &m_emlrtRTEI,
        "MATLAB:sub2ind:SubscriptVectorSize", 0);
    }

    c_st.site = &lb_emlrtRSI;
    d_st.site = &mb_emlrtRSI;
    if (!allinrange(varargin_2, (int32_T)(2.0F * W + 1.0F))) {
      emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    /*         %% draw */
    i1 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = varargin_1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r3, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    nm1d2 = TEMPLATE->size[0] * TEMPLATE->size[1];
    loop_ub = varargin_1->size[0] * varargin_1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      k = (int32_T)(real32_T)((int32_T)varargin_1->data[i1] + n * ((int32_T)
        varargin_2->data[i1] - 1));
      if (!((k >= 1) && (k <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, nm1d2, &i_emlrtBCI, sp);
      }

      r3->data[i1] = (int32_T)(real32_T)k;
    }

    b_c = 57.2957802F * x;
    loop_ub = r3->size[0] * r3->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      TEMPLATE->data[r3->data[i1] - 1] = b_c;
    }

    h++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real32_T(&c_value);
  emxFree_real32_T(&b_value);
  emxFree_real32_T(&b_pixrot);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);

  /*     %% bottom border left part */
  i0 = (int32_T)((-1.0F - W) / -1.0F);
  emlrtForLoopVectorCheckR2012b(W, -1.0, 0.0, mxSINGLE_CLASS, i0, &g_emlrtRTEI,
    sp);
  h = 0;
  emxInit_real32_T(sp, &c_pixrot, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &d_value, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &e_value, 2, &emlrtRTEI, true);
  while (h <= i0 - 1) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);

    /*         %% angle */
    x = muSingleScalarAtan((W + -(real32_T)h) / H);

    /*         %% draw in template */
    b_c = muSingleScalarCos(-(1.57079637F - x));
    varargin_3 = muSingleScalarSin(-(1.57079637F - x));
    rot[0] = b_c;
    rot[2] = -varargin_3;
    rot[1] = varargin_3;
    rot[3] = b_c;
    st.site = &f_emlrtRSI;
    b_st.site = &y_emlrtRSI;
    c_st.site = &ab_emlrtRSI;
    unnamed_idx_1 = (uint32_T)pix->size[1];
    i1 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = (int32_T)unnamed_idx_1;
    pixrot->size[0] = 2;
    emxEnsureCapacity(&c_st, (emxArray__common *)pixrot, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = pixrot->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i1] = 0.0F;
      }
    }

    d_st.site = &bb_emlrtRSI;
    if (!(pix->size[1] < 1)) {
      e_st.site = &cb_emlrtRSI;
      e_st.site = &cb_emlrtRSI;
      e_st.site = &cb_emlrtRSI;
      e_st.site = &db_emlrtRSI;
      e_st.site = &eb_emlrtRSI;
      e_st.site = &fb_emlrtRSI;
      e_st.site = &gb_emlrtRSI;
      b_c = 1.0F;
      varargin_3 = 0.0F;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)2;
      n_t = (ptrdiff_t)pix->size[1];
      k_t = (ptrdiff_t)2;
      lda_t = (ptrdiff_t)2;
      ldb_t = (ptrdiff_t)2;
      ldc_t = (ptrdiff_t)2;
      sgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &b_c, &rot[0], &lda_t,
            &pix->data[0], &ldb_t, &varargin_3, &pixrot->data[0], &ldc_t);
    }

    loop_ub = pixrot->size[1];
    i1 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r0->data[i1] = i1;
    }

    loop_ub = pixrot->size[1];
    i1 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)varargin_1, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1->data[varargin_1->size[0] * i1] = (pixrot->data[pixrot->size[0]
        * i1] + W) + 1.0F;
    }

    iv1[0] = 1;
    iv1[1] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(iv1, 2, *(int32_T (*)[2])varargin_1->size, 2,
      &d_emlrtECI, sp);
    loop_ub = varargin_1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      pixrot->data[pixrot->size[0] * r0->data[i1]] = varargin_1->data
        [varargin_1->size[0] * i1];
    }

    loop_ub = pixrot->size[1];
    i1 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r0->data[i1] = i1;
    }

    loop_ub = pixrot->size[1];
    i1 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)varargin_1, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1->data[varargin_1->size[0] * i1] = (pixrot->data[1 +
        pixrot->size[0] * i1] + H) + 1.0F;
    }

    iv4[0] = 1;
    iv4[1] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(iv4, 2, *(int32_T (*)[2])varargin_1->size, 2,
      &e_emlrtECI, sp);
    loop_ub = varargin_1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      pixrot->data[1 + pixrot->size[0] * r0->data[i1]] = varargin_1->
        data[varargin_1->size[0] * i1];
    }

    loop_ub = pixrot->size[1];
    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[r1->size[0] * i1] = (1.0F <= pixrot->data[pixrot->size[0] * i1]);
    }

    c = 2.0F * W;
    loop_ub = pixrot->size[1];
    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[r2->size[0] * i1] = (pixrot->data[pixrot->size[0] * i1] <= c +
        1.0F);
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv8[i1] = r1->size[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv9[i1] = r2->size[i1];
    }

    if ((iv8[0] != iv9[0]) || (iv8[1] != iv9[1])) {
      emlrtSizeEqCheckNDR2012b(&iv8[0], &iv9[0], &f_emlrtECI, sp);
    }

    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    i1 = r1->size[0];
    k = r1->size[1];
    loop_ub = i1 * k;
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[i1] = (r1->data[i1] && r2->data[i1]);
    }

    loop_ub = pixrot->size[1];
    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[r2->size[0] * i1] = (1.0F <= pixrot->data[1 + pixrot->size[0] *
        i1]);
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv14[i1] = r1->size[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv15[i1] = r2->size[i1];
    }

    if ((iv14[0] != iv15[0]) || (iv14[1] != iv15[1])) {
      emlrtSizeEqCheckNDR2012b(&iv14[0], &iv15[0], &f_emlrtECI, sp);
    }

    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    i1 = r1->size[0];
    k = r1->size[1];
    loop_ub = i1 * k;
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[i1] = (r1->data[i1] && r2->data[i1]);
    }

    c = 2.0F * H;
    loop_ub = pixrot->size[1];
    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[r2->size[0] * i1] = (pixrot->data[1 + pixrot->size[0] * i1] <= c
        + 1.0F);
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv21[i1] = r1->size[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv22[i1] = r2->size[i1];
    }

    if ((iv21[0] != iv22[0]) || (iv21[1] != iv22[1])) {
      emlrtSizeEqCheckNDR2012b(&iv21[0], &iv22[0], &f_emlrtECI, sp);
    }

    k = r1->size[1] - 1;
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        nm1d2++;
      }
    }

    i1 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)r3, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        r3->data[nm1d2] = n + 1;
        nm1d2++;
      }
    }

    nm1d2 = pixrot->size[1];
    i1 = c_pixrot->size[0] * c_pixrot->size[1];
    c_pixrot->size[0] = 2;
    c_pixrot->size[1] = r3->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)c_pixrot, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = r3->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (k = 0; k < 2; k++) {
        n = r3->data[r3->size[0] * i1];
        if (!((n >= 1) && (n <= nm1d2))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, nm1d2, &f_emlrtBCI, sp);
        }

        c_pixrot->data[k + c_pixrot->size[0] * i1] = pixrot->data[k +
          pixrot->size[0] * (n - 1)];
      }
    }

    i1 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = c_pixrot->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)pixrot, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = c_pixrot->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i1] = c_pixrot->data[k +
          c_pixrot->size[0] * i1];
      }
    }

    i1 = value->size[0] * value->size[1];
    value->size[0] = 2;
    value->size[1] = pixrot->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)value, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = pixrot->size[0] * pixrot->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      value->data[i1] = pixrot->data[i1];
    }

    st.site = &g_emlrtRSI;
    b_round(&st, value);

    /*         %% get indices of the vanashing line */
    st.site = &h_emlrtRSI;
    loop_ub = value->size[1];
    i1 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_1, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1->data[varargin_1->size[0] * i1] = value->data[1 + value->size[0]
        * i1];
    }

    loop_ub = value->size[1];
    i1 = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_2, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_2->data[varargin_2->size[0] * i1] = value->data[value->size[0] *
        i1];
    }

    b_st.site = &kb_emlrtRSI;
    n = (int32_T)(2.0F * H + 1.0F);
    if (!allinrange(varargin_1, n)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    loop_ub = value->size[1];
    i1 = d_value->size[0] * d_value->size[1];
    d_value->size[0] = 1;
    d_value->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)d_value, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      d_value->data[d_value->size[0] * i1] = value->data[1 + value->size[0] * i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      b_varargin_1[i1] = (uint32_T)d_value->size[i1];
    }

    loop_ub = value->size[1];
    i1 = e_value->size[0] * e_value->size[1];
    e_value->size[0] = 1;
    e_value->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)e_value, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      e_value->data[e_value->size[0] * i1] = value->data[value->size[0] * i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      b_varargin_2[i1] = (uint32_T)e_value->size[i1];
    }

    p = false;
    b_p = true;
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 2)) {
      if (!((int32_T)b_varargin_1[k] == (int32_T)b_varargin_2[k])) {
        b_p = false;
        exitg3 = true;
      } else {
        k++;
      }
    }

    if (b_p) {
      p = true;
    }

    if (!p) {
      emlrtErrorWithMessageIdR2012b(&b_st, &m_emlrtRTEI,
        "MATLAB:sub2ind:SubscriptVectorSize", 0);
    }

    c_st.site = &lb_emlrtRSI;
    d_st.site = &mb_emlrtRSI;
    if (!allinrange(varargin_2, (int32_T)(2.0F * W + 1.0F))) {
      emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    /*         %% draw */
    i1 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = varargin_1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r3, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    nm1d2 = TEMPLATE->size[0] * TEMPLATE->size[1];
    loop_ub = varargin_1->size[0] * varargin_1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      k = (int32_T)(real32_T)((int32_T)varargin_1->data[i1] + n * ((int32_T)
        varargin_2->data[i1] - 1));
      if (!((k >= 1) && (k <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, nm1d2, &g_emlrtBCI, sp);
      }

      r3->data[i1] = (int32_T)(real32_T)k;
    }

    b_c = 57.2957802F * (1.57079637F - x);
    loop_ub = r3->size[0] * r3->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      TEMPLATE->data[r3->data[i1] - 1] = b_c;
    }

    h++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real32_T(&e_value);
  emxFree_real32_T(&d_value);
  emxFree_real32_T(&c_pixrot);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 1, 0);

  /*     %% bottom border rithg part */
  i0 = (int32_T)((-1.0F - W) / -1.0F);
  emlrtForLoopVectorCheckR2012b(W, -1.0, 0.0, mxSINGLE_CLASS, i0, &h_emlrtRTEI,
    sp);
  h = 0;
  emxInit_real32_T(sp, &d_pixrot, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &f_value, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &g_value, 2, &emlrtRTEI, true);
  while (h <= i0 - 1) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);

    /*         %% angle */
    x = muSingleScalarAtan((W + -(real32_T)h) / H);

    /*         %% draw in template */
    b_c = muSingleScalarCos(-(1.57079637F + x));
    varargin_3 = muSingleScalarSin(-(1.57079637F + x));
    rot[0] = b_c;
    rot[2] = -varargin_3;
    rot[1] = varargin_3;
    rot[3] = b_c;
    st.site = &i_emlrtRSI;
    b_st.site = &y_emlrtRSI;
    c_st.site = &ab_emlrtRSI;
    unnamed_idx_1 = (uint32_T)pix->size[1];
    i1 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = (int32_T)unnamed_idx_1;
    pixrot->size[0] = 2;
    emxEnsureCapacity(&c_st, (emxArray__common *)pixrot, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = pixrot->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i1] = 0.0F;
      }
    }

    d_st.site = &bb_emlrtRSI;
    if (!(pix->size[1] < 1)) {
      e_st.site = &cb_emlrtRSI;
      e_st.site = &cb_emlrtRSI;
      e_st.site = &cb_emlrtRSI;
      e_st.site = &db_emlrtRSI;
      e_st.site = &eb_emlrtRSI;
      e_st.site = &fb_emlrtRSI;
      e_st.site = &gb_emlrtRSI;
      b_c = 1.0F;
      varargin_3 = 0.0F;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)2;
      n_t = (ptrdiff_t)pix->size[1];
      k_t = (ptrdiff_t)2;
      lda_t = (ptrdiff_t)2;
      ldb_t = (ptrdiff_t)2;
      ldc_t = (ptrdiff_t)2;
      sgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &b_c, &rot[0], &lda_t,
            &pix->data[0], &ldb_t, &varargin_3, &pixrot->data[0], &ldc_t);
    }

    loop_ub = pixrot->size[1];
    i1 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r0->data[i1] = i1;
    }

    loop_ub = pixrot->size[1];
    i1 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)varargin_1, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1->data[varargin_1->size[0] * i1] = (pixrot->data[pixrot->size[0]
        * i1] + W) + 1.0F;
    }

    iv3[0] = 1;
    iv3[1] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(iv3, 2, *(int32_T (*)[2])varargin_1->size, 2,
      &g_emlrtECI, sp);
    loop_ub = varargin_1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      pixrot->data[pixrot->size[0] * r0->data[i1]] = varargin_1->data
        [varargin_1->size[0] * i1];
    }

    loop_ub = pixrot->size[1];
    i1 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r0->data[i1] = i1;
    }

    loop_ub = pixrot->size[1];
    i1 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)varargin_1, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1->data[varargin_1->size[0] * i1] = (pixrot->data[1 +
        pixrot->size[0] * i1] + H) + 1.0F;
    }

    iv7[0] = 1;
    iv7[1] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(iv7, 2, *(int32_T (*)[2])varargin_1->size, 2,
      &h_emlrtECI, sp);
    loop_ub = varargin_1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      pixrot->data[1 + pixrot->size[0] * r0->data[i1]] = varargin_1->
        data[varargin_1->size[0] * i1];
    }

    loop_ub = pixrot->size[1];
    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[r1->size[0] * i1] = (1.0F <= pixrot->data[pixrot->size[0] * i1]);
    }

    c = 2.0F * W;
    loop_ub = pixrot->size[1];
    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[r2->size[0] * i1] = (pixrot->data[pixrot->size[0] * i1] <= c +
        1.0F);
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv11[i1] = r1->size[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv13[i1] = r2->size[i1];
    }

    if ((iv11[0] != iv13[0]) || (iv11[1] != iv13[1])) {
      emlrtSizeEqCheckNDR2012b(&iv11[0], &iv13[0], &i_emlrtECI, sp);
    }

    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    i1 = r1->size[0];
    k = r1->size[1];
    loop_ub = i1 * k;
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[i1] = (r1->data[i1] && r2->data[i1]);
    }

    loop_ub = pixrot->size[1];
    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[r2->size[0] * i1] = (1.0F <= pixrot->data[1 + pixrot->size[0] *
        i1]);
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv17[i1] = r1->size[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv19[i1] = r2->size[i1];
    }

    if ((iv17[0] != iv19[0]) || (iv17[1] != iv19[1])) {
      emlrtSizeEqCheckNDR2012b(&iv17[0], &iv19[0], &i_emlrtECI, sp);
    }

    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    i1 = r1->size[0];
    k = r1->size[1];
    loop_ub = i1 * k;
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[i1] = (r1->data[i1] && r2->data[i1]);
    }

    c = 2.0F * H;
    loop_ub = pixrot->size[1];
    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[r2->size[0] * i1] = (pixrot->data[1 + pixrot->size[0] * i1] <= c
        + 1.0F);
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv24[i1] = r1->size[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv25[i1] = r2->size[i1];
    }

    if ((iv24[0] != iv25[0]) || (iv24[1] != iv25[1])) {
      emlrtSizeEqCheckNDR2012b(&iv24[0], &iv25[0], &i_emlrtECI, sp);
    }

    k = r1->size[1] - 1;
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        nm1d2++;
      }
    }

    i1 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)r3, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        r3->data[nm1d2] = n + 1;
        nm1d2++;
      }
    }

    nm1d2 = pixrot->size[1];
    i1 = d_pixrot->size[0] * d_pixrot->size[1];
    d_pixrot->size[0] = 2;
    d_pixrot->size[1] = r3->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)d_pixrot, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = r3->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (k = 0; k < 2; k++) {
        n = r3->data[r3->size[0] * i1];
        if (!((n >= 1) && (n <= nm1d2))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, nm1d2, &d_emlrtBCI, sp);
        }

        d_pixrot->data[k + d_pixrot->size[0] * i1] = pixrot->data[k +
          pixrot->size[0] * (n - 1)];
      }
    }

    i1 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = d_pixrot->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)pixrot, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = d_pixrot->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i1] = d_pixrot->data[k +
          d_pixrot->size[0] * i1];
      }
    }

    i1 = value->size[0] * value->size[1];
    value->size[0] = 2;
    value->size[1] = pixrot->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)value, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = pixrot->size[0] * pixrot->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      value->data[i1] = pixrot->data[i1];
    }

    st.site = &j_emlrtRSI;
    b_round(&st, value);

    /*         %% get indices of the vanashing line */
    st.site = &k_emlrtRSI;
    loop_ub = value->size[1];
    i1 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_1, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1->data[varargin_1->size[0] * i1] = value->data[1 + value->size[0]
        * i1];
    }

    loop_ub = value->size[1];
    i1 = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_2, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_2->data[varargin_2->size[0] * i1] = value->data[value->size[0] *
        i1];
    }

    b_st.site = &kb_emlrtRSI;
    n = (int32_T)(2.0F * H + 1.0F);
    if (!allinrange(varargin_1, n)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    loop_ub = value->size[1];
    i1 = f_value->size[0] * f_value->size[1];
    f_value->size[0] = 1;
    f_value->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)f_value, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      f_value->data[f_value->size[0] * i1] = value->data[1 + value->size[0] * i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      b_varargin_1[i1] = (uint32_T)f_value->size[i1];
    }

    loop_ub = value->size[1];
    i1 = g_value->size[0] * g_value->size[1];
    g_value->size[0] = 1;
    g_value->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)g_value, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      g_value->data[g_value->size[0] * i1] = value->data[value->size[0] * i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      b_varargin_2[i1] = (uint32_T)g_value->size[i1];
    }

    p = false;
    b_p = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 2)) {
      if (!((int32_T)b_varargin_1[k] == (int32_T)b_varargin_2[k])) {
        b_p = false;
        exitg2 = true;
      } else {
        k++;
      }
    }

    if (b_p) {
      p = true;
    }

    if (!p) {
      emlrtErrorWithMessageIdR2012b(&b_st, &m_emlrtRTEI,
        "MATLAB:sub2ind:SubscriptVectorSize", 0);
    }

    c_st.site = &lb_emlrtRSI;
    d_st.site = &mb_emlrtRSI;
    if (!allinrange(varargin_2, (int32_T)(2.0F * W + 1.0F))) {
      emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    /*         %% draw */
    i1 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = varargin_1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r3, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    nm1d2 = TEMPLATE->size[0] * TEMPLATE->size[1];
    loop_ub = varargin_1->size[0] * varargin_1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      k = (int32_T)(real32_T)((int32_T)varargin_1->data[i1] + n * ((int32_T)
        varargin_2->data[i1] - 1));
      if (!((k >= 1) && (k <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, nm1d2, &e_emlrtBCI, sp);
      }

      r3->data[i1] = (int32_T)(real32_T)k;
    }

    b_c = 57.2957802F * (1.57079637F + x);
    loop_ub = r3->size[0] * r3->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      TEMPLATE->data[r3->data[i1] - 1] = b_c;
    }

    h++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real32_T(&g_value);
  emxFree_real32_T(&f_value);
  emxFree_real32_T(&d_pixrot);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4U);

  /*     %% right border */
  b_c = -2.0F * W;
  varargin_3 = 2.0F * W;
  c = 4.0F * W;
  st.site = &l_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  c_st.site = &r_emlrtRSI;
  if (muSingleScalarIsNaN(b_c) || muSingleScalarIsNaN(varargin_3)) {
    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i0, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    varargin_1->data[0] = ((real32_T)rtNaN);
  } else if (varargin_3 < b_c) {
    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = 0;
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i0, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
  } else if ((muSingleScalarIsInf(b_c) || muSingleScalarIsInf(varargin_3)) &&
             (b_c == varargin_3)) {
    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i0, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    varargin_1->data[0] = ((real32_T)rtNaN);
  } else if (muSingleScalarFloor(b_c) == b_c) {
    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = (int32_T)muSingleScalarFloor(varargin_3 - b_c) + 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i0, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = (int32_T)muSingleScalarFloor(varargin_3 - b_c);
    for (i0 = 0; i0 <= loop_ub; i0++) {
      varargin_1->data[varargin_1->size[0] * i0] = b_c + (real32_T)i0;
    }
  } else {
    d_st.site = &s_emlrtRSI;
    ndbl = muDoubleScalarFloor(((real_T)varargin_3 - b_c) + 0.5);
    apnd = b_c + ndbl;
    cdiff = apnd - varargin_3;
    absa = muDoubleScalarAbs(b_c);
    absb = muDoubleScalarAbs(varargin_3);
    if (muDoubleScalarAbs(cdiff) < 2.38418579E-7F * (real32_T)muDoubleScalarMax
        (absa, absb)) {
      ndbl++;
    } else if (cdiff > 0.0) {
      varargin_3 = (real32_T)(b_c + (ndbl - 1.0));
    } else {
      ndbl++;
      varargin_3 = (real32_T)apnd;
    }

    if (ndbl >= 0.0) {
      n = (int32_T)ndbl;
    } else {
      n = 0;
    }

    e_st.site = &t_emlrtRSI;
    if (2.147483647E+9 < ndbl) {
      emlrtErrorWithMessageIdR2012b(&e_st, &j_emlrtRTEI, "Coder:MATLAB:pmaxsize",
        0);
    }

    i0 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = n;
    emxEnsureCapacity(&d_st, (emxArray__common *)varargin_1, i0, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    if (n > 0) {
      varargin_1->data[0] = b_c;
      if (n > 1) {
        varargin_1->data[n - 1] = varargin_3;
        nm1d2 = (n - 1) / 2;
        e_st.site = &u_emlrtRSI;
        for (k = 1; k < nm1d2; k++) {
          varargin_1->data[k] = b_c + (real32_T)k;
          varargin_1->data[(n - k) - 1] = varargin_3 - (real32_T)k;
        }

        if (nm1d2 << 1 == n - 1) {
          varargin_1->data[nm1d2] = (b_c + varargin_3) / 2.0F;
        } else {
          varargin_1->data[nm1d2] = b_c + (real32_T)nm1d2;
          varargin_1->data[nm1d2 + 1] = varargin_3 - (real32_T)nm1d2;
        }
      }
    }
  }

  st.site = &l_emlrtRSI;
  ndbl = c + 1.0F;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &d_emlrtDCI, &st);
  }

  ndbl = (real32_T)ndbl;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &e_emlrtDCI, &st);
  }

  i0 = varargin_2->size[0] * varargin_2->size[1];
  varargin_2->size[0] = 1;
  varargin_2->size[1] = (int32_T)(c + 1.0F);
  emxEnsureCapacity(&st, (emxArray__common *)varargin_2, i0, (int32_T)sizeof
                    (real32_T), &emlrtRTEI);
  loop_ub = (int32_T)(c + 1.0F);
  for (i0 = 0; i0 < loop_ub; i0++) {
    varargin_2->data[i0] = 0.0F;
  }

  st.site = &l_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  p = true;
  if (varargin_1->size[1] != varargin_2->size[1]) {
    p = false;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(&c_st, &k_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  i0 = pix->size[0] * pix->size[1];
  pix->size[0] = 2;
  pix->size[1] = varargin_1->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)pix, i0, (int32_T)sizeof(real32_T),
                    &emlrtRTEI);
  loop_ub = varargin_1->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    pix->data[pix->size[0] * i0] = varargin_1->data[varargin_1->size[0] * i0];
  }

  loop_ub = varargin_2->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    pix->data[1 + pix->size[0] * i0] = varargin_2->data[varargin_2->size[0] * i0];
  }

  c = 2.0F * H;
  i0 = (int32_T)((c + 1.0F) + (1.0F - (H + 1.0F)));
  emlrtForLoopVectorCheckR2012b(H + 1.0F, 1.0, c + 1.0F, mxSINGLE_CLASS, i0,
    &i_emlrtRTEI, sp);
  h = 0;
  emxInit_real32_T(sp, &e_pixrot, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &h_value, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &i_value, 2, &emlrtRTEI, true);
  while (h <= i0 - 1) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 5U);

    /*         %% angle */
    x = muSingleScalarAtan((((H + 1.0F) + (real32_T)h) - (H + 1.0F)) / W);

    /*         %% draw in template */
    b_c = muSingleScalarCos(-(3.14159274F - x));
    varargin_3 = muSingleScalarSin(-(3.14159274F - x));
    rot[0] = b_c;
    rot[2] = -varargin_3;
    rot[1] = varargin_3;
    rot[3] = b_c;
    st.site = &m_emlrtRSI;
    b_st.site = &y_emlrtRSI;
    c_st.site = &ab_emlrtRSI;
    unnamed_idx_1 = (uint32_T)pix->size[1];
    i1 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = (int32_T)unnamed_idx_1;
    pixrot->size[0] = 2;
    emxEnsureCapacity(&c_st, (emxArray__common *)pixrot, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = pixrot->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i1] = 0.0F;
      }
    }

    d_st.site = &bb_emlrtRSI;
    if (!(pix->size[1] < 1)) {
      e_st.site = &cb_emlrtRSI;
      e_st.site = &cb_emlrtRSI;
      e_st.site = &cb_emlrtRSI;
      e_st.site = &db_emlrtRSI;
      e_st.site = &eb_emlrtRSI;
      e_st.site = &fb_emlrtRSI;
      e_st.site = &gb_emlrtRSI;
      b_c = 1.0F;
      varargin_3 = 0.0F;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)2;
      n_t = (ptrdiff_t)pix->size[1];
      k_t = (ptrdiff_t)2;
      lda_t = (ptrdiff_t)2;
      ldb_t = (ptrdiff_t)2;
      ldc_t = (ptrdiff_t)2;
      sgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &b_c, &rot[0], &lda_t,
            &pix->data[0], &ldb_t, &varargin_3, &pixrot->data[0], &ldc_t);
    }

    loop_ub = pixrot->size[1];
    i1 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r0->data[i1] = i1;
    }

    loop_ub = pixrot->size[1];
    i1 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)varargin_1, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1->data[varargin_1->size[0] * i1] = (pixrot->data[pixrot->size[0]
        * i1] + W) + 1.0F;
    }

    iv20[0] = 1;
    iv20[1] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(iv20, 2, *(int32_T (*)[2])varargin_1->size, 2,
      &j_emlrtECI, sp);
    loop_ub = varargin_1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      pixrot->data[pixrot->size[0] * r0->data[i1]] = varargin_1->data
        [varargin_1->size[0] * i1];
    }

    loop_ub = pixrot->size[1];
    i1 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r0->data[i1] = i1;
    }

    loop_ub = pixrot->size[1];
    i1 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)varargin_1, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1->data[varargin_1->size[0] * i1] = (pixrot->data[1 +
        pixrot->size[0] * i1] + H) + 1.0F;
    }

    iv23[0] = 1;
    iv23[1] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(iv23, 2, *(int32_T (*)[2])varargin_1->size, 2,
      &k_emlrtECI, sp);
    loop_ub = varargin_1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      pixrot->data[1 + pixrot->size[0] * r0->data[i1]] = varargin_1->
        data[varargin_1->size[0] * i1];
    }

    loop_ub = pixrot->size[1];
    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[r1->size[0] * i1] = (1.0F <= pixrot->data[pixrot->size[0] * i1]);
    }

    c = 2.0F * W;
    loop_ub = pixrot->size[1];
    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[r2->size[0] * i1] = (pixrot->data[pixrot->size[0] * i1] <= c +
        1.0F);
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv26[i1] = r1->size[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv27[i1] = r2->size[i1];
    }

    if ((iv26[0] != iv27[0]) || (iv26[1] != iv27[1])) {
      emlrtSizeEqCheckNDR2012b(&iv26[0], &iv27[0], &l_emlrtECI, sp);
    }

    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    i1 = r1->size[0];
    k = r1->size[1];
    loop_ub = i1 * k;
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[i1] = (r1->data[i1] && r2->data[i1]);
    }

    loop_ub = pixrot->size[1];
    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[r2->size[0] * i1] = (1.0F <= pixrot->data[1 + pixrot->size[0] *
        i1]);
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv28[i1] = r1->size[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv29[i1] = r2->size[i1];
    }

    if ((iv28[0] != iv29[0]) || (iv28[1] != iv29[1])) {
      emlrtSizeEqCheckNDR2012b(&iv28[0], &iv29[0], &l_emlrtECI, sp);
    }

    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    i1 = r1->size[0];
    k = r1->size[1];
    loop_ub = i1 * k;
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[i1] = (r1->data[i1] && r2->data[i1]);
    }

    c = 2.0F * H;
    loop_ub = pixrot->size[1];
    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[r2->size[0] * i1] = (pixrot->data[1 + pixrot->size[0] * i1] <= c
        + 1.0F);
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv30[i1] = r1->size[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv31[i1] = r2->size[i1];
    }

    if ((iv30[0] != iv31[0]) || (iv30[1] != iv31[1])) {
      emlrtSizeEqCheckNDR2012b(&iv30[0], &iv31[0], &l_emlrtECI, sp);
    }

    k = r1->size[1] - 1;
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        nm1d2++;
      }
    }

    i1 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)r3, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        r3->data[nm1d2] = n + 1;
        nm1d2++;
      }
    }

    nm1d2 = pixrot->size[1];
    i1 = e_pixrot->size[0] * e_pixrot->size[1];
    e_pixrot->size[0] = 2;
    e_pixrot->size[1] = r3->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)e_pixrot, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = r3->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (k = 0; k < 2; k++) {
        n = r3->data[r3->size[0] * i1];
        if (!((n >= 1) && (n <= nm1d2))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, nm1d2, &b_emlrtBCI, sp);
        }

        e_pixrot->data[k + e_pixrot->size[0] * i1] = pixrot->data[k +
          pixrot->size[0] * (n - 1)];
      }
    }

    i1 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = e_pixrot->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)pixrot, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = e_pixrot->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i1] = e_pixrot->data[k +
          e_pixrot->size[0] * i1];
      }
    }

    i1 = value->size[0] * value->size[1];
    value->size[0] = 2;
    value->size[1] = pixrot->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)value, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    loop_ub = pixrot->size[0] * pixrot->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      value->data[i1] = pixrot->data[i1];
    }

    st.site = &n_emlrtRSI;
    b_round(&st, value);

    /*         %% get indices of the vanashing line */
    st.site = &o_emlrtRSI;
    loop_ub = value->size[1];
    i1 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_1, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1->data[varargin_1->size[0] * i1] = value->data[1 + value->size[0]
        * i1];
    }

    loop_ub = value->size[1];
    i1 = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_2, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_2->data[varargin_2->size[0] * i1] = value->data[value->size[0] *
        i1];
    }

    b_st.site = &kb_emlrtRSI;
    n = (int32_T)(2.0F * H + 1.0F);
    if (!allinrange(varargin_1, n)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    loop_ub = value->size[1];
    i1 = h_value->size[0] * h_value->size[1];
    h_value->size[0] = 1;
    h_value->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)h_value, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      h_value->data[h_value->size[0] * i1] = value->data[1 + value->size[0] * i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      b_varargin_1[i1] = (uint32_T)h_value->size[i1];
    }

    loop_ub = value->size[1];
    i1 = i_value->size[0] * i_value->size[1];
    i_value->size[0] = 1;
    i_value->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)i_value, i1, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      i_value->data[i_value->size[0] * i1] = value->data[value->size[0] * i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      b_varargin_2[i1] = (uint32_T)i_value->size[i1];
    }

    p = false;
    b_p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!((int32_T)b_varargin_1[k] == (int32_T)b_varargin_2[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    if (b_p) {
      p = true;
    }

    if (!p) {
      emlrtErrorWithMessageIdR2012b(&b_st, &m_emlrtRTEI,
        "MATLAB:sub2ind:SubscriptVectorSize", 0);
    }

    c_st.site = &lb_emlrtRSI;
    d_st.site = &mb_emlrtRSI;
    if (!allinrange(varargin_2, (int32_T)(2.0F * W + 1.0F))) {
      emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    /*         %% draw */
    i1 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = varargin_1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r3, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    nm1d2 = TEMPLATE->size[0] * TEMPLATE->size[1];
    loop_ub = varargin_1->size[0] * varargin_1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      k = (int32_T)(real32_T)((int32_T)varargin_1->data[i1] + n * ((int32_T)
        varargin_2->data[i1] - 1));
      if (!((k >= 1) && (k <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, nm1d2, &c_emlrtBCI, sp);
      }

      r3->data[i1] = (int32_T)(real32_T)k;
    }

    b_c = 57.2957802F * (3.14159274F - x);
    loop_ub = r3->size[0] * r3->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      TEMPLATE->data[r3->data[i1] - 1] = b_c;
    }

    h++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real32_T(&i_value);
  emxFree_real32_T(&h_value);
  emxFree_real32_T(&e_pixrot);
  emxFree_real32_T(&value);
  emxFree_real32_T(&varargin_2);
  emxFree_real32_T(&varargin_1);
  emxFree_int32_T(&r3);
  emxFree_boolean_T(&r2);
  emxFree_boolean_T(&r1);
  emxFree_int32_T(&r0);
  emxFree_real32_T(&pixrot);
  emxFree_real32_T(&pix);
  emxInit_real32_T(sp, &j_value, 2, &emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);

  /*     %% fill in holes */
  st.site = &p_emlrtRSI;
  imdilate(&st, TEMPLATE, j_value);
  i0 = TEMPLATE->size[0] * TEMPLATE->size[1];
  TEMPLATE->size[0] = j_value->size[0];
  TEMPLATE->size[1] = j_value->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)TEMPLATE, i0, (int32_T)sizeof
                    (real32_T), &emlrtRTEI);
  loop_ub = j_value->size[0] * j_value->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    TEMPLATE->data[i0] = j_value->data[i0];
  }

  if (1.0F > H + 2.0F) {
    loop_ub = 0;
  } else {
    i0 = j_value->size[0];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &emlrtBCI, sp);
    }

    ndbl = H + 2.0F;
    if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
      emlrtIntegerCheckR2012b(ndbl, &emlrtDCI, sp);
    }

    i0 = j_value->size[0];
    i1 = (int32_T)(real32_T)ndbl;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &emlrtBCI, sp);
    }

    loop_ub = (int32_T)(real32_T)i1;
  }

  nm1d2 = j_value->size[1];
  emxFree_real32_T(&j_value);
  for (i0 = 0; i0 < nm1d2; i0++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      TEMPLATE->data[i1 + TEMPLATE->size[0] * i0] = -180.0F;
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (createTemplate.c) */
