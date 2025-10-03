/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code.h
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

/* Block signals for system '<S2>/ax_filter' */
typedef struct {
  real_T ax_filter;                    /* '<S2>/ax_filter' */
} B_ax_filter_tv_code_T;

/* Block states (default storage) for system '<S2>/ax_filter' */
typedef struct {
  dsp_simulink_LowpassFilter_tv_T obj; /* '<S2>/ax_filter' */
  boolean_T objisempty;                /* '<S2>/ax_filter' */
  boolean_T isInitialized;             /* '<S2>/ax_filter' */
} DW_ax_filter_tv_code_T;

/* Block signals (default storage) */
typedef struct {
  real_T Product1;                     /* '<S14>/Product1' */
  real_T Saturation[4];                /* '<S12>/Saturation' */
  real_T Gain1;                        /* '<S11>/Gain1' */
  real_T Switch;                       /* '<S10>/Switch' */
  real_T Switch_b;                     /* '<S13>/Switch' */
  real_T Gain1_k;                      /* '<S27>/Gain1' */
  real_T DotProduct;                   /* '<S15>/Dot Product' */
  real_T Sum1;                         /* '<S15>/Sum1' */
  real_T DotProduct_n;                 /* '<S13>/Dot Product' */
  real_T Gain1_j;                      /* '<S28>/Gain1' */
  real_T DotProduct1;                  /* '<S13>/Dot Product1' */
  real_T Gain1_d;                      /* '<S30>/Gain1' */
  real_T DotProduct2;                  /* '<S13>/Dot Product2' */
  real_T Gain1_m;                      /* '<S29>/Gain1' */
  real_T DotProduct3;                  /* '<S13>/Dot Product3' */
  real_T speed_switch[4];              /* '<S4>/speed_switch' */
  real_T TransferFcn;                  /* '<S3>/Transfer Fcn' */
  real_T Saturation3;                  /* '<S7>/Saturation3' */
  real_T Saturation2;                  /* '<S7>/Saturation2' */
  real_T Saturation1;                  /* '<S7>/Saturation1' */
  real_T Saturation_c;                 /* '<S7>/Saturation' */
  real_T Sum;                          /* '<S7>/Sum' */
  real_T trq_fl;                       /* '<Root>/trq_fl' */
  real_T trq_fr;                       /* '<Root>/trq_fr' */
  real_T trq_rl;                       /* '<Root>/trq_rl' */
  real_T trq_rr;                       /* '<Root>/trq_rr' */
  real_T Saturation3_l;                /* '<S16>/Saturation3' */
  real_T Ceil3;                        /* '<S16>/Ceil3' */
  real_T Saturation_p;                 /* '<S16>/Saturation' */
  real_T Ceil;                         /* '<S16>/Ceil' */
  real_T Saturation1_c;                /* '<S16>/Saturation1' */
  real_T Ceil1;                        /* '<S16>/Ceil1' */
  real_T Saturation2_a;                /* '<S16>/Saturation2' */
  real_T Ceil2;                        /* '<S16>/Ceil2' */
  real_T PowerError;                   /* '<S8>/Saturation' */
  real_T Max;                          /* '<S8>/Max' */
  real_T torque_fixed;                 /* '<S8>/torque_fixed' */
  real_T est_power;                    /* '<S8>/est_power' */
  real_T DotProduct1_a;                /* '<S15>/Dot Product1' */
  real_T yaw_ref;                      /* '<S9>/yaw_ref' */
  real_T Divide;                       /* '<S5>/Divide' */
  real_T regen_switch;                 /* '<S10>/regen_switch' */
  real_T Gain1_m3;                     /* '<S10>/Gain1' */
  real_T Gain;                         /* '<S10>/Gain' */
  real_T Switch_i[4];                  /* '<S7>/Switch' */
  real_T Min;                          /* '<S7>/Min' */
  real_T Min1;                         /* '<S7>/Min1' */
  real_T Min2;                         /* '<S7>/Min2' */
  real_T Min3;                         /* '<S7>/Min3' */
  real_T Gain1_b[4];                   /* '<S16>/Gain1' */
  real_T ManualSwitch[4];              /* '<S1>/Manual Switch' */
  real_T DotProduct3_n;                /* '<S6>/Dot Product3' */
  real_T DotProduct_i;                 /* '<S6>/Dot Product' */
  real_T DotProduct1_l;                /* '<S6>/Dot Product1' */
  real_T DotProduct2_a;                /* '<S6>/Dot Product2' */
  real_T DotProduct_l;                 /* '<S22>/Dot Product' */
  real_T div2;                         /* '<S22>/div2' */
  real_T T_max;                        /* '<S7>/Divide3' */
  real_T T_max_b;                      /* '<S7>/Divide2' */
  real_T Saturation_j;                 /* '<S9>/Saturation' */
  real_T Gain1_jz;                     /* '<S21>/Gain1' */
  real_T Gain11;                       /* '<S16>/Gain11' */
  real_T ki;                           /* '<S8>/ki' */
  real_T Max_a;                        /* '<S10>/Max' */
  real_T P_el;                         /* '<S3>/P_el' */
  real_T Torquefixed;                  /* '<S8>/Sum' */
  real_T P_est;                        /* '<S16>/Sum' */
  real_T Sum_d;                        /* '<S15>/Sum' */
  real_T Gain13;                       /* '<S16>/Gain13' */
  real_T Sum_f;                        /* '<S6>/Sum' */
  B_ax_filter_tv_code_T yaw_rate_filter;/* '<S2>/ax_filter' */
  B_ax_filter_tv_code_T ay_filter;     /* '<S2>/ax_filter' */
  B_ax_filter_tv_code_T ax_filter;     /* '<S2>/ax_filter' */
} B_tv_code_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_ax_filter_tv_code_T yaw_rate_filter;/* '<S2>/ax_filter' */
  DW_ax_filter_tv_code_T ay_filter;    /* '<S2>/ax_filter' */
  DW_ax_filter_tv_code_T ax_filter;    /* '<S2>/ax_filter' */
} DW_tv_code_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S15>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<S3>/Transfer Fcn' */
} X_tv_code_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S15>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<S3>/Transfer Fcn' */
} XDot_tv_code_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S15>/Integrator' */
  boolean_T TransferFcn_CSTATE;        /* '<S3>/Transfer Fcn' */
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
  real_T Ku;                           /* Variable: Ku
                                        * Referenced by: '<S9>/Desired Understeer Gradient'
                                        */
  real_T L;                            /* Variable: L
                                        * Referenced by:
                                        *   '<S9>/axlebase'
                                        *   '<S21>/Z1'
                                        *   '<S21>/Z2'
                                        *   '<S23>/Gain'
                                        *   '<S24>/Gain'
                                        *   '<S25>/Gain'
                                        *   '<S26>/Gain'
                                        */
  real_T Mz_I;                         /* Variable: Mz_I
                                        * Referenced by: '<S2>/Mz Integative Gain'
                                        */
  real_T Mz_p;                         /* Variable: Mz_p
                                        * Referenced by: '<S2>/Mz Proportional Gain'
                                        */
  real_T P_max;                        /* Variable: P_max
                                        * Referenced by:
                                        *   '<S3>/ref_p_max'
                                        *   '<S8>/Max_power'
                                        */
  real_T batt_curr;                    /* Variable: batt_curr
                                        * Referenced by: '<S3>/I_batt'
                                        */
  real_T batt_voltage;                 /* Variable: batt_voltage
                                        * Referenced by: '<S3>/P_el'
                                        */
  real_T drive_ratio;                  /* Variable: drive_ratio
                                        * Referenced by:
                                        *   '<S13>/Saturation'
                                        *   '<S13>/Saturation1'
                                        *   '<S13>/Saturation2'
                                        *   '<S13>/Saturation3'
                                        *   '<S14>/Constant1'
                                        *   '<S21>/Gain'
                                        *   '<S21>/Gain1'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by:
                                        *   '<S21>/Z1'
                                        *   '<S21>/Z2'
                                        *   '<S23>/Constant'
                                        *   '<S24>/Constant'
                                        *   '<S25>/Constant'
                                        *   '<S26>/Constant'
                                        *   '<S27>/Gain1'
                                        *   '<S28>/Gain1'
                                        *   '<S29>/Gain1'
                                        *   '<S30>/Gain1'
                                        */
  real_T h;                            /* Variable: h
                                        * Referenced by:
                                        *   '<S23>/Gain1'
                                        *   '<S23>/Gain2'
                                        *   '<S24>/Gain1'
                                        *   '<S24>/Gain2'
                                        *   '<S25>/Gain1'
                                        *   '<S25>/Gain2'
                                        *   '<S26>/Gain1'
                                        *   '<S26>/Gain2'
                                        */
  real_T lf;                           /* Variable: lf
                                        * Referenced by:
                                        *   '<S21>/Z1'
                                        *   '<S25>/Constant'
                                        *   '<S25>/Gain2'
                                        *   '<S26>/Constant'
                                        *   '<S26>/Gain2'
                                        */
  real_T lr;                           /* Variable: lr
                                        * Referenced by:
                                        *   '<S21>/Z2'
                                        *   '<S23>/Constant'
                                        *   '<S23>/Gain2'
                                        *   '<S24>/Constant'
                                        *   '<S24>/Gain2'
                                        */
  real_T ls;                           /* Variable: ls
                                        * Referenced by:
                                        *   '<S23>/Gain2'
                                        *   '<S24>/Gain2'
                                        *   '<S25>/Gain2'
                                        *   '<S26>/Gain2'
                                        *   '<S27>/Gain'
                                        *   '<S28>/Gain'
                                        *   '<S29>/Gain'
                                        *   '<S30>/Gain'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by:
                                        *   '<S21>/Z1'
                                        *   '<S21>/Z2'
                                        *   '<S23>/Gain'
                                        *   '<S24>/Gain'
                                        *   '<S25>/Gain'
                                        *   '<S26>/Gain'
                                        *   '<S27>/Gain1'
                                        *   '<S28>/Gain1'
                                        *   '<S29>/Gain1'
                                        *   '<S30>/Gain1'
                                        */
  real_T max_moment;                   /* Variable: max_moment
                                        * Referenced by:
                                        *   '<S13>/Saturation'
                                        *   '<S13>/Saturation1'
                                        *   '<S13>/Saturation2'
                                        *   '<S13>/Saturation3'
                                        *   '<S14>/Constant1'
                                        */
  real_T mu;                           /* Variable: mu
                                        * Referenced by:
                                        *   '<S21>/X1'
                                        *   '<S21>/X2'
                                        */
  real_T rw;                           /* Variable: rw
                                        * Referenced by:
                                        *   '<S11>/Gain1'
                                        *   '<S21>/Ta'
                                        *   '<S21>/Tr'
                                        *   '<S27>/Gain'
                                        *   '<S28>/Gain'
                                        *   '<S29>/Gain'
                                        *   '<S30>/Gain'
                                        */
  real_T stator_current_line_rms[4221];/* Variable: stator_current_line_rms
                                        * Referenced by:
                                        *   '<S16>/n-D Lookup Table1'
                                        *   '<S16>/n-D Lookup Table2'
                                        *   '<S16>/n-D Lookup Table3'
                                        *   '<S16>/n-D Lookup Table4'
                                        */
  real_T torque_map[4221];             /* Variable: torque_map
                                        * Referenced by:
                                        *   '<S16>/Constant2'
                                        *   '<S16>/Constant3'
                                        *   '<S16>/Constant5'
                                        *   '<S16>/Constant7'
                                        */
  real_T voltage_map[4221];            /* Variable: voltage_map
                                        * Referenced by:
                                        *   '<S16>/2-D Lookup Table'
                                        *   '<S16>/2-D Lookup Table1'
                                        *   '<S16>/2-D Lookup Table2'
                                        *   '<S16>/2-D Lookup Table3'
                                        */
  real_T Switch_Threshold;             /* Expression: 3
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T TT_max_Value;                 /* Expression: 50
                                        * Referenced by: '<S10>/TT_max'
                                        */
  real_T Vdc_Value;                    /* Expression: 550
                                        * Referenced by: '<S22>/Vdc'
                                        */
  real_T I_max_Value;                  /* Expression: 15
                                        * Referenced by: '<S22>/I_max'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 0.95
                                        * Referenced by: '<S22>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T whl_speed_fl_Value;           /* Expression: 0
                                        * Referenced by: '<S2>/whl_speed_fl'
                                        */
  real_T whl_speed_fr_Value;           /* Expression: 0
                                        * Referenced by: '<S2>/whl_speed_fr'
                                        */
  real_T whl_speed_rl_Value;           /* Expression: 0
                                        * Referenced by: '<S2>/whl_speed_rl'
                                        */
  real_T whl_speed_rr_Value;           /* Expression: 0
                                        * Referenced by: '<S2>/whl_speed_rr'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 60/(2*pi)
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T acc_pedal_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/acc_pedal'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 1/4
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 1/4
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 0
                                        * Referenced by: '<S10>/Switch'
                                        */
  real_T ax_Value;                     /* Expression: 0
                                        * Referenced by: '<S2>/ax'
                                        */
  real_T ay_Value;                     /* Expression: 0
                                        * Referenced by: '<S2>/ay'
                                        */
  real_T yaw_rate_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/yaw_rate'
                                        */
  real_T delta_Value;                  /* Expression: 0
                                        * Referenced by: '<S2>/delta'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S9>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0.3
                                        * Referenced by: '<S9>/Saturation1'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 6
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -6
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S10>/Switch1'
                                        */
  real_T speed_switch_Threshold;       /* Expression: 2
                                        * Referenced by: '<S4>/speed_switch'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S7>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0.5
                                        * Referenced by: '<S7>/Saturation3'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S7>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0.5
                                        * Referenced by: '<S7>/Saturation2'
                                        */
  real_T Saturation1_UpperSat_p;       /* Expression: inf
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_e;       /* Expression: 0.5
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: inf
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: 0.5
                                        * Referenced by: '<S7>/Saturation'
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
  real_T Saturation3_UpperSat_m;       /* Expression: 20000
                                        * Referenced by: '<S16>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_i;       /* Expression: 0
                                        * Referenced by: '<S16>/Saturation3'
                                        */
  real_T Rowindex3_tableData[201];     /* Expression: 0:1:200
                                        * Referenced by: '<S16>/Row index3'
                                        */
  real_T Rowindex3_bp01Data[201];      /* Computed Parameter: Rowindex3_bp01Data
                                        * Referenced by: '<S16>/Row index3'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S16>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: 1
                                        * Referenced by: '<S16>/Saturation4'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<S16>/Constant6'
                                        */
  real_T nDLookupTable4_bp01Data[201]; /* Expression: 0:1:200
                                        * Referenced by: '<S16>/n-D Lookup Table4'
                                        */
  real_T nDLookupTable4_bp02Data[21];  /* Expression: 0:1:20
                                        * Referenced by: '<S16>/n-D Lookup Table4'
                                        */
  real_T uDLookupTable3_bp01Data[201];
                                  /* Computed Parameter: uDLookupTable3_bp01Data
                                   * Referenced by: '<S16>/2-D Lookup Table3'
                                   */
  real_T uDLookupTable3_bp02Data[21];
                                 /* Expression: stator_current_line_rms(1,1:end)
                                  * Referenced by: '<S16>/2-D Lookup Table3'
                                  */
  real_T Gain13_Gain;                  /* Expression: sqrt(3)
                                        * Referenced by: '<S16>/Gain13'
                                        */
  real_T Saturation_UpperSat_or;       /* Expression: 20000
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: 0
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Rowindex_tableData[201];      /* Expression: 0:1:200
                                        * Referenced by: '<S16>/Row index'
                                        */
  real_T Rowindex_bp01Data[201];       /* Computed Parameter: Rowindex_bp01Data
                                        * Referenced by: '<S16>/Row index'
                                        */
  real_T Saturation7_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S16>/Saturation7'
                                        */
  real_T Saturation7_LowerSat;         /* Expression: 1
                                        * Referenced by: '<S16>/Saturation7'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T nDLookupTable1_bp01Data[201]; /* Expression: 0:1:200
                                        * Referenced by: '<S16>/n-D Lookup Table1'
                                        */
  real_T nDLookupTable1_bp02Data[21];  /* Expression: 0:1:20
                                        * Referenced by: '<S16>/n-D Lookup Table1'
                                        */
  real_T uDLookupTable_bp01Data[201];
                                   /* Computed Parameter: uDLookupTable_bp01Data
                                    * Referenced by: '<S16>/2-D Lookup Table'
                                    */
  real_T uDLookupTable_bp02Data[21];
                                 /* Expression: stator_current_line_rms(1,1:end)
                                  * Referenced by: '<S16>/2-D Lookup Table'
                                  */
  real_T Gain10_Gain;                  /* Expression: sqrt(3)
                                        * Referenced by: '<S16>/Gain10'
                                        */
  real_T Saturation1_UpperSat_c;       /* Expression: 20000
                                        * Referenced by: '<S16>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_h;       /* Expression: 0
                                        * Referenced by: '<S16>/Saturation1'
                                        */
  real_T Rowindex1_tableData[201];     /* Expression: 0:1:200
                                        * Referenced by: '<S16>/Row index1'
                                        */
  real_T Rowindex1_bp01Data[201];      /* Computed Parameter: Rowindex1_bp01Data
                                        * Referenced by: '<S16>/Row index1'
                                        */
  real_T Saturation6_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S16>/Saturation6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: 1
                                        * Referenced by: '<S16>/Saturation6'
                                        */
  real_T Constant1_Value_n;            /* Expression: 1
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T nDLookupTable2_bp01Data[201]; /* Expression: 0:1:200
                                        * Referenced by: '<S16>/n-D Lookup Table2'
                                        */
  real_T nDLookupTable2_bp02Data[21];  /* Expression: 0:1:20
                                        * Referenced by: '<S16>/n-D Lookup Table2'
                                        */
  real_T uDLookupTable1_bp01Data[201];
                                  /* Computed Parameter: uDLookupTable1_bp01Data
                                   * Referenced by: '<S16>/2-D Lookup Table1'
                                   */
  real_T uDLookupTable1_bp02Data[21];
                                 /* Expression: stator_current_line_rms(1,1:end)
                                  * Referenced by: '<S16>/2-D Lookup Table1'
                                  */
  real_T Gain11_Gain;                  /* Expression: sqrt(3)
                                        * Referenced by: '<S16>/Gain11'
                                        */
  real_T Saturation2_UpperSat_d;       /* Expression: 20000
                                        * Referenced by: '<S16>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_d;       /* Expression: 0
                                        * Referenced by: '<S16>/Saturation2'
                                        */
  real_T Rowindex2_tableData[201];     /* Expression: 0:1:200
                                        * Referenced by: '<S16>/Row index2'
                                        */
  real_T Rowindex2_bp01Data[201];      /* Computed Parameter: Rowindex2_bp01Data
                                        * Referenced by: '<S16>/Row index2'
                                        */
  real_T Saturation5_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S16>/Saturation5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: 1
                                        * Referenced by: '<S16>/Saturation5'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S16>/Constant4'
                                        */
  real_T nDLookupTable3_bp01Data[201]; /* Expression: 0:1:200
                                        * Referenced by: '<S16>/n-D Lookup Table3'
                                        */
  real_T nDLookupTable3_bp02Data[21];  /* Expression: 0:1:20
                                        * Referenced by: '<S16>/n-D Lookup Table3'
                                        */
  real_T uDLookupTable2_bp01Data[201];
                                  /* Computed Parameter: uDLookupTable2_bp01Data
                                   * Referenced by: '<S16>/2-D Lookup Table2'
                                   */
  real_T uDLookupTable2_bp02Data[21];
                                 /* Expression: stator_current_line_rms(1,1:end)
                                  * Referenced by: '<S16>/2-D Lookup Table2'
                                  */
  real_T Gain12_Gain;                  /* Expression: sqrt(3)
                                        * Referenced by: '<S16>/Gain12'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: inf
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: 0
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T kp_Gain;                      /* Expression: 2
                                        * Referenced by: '<S8>/kp'
                                        */
  real_T ki_Gain;                      /* Expression: 2
                                        * Referenced by: '<S8>/ki'
                                        */
  real_T torque_fixed_Gain;            /* Expression: 1
                                        * Referenced by: '<S8>/torque_fixed'
                                        */
  real_T est_power_Gain;               /* Expression: 1
                                        * Referenced by: '<S8>/est_power'
                                        */
  real_T yaw_ref_Gain;                 /* Expression: 1
                                        * Referenced by: '<S9>/yaw_ref'
                                        */
  real_T trq_rr_in_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/trq_rr_in'
                                        */
  real_T trq_fl_in_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/trq_fl_in'
                                        */
  real_T trq_fr_in_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/trq_fr_in'
                                        */
  real_T trq_rl_in_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/trq_rl_in'
                                        */
  real_T Saturation_UpperSat_dt;       /* Expression: inf
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: 1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  uint32_T nDLookupTable4_maxIndex[2];
                                  /* Computed Parameter: nDLookupTable4_maxIndex
                                   * Referenced by: '<S16>/n-D Lookup Table4'
                                   */
  uint32_T uDLookupTable3_maxIndex[2];
                                  /* Computed Parameter: uDLookupTable3_maxIndex
                                   * Referenced by: '<S16>/2-D Lookup Table3'
                                   */
  uint32_T nDLookupTable1_maxIndex[2];
                                  /* Computed Parameter: nDLookupTable1_maxIndex
                                   * Referenced by: '<S16>/n-D Lookup Table1'
                                   */
  uint32_T uDLookupTable_maxIndex[2];
                                   /* Computed Parameter: uDLookupTable_maxIndex
                                    * Referenced by: '<S16>/2-D Lookup Table'
                                    */
  uint32_T nDLookupTable2_maxIndex[2];
                                  /* Computed Parameter: nDLookupTable2_maxIndex
                                   * Referenced by: '<S16>/n-D Lookup Table2'
                                   */
  uint32_T uDLookupTable1_maxIndex[2];
                                  /* Computed Parameter: uDLookupTable1_maxIndex
                                   * Referenced by: '<S16>/2-D Lookup Table1'
                                   */
  uint32_T nDLookupTable3_maxIndex[2];
                                  /* Computed Parameter: nDLookupTable3_maxIndex
                                   * Referenced by: '<S16>/n-D Lookup Table3'
                                   */
  uint32_T uDLookupTable2_maxIndex[2];
                                  /* Computed Parameter: uDLookupTable2_maxIndex
                                   * Referenced by: '<S16>/2-D Lookup Table2'
                                   */
  uint8_T regen_switch_CurrentSetting;
                              /* Computed Parameter: regen_switch_CurrentSetting
                               * Referenced by: '<S10>/regen_switch'
                               */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S1>/Manual Switch'
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
  real_T odeY[2];
  real_T odeF[4][2];
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
 * '<S2>'   : 'tv_code/The Best TorqueVectoring/CarMaker_Inputs'
 * '<S3>'   : 'tv_code/The Best TorqueVectoring/PowerLimiter'
 * '<S4>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring2'
 * '<S5>'   : 'tv_code/The Best TorqueVectoring/PowerLimiter/Efficiency'
 * '<S6>'   : 'tv_code/The Best TorqueVectoring/PowerLimiter/P_mech'
 * '<S7>'   : 'tv_code/The Best TorqueVectoring/PowerLimiter/Subsystem'
 * '<S8>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter'
 * '<S9>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Reference generator'
 * '<S10>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Regenerative braking'
 * '<S11>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Speed estimaor'
 * '<S12>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Toque distibution NO Tv'
 * '<S13>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv'
 * '<S14>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Total Torque Request'
 * '<S15>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Upper Controller'
 * '<S16>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator'
 * '<S17>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/MATLAB Function'
 * '<S18>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/MATLAB Function1'
 * '<S19>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/MATLAB Function2'
 * '<S20>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/MATLAB Function3'
 * '<S21>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Regenerative braking/Subsystem'
 * '<S22>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Regenerative braking/Tmax'
 * '<S23>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/Fzfl'
 * '<S24>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/Fzfr'
 * '<S25>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/Fzrl'
 * '<S26>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/Fzrr'
 * '<S27>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/T_FL'
 * '<S28>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/T_FR'
 * '<S29>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/T_FR1'
 * '<S30>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/T_RL'
 */
#endif                                 /* RTW_HEADER_tv_code_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
