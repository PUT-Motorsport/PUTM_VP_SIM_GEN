/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code.c
 *
 * Code generated for Simulink model 'tv_code'.
 *
 * Model version                  : 5.4
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Oct  5 22:09:03 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "tv_code.h"
#include "rtwtypes.h"
#include "tv_code_private.h"

/* Block signals (default storage) */
B_tv_code_T tv_code_B;

/* Continuous states */
X_tv_code_T tv_code_X;

/* Disabled State Vector */
XDis_tv_code_T tv_code_XDis;

/* External inputs (root inport signals with default storage) */
ExtU_tv_code_T tv_code_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_tv_code_T tv_code_Y;

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

/* Model step function */
void tv_code_step(void)
{
  real_T Gain1_tmp;
  real_T Gain2_tmp;
  real_T Sum_a_tmp;
  real_T Sum_h_tmp;
  real_T tmp;
  real_T u0;
  real_T y;
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&tv_code_M->solverInfo,((tv_code_M->Timing.clockTick0+
      1)*tv_code_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(tv_code_M)) {
    tv_code_M->Timing.t[0] = rtsiGetT(&tv_code_M->solverInfo);
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/yaw_rate'
   *  Inport: '<Root>/yaw_rate_ref'
   */
  tv_code_B.Sum = tv_code_U.yaw_rate_ref - tv_code_U.yaw_rate;

  /* Integrator: '<S3>/Integrator' */
  tv_code_B.Integrator = tv_code_X.Integrator_CSTATE;

  /* Switch: '<Root>/speed_switch' incorporates:
   *  Inport: '<Root>/vx'
   */
  if (tv_code_U.vx > 1.0) {
    /* DotProduct: '<S3>/Dot Product' */
    u0 = tv_code_B.Sum;

    /* DotProduct: '<S3>/Dot Product' incorporates:
     *  Inport: '<Root>/kp'
     */
    tv_code_B.DotProduct = tv_code_U.kp * u0;

    /* Sum: '<S3>/Sum1' */
    tv_code_B.Sum1 = tv_code_B.DotProduct + tv_code_B.Integrator;

    /* Gain: '<S8>/Gain' incorporates:
     *  Gain: '<S10>/Gain'
     *  Gain: '<S11>/Gain'
     *  Gain: '<S9>/Gain'
     */
    y = 0.15539452495974235 * tv_code_B.Sum1;

    /* Gain: '<S8>/Gain' */
    tv_code_B.Gain_h = y;

    /* Sum: '<S8>/Sum' incorporates:
     *  Inport: '<Root>/Inport7'
     *  Sum: '<S11>/Sum'
     */
    Sum_h_tmp = tv_code_U.Inport7 - tv_code_B.Gain_h;

    /* Sum: '<S8>/Sum' */
    tv_code_B.Sum_h = Sum_h_tmp;

    /* Gain: '<S4>/Gain2' incorporates:
     *  Gain: '<S5>/Gain2'
     *  Gain: '<S6>/Gain2'
     *  Gain: '<S7>/Gain2'
     *  Inport: '<Root>/ay'
     */
    Gain2_tmp = 0.1539855072463768 * tv_code_U.ay;

    /* Gain: '<S4>/Gain2' */
    tv_code_B.Gain2 = Gain2_tmp;

    /* Gain: '<S4>/Gain1' incorporates:
     *  Gain: '<S5>/Gain1'
     *  Gain: '<S6>/Gain1'
     *  Gain: '<S7>/Gain1'
     *  Inport: '<Root>/ax'
     */
    Gain1_tmp = 0.25 * tv_code_U.ax;

    /* Gain: '<S4>/Gain1' */
    tv_code_B.Gain1 = Gain1_tmp;

    /* Sum: '<S4>/Sum' incorporates:
     *  Constant: '<S4>/Constant'
     */
    tv_code_B.Sum_c = (7.5046500000000007 - tv_code_B.Gain1) - tv_code_B.Gain2;

    /* Gain: '<S4>/Gain' */
    tv_code_B.Gain_o = 95.098039215686271 * tv_code_B.Sum_c;

    /* Gain: '<S8>/Gain1' */
    tv_code_B.Gain1_m = 0.00035029827898455532 * tv_code_B.Gain_o;

    /* Product: '<S8>/Product' */
    tv_code_B.Product = tv_code_B.Gain1_m * tv_code_B.Sum_h;

    /* Saturate: '<S2>/Saturation' */
    u0 = tv_code_B.Product;
    if (u0 > 143.0) {
      /* Saturate: '<S2>/Saturation' */
      tv_code_B.Saturation_c = 143.0;
    } else if (u0 < 0.0) {
      /* Saturate: '<S2>/Saturation' */
      tv_code_B.Saturation_c = 0.0;
    } else {
      /* Saturate: '<S2>/Saturation' */
      tv_code_B.Saturation_c = u0;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* Switch: '<S2>/Switch' incorporates:
     *  Inport: '<Root>/Inport7'
     */
    tv_code_B.Switch = (tv_code_U.Inport7 != 0.0);

    /* DotProduct: '<S2>/Dot Product' */
    u0 = tv_code_B.Switch;
    tmp = tv_code_B.Saturation_c;

    /* DotProduct: '<S2>/Dot Product' */
    tv_code_B.DotProduct_j = u0 * tmp;

    /* Gain: '<S9>/Gain' */
    tv_code_B.Gain_n = y;

    /* Sum: '<S9>/Sum' incorporates:
     *  Inport: '<Root>/Inport7'
     *  Sum: '<S10>/Sum'
     */
    Sum_a_tmp = tv_code_U.Inport7 + tv_code_B.Gain_n;

    /* Sum: '<S9>/Sum' */
    tv_code_B.Sum_a = Sum_a_tmp;

    /* Gain: '<S5>/Gain2' */
    tv_code_B.Gain2_p = Gain2_tmp;

    /* Gain: '<S5>/Gain1' */
    tv_code_B.Gain1_d = Gain1_tmp;

    /* Sum: '<S5>/Sum' incorporates:
     *  Constant: '<S5>/Constant'
     */
    tv_code_B.Sum_j = (7.5046500000000007 - tv_code_B.Gain1_d) +
      tv_code_B.Gain2_p;

    /* Gain: '<S5>/Gain' */
    tv_code_B.Gain_f = 95.098039215686271 * tv_code_B.Sum_j;

    /* Gain: '<S9>/Gain1' */
    tv_code_B.Gain1_o = 0.00035029827898455532 * tv_code_B.Gain_f;

    /* Product: '<S9>/Product' */
    tv_code_B.Product_m = tv_code_B.Gain1_o * tv_code_B.Sum_a;

    /* Saturate: '<S2>/Saturation1' */
    u0 = tv_code_B.Product_m;
    if (u0 > 143.0) {
      /* Saturate: '<S2>/Saturation1' */
      tv_code_B.Saturation1 = 143.0;
    } else if (u0 < 0.0) {
      /* Saturate: '<S2>/Saturation1' */
      tv_code_B.Saturation1 = 0.0;
    } else {
      /* Saturate: '<S2>/Saturation1' */
      tv_code_B.Saturation1 = u0;
    }

    /* End of Saturate: '<S2>/Saturation1' */

    /* DotProduct: '<S2>/Dot Product1' */
    u0 = tv_code_B.Switch;
    tmp = tv_code_B.Saturation1;

    /* DotProduct: '<S2>/Dot Product1' */
    tv_code_B.DotProduct1_e = u0 * tmp;

    /* Gain: '<S11>/Gain' */
    tv_code_B.Gain_c = y;

    /* Sum: '<S11>/Sum' */
    tv_code_B.Sum_o = Sum_h_tmp;

    /* Gain: '<S6>/Gain2' */
    tv_code_B.Gain2_c = Gain2_tmp;

    /* Gain: '<S6>/Gain1' */
    tv_code_B.Gain1_n = Gain1_tmp;

    /* Sum: '<S6>/Sum' incorporates:
     *  Constant: '<S6>/Constant'
     */
    tv_code_B.Sum_c5 = (tv_code_B.Gain1_n + 7.5046500000000007) -
      tv_code_B.Gain2_c;

    /* Gain: '<S6>/Gain' */
    tv_code_B.Gain_ni = 95.098039215686271 * tv_code_B.Sum_c5;

    /* Gain: '<S11>/Gain1' */
    tv_code_B.Gain1_h = 0.00035029827898455532 * tv_code_B.Gain_ni;

    /* Product: '<S11>/Product' */
    tv_code_B.Product_l = tv_code_B.Gain1_h * tv_code_B.Sum_o;

    /* Saturate: '<S2>/Saturation2' */
    u0 = tv_code_B.Product_l;
    if (u0 > 143.0) {
      /* Saturate: '<S2>/Saturation2' */
      tv_code_B.Saturation2 = 143.0;
    } else if (u0 < 0.0) {
      /* Saturate: '<S2>/Saturation2' */
      tv_code_B.Saturation2 = 0.0;
    } else {
      /* Saturate: '<S2>/Saturation2' */
      tv_code_B.Saturation2 = u0;
    }

    /* End of Saturate: '<S2>/Saturation2' */

    /* DotProduct: '<S2>/Dot Product2' */
    u0 = tv_code_B.Switch;
    tmp = tv_code_B.Saturation2;

    /* DotProduct: '<S2>/Dot Product2' */
    tv_code_B.DotProduct2 = u0 * tmp;

    /* Gain: '<S10>/Gain' */
    tv_code_B.Gain_h5 = y;

    /* Sum: '<S10>/Sum' */
    tv_code_B.Sum_e = Sum_a_tmp;

    /* Gain: '<S7>/Gain2' */
    tv_code_B.Gain2_cd = Gain2_tmp;

    /* Gain: '<S7>/Gain1' */
    tv_code_B.Gain1_oe = Gain1_tmp;

    /* Sum: '<S7>/Sum' incorporates:
     *  Constant: '<S7>/Constant'
     */
    tv_code_B.Sum_i = (tv_code_B.Gain1_oe + 7.5046500000000007) +
      tv_code_B.Gain2_cd;

    /* Gain: '<S7>/Gain' */
    tv_code_B.Gain_ca = 95.098039215686271 * tv_code_B.Sum_i;

    /* Gain: '<S10>/Gain1' */
    tv_code_B.Gain1_nd = 0.00035029827898455532 * tv_code_B.Gain_ca;

    /* Product: '<S10>/Product' */
    tv_code_B.Product_c = tv_code_B.Gain1_nd * tv_code_B.Sum_e;

    /* Saturate: '<S2>/Saturation3' */
    u0 = tv_code_B.Product_c;
    if (u0 > 143.0) {
      /* Saturate: '<S2>/Saturation3' */
      tv_code_B.Saturation3 = 143.0;
    } else if (u0 < 0.0) {
      /* Saturate: '<S2>/Saturation3' */
      tv_code_B.Saturation3 = 0.0;
    } else {
      /* Saturate: '<S2>/Saturation3' */
      tv_code_B.Saturation3 = u0;
    }

    /* End of Saturate: '<S2>/Saturation3' */

    /* DotProduct: '<S2>/Dot Product3' */
    u0 = tv_code_B.Switch;
    tmp = tv_code_B.Saturation3;

    /* DotProduct: '<S2>/Dot Product3' */
    tv_code_B.DotProduct3 = u0 * tmp;

    /* Switch: '<Root>/speed_switch' */
    tv_code_B.speed_switch[0] = tv_code_B.DotProduct_j;
    tv_code_B.speed_switch[1] = tv_code_B.DotProduct1_e;
    tv_code_B.speed_switch[2] = tv_code_B.DotProduct2;
    tv_code_B.speed_switch[3] = tv_code_B.DotProduct3;
  } else {
    /* Gain: '<S1>/Gain' incorporates:
     *  Inport: '<Root>/Inport7'
     */
    tv_code_B.Gain = 0.25 * tv_code_U.Inport7;

    /* Saturate: '<S1>/Saturation' */
    if (tv_code_B.Gain <= 0.0) {
      y = 0.0;
    } else {
      y = tv_code_B.Gain;
    }

    /* Saturate: '<S1>/Saturation' */
    tv_code_B.Saturation[0] = y;

    /* Saturate: '<S1>/Saturation' */
    if (tv_code_B.Gain <= 0.0) {
      y = 0.0;
    } else {
      y = tv_code_B.Gain;
    }

    /* Saturate: '<S1>/Saturation' */
    tv_code_B.Saturation[1] = y;

    /* Saturate: '<S1>/Saturation' */
    if (tv_code_B.Gain <= 0.0) {
      y = 0.0;
    } else {
      y = tv_code_B.Gain;
    }

    /* Saturate: '<S1>/Saturation' */
    tv_code_B.Saturation[2] = y;

    /* Saturate: '<S1>/Saturation' */
    if (tv_code_B.Gain <= 0.0) {
      y = 0.0;
    } else {
      y = tv_code_B.Gain;
    }

    /* Saturate: '<S1>/Saturation' */
    tv_code_B.Saturation[3] = y;

    /* Switch: '<Root>/speed_switch' */
    tv_code_B.speed_switch[0] = tv_code_B.Saturation[0];
    tv_code_B.speed_switch[1] = tv_code_B.Saturation[1];
    tv_code_B.speed_switch[2] = tv_code_B.Saturation[2];
    tv_code_B.speed_switch[3] = tv_code_B.Saturation[3];
  }

  /* End of Switch: '<Root>/speed_switch' */

  /* Outport: '<Root>/Outport' */
  tv_code_Y.Outport = tv_code_B.speed_switch[0];

  /* Outport: '<Root>/Outport1' */
  tv_code_Y.Outport1 = tv_code_B.speed_switch[1];

  /* Outport: '<Root>/Outport2' */
  tv_code_Y.Outport2 = tv_code_B.speed_switch[2];

  /* Outport: '<Root>/Outport3' */
  tv_code_Y.Outport3 = tv_code_B.speed_switch[3];

  /* DotProduct: '<S3>/Dot Product1' */
  u0 = tv_code_B.Sum;

  /* DotProduct: '<S3>/Dot Product1' incorporates:
   *  Inport: '<Root>/ki'
   */
  tv_code_B.DotProduct1 = u0 * tv_code_U.ki;
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
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
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

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE = tv_code_B.DotProduct1;
}

/* Model initialize function */
void tv_code_initialize(void)
{
  /* Registration code */
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
    rtsiSetContStateDisabledPtr(&tv_code_M->solverInfo, (boolean_T**)
      &tv_code_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&tv_code_M->solverInfo, (&rtmGetErrorStatus(tv_code_M)));
    rtsiSetRTModelPtr(&tv_code_M->solverInfo, tv_code_M);
  }

  rtsiSetSimTimeStep(&tv_code_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&tv_code_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&tv_code_M->solverInfo, false);
  tv_code_M->intgData.y = tv_code_M->odeY;
  tv_code_M->intgData.f[0] = tv_code_M->odeF[0];
  tv_code_M->intgData.f[1] = tv_code_M->odeF[1];
  tv_code_M->intgData.f[2] = tv_code_M->odeF[2];
  tv_code_M->intgData.f[3] = tv_code_M->odeF[3];
  tv_code_M->contStates = ((X_tv_code_T *) &tv_code_X);
  tv_code_M->contStateDisabled = ((XDis_tv_code_T *) &tv_code_XDis);
  tv_code_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&tv_code_M->solverInfo, (void *)&tv_code_M->intgData);
  rtsiSetSolverName(&tv_code_M->solverInfo,"ode4");
  rtmSetTPtr(tv_code_M, &tv_code_M->Timing.tArray[0]);
  tv_code_M->Timing.stepSize0 = 0.01;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  tv_code_X.Integrator_CSTATE = 0.0;
}

/* Model terminate function */
void tv_code_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
