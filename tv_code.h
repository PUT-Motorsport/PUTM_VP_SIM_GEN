/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code.h
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

#ifndef tv_code_h_
#define tv_code_h_
#ifndef tv_code_COMMON_INCLUDES_
#define tv_code_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* tv_code_COMMON_INCLUDES_ */

#include "tv_code_types.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Sum;                          /* '<S3>/Sum' */
  real_T Integrator;                   /* '<S3>/Integrator' */
  real_T speed_switch[4];              /* '<Root>/speed_switch' */
  real_T DotProduct1;                  /* '<S3>/Dot Product1' */
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Saturation[4];                /* '<S1>/Saturation' */
  real_T DotProduct;                   /* '<S3>/Dot Product' */
  real_T Sum1;                         /* '<S3>/Sum1' */
  real_T Gain_h;                       /* '<S8>/Gain' */
  real_T Sum_h;                        /* '<S8>/Sum' */
  real_T Gain2;                        /* '<S4>/Gain2' */
  real_T Gain1;                        /* '<S4>/Gain1' */
  real_T Sum_c;                        /* '<S4>/Sum' */
  real_T Gain_o;                       /* '<S4>/Gain' */
  real_T Gain1_m;                      /* '<S8>/Gain1' */
  real_T Product;                      /* '<S8>/Product' */
  real_T Saturation_c;                 /* '<S2>/Saturation' */
  real_T Switch;                       /* '<S2>/Switch' */
  real_T DotProduct_j;                 /* '<S2>/Dot Product' */
  real_T Gain_n;                       /* '<S9>/Gain' */
  real_T Sum_a;                        /* '<S9>/Sum' */
  real_T Gain2_p;                      /* '<S5>/Gain2' */
  real_T Gain1_d;                      /* '<S5>/Gain1' */
  real_T Sum_j;                        /* '<S5>/Sum' */
  real_T Gain_f;                       /* '<S5>/Gain' */
  real_T Gain1_o;                      /* '<S9>/Gain1' */
  real_T Product_m;                    /* '<S9>/Product' */
  real_T Saturation1;                  /* '<S2>/Saturation1' */
  real_T DotProduct1_e;                /* '<S2>/Dot Product1' */
  real_T Gain_c;                       /* '<S11>/Gain' */
  real_T Sum_o;                        /* '<S11>/Sum' */
  real_T Gain2_c;                      /* '<S6>/Gain2' */
  real_T Gain1_n;                      /* '<S6>/Gain1' */
  real_T Sum_c5;                       /* '<S6>/Sum' */
  real_T Gain_ni;                      /* '<S6>/Gain' */
  real_T Gain1_h;                      /* '<S11>/Gain1' */
  real_T Product_l;                    /* '<S11>/Product' */
  real_T Saturation2;                  /* '<S2>/Saturation2' */
  real_T DotProduct2;                  /* '<S2>/Dot Product2' */
  real_T Gain_h5;                      /* '<S10>/Gain' */
  real_T Sum_e;                        /* '<S10>/Sum' */
  real_T Gain2_cd;                     /* '<S7>/Gain2' */
  real_T Gain1_oe;                     /* '<S7>/Gain1' */
  real_T Sum_i;                        /* '<S7>/Sum' */
  real_T Gain_ca;                      /* '<S7>/Gain' */
  real_T Gain1_nd;                     /* '<S10>/Gain1' */
  real_T Product_c;                    /* '<S10>/Product' */
  real_T Saturation3;                  /* '<S2>/Saturation3' */
  real_T DotProduct3;                  /* '<S2>/Dot Product3' */
} B_tv_code_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
} X_tv_code_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
} XDot_tv_code_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S3>/Integrator' */
} XDis_tv_code_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ax;                           /* '<Root>/ax' */
  real_T ay;                           /* '<Root>/ay' */
  real_T vx;                           /* '<Root>/vx' */
  real_T yaw_rate_ref;                 /* '<Root>/yaw_rate_ref' */
  real_T yaw_rate;                     /* '<Root>/yaw_rate' */
  real_T kp;                           /* '<Root>/kp' */
  real_T ki;                           /* '<Root>/ki' */
  real_T Inport7;                      /* '<Root>/Inport7' */
} ExtU_tv_code_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Outport;                      /* '<Root>/Outport' */
  real_T Outport1;                     /* '<Root>/Outport1' */
  real_T Outport2;                     /* '<Root>/Outport2' */
  real_T Outport3;                     /* '<Root>/Outport3' */
} ExtY_tv_code_T;

/* Real-time Model Data Structure */
struct tag_RTM_tv_code_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_tv_code_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_tv_code_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[4][1];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_tv_code_T tv_code_B;

/* Continuous states (default storage) */
extern X_tv_code_T tv_code_X;

/* Disabled states (default storage) */
extern XDis_tv_code_T tv_code_XDis;

/* External inputs (root inport signals with default storage) */
extern ExtU_tv_code_T tv_code_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_tv_code_T tv_code_Y;

/* Model entry point functions */
extern void tv_code_initialize(void);
extern void tv_code_step(void);
extern void tv_code_terminate(void);

/* Real-time Model object */
extern RT_MODEL_tv_code_T *const tv_code_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/ax_gain' : Eliminated nontunable gain of 1
 * Block '<Root>/ay_gain' : Eliminated nontunable gain of 1
 * Block '<Root>/ki_gain' : Eliminated nontunable gain of 1
 * Block '<Root>/kp_gain' : Eliminated nontunable gain of 1
 * Block '<Root>/total_torque' : Eliminated nontunable gain of 1
 * Block '<Root>/trq_fl' : Eliminated nontunable gain of 1
 * Block '<Root>/trq_fr' : Eliminated nontunable gain of 1
 * Block '<Root>/trq_rl' : Eliminated nontunable gain of 1
 * Block '<Root>/trq_rr' : Eliminated nontunable gain of 1
 * Block '<Root>/vx_gain' : Eliminated nontunable gain of 1
 * Block '<Root>/yaw_rate_gain' : Eliminated nontunable gain of 1
 * Block '<Root>/yaw_rate_ref_gain' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'tv_code'
 * '<S1>'   : 'tv_code/Toque distibution NO Tv'
 * '<S2>'   : 'tv_code/Torque distribution Tv'
 * '<S3>'   : 'tv_code/Upper Controller'
 * '<S4>'   : 'tv_code/Torque distribution Tv/Fzfl'
 * '<S5>'   : 'tv_code/Torque distribution Tv/Fzfr'
 * '<S6>'   : 'tv_code/Torque distribution Tv/Fzrl'
 * '<S7>'   : 'tv_code/Torque distribution Tv/Fzrr'
 * '<S8>'   : 'tv_code/Torque distribution Tv/T_FL'
 * '<S9>'   : 'tv_code/Torque distribution Tv/T_FR'
 * '<S10>'  : 'tv_code/Torque distribution Tv/T_FR1'
 * '<S11>'  : 'tv_code/Torque distribution Tv/T_RL'
 */
#endif                                 /* tv_code_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
