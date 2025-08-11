/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code.h
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
  real_T Product1;                     /* '<S10>/Product1' */
  real_T Saturation[4];                /* '<S8>/Saturation' */
  real_T Gain1;                        /* '<S7>/Gain1' */
  real_T Switch;                       /* '<S6>/Switch' */
  real_T Switch_b;                     /* '<S9>/Switch' */
  real_T Gain1_k;                      /* '<S32>/Gain1' */
  real_T DotProduct;                   /* '<S11>/Dot Product' */
  real_T Sum1;                         /* '<S11>/Sum1' */
  real_T Switch1;                      /* '<S6>/Switch1' */
  real_T DotProduct_n;                 /* '<S9>/Dot Product' */
  real_T Gain1_j;                      /* '<S33>/Gain1' */
  real_T DotProduct1;                  /* '<S9>/Dot Product1' */
  real_T Gain1_d;                      /* '<S35>/Gain1' */
  real_T DotProduct2;                  /* '<S9>/Dot Product2' */
  real_T Gain1_m;                      /* '<S34>/Gain1' */
  real_T DotProduct3;                  /* '<S9>/Dot Product3' */
  real_T Saturation_c;                 /* '<S12>/Saturation' */
  real_T Ceil;                         /* '<S12>/Ceil' */
  real_T Saturation1;                  /* '<S12>/Saturation1' */
  real_T Ceil1;                        /* '<S12>/Ceil1' */
  real_T Saturation2;                  /* '<S12>/Saturation2' */
  real_T Ceil2;                        /* '<S12>/Ceil2' */
  real_T Saturation3;                  /* '<S12>/Saturation3' */
  real_T Ceil3;                        /* '<S12>/Ceil3' */
  real_T PowerError;                   /* '<S4>/Saturation' */
  real_T Max;                          /* '<S4>/Max' */
  real_T Torquefixed;                  /* '<S4>/Sum' */
  real_T Gain1_e;                      /* '<S22>/Gain1' */
  real_T Gain1_n;                      /* '<S23>/Gain1' */
  real_T Gain1_ew;                     /* '<S25>/Gain1' */
  real_T Gain1_me;                     /* '<S24>/Gain1' */
  real_T trq_fl;                       /* '<Root>/trq_fl' */
  real_T trq_fr;                       /* '<Root>/trq_fr' */
  real_T trq_rl;                       /* '<Root>/trq_rl' */
  real_T trq_rr;                       /* '<Root>/trq_rr' */
  real_T torque_fixed;                 /* '<S4>/torque_fixed' */
  real_T est_power;                    /* '<S4>/est_power' */
  real_T URR;                          /* '<S12>/URR' */
  real_T IRR;                          /* '<S12>/IRR' */
  real_T URL;                          /* '<S12>/URL' */
  real_T IRL;                          /* '<S12>/IRL' */
  real_T UFR;                          /* '<S12>/UFR' */
  real_T IFR;                          /* '<S12>/IFR' */
  real_T UFL;                          /* '<S12>/UFL' */
  real_T IFL;                          /* '<S12>/IFL' */
  real_T DotProduct1_a;                /* '<S11>/Dot Product1' */
  real_T yaw_ref;                      /* '<S5>/yaw_ref' */
  real_T power_limiter_switch[4];      /* '<S3>/power_limiter_switch' */
  real_T DotProduct_o;                 /* '<S17>/Dot Product' */
  real_T DotProduct1_p;                /* '<S17>/Dot Product1' */
  real_T DotProduct2_l;                /* '<S17>/Dot Product2' */
  real_T DotProduct3_d;                /* '<S17>/Dot Product3' */
  real_T regen_switch;                 /* '<S6>/regen_switch' */
  real_T Gain1_m3;                     /* '<S6>/Gain1' */
  real_T Gain;                         /* '<S6>/Gain' */
  real_T Gain1_nz[4];                  /* '<S12>/Gain1' */
  real_T uDLookupTable;                /* '<S12>/2-D Lookup Table' */
  real_T uDLookupTable1;               /* '<S12>/2-D Lookup Table1' */
  real_T uDLookupTable2;               /* '<S12>/2-D Lookup Table2' */
  real_T uDLookupTable3;               /* '<S12>/2-D Lookup Table3' */
  real_T speed_switch[4];              /* '<S3>/speed_switch' */
  real_T Switch_f;                     /* '<S17>/Switch' */
  real_T DotProduct_l;                 /* '<S27>/Dot Product' */
  real_T nDLookupTable2;               /* '<S12>/n-D Lookup Table2' */
  real_T Gain11;                       /* '<S12>/Gain11' */
  real_T nDLookupTable3;               /* '<S12>/n-D Lookup Table3' */
  real_T nDLookupTable4;               /* '<S12>/n-D Lookup Table4' */
  real_T div2;                         /* '<S27>/div2' */
  real_T P_est;                        /* '<S12>/Sum' */
  real_T ki;                           /* '<S4>/ki' */
  real_T Saturation_j;                 /* '<S5>/Saturation' */
  real_T Gain1_jz;                     /* '<S26>/Gain1' */
  real_T Max_a;                        /* '<S6>/Max' */
  real_T Gain2;                        /* '<S21>/Gain2' */
  real_T Sum2;                         /* '<S4>/Sum2' */
  real_T Sum;                          /* '<S11>/Sum' */
  real_T Saturation3_c;                /* '<S17>/Saturation3' */
  real_T nDLookupTable1;               /* '<S12>/n-D Lookup Table1' */
  real_T Gain_l;                       /* '<S21>/Gain' */
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
  real_T Integrator_CSTATE;            /* '<S11>/Integrator' */
} X_tv_code_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S11>/Integrator' */
} XDot_tv_code_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S11>/Integrator' */
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
                                        * Referenced by: '<S5>/Desired Understeer Gradient'
                                        */
  real_T L;                            /* Variable: L
                                        * Referenced by:
                                        *   '<S5>/axlebase'
                                        *   '<S26>/Z1'
                                        *   '<S26>/Z2'
                                        *   '<S28>/Gain'
                                        *   '<S29>/Gain'
                                        *   '<S30>/Gain'
                                        *   '<S31>/Gain'
                                        *   '<S18>/Gain'
                                        *   '<S19>/Gain'
                                        *   '<S20>/Gain'
                                        *   '<S21>/Gain'
                                        */
  real_T Mz_I;                         /* Variable: Mz_I
                                        * Referenced by: '<S2>/Mz Integative Gain'
                                        */
  real_T Mz_p;                         /* Variable: Mz_p
                                        * Referenced by: '<S2>/Mz Proportional Gain'
                                        */
  real_T P_max;                        /* Variable: P_max
                                        * Referenced by: '<S4>/Max_power'
                                        */
  real_T drive_ratio;                  /* Variable: drive_ratio
                                        * Referenced by:
                                        *   '<S9>/Saturation'
                                        *   '<S9>/Saturation1'
                                        *   '<S9>/Saturation2'
                                        *   '<S9>/Saturation3'
                                        *   '<S10>/Constant1'
                                        *   '<S26>/Gain'
                                        *   '<S26>/Gain1'
                                        *   '<S17>/Saturation'
                                        *   '<S17>/Saturation1'
                                        *   '<S17>/Saturation2'
                                        *   '<S17>/Saturation3'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by:
                                        *   '<S26>/Z1'
                                        *   '<S26>/Z2'
                                        *   '<S28>/Constant'
                                        *   '<S29>/Constant'
                                        *   '<S30>/Constant'
                                        *   '<S31>/Constant'
                                        *   '<S32>/Gain1'
                                        *   '<S33>/Gain1'
                                        *   '<S34>/Gain1'
                                        *   '<S35>/Gain1'
                                        *   '<S18>/Constant'
                                        *   '<S19>/Constant'
                                        *   '<S20>/Constant'
                                        *   '<S21>/Constant'
                                        *   '<S22>/Gain1'
                                        *   '<S23>/Gain1'
                                        *   '<S24>/Gain1'
                                        *   '<S25>/Gain1'
                                        */
  real_T h;                            /* Variable: h
                                        * Referenced by:
                                        *   '<S28>/Gain1'
                                        *   '<S28>/Gain2'
                                        *   '<S29>/Gain1'
                                        *   '<S29>/Gain2'
                                        *   '<S30>/Gain1'
                                        *   '<S30>/Gain2'
                                        *   '<S31>/Gain1'
                                        *   '<S31>/Gain2'
                                        *   '<S18>/Gain1'
                                        *   '<S18>/Gain2'
                                        *   '<S19>/Gain1'
                                        *   '<S19>/Gain2'
                                        *   '<S20>/Gain1'
                                        *   '<S20>/Gain2'
                                        *   '<S21>/Gain1'
                                        *   '<S21>/Gain2'
                                        */
  real_T lf;                           /* Variable: lf
                                        * Referenced by:
                                        *   '<S26>/Z1'
                                        *   '<S30>/Constant'
                                        *   '<S30>/Gain2'
                                        *   '<S31>/Constant'
                                        *   '<S31>/Gain2'
                                        *   '<S20>/Constant'
                                        *   '<S20>/Gain2'
                                        *   '<S21>/Constant'
                                        *   '<S21>/Gain2'
                                        */
  real_T lr;                           /* Variable: lr
                                        * Referenced by:
                                        *   '<S26>/Z2'
                                        *   '<S28>/Constant'
                                        *   '<S28>/Gain2'
                                        *   '<S29>/Constant'
                                        *   '<S29>/Gain2'
                                        *   '<S18>/Constant'
                                        *   '<S18>/Gain2'
                                        *   '<S19>/Constant'
                                        *   '<S19>/Gain2'
                                        */
  real_T ls;                           /* Variable: ls
                                        * Referenced by:
                                        *   '<S28>/Gain2'
                                        *   '<S29>/Gain2'
                                        *   '<S30>/Gain2'
                                        *   '<S31>/Gain2'
                                        *   '<S32>/Gain'
                                        *   '<S33>/Gain'
                                        *   '<S34>/Gain'
                                        *   '<S35>/Gain'
                                        *   '<S18>/Gain2'
                                        *   '<S19>/Gain2'
                                        *   '<S20>/Gain2'
                                        *   '<S21>/Gain2'
                                        *   '<S22>/Gain'
                                        *   '<S23>/Gain'
                                        *   '<S24>/Gain'
                                        *   '<S25>/Gain'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by:
                                        *   '<S26>/Z1'
                                        *   '<S26>/Z2'
                                        *   '<S28>/Gain'
                                        *   '<S29>/Gain'
                                        *   '<S30>/Gain'
                                        *   '<S31>/Gain'
                                        *   '<S32>/Gain1'
                                        *   '<S33>/Gain1'
                                        *   '<S34>/Gain1'
                                        *   '<S35>/Gain1'
                                        *   '<S18>/Gain'
                                        *   '<S19>/Gain'
                                        *   '<S20>/Gain'
                                        *   '<S21>/Gain'
                                        *   '<S22>/Gain1'
                                        *   '<S23>/Gain1'
                                        *   '<S24>/Gain1'
                                        *   '<S25>/Gain1'
                                        */
  real_T max_moment;                   /* Variable: max_moment
                                        * Referenced by:
                                        *   '<S9>/Saturation'
                                        *   '<S9>/Saturation1'
                                        *   '<S9>/Saturation2'
                                        *   '<S9>/Saturation3'
                                        *   '<S10>/Constant1'
                                        *   '<S17>/Saturation'
                                        *   '<S17>/Saturation1'
                                        *   '<S17>/Saturation2'
                                        *   '<S17>/Saturation3'
                                        */
  real_T mu;                           /* Variable: mu
                                        * Referenced by:
                                        *   '<S26>/X1'
                                        *   '<S26>/X2'
                                        */
  real_T rw;                           /* Variable: rw
                                        * Referenced by:
                                        *   '<S7>/Gain1'
                                        *   '<S26>/Ta'
                                        *   '<S26>/Tr'
                                        *   '<S32>/Gain'
                                        *   '<S33>/Gain'
                                        *   '<S34>/Gain'
                                        *   '<S35>/Gain'
                                        *   '<S22>/Gain'
                                        *   '<S23>/Gain'
                                        *   '<S24>/Gain'
                                        *   '<S25>/Gain'
                                        */
  real_T stator_current_line_rms[4221];/* Variable: stator_current_line_rms
                                        * Referenced by:
                                        *   '<S12>/n-D Lookup Table1'
                                        *   '<S12>/n-D Lookup Table2'
                                        *   '<S12>/n-D Lookup Table3'
                                        *   '<S12>/n-D Lookup Table4'
                                        */
  real_T torque_map[4221];             /* Variable: torque_map
                                        * Referenced by:
                                        *   '<S12>/Constant2'
                                        *   '<S12>/Constant3'
                                        *   '<S12>/Constant5'
                                        *   '<S12>/Constant7'
                                        */
  real_T voltage_map[4221];            /* Variable: voltage_map
                                        * Referenced by:
                                        *   '<S12>/2-D Lookup Table'
                                        *   '<S12>/2-D Lookup Table1'
                                        *   '<S12>/2-D Lookup Table2'
                                        *   '<S12>/2-D Lookup Table3'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T TT_max_Value;                 /* Expression: 50
                                        * Referenced by: '<S6>/TT_max'
                                        */
  real_T Vdc_Value;                    /* Expression: 550
                                        * Referenced by: '<S27>/Vdc'
                                        */
  real_T I_max_Value;                  /* Expression: 15
                                        * Referenced by: '<S27>/I_max'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 0.95
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
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
  real_T Gain1_Gain_m;                 /* Expression: 60/(2*pi)
                                        * Referenced by: '<S12>/Gain1'
                                        */
  real_T acc_pedal_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/acc_pedal'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 1/4
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 1/4
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
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
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0.3
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 6
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -6
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S11>/Integrator'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S6>/Switch1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 20000
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: 0
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Rowindex_tableData[201];      /* Expression: 0:1:200
                                        * Referenced by: '<S12>/Row index'
                                        */
  real_T Rowindex_bp01Data[201];       /* Computed Parameter: Rowindex_bp01Data
                                        * Referenced by: '<S12>/Row index'
                                        */
  real_T Saturation7_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S12>/Saturation7'
                                        */
  real_T Saturation7_LowerSat;         /* Expression: 1
                                        * Referenced by: '<S12>/Saturation7'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T nDLookupTable1_bp01Data[201]; /* Expression: 0:1:200
                                        * Referenced by: '<S12>/n-D Lookup Table1'
                                        */
  real_T nDLookupTable1_bp02Data[21];  /* Expression: 0:1:20
                                        * Referenced by: '<S12>/n-D Lookup Table1'
                                        */
  real_T uDLookupTable_bp01Data[201];
                                   /* Computed Parameter: uDLookupTable_bp01Data
                                    * Referenced by: '<S12>/2-D Lookup Table'
                                    */
  real_T uDLookupTable_bp02Data[21];
                                 /* Expression: stator_current_line_rms(1,1:end)
                                  * Referenced by: '<S12>/2-D Lookup Table'
                                  */
  real_T Gain10_Gain;                  /* Expression: sqrt(3)
                                        * Referenced by: '<S12>/Gain10'
                                        */
  real_T Saturation1_UpperSat_n;       /* Expression: 20000
                                        * Referenced by: '<S12>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: 0
                                        * Referenced by: '<S12>/Saturation1'
                                        */
  real_T Rowindex1_tableData[201];     /* Expression: 0:1:200
                                        * Referenced by: '<S12>/Row index1'
                                        */
  real_T Rowindex1_bp01Data[201];      /* Computed Parameter: Rowindex1_bp01Data
                                        * Referenced by: '<S12>/Row index1'
                                        */
  real_T Saturation6_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S12>/Saturation6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: 1
                                        * Referenced by: '<S12>/Saturation6'
                                        */
  real_T Constant1_Value_p;            /* Expression: 1
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T nDLookupTable2_bp01Data[201]; /* Expression: 0:1:200
                                        * Referenced by: '<S12>/n-D Lookup Table2'
                                        */
  real_T nDLookupTable2_bp02Data[21];  /* Expression: 0:1:20
                                        * Referenced by: '<S12>/n-D Lookup Table2'
                                        */
  real_T uDLookupTable1_bp01Data[201];
                                  /* Computed Parameter: uDLookupTable1_bp01Data
                                   * Referenced by: '<S12>/2-D Lookup Table1'
                                   */
  real_T uDLookupTable1_bp02Data[21];
                                 /* Expression: stator_current_line_rms(1,1:end)
                                  * Referenced by: '<S12>/2-D Lookup Table1'
                                  */
  real_T Gain11_Gain;                  /* Expression: sqrt(3)
                                        * Referenced by: '<S12>/Gain11'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 20000
                                        * Referenced by: '<S12>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S12>/Saturation2'
                                        */
  real_T Rowindex2_tableData[201];     /* Expression: 0:1:200
                                        * Referenced by: '<S12>/Row index2'
                                        */
  real_T Rowindex2_bp01Data[201];      /* Computed Parameter: Rowindex2_bp01Data
                                        * Referenced by: '<S12>/Row index2'
                                        */
  real_T Saturation5_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S12>/Saturation5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: 1
                                        * Referenced by: '<S12>/Saturation5'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S12>/Constant4'
                                        */
  real_T nDLookupTable3_bp01Data[201]; /* Expression: 0:1:200
                                        * Referenced by: '<S12>/n-D Lookup Table3'
                                        */
  real_T nDLookupTable3_bp02Data[21];  /* Expression: 0:1:20
                                        * Referenced by: '<S12>/n-D Lookup Table3'
                                        */
  real_T uDLookupTable2_bp01Data[201];
                                  /* Computed Parameter: uDLookupTable2_bp01Data
                                   * Referenced by: '<S12>/2-D Lookup Table2'
                                   */
  real_T uDLookupTable2_bp02Data[21];
                                 /* Expression: stator_current_line_rms(1,1:end)
                                  * Referenced by: '<S12>/2-D Lookup Table2'
                                  */
  real_T Gain12_Gain;                  /* Expression: sqrt(3)
                                        * Referenced by: '<S12>/Gain12'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 20000
                                        * Referenced by: '<S12>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S12>/Saturation3'
                                        */
  real_T Rowindex3_tableData[201];     /* Expression: 0:1:200
                                        * Referenced by: '<S12>/Row index3'
                                        */
  real_T Rowindex3_bp01Data[201];      /* Computed Parameter: Rowindex3_bp01Data
                                        * Referenced by: '<S12>/Row index3'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S12>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: 1
                                        * Referenced by: '<S12>/Saturation4'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<S12>/Constant6'
                                        */
  real_T nDLookupTable4_bp01Data[201]; /* Expression: 0:1:200
                                        * Referenced by: '<S12>/n-D Lookup Table4'
                                        */
  real_T nDLookupTable4_bp02Data[21];  /* Expression: 0:1:20
                                        * Referenced by: '<S12>/n-D Lookup Table4'
                                        */
  real_T uDLookupTable3_bp01Data[201];
                                  /* Computed Parameter: uDLookupTable3_bp01Data
                                   * Referenced by: '<S12>/2-D Lookup Table3'
                                   */
  real_T uDLookupTable3_bp02Data[21];
                                 /* Expression: stator_current_line_rms(1,1:end)
                                  * Referenced by: '<S12>/2-D Lookup Table3'
                                  */
  real_T Gain13_Gain;                  /* Expression: sqrt(3)
                                        * Referenced by: '<S12>/Gain13'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: inf
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: 0
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T kp_Gain;                      /* Expression: 2
                                        * Referenced by: '<S4>/kp'
                                        */
  real_T ki_Gain;                      /* Expression: 2
                                        * Referenced by: '<S4>/ki'
                                        */
  real_T speed_switch_Threshold;       /* Expression: 2
                                        * Referenced by: '<S3>/speed_switch'
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
  real_T torque_fixed_Gain;            /* Expression: 1
                                        * Referenced by: '<S4>/torque_fixed'
                                        */
  real_T est_power_Gain;               /* Expression: 1
                                        * Referenced by: '<S4>/est_power'
                                        */
  real_T URR_Gain;                     /* Expression: 1
                                        * Referenced by: '<S12>/URR'
                                        */
  real_T IRR_Gain;                     /* Expression: 1
                                        * Referenced by: '<S12>/IRR'
                                        */
  real_T URL_Gain;                     /* Expression: 1
                                        * Referenced by: '<S12>/URL'
                                        */
  real_T IRL_Gain;                     /* Expression: 1
                                        * Referenced by: '<S12>/IRL'
                                        */
  real_T UFR_Gain;                     /* Expression: 1
                                        * Referenced by: '<S12>/UFR'
                                        */
  real_T IFR_Gain;                     /* Expression: 1
                                        * Referenced by: '<S12>/IFR'
                                        */
  real_T UFL_Gain;                     /* Expression: 1
                                        * Referenced by: '<S12>/UFL'
                                        */
  real_T IFL_Gain;                     /* Expression: 1
                                        * Referenced by: '<S12>/IFL'
                                        */
  real_T yaw_ref_Gain;                 /* Expression: 1
                                        * Referenced by: '<S5>/yaw_ref'
                                        */
  uint32_T nDLookupTable1_maxIndex[2];
                                  /* Computed Parameter: nDLookupTable1_maxIndex
                                   * Referenced by: '<S12>/n-D Lookup Table1'
                                   */
  uint32_T uDLookupTable_maxIndex[2];
                                   /* Computed Parameter: uDLookupTable_maxIndex
                                    * Referenced by: '<S12>/2-D Lookup Table'
                                    */
  uint32_T nDLookupTable2_maxIndex[2];
                                  /* Computed Parameter: nDLookupTable2_maxIndex
                                   * Referenced by: '<S12>/n-D Lookup Table2'
                                   */
  uint32_T uDLookupTable1_maxIndex[2];
                                  /* Computed Parameter: uDLookupTable1_maxIndex
                                   * Referenced by: '<S12>/2-D Lookup Table1'
                                   */
  uint32_T nDLookupTable3_maxIndex[2];
                                  /* Computed Parameter: nDLookupTable3_maxIndex
                                   * Referenced by: '<S12>/n-D Lookup Table3'
                                   */
  uint32_T uDLookupTable2_maxIndex[2];
                                  /* Computed Parameter: uDLookupTable2_maxIndex
                                   * Referenced by: '<S12>/2-D Lookup Table2'
                                   */
  uint32_T nDLookupTable4_maxIndex[2];
                                  /* Computed Parameter: nDLookupTable4_maxIndex
                                   * Referenced by: '<S12>/n-D Lookup Table4'
                                   */
  uint32_T uDLookupTable3_maxIndex[2];
                                  /* Computed Parameter: uDLookupTable3_maxIndex
                                   * Referenced by: '<S12>/2-D Lookup Table3'
                                   */
  uint8_T regen_switch_CurrentSetting;
                              /* Computed Parameter: regen_switch_CurrentSetting
                               * Referenced by: '<S6>/regen_switch'
                               */
  uint8_T power_limiter_switch_CurrentSet;
                          /* Computed Parameter: power_limiter_switch_CurrentSet
                           * Referenced by: '<S3>/power_limiter_switch'
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
 * '<S2>'   : 'tv_code/The Best TorqueVectoring/CarMaker_Inputs'
 * '<S3>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring2'
 * '<S4>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter'
 * '<S5>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Reference generator'
 * '<S6>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Regenerative braking'
 * '<S7>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Speed estimaor'
 * '<S8>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Toque distibution NO Tv'
 * '<S9>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv'
 * '<S10>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Total Torque Request'
 * '<S11>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Upper Controller'
 * '<S12>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator'
 * '<S13>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/MATLAB Function'
 * '<S14>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/MATLAB Function1'
 * '<S15>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/MATLAB Function2'
 * '<S16>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/MATLAB Function3'
 * '<S17>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/Torque distribution Tv'
 * '<S18>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/Torque distribution Tv/Fzfl'
 * '<S19>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/Torque distribution Tv/Fzfr'
 * '<S20>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/Torque distribution Tv/Fzrl'
 * '<S21>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/Torque distribution Tv/Fzrr'
 * '<S22>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/Torque distribution Tv/T_FL'
 * '<S23>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/Torque distribution Tv/T_FR'
 * '<S24>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/Torque distribution Tv/T_FR1'
 * '<S25>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Power Limiter/Power estimator/Torque distribution Tv/T_RL'
 * '<S26>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Regenerative braking/Subsystem'
 * '<S27>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Regenerative braking/Tmax'
 * '<S28>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/Fzfl'
 * '<S29>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/Fzfr'
 * '<S30>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/Fzrl'
 * '<S31>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/Fzrr'
 * '<S32>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/T_FL'
 * '<S33>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/T_FR'
 * '<S34>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/T_FR1'
 * '<S35>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring2/Torque distribution Tv/T_RL'
 */
#endif                                 /* RTW_HEADER_tv_code_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
