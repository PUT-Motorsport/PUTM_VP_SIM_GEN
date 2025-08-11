/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code_private.h
 *
 * Code generated for Simulink model 'tv_code'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Aug 11 17:54:13 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_tv_code_private_h_
#define RTW_HEADER_tv_code_private_h_
#include "rtwtypes.h"
#include "tv_code.h"
#include "tv_code_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
extern void tv_code_ax_filter_Init(DW_ax_filter_tv_code_T *localDW);
extern void tv_code_ax_filter(real_T rtu_0, B_ax_filter_tv_code_T *localB,
  DW_ax_filter_tv_code_T *localDW);
extern void tv_code_MATLABFunction(const real_T rtu_data[4221], real_T
  rtu_torque_req, real_T rtu_row_num, real_T *rty_idx);
extern void tv_code_ax_filter_Term(DW_ax_filter_tv_code_T *localDW);

/* private model entry point functions */
extern void tv_code_derivatives(void);

#endif                                 /* RTW_HEADER_tv_code_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
