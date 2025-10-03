/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code.c
 *
 * Code generated for Simulink model 'tv_code'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Oct  3 14:30:30 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "tv_code.h"
#include "rtwtypes.h"
#include "tv_code_private.h"
#include "tv_code_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Block signals (default storage) */
B_tv_code_T tv_code_B;

/* Continuous states */
X_tv_code_T tv_code_X;

/* Block states (default storage) */
DW_tv_code_T tv_code_DW;

/* Real-time model */
static RT_MODEL_tv_code_T tv_code_M_;
RT_MODEL_tv_code_T *const tv_code_M = &tv_code_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  tv_code_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  tv_code_step();
  tv_code_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  tv_code_step();
  tv_code_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  tv_code_step();
  tv_code_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* System initialize for atomic system: */
void tv_code_ax_filter_Init(DW_ax_filter_tv_code_T *localDW)
{
  b_dspcodegen_FIRFilter_tv_cod_T *iobj_0;
  int32_T i;
  static const real_T tmp[9] = { -0.005412996192943418, -0.00037695464995368688,
    0.082835378892191724, 0.25136596710560233, 0.34706570862151792,
    0.25136596710560233, 0.082835378892191724, -0.00037695464995368688,
    -0.005412996192943418 };

  /* Start for MATLABSystem: '<S2>/ax_filter' */
  localDW->obj._pobj0.matlabCodegenIsDeleted = true;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  if (localDW->obj.NumChannels == -1) {
    localDW->obj.NumChannels = 1;
  }

  iobj_0 = &localDW->obj._pobj0;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj._pobj0.isInitialized = 0;

  /* System object Constructor function: dsp.FIRFilter */
  localDW->obj._pobj0.cSFunObject.P0_InitialStates = 0.0;
  for (i = 0; i < 9; i++) {
    iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
  }

  localDW->obj._pobj0.matlabCodegenIsDeleted = false;
  localDW->obj.FilterObj = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;

  /* End of Start for MATLABSystem: '<S2>/ax_filter' */

  /* InitializeConditions for MATLABSystem: '<S2>/ax_filter' */
  iobj_0 = localDW->obj.FilterObj;
  if (iobj_0->isInitialized == 1) {
    /* System object Initialization function: dsp.FIRFilter */
    for (i = 0; i < 8; i++) {
      iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
    }
  }

  /* End of InitializeConditions for MATLABSystem: '<S2>/ax_filter' */
}

/* Output and update for atomic system: */
void tv_code_ax_filter(real_T rtu_0, B_ax_filter_tv_code_T *localB,
  DW_ax_filter_tv_code_T *localDW)
{
  b_dsp_FIRFilter_0_tv_code_T *obj_0;
  b_dspcodegen_FIRFilter_tv_cod_T *obj;
  real_T acc1;
  real_T zCurr;
  real_T zNext;
  int32_T n;

  /* MATLABSystem: '<S2>/ax_filter' */
  obj = localDW->obj.FilterObj;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (n = 0; n < 8; n++) {
      obj->cSFunObject.W0_states[n] = obj->cSFunObject.P0_InitialStates;
    }
  }

  obj_0 = &obj->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  acc1 = 0.0;

  /* load input sample */
  zNext = rtu_0;
  for (n = 0; n < 8; n++) {
    /* shift state */
    zCurr = zNext;
    zNext = obj_0->W0_states[n];
    obj_0->W0_states[n] = zCurr;

    /* compute one tap */
    zCurr *= obj_0->P1_Coefficients[n];
    acc1 += zCurr;
  }

  /* compute last tap */
  zCurr = obj->cSFunObject.P1_Coefficients[n] * zNext;

  /* MATLABSystem: '<S2>/ax_filter' */
  /* store output sample */
  localB->ax_filter = acc1 + zCurr;
}

/* Termination for atomic system: */
void tv_code_ax_filter_Term(DW_ax_filter_tv_code_T *localDW)
{
  b_dspcodegen_FIRFilter_tv_cod_T *obj;

  /* Terminate for MATLABSystem: '<S2>/ax_filter' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.FilterObj;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  if (!localDW->obj._pobj0.matlabCodegenIsDeleted) {
    localDW->obj._pobj0.matlabCodegenIsDeleted = true;
    if (localDW->obj._pobj0.isInitialized == 1) {
      localDW->obj._pobj0.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ax_filter' */
}

/*
 * Output and update for atomic system:
 *    '<S16>/MATLAB Function'
 *    '<S16>/MATLAB Function1'
 *    '<S16>/MATLAB Function2'
 *    '<S16>/MATLAB Function3'
 */
