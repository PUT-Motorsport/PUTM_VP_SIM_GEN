/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code.h
 *
 * Code generated for Simulink model 'tv_code'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov  3 18:13:48 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_tv_code_h_
#define RTW_HEADER_tv_code_h_
#ifndef tv_code_COMMON_INCLUDES_
#define tv_code_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* tv_code_COMMON_INCLUDES_ */

#include "tv_code_types.h"
#include "rtGetInf.h"
#include <string.h>
#include "rt_nonfinite.h"

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

/* Block signals for system '<S3>/ax_filter' */
typedef struct {
  real_T ax_filter;                    /* '<S3>/ax_filter' */
} B_ax_filter_tv_code_T;

/* Block states (default storage) for system '<S3>/ax_filter' */
typedef struct {
  dsp_simulink_LowpassFilter_tv_T obj; /* '<S3>/ax_filter' */
  boolean_T objisempty;                /* '<S3>/ax_filter' */
  boolean_T isInitialized;             /* '<S3>/ax_filter' */
} DW_ax_filter_tv_code_T;

/* Block signals for system '<S3>/speed_filter_fl' */
typedef struct {
  real_T speed_filter_fl;              /* '<S3>/speed_filter_fl' */
} B_speed_filter_fl_tv_code_T;

/* Block states (default storage) for system '<S3>/speed_filter_fl' */
typedef struct {
  dsp_simulink_LowpassFilter_j_T obj;  /* '<S3>/speed_filter_fl' */
  boolean_T objisempty;                /* '<S3>/speed_filter_fl' */
  boolean_T isInitialized;             /* '<S3>/speed_filter_fl' */
} DW_speed_filter_fl_tv_code_T;

