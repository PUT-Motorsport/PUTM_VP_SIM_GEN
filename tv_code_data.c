/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code_data.c
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

/* Block parameters (default storage) */
P_tv_code_T tv_code_P = {
  /* Variable: K_slip
   * Referenced by:
   *   '<S5>/Gain'
   *   '<S6>/ek_slip'
   *   '<S7>/Gain'
   *   '<S8>/Gain'
   */
  20.0,

  /* Variable: Ku
   * Referenced by: '<S13>/Desired Understeer Gradient'
   */
  -0.0014285714285714286,

  /* Variable: L
   * Referenced by:
   *   '<S13>/axlebase'
   *   '<S20>/Z1'
   *   '<S20>/Z2'
   *   '<S22>/Gain'
   *   '<S23>/Gain'
   *   '<S24>/Gain'
   *   '<S25>/Gain'
   */
  1.53,

  /* Variable: Mz_I
   * Referenced by: '<S3>/Mz Integative Gain'
   */
  30.0,

  /* Variable: Mz_p
   * Referenced by: '<S3>/Mz Proportional Gain'
   */
  200.0,

  /* Variable: drive_ratio
   * Referenced by:
   *   '<S17>/Saturation'
   *   '<S17>/Saturation1'
   *   '<S17>/Saturation2'
   *   '<S17>/Saturation3'
   *   '<S18>/Constant1'
   *   '<S20>/Gain'
   *   '<S20>/Gain1'
   */
  14.25,

  /* Variable: g
   * Referenced by:
   *   '<S20>/Z1'
   *   '<S20>/Z2'
   *   '<S22>/Constant'
   *   '<S23>/Constant'
   *   '<S24>/Constant'
   *   '<S25>/Constant'
   *   '<S26>/Gain1'
   *   '<S27>/Gain1'
   *   '<S28>/Gain1'
   *   '<S29>/Gain1'
   */
  9.81,

  /* Variable: h
   * Referenced by:
   *   '<S22>/Gain1'
   *   '<S22>/Gain2'
   *   '<S23>/Gain1'
   *   '<S23>/Gain2'
   *   '<S24>/Gain1'
   *   '<S24>/Gain2'
   *   '<S25>/Gain1'
   *   '<S25>/Gain2'
   */
  0.3,

  /* Variable: lf
   * Referenced by:
   *   '<S20>/Z1'
   *   '<S24>/Constant'
   *   '<S24>/Gain2'
   *   '<S25>/Constant'
   *   '<S25>/Gain2'
   */
  0.765,

  /* Variable: lr
   * Referenced by:
   *   '<S20>/Z2'
   *   '<S22>/Constant'
   *   '<S22>/Gain2'
   *   '<S23>/Constant'
   *   '<S23>/Gain2'
   */
  0.765,

  /* Variable: ls
   * Referenced by:
   *   '<S22>/Gain2'
   *   '<S23>/Gain2'
   *   '<S24>/Gain2'
   *   '<S25>/Gain2'
   *   '<S26>/Gain'
   *   '<S27>/Gain'
   *   '<S28>/Gain'
   *   '<S29>/Gain'
   */
  1.242,

  /* Variable: m
   * Referenced by:
   *   '<S20>/Z1'
   *   '<S20>/Z2'
   *   '<S22>/Gain'
   *   '<S23>/Gain'
   *   '<S24>/Gain'
   *   '<S25>/Gain'
   *   '<S26>/Gain1'
   *   '<S27>/Gain1'
   *   '<S28>/Gain1'
   *   '<S29>/Gain1'
   */
  297.0,

  /* Variable: max_moment
   * Referenced by:
   *   '<S17>/Saturation'
   *   '<S17>/Saturation1'
   *   '<S17>/Saturation2'
   *   '<S17>/Saturation3'
   *   '<S18>/Constant1'
   */
  9.8,

  /* Variable: mu
   * Referenced by:
   *   '<S20>/X1'
   *   '<S20>/X2'
   */
  1.48,

  /* Variable: rw
   * Referenced by:
   *   '<S15>/car_vx'
   *   '<S9>/Gain'
   *   '<S10>/Gain'
   *   '<S11>/Gain'
   *   '<S12>/Gain'
   *   '<S20>/Ta'
   *   '<S20>/Tr'
   *   '<S26>/Gain'
   *   '<S27>/Gain'
   *   '<S28>/Gain'
   *   '<S29>/Gain'
   */
  0.217,

  /* Variable: s_max
   * Referenced by:
   *   '<S9>/Constant'
   *   '<S10>/Constant'
   *   '<S11>/Constant'
   *   '<S12>/Constant'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S14>/Constant'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S14>/TT_max'
   */
  50.0,

  /* Expression: 550
   * Referenced by: '<S21>/Vdc'
   */
  550.0,

  /* Expression: 15
   * Referenced by: '<S21>/I_max'
   */
  15.0,

  /* Expression: 0.95
   * Referenced by: '<S21>/Gain'
   */
  0.95,

  /* Expression: -1
   * Referenced by: '<S14>/Gain1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S14>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S14>/Switch1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S17>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S17>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/acc_pedal'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S18>/Constant'
   */
  0.0,

  /* Expression: 1/4
   * Referenced by: '<S16>/Gain'
   */
  0.25,

  /* Expression: inf
   * Referenced by: '<S16>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S16>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/whl_speed_fl'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/whl_speed_fr'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/whl_speed_rl'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/whl_speed_rr'
   */
  0.0,

  /* Expression: 1/4
   * Referenced by: '<S15>/Gain'
   */
  0.25,

  /* Expression: 0
   * Referenced by: '<S14>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/ax'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/ay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/yaw_rate'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/delta'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S13>/Constant'
   */
  1.0,

  /* Expression: inf
   * Referenced by: '<S13>/Saturation1'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<S13>/Saturation1'
   */
  0.3,

  /* Expression: 6
   * Referenced by: '<S13>/Saturation'
   */
  6.0,

  /* Expression: -6
   * Referenced by: '<S13>/Saturation'
   */
  -6.0,

  /* Expression: 0
   * Referenced by: '<S19>/Integrator'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S4>/speed_switch'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/trq_fl'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S10>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/trq_fr'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S11>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/trq_rl'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S12>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/trq_rr'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S13>/yaw_ref'
   */
  1.0,

  /* Computed Parameter: regen_switch_CurrentSetting
   * Referenced by: '<S14>/regen_switch'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
