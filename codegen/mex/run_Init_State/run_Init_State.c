/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_Init_State.c
 *
 * Code generation for function 'run_Init_State'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_Init_State.h"
#include "run_Init_State_emxutil.h"
#include "createTemplate.h"
#include "run_Init_State_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 40,    /* lineNo */
  "run_Init_State",                    /* fcnName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  57,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 49,/* lineNo */
  5,                                   /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 60,/* lineNo */
  5,                                   /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 16,    /* lineNo */
  29,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 16,  /* lineNo */
  40,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 16,  /* lineNo */
  51,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 17,  /* lineNo */
  29,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 17,  /* lineNo */
  40,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 18,  /* lineNo */
  32,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 18,  /* lineNo */
  43,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 19,  /* lineNo */
  32,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 19,  /* lineNo */
  43,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 20,  /* lineNo */
  29,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 20,  /* lineNo */
  40,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 21,  /* lineNo */
  29,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 21,  /* lineNo */
  40,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 22,  /* lineNo */
  29,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 22,  /* lineNo */
  40,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 23,  /* lineNo */
  29,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 23,  /* lineNo */
  40,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRTEInfo j_emlrtRTEI = { 53,/* lineNo */
  13,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 63,/* lineNo */
  13,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  30,                                  /* colNo */
  "ROOT_IDEPTH_TEMPLATE",              /* aName */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  24,                                  /* colNo */
  "ROOT_PROB_TEMPLATE",                /* aName */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  26,                                  /* colNo */
  "ROOT_PROB_TEMPLATE",                /* aName */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 49,  /* lineNo */
  32,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 49,  /* lineNo */
  32,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 49,  /* lineNo */
  46,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 49,  /* lineNo */
  46,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 60,  /* lineNo */
  34,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 60,  /* lineNo */
  34,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 60,  /* lineNo */
  48,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 60,  /* lineNo */
  48,                                  /* colNo */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  5,                                   /* colNo */
  "ROOT_IDEPTH_TEMPLATE",              /* aName */
  "run_Init_State",                    /* fName */
  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void run_Init_State(const emlrtStack *sp, const int32_T RES_VH[2], int32_T
                    NBUFFER, const struct0_T *laneFilter, const struct1_T
                    *vpFilter, MatlabStruct_likelihoods *likelihoods,
                    MatlabStruct_templates *templates, MatlabStruct_vanishingPt *
                    vanishingPt, MatlabStruct_focusMask *masks)
{
  int32_T i0;
  real32_T b_RES_VH[2];
  emxArray_real_T *ROOT_DIR_TEMPLATE;
  emxArray_real_T *ROOT_PROB_TEMPLATE;
  real32_T absx;
  real_T d0;
  real_T d1;
  int32_T loop_ub;
  int32_T i1;
  int32_T unnamed_idx_0;
  int32_T end;
  emxArray_real_T *ROOT_IDEPTH_TEMPLATE;
  real32_T step;
  real32_T angle;
  real32_T x;
  int8_T n;
  emlrtStack st;
  (void)laneFilter;
  (void)vpFilter;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /* coder.cstructname(laneFilter, 'MatlabStruct_laneFilter'); */
  /* coder.cstructname(vpFilter, 'MatlabStruct_vpFilter'); */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*     %% (re)start the filters %% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%% */
  i0 = RES_VH[0];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &emlrtDCI, sp);
  }

  i0 = RES_VH[1];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &b_emlrtDCI, sp);
  }

  if (!(NBUFFER >= 0)) {
    emlrtNonNegativeCheckR2012b(NBUFFER, &c_emlrtDCI, sp);
  }

  i0 = RES_VH[0];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &d_emlrtDCI, sp);
  }

  i0 = RES_VH[1];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &e_emlrtDCI, sp);
  }

  i0 = RES_VH[0];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &f_emlrtDCI, sp);
  }

  i0 = RES_VH[1];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &g_emlrtDCI, sp);
  }

  i0 = RES_VH[0];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &h_emlrtDCI, sp);
  }

  i0 = RES_VH[1];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &i_emlrtDCI, sp);
  }

  i0 = RES_VH[0];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &j_emlrtDCI, sp);
  }

  i0 = RES_VH[1];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &k_emlrtDCI, sp);
  }

  i0 = RES_VH[0];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &l_emlrtDCI, sp);
  }

  i0 = RES_VH[1];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &m_emlrtDCI, sp);
  }

  i0 = RES_VH[0];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &n_emlrtDCI, sp);
  }

  i0 = RES_VH[1];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &o_emlrtDCI, sp);
  }

  i0 = RES_VH[0];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &p_emlrtDCI, sp);
  }

  i0 = RES_VH[1];
  if (!(i0 >= 0)) {
    emlrtNonNegativeCheckR2012b(i0, &q_emlrtDCI, sp);
  }

  /*     IDX_LANE_PIX   = []; */
  /*   */
  /*  Create Segment Mask %% */
  /*  %  */
  /*  %     SEGMENT            = zeros( RES_VH(1),RES_VH(2)); */
  /*  %     SEGMENT_TIGHT      = zeros( RES_VH(1),RES_VH(2) ); */
  /*  %     SEGMENT_VERY_TIGHT = zeros( RES_VH(1),RES_VH(2) ); */
  /*  %     SEGMENT_WIDE       = zeros( RES_VH(1),RES_VH(2) ); */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*     %% create the gradient template %% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (i0 = 0; i0 < 2; i0++) {
    b_RES_VH[i0] = (real32_T)RES_VH[i0];
  }

  emxInit_real_T(sp, &ROOT_DIR_TEMPLATE, 2, &b_emlrtRTEI, true);
  emxInit_real_T(sp, &ROOT_PROB_TEMPLATE, 2, &c_emlrtRTEI, true);
  st.site = &emlrtRSI;
  createTemplate(&st, b_RES_VH[0], b_RES_VH[1], ROOT_DIR_TEMPLATE);

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*     %% create the prob template               %% */
  /*     %% masks out parts above horizon + margin %% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Note: Should be fitted using sweeps */
  absx = 2.0F * b_RES_VH[0];
  i0 = ROOT_PROB_TEMPLATE->size[0] * ROOT_PROB_TEMPLATE->size[1];
  d0 = absx + 1.0F;
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &s_emlrtDCI, sp);
  }

  d0 = (real32_T)d0;
  if (d0 != (int32_T)d0) {
    emlrtIntegerCheckR2012b(d0, &r_emlrtDCI, sp);
  }

  ROOT_PROB_TEMPLATE->size[0] = (int32_T)(real32_T)d0;
  d0 = b_RES_VH[1];
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &u_emlrtDCI, sp);
  }

  d0 = (real32_T)d0;
  if (d0 != (int32_T)d0) {
    emlrtIntegerCheckR2012b(d0, &t_emlrtDCI, sp);
  }

  ROOT_PROB_TEMPLATE->size[1] = (int32_T)(real32_T)d0;
  emxEnsureCapacity(sp, (emxArray__common *)ROOT_PROB_TEMPLATE, i0, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  d0 = absx + 1.0F;
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &s_emlrtDCI, sp);
  }

  d0 = (real32_T)d0;
  if (d0 != (int32_T)d0) {
    emlrtIntegerCheckR2012b(d0, &r_emlrtDCI, sp);
  }

  d1 = b_RES_VH[1];
  if (!(d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d1, &u_emlrtDCI, sp);
  }

  d1 = (real32_T)d1;
  if (d1 != (int32_T)d1) {
    emlrtIntegerCheckR2012b(d1, &t_emlrtDCI, sp);
  }

  loop_ub = (int32_T)(real32_T)d0 * (int32_T)(real32_T)d1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    ROOT_PROB_TEMPLATE->data[i0] = 0.0;
  }

  if ((real_T)(b_RES_VH[0] + 100.0F) > (int32_T)(absx + 1.0F)) {
    i0 = 1;
    i1 = 1;
  } else {
    i0 = (int32_T)(absx + 1.0F);
    i1 = (int32_T)(b_RES_VH[0] + 100.0F);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &b_emlrtBCI, sp);
    }

    i0 = (int32_T)(real32_T)i1;
    i1 = (int32_T)(absx + 1.0F);
    end = (int32_T)(absx + 1.0F);
    if (!((end >= 1) && (end <= i1))) {
      emlrtDynamicBoundsCheckR2012b(end, 1, i1, &b_emlrtBCI, sp);
    }

    i1 = end + 1;
  }

  unnamed_idx_0 = i1 - i0;
  loop_ub = (int32_T)b_RES_VH[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (end = 0; end < unnamed_idx_0; end++) {
      ROOT_PROB_TEMPLATE->data[((i0 + end) + ROOT_PROB_TEMPLATE->size[0] * i1) -
        1] = 1.0;
    }
  }

  emlrtForLoopVectorCheckR2012b(481.0, 1.0, b_RES_VH[0] + 100.0F, mxSINGLE_CLASS,
    (int32_T)((b_RES_VH[0] + 100.0F) + -480.0F), &j_emlrtRTEI, sp);
  unnamed_idx_0 = 0;
  while (unnamed_idx_0 <= (int32_T)((b_RES_VH[0] + 100.0F) + -480.0F) - 1) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
    absx = muSingleScalarPower(((481.0F + (real32_T)unnamed_idx_0) - b_RES_VH[0])
      / 100.0F, 3.0F);
    loop_ub = ROOT_PROB_TEMPLATE->size[1];
    end = ROOT_PROB_TEMPLATE->size[0];
    i0 = (int32_T)(481.0F + (real32_T)unnamed_idx_0);
    if (!((i0 >= 1) && (i0 <= end))) {
      emlrtDynamicBoundsCheckR2012b(i0, 1, end, &c_emlrtBCI, sp);
    }

    for (i0 = 0; i0 < loop_ub; i0++) {
      ROOT_PROB_TEMPLATE->data[((int32_T)(481.0F + (real32_T)unnamed_idx_0) +
        ROOT_PROB_TEMPLATE->size[0] * i0) - 1] = absx;
    }

    unnamed_idx_0++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_real_T(sp, &ROOT_IDEPTH_TEMPLATE, 2, &d_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*     %% create the depth template              %% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  absx = 2.0F * b_RES_VH[0];
  i0 = ROOT_IDEPTH_TEMPLATE->size[0] * ROOT_IDEPTH_TEMPLATE->size[1];
  d0 = absx + 1.0F;
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &w_emlrtDCI, sp);
  }

  d0 = (real32_T)d0;
  if (d0 != (int32_T)d0) {
    emlrtIntegerCheckR2012b(d0, &v_emlrtDCI, sp);
  }

  ROOT_IDEPTH_TEMPLATE->size[0] = (int32_T)(real32_T)d0;
  d0 = b_RES_VH[1];
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &y_emlrtDCI, sp);
  }

  d0 = (real32_T)d0;
  if (d0 != (int32_T)d0) {
    emlrtIntegerCheckR2012b(d0, &x_emlrtDCI, sp);
  }

  ROOT_IDEPTH_TEMPLATE->size[1] = (int32_T)(real32_T)d0;
  emxEnsureCapacity(sp, (emxArray__common *)ROOT_IDEPTH_TEMPLATE, i0, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  d0 = absx + 1.0F;
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &w_emlrtDCI, sp);
  }

  d0 = (real32_T)d0;
  if (d0 != (int32_T)d0) {
    emlrtIntegerCheckR2012b(d0, &v_emlrtDCI, sp);
  }

  d1 = b_RES_VH[1];
  if (!(d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d1, &y_emlrtDCI, sp);
  }

  d1 = (real32_T)d1;
  if (d1 != (int32_T)d1) {
    emlrtIntegerCheckR2012b(d1, &x_emlrtDCI, sp);
  }

  loop_ub = (int32_T)(real32_T)d0 * (int32_T)(real32_T)d1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    ROOT_IDEPTH_TEMPLATE->data[i0] = 0.0;
  }

  step = 45.0F / b_RES_VH[0];
  angle = 90.0F - step;
  absx = 2.0F * b_RES_VH[0];
  i0 = (int32_T)((absx + 1.0F) + (1.0F - (b_RES_VH[0] + 1.0F)));
  emlrtForLoopVectorCheckR2012b(b_RES_VH[0] + 1.0F, 1.0, absx + 1.0F,
    mxSINGLE_CLASS, i0, &k_emlrtRTEI, sp);
  unnamed_idx_0 = 0;
  while (unnamed_idx_0 <= i0 - 1) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);
    if (!((!muSingleScalarIsInf(angle)) && (!muSingleScalarIsNaN(angle)))) {
      x = ((real32_T)rtNaN);
    } else {
      x = muSingleScalarRem(angle, 360.0F);
      absx = muSingleScalarAbs(x);
      if (absx > 180.0F) {
        if (x > 0.0F) {
          x -= 360.0F;
        } else {
          x += 360.0F;
        }

        absx = muSingleScalarAbs(x);
      }

      if (absx <= 45.0F) {
        x *= 0.0174532924F;
        n = 0;
      } else if (absx <= 135.0F) {
        if (x > 0.0F) {
          x = 0.0174532924F * (x - 90.0F);
          n = 1;
        } else {
          x = 0.0174532924F * (x + 90.0F);
          n = -1;
        }
      } else if (x > 0.0F) {
        x = 0.0174532924F * (x - 180.0F);
        n = 2;
      } else {
        x = 0.0174532924F * (x + 180.0F);
        n = -2;
      }

      x = muSingleScalarTan(x);
      if ((n == 1) || (n == -1)) {
        absx = 1.0F / x;
        x = -(1.0F / x);
        if (muSingleScalarIsInf(x) && (n == 1)) {
          x = -(-absx);
        }
      }
    }

    absx = 1.75F * x;
    loop_ub = ROOT_IDEPTH_TEMPLATE->size[1];
    end = ROOT_IDEPTH_TEMPLATE->size[0];
    i1 = (int32_T)((b_RES_VH[0] + 1.0F) + (real32_T)unnamed_idx_0);
    if (!((i1 >= 1) && (i1 <= end))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, end, &emlrtBCI, sp);
    }

    end = (int32_T)(real32_T)i1;
    for (i1 = 0; i1 < loop_ub; i1++) {
      ROOT_IDEPTH_TEMPLATE->data[(end + ROOT_IDEPTH_TEMPLATE->size[0] * i1) - 1]
        = absx;
    }

    angle -= step;
    unnamed_idx_0++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4U);
  end = ROOT_IDEPTH_TEMPLATE->size[0] * ROOT_IDEPTH_TEMPLATE->size[1];
  for (unnamed_idx_0 = 0; unnamed_idx_0 < end; unnamed_idx_0++) {
    if (100.0 < ROOT_IDEPTH_TEMPLATE->data[unnamed_idx_0]) {
      i0 = ROOT_IDEPTH_TEMPLATE->size[0] * ROOT_IDEPTH_TEMPLATE->size[1];
      if (!((unnamed_idx_0 + 1 >= 1) && (unnamed_idx_0 + 1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(unnamed_idx_0 + 1, 1, i0, &d_emlrtBCI, sp);
      }

      ROOT_IDEPTH_TEMPLATE->data[unnamed_idx_0] = 100.0;
    }
  }

  /*      figure(234) */
  /*      imshow(ROOT_IDEPTH_TEMPLATE,[0 100]) */
  /*      colormap jet */
  /*      drawnow */
  /*      pause */
  /* %%%%%%%%%%%%%%%%%%%%%%% */
  /*     %% this state is done %% */
  /* %%%%%%%%%%%%%%%%%%%%%%% */
  i0 = templates->GRADIENT_DIR_ROOT->size[0] * templates->
    GRADIENT_DIR_ROOT->size[1];
  templates->GRADIENT_DIR_ROOT->size[0] = ROOT_DIR_TEMPLATE->size[0];
  templates->GRADIENT_DIR_ROOT->size[1] = ROOT_DIR_TEMPLATE->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)templates->GRADIENT_DIR_ROOT, i0,
                    (int32_T)sizeof(real_T), &emlrtRTEI);
  loop_ub = ROOT_DIR_TEMPLATE->size[0] * ROOT_DIR_TEMPLATE->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    templates->GRADIENT_DIR_ROOT->data[i0] = ROOT_DIR_TEMPLATE->data[i0];
  }

  emxFree_real_T(&ROOT_DIR_TEMPLATE);
  i0 = templates->PROB_ROOT->size[0] * templates->PROB_ROOT->size[1];
  templates->PROB_ROOT->size[0] = ROOT_PROB_TEMPLATE->size[0];
  templates->PROB_ROOT->size[1] = ROOT_PROB_TEMPLATE->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)templates->PROB_ROOT, i0, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  loop_ub = ROOT_PROB_TEMPLATE->size[0] * ROOT_PROB_TEMPLATE->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    templates->PROB_ROOT->data[i0] = ROOT_PROB_TEMPLATE->data[i0];
  }

  emxFree_real_T(&ROOT_PROB_TEMPLATE);
  i0 = templates->DEPTH_ROOT->size[0] * templates->DEPTH_ROOT->size[1];
  templates->DEPTH_ROOT->size[0] = ROOT_IDEPTH_TEMPLATE->size[0];
  templates->DEPTH_ROOT->size[1] = ROOT_IDEPTH_TEMPLATE->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)templates->DEPTH_ROOT, i0, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  loop_ub = ROOT_IDEPTH_TEMPLATE->size[0] * ROOT_IDEPTH_TEMPLATE->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    templates->DEPTH_ROOT->data[i0] = ROOT_IDEPTH_TEMPLATE->data[i0];
  }

  emxFree_real_T(&ROOT_IDEPTH_TEMPLATE);
  vanishingPt->V = 0.0;
  vanishingPt->H = 0.0;
  vanishingPt->V_prev = 0.0;
  vanishingPt->H_prev = 0.0;
  i0 = likelihoods->TOT_ALL->size[0] * likelihoods->TOT_ALL->size[1] *
    likelihoods->TOT_ALL->size[2];
  likelihoods->TOT_ALL->size[0] = RES_VH[0];
  likelihoods->TOT_ALL->size[1] = RES_VH[1];
  likelihoods->TOT_ALL->size[2] = NBUFFER;
  emxEnsureCapacity(sp, (emxArray__common *)likelihoods->TOT_ALL, i0, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  loop_ub = RES_VH[0] * RES_VH[1] * NBUFFER;
  for (i0 = 0; i0 < loop_ub; i0++) {
    likelihoods->TOT_ALL->data[i0] = 0.0;
  }

  i0 = likelihoods->TOT_MAX->size[0] * likelihoods->TOT_MAX->size[1];
  likelihoods->TOT_MAX->size[0] = RES_VH[0];
  likelihoods->TOT_MAX->size[1] = RES_VH[1];
  emxEnsureCapacity(sp, (emxArray__common *)likelihoods->TOT_MAX, i0, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  loop_ub = RES_VH[0] * RES_VH[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    likelihoods->TOT_MAX->data[i0] = 0.0;
  }

  i0 = likelihoods->GRADIENT_DIR_ALL->size[0] * likelihoods->
    GRADIENT_DIR_ALL->size[1] * likelihoods->GRADIENT_DIR_ALL->size[2];
  likelihoods->GRADIENT_DIR_ALL->size[0] = RES_VH[0];
  likelihoods->GRADIENT_DIR_ALL->size[1] = RES_VH[1];
  likelihoods->GRADIENT_DIR_ALL->size[2] = NBUFFER;
  emxEnsureCapacity(sp, (emxArray__common *)likelihoods->GRADIENT_DIR_ALL, i0,
                    (int32_T)sizeof(real_T), &emlrtRTEI);
  loop_ub = RES_VH[0] * RES_VH[1] * NBUFFER;
  for (i0 = 0; i0 < loop_ub; i0++) {
    likelihoods->GRADIENT_DIR_ALL->data[i0] = 0.0;
  }

  i0 = likelihoods->GRADIENT_DIR_AVG->size[0] * likelihoods->
    GRADIENT_DIR_AVG->size[1];
  likelihoods->GRADIENT_DIR_AVG->size[0] = RES_VH[0];
  likelihoods->GRADIENT_DIR_AVG->size[1] = RES_VH[1];
  emxEnsureCapacity(sp, (emxArray__common *)likelihoods->GRADIENT_DIR_AVG, i0,
                    (int32_T)sizeof(real_T), &emlrtRTEI);
  loop_ub = RES_VH[0] * RES_VH[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    likelihoods->GRADIENT_DIR_AVG->data[i0] = 0.0;
  }

  i0 = likelihoods->TOT_ALL_BACK_UP->size[0] * likelihoods->
    TOT_ALL_BACK_UP->size[1] * likelihoods->TOT_ALL_BACK_UP->size[2];
  likelihoods->TOT_ALL_BACK_UP->size[0] = RES_VH[0];
  likelihoods->TOT_ALL_BACK_UP->size[1] = RES_VH[1];
  likelihoods->TOT_ALL_BACK_UP->size[2] = NBUFFER;
  emxEnsureCapacity(sp, (emxArray__common *)likelihoods->TOT_ALL_BACK_UP, i0,
                    (int32_T)sizeof(real_T), &emlrtRTEI);
  loop_ub = RES_VH[0] * RES_VH[1] * NBUFFER;
  for (i0 = 0; i0 < loop_ub; i0++) {
    likelihoods->TOT_ALL_BACK_UP->data[i0] = 0.0;
  }

  i0 = likelihoods->GRADIENT_DIR_ALL_BACK_UP->size[0] *
    likelihoods->GRADIENT_DIR_ALL_BACK_UP->size[1] *
    likelihoods->GRADIENT_DIR_ALL_BACK_UP->size[2];
  likelihoods->GRADIENT_DIR_ALL_BACK_UP->size[0] = RES_VH[0];
  likelihoods->GRADIENT_DIR_ALL_BACK_UP->size[1] = RES_VH[1];
  likelihoods->GRADIENT_DIR_ALL_BACK_UP->size[2] = NBUFFER;
  emxEnsureCapacity(sp, (emxArray__common *)
                    likelihoods->GRADIENT_DIR_ALL_BACK_UP, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = RES_VH[0] * RES_VH[1] * NBUFFER;
  for (i0 = 0; i0 < loop_ub; i0++) {
    likelihoods->GRADIENT_DIR_ALL_BACK_UP->data[i0] = 0.0;
  }

  i0 = likelihoods->TOT_FOCUSED->size[0] * likelihoods->TOT_FOCUSED->size[1];
  likelihoods->TOT_FOCUSED->size[0] = RES_VH[0];
  likelihoods->TOT_FOCUSED->size[1] = RES_VH[1];
  emxEnsureCapacity(sp, (emxArray__common *)likelihoods->TOT_FOCUSED, i0,
                    (int32_T)sizeof(real_T), &emlrtRTEI);
  loop_ub = RES_VH[0] * RES_VH[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    likelihoods->TOT_FOCUSED->data[i0] = 0.0;
  }

  i0 = masks->FOCUS->size[0] * masks->FOCUS->size[1];
  masks->FOCUS->size[0] = RES_VH[0];
  masks->FOCUS->size[1] = RES_VH[1];
  emxEnsureCapacity(sp, (emxArray__common *)masks->FOCUS, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = RES_VH[0] * RES_VH[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    masks->FOCUS->data[i0] = 1.0;
  }

  /* Redifinition in createEGOLaneMask()                         */
  /*  %                        segmentMask =struct;      */
  /*  %                         SEGMENT            = zeros( 480, 640 ); */
  /*  %                         SEGMENT_TIGHT      = zeros( 480, 640 ); */
  /*  %                         SEGMENT_VERY_TIGHT = zeros( 480, 640 ); */
  /*  %                         SEGMENT_WIDE       = zeros( 480, 640 );     */
  /*  %                          */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (run_Init_State.c) */
