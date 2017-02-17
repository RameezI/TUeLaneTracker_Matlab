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
#include "run_Init_State.h"
#include "createTemplate.h"
#include "run_Init_State_emxutil.h"
#include "sub2ind.h"
#include "round.h"
#include "imdilate.h"
#include "run_Init_State_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo c_emlrtRSI = { 12,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 24,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 28,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 31,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 47,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 51,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 54,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 70,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 74,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 77,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 84,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 94,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 98,  /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 101, /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 108, /* lineNo */
  "createTemplate",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 25,  /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
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

static emlrtRSInfo y_emlrtRSI = { 68,  /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 87, /* lineNo */
  "xgemm",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 89, /* lineNo */
  "xgemm",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 90, /* lineNo */
  "xgemm",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 92, /* lineNo */
  "xgemm",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 85, /* lineNo */
  "xgemm",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 10, /* lineNo */
  "int",                               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/+blas/int.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 16, /* lineNo */
  "sub2ind",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 39, /* lineNo */
  "sub2ind",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 71, /* lineNo */
  "sub2ind",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRTEInfo e_emlrtRTEI = { 8, /* lineNo */
  23,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 12,/* lineNo */
  5,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 24,/* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtDCInfo ab_emlrtDCI = { 11, /* lineNo */
  29,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 11, /* lineNo */
  29,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = { 11, /* lineNo */
  36,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo db_emlrtDCI = { 11, /* lineNo */
  36,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = { 12, /* lineNo */
  34,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = { 12, /* lineNo */
  34,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo l_emlrtRTEI = { 15,/* lineNo */
  13,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  25,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  26,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { 2,   /* nDims */
  27,                                  /* lineNo */
  33,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 38,/* lineNo */
  13,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  48,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  49,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo f_emlrtECI = { 2,   /* nDims */
  50,                                  /* lineNo */
  33,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 61,/* lineNo */
  13,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  71,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  72,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { 2,   /* nDims */
  73,                                  /* lineNo */
  33,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtDCInfo gb_emlrtDCI = { 84, /* lineNo */
  29,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo hb_emlrtDCI = { 84, /* lineNo */
  29,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo o_emlrtRTEI = { 85,/* lineNo */
  13,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  95,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo k_emlrtECI = { -1,  /* nDims */
  96,                                  /* lineNo */
  9,                                   /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { 2,   /* nDims */
  97,                                  /* lineNo */
  33,                                  /* colNo */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m"/* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  14,                                  /* colNo */
  "TEMPLATE",                          /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo p_emlrtRTEI = { 381,/* lineNo */
  15,                                  /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 281,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 41,/* lineNo */
  19,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 31,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  33,                                  /* colNo */
  "pixrot",                            /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  9,                                   /* colNo */
  "TEMPLATE",                          /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  33,                                  /* colNo */
  "pixrot",                            /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  9,                                   /* colNo */
  "TEMPLATE",                          /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  33,                                  /* colNo */
  "pixrot",                            /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  9,                                   /* colNo */
  "TEMPLATE",                          /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  33,                                  /* colNo */
  "pixrot",                            /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  9,                                   /* colNo */
  "TEMPLATE",                          /* aName */
  "createTemplate",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void createTemplate(const emlrtStack *sp, real32_T H, real32_T W,
                    emxArray_real_T *TEMPLATE)
{
  real32_T y;
  real32_T cs;
  real_T ndbl;
  int32_T i2;
  int32_T loop_ub;
  real32_T sn;
  emxArray_real32_T *varargin_1;
  real_T apnd;
  real_T cdiff;
  real_T absa;
  real_T absb;
  int32_T n;
  boolean_T p;
  emxArray_real32_T *pix;
  int32_T nm1d2;
  int32_T k;
  int32_T h;
  emxArray_real32_T *pixrot;
  emxArray_int32_T *r0;
  emxArray_boolean_T *r1;
  emxArray_boolean_T *r2;
  emxArray_int32_T *r3;
  emxArray_real32_T *varargin_2;
  emxArray_real32_T *b_pixrot;
  emxArray_real32_T *c_pixrot;
  emxArray_real32_T *d_pixrot;
  emxArray_real32_T *e_pixrot;
  emxArray_real32_T *f_pixrot;
  emxArray_real32_T *g_pixrot;
  emxArray_real32_T *h_pixrot;
  real32_T an;
  real32_T rot[4];
  emxArray_real32_T *i_pixrot;
  uint32_T unnamed_idx_1;
  emxArray_real32_T *j_pixrot;
  int32_T i3;
  emxArray_real32_T *k_pixrot;
  emxArray_real32_T *l_pixrot;
  emxArray_real32_T *m_pixrot;
  emxArray_real32_T *n_pixrot;
  emxArray_real32_T *o_pixrot;
  int32_T iv0[2];
  emxArray_real32_T *p_pixrot;
  emxArray_real32_T *q_pixrot;
  emxArray_real32_T *r_pixrot;
  emxArray_real32_T *s_pixrot;
  emxArray_real32_T *t_pixrot;
  emxArray_real32_T *u_pixrot;
  emxArray_real32_T *v_pixrot;
  int32_T w_pixrot[2];
  int32_T iv1[2];
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  int32_T iv2[2];
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  int32_T iv3[2];
  int32_T iv4[2];
  emxArray_real32_T *x_pixrot;
  emxArray_real32_T *y_pixrot;
  emxArray_real32_T *ab_pixrot;
  emxArray_real32_T *bb_pixrot;
  int32_T iv5[2];
  emxArray_real32_T *cb_pixrot;
  emxArray_real32_T *db_pixrot;
  emxArray_real32_T *eb_pixrot;
  int32_T iv6[2];
  int32_T iv7[2];
  emxArray_real_T *b_TEMPLATE;
  int32_T iv8[2];
  int32_T iv9[2];
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
  uint32_T b_varargin_1[2];
  uint32_T b_varargin_2[2];
  boolean_T b_p;
  boolean_T exitg4;
  int32_T iv28[2];
  int32_T iv29[2];
  boolean_T exitg3;
  int32_T iv30[2];
  int32_T iv31[2];
  boolean_T exitg2;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 1U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 0U);

  /*  */
  /*  */
  /*  */
  /*  create edge template */
  /*  */
  /*  */
  /*  */
  /*     %% empty template */
  y = 2.0F * H;
  cs = 2.0F * W;
  ndbl = y + 1.0F;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &ab_emlrtDCI, sp);
  }

  ndbl = (real32_T)ndbl;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &bb_emlrtDCI, sp);
  }

  ndbl = cs + 1.0F;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &cb_emlrtDCI, sp);
  }

  ndbl = (real32_T)ndbl;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &db_emlrtDCI, sp);
  }

  i2 = TEMPLATE->size[0] * TEMPLATE->size[1];
  TEMPLATE->size[0] = (int32_T)(y + 1.0F);
  TEMPLATE->size[1] = (int32_T)(cs + 1.0F);
  emxEnsureCapacity(sp, (emxArray__common *)TEMPLATE, i2, (int32_T)sizeof(real_T),
                    &e_emlrtRTEI);
  loop_ub = (int32_T)(y + 1.0F) * (int32_T)(cs + 1.0F);
  for (i2 = 0; i2 < loop_ub; i2++) {
    TEMPLATE->data[i2] = -180.0;
  }

  cs = -2.0F * W;
  sn = 2.0F * W;
  st.site = &c_emlrtRSI;
  b_st.site = &r_emlrtRSI;
  emxInit_real32_T(&b_st, &varargin_1, 2, &e_emlrtRTEI, true);
  if (sn < cs) {
    i2 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)varargin_1, i2, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
  } else if (cs == cs) {
    i2 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = (int32_T)muSingleScalarFloor(sn - cs) + 1;
    emxEnsureCapacity(&b_st, (emxArray__common *)varargin_1, i2, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = (int32_T)muSingleScalarFloor(sn - cs);
    for (i2 = 0; i2 <= loop_ub; i2++) {
      varargin_1->data[varargin_1->size[0] * i2] = cs + (real32_T)i2;
    }
  } else {
    c_st.site = &s_emlrtRSI;
    ndbl = muDoubleScalarFloor(((real_T)sn - cs) + 0.5);
    apnd = cs + ndbl;
    cdiff = apnd - sn;
    absa = muDoubleScalarAbs(cs);
    absb = muDoubleScalarAbs(sn);
    if (muDoubleScalarAbs(cdiff) < 2.38418579E-7F * (real32_T)muDoubleScalarMax
        (absa, absb)) {
      ndbl++;
    } else if (cdiff > 0.0) {
      sn = (real32_T)(cs + (ndbl - 1.0));
    } else {
      ndbl++;
      sn = (real32_T)apnd;
    }

    if (ndbl >= 0.0) {
      n = (int32_T)ndbl;
    } else {
      n = 0;
    }

    d_st.site = &t_emlrtRSI;
    if (2.147483647E+9 < ndbl) {
      emlrtErrorWithMessageIdR2012b(&d_st, &p_emlrtRTEI, "Coder:MATLAB:pmaxsize",
        0);
    }

    i2 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = n;
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i2, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    if (n > 0) {
      varargin_1->data[0] = cs;
      if (n > 1) {
        varargin_1->data[n - 1] = sn;
        nm1d2 = (n - 1) / 2;
        d_st.site = &u_emlrtRSI;
        for (k = 1; k < nm1d2; k++) {
          varargin_1->data[k] = cs + (real32_T)k;
          varargin_1->data[(n - k) - 1] = sn - (real32_T)k;
        }

        if (nm1d2 << 1 == n - 1) {
          varargin_1->data[nm1d2] = (cs + sn) / 2.0F;
        } else {
          varargin_1->data[nm1d2] = cs + (real32_T)nm1d2;
          varargin_1->data[nm1d2 + 1] = sn - (real32_T)nm1d2;
        }
      }
    }
  }

  y = 4.0F * W;
  ndbl = y + 1.0F;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &eb_emlrtDCI, sp);
  }

  ndbl = (real32_T)ndbl;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &fb_emlrtDCI, sp);
  }

  st.site = &c_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  p = true;
  if (varargin_1->size[1] != (int32_T)(y + 1.0F)) {
    p = false;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(&c_st, &q_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real32_T(&c_st, &pix, 2, &f_emlrtRTEI, true);
  i2 = pix->size[0] * pix->size[1];
  pix->size[0] = 2;
  pix->size[1] = varargin_1->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)pix, i2, (int32_T)sizeof(real32_T),
                    &e_emlrtRTEI);
  loop_ub = varargin_1->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    pix->data[pix->size[0] * i2] = varargin_1->data[varargin_1->size[0] * i2];
  }

  loop_ub = (int32_T)(y + 1.0F);
  for (i2 = 0; i2 < loop_ub; i2++) {
    pix->data[1 + pix->size[0] * i2] = 0.0F;
  }

  /*     %% left border */
  y = 2.0F * H;
  i2 = (int32_T)((y + 1.0F) + (1.0F - (H + 1.0F)));
  emlrtForLoopVectorCheckR2012b(H + 1.0F, 1.0, y + 1.0F, mxSINGLE_CLASS, i2,
    &l_emlrtRTEI, sp);
  h = 0;
  emxInit_real32_T(sp, &pixrot, 2, &g_emlrtRTEI, true);
  emxInit_int32_T(sp, &r0, 1, &e_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r1, 2, &e_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r2, 2, &e_emlrtRTEI, true);
  emxInit_int32_T1(sp, &r3, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &varargin_2, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &b_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &c_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &d_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &e_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &f_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &g_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &h_pixrot, 2, &e_emlrtRTEI, true);
  while (h <= i2 - 1) {
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 1U);

    /*         %% angle */
    an = muSingleScalarAtan((((H + 1.0F) + (real32_T)h) - (H + 1.0F)) / W);

    /*         %% draw in template */
    cs = muSingleScalarCos(-an);
    sn = muSingleScalarSin(-an);
    rot[0] = cs;
    rot[2] = -sn;
    rot[1] = sn;
    rot[3] = cs;
    st.site = &d_emlrtRSI;
    unnamed_idx_1 = (uint32_T)pix->size[1];
    i3 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = (int32_T)unnamed_idx_1;
    pixrot->size[0] = 2;
    emxEnsureCapacity(&st, (emxArray__common *)pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i3] = 0.0F;
      }
    }

    b_st.site = &y_emlrtRSI;
    if (!(pix->size[1] < 1)) {
      c_st.site = &ab_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &ab_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &ab_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &bb_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &cb_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &db_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &eb_emlrtRSI;
      cs = 1.0F;
      sn = 0.0F;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)2;
      n_t = (ptrdiff_t)pix->size[1];
      k_t = (ptrdiff_t)2;
      lda_t = (ptrdiff_t)2;
      ldb_t = (ptrdiff_t)2;
      ldc_t = (ptrdiff_t)2;
      sgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &cs, &rot[0], &lda_t, &pix->
            data[0], &ldb_t, &sn, &pixrot->data[0], &ldc_t);
    }

    loop_ub = pixrot->size[1];
    i3 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r0->data[i3] = i3;
    }

    iv0[0] = 1;
    iv0[1] = r0->size[0];
    loop_ub = pixrot->size[1];
    i3 = b_pixrot->size[0] * b_pixrot->size[1];
    b_pixrot->size[0] = 1;
    b_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)b_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      b_pixrot->data[b_pixrot->size[0] * i3] = pixrot->data[pixrot->size[0] * i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      w_pixrot[i3] = b_pixrot->size[i3];
    }

    emlrtSubAssignSizeCheckR2012b(iv0, 2, w_pixrot, 2, &emlrtECI, sp);
    nm1d2 = pixrot->size[1];
    i3 = c_pixrot->size[0] * c_pixrot->size[1];
    c_pixrot->size[0] = 1;
    c_pixrot->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)c_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < nm1d2; i3++) {
      c_pixrot->data[c_pixrot->size[0] * i3] = (pixrot->data[pixrot->size[0] *
        i3] + W) + 1.0F;
    }

    loop_ub = c_pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      pixrot->data[pixrot->size[0] * r0->data[i3]] = c_pixrot->data
        [c_pixrot->size[0] * i3];
    }

    loop_ub = pixrot->size[1];
    i3 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r0->data[i3] = i3;
    }

    iv2[0] = 1;
    iv2[1] = r0->size[0];
    loop_ub = pixrot->size[1];
    i3 = d_pixrot->size[0] * d_pixrot->size[1];
    d_pixrot->size[0] = 1;
    d_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)d_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      d_pixrot->data[d_pixrot->size[0] * i3] = pixrot->data[1 + pixrot->size[0] *
        i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      w_pixrot[i3] = d_pixrot->size[i3];
    }

    emlrtSubAssignSizeCheckR2012b(iv2, 2, w_pixrot, 2, &b_emlrtECI, sp);
    nm1d2 = pixrot->size[1];
    i3 = e_pixrot->size[0] * e_pixrot->size[1];
    e_pixrot->size[0] = 1;
    e_pixrot->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)e_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < nm1d2; i3++) {
      e_pixrot->data[e_pixrot->size[0] * i3] = (pixrot->data[1 + pixrot->size[0]
        * i3] + H) + 1.0F;
    }

    loop_ub = e_pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      pixrot->data[1 + pixrot->size[0] * r0->data[i3]] = e_pixrot->data
        [e_pixrot->size[0] * i3];
    }

    loop_ub = pixrot->size[1];
    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r1->data[r1->size[0] * i3] = (1.0F <= pixrot->data[pixrot->size[0] * i3]);
    }

    y = 2.0F * W;
    loop_ub = pixrot->size[1];
    i3 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r2->data[r2->size[0] * i3] = (pixrot->data[pixrot->size[0] * i3] <= y +
        1.0F);
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv5[i3] = r1->size[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv6[i3] = r2->size[i3];
    }

    if ((iv5[0] != iv6[0]) || (iv5[1] != iv6[1])) {
      emlrtSizeEqCheckNDR2012b(&iv5[0], &iv6[0], &c_emlrtECI, sp);
    }

    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    i3 = r1->size[0];
    k = r1->size[1];
    loop_ub = i3 * k;
    for (i3 = 0; i3 < loop_ub; i3++) {
      r1->data[i3] = (r1->data[i3] && r2->data[i3]);
    }

    loop_ub = pixrot->size[1];
    i3 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r2->data[r2->size[0] * i3] = (1.0F <= pixrot->data[1 + pixrot->size[0] *
        i3]);
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv9[i3] = r1->size[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv11[i3] = r2->size[i3];
    }

    if ((iv9[0] != iv11[0]) || (iv9[1] != iv11[1])) {
      emlrtSizeEqCheckNDR2012b(&iv9[0], &iv11[0], &c_emlrtECI, sp);
    }

    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    i3 = r1->size[0];
    k = r1->size[1];
    loop_ub = i3 * k;
    for (i3 = 0; i3 < loop_ub; i3++) {
      r1->data[i3] = (r1->data[i3] && r2->data[i3]);
    }

    y = 2.0F * H;
    loop_ub = pixrot->size[1];
    i3 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r2->data[r2->size[0] * i3] = (pixrot->data[1 + pixrot->size[0] * i3] <= y
        + 1.0F);
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv16[i3] = r1->size[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv18[i3] = r2->size[i3];
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

    i3 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)r3, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        r3->data[nm1d2] = n + 1;
        nm1d2++;
      }
    }

    nm1d2 = pixrot->size[1];
    i3 = f_pixrot->size[0] * f_pixrot->size[1];
    f_pixrot->size[0] = 2;
    f_pixrot->size[1] = r3->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)f_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = r3->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (k = 0; k < 2; k++) {
        n = r3->data[r3->size[0] * i3];
        if (!((n >= 1) && (n <= nm1d2))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, nm1d2, &l_emlrtBCI, sp);
        }

        f_pixrot->data[k + f_pixrot->size[0] * i3] = pixrot->data[k +
          pixrot->size[0] * (n - 1)];
      }
    }

    i3 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = f_pixrot->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = f_pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i3] = f_pixrot->data[k +
          f_pixrot->size[0] * i3];
      }
    }

    st.site = &e_emlrtRSI;
    b_round(&st, pixrot);

    /*         %% get indices of the vanashing line */
    st.site = &f_emlrtRSI;
    loop_ub = pixrot->size[1];
    i3 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_1, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      varargin_1->data[varargin_1->size[0] * i3] = pixrot->data[1 + pixrot->
        size[0] * i3];
    }

    loop_ub = pixrot->size[1];
    i3 = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_2, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      varargin_2->data[varargin_2->size[0] * i3] = pixrot->data[pixrot->size[0] *
        i3];
    }

    b_st.site = &ib_emlrtRSI;
    n = (int32_T)(2.0F * H + 1.0F);
    if (!allinrange(varargin_1, n)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    loop_ub = pixrot->size[1];
    i3 = g_pixrot->size[0] * g_pixrot->size[1];
    g_pixrot->size[0] = 1;
    g_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)g_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      g_pixrot->data[g_pixrot->size[0] * i3] = pixrot->data[1 + pixrot->size[0] *
        i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      b_varargin_1[i3] = (uint32_T)g_pixrot->size[i3];
    }

    loop_ub = pixrot->size[1];
    i3 = h_pixrot->size[0] * h_pixrot->size[1];
    h_pixrot->size[0] = 1;
    h_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)h_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      h_pixrot->data[h_pixrot->size[0] * i3] = pixrot->data[pixrot->size[0] * i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      b_varargin_2[i3] = (uint32_T)h_pixrot->size[i3];
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
      emlrtErrorWithMessageIdR2012b(&b_st, &s_emlrtRTEI,
        "MATLAB:sub2ind:SubscriptVectorSize", 0);
    }

    c_st.site = &jb_emlrtRSI;
    d_st.site = &kb_emlrtRSI;
    if (!allinrange(varargin_2, (int32_T)(2.0F * W + 1.0F))) {
      emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    /*         %% draw */
    i3 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = varargin_1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r3, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    nm1d2 = TEMPLATE->size[0] * TEMPLATE->size[1];
    loop_ub = varargin_1->size[0] * varargin_1->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      k = (int32_T)varargin_1->data[i3] + n * ((int32_T)varargin_2->data[i3] - 1);
      if (!((k >= 1) && (k <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, nm1d2, &m_emlrtBCI, sp);
      }

      r3->data[i3] = k;
    }

    cs = 57.2957802F * an;
    loop_ub = r3->size[0] * r3->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      TEMPLATE->data[r3->data[i3] - 1] = cs;
    }

    h++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real32_T(&h_pixrot);
  emxFree_real32_T(&g_pixrot);
  emxFree_real32_T(&f_pixrot);
  emxFree_real32_T(&e_pixrot);
  emxFree_real32_T(&d_pixrot);
  emxFree_real32_T(&c_pixrot);
  emxFree_real32_T(&b_pixrot);
  covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 0, 0);

  /*     %% bottom border left part */
  i2 = (int32_T)((-1.0F - W) / -1.0F);
  emlrtForLoopVectorCheckR2012b(W, -1.0, 0.0, mxSINGLE_CLASS, i2, &m_emlrtRTEI,
    sp);
  h = 0;
  emxInit_real32_T(sp, &i_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &j_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &k_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &l_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &m_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &n_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &o_pixrot, 2, &e_emlrtRTEI, true);
  while (h <= i2 - 1) {
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 2U);

    /*         %% angle */
    y = (W + -(real32_T)h) / H;
    an = 1.57079637F - muSingleScalarAtan(y);

    /*         %% draw in template */
    cs = muSingleScalarCos(-an);
    sn = muSingleScalarSin(-an);
    rot[0] = cs;
    rot[2] = -sn;
    rot[1] = sn;
    rot[3] = cs;
    st.site = &g_emlrtRSI;
    unnamed_idx_1 = (uint32_T)pix->size[1];
    i3 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = (int32_T)unnamed_idx_1;
    pixrot->size[0] = 2;
    emxEnsureCapacity(&st, (emxArray__common *)pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i3] = 0.0F;
      }
    }

    b_st.site = &y_emlrtRSI;
    if (!(pix->size[1] < 1)) {
      c_st.site = &ab_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &ab_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &ab_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &bb_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &cb_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &db_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &eb_emlrtRSI;
      cs = 1.0F;
      sn = 0.0F;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)2;
      n_t = (ptrdiff_t)pix->size[1];
      k_t = (ptrdiff_t)2;
      lda_t = (ptrdiff_t)2;
      ldb_t = (ptrdiff_t)2;
      ldc_t = (ptrdiff_t)2;
      sgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &cs, &rot[0], &lda_t, &pix->
            data[0], &ldb_t, &sn, &pixrot->data[0], &ldc_t);
    }

    loop_ub = pixrot->size[1];
    i3 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r0->data[i3] = i3;
    }

    iv1[0] = 1;
    iv1[1] = r0->size[0];
    loop_ub = pixrot->size[1];
    i3 = i_pixrot->size[0] * i_pixrot->size[1];
    i_pixrot->size[0] = 1;
    i_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)i_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      i_pixrot->data[i_pixrot->size[0] * i3] = pixrot->data[pixrot->size[0] * i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      w_pixrot[i3] = i_pixrot->size[i3];
    }

    emlrtSubAssignSizeCheckR2012b(iv1, 2, w_pixrot, 2, &d_emlrtECI, sp);
    nm1d2 = pixrot->size[1];
    i3 = j_pixrot->size[0] * j_pixrot->size[1];
    j_pixrot->size[0] = 1;
    j_pixrot->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)j_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < nm1d2; i3++) {
      j_pixrot->data[j_pixrot->size[0] * i3] = (pixrot->data[pixrot->size[0] *
        i3] + W) + 1.0F;
    }

    loop_ub = j_pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      pixrot->data[pixrot->size[0] * r0->data[i3]] = j_pixrot->data
        [j_pixrot->size[0] * i3];
    }

    loop_ub = pixrot->size[1];
    i3 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r0->data[i3] = i3;
    }

    iv4[0] = 1;
    iv4[1] = r0->size[0];
    loop_ub = pixrot->size[1];
    i3 = k_pixrot->size[0] * k_pixrot->size[1];
    k_pixrot->size[0] = 1;
    k_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)k_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      k_pixrot->data[k_pixrot->size[0] * i3] = pixrot->data[1 + pixrot->size[0] *
        i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      w_pixrot[i3] = k_pixrot->size[i3];
    }

    emlrtSubAssignSizeCheckR2012b(iv4, 2, w_pixrot, 2, &e_emlrtECI, sp);
    nm1d2 = pixrot->size[1];
    i3 = l_pixrot->size[0] * l_pixrot->size[1];
    l_pixrot->size[0] = 1;
    l_pixrot->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)l_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < nm1d2; i3++) {
      l_pixrot->data[l_pixrot->size[0] * i3] = (pixrot->data[1 + pixrot->size[0]
        * i3] + H) + 1.0F;
    }

    loop_ub = l_pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      pixrot->data[1 + pixrot->size[0] * r0->data[i3]] = l_pixrot->data
        [l_pixrot->size[0] * i3];
    }

    loop_ub = pixrot->size[1];
    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r1->data[r1->size[0] * i3] = (1.0F <= pixrot->data[pixrot->size[0] * i3]);
    }

    cs = 2.0F * W;
    loop_ub = pixrot->size[1];
    i3 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r2->data[r2->size[0] * i3] = (pixrot->data[pixrot->size[0] * i3] <= cs +
        1.0F);
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv8[i3] = r1->size[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv10[i3] = r2->size[i3];
    }

    if ((iv8[0] != iv10[0]) || (iv8[1] != iv10[1])) {
      emlrtSizeEqCheckNDR2012b(&iv8[0], &iv10[0], &f_emlrtECI, sp);
    }

    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    i3 = r1->size[0];
    k = r1->size[1];
    loop_ub = i3 * k;
    for (i3 = 0; i3 < loop_ub; i3++) {
      r1->data[i3] = (r1->data[i3] && r2->data[i3]);
    }

    loop_ub = pixrot->size[1];
    i3 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r2->data[r2->size[0] * i3] = (1.0F <= pixrot->data[1 + pixrot->size[0] *
        i3]);
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv14[i3] = r1->size[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv17[i3] = r2->size[i3];
    }

    if ((iv14[0] != iv17[0]) || (iv14[1] != iv17[1])) {
      emlrtSizeEqCheckNDR2012b(&iv14[0], &iv17[0], &f_emlrtECI, sp);
    }

    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    i3 = r1->size[0];
    k = r1->size[1];
    loop_ub = i3 * k;
    for (i3 = 0; i3 < loop_ub; i3++) {
      r1->data[i3] = (r1->data[i3] && r2->data[i3]);
    }

    cs = 2.0F * H;
    loop_ub = pixrot->size[1];
    i3 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r2->data[r2->size[0] * i3] = (pixrot->data[1 + pixrot->size[0] * i3] <= cs
        + 1.0F);
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv22[i3] = r1->size[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv23[i3] = r2->size[i3];
    }

    if ((iv22[0] != iv23[0]) || (iv22[1] != iv23[1])) {
      emlrtSizeEqCheckNDR2012b(&iv22[0], &iv23[0], &f_emlrtECI, sp);
    }

    k = r1->size[1] - 1;
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        nm1d2++;
      }
    }

    i3 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)r3, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        r3->data[nm1d2] = n + 1;
        nm1d2++;
      }
    }

    nm1d2 = pixrot->size[1];
    i3 = m_pixrot->size[0] * m_pixrot->size[1];
    m_pixrot->size[0] = 2;
    m_pixrot->size[1] = r3->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)m_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = r3->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (k = 0; k < 2; k++) {
        n = r3->data[r3->size[0] * i3];
        if (!((n >= 1) && (n <= nm1d2))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, nm1d2, &j_emlrtBCI, sp);
        }

        m_pixrot->data[k + m_pixrot->size[0] * i3] = pixrot->data[k +
          pixrot->size[0] * (n - 1)];
      }
    }

    i3 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = m_pixrot->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = m_pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i3] = m_pixrot->data[k +
          m_pixrot->size[0] * i3];
      }
    }

    st.site = &h_emlrtRSI;
    b_round(&st, pixrot);

    /*         %% get indices of the vanashing line */
    st.site = &i_emlrtRSI;
    loop_ub = pixrot->size[1];
    i3 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_1, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      varargin_1->data[varargin_1->size[0] * i3] = pixrot->data[1 + pixrot->
        size[0] * i3];
    }

    loop_ub = pixrot->size[1];
    i3 = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_2, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      varargin_2->data[varargin_2->size[0] * i3] = pixrot->data[pixrot->size[0] *
        i3];
    }

    b_st.site = &ib_emlrtRSI;
    n = (int32_T)(2.0F * H + 1.0F);
    if (!allinrange(varargin_1, n)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    loop_ub = pixrot->size[1];
    i3 = n_pixrot->size[0] * n_pixrot->size[1];
    n_pixrot->size[0] = 1;
    n_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)n_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      n_pixrot->data[n_pixrot->size[0] * i3] = pixrot->data[1 + pixrot->size[0] *
        i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      b_varargin_1[i3] = (uint32_T)n_pixrot->size[i3];
    }

    loop_ub = pixrot->size[1];
    i3 = o_pixrot->size[0] * o_pixrot->size[1];
    o_pixrot->size[0] = 1;
    o_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)o_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      o_pixrot->data[o_pixrot->size[0] * i3] = pixrot->data[pixrot->size[0] * i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      b_varargin_2[i3] = (uint32_T)o_pixrot->size[i3];
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
      emlrtErrorWithMessageIdR2012b(&b_st, &s_emlrtRTEI,
        "MATLAB:sub2ind:SubscriptVectorSize", 0);
    }

    c_st.site = &jb_emlrtRSI;
    d_st.site = &kb_emlrtRSI;
    if (!allinrange(varargin_2, (int32_T)(2.0F * W + 1.0F))) {
      emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    /*         %% draw */
    i3 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = varargin_1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r3, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    nm1d2 = TEMPLATE->size[0] * TEMPLATE->size[1];
    loop_ub = varargin_1->size[0] * varargin_1->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      k = (int32_T)varargin_1->data[i3] + n * ((int32_T)varargin_2->data[i3] - 1);
      if (!((k >= 1) && (k <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, nm1d2, &k_emlrtBCI, sp);
      }

      r3->data[i3] = k;
    }

    cs = 57.2957802F * (1.57079637F - muSingleScalarAtan(y));
    loop_ub = r3->size[0] * r3->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      TEMPLATE->data[r3->data[i3] - 1] = cs;
    }

    h++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real32_T(&o_pixrot);
  emxFree_real32_T(&n_pixrot);
  emxFree_real32_T(&m_pixrot);
  emxFree_real32_T(&l_pixrot);
  emxFree_real32_T(&k_pixrot);
  emxFree_real32_T(&j_pixrot);
  emxFree_real32_T(&i_pixrot);
  covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 1, 0);

  /*     %% bottom border rithg part */
  i2 = (int32_T)((-1.0F - W) / -1.0F);
  emlrtForLoopVectorCheckR2012b(W, -1.0, 0.0, mxSINGLE_CLASS, i2, &n_emlrtRTEI,
    sp);
  h = 0;
  emxInit_real32_T(sp, &p_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &q_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &r_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &s_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &t_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &u_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &v_pixrot, 2, &e_emlrtRTEI, true);
  while (h <= i2 - 1) {
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 3U);

    /*         %% angle */
    y = (W + -(real32_T)h) / H;
    an = 1.57079637F + muSingleScalarAtan(y);

    /*         %% draw in template */
    cs = muSingleScalarCos(-an);
    sn = muSingleScalarSin(-an);
    rot[0] = cs;
    rot[2] = -sn;
    rot[1] = sn;
    rot[3] = cs;
    st.site = &j_emlrtRSI;
    unnamed_idx_1 = (uint32_T)pix->size[1];
    i3 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = (int32_T)unnamed_idx_1;
    pixrot->size[0] = 2;
    emxEnsureCapacity(&st, (emxArray__common *)pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i3] = 0.0F;
      }
    }

    b_st.site = &y_emlrtRSI;
    if (!(pix->size[1] < 1)) {
      c_st.site = &ab_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &ab_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &ab_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &bb_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &cb_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &db_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &eb_emlrtRSI;
      cs = 1.0F;
      sn = 0.0F;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)2;
      n_t = (ptrdiff_t)pix->size[1];
      k_t = (ptrdiff_t)2;
      lda_t = (ptrdiff_t)2;
      ldb_t = (ptrdiff_t)2;
      ldc_t = (ptrdiff_t)2;
      sgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &cs, &rot[0], &lda_t, &pix->
            data[0], &ldb_t, &sn, &pixrot->data[0], &ldc_t);
    }

    loop_ub = pixrot->size[1];
    i3 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r0->data[i3] = i3;
    }

    iv3[0] = 1;
    iv3[1] = r0->size[0];
    loop_ub = pixrot->size[1];
    i3 = p_pixrot->size[0] * p_pixrot->size[1];
    p_pixrot->size[0] = 1;
    p_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)p_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      p_pixrot->data[p_pixrot->size[0] * i3] = pixrot->data[pixrot->size[0] * i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      w_pixrot[i3] = p_pixrot->size[i3];
    }

    emlrtSubAssignSizeCheckR2012b(iv3, 2, w_pixrot, 2, &g_emlrtECI, sp);
    nm1d2 = pixrot->size[1];
    i3 = q_pixrot->size[0] * q_pixrot->size[1];
    q_pixrot->size[0] = 1;
    q_pixrot->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)q_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < nm1d2; i3++) {
      q_pixrot->data[q_pixrot->size[0] * i3] = (pixrot->data[pixrot->size[0] *
        i3] + W) + 1.0F;
    }

    loop_ub = q_pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      pixrot->data[pixrot->size[0] * r0->data[i3]] = q_pixrot->data
        [q_pixrot->size[0] * i3];
    }

    loop_ub = pixrot->size[1];
    i3 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r0->data[i3] = i3;
    }

    iv7[0] = 1;
    iv7[1] = r0->size[0];
    loop_ub = pixrot->size[1];
    i3 = r_pixrot->size[0] * r_pixrot->size[1];
    r_pixrot->size[0] = 1;
    r_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r_pixrot->data[r_pixrot->size[0] * i3] = pixrot->data[1 + pixrot->size[0] *
        i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      w_pixrot[i3] = r_pixrot->size[i3];
    }

    emlrtSubAssignSizeCheckR2012b(iv7, 2, w_pixrot, 2, &h_emlrtECI, sp);
    nm1d2 = pixrot->size[1];
    i3 = s_pixrot->size[0] * s_pixrot->size[1];
    s_pixrot->size[0] = 1;
    s_pixrot->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)s_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < nm1d2; i3++) {
      s_pixrot->data[s_pixrot->size[0] * i3] = (pixrot->data[1 + pixrot->size[0]
        * i3] + H) + 1.0F;
    }

    loop_ub = s_pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      pixrot->data[1 + pixrot->size[0] * r0->data[i3]] = s_pixrot->data
        [s_pixrot->size[0] * i3];
    }

    loop_ub = pixrot->size[1];
    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r1->data[r1->size[0] * i3] = (1.0F <= pixrot->data[pixrot->size[0] * i3]);
    }

    cs = 2.0F * W;
    loop_ub = pixrot->size[1];
    i3 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r2->data[r2->size[0] * i3] = (pixrot->data[pixrot->size[0] * i3] <= cs +
        1.0F);
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv13[i3] = r1->size[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv15[i3] = r2->size[i3];
    }

    if ((iv13[0] != iv15[0]) || (iv13[1] != iv15[1])) {
      emlrtSizeEqCheckNDR2012b(&iv13[0], &iv15[0], &i_emlrtECI, sp);
    }

    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    i3 = r1->size[0];
    k = r1->size[1];
    loop_ub = i3 * k;
    for (i3 = 0; i3 < loop_ub; i3++) {
      r1->data[i3] = (r1->data[i3] && r2->data[i3]);
    }

    loop_ub = pixrot->size[1];
    i3 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r2->data[r2->size[0] * i3] = (1.0F <= pixrot->data[1 + pixrot->size[0] *
        i3]);
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv19[i3] = r1->size[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv21[i3] = r2->size[i3];
    }

    if ((iv19[0] != iv21[0]) || (iv19[1] != iv21[1])) {
      emlrtSizeEqCheckNDR2012b(&iv19[0], &iv21[0], &i_emlrtECI, sp);
    }

    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    i3 = r1->size[0];
    k = r1->size[1];
    loop_ub = i3 * k;
    for (i3 = 0; i3 < loop_ub; i3++) {
      r1->data[i3] = (r1->data[i3] && r2->data[i3]);
    }

    cs = 2.0F * H;
    loop_ub = pixrot->size[1];
    i3 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r2->data[r2->size[0] * i3] = (pixrot->data[1 + pixrot->size[0] * i3] <= cs
        + 1.0F);
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv24[i3] = r1->size[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv25[i3] = r2->size[i3];
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

    i3 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)r3, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        r3->data[nm1d2] = n + 1;
        nm1d2++;
      }
    }

    nm1d2 = pixrot->size[1];
    i3 = t_pixrot->size[0] * t_pixrot->size[1];
    t_pixrot->size[0] = 2;
    t_pixrot->size[1] = r3->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)t_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = r3->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (k = 0; k < 2; k++) {
        n = r3->data[r3->size[0] * i3];
        if (!((n >= 1) && (n <= nm1d2))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, nm1d2, &h_emlrtBCI, sp);
        }

        t_pixrot->data[k + t_pixrot->size[0] * i3] = pixrot->data[k +
          pixrot->size[0] * (n - 1)];
      }
    }

    i3 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = t_pixrot->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = t_pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i3] = t_pixrot->data[k +
          t_pixrot->size[0] * i3];
      }
    }

    st.site = &k_emlrtRSI;
    b_round(&st, pixrot);

    /*         %% get indices of the vanashing line */
    st.site = &l_emlrtRSI;
    loop_ub = pixrot->size[1];
    i3 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_1, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      varargin_1->data[varargin_1->size[0] * i3] = pixrot->data[1 + pixrot->
        size[0] * i3];
    }

    loop_ub = pixrot->size[1];
    i3 = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_2, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      varargin_2->data[varargin_2->size[0] * i3] = pixrot->data[pixrot->size[0] *
        i3];
    }

    b_st.site = &ib_emlrtRSI;
    n = (int32_T)(2.0F * H + 1.0F);
    if (!allinrange(varargin_1, n)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    loop_ub = pixrot->size[1];
    i3 = u_pixrot->size[0] * u_pixrot->size[1];
    u_pixrot->size[0] = 1;
    u_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)u_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      u_pixrot->data[u_pixrot->size[0] * i3] = pixrot->data[1 + pixrot->size[0] *
        i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      b_varargin_1[i3] = (uint32_T)u_pixrot->size[i3];
    }

    loop_ub = pixrot->size[1];
    i3 = v_pixrot->size[0] * v_pixrot->size[1];
    v_pixrot->size[0] = 1;
    v_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)v_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      v_pixrot->data[v_pixrot->size[0] * i3] = pixrot->data[pixrot->size[0] * i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      b_varargin_2[i3] = (uint32_T)v_pixrot->size[i3];
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
      emlrtErrorWithMessageIdR2012b(&b_st, &s_emlrtRTEI,
        "MATLAB:sub2ind:SubscriptVectorSize", 0);
    }

    c_st.site = &jb_emlrtRSI;
    d_st.site = &kb_emlrtRSI;
    if (!allinrange(varargin_2, (int32_T)(2.0F * W + 1.0F))) {
      emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    /*         %% draw */
    i3 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = varargin_1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r3, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    nm1d2 = TEMPLATE->size[0] * TEMPLATE->size[1];
    loop_ub = varargin_1->size[0] * varargin_1->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      k = (int32_T)varargin_1->data[i3] + n * ((int32_T)varargin_2->data[i3] - 1);
      if (!((k >= 1) && (k <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, nm1d2, &i_emlrtBCI, sp);
      }

      r3->data[i3] = k;
    }

    cs = 57.2957802F * (1.57079637F + muSingleScalarAtan(y));
    loop_ub = r3->size[0] * r3->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      TEMPLATE->data[r3->data[i3] - 1] = cs;
    }

    h++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real32_T(&v_pixrot);
  emxFree_real32_T(&u_pixrot);
  emxFree_real32_T(&t_pixrot);
  emxFree_real32_T(&s_pixrot);
  emxFree_real32_T(&r_pixrot);
  emxFree_real32_T(&q_pixrot);
  emxFree_real32_T(&p_pixrot);
  covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 4U);

  /*     %% right border */
  cs = -2.0F * W;
  sn = 2.0F * W;
  st.site = &m_emlrtRSI;
  b_st.site = &r_emlrtRSI;
  if (sn < cs) {
    i2 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)varargin_1, i2, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
  } else if (cs == cs) {
    i2 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = (int32_T)muSingleScalarFloor(sn - cs) + 1;
    emxEnsureCapacity(&b_st, (emxArray__common *)varargin_1, i2, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = (int32_T)muSingleScalarFloor(sn - cs);
    for (i2 = 0; i2 <= loop_ub; i2++) {
      varargin_1->data[varargin_1->size[0] * i2] = cs + (real32_T)i2;
    }
  } else {
    c_st.site = &s_emlrtRSI;
    ndbl = muDoubleScalarFloor(((real_T)sn - cs) + 0.5);
    apnd = cs + ndbl;
    cdiff = apnd - sn;
    absa = muDoubleScalarAbs(cs);
    absb = muDoubleScalarAbs(sn);
    if (muDoubleScalarAbs(cdiff) < 2.38418579E-7F * (real32_T)muDoubleScalarMax
        (absa, absb)) {
      ndbl++;
    } else if (cdiff > 0.0) {
      sn = (real32_T)(cs + (ndbl - 1.0));
    } else {
      ndbl++;
      sn = (real32_T)apnd;
    }

    if (ndbl >= 0.0) {
      n = (int32_T)ndbl;
    } else {
      n = 0;
    }

    d_st.site = &t_emlrtRSI;
    if (2.147483647E+9 < ndbl) {
      emlrtErrorWithMessageIdR2012b(&d_st, &p_emlrtRTEI, "Coder:MATLAB:pmaxsize",
        0);
    }

    i2 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = n;
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i2, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    if (n > 0) {
      varargin_1->data[0] = cs;
      if (n > 1) {
        varargin_1->data[n - 1] = sn;
        nm1d2 = (n - 1) / 2;
        d_st.site = &u_emlrtRSI;
        for (k = 1; k < nm1d2; k++) {
          varargin_1->data[k] = cs + (real32_T)k;
          varargin_1->data[(n - k) - 1] = sn - (real32_T)k;
        }

        if (nm1d2 << 1 == n - 1) {
          varargin_1->data[nm1d2] = (cs + sn) / 2.0F;
        } else {
          varargin_1->data[nm1d2] = cs + (real32_T)nm1d2;
          varargin_1->data[nm1d2 + 1] = sn - (real32_T)nm1d2;
        }
      }
    }
  }

  y = 4.0F * W;
  ndbl = y + 1.0F;
  if (!(ndbl >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndbl, &gb_emlrtDCI, sp);
  }

  ndbl = (real32_T)ndbl;
  if (ndbl != (int32_T)muDoubleScalarFloor(ndbl)) {
    emlrtIntegerCheckR2012b(ndbl, &hb_emlrtDCI, sp);
  }

  st.site = &m_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  p = true;
  if (varargin_1->size[1] != (int32_T)(y + 1.0F)) {
    p = false;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(&c_st, &q_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  i2 = pix->size[0] * pix->size[1];
  pix->size[0] = 2;
  pix->size[1] = varargin_1->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)pix, i2, (int32_T)sizeof(real32_T),
                    &e_emlrtRTEI);
  loop_ub = varargin_1->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    pix->data[pix->size[0] * i2] = varargin_1->data[varargin_1->size[0] * i2];
  }

  loop_ub = (int32_T)(y + 1.0F);
  for (i2 = 0; i2 < loop_ub; i2++) {
    pix->data[1 + pix->size[0] * i2] = 0.0F;
  }

  y = 2.0F * H;
  i2 = (int32_T)((y + 1.0F) + (1.0F - (H + 1.0F)));
  emlrtForLoopVectorCheckR2012b(H + 1.0F, 1.0, y + 1.0F, mxSINGLE_CLASS, i2,
    &o_emlrtRTEI, sp);
  h = 0;
  emxInit_real32_T(sp, &x_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &y_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &ab_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &bb_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &cb_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &db_pixrot, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &eb_pixrot, 2, &e_emlrtRTEI, true);
  while (h <= i2 - 1) {
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 5U);

    /*         %% angle */
    y = (((H + 1.0F) + (real32_T)h) - (H + 1.0F)) / W;
    an = 3.14159274F - muSingleScalarAtan(y);

    /*         %% draw in template */
    cs = muSingleScalarCos(-an);
    sn = muSingleScalarSin(-an);
    rot[0] = cs;
    rot[2] = -sn;
    rot[1] = sn;
    rot[3] = cs;
    st.site = &n_emlrtRSI;
    unnamed_idx_1 = (uint32_T)pix->size[1];
    i3 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = (int32_T)unnamed_idx_1;
    pixrot->size[0] = 2;
    emxEnsureCapacity(&st, (emxArray__common *)pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i3] = 0.0F;
      }
    }

    b_st.site = &y_emlrtRSI;
    if (!(pix->size[1] < 1)) {
      c_st.site = &ab_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &ab_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &ab_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &bb_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &cb_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &db_emlrtRSI;
      d_st.site = &fb_emlrtRSI;
      c_st.site = &eb_emlrtRSI;
      cs = 1.0F;
      sn = 0.0F;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)2;
      n_t = (ptrdiff_t)pix->size[1];
      k_t = (ptrdiff_t)2;
      lda_t = (ptrdiff_t)2;
      ldb_t = (ptrdiff_t)2;
      ldc_t = (ptrdiff_t)2;
      sgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &cs, &rot[0], &lda_t, &pix->
            data[0], &ldb_t, &sn, &pixrot->data[0], &ldc_t);
    }

    loop_ub = pixrot->size[1];
    i3 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r0->data[i3] = i3;
    }

    iv12[0] = 1;
    iv12[1] = r0->size[0];
    loop_ub = pixrot->size[1];
    i3 = x_pixrot->size[0] * x_pixrot->size[1];
    x_pixrot->size[0] = 1;
    x_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)x_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      x_pixrot->data[x_pixrot->size[0] * i3] = pixrot->data[pixrot->size[0] * i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      w_pixrot[i3] = x_pixrot->size[i3];
    }

    emlrtSubAssignSizeCheckR2012b(iv12, 2, w_pixrot, 2, &j_emlrtECI, sp);
    nm1d2 = pixrot->size[1];
    i3 = y_pixrot->size[0] * y_pixrot->size[1];
    y_pixrot->size[0] = 1;
    y_pixrot->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)y_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < nm1d2; i3++) {
      y_pixrot->data[y_pixrot->size[0] * i3] = (pixrot->data[pixrot->size[0] *
        i3] + W) + 1.0F;
    }

    loop_ub = y_pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      pixrot->data[pixrot->size[0] * r0->data[i3]] = y_pixrot->data
        [y_pixrot->size[0] * i3];
    }

    loop_ub = pixrot->size[1];
    i3 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r0->data[i3] = i3;
    }

    iv20[0] = 1;
    iv20[1] = r0->size[0];
    loop_ub = pixrot->size[1];
    i3 = ab_pixrot->size[0] * ab_pixrot->size[1];
    ab_pixrot->size[0] = 1;
    ab_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)ab_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      ab_pixrot->data[ab_pixrot->size[0] * i3] = pixrot->data[1 + pixrot->size[0]
        * i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      w_pixrot[i3] = ab_pixrot->size[i3];
    }

    emlrtSubAssignSizeCheckR2012b(iv20, 2, w_pixrot, 2, &k_emlrtECI, sp);
    nm1d2 = pixrot->size[1];
    i3 = bb_pixrot->size[0] * bb_pixrot->size[1];
    bb_pixrot->size[0] = 1;
    bb_pixrot->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)bb_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < nm1d2; i3++) {
      bb_pixrot->data[bb_pixrot->size[0] * i3] = (pixrot->data[1 + pixrot->size
        [0] * i3] + H) + 1.0F;
    }

    loop_ub = bb_pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      pixrot->data[1 + pixrot->size[0] * r0->data[i3]] = bb_pixrot->
        data[bb_pixrot->size[0] * i3];
    }

    loop_ub = pixrot->size[1];
    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r1->data[r1->size[0] * i3] = (1.0F <= pixrot->data[pixrot->size[0] * i3]);
    }

    cs = 2.0F * W;
    loop_ub = pixrot->size[1];
    i3 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r2->data[r2->size[0] * i3] = (pixrot->data[pixrot->size[0] * i3] <= cs +
        1.0F);
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv26[i3] = r1->size[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv27[i3] = r2->size[i3];
    }

    if ((iv26[0] != iv27[0]) || (iv26[1] != iv27[1])) {
      emlrtSizeEqCheckNDR2012b(&iv26[0], &iv27[0], &l_emlrtECI, sp);
    }

    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    i3 = r1->size[0];
    k = r1->size[1];
    loop_ub = i3 * k;
    for (i3 = 0; i3 < loop_ub; i3++) {
      r1->data[i3] = (r1->data[i3] && r2->data[i3]);
    }

    loop_ub = pixrot->size[1];
    i3 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r2->data[r2->size[0] * i3] = (1.0F <= pixrot->data[1 + pixrot->size[0] *
        i3]);
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv28[i3] = r1->size[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv29[i3] = r2->size[i3];
    }

    if ((iv28[0] != iv29[0]) || (iv28[1] != iv29[1])) {
      emlrtSizeEqCheckNDR2012b(&iv28[0], &iv29[0], &l_emlrtECI, sp);
    }

    i3 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    i3 = r1->size[0];
    k = r1->size[1];
    loop_ub = i3 * k;
    for (i3 = 0; i3 < loop_ub; i3++) {
      r1->data[i3] = (r1->data[i3] && r2->data[i3]);
    }

    cs = 2.0F * H;
    loop_ub = pixrot->size[1];
    i3 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i3, (int32_T)sizeof(boolean_T),
                      &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      r2->data[r2->size[0] * i3] = (pixrot->data[1 + pixrot->size[0] * i3] <= cs
        + 1.0F);
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv30[i3] = r1->size[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      iv31[i3] = r2->size[i3];
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

    i3 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = nm1d2;
    emxEnsureCapacity(sp, (emxArray__common *)r3, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    nm1d2 = 0;
    for (n = 0; n <= k; n++) {
      if (r1->data[n] && r2->data[n]) {
        r3->data[nm1d2] = n + 1;
        nm1d2++;
      }
    }

    nm1d2 = pixrot->size[1];
    i3 = cb_pixrot->size[0] * cb_pixrot->size[1];
    cb_pixrot->size[0] = 2;
    cb_pixrot->size[1] = r3->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)cb_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = r3->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (k = 0; k < 2; k++) {
        n = r3->data[r3->size[0] * i3];
        if (!((n >= 1) && (n <= nm1d2))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, nm1d2, &f_emlrtBCI, sp);
        }

        cb_pixrot->data[k + cb_pixrot->size[0] * i3] = pixrot->data[k +
          pixrot->size[0] * (n - 1)];
      }
    }

    i3 = pixrot->size[0] * pixrot->size[1];
    pixrot->size[0] = 2;
    pixrot->size[1] = cb_pixrot->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    loop_ub = cb_pixrot->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (k = 0; k < 2; k++) {
        pixrot->data[k + pixrot->size[0] * i3] = cb_pixrot->data[k +
          cb_pixrot->size[0] * i3];
      }
    }

    st.site = &o_emlrtRSI;
    b_round(&st, pixrot);

    /*         %% get indices of the vanashing line */
    st.site = &p_emlrtRSI;
    loop_ub = pixrot->size[1];
    i3 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_1, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      varargin_1->data[varargin_1->size[0] * i3] = pixrot->data[1 + pixrot->
        size[0] * i3];
    }

    loop_ub = pixrot->size[1];
    i3 = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)varargin_2, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      varargin_2->data[varargin_2->size[0] * i3] = pixrot->data[pixrot->size[0] *
        i3];
    }

    b_st.site = &ib_emlrtRSI;
    n = (int32_T)(2.0F * H + 1.0F);
    if (!allinrange(varargin_1, n)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    loop_ub = pixrot->size[1];
    i3 = db_pixrot->size[0] * db_pixrot->size[1];
    db_pixrot->size[0] = 1;
    db_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)db_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      db_pixrot->data[db_pixrot->size[0] * i3] = pixrot->data[1 + pixrot->size[0]
        * i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      b_varargin_1[i3] = (uint32_T)db_pixrot->size[i3];
    }

    loop_ub = pixrot->size[1];
    i3 = eb_pixrot->size[0] * eb_pixrot->size[1];
    eb_pixrot->size[0] = 1;
    eb_pixrot->size[1] = loop_ub;
    emxEnsureCapacity(&b_st, (emxArray__common *)eb_pixrot, i3, (int32_T)sizeof
                      (real32_T), &e_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      eb_pixrot->data[eb_pixrot->size[0] * i3] = pixrot->data[pixrot->size[0] *
        i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      b_varargin_2[i3] = (uint32_T)eb_pixrot->size[i3];
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
      emlrtErrorWithMessageIdR2012b(&b_st, &s_emlrtRTEI,
        "MATLAB:sub2ind:SubscriptVectorSize", 0);
    }

    c_st.site = &jb_emlrtRSI;
    d_st.site = &kb_emlrtRSI;
    if (!allinrange(varargin_2, (int32_T)(2.0F * W + 1.0F))) {
      emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    /*         %% draw */
    i3 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = varargin_1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r3, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    nm1d2 = TEMPLATE->size[0] * TEMPLATE->size[1];
    loop_ub = varargin_1->size[0] * varargin_1->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      k = (int32_T)varargin_1->data[i3] + n * ((int32_T)varargin_2->data[i3] - 1);
      if (!((k >= 1) && (k <= nm1d2))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, nm1d2, &g_emlrtBCI, sp);
      }

      r3->data[i3] = k;
    }

    cs = 57.2957802F * (3.14159274F - muSingleScalarAtan(y));
    loop_ub = r3->size[0] * r3->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      TEMPLATE->data[r3->data[i3] - 1] = cs;
    }

    h++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real32_T(&eb_pixrot);
  emxFree_real32_T(&db_pixrot);
  emxFree_real32_T(&cb_pixrot);
  emxFree_real32_T(&bb_pixrot);
  emxFree_real32_T(&ab_pixrot);
  emxFree_real32_T(&y_pixrot);
  emxFree_real32_T(&x_pixrot);
  emxFree_real32_T(&varargin_2);
  emxFree_real32_T(&varargin_1);
  emxFree_int32_T(&r3);
  emxFree_boolean_T(&r2);
  emxFree_boolean_T(&r1);
  emxFree_int32_T(&r0);
  emxFree_real32_T(&pixrot);
  emxFree_real32_T(&pix);
  emxInit_real_T(sp, &b_TEMPLATE, 2, &e_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 6U);

  /*     %% fill in holes */
  i2 = b_TEMPLATE->size[0] * b_TEMPLATE->size[1];
  b_TEMPLATE->size[0] = TEMPLATE->size[0];
  b_TEMPLATE->size[1] = TEMPLATE->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_TEMPLATE, i2, (int32_T)sizeof
                    (real_T), &e_emlrtRTEI);
  loop_ub = TEMPLATE->size[0] * TEMPLATE->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_TEMPLATE->data[i2] = TEMPLATE->data[i2];
  }

  st.site = &q_emlrtRSI;
  imdilate(&st, b_TEMPLATE, TEMPLATE);
  emxFree_real_T(&b_TEMPLATE);
  if (1.0F > H + 2.0F) {
    loop_ub = 0;
  } else {
    i2 = TEMPLATE->size[0];
    if (!(1 <= i2)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i2, &e_emlrtBCI, sp);
    }

    i2 = TEMPLATE->size[0];
    i3 = (int32_T)(H + 2.0F);
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &e_emlrtBCI, sp);
    }

    loop_ub = (int32_T)(real32_T)i3;
  }

  nm1d2 = TEMPLATE->size[1];
  for (i2 = 0; i2 < nm1d2; i2++) {
    for (i3 = 0; i3 < loop_ub; i3++) {
      TEMPLATE->data[i3 + TEMPLATE->size[0] * i2] = -180.0;
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (createTemplate.c) */
