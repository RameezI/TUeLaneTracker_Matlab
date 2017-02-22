/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * createTemplate_initialize.c
 *
 * Code generation for function 'createTemplate_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "createTemplate.h"
#include "createTemplate_initialize.h"
#include "_coder_createTemplate_mex.h"
#include "createTemplate_data.h"

/* Function Declarations */
static void createTemplate_once(void);

/* Function Definitions */
static void createTemplate_once(void)
{
  covrtInstanceData *t0_data = NULL;
  emlrtCoverageInstance.data = t0_data;

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/rameez/TUE_Lane_Tracker_v4.0/createTemplate.m", 0U, 1U,
                  7U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "createTemplate", 30, -1, 3178);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 3088, -1, 3160);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 2417, -1, 3038);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 2336, -1, 2367);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 1682, -1, 2292);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 968, -1, 1578);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 256, -1, 861);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 102, -1, 182);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 212, 230, 880);
  covrtForInit(&emlrtCoverageInstance, 0U, 1U, 920, 935, 1596);
  covrtForInit(&emlrtCoverageInstance, 0U, 2U, 1634, 1649, 2310);
  covrtForInit(&emlrtCoverageInstance, 0U, 3U, 2373, 2391, 3057);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void createTemplate_initialize(void)
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
    createTemplate_once();
  }
}

/* End of code generation (createTemplate_initialize.c) */