void tv_code_MATLABFunction(const real_T rtu_data[4221], real_T rtu_torque_req,
  real_T rtu_row_num, real_T *rty_idx)
{
  real_T differences[21];
  int32_T idx;
  int32_T iindx;
  int32_T k;
  for (k = 0; k < 21; k++) {
    differences[k] = fabs(rtu_data[(201 * k + (int32_T)rtu_row_num) - 1] -
                          rtu_torque_req);
  }

  if (!rtIsNaN(differences[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 22)) {
      if (!rtIsNaN(differences[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    iindx = 1;
  } else {
    real_T ex;
    ex = differences[idx - 1];
    iindx = idx;
    for (k = idx + 1; k < 22; k++) {
      real_T tmp;
      tmp = differences[k - 1];
      if (ex > tmp) {
        ex = tmp;
        iindx = k;
      }
    }
  }

  *rty_idx = iindx;
}

/* Model step function */
void tv_code_step(void)
{
  real_T Sum_d_tmp;
  real_T u2_tmp;
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&tv_code_M->solverInfo,((tv_code_M->Timing.clockTick0+
      1)*tv_code_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(tv_code_M)) {
    tv_code_M->Timing.t[0] = rtsiGetT(&tv_code_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* Gain: '<S16>/Gain1' incorporates:
     *  Constant: '<S2>/whl_speed_fl'
     *  Constant: '<S2>/whl_speed_fr'
     *  Constant: '<S2>/whl_speed_rl'
     *  Constant: '<S2>/whl_speed_rr'
     */
    tv_code_B.Gain1_b[0] = tv_code_P.Gain1_Gain_c * tv_code_P.whl_speed_fl_Value;
    tv_code_B.Gain1_b[1] = tv_code_P.Gain1_Gain_c * tv_code_P.whl_speed_fr_Value;
    tv_code_B.Gain1_b[2] = tv_code_P.Gain1_Gain_c * tv_code_P.whl_speed_rl_Value;
    tv_code_B.Gain1_b[3] = tv_code_P.Gain1_Gain_c * tv_code_P.whl_speed_rr_Value;

    /* Sum: '<S15>/Sum' incorporates:
     *  Constant: '<S14>/Constant'
     *  Constant: '<S2>/acc_pedal'
     *  Sum: '<S14>/Sum1'
     */
    tv_code_B.Sum_d = tv_code_P.acc_pedal_Value - tv_code_P.Constant_Value_g;

    /* Product: '<S14>/Product1' incorporates:
     *  Constant: '<S14>/Constant1'
     */
    tv_code_B.Product1 = 4.0 * tv_code_P.max_moment * tv_code_P.drive_ratio *
      tv_code_B.Sum_d;

    /* Sum: '<S15>/Sum' incorporates:
     *  Gain: '<S12>/Gain'
     */
    tv_code_B.Sum_d = tv_code_P.Gain_Gain_l * tv_code_B.Product1;

    /* Saturate: '<S12>/Saturation' */
    if (tv_code_B.Sum_d > tv_code_P.Saturation_UpperSat) {
      /* Saturate: '<S12>/Saturation' */
      tv_code_B.Saturation[0] = tv_code_P.Saturation_UpperSat;
    } else if (tv_code_B.Sum_d < tv_code_P.Saturation_LowerSat) {
      /* Saturate: '<S12>/Saturation' */
      tv_code_B.Saturation[0] = tv_code_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S12>/Saturation' */
      tv_code_B.Saturation[0] = tv_code_B.Sum_d;
    }

    if (tv_code_B.Sum_d > tv_code_P.Saturation_UpperSat) {
      /* Saturate: '<S12>/Saturation' */
      tv_code_B.Saturation[1] = tv_code_P.Saturation_UpperSat;
    } else if (tv_code_B.Sum_d < tv_code_P.Saturation_LowerSat) {
      /* Saturate: '<S12>/Saturation' */
      tv_code_B.Saturation[1] = tv_code_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S12>/Saturation' */
      tv_code_B.Saturation[1] = tv_code_B.Sum_d;
    }

    if (tv_code_B.Sum_d > tv_code_P.Saturation_UpperSat) {
      /* Saturate: '<S12>/Saturation' */
      tv_code_B.Saturation[2] = tv_code_P.Saturation_UpperSat;
    } else if (tv_code_B.Sum_d < tv_code_P.Saturation_LowerSat) {
      /* Saturate: '<S12>/Saturation' */
      tv_code_B.Saturation[2] = tv_code_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S12>/Saturation' */
      tv_code_B.Saturation[2] = tv_code_B.Sum_d;
    }

    if (tv_code_B.Sum_d > tv_code_P.Saturation_UpperSat) {
      /* Saturate: '<S12>/Saturation' */
      tv_code_B.Saturation[3] = tv_code_P.Saturation_UpperSat;
    } else if (tv_code_B.Sum_d < tv_code_P.Saturation_LowerSat) {
      /* Saturate: '<S12>/Saturation' */
      tv_code_B.Saturation[3] = tv_code_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S12>/Saturation' */
      tv_code_B.Saturation[3] = tv_code_B.Sum_d;
    }

    /* End of Saturate: '<S12>/Saturation' */

    /* Sum: '<S11>/Plus' incorporates:
     *  Constant: '<S2>/whl_speed_fl'
     *  Constant: '<S2>/whl_speed_fr'
     *  Constant: '<S2>/whl_speed_rl'
     *  Constant: '<S2>/whl_speed_rr'
     *  ManualSwitch: '<S10>/regen_switch'
     *  Sum: '<S22>/Add'
     *  Switch: '<S10>/Switch'
     */
    Sum_d_tmp = ((tv_code_P.whl_speed_fl_Value + tv_code_P.whl_speed_fr_Value) +
                 tv_code_P.whl_speed_rl_Value) + tv_code_P.whl_speed_rr_Value;

    /* Sum: '<S15>/Sum' incorporates:
     *  Gain: '<S11>/Gain'
     *  Sum: '<S11>/Plus'
     */
    tv_code_B.Sum_d = Sum_d_tmp;
    tv_code_B.Sum_d *= tv_code_P.Gain_Gain_a;

    /* Gain: '<S11>/Gain1' */
    tv_code_B.Gain1 = tv_code_P.rw * tv_code_B.Sum_d;

    /* Switch: '<S10>/Switch' incorporates:
     *  ManualSwitch: '<S10>/regen_switch'
     */
    if (tv_code_B.Product1 > tv_code_P.Switch_Threshold_p) {
      /* Switch: '<S10>/Switch' */
      tv_code_B.Switch = tv_code_B.Product1;
    } else {
      if (tv_code_P.regen_switch_CurrentSetting == 1) {
        /* ManualSwitch: '<S10>/regen_switch' incorporates:
         *  Constant: '<S10>/Constant'
         */
        tv_code_B.regen_switch = tv_code_P.Constant_Value;
      } else {
        /* Gain: '<S21>/Gain1' incorporates:
         *  ManualSwitch: '<S10>/regen_switch'
         *  Sum: '<S22>/Add'
         */
        tv_code_B.Gain1_jz = Sum_d_tmp;

        /* DotProduct: '<S22>/Dot Product' incorporates:
         *  Constant: '<S22>/I_max'
         *  Constant: '<S22>/Vdc'
         *  ManualSwitch: '<S10>/regen_switch'
         */
        tv_code_B.DotProduct_l = tv_code_P.I_max_Value * tv_code_P.Vdc_Value;

        /* Product: '<S22>/div2' incorporates:
         *  Gain: '<S22>/Gain'
         *  ManualSwitch: '<S10>/regen_switch'
         */
        tv_code_B.div2 = tv_code_P.Gain_Gain_m * tv_code_B.DotProduct_l;
        tv_code_B.div2 /= tv_code_B.Gain1_jz;

        /* Gain: '<S21>/X2' incorporates:
         *  Constant: '<S21>/Z1'
         *  Constant: '<S21>/Z2'
         *  Gain: '<S21>/X1'
         *  ManualSwitch: '<S10>/regen_switch'
         */
        Sum_d_tmp = tv_code_P.m * tv_code_P.g;

        /* Gain: '<S21>/Gain1' incorporates:
         *  Constant: '<S21>/Z2'
         *  Gain: '<S21>/Tr'
         *  Gain: '<S21>/X2'
         *  ManualSwitch: '<S10>/regen_switch'
         */
        tv_code_B.Gain1_jz = Sum_d_tmp * tv_code_P.lr / tv_code_P.L *
          tv_code_P.mu;
        tv_code_B.Gain1_jz *= tv_code_P.rw;
        tv_code_B.Gain1_jz *= 1.0 / tv_code_P.drive_ratio;

        /* MinMax: '<S10>/Max' incorporates:
         *  Constant: '<S10>/TT_max'
         *  Constant: '<S21>/Z1'
         *  Gain: '<S21>/Gain'
         *  Gain: '<S21>/Ta'
         *  Gain: '<S21>/X1'
         *  ManualSwitch: '<S10>/regen_switch'
         *  MinMax: '<S10>/Max of Elements'
         *  Sum: '<S10>/Sum'
         */
        tv_code_B.Max_a = Sum_d_tmp * tv_code_P.lf / tv_code_P.L * tv_code_P.mu;
        tv_code_B.Max_a *= tv_code_P.rw;
        tv_code_B.Max_a *= 1.0 / tv_code_P.drive_ratio;
        tv_code_B.Max_a += tv_code_B.Gain1_jz;
        tv_code_B.Max_a = fmin(tv_code_B.Max_a, tv_code_B.div2);
        tv_code_B.Max_a = fmax(tv_code_B.Max_a, tv_code_P.TT_max_Value);

        /* Gain: '<S10>/Gain1' incorporates:
         *  ManualSwitch: '<S10>/regen_switch'
         */
        tv_code_B.Gain1_m3 = tv_code_P.Gain1_Gain * tv_code_B.Max_a;

        /* ManualSwitch: '<S10>/regen_switch' */
        tv_code_B.regen_switch = tv_code_B.Gain1_m3;
      }

      /* Switch: '<S10>/Switch' */
      tv_code_B.Switch = tv_code_B.regen_switch;
    }

    /* Switch: '<S13>/Switch' */
    if (tv_code_B.Switch != 0.0) {
      /* Switch: '<S13>/Switch' incorporates:
       *  Constant: '<S13>/Constant'
       */
      tv_code_B.Switch_b = tv_code_P.Constant_Value_l;
    } else {
      /* Switch: '<S13>/Switch' incorporates:
       *  Constant: '<S13>/Constant1'
       */
      tv_code_B.Switch_b = tv_code_P.Constant1_Value;
    }

    /* End of Switch: '<S13>/Switch' */

    /* Constant: '<S2>/ax' */
    tv_code_ax_filter(tv_code_P.ax_Value, &tv_code_B.ax_filter,
                      &tv_code_DW.ax_filter);

    /* Sum: '<S15>/Sum' incorporates:
     *  Gain: '<S23>/Gain1'
     */
    tv_code_B.Sum_d = tv_code_P.h * tv_code_B.ax_filter.ax_filter;

    /* Constant: '<S2>/ay' */
    tv_code_ax_filter(tv_code_P.ay_Value, &tv_code_B.ay_filter,
                      &tv_code_DW.ay_filter);

    /* Saturate: '<S9>/Saturation' incorporates:
     *  Gain: '<S23>/Gain2'
     */
    tv_code_B.Saturation_j = tv_code_P.h * tv_code_P.lr / tv_code_P.ls *
      tv_code_B.ay_filter.ax_filter;

    /* Sum: '<S15>/Sum' incorporates:
     *  Constant: '<S23>/Constant'
     *  Gain: '<S23>/Gain'
     *  Sum: '<S23>/Sum'
     */
    tv_code_B.Sum_d = (tv_code_P.g * tv_code_P.lr - tv_code_B.Sum_d) -
      tv_code_B.Saturation_j;
    tv_code_B.Sum_d *= tv_code_P.m / (2.0 * tv_code_P.L);

    /* Gain: '<S27>/Gain1' */
    tv_code_B.Gain1_k = 1.0 / (tv_code_P.m * tv_code_P.g) * tv_code_B.Sum_d;

    /* Constant: '<S2>/yaw_rate' */
    tv_code_ax_filter(tv_code_P.yaw_rate_Value, &tv_code_B.yaw_rate_filter,
                      &tv_code_DW.yaw_rate_filter);

    /* Saturate: '<S9>/Saturation' incorporates:
     *  Constant: '<S2>/delta'
     *  Product: '<S9>/Product'
     */
    tv_code_B.Saturation_j = tv_code_P.delta_Value * tv_code_B.Gain1;

    /* Sum: '<S15>/Sum' incorporates:
     *  Constant: '<S9>/Constant'
     *  Gain: '<S9>/Desired Understeer Gradient'
     *  Gain: '<S9>/axlebase'
     *  Math: '<S9>/Square'
     *  Sum: '<S9>/Sum'
     */
    tv_code_B.Sum_d = tv_code_B.Gain1 * tv_code_B.Gain1;
    tv_code_B.Sum_d *= tv_code_P.Ku;
    tv_code_B.Sum_d += tv_code_P.Constant_Value_b;
    tv_code_B.Sum_d *= tv_code_P.L;

    /* Saturate: '<S9>/Saturation1' */
    if (tv_code_B.Sum_d > tv_code_P.Saturation1_UpperSat) {
      /* Sum: '<S15>/Sum' */
      tv_code_B.Sum_d = tv_code_P.Saturation1_UpperSat;
    } else if (tv_code_B.Sum_d < tv_code_P.Saturation1_LowerSat) {
      /* Sum: '<S15>/Sum' */
      tv_code_B.Sum_d = tv_code_P.Saturation1_LowerSat;
    }

    /* End of Saturate: '<S9>/Saturation1' */

    /* Saturate: '<S9>/Saturation' incorporates:
     *  Product: '<S9>/div3'
     */
    tv_code_B.Saturation_j /= tv_code_B.Sum_d;

    /* Saturate: '<S9>/Saturation' */
    if (tv_code_B.Saturation_j > tv_code_P.Saturation_UpperSat_o) {
      /* Saturate: '<S9>/Saturation' */
      tv_code_B.Saturation_j = tv_code_P.Saturation_UpperSat_o;
    } else if (tv_code_B.Saturation_j < tv_code_P.Saturation_LowerSat_k) {
      /* Saturate: '<S9>/Saturation' */
      tv_code_B.Saturation_j = tv_code_P.Saturation_LowerSat_k;
    }

    /* End of Saturate: '<S9>/Saturation' */

    /* Sum: '<S15>/Sum' */
    tv_code_B.Sum_d = tv_code_B.Saturation_j -
      tv_code_B.yaw_rate_filter.ax_filter;

    /* DotProduct: '<S15>/Dot Product' incorporates:
     *  Constant: '<S2>/Mz Proportional Gain'
     */
    tv_code_B.DotProduct = tv_code_P.Mz_p * tv_code_B.Sum_d;
  }

  /* Gain: '<S27>/Gain' incorporates:
   *  Integrator: '<S15>/Integrator'
   *  Sum: '<S16>/Sum'
   */
  tv_code_B.P_est = tv_code_X.Integrator_CSTATE;

  /* Sum: '<S15>/Sum1' */
  tv_code_B.Sum1 = tv_code_B.DotProduct + tv_code_B.P_est;

  /* Switch: '<S10>/Switch1' */
  if (tv_code_B.Product1 > tv_code_P.Switch1_Threshold) {
    /* Gain: '<S27>/Gain' incorporates:
     *  Sum: '<S16>/Sum'
     */
    tv_code_B.P_est = tv_code_B.Sum1;
  } else {
    /* Gain: '<S10>/Gain' */
    tv_code_B.Gain = tv_code_P.Gain_Gain * tv_code_B.Sum1;

    /* Gain: '<S27>/Gain' incorporates:
     *  Sum: '<S16>/Sum'
     */
    tv_code_B.P_est = tv_code_B.Gain;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* Gain: '<S27>/Gain' incorporates:
   *  Gain: '<S28>/Gain'
   *  Gain: '<S29>/Gain'
   *  Gain: '<S30>/Gain'
   */
  tv_code_B.P_est *= tv_code_P.rw / tv_code_P.ls;

  /* Gain: '<S16>/Gain13' incorporates:
   *  Gain: '<S27>/Gain'
   *  Product: '<S27>/Product'
   *  Sum: '<S27>/Sum'
   */
  tv_code_B.Gain13 = tv_code_B.P_est;
  tv_code_B.Gain13 = tv_code_B.Switch - tv_code_B.Gain13;
  tv_code_B.Gain13 *= tv_code_B.Gain1_k;

  /* Saturate: '<S13>/Saturation' incorporates:
   *  Saturate: '<S13>/Saturation1'
   *  Saturate: '<S13>/Saturation2'
   *  Saturate: '<S13>/Saturation3'
   */
  Sum_d_tmp = -tv_code_P.max_moment * tv_code_P.drive_ratio;
  u2_tmp = tv_code_P.max_moment * tv_code_P.drive_ratio;
  if (tv_code_B.Gain13 > u2_tmp) {
    /* Gain: '<S16>/Gain13' */
    tv_code_B.Gain13 = u2_tmp;
  } else if (tv_code_B.Gain13 < Sum_d_tmp) {
    /* Gain: '<S16>/Gain13' */
    tv_code_B.Gain13 = Sum_d_tmp;
  }

  /* End of Saturate: '<S13>/Saturation' */

  /* DotProduct: '<S13>/Dot Product' */
  tv_code_B.DotProduct_n = tv_code_B.Switch_b * tv_code_B.Gain13;
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* Gain: '<S3>/P_el' incorporates:
     *  Gain: '<S24>/Gain1'
     */
    tv_code_B.P_el = tv_code_P.h * tv_code_B.ax_filter.ax_filter;

    /* Sum: '<S6>/Sum' incorporates:
     *  Gain: '<S24>/Gain2'
     */
    tv_code_B.Sum_f = tv_code_P.h * tv_code_P.lr / tv_code_P.ls *
      tv_code_B.ay_filter.ax_filter;

    /* Gain: '<S3>/P_el' incorporates:
     *  Constant: '<S24>/Constant'
     *  Gain: '<S24>/Gain'
     *  Sum: '<S24>/Sum'
     */
    tv_code_B.P_el = (tv_code_P.g * tv_code_P.lr - tv_code_B.P_el) +
      tv_code_B.Sum_f;
    tv_code_B.P_el *= tv_code_P.m / (2.0 * tv_code_P.L);

    /* Gain: '<S28>/Gain1' */
    tv_code_B.Gain1_j = 1.0 / (tv_code_P.m * tv_code_P.g) * tv_code_B.P_el;
  }

  /* Gain: '<S16>/Gain13' incorporates:
   *  Gain: '<S28>/Gain'
   *  Product: '<S28>/Product'
   *  Sum: '<S28>/Sum'
   */
  tv_code_B.Gain13 = tv_code_B.P_est;
  tv_code_B.Gain13 += tv_code_B.Switch;
  tv_code_B.Gain13 *= tv_code_B.Gain1_j;

  /* Saturate: '<S13>/Saturation1' */
  if (tv_code_B.Gain13 > u2_tmp) {
    /* Gain: '<S16>/Gain13' */
    tv_code_B.Gain13 = u2_tmp;
  } else if (tv_code_B.Gain13 < Sum_d_tmp) {
    /* Gain: '<S16>/Gain13' */
    tv_code_B.Gain13 = Sum_d_tmp;
  }

  /* DotProduct: '<S13>/Dot Product1' */
  tv_code_B.DotProduct1 = tv_code_B.Switch_b * tv_code_B.Gain13;
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* Sum: '<S6>/Sum' incorporates:
     *  Gain: '<S25>/Gain1'
     */
    tv_code_B.Sum_f = tv_code_P.h * tv_code_B.ax_filter.ax_filter;

    /* Gain: '<S3>/P_el' incorporates:
     *  Gain: '<S25>/Gain2'
     */
    tv_code_B.P_el = tv_code_P.h * tv_code_P.lf / tv_code_P.ls *
      tv_code_B.ay_filter.ax_filter;

    /* Sum: '<S6>/Sum' incorporates:
     *  Constant: '<S25>/Constant'
     *  Gain: '<S25>/Gain'
     *  Sum: '<S25>/Sum'
     */
    tv_code_B.Sum_f = (tv_code_P.g * tv_code_P.lf + tv_code_B.Sum_f) -
      tv_code_B.P_el;
    tv_code_B.Sum_f *= tv_code_P.m / (2.0 * tv_code_P.L);

    /* Gain: '<S30>/Gain1' */
    tv_code_B.Gain1_d = 1.0 / (tv_code_P.m * tv_code_P.g) * tv_code_B.Sum_f;
  }

  /* Gain: '<S16>/Gain13' incorporates:
   *  Gain: '<S30>/Gain'
   *  Product: '<S30>/Product'
   *  Sum: '<S30>/Sum'
   */
  tv_code_B.Gain13 = tv_code_B.P_est;
  tv_code_B.Gain13 = tv_code_B.Switch - tv_code_B.Gain13;
  tv_code_B.Gain13 *= tv_code_B.Gain1_d;

  /* Saturate: '<S13>/Saturation2' */
  if (tv_code_B.Gain13 > u2_tmp) {
    /* Gain: '<S16>/Gain13' */
    tv_code_B.Gain13 = u2_tmp;
  } else if (tv_code_B.Gain13 < Sum_d_tmp) {
    /* Gain: '<S16>/Gain13' */
    tv_code_B.Gain13 = Sum_d_tmp;
  }

  /* DotProduct: '<S13>/Dot Product2' */
  tv_code_B.DotProduct2 = tv_code_B.Switch_b * tv_code_B.Gain13;
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* Sum: '<S6>/Sum' incorporates:
     *  Gain: '<S26>/Gain1'
     */
    tv_code_B.Sum_f = tv_code_P.h * tv_code_B.ax_filter.ax_filter;

    /* Gain: '<S3>/P_el' incorporates:
     *  Gain: '<S26>/Gain2'
     */
    tv_code_B.P_el = tv_code_P.h * tv_code_P.lf / tv_code_P.ls *
      tv_code_B.ay_filter.ax_filter;

    /* Sum: '<S6>/Sum' incorporates:
     *  Constant: '<S26>/Constant'
     *  Gain: '<S26>/Gain'
     *  Sum: '<S26>/Sum'
     */
    tv_code_B.Sum_f = (tv_code_P.g * tv_code_P.lf + tv_code_B.Sum_f) +
      tv_code_B.P_el;
    tv_code_B.Sum_f *= tv_code_P.m / (2.0 * tv_code_P.L);

    /* Gain: '<S29>/Gain1' */
    tv_code_B.Gain1_m = 1.0 / (tv_code_P.m * tv_code_P.g) * tv_code_B.Sum_f;
  }

  /* Gain: '<S27>/Gain' incorporates:
   *  Product: '<S29>/Product'
   *  Sum: '<S16>/Sum'
   *  Sum: '<S29>/Sum'
   */
  tv_code_B.P_est += tv_code_B.Switch;
  tv_code_B.P_est *= tv_code_B.Gain1_m;

  /* Saturate: '<S13>/Saturation3' */
  if (tv_code_B.P_est > u2_tmp) {
    /* Gain: '<S27>/Gain' incorporates:
     *  Sum: '<S16>/Sum'
     */
    tv_code_B.P_est = u2_tmp;
  } else if (tv_code_B.P_est < Sum_d_tmp) {
    /* Gain: '<S27>/Gain' incorporates:
     *  Sum: '<S16>/Sum'
     */
    tv_code_B.P_est = Sum_d_tmp;
  }

  /* DotProduct: '<S13>/Dot Product3' */
  tv_code_B.DotProduct3 = tv_code_B.Switch_b * tv_code_B.P_est;

  /* Switch: '<S4>/speed_switch' */
  if (tv_code_B.Gain1 > tv_code_P.speed_switch_Threshold) {
    /* Switch: '<S4>/speed_switch' */
    tv_code_B.speed_switch[0] = tv_code_B.DotProduct_n;
    tv_code_B.speed_switch[1] = tv_code_B.DotProduct1;
    tv_code_B.speed_switch[2] = tv_code_B.DotProduct2;
    tv_code_B.speed_switch[3] = tv_code_B.DotProduct3;
  } else {
    /* Switch: '<S4>/speed_switch' */
    tv_code_B.speed_switch[0] = tv_code_B.Saturation[0];
    tv_code_B.speed_switch[1] = tv_code_B.Saturation[1];
    tv_code_B.speed_switch[2] = tv_code_B.Saturation[2];
    tv_code_B.speed_switch[3] = tv_code_B.Saturation[3];
  }

  /* End of Switch: '<S4>/speed_switch' */

  /* TransferFcn: '<S3>/Transfer Fcn' */
  tv_code_B.TransferFcn = tv_code_P.TransferFcn_C * tv_code_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* Saturate: '<S7>/Saturation3' incorporates:
     *  Constant: '<S2>/whl_speed_fl'
     */
    if (tv_code_P.whl_speed_fl_Value > tv_code_P.Saturation3_UpperSat) {
      /* Saturate: '<S7>/Saturation3' */
      tv_code_B.Saturation3 = tv_code_P.Saturation3_UpperSat;
    } else if (tv_code_P.whl_speed_fl_Value < tv_code_P.Saturation3_LowerSat) {
      /* Saturate: '<S7>/Saturation3' */
      tv_code_B.Saturation3 = tv_code_P.Saturation3_LowerSat;
    } else {
      /* Saturate: '<S7>/Saturation3' */
      tv_code_B.Saturation3 = tv_code_P.whl_speed_fl_Value;
    }

    /* End of Saturate: '<S7>/Saturation3' */

    /* Saturate: '<S7>/Saturation2' incorporates:
     *  Constant: '<S2>/whl_speed_fr'
     */
    if (tv_code_P.whl_speed_fr_Value > tv_code_P.Saturation2_UpperSat) {
      /* Saturate: '<S7>/Saturation2' */
      tv_code_B.Saturation2 = tv_code_P.Saturation2_UpperSat;
    } else if (tv_code_P.whl_speed_fr_Value < tv_code_P.Saturation2_LowerSat) {
      /* Saturate: '<S7>/Saturation2' */
      tv_code_B.Saturation2 = tv_code_P.Saturation2_LowerSat;
    } else {
      /* Saturate: '<S7>/Saturation2' */
      tv_code_B.Saturation2 = tv_code_P.whl_speed_fr_Value;
    }

    /* End of Saturate: '<S7>/Saturation2' */

    /* Saturate: '<S7>/Saturation1' incorporates:
     *  Constant: '<S2>/whl_speed_rl'
     */
    if (tv_code_P.whl_speed_rl_Value > tv_code_P.Saturation1_UpperSat_p) {
      /* Saturate: '<S7>/Saturation1' */
      tv_code_B.Saturation1 = tv_code_P.Saturation1_UpperSat_p;
    } else if (tv_code_P.whl_speed_rl_Value < tv_code_P.Saturation1_LowerSat_e)
    {
      /* Saturate: '<S7>/Saturation1' */
      tv_code_B.Saturation1 = tv_code_P.Saturation1_LowerSat_e;
    } else {
      /* Saturate: '<S7>/Saturation1' */
      tv_code_B.Saturation1 = tv_code_P.whl_speed_rl_Value;
    }

    /* End of Saturate: '<S7>/Saturation1' */

    /* Saturate: '<S7>/Saturation' incorporates:
     *  Constant: '<S2>/whl_speed_rr'
     */
    if (tv_code_P.whl_speed_rr_Value > tv_code_P.Saturation_UpperSat_f) {
      /* Saturate: '<S7>/Saturation' */
      tv_code_B.Saturation_c = tv_code_P.Saturation_UpperSat_f;
    } else if (tv_code_P.whl_speed_rr_Value < tv_code_P.Saturation_LowerSat_g) {
      /* Saturate: '<S7>/Saturation' */
      tv_code_B.Saturation_c = tv_code_P.Saturation_LowerSat_g;
    } else {
      /* Saturate: '<S7>/Saturation' */
      tv_code_B.Saturation_c = tv_code_P.whl_speed_rr_Value;
    }

    /* End of Saturate: '<S7>/Saturation' */

    /* Sum: '<S7>/Sum' */
    tv_code_B.Sum = ((tv_code_B.Saturation3 + tv_code_B.Saturation2) +
                     tv_code_B.Saturation1) + tv_code_B.Saturation_c;
  }

  /* ManualSwitch: '<S1>/Manual Switch' incorporates:
   *  Switch: '<S7>/Switch'
   */
  if (tv_code_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<S1>/Manual Switch' */
    tv_code_B.ManualSwitch[0] = tv_code_B.speed_switch[0];
    tv_code_B.ManualSwitch[1] = tv_code_B.speed_switch[1];
    tv_code_B.ManualSwitch[2] = tv_code_B.speed_switch[2];
    tv_code_B.ManualSwitch[3] = tv_code_B.speed_switch[3];
  } else {
    if (tv_code_B.Sum > tv_code_P.Switch_Threshold) {
      /* Product: '<S7>/Divide3' incorporates:
       *  Gain: '<S3>/ref_p_max'
       *  Switch: '<S7>/Switch'
       */
      tv_code_B.T_max = tv_code_P.P_max * tv_code_B.TransferFcn;

      /* Product: '<S7>/Divide2' incorporates:
       *  Product: '<S7>/Divide'
       *  Switch: '<S7>/Switch'
       */
      tv_code_B.T_max_b = tv_code_B.T_max / tv_code_B.Saturation3;

      /* MinMax: '<S7>/Min' incorporates:
       *  Switch: '<S7>/Switch'
       */
      tv_code_B.Min = fmin(tv_code_B.speed_switch[0], tv_code_B.T_max_b);

      /* Product: '<S7>/Divide2' incorporates:
       *  Product: '<S7>/Divide1'
       *  Switch: '<S7>/Switch'
       */
      tv_code_B.T_max_b = tv_code_B.T_max / tv_code_B.Saturation2;

      /* MinMax: '<S7>/Min1' incorporates:
       *  Switch: '<S7>/Switch'
       */
      tv_code_B.Min1 = fmin(tv_code_B.speed_switch[1], tv_code_B.T_max_b);

      /* Product: '<S7>/Divide2' incorporates:
       *  Switch: '<S7>/Switch'
       */
      tv_code_B.T_max_b = tv_code_B.T_max / tv_code_B.Saturation1;

      /* MinMax: '<S7>/Min2' incorporates:
       *  Switch: '<S7>/Switch'
       */
      tv_code_B.Min2 = fmin(tv_code_B.speed_switch[2], tv_code_B.T_max_b);

      /* Product: '<S7>/Divide3' incorporates:
       *  Switch: '<S7>/Switch'
       */
      tv_code_B.T_max /= tv_code_B.Saturation_c;

      /* MinMax: '<S7>/Min3' incorporates:
       *  Switch: '<S7>/Switch'
       */
      tv_code_B.Min3 = fmin(tv_code_B.speed_switch[3], tv_code_B.T_max);

      /* Switch: '<S7>/Switch' */
      tv_code_B.Switch_i[0] = tv_code_B.Min;
      tv_code_B.Switch_i[1] = tv_code_B.Min1;
      tv_code_B.Switch_i[2] = tv_code_B.Min2;
      tv_code_B.Switch_i[3] = tv_code_B.Min3;
    } else {
      /* Switch: '<S7>/Switch' */
      tv_code_B.Switch_i[0] = tv_code_B.speed_switch[0];
      tv_code_B.Switch_i[1] = tv_code_B.speed_switch[1];
      tv_code_B.Switch_i[2] = tv_code_B.speed_switch[2];
      tv_code_B.Switch_i[3] = tv_code_B.speed_switch[3];
    }

    /* ManualSwitch: '<S1>/Manual Switch' */
    tv_code_B.ManualSwitch[0] = tv_code_B.Switch_i[0];
    tv_code_B.ManualSwitch[1] = tv_code_B.Switch_i[1];
    tv_code_B.ManualSwitch[2] = tv_code_B.Switch_i[2];
    tv_code_B.ManualSwitch[3] = tv_code_B.Switch_i[3];
  }

  /* End of ManualSwitch: '<S1>/Manual Switch' */

  /* Gain: '<Root>/trq_fl' */
  tv_code_B.trq_fl = tv_code_P.trq_fl_Gain * tv_code_B.ManualSwitch[0];

  /* Gain: '<Root>/trq_fr' */
  tv_code_B.trq_fr = tv_code_P.trq_fr_Gain * tv_code_B.ManualSwitch[1];

  /* Gain: '<Root>/trq_rl' */
  tv_code_B.trq_rl = tv_code_P.trq_rl_Gain * tv_code_B.ManualSwitch[2];

  /* Gain: '<Root>/trq_rr' */
  tv_code_B.trq_rr = tv_code_P.trq_rr_Gain * tv_code_B.ManualSwitch[3];
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* Saturate: '<S16>/Saturation3' */
    if (tv_code_B.Gain1_b[3] > tv_code_P.Saturation3_UpperSat_m) {
      /* Saturate: '<S16>/Saturation3' */
      tv_code_B.Saturation3_l = tv_code_P.Saturation3_UpperSat_m;
    } else if (tv_code_B.Gain1_b[3] < tv_code_P.Saturation3_LowerSat_i) {
      /* Saturate: '<S16>/Saturation3' */
      tv_code_B.Saturation3_l = tv_code_P.Saturation3_LowerSat_i;
    } else {
      /* Saturate: '<S16>/Saturation3' */
      tv_code_B.Saturation3_l = tv_code_B.Gain1_b[3];
    }

    /* End of Saturate: '<S16>/Saturation3' */

    /* Sum: '<S6>/Sum' incorporates:
     *  Lookup_n-D: '<S16>/Row index3'
     *  Saturate: '<S16>/Saturation3'
     */
    tv_code_B.Sum_f = look1_binlxpw(tv_code_B.Saturation3_l,
      tv_code_P.Rowindex3_bp01Data, tv_code_P.Rowindex3_tableData, 200U);

    /* Saturate: '<S16>/Saturation4' */
    if (tv_code_B.Sum_f > tv_code_P.Saturation4_UpperSat) {
      /* Sum: '<S6>/Sum' */
      tv_code_B.Sum_f = tv_code_P.Saturation4_UpperSat;
    } else if (tv_code_B.Sum_f < tv_code_P.Saturation4_LowerSat) {
      /* Sum: '<S6>/Sum' */
      tv_code_B.Sum_f = tv_code_P.Saturation4_LowerSat;
    }

    /* End of Saturate: '<S16>/Saturation4' */

    /* Rounding: '<S16>/Ceil3' */
    tv_code_B.Ceil3 = ceil(tv_code_B.Sum_f);
  }

  /* MATLAB Function: '<S16>/MATLAB Function3' incorporates:
   *  Constant: '<S16>/Constant7'
   */
  tv_code_MATLABFunction(tv_code_P.torque_map, tv_code_B.DotProduct3,
    tv_code_B.Ceil3, &tv_code_B.Torquefixed);

  /* Gain: '<S16>/Gain13' incorporates:
   *  Constant: '<S16>/Constant6'
   *  Lookup_n-D: '<S16>/n-D Lookup Table4'
   *  Rounding: '<S16>/Ceil3'
   *  Sum: '<S16>/Add3'
   */
  tv_code_B.Gain13 = tv_code_B.Torquefixed - tv_code_P.Constant6_Value;
  tv_code_B.Gain13 = look2_binlxpw(tv_code_B.Ceil3, tv_code_B.Gain13,
    tv_code_P.nDLookupTable4_bp01Data, tv_code_P.nDLookupTable4_bp02Data,
    tv_code_P.stator_current_line_rms, tv_code_P.nDLookupTable4_maxIndex, 201U);

  /* Gain: '<S27>/Gain' incorporates:
   *  Gain: '<S16>/Gain13'
   *  Lookup_n-D: '<S16>/2-D Lookup Table3'
   *  Saturate: '<S16>/Saturation3'
   *  Sum: '<S16>/Sum'
   */
  tv_code_B.P_est = look2_binlxpw(tv_code_B.Saturation3_l, tv_code_B.Gain13,
    tv_code_P.uDLookupTable3_bp01Data, tv_code_P.uDLookupTable3_bp02Data,
    tv_code_P.voltage_map, tv_code_P.uDLookupTable3_maxIndex, 201U);

  /* Gain: '<S16>/Gain13' incorporates:
   *  Product: '<S16>/Product3'
   */
  tv_code_B.Gain13 *= tv_code_B.P_est;
  tv_code_B.Gain13 *= tv_code_P.Gain13_Gain;
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* Saturate: '<S16>/Saturation' */
    if (tv_code_B.Gain1_b[0] > tv_code_P.Saturation_UpperSat_or) {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation_p = tv_code_P.Saturation_UpperSat_or;
    } else if (tv_code_B.Gain1_b[0] < tv_code_P.Saturation_LowerSat_b) {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation_p = tv_code_P.Saturation_LowerSat_b;
    } else {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation_p = tv_code_B.Gain1_b[0];
    }

    /* End of Saturate: '<S16>/Saturation' */

    /* Sum: '<S6>/Sum' incorporates:
     *  Lookup_n-D: '<S16>/Row index'
     *  Saturate: '<S16>/Saturation'
     */
    tv_code_B.Sum_f = look1_binlxpw(tv_code_B.Saturation_p,
      tv_code_P.Rowindex_bp01Data, tv_code_P.Rowindex_tableData, 200U);

    /* Saturate: '<S16>/Saturation7' */
    if (tv_code_B.Sum_f > tv_code_P.Saturation7_UpperSat) {
      /* Sum: '<S6>/Sum' */
      tv_code_B.Sum_f = tv_code_P.Saturation7_UpperSat;
    } else if (tv_code_B.Sum_f < tv_code_P.Saturation7_LowerSat) {
      /* Sum: '<S6>/Sum' */
      tv_code_B.Sum_f = tv_code_P.Saturation7_LowerSat;
    }

    /* End of Saturate: '<S16>/Saturation7' */

    /* Rounding: '<S16>/Ceil' */
    tv_code_B.Ceil = ceil(tv_code_B.Sum_f);
  }

  /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
   *  Constant: '<S16>/Constant2'
   */
  tv_code_MATLABFunction(tv_code_P.torque_map, tv_code_B.DotProduct_n,
    tv_code_B.Ceil, &tv_code_B.Torquefixed);

  /* Gain: '<S27>/Gain' incorporates:
   *  Constant: '<S16>/Constant'
   *  Lookup_n-D: '<S16>/n-D Lookup Table1'
   *  Rounding: '<S16>/Ceil'
   *  Sum: '<S16>/Add'
   *  Sum: '<S16>/Sum'
   */
  tv_code_B.P_est = tv_code_B.Torquefixed - tv_code_P.Constant_Value_e;
  tv_code_B.P_est = look2_binlxpw(tv_code_B.Ceil, tv_code_B.P_est,
    tv_code_P.nDLookupTable1_bp01Data, tv_code_P.nDLookupTable1_bp02Data,
    tv_code_P.stator_current_line_rms, tv_code_P.nDLookupTable1_maxIndex, 201U);

  /* Gain: '<S16>/Gain11' incorporates:
   *  Lookup_n-D: '<S16>/2-D Lookup Table'
   *  Saturate: '<S16>/Saturation'
   *  Sum: '<S16>/Sum'
   */
  tv_code_B.Gain11 = look2_binlxpw(tv_code_B.Saturation_p, tv_code_B.P_est,
    tv_code_P.uDLookupTable_bp01Data, tv_code_P.uDLookupTable_bp02Data,
    tv_code_P.voltage_map, tv_code_P.uDLookupTable_maxIndex, 201U);

  /* Gain: '<S27>/Gain' incorporates:
   *  Gain: '<S16>/Gain10'
   *  Product: '<S16>/Product'
   *  Sum: '<S16>/Sum'
   */
  tv_code_B.P_est *= tv_code_B.Gain11;
  tv_code_B.P_est *= tv_code_P.Gain10_Gain;
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* Saturate: '<S16>/Saturation1' */
    if (tv_code_B.Gain1_b[1] > tv_code_P.Saturation1_UpperSat_c) {
      /* Saturate: '<S16>/Saturation1' */
      tv_code_B.Saturation1_c = tv_code_P.Saturation1_UpperSat_c;
    } else if (tv_code_B.Gain1_b[1] < tv_code_P.Saturation1_LowerSat_h) {
      /* Saturate: '<S16>/Saturation1' */
      tv_code_B.Saturation1_c = tv_code_P.Saturation1_LowerSat_h;
    } else {
      /* Saturate: '<S16>/Saturation1' */
      tv_code_B.Saturation1_c = tv_code_B.Gain1_b[1];
    }

    /* End of Saturate: '<S16>/Saturation1' */

    /* Sum: '<S6>/Sum' incorporates:
     *  Lookup_n-D: '<S16>/Row index1'
     *  Saturate: '<S16>/Saturation1'
     */
    tv_code_B.Sum_f = look1_binlxpw(tv_code_B.Saturation1_c,
      tv_code_P.Rowindex1_bp01Data, tv_code_P.Rowindex1_tableData, 200U);

    /* Saturate: '<S16>/Saturation6' */
    if (tv_code_B.Sum_f > tv_code_P.Saturation6_UpperSat) {
      /* Sum: '<S6>/Sum' */
      tv_code_B.Sum_f = tv_code_P.Saturation6_UpperSat;
    } else if (tv_code_B.Sum_f < tv_code_P.Saturation6_LowerSat) {
      /* Sum: '<S6>/Sum' */
      tv_code_B.Sum_f = tv_code_P.Saturation6_LowerSat;
    }

    /* End of Saturate: '<S16>/Saturation6' */

    /* Rounding: '<S16>/Ceil1' */
    tv_code_B.Ceil1 = ceil(tv_code_B.Sum_f);
  }

  /* MATLAB Function: '<S16>/MATLAB Function1' incorporates:
   *  Constant: '<S16>/Constant3'
   */
  tv_code_MATLABFunction(tv_code_P.torque_map, tv_code_B.DotProduct1,
    tv_code_B.Ceil1, &tv_code_B.Torquefixed);

  /* Gain: '<S16>/Gain11' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Lookup_n-D: '<S16>/n-D Lookup Table2'
   *  Rounding: '<S16>/Ceil1'
   *  Sum: '<S16>/Add1'
   */
  tv_code_B.Gain11 = tv_code_B.Torquefixed - tv_code_P.Constant1_Value_n;
  tv_code_B.Gain11 = look2_binlxpw(tv_code_B.Ceil1, tv_code_B.Gain11,
    tv_code_P.nDLookupTable2_bp01Data, tv_code_P.nDLookupTable2_bp02Data,
    tv_code_P.stator_current_line_rms, tv_code_P.nDLookupTable2_maxIndex, 201U);

  /* Gain: '<S8>/ki' incorporates:
   *  Gain: '<S16>/Gain11'
   *  Lookup_n-D: '<S16>/2-D Lookup Table1'
   *  Saturate: '<S16>/Saturation1'
   */
  tv_code_B.ki = look2_binlxpw(tv_code_B.Saturation1_c, tv_code_B.Gain11,
    tv_code_P.uDLookupTable1_bp01Data, tv_code_P.uDLookupTable1_bp02Data,
    tv_code_P.voltage_map, tv_code_P.uDLookupTable1_maxIndex, 201U);

  /* Gain: '<S16>/Gain11' incorporates:
   *  Product: '<S16>/Product1'
   */
  tv_code_B.Gain11 *= tv_code_B.ki;
  tv_code_B.Gain11 *= tv_code_P.Gain11_Gain;
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* Saturate: '<S16>/Saturation2' */
    if (tv_code_B.Gain1_b[2] > tv_code_P.Saturation2_UpperSat_d) {
      /* Saturate: '<S16>/Saturation2' */
      tv_code_B.Saturation2_a = tv_code_P.Saturation2_UpperSat_d;
    } else if (tv_code_B.Gain1_b[2] < tv_code_P.Saturation2_LowerSat_d) {
      /* Saturate: '<S16>/Saturation2' */
      tv_code_B.Saturation2_a = tv_code_P.Saturation2_LowerSat_d;
    } else {
      /* Saturate: '<S16>/Saturation2' */
      tv_code_B.Saturation2_a = tv_code_B.Gain1_b[2];
    }

    /* End of Saturate: '<S16>/Saturation2' */

    /* Sum: '<S6>/Sum' incorporates:
     *  Lookup_n-D: '<S16>/Row index2'
     *  Saturate: '<S16>/Saturation2'
     */
    tv_code_B.Sum_f = look1_binlxpw(tv_code_B.Saturation2_a,
      tv_code_P.Rowindex2_bp01Data, tv_code_P.Rowindex2_tableData, 200U);

    /* Saturate: '<S16>/Saturation5' */
    if (tv_code_B.Sum_f > tv_code_P.Saturation5_UpperSat) {
      /* Sum: '<S6>/Sum' */
      tv_code_B.Sum_f = tv_code_P.Saturation5_UpperSat;
    } else if (tv_code_B.Sum_f < tv_code_P.Saturation5_LowerSat) {
      /* Sum: '<S6>/Sum' */
      tv_code_B.Sum_f = tv_code_P.Saturation5_LowerSat;
    }

    /* End of Saturate: '<S16>/Saturation5' */

    /* Rounding: '<S16>/Ceil2' */
    tv_code_B.Ceil2 = ceil(tv_code_B.Sum_f);
  }

  /* MATLAB Function: '<S16>/MATLAB Function2' incorporates:
   *  Constant: '<S16>/Constant5'
   */
  tv_code_MATLABFunction(tv_code_P.torque_map, tv_code_B.DotProduct2,
    tv_code_B.Ceil2, &tv_code_B.Torquefixed);

  /* Gain: '<S8>/ki' incorporates:
   *  Constant: '<S16>/Constant4'
   *  Lookup_n-D: '<S16>/n-D Lookup Table3'
   *  Rounding: '<S16>/Ceil2'
   *  Sum: '<S16>/Add2'
   */
  tv_code_B.ki = tv_code_B.Torquefixed - tv_code_P.Constant4_Value;
  tv_code_B.ki = look2_binlxpw(tv_code_B.Ceil2, tv_code_B.ki,
    tv_code_P.nDLookupTable3_bp01Data, tv_code_P.nDLookupTable3_bp02Data,
    tv_code_P.stator_current_line_rms, tv_code_P.nDLookupTable3_maxIndex, 201U);

  /* Sum: '<S8>/Sum' incorporates:
   *  Gain: '<S8>/ki'
   *  Lookup_n-D: '<S16>/2-D Lookup Table2'
   *  Saturate: '<S16>/Saturation2'
   */
  tv_code_B.Torquefixed = look2_binlxpw(tv_code_B.Saturation2_a, tv_code_B.ki,
    tv_code_P.uDLookupTable2_bp01Data, tv_code_P.uDLookupTable2_bp02Data,
    tv_code_P.voltage_map, tv_code_P.uDLookupTable2_maxIndex, 201U);

  /* Gain: '<S8>/ki' incorporates:
   *  Gain: '<S16>/Gain12'
   *  Product: '<S16>/Product2'
   */
  tv_code_B.ki *= tv_code_B.Torquefixed;
  tv_code_B.ki *= tv_code_P.Gain12_Gain;

  /* Gain: '<S27>/Gain' incorporates:
   *  Sum: '<S16>/Sum'
   */
  tv_code_B.P_est = ((tv_code_B.P_est + tv_code_B.Gain11) + tv_code_B.ki) +
    tv_code_B.Gain13;

  /* Sum: '<S8>/Sum' incorporates:
   *  Constant: '<S8>/Max_power'
   *  Sum: '<S8>/Sum1'
   */
  tv_code_B.Torquefixed = tv_code_B.P_est - tv_code_P.P_max;

  /* Saturate: '<S8>/Saturation' */
  if (tv_code_B.Torquefixed > tv_code_P.Saturation_UpperSat_d) {
    /* Saturate: '<S8>/Saturation' */
    tv_code_B.PowerError = tv_code_P.Saturation_UpperSat_d;
  } else if (tv_code_B.Torquefixed < tv_code_P.Saturation_LowerSat_h) {
    /* Saturate: '<S8>/Saturation' */
    tv_code_B.PowerError = tv_code_P.Saturation_LowerSat_h;
  } else {
    /* Saturate: '<S8>/Saturation' */
    tv_code_B.PowerError = tv_code_B.Torquefixed;
  }

  /* End of Saturate: '<S8>/Saturation' */
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* MinMax: '<S8>/Max' incorporates:
     *  Constant: '<S2>/whl_speed_fl'
     *  Constant: '<S2>/whl_speed_fr'
     *  Constant: '<S2>/whl_speed_rl'
     *  Constant: '<S2>/whl_speed_rr'
     */
    tv_code_B.Max = fmin(fmin(fmin(tv_code_P.whl_speed_fl_Value,
      tv_code_P.whl_speed_fr_Value), tv_code_P.whl_speed_rl_Value),
                         tv_code_P.whl_speed_rr_Value);

    /* DotProduct: '<S15>/Dot Product1' incorporates:
     *  Constant: '<S2>/Mz Integative Gain'
     */
    tv_code_B.DotProduct1_a = tv_code_B.Sum_d * tv_code_P.Mz_I;

    /* Gain: '<S9>/yaw_ref' */
    tv_code_B.yaw_ref = tv_code_P.yaw_ref_Gain * tv_code_B.Saturation_j;

    /* DotProduct: '<S6>/Dot Product3' incorporates:
     *  Constant: '<S1>/trq_rr_in'
     *  Constant: '<S2>/whl_speed_rr'
     */
    tv_code_B.DotProduct3_n = tv_code_P.trq_rr_in_Value *
      tv_code_P.whl_speed_rr_Value;

    /* DotProduct: '<S6>/Dot Product' incorporates:
     *  Constant: '<S1>/trq_fl_in'
     *  Constant: '<S2>/whl_speed_fl'
     */
    tv_code_B.DotProduct_i = tv_code_P.trq_fl_in_Value *
      tv_code_P.whl_speed_fl_Value;

    /* DotProduct: '<S6>/Dot Product1' incorporates:
     *  Constant: '<S1>/trq_fr_in'
     *  Constant: '<S2>/whl_speed_fr'
     */
    tv_code_B.DotProduct1_l = tv_code_P.trq_fr_in_Value *
      tv_code_P.whl_speed_fr_Value;

    /* DotProduct: '<S6>/Dot Product2' incorporates:
     *  Constant: '<S1>/trq_rl_in'
     *  Constant: '<S2>/whl_speed_rl'
     */
    tv_code_B.DotProduct2_a = tv_code_P.trq_rl_in_Value *
      tv_code_P.whl_speed_rl_Value;

    /* Sum: '<S6>/Sum' */
    tv_code_B.Sum_f = ((tv_code_B.DotProduct_i + tv_code_B.DotProduct1_l) +
                       tv_code_B.DotProduct2_a) + tv_code_B.DotProduct3_n;

    /* Saturate: '<S3>/Saturation' */
    if (tv_code_P.batt_curr > tv_code_P.Saturation_UpperSat_dt) {
      /* Gain: '<S3>/P_el' */
      tv_code_B.P_el = tv_code_P.Saturation_UpperSat_dt;
    } else if (tv_code_P.batt_curr < tv_code_P.Saturation_LowerSat_a) {
      /* Gain: '<S3>/P_el' */
      tv_code_B.P_el = tv_code_P.Saturation_LowerSat_a;
    } else {
      /* Gain: '<S3>/P_el' */
      tv_code_B.P_el = tv_code_P.batt_curr;
    }

    /* End of Saturate: '<S3>/Saturation' */

    /* Gain: '<S3>/P_el' */
    tv_code_B.P_el *= tv_code_P.batt_voltage;

    /* Product: '<S5>/Divide' */
    tv_code_B.Divide = tv_code_B.Sum_f / tv_code_B.P_el;
  }

  /* Sum: '<S8>/Sum' incorporates:
   *  Gain: '<S8>/kp'
   *  Product: '<S8>/Divide'
   */
  tv_code_B.Torquefixed = 1.0 / tv_code_B.Max * tv_code_B.PowerError;
  tv_code_B.Torquefixed *= tv_code_P.kp_Gain;

  /* Gain: '<S8>/ki' */
  tv_code_B.ki = tv_code_P.ki_Gain * tv_code_B.Torquefixed;

  /* Sum: '<S8>/Sum' incorporates:
   *  Sum: '<S8>/Sum2'
   */
  tv_code_B.Torquefixed += tv_code_B.ki;
  tv_code_B.Torquefixed = tv_code_B.Switch - tv_code_B.Torquefixed;

  /* Gain: '<S8>/torque_fixed' */
  tv_code_B.torque_fixed = tv_code_P.torque_fixed_Gain * tv_code_B.Torquefixed;

  /* Gain: '<S8>/est_power' */
  tv_code_B.est_power = tv_code_P.est_power_Gain * tv_code_B.P_est;
  if (rtmIsMajorTimeStep(tv_code_M)) {
    rt_ertODEUpdateContinuousStates(&tv_code_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++tv_code_M->Timing.clockTick0;
    tv_code_M->Timing.t[0] = rtsiGetSolverStopTime(&tv_code_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      tv_code_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void tv_code_derivatives(void)
{
  XDot_tv_code_T *_rtXdot;
  _rtXdot = ((XDot_tv_code_T *) tv_code_M->derivs);

  /* Derivatives for Integrator: '<S15>/Integrator' */
  _rtXdot->Integrator_CSTATE = tv_code_B.DotProduct1_a;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = tv_code_P.TransferFcn_A *
    tv_code_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += tv_code_B.Divide;
}

/* Model initialize function */
void tv_code_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  tv_code_P.Saturation_UpperSat = rtInf;
  tv_code_P.Saturation1_UpperSat = rtInf;
  tv_code_P.Saturation3_UpperSat = rtInf;
  tv_code_P.Saturation2_UpperSat = rtInf;
  tv_code_P.Saturation1_UpperSat_p = rtInf;
  tv_code_P.Saturation_UpperSat_f = rtInf;
  tv_code_P.Saturation4_UpperSat = rtInf;
  tv_code_P.Saturation7_UpperSat = rtInf;
  tv_code_P.Saturation6_UpperSat = rtInf;
  tv_code_P.Saturation5_UpperSat = rtInf;
  tv_code_P.Saturation_UpperSat_d = rtInf;
  tv_code_P.Saturation_UpperSat_dt = rtInf;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&tv_code_M->solverInfo, &tv_code_M->Timing.simTimeStep);
    rtsiSetTPtr(&tv_code_M->solverInfo, &rtmGetTPtr(tv_code_M));
    rtsiSetStepSizePtr(&tv_code_M->solverInfo, &tv_code_M->Timing.stepSize0);
    rtsiSetdXPtr(&tv_code_M->solverInfo, &tv_code_M->derivs);
    rtsiSetContStatesPtr(&tv_code_M->solverInfo, (real_T **)
                         &tv_code_M->contStates);
    rtsiSetNumContStatesPtr(&tv_code_M->solverInfo,
      &tv_code_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&tv_code_M->solverInfo,
      &tv_code_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&tv_code_M->solverInfo,
      &tv_code_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&tv_code_M->solverInfo,
      &tv_code_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&tv_code_M->solverInfo, (&rtmGetErrorStatus(tv_code_M)));
    rtsiSetRTModelPtr(&tv_code_M->solverInfo, tv_code_M);
  }

  rtsiSetSimTimeStep(&tv_code_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&tv_code_M->solverInfo, false);
  tv_code_M->intgData.y = tv_code_M->odeY;
  tv_code_M->intgData.f[0] = tv_code_M->odeF[0];
  tv_code_M->intgData.f[1] = tv_code_M->odeF[1];
  tv_code_M->intgData.f[2] = tv_code_M->odeF[2];
  tv_code_M->intgData.f[3] = tv_code_M->odeF[3];
  tv_code_M->contStates = ((X_tv_code_T *) &tv_code_X);
  rtsiSetSolverData(&tv_code_M->solverInfo, (void *)&tv_code_M->intgData);
  rtsiSetSolverName(&tv_code_M->solverInfo,"ode4");
  rtmSetTPtr(tv_code_M, &tv_code_M->Timing.tArray[0]);
  tv_code_M->Timing.stepSize0 = 0.005;

  /* InitializeConditions for Integrator: '<S15>/Integrator' */
  tv_code_X.Integrator_CSTATE = tv_code_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn' */
  tv_code_X.TransferFcn_CSTATE = 0.0;

  /* Constant: '<S2>/ax' */
  tv_code_ax_filter_Init(&tv_code_DW.ax_filter);

  /* Constant: '<S2>/ay' */
  tv_code_ax_filter_Init(&tv_code_DW.ay_filter);

  /* Constant: '<S2>/yaw_rate' */
  tv_code_ax_filter_Init(&tv_code_DW.yaw_rate_filter);
}

/* Model terminate function */
void tv_code_terminate(void)
{
  tv_code_ax_filter_Term(&tv_code_DW.ax_filter);
  tv_code_ax_filter_Term(&tv_code_DW.ay_filter);
  tv_code_ax_filter_Term(&tv_code_DW.yaw_rate_filter);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
