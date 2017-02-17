/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_Init_State_initialize.c
 *
 * Code generation for function 'run_Init_State_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_Init_State.h"
#include "run_Init_State_initialize.h"
#include "_coder_run_Init_State_mex.h"
#include "run_Init_State_data.h"

/* Function Declarations */
static void run_Init_State_once(void);

/* Function Definitions */
static void run_Init_State_once(void)
{
  covrtInstanceData *t0_data = NULL;
  emlrtCoverageInstance.data = t0_data;

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/rameez/TUE_Lane_Tracker_v4.0/run_Init_State.m", 0U, 1U,
                  5U, 0U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "run_Init_State", 0, -1, 4842);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 2315, -1, 4832);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 2209, -1, 2301);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 2061, -1, 2161);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1846, -1, 1896);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 346, -1, 1796);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 1811, 1840, 1905);
  covrtForInit(&emlrtCoverageInstance, 0U, 1U, 2167, 2201, 2310);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m", 1U, 1U,
                  7U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "createTemplate", 42, -1, 3190);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 6U, 3100, -1, 3172);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 5U, 2429, -1, 3050);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 2348, -1, 2379);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 1694, -1, 2304);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 980, -1, 1590);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 268, -1, 873);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 114, -1, 194);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 1U, 0U, 224, 242, 892);
  covrtForInit(&emlrtCoverageInstance, 1U, 1U, 932, 947, 1608);
  covrtForInit(&emlrtCoverageInstance, 1U, 2U, 1646, 1661, 2322);
  covrtForInit(&emlrtCoverageInstance, 1U, 3U, 2385, 2403, 3069);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);
}

void run_Init_State_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    run_Init_State_once();
  }
}

/* End of code generation (run_Init_State_initialize.c) */
