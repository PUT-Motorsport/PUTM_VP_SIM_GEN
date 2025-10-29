/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code.c
 *
 * Code generated for Simulink model 'tv_code'.
 *
 * Model version                  : 1.48
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Oct 29 15:40:41 2025
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
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_tv_code_T tv_code_B;

/* Continuous states */
X_tv_code_T tv_code_X;

/* Block states (default storage) */
DW_tv_code_T tv_code_DW;

/* Real-time model */
static RT_MODEL_tv_code_T tv_code_M_;
RT_MODEL_tv_code_T *const tv_code_M = &tv_code_M_;

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
  int_T nXc = 1;
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
void tv_code_LowpassFilter_Init(DW_LowpassFilter_tv_code_T *localDW)
{
  b_dspcodegen_FIRFilter_tv_cod_T *iobj_0;
  int32_T i;
  static const real_T tmp[17] = { 0.014074606922661284, -0.042838893432462,
    0.017762700917229431, 0.047520322185601614, -0.018747841017485233,
    -0.094954013206475632, 0.021190058476452077, 0.31432768517685217,
    0.47768194760527544, 0.31432768517685217, 0.021190058476452077,
    -0.094954013206475632, -0.018747841017485233, 0.047520322185601614,
    0.017762700917229431, -0.042838893432462, 0.014074606922661284 };

  /* Start for MATLABSystem: '<S3>/Lowpass Filter' */
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
  for (i = 0; i < 17; i++) {
    iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
  }

  localDW->obj._pobj0.matlabCodegenIsDeleted = false;
  localDW->obj.FilterObj = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;

  /* End of Start for MATLABSystem: '<S3>/Lowpass Filter' */

  /* InitializeConditions for MATLABSystem: '<S3>/Lowpass Filter' */
  iobj_0 = localDW->obj.FilterObj;
  if (iobj_0->isInitialized == 1) {
    /* System object Initialization function: dsp.FIRFilter */
    for (i = 0; i < 16; i++) {
      iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
    }
  }

  /* End of InitializeConditions for MATLABSystem: '<S3>/Lowpass Filter' */
}

/* Output and update for atomic system: */
void tv_code_LowpassFilter(real_T rtu_0, B_LowpassFilter_tv_code_T *localB,
  DW_LowpassFilter_tv_code_T *localDW)
{
  b_dsp_FIRFilter_0_tv_code_T *obj_0;
  b_dspcodegen_FIRFilter_tv_cod_T *obj;
  real_T acc1;
  real_T zCurr;
  real_T zNext;
  int32_T n;

  /* MATLABSystem: '<S3>/Lowpass Filter' */
  obj = localDW->obj.FilterObj;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (n = 0; n < 16; n++) {
      obj->cSFunObject.W0_states[n] = obj->cSFunObject.P0_InitialStates;
    }
  }

  obj_0 = &obj->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  acc1 = 0.0;

  /* load input sample */
  zNext = rtu_0;
  for (n = 0; n < 16; n++) {
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

  /* MATLABSystem: '<S3>/Lowpass Filter' */
  /* store output sample */
  localB->LowpassFilter = acc1 + zCurr;
}

/* Termination for atomic system: */
void tv_code_LowpassFilter_Term(DW_LowpassFilter_tv_code_T *localDW)
{
  b_dspcodegen_FIRFilter_tv_cod_T *obj;

  /* Terminate for MATLABSystem: '<S3>/Lowpass Filter' */
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

  /* End of Terminate for MATLABSystem: '<S3>/Lowpass Filter' */
}

/* System initialize for atomic system: */
void tv_code_ax_filter_Init(DW_ax_filter_tv_code_T *localDW)
{
  b_dspcodegen_FIRFilter_tv_c_l_T *iobj_0;
  int32_T i;
  static const real_T tmp[9] = { -0.005412996192943418, -0.00037695464995368688,
    0.082835378892191724, 0.25136596710560233, 0.34706570862151792,
    0.25136596710560233, 0.082835378892191724, -0.00037695464995368688,
    -0.005412996192943418 };

  /* Start for MATLABSystem: '<S3>/ax_filter' */
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

  /* End of Start for MATLABSystem: '<S3>/ax_filter' */

  /* InitializeConditions for MATLABSystem: '<S3>/ax_filter' */
  iobj_0 = localDW->obj.FilterObj;
  if (iobj_0->isInitialized == 1) {
    /* System object Initialization function: dsp.FIRFilter */
    for (i = 0; i < 8; i++) {
      iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
    }
  }

  /* End of InitializeConditions for MATLABSystem: '<S3>/ax_filter' */
}

