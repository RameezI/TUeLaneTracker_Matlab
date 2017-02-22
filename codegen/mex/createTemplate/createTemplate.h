/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * createTemplate.h
 *
 * Code generation for function 'createTemplate'
 *
 */

#ifndef CREATETEMPLATE_H
#define CREATETEMPLATE_H

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
extern void createTemplate(const emlrtStack *sp, real32_T H, real32_T W,
  emxArray_real32_T *TEMPLATE);

#endif

/* End of code generation (createTemplate.h) */
