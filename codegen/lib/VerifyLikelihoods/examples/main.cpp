//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 01-Feb-2017 21:08:45
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include "rt_nonfinite.h"
#include "VerifyLikelihoods.h"
#include "main.h"
#include "VerifyLikelihoods_terminate.h"
#include "VerifyLikelihoods_emxAPI.h"
#include "VerifyLikelihoods_initialize.h"

// Function Declarations
static void argInit_480x640_real_T(double result[307200]);
static void argInit_480x640x3_real_T(double result[921600]);
static double argInit_real_T();
static void argInit_struct0_T(struct0_T *result);
static emxArray_real_T *c_argInit_UnboundedxUnboundedxU();
static void main_VerifyLikelihoods();

// Function Definitions

//
// Arguments    : double result[307200]
// Return Type  : void
//
static void argInit_480x640_real_T(double result[307200])
{
  int idx0;
  int idx1;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 480; idx0++) {
    for (idx1 = 0; idx1 < 640; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + 480 * idx1] = argInit_real_T();
    }
  }
}

//
// Arguments    : double result[921600]
// Return Type  : void
//
static void argInit_480x640x3_real_T(double result[921600])
{
  int idx0;
  int idx1;
  int idx2;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 480; idx0++) {
    for (idx1 = 0; idx1 < 640; idx1++) {
      for (idx2 = 0; idx2 < 3; idx2++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result[(idx0 + 480 * idx1) + 307200 * idx2] = argInit_real_T();
      }
    }
  }
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : struct0_T *result
// Return Type  : void
//
static void argInit_struct0_T(struct0_T *result)
{
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result->TOT_ALL = c_argInit_UnboundedxUnboundedxU();
  argInit_480x640_real_T(result->TOT_MAX);
  argInit_480x640x3_real_T(result->GRADIENT_DIR_ALL);
  argInit_480x640_real_T(result->GRADIENT_DIR_AVG);
  argInit_480x640x3_real_T(result->TOT_ALL_BACK_UP);
  argInit_480x640x3_real_T(result->GRADIENT_DIR_ALL_BACK_UP);
  argInit_480x640_real_T(result->TOT_FOCUSED);
}

//
// Arguments    : void
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *c_argInit_UnboundedxUnboundedxU()
{
  emxArray_real_T *result;
  static int iv0[3] = { 2, 2, 2 };

  int idx0;
  int idx1;
  int idx2;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real_T(3, *(int (*)[3])&iv0[0]);

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      for (idx2 = 0; idx2 < result->size[2U]; idx2++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result->data[(idx0 + result->size[0] * idx1) + result->size[0] *
          result->size[1] * idx2] = argInit_real_T();
      }
    }
  }

  return result;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_VerifyLikelihoods()
{
  static struct0_T likelihoods;

  // Initialize function 'VerifyLikelihoods' input arguments.
  // Initialize function input argument 'likelihoods'.
  argInit_struct0_T(&likelihoods);

  // Call the entry-point 'VerifyLikelihoods'.
  VerifyLikelihoods(&likelihoods);
  emxDestroy_struct0_T(likelihoods);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  VerifyLikelihoods_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_VerifyLikelihoods();

  // Terminate the application.
  // You do not need to do this more than one time.
  VerifyLikelihoods_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