/* Output and update for atomic system: */
void tv_code_ax_filter(real_T rtu_0, B_ax_filter_tv_code_T *localB,
  DW_ax_filter_tv_code_T *localDW)
{
  b_dsp_FIRFilter_0_tv_code_a_T *obj_0;
  b_dspcodegen_FIRFilter_tv_c_l_T *obj;
  real_T acc1;
  real_T zCurr;
  real_T zNext;
  int32_T n;

  /* MATLABSystem: '<S3>/ax_filter' */
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

  /* MATLABSystem: '<S3>/ax_filter' */
  /* store output sample */
  localB->ax_filter = acc1 + zCurr;
}

/* Termination for atomic system: */
void tv_code_ax_filter_Term(DW_ax_filter_tv_code_T *localDW)
{
  b_dspcodegen_FIRFilter_tv_c_l_T *obj;

  /* Terminate for MATLABSystem: '<S3>/ax_filter' */
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

  /* End of Terminate for MATLABSystem: '<S3>/ax_filter' */
}

/* Model step function */
void tv_code_step(void)
{
  real_T Sum_tmp;
  real_T Sum_tmp_1;
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
    real_T Gain1_tmp;
    real_T Sum_tmp_0;

    /* Sum: '<S19>/Sum' incorporates:
     *  Constant: '<S18>/Constant'
     *  Constant: '<S3>/acc_pedal'
     *  Sum: '<S18>/Sum1'
     */
    tv_code_B.Sum = tv_code_P.acc_pedal_Value - tv_code_P.Constant_Value_c;

    /* Product: '<S18>/Product1' incorporates:
     *  Constant: '<S18>/Constant1'
     */
    tv_code_B.Product1 = 4.0 * tv_code_P.max_moment * tv_code_P.drive_ratio *
      tv_code_B.Sum;

    /* Sum: '<S19>/Sum' incorporates:
     *  Gain: '<S16>/Gain'
     */
    tv_code_B.Sum = tv_code_P.Gain_Gain_po * tv_code_B.Product1;

    /* Saturate: '<S16>/Saturation' */
    if (tv_code_B.Sum > tv_code_P.Saturation_UpperSat) {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation[0] = tv_code_P.Saturation_UpperSat;
    } else if (tv_code_B.Sum < tv_code_P.Saturation_LowerSat) {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation[0] = tv_code_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation[0] = tv_code_B.Sum;
    }

    if (tv_code_B.Sum > tv_code_P.Saturation_UpperSat) {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation[1] = tv_code_P.Saturation_UpperSat;
    } else if (tv_code_B.Sum < tv_code_P.Saturation_LowerSat) {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation[1] = tv_code_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation[1] = tv_code_B.Sum;
    }

    if (tv_code_B.Sum > tv_code_P.Saturation_UpperSat) {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation[2] = tv_code_P.Saturation_UpperSat;
    } else if (tv_code_B.Sum < tv_code_P.Saturation_LowerSat) {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation[2] = tv_code_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation[2] = tv_code_B.Sum;
    }

    if (tv_code_B.Sum > tv_code_P.Saturation_UpperSat) {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation[3] = tv_code_P.Saturation_UpperSat;
    } else if (tv_code_B.Sum < tv_code_P.Saturation_LowerSat) {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation[3] = tv_code_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S16>/Saturation' */
      tv_code_B.Saturation[3] = tv_code_B.Sum;
    }

    /* End of Saturate: '<S16>/Saturation' */

    /* Constant: '<S3>/whl_speed_fl' */
    tv_code_LowpassFilter(tv_code_P.whl_speed_fl_Value, &tv_code_B.LowpassFilter,
                          &tv_code_DW.LowpassFilter);

    /* Constant: '<S3>/whl_speed_fr' */
    tv_code_LowpassFilter(tv_code_P.whl_speed_fr_Value,
                          &tv_code_B.LowpassFilter1, &tv_code_DW.LowpassFilter1);

    /* Constant: '<S3>/whl_speed_rl' */
    tv_code_LowpassFilter(tv_code_P.whl_speed_rl_Value,
                          &tv_code_B.LowpassFilter2, &tv_code_DW.LowpassFilter2);

    /* Constant: '<S3>/whl_speed_rr' */
    tv_code_LowpassFilter(tv_code_P.whl_speed_rr_Value,
                          &tv_code_B.LowpassFilter3, &tv_code_DW.LowpassFilter3);

    /* Sum: '<S15>/Plus' incorporates:
     *  ManualSwitch: '<S14>/regen_switch'
     *  Sum: '<S21>/Add'
     *  Switch: '<S14>/Switch'
     */
    Sum_tmp = ((tv_code_B.LowpassFilter.LowpassFilter +
                tv_code_B.LowpassFilter1.LowpassFilter) +
               tv_code_B.LowpassFilter2.LowpassFilter) +
      tv_code_B.LowpassFilter3.LowpassFilter;

    /* Sum: '<S19>/Sum' incorporates:
     *  Gain: '<S15>/Gain'
     *  Sum: '<S15>/Plus'
     */
    tv_code_B.Sum = Sum_tmp;
    tv_code_B.Sum *= tv_code_P.Gain_Gain_f;

    /* Gain: '<S15>/car_vx' */
    tv_code_B.car_vx = tv_code_P.rw * tv_code_B.Sum;

    /* Switch: '<S14>/Switch' incorporates:
     *  ManualSwitch: '<S14>/regen_switch'
     */
    if (tv_code_B.Product1 > tv_code_P.Switch_Threshold) {
      /* Switch: '<S14>/Switch' */
      tv_code_B.Switch = tv_code_B.Product1;
    } else {
      if (tv_code_P.regen_switch_CurrentSetting == 1) {
        /* ManualSwitch: '<S14>/regen_switch' incorporates:
         *  Constant: '<S14>/Constant'
         */
        tv_code_B.regen_switch = tv_code_P.Constant_Value;
      } else {
        /* Gain: '<S20>/Gain1' incorporates:
         *  ManualSwitch: '<S14>/regen_switch'
         *  Sum: '<S21>/Add'
         */
        tv_code_B.Gain1_a = Sum_tmp;

        /* DotProduct: '<S21>/Dot Product' incorporates:
         *  Constant: '<S21>/I_max'
         *  Constant: '<S21>/Vdc'
         *  ManualSwitch: '<S14>/regen_switch'
         */
        tv_code_B.DotProduct_h = tv_code_P.I_max_Value * tv_code_P.Vdc_Value;

        /* Product: '<S21>/div2' incorporates:
         *  Gain: '<S21>/Gain'
         *  ManualSwitch: '<S14>/regen_switch'
         */
        tv_code_B.div2 = tv_code_P.Gain_Gain * tv_code_B.DotProduct_h;
        tv_code_B.div2 /= tv_code_B.Gain1_a;

        /* Gain: '<S20>/X2' incorporates:
         *  Constant: '<S20>/Z1'
         *  Constant: '<S20>/Z2'
         *  Gain: '<S20>/X1'
         *  ManualSwitch: '<S14>/regen_switch'
         */
        Sum_tmp = tv_code_P.m * tv_code_P.g;

        /* Gain: '<S20>/Gain1' incorporates:
         *  Constant: '<S20>/Z2'
         *  Gain: '<S20>/Tr'
         *  Gain: '<S20>/X2'
         *  ManualSwitch: '<S14>/regen_switch'
         */
        tv_code_B.Gain1_a = Sum_tmp * tv_code_P.lr / tv_code_P.L * tv_code_P.mu;
        tv_code_B.Gain1_a *= tv_code_P.rw;
        tv_code_B.Gain1_a *= 1.0 / tv_code_P.drive_ratio;

        /* MinMax: '<S14>/Max' incorporates:
         *  Constant: '<S14>/TT_max'
         *  Constant: '<S20>/Z1'
         *  Gain: '<S20>/Gain'
         *  Gain: '<S20>/Ta'
         *  Gain: '<S20>/X1'
         *  ManualSwitch: '<S14>/regen_switch'
         *  MinMax: '<S14>/Max of Elements'
         *  Sum: '<S14>/Sum'
         */
        tv_code_B.Max = Sum_tmp * tv_code_P.lf / tv_code_P.L * tv_code_P.mu;
        tv_code_B.Max *= tv_code_P.rw;
        tv_code_B.Max *= 1.0 / tv_code_P.drive_ratio;
        tv_code_B.Max += tv_code_B.Gain1_a;
        tv_code_B.Max = fmin(tv_code_B.Max, tv_code_B.div2);
        tv_code_B.Max = fmax(tv_code_B.Max, tv_code_P.TT_max_Value);

        /* Gain: '<S14>/Gain1' incorporates:
         *  ManualSwitch: '<S14>/regen_switch'
         */
        tv_code_B.Gain1_d = tv_code_P.Gain1_Gain * tv_code_B.Max;

        /* ManualSwitch: '<S14>/regen_switch' */
        tv_code_B.regen_switch = tv_code_B.Gain1_d;
      }

      /* Switch: '<S14>/Switch' */
      tv_code_B.Switch = tv_code_B.regen_switch;
    }

    /* Switch: '<S17>/Switch' */
    if (tv_code_B.Switch != 0.0) {
      /* Switch: '<S17>/Switch' incorporates:
       *  Constant: '<S17>/Constant'
       */
      tv_code_B.Switch_k = tv_code_P.Constant_Value_n;
    } else {
      /* Switch: '<S17>/Switch' incorporates:
       *  Constant: '<S17>/Constant1'
       */
      tv_code_B.Switch_k = tv_code_P.Constant1_Value;
    }

    /* End of Switch: '<S17>/Switch' */

    /* Constant: '<S3>/ax' */
    tv_code_ax_filter(tv_code_P.ax_Value, &tv_code_B.ax_filter,
                      &tv_code_DW.ax_filter);

    /* Gain: '<S22>/Gain1' incorporates:
     *  Gain: '<S23>/Gain1'
     */
    Sum_tmp = tv_code_P.h * tv_code_B.ax_filter.ax_filter;

    /* Sum: '<S19>/Sum' incorporates:
     *  Gain: '<S22>/Gain1'
     */
    tv_code_B.Sum = Sum_tmp;

    /* Constant: '<S3>/ay' */
    tv_code_ax_filter(tv_code_P.ay_Value, &tv_code_B.ay_filter,
                      &tv_code_DW.ay_filter);

    /* Gain: '<S22>/Gain2' incorporates:
     *  Gain: '<S23>/Gain2'
     */
    tv_code_B.e_slip = tv_code_P.h * tv_code_P.lr / tv_code_P.ls *
      tv_code_B.ay_filter.ax_filter;

    /* Saturate: '<S13>/Saturation' incorporates:
     *  Gain: '<S22>/Gain2'
     */
    tv_code_B.Saturation_j = tv_code_B.e_slip;

    /* Sum: '<S22>/Sum' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S23>/Constant'
     *  Sum: '<S23>/Sum'
     */
    Sum_tmp_0 = tv_code_P.g * tv_code_P.lr;

    /* Sum: '<S19>/Sum' incorporates:
     *  Constant: '<S22>/Constant'
     *  Sum: '<S22>/Sum'
     */
    tv_code_B.Sum = (Sum_tmp_0 - tv_code_B.Sum) - tv_code_B.Saturation_j;

    /* Gain: '<S22>/Gain' incorporates:
     *  Gain: '<S23>/Gain'
     */
    Sum_tmp_1 = tv_code_P.m / (2.0 * tv_code_P.L);

    /* Sum: '<S19>/Sum' incorporates:
     *  Gain: '<S22>/Gain'
     */
    tv_code_B.Sum *= Sum_tmp_1;

    /* Gain: '<S26>/Gain1' incorporates:
     *  Gain: '<S27>/Gain1'
     */
    Gain1_tmp = 1.0 / (tv_code_P.m * tv_code_P.g);

    /* Gain: '<S26>/Gain1' */
    tv_code_B.Gain1 = Gain1_tmp * tv_code_B.Sum;

    /* Constant: '<S3>/yaw_rate' */
    tv_code_ax_filter(tv_code_P.yaw_rate_Value, &tv_code_B.yaw_rate_filter,
                      &tv_code_DW.yaw_rate_filter);

    /* Saturate: '<S13>/Saturation' incorporates:
     *  Constant: '<S3>/delta'
     *  Product: '<S13>/Product'
     */
    tv_code_B.Saturation_j = tv_code_P.delta_Value * tv_code_B.car_vx;

    /* Sum: '<S19>/Sum' incorporates:
     *  Constant: '<S13>/Constant'
     *  Gain: '<S13>/Desired Understeer Gradient'
     *  Gain: '<S13>/axlebase'
     *  Math: '<S13>/Square'
     *  Sum: '<S13>/Sum'
     */
    tv_code_B.Sum = tv_code_B.car_vx * tv_code_B.car_vx;
    tv_code_B.Sum *= tv_code_P.Ku;
    tv_code_B.Sum += tv_code_P.Constant_Value_m;
    tv_code_B.Sum *= tv_code_P.L;

    /* Saturate: '<S13>/Saturation1' */
    if (tv_code_B.Sum > tv_code_P.Saturation1_UpperSat) {
      /* Sum: '<S19>/Sum' */
      tv_code_B.Sum = tv_code_P.Saturation1_UpperSat;
    } else if (tv_code_B.Sum < tv_code_P.Saturation1_LowerSat) {
      /* Sum: '<S19>/Sum' */
      tv_code_B.Sum = tv_code_P.Saturation1_LowerSat;
    }

    /* End of Saturate: '<S13>/Saturation1' */

    /* Saturate: '<S13>/Saturation' incorporates:
     *  Product: '<S13>/div3'
     */
    tv_code_B.Saturation_j /= tv_code_B.Sum;

    /* Saturate: '<S13>/Saturation' */
    if (tv_code_B.Saturation_j > tv_code_P.Saturation_UpperSat_b) {
      /* Saturate: '<S13>/Saturation' */
      tv_code_B.Saturation_j = tv_code_P.Saturation_UpperSat_b;
    } else if (tv_code_B.Saturation_j < tv_code_P.Saturation_LowerSat_i) {
      /* Saturate: '<S13>/Saturation' */
      tv_code_B.Saturation_j = tv_code_P.Saturation_LowerSat_i;
    }

    /* End of Saturate: '<S13>/Saturation' */

    /* Sum: '<S19>/Sum' */
    tv_code_B.Sum = tv_code_B.Saturation_j - tv_code_B.yaw_rate_filter.ax_filter;

    /* DotProduct: '<S19>/Dot Product' incorporates:
     *  Constant: '<S3>/Mz Proportional Gain'
     */
    tv_code_B.DotProduct = tv_code_P.Mz_p * tv_code_B.Sum;

    /* Gain: '<S24>/Gain2' incorporates:
     *  Gain: '<S23>/Gain'
     *  Gain: '<S23>/Gain1'
     *  Gain: '<S25>/Gain2'
     *  Sum: '<S23>/Sum'
     */
    tv_code_B.Gain2 = Sum_tmp;
    tv_code_B.Gain2 = (Sum_tmp_0 - tv_code_B.Gain2) + tv_code_B.e_slip;
    tv_code_B.Gain2 *= Sum_tmp_1;

    /* Gain: '<S27>/Gain1' */
    tv_code_B.Gain1_b = Gain1_tmp * tv_code_B.Gain2;

    /* Gain: '<S22>/Gain2' incorporates:
     *  Gain: '<S24>/Gain1'
     *  MinMax: '<S8>/e_slip'
     */
    tv_code_B.e_slip = Sum_tmp;

    /* Gain: '<S24>/Gain2' incorporates:
     *  Gain: '<S25>/Gain2'
     */
    tv_code_B.Gain2 = tv_code_P.h * tv_code_P.lf / tv_code_P.ls *
      tv_code_B.ay_filter.ax_filter;

    /* Sum: '<S24>/Sum' incorporates:
     *  Constant: '<S24>/Constant'
     *  Constant: '<S25>/Constant'
     *  Sum: '<S25>/Sum'
     */
    Sum_tmp_0 = tv_code_P.g * tv_code_P.lf;

    /* Gain: '<S22>/Gain2' incorporates:
     *  Constant: '<S24>/Constant'
     *  Gain: '<S24>/Gain'
     *  MinMax: '<S8>/e_slip'
     *  Sum: '<S24>/Sum'
     */
    tv_code_B.e_slip = (Sum_tmp_0 + tv_code_B.e_slip) - tv_code_B.Gain2;
    tv_code_B.e_slip *= Sum_tmp_1;

    /* Gain: '<S29>/Gain1' */
    tv_code_B.Gain1_bu = Gain1_tmp * tv_code_B.e_slip;

    /* Gain: '<S22>/Gain2' incorporates:
     *  Gain: '<S25>/Gain'
     *  Gain: '<S25>/Gain1'
     *  MinMax: '<S8>/e_slip'
     *  Sum: '<S25>/Sum'
     */
    tv_code_B.e_slip = Sum_tmp;
    tv_code_B.e_slip = (Sum_tmp_0 + tv_code_B.e_slip) + tv_code_B.Gain2;
    tv_code_B.e_slip *= Sum_tmp_1;

    /* Gain: '<S28>/Gain1' */
    tv_code_B.Gain1_e = Gain1_tmp * tv_code_B.e_slip;
  }

  /* MinMax: '<S8>/Max' incorporates:
   *  Integrator: '<S19>/Integrator'
   */
  tv_code_B.Max_d = tv_code_X.Integrator_CSTATE;

  /* Sum: '<S19>/Sum1' */
  tv_code_B.Sum1 = tv_code_B.DotProduct + tv_code_B.Max_d;

  /* Switch: '<S4>/speed_switch' */
  if (tv_code_B.car_vx > tv_code_P.speed_switch_Threshold) {
    /* Switch: '<S14>/Switch1' */
    if (tv_code_B.Product1 > tv_code_P.Switch1_Threshold) {
      /* Gain: '<S26>/Gain' incorporates:
       *  Saturate: '<S17>/Saturation3'
       */
      tv_code_B.Saturation3 = tv_code_B.Sum1;
    } else {
      /* Gain: '<S14>/Gain' */
      tv_code_B.Gain_m = tv_code_P.Gain_Gain_p * tv_code_B.Sum1;

      /* Gain: '<S26>/Gain' incorporates:
       *  Saturate: '<S17>/Saturation3'
       */
      tv_code_B.Saturation3 = tv_code_B.Gain_m;
    }

    /* End of Switch: '<S14>/Switch1' */

    /* Gain: '<S26>/Gain' incorporates:
     *  Gain: '<S27>/Gain'
     *  Gain: '<S28>/Gain'
     *  Gain: '<S29>/Gain'
     */
    tv_code_B.Saturation3 *= tv_code_P.rw / tv_code_P.ls;

    /* Saturate: '<S17>/Saturation2' incorporates:
     *  Gain: '<S26>/Gain'
     *  Product: '<S26>/Product'
     *  Sum: '<S26>/Sum'
     */
    tv_code_B.Saturation2 = tv_code_B.Saturation3;
    tv_code_B.Saturation2 = tv_code_B.Switch - tv_code_B.Saturation2;
    tv_code_B.Saturation2 *= tv_code_B.Gain1;

    /* Saturate: '<S17>/Saturation' incorporates:
     *  Saturate: '<S17>/Saturation1'
     *  Saturate: '<S17>/Saturation2'
     *  Saturate: '<S17>/Saturation3'
     */
    Sum_tmp = -tv_code_P.max_moment * tv_code_P.drive_ratio;
    Sum_tmp_1 = tv_code_P.max_moment * tv_code_P.drive_ratio;
    if (tv_code_B.Saturation2 > Sum_tmp_1) {
      /* Saturate: '<S17>/Saturation2' */
      tv_code_B.Saturation2 = Sum_tmp_1;
    } else if (tv_code_B.Saturation2 < Sum_tmp) {
      /* Saturate: '<S17>/Saturation2' */
      tv_code_B.Saturation2 = Sum_tmp;
    }

    /* End of Saturate: '<S17>/Saturation' */

    /* DotProduct: '<S17>/Dot Product' */
    tv_code_B.DotProduct_j = tv_code_B.Switch_k * tv_code_B.Saturation2;

    /* Saturate: '<S17>/Saturation2' incorporates:
     *  Gain: '<S27>/Gain'
     *  Product: '<S27>/Product'
     *  Sum: '<S27>/Sum'
     */
    tv_code_B.Saturation2 = tv_code_B.Saturation3;
    tv_code_B.Saturation2 += tv_code_B.Switch;
    tv_code_B.Saturation2 *= tv_code_B.Gain1_b;

    /* Saturate: '<S17>/Saturation1' */
    if (tv_code_B.Saturation2 > Sum_tmp_1) {
      /* Saturate: '<S17>/Saturation2' */
      tv_code_B.Saturation2 = Sum_tmp_1;
    } else if (tv_code_B.Saturation2 < Sum_tmp) {
      /* Saturate: '<S17>/Saturation2' */
      tv_code_B.Saturation2 = Sum_tmp;
    }

    /* DotProduct: '<S17>/Dot Product1' */
    tv_code_B.DotProduct1_l = tv_code_B.Switch_k * tv_code_B.Saturation2;

    /* Saturate: '<S17>/Saturation2' incorporates:
     *  Gain: '<S29>/Gain'
     *  Product: '<S29>/Product'
     *  Sum: '<S29>/Sum'
     */
    tv_code_B.Saturation2 = tv_code_B.Saturation3;
    tv_code_B.Saturation2 = tv_code_B.Switch - tv_code_B.Saturation2;
    tv_code_B.Saturation2 *= tv_code_B.Gain1_bu;

    /* Saturate: '<S17>/Saturation2' */
    if (tv_code_B.Saturation2 > Sum_tmp_1) {
      /* Saturate: '<S17>/Saturation2' */
      tv_code_B.Saturation2 = Sum_tmp_1;
    } else if (tv_code_B.Saturation2 < Sum_tmp) {
      /* Saturate: '<S17>/Saturation2' */
      tv_code_B.Saturation2 = Sum_tmp;
    }

    /* DotProduct: '<S17>/Dot Product2' */
    tv_code_B.DotProduct2 = tv_code_B.Switch_k * tv_code_B.Saturation2;

    /* Gain: '<S26>/Gain' incorporates:
     *  Product: '<S28>/Product'
     *  Saturate: '<S17>/Saturation3'
     *  Sum: '<S28>/Sum'
     */
    tv_code_B.Saturation3 += tv_code_B.Switch;
    tv_code_B.Saturation3 *= tv_code_B.Gain1_e;

    /* Saturate: '<S17>/Saturation3' */
    if (tv_code_B.Saturation3 > Sum_tmp_1) {
      /* Gain: '<S26>/Gain' incorporates:
       *  Saturate: '<S17>/Saturation3'
       */
      tv_code_B.Saturation3 = Sum_tmp_1;
    } else if (tv_code_B.Saturation3 < Sum_tmp) {
      /* Gain: '<S26>/Gain' incorporates:
       *  Saturate: '<S17>/Saturation3'
       */
      tv_code_B.Saturation3 = Sum_tmp;
    }

    /* DotProduct: '<S17>/Dot Product3' */
    tv_code_B.DotProduct3 = tv_code_B.Switch_k * tv_code_B.Saturation3;

    /* Switch: '<S4>/speed_switch' */
    tv_code_B.speed_switch[0] = tv_code_B.DotProduct_j;
    tv_code_B.speed_switch[1] = tv_code_B.DotProduct1_l;
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
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* Gain: '<S22>/Gain2' incorporates:
     *  Constant: '<S9>/Constant'
     *  Constant: '<S9>/Constant1'
     *  MinMax: '<S8>/e_slip'
     *  Sum: '<S9>/Sum'
     */
    tv_code_B.e_slip = tv_code_P.Constant1_Value_d + tv_code_P.s_max;

    /* DotProduct: '<S9>/Dot Product' */
    tv_code_B.DotProduct_f = tv_code_B.e_slip * tv_code_B.car_vx;

    /* Gain: '<S22>/Gain2' incorporates:
     *  Constant: '<S5>/Constant2'
     *  Gain: '<S9>/Gain'
     *  MinMax: '<S5>/e_slip'
     *  MinMax: '<S8>/e_slip'
     *  Sum: '<S5>/Sum'
     */
    tv_code_B.e_slip = 1.0 / tv_code_P.rw * tv_code_B.DotProduct_f;
    tv_code_B.e_slip = tv_code_B.LowpassFilter.LowpassFilter - tv_code_B.e_slip;
    tv_code_B.e_slip = fmax(tv_code_B.e_slip, tv_code_P.Constant2_Value);

    /* Gain: '<S5>/Gain' */
    tv_code_B.Gain = tv_code_P.K_slip * tv_code_B.e_slip;

    /* Gain: '<S22>/Gain2' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S10>/Constant1'
     *  MinMax: '<S8>/e_slip'
     *  Sum: '<S10>/Sum'
     */
    tv_code_B.e_slip = tv_code_P.Constant1_Value_p + tv_code_P.s_max;

    /* DotProduct: '<S10>/Dot Product' */
    tv_code_B.DotProduct_fj = tv_code_B.e_slip * tv_code_B.car_vx;

    /* Gain: '<S22>/Gain2' incorporates:
     *  Constant: '<S6>/Constant2'
     *  Gain: '<S10>/Gain'
     *  MinMax: '<S6>/e_slip'
     *  MinMax: '<S8>/e_slip'
     *  Sum: '<S6>/Sum'
     */
    tv_code_B.e_slip = 1.0 / tv_code_P.rw * tv_code_B.DotProduct_fj;
    tv_code_B.e_slip = tv_code_B.LowpassFilter1.LowpassFilter - tv_code_B.e_slip;
    tv_code_B.e_slip = fmax(tv_code_B.e_slip, tv_code_P.Constant2_Value_j);

    /* Gain: '<S6>/ek_slip' */
    tv_code_B.ek_slip = tv_code_P.K_slip * tv_code_B.e_slip;
  }

  /* MinMax: '<S8>/Max' incorporates:
   *  Constant: '<S5>/Constant2'
   *  MinMax: '<S5>/Max'
   *  Sum: '<S5>/Sum1'
   */
  tv_code_B.Max_d = tv_code_B.speed_switch[0] - tv_code_B.Gain;
  tv_code_B.Max_d = fmax(tv_code_B.Max_d, tv_code_P.Constant2_Value);

  /* Gain: '<Root>/trq_fl' */
  tv_code_B.trq_fl = tv_code_P.trq_fl_Gain * tv_code_B.Max_d;

  /* MinMax: '<S8>/Max' incorporates:
   *  Constant: '<S6>/Constant2'
   *  MinMax: '<S6>/Max'
   *  Sum: '<S6>/Sum1'
   */
  tv_code_B.Max_d = tv_code_B.speed_switch[1] - tv_code_B.ek_slip;
  tv_code_B.Max_d = fmax(tv_code_B.Max_d, tv_code_P.Constant2_Value_j);

  /* Gain: '<Root>/trq_fr' */
  tv_code_B.trq_fr = tv_code_P.trq_fr_Gain * tv_code_B.Max_d;
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* Gain: '<S22>/Gain2' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant1'
     *  MinMax: '<S8>/e_slip'
     *  Sum: '<S11>/Sum'
     */
    tv_code_B.e_slip = tv_code_P.Constant1_Value_i + tv_code_P.s_max;

    /* DotProduct: '<S11>/Dot Product' */
    tv_code_B.DotProduct_p = tv_code_B.e_slip * tv_code_B.car_vx;

    /* Gain: '<S22>/Gain2' incorporates:
     *  Constant: '<S7>/Constant2'
     *  Gain: '<S11>/Gain'
     *  MinMax: '<S7>/e_slip'
     *  MinMax: '<S8>/e_slip'
     *  Sum: '<S7>/Sum'
     */
    tv_code_B.e_slip = 1.0 / tv_code_P.rw * tv_code_B.DotProduct_p;
    tv_code_B.e_slip = tv_code_B.LowpassFilter2.LowpassFilter - tv_code_B.e_slip;
    tv_code_B.e_slip = fmax(tv_code_B.e_slip, tv_code_P.Constant2_Value_n);

    /* Gain: '<S7>/Gain' */
    tv_code_B.Gain_h = tv_code_P.K_slip * tv_code_B.e_slip;

    /* Gain: '<S22>/Gain2' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S12>/Constant1'
     *  MinMax: '<S8>/e_slip'
     *  Sum: '<S12>/Sum'
     */
    tv_code_B.e_slip = tv_code_P.Constant1_Value_g + tv_code_P.s_max;

    /* DotProduct: '<S12>/Dot Product' */
    tv_code_B.DotProduct_n = tv_code_B.e_slip * tv_code_B.car_vx;

    /* Gain: '<S22>/Gain2' incorporates:
     *  Constant: '<S8>/Constant2'
     *  Gain: '<S12>/Gain'
     *  MinMax: '<S8>/e_slip'
     *  Sum: '<S8>/Sum'
     */
    tv_code_B.e_slip = 1.0 / tv_code_P.rw * tv_code_B.DotProduct_n;
    tv_code_B.e_slip = tv_code_B.LowpassFilter3.LowpassFilter - tv_code_B.e_slip;
    tv_code_B.e_slip = fmax(tv_code_B.e_slip, tv_code_P.Constant2_Value_f);

    /* Gain: '<S8>/Gain' */
    tv_code_B.Gain_h4 = tv_code_P.K_slip * tv_code_B.e_slip;
  }

  /* MinMax: '<S8>/Max' incorporates:
   *  Constant: '<S7>/Constant2'
   *  MinMax: '<S7>/Max'
   *  Sum: '<S7>/Sum1'
   */
  tv_code_B.Max_d = tv_code_B.speed_switch[2] - tv_code_B.Gain_h;
  tv_code_B.Max_d = fmax(tv_code_B.Max_d, tv_code_P.Constant2_Value_n);

  /* Gain: '<Root>/trq_rl' */
  tv_code_B.trq_rl = tv_code_P.trq_rl_Gain * tv_code_B.Max_d;

  /* MinMax: '<S8>/Max' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Sum: '<S8>/Sum1'
   */
  tv_code_B.Max_d = tv_code_B.speed_switch[3] - tv_code_B.Gain_h4;
  tv_code_B.Max_d = fmax(tv_code_B.Max_d, tv_code_P.Constant2_Value_f);

  /* Gain: '<Root>/trq_rr' */
  tv_code_B.trq_rr = tv_code_P.trq_rr_Gain * tv_code_B.Max_d;
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* DotProduct: '<S19>/Dot Product1' incorporates:
     *  Constant: '<S3>/Mz Integative Gain'
     */
    tv_code_B.DotProduct1 = tv_code_B.Sum * tv_code_P.Mz_I;

    /* Gain: '<S13>/yaw_ref' */
    tv_code_B.yaw_ref = tv_code_P.yaw_ref_Gain * tv_code_B.Saturation_j;
  }

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

  /* Derivatives for Integrator: '<S19>/Integrator' */
  _rtXdot->Integrator_CSTATE = tv_code_B.DotProduct1;
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

  /* InitializeConditions for Integrator: '<S19>/Integrator' */
  tv_code_X.Integrator_CSTATE = tv_code_P.Integrator_IC;

  /* Constant: '<S3>/whl_speed_fl' */
  tv_code_LowpassFilter_Init(&tv_code_DW.LowpassFilter);

  /* Constant: '<S3>/whl_speed_fr' */
  tv_code_LowpassFilter_Init(&tv_code_DW.LowpassFilter1);

  /* Constant: '<S3>/whl_speed_rl' */
  tv_code_LowpassFilter_Init(&tv_code_DW.LowpassFilter2);

  /* Constant: '<S3>/whl_speed_rr' */
  tv_code_LowpassFilter_Init(&tv_code_DW.LowpassFilter3);

  /* Constant: '<S3>/ax' */
  tv_code_ax_filter_Init(&tv_code_DW.ax_filter);

  /* Constant: '<S3>/ay' */
  tv_code_ax_filter_Init(&tv_code_DW.ay_filter);

  /* Constant: '<S3>/yaw_rate' */
  tv_code_ax_filter_Init(&tv_code_DW.yaw_rate_filter);
}

/* Model terminate function */
void tv_code_terminate(void)
{
  tv_code_LowpassFilter_Term(&tv_code_DW.LowpassFilter);
  tv_code_LowpassFilter_Term(&tv_code_DW.LowpassFilter1);
  tv_code_LowpassFilter_Term(&tv_code_DW.LowpassFilter2);
  tv_code_LowpassFilter_Term(&tv_code_DW.LowpassFilter3);
  tv_code_ax_filter_Term(&tv_code_DW.ax_filter);
  tv_code_ax_filter_Term(&tv_code_DW.ay_filter);
  tv_code_ax_filter_Term(&tv_code_DW.yaw_rate_filter);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
