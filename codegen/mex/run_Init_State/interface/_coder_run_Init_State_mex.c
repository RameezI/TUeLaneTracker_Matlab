/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_run_Init_State_mex.c
 *
 * Code generation for function '_coder_run_Init_State_mex'
 *
 */

/* Include files */
#include "run_Init_State.h"
#include "_coder_run_Init_State_mex.h"
#include "run_Init_State_terminate.h"
#include "_coder_run_Init_State_api.h"
#include "run_Init_State_initialize.h"
#include "run_Init_State_data.h"

/* Function Declarations */
static void run_Init_State_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T
  nrhs, const mxArray *prhs[4]);

/* Function Definitions */
static void run_Init_State_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T
  nrhs, const mxArray *prhs[4])
{
  int32_T n;
  const mxArray *inputs[4];
  const mxArray *outputs[4];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        14, "run_Init_State");
  }

  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "run_Init_State");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  run_Init_State_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  run_Init_State_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(run_Init_State_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  run_Init_State_initialize();

  /* Dispatch the entry-point. */
  run_Init_State_mexFunction(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_run_Init_State_mex.c) */