/* Block signals (default storage) */
typedef struct {
  real_T Product1;                     /* '<S18>/Product1' */
  real_T Saturation[4];                /* '<S16>/Saturation' */
  real_T Gain;                         /* '<S3>/Gain' */
  real_T Gain1;                        /* '<S3>/Gain1' */
  real_T Gain2;                        /* '<S3>/Gain2' */
  real_T Gain3;                        /* '<S3>/Gain3' */
  real_T avg_min_speed_switch;         /* '<S15>/avg_min_speed_switch' */
  real_T Switch;                       /* '<S14>/Switch' */
  real_T Switch_k;                     /* '<S17>/Switch' */
  real_T Gain1_m;                      /* '<S26>/Gain1' */
  real_T DotProduct;                   /* '<S19>/Dot Product' */
  real_T Sum1;                         /* '<S19>/Sum1' */
  real_T Gain1_b;                      /* '<S27>/Gain1' */
  real_T Gain1_bu;                     /* '<S29>/Gain1' */
  real_T Gain1_e;                      /* '<S28>/Gain1' */
  real_T speed_switch[4];              /* '<S4>/speed_switch' */
  real_T Gain_m;                       /* '<S5>/Gain' */
  real_T ek_slip;                      /* '<S6>/ek_slip' */
  real_T Gain_h;                       /* '<S7>/Gain' */
  real_T Gain_h4;                      /* '<S8>/Gain' */
  real_T trq_fl;                       /* '<Root>/trq_fl' */
  real_T trq_fr;                       /* '<Root>/trq_fr' */
  real_T trq_rl;                       /* '<Root>/trq_rl' */
  real_T trq_rr;                       /* '<Root>/trq_rr' */
  real_T DotProduct1;                  /* '<S19>/Dot Product1' */
  real_T yaw_ref;                      /* '<S13>/yaw_ref' */
  real_T DotProduct_j;                 /* '<S17>/Dot Product' */
  real_T DotProduct1_l;                /* '<S17>/Dot Product1' */
  real_T DotProduct2;                  /* '<S17>/Dot Product2' */
  real_T DotProduct3;                  /* '<S17>/Dot Product3' */
  real_T Gain_mh;                      /* '<S14>/Gain' */
  real_T Min;                          /* '<S15>/Min' */
  real_T Gain_hu;                      /* '<S15>/Gain' */
  real_T regen_switch;                 /* '<S14>/regen_switch' */
  real_T Gain1_d;                      /* '<S14>/Gain1' */
  real_T Max;                          /* '<S5>/Max' */
  real_T Max_o;                        /* '<S6>/Max' */
  real_T Max_f;                        /* '<S7>/Max' */
  real_T Max_d;                        /* '<S8>/Max' */
  real_T Integrator;                   /* '<S19>/Integrator' */
  real_T DotProduct_f;                 /* '<S9>/Dot Product' */
  real_T DotProduct_fj;                /* '<S10>/Dot Product' */
  real_T DotProduct_p;                 /* '<S11>/Dot Product' */
  real_T DotProduct_n;                 /* '<S12>/Dot Product' */
  real_T slip_switch[4];               /* '<S1>/slip_switch' */
  real_T Plus;                         /* '<S15>/Plus' */
  real_T DotProduct_h;                 /* '<S21>/Dot Product' */
  real_T div2;                         /* '<S21>/div2' */
  real_T Saturation_j;                 /* '<S13>/Saturation' */
  real_T Gain1_a;                      /* '<S20>/Gain1' */
  real_T Sum1_p;                       /* '<S8>/Sum1' */
  real_T Gain2_a;                      /* '<S25>/Gain2' */
  real_T Saturation3;                  /* '<S17>/Saturation3' */
  real_T Max_a;                        /* '<S14>/Max' */
  real_T Saturation2;                  /* '<S17>/Saturation2' */
  real_T Sum;                          /* '<S19>/Sum' */
  real_T e_slip;                       /* '<S8>/e_slip' */
  B_ax_filter_tv_code_T yaw_rate_filter;/* '<S3>/ax_filter' */
  B_speed_filter_fl_tv_code_T speed_filter_rr;/* '<S3>/speed_filter_fl' */
  B_speed_filter_fl_tv_code_T speed_filter_rl;/* '<S3>/speed_filter_fl' */
  B_speed_filter_fl_tv_code_T speed_filter_fr;/* '<S3>/speed_filter_fl' */
  B_speed_filter_fl_tv_code_T speed_filter_fl;/* '<S3>/speed_filter_fl' */
  B_ax_filter_tv_code_T ay_filter;     /* '<S3>/ax_filter' */
  B_ax_filter_tv_code_T ax_filter;     /* '<S3>/ax_filter' */
} B_tv_code_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_ax_filter_tv_code_T yaw_rate_filter;/* '<S3>/ax_filter' */
  DW_speed_filter_fl_tv_code_T speed_filter_rr;/* '<S3>/speed_filter_fl' */
  DW_speed_filter_fl_tv_code_T speed_filter_rl;/* '<S3>/speed_filter_fl' */
  DW_speed_filter_fl_tv_code_T speed_filter_fr;/* '<S3>/speed_filter_fl' */
  DW_speed_filter_fl_tv_code_T speed_filter_fl;/* '<S3>/speed_filter_fl' */
  DW_ax_filter_tv_code_T ay_filter;    /* '<S3>/ax_filter' */
  DW_ax_filter_tv_code_T ax_filter;    /* '<S3>/ax_filter' */
} DW_tv_code_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S19>/Integrator' */
} X_tv_code_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S19>/Integrator' */
} XDot_tv_code_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S19>/Integrator' */
} XDis_tv_code_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (default storage) */
struct P_tv_code_T_ {
  real_T K_slip;                       /* Variable: K_slip
                                        * Referenced by:
                                        *   '<S5>/Gain'
                                        *   '<S6>/ek_slip'
                                        *   '<S7>/Gain'
                                        *   '<S8>/Gain'
                                        */
  real_T Ku;                           /* Variable: Ku
                                        * Referenced by: '<S13>/Desired Understeer Gradient'
                                        */
  real_T L;                            /* Variable: L
                                        * Referenced by:
                                        *   '<S13>/axlebase'
                                        *   '<S20>/Z1'
                                        *   '<S20>/Z2'
                                        *   '<S22>/Gain'
                                        *   '<S23>/Gain'
                                        *   '<S24>/Gain'
                                        *   '<S25>/Gain'
                                        */
  real_T Mz_I;                         /* Variable: Mz_I
                                        * Referenced by: '<S3>/Mz Integative Gain'
                                        */
  real_T Mz_p;                         /* Variable: Mz_p
                                        * Referenced by: '<S3>/Mz Proportional Gain'
                                        */
  real_T drive_ratio;                  /* Variable: drive_ratio
                                        * Referenced by:
                                        *   '<S17>/Saturation'
                                        *   '<S17>/Saturation1'
                                        *   '<S17>/Saturation2'
                                        *   '<S17>/Saturation3'
                                        *   '<S18>/Constant1'
                                        *   '<S20>/Gain'
                                        *   '<S20>/Gain1'
                                        */
  real_T g;                            /* Variable: g
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
  real_T h;                            /* Variable: h
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
  real_T lf;                           /* Variable: lf
                                        * Referenced by:
                                        *   '<S20>/Z1'
                                        *   '<S24>/Constant'
                                        *   '<S24>/Gain2'
                                        *   '<S25>/Constant'
                                        *   '<S25>/Gain2'
                                        */
  real_T lr;                           /* Variable: lr
                                        * Referenced by:
                                        *   '<S20>/Z2'
                                        *   '<S22>/Constant'
                                        *   '<S22>/Gain2'
                                        *   '<S23>/Constant'
                                        *   '<S23>/Gain2'
                                        */
  real_T ls;                           /* Variable: ls
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
  real_T m;                            /* Variable: m
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
  real_T max_moment;                   /* Variable: max_moment
                                        * Referenced by:
                                        *   '<S17>/Saturation'
                                        *   '<S17>/Saturation1'
                                        *   '<S17>/Saturation2'
                                        *   '<S17>/Saturation3'
                                        *   '<S18>/Constant1'
                                        */
  real_T mu;                           /* Variable: mu
                                        * Referenced by:
                                        *   '<S20>/X1'
                                        *   '<S20>/X2'
                                        */
  real_T rw;                           /* Variable: rw
                                        * Referenced by:
                                        *   '<S3>/Gain'
                                        *   '<S3>/Gain1'
                                        *   '<S3>/Gain2'
                                        *   '<S3>/Gain3'
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
  real_T s_max;                        /* Variable: s_max
                                        * Referenced by:
                                        *   '<S9>/Constant'
                                        *   '<S10>/Constant'
                                        *   '<S11>/Constant'
                                        *   '<S12>/Constant'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T TT_max_Value;                 /* Expression: 50
                                        * Referenced by: '<S14>/TT_max'
                                        */
  real_T Vdc_Value;                    /* Expression: 550
                                        * Referenced by: '<S21>/Vdc'
                                        */
  real_T I_max_Value;                  /* Expression: 15
                                        * Referenced by: '<S21>/I_max'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.95
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S14>/Gain1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 1/4
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S14>/Switch1'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T acc_pedal_Value;              /* Expression: 1
                                        * Referenced by: '<S3>/acc_pedal'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Gain_Gain_po;                 /* Expression: 1/4
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T whl_speed_fl_Value;           /* Expression: 0
                                        * Referenced by: '<S3>/whl_speed_fl'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/14.25
                                        * Referenced by: '<S3>/Gain5'
                                        */
  real_T Gain8_Gain;                   /* Expression: pi/30
                                        * Referenced by: '<S3>/Gain8'
                                        */
  real_T whl_speed_fr_Value;           /* Expression: 0
                                        * Referenced by: '<S3>/whl_speed_fr'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/14.25
                                        * Referenced by: '<S3>/Gain4'
                                        */
  real_T Gain9_Gain;                   /* Expression: pi/30
                                        * Referenced by: '<S3>/Gain9'
                                        */
  real_T whl_speed_rl_Value;           /* Expression: 0
                                        * Referenced by: '<S3>/whl_speed_rl'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1/14.25
                                        * Referenced by: '<S3>/Gain6'
                                        */
  real_T Gain10_Gain;                  /* Expression: pi/30
                                        * Referenced by: '<S3>/Gain10'
                                        */
  real_T whl_speed_rr_Value;           /* Expression: 0
                                        * Referenced by: '<S3>/whl_speed_rr'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1/14.25
                                        * Referenced by: '<S3>/Gain7'
                                        */
  real_T Gain11_Gain;                  /* Expression: pi/30
                                        * Referenced by: '<S3>/Gain11'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S14>/Switch'
                                        */
  real_T ax_Value;                     /* Expression: 0
                                        * Referenced by: '<S3>/ax'
                                        */
  real_T ay_Value;                     /* Expression: 0
                                        * Referenced by: '<S3>/ay'
                                        */
  real_T yaw_rate_Value;               /* Expression: 0
                                        * Referenced by: '<S3>/yaw_rate'
                                        */
  real_T delta_Value;                  /* Expression: 0
                                        * Referenced by: '<S3>/delta'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S13>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0.3
                                        * Referenced by: '<S13>/Saturation1'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: 6
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: -6
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S19>/Integrator'
                                        */
  real_T speed_switch_Threshold;       /* Expression: 2
                                        * Referenced by: '<S4>/speed_switch'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant1_Value_d;            /* Expression: 1
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Constant1_Value_p;            /* Expression: 1
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 0
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant1_Value_i;            /* Expression: 1
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Constant2_Value_f;            /* Expression: 0
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Constant1_Value_g;            /* Expression: 1
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T trq_fl_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/trq_fl'
                                        */
  real_T trq_fr_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/trq_fr'
                                        */
  real_T trq_rl_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/trq_rl'
                                        */
  real_T trq_rr_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/trq_rr'
                                        */
  real_T yaw_ref_Gain;                 /* Expression: 1
                                        * Referenced by: '<S13>/yaw_ref'
                                        */
  uint8_T regen_switch_CurrentSetting;
                              /* Computed Parameter: regen_switch_CurrentSetting
                               * Referenced by: '<S14>/regen_switch'
                               */
  uint8_T avg_min_speed_switch_CurrentSet;
                          /* Computed Parameter: avg_min_speed_switch_CurrentSet
                           * Referenced by: '<S15>/avg_min_speed_switch'
                           */
  uint8_T slip_switch_CurrentSetting;
                               /* Computed Parameter: slip_switch_CurrentSetting
                                * Referenced by: '<S1>/slip_switch'
                                */
};

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
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_tv_code_T tv_code_P;

