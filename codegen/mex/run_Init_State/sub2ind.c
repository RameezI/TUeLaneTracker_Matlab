/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sub2ind.c
 *
 * Code generation for function 'sub2ind'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_Init_State.h"
#include "sub2ind.h"

/* Function Definitions */
boolean_T allinrange(const emxArray_real32_T *x, int32_T hi)
{
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  boolean_T guard1 = false;
  boolean_T b0;
  k = 0;
  do {
    exitg1 = 0;
    if (k <= x->size[1] - 1) {
      guard1 = false;
      if (x->data[k] >= 1.0F) {
        if ((x->data[k] <= -2.14748365E+9F) || ((x->data[k] < 2.14748365E+9F) &&
             (hi >= (int32_T)muSingleScalarCeil(x->data[k])))) {
          p = true;
        } else {
          p = false;
        }

        if (p) {
          b0 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        b0 = false;
      }

      if (!b0) {
        p = false;
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return p;
}

/* End of code generation (sub2ind.c) */
