/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imdilate.h
 *
 * Code generation for function 'imdilate'
 *
 */

#ifndef IMDILATE_H
#define IMDILATE_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "createTemplate_types.h"

/* Function Declarations */
extern void imdilate(const emlrtStack *sp, const emxArray_real32_T *A,
                     emxArray_real32_T *B);

#endif

/* End of code generation (imdilate.h) */
