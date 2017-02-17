//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: VerifyLikelihoods.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 01-Feb-2017 21:08:45
//

// Include Files
#include "rt_nonfinite.h"
#include "VerifyLikelihoods.h"
#include "VerifyLikelihoods_emxutil.h"

// Function Definitions

//
// Arguments    : struct0_T *likelihoods
// Return Type  : void
//
void VerifyLikelihoods(struct0_T *likelihoods)
{
  emxArray_int32_T *r0;
  int loop_ub;
  int i0;
  emxArray_int32_T *r1;
  int unnamed_idx_1;
  int i1;
  emxInit_int32_T(&r0, 1);
  loop_ub = likelihoods->TOT_ALL->size[0];
  i0 = r0->size[0];
  r0->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(int));
  for (i0 = 0; i0 < loop_ub; i0++) {
    r0->data[i0] = i0;
  }

  emxInit_int32_T(&r1, 1);
  loop_ub = likelihoods->TOT_ALL->size[1];
  i0 = r1->size[0];
  r1->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)r1, i0, (int)sizeof(int));
  for (i0 = 0; i0 < loop_ub; i0++) {
    r1->data[i0] = i0;
  }

  loop_ub = r0->size[0];
  unnamed_idx_1 = r1->size[0];
  for (i0 = 0; i0 < unnamed_idx_1; i0++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      likelihoods->TOT_ALL->data[(r0->data[i1] + likelihoods->TOT_ALL->size[0] *
        r1->data[i0]) + likelihoods->TOT_ALL->size[0] * likelihoods->
        TOT_ALL->size[1]] = 1.0;
    }
  }

  emxFree_int32_T(&r1);
  emxFree_int32_T(&r0);
}

//
// File trailer for VerifyLikelihoods.cpp
//
// [EOF]
//