/* Block signals (default storage) */
extern B_tv_code_T tv_code_B;

/* Continuous states (default storage) */
extern X_tv_code_T tv_code_X;

/* Block states (default storage) */
extern DW_tv_code_T tv_code_DW;

/* Model entry point functions */
extern void tv_code_initialize(void);
extern void tv_code_step(void);
extern void tv_code_terminate(void);

/* Real-time Model object */
extern RT_MODEL_tv_code_T *const tv_code_M;

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
 * '<S1>'   : 'tv_code/The Best TorqueVectoring'
 * '<S2>'   : 'tv_code/The Best TorqueVectoring/AntiSlip'
 * '<S3>'   : 'tv_code/The Best TorqueVectoring/CarMaker_Inputs'
 * '<S4>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring2'
 * '<S5>'   : 'tv_code/The Best TorqueVectoring/AntiSlip/slope'
 * '<S6>'   : 'tv_code/The Best TorqueVectoring/AntiSlip/slope1'
 * '<S7>'   : 'tv_code/The Best TorqueVectoring/AntiSlip/slope2'
 * '<S8>'   : 'tv_code/The Best TorqueVectoring/AntiSlip/slope3'
 * '<S9>'   : 'tv_code/The Best TorqueVectoring/AntiSlip/slope/Subsystem'
 * '<S10>'  : 'tv_code/The Best TorqueVectoring/AntiSlip/slope1/Subsystem'
 * '<S11>'  : 'tv_code/The Best TorqueVectoring/AntiSlip/slope2/Subsystem'
 * '<S12>'  : 'tv_code/The Best TorqueVectoring/AntiSlip/slope3/Subsystem'
 * '<S13>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Reference generator'
 * '<S14>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Regenerative braking'
 * '<S15>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Speed estimaor'
 * '<S16>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Toque distibution NO Tv'
 * '<S17>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv'
 * '<S18>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Total Torque Request'
 * '<S19>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Upper Controller'
 * '<S20>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Regenerative braking/Subsystem'
 * '<S21>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Regenerative braking/Tmax'
 * '<S22>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/Fzfl'
 * '<S23>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/Fzfr'
 * '<S24>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/Fzrl'
 * '<S25>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/Fzrr'
 * '<S26>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/T_FL'
 * '<S27>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/T_FR'
 * '<S28>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/T_FR1'
 * '<S29>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/T_RL'
 */
#endif                                 /* RTW_HEADER_tv_code_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
