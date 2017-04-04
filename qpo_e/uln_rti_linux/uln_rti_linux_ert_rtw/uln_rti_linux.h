/*
 * File: uln_rti_linux.h
 *
 * Code generated for Simulink model 'uln_rti_linux'.
 *
 * Model version                  : 1.197
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Tue Apr 04 13:00:13 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_uln_rti_linux_h_
#define RTW_HEADER_uln_rti_linux_h_
#include <math.h>
#include <string.h>
#ifndef uln_rti_linux_COMMON_INCLUDES_
# define uln_rti_linux_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rqp.h"
#include "qpOASES_e.h"
#endif                                 /* uln_rti_linux_COMMON_INCLUDES_ */

#include "uln_rti_linux_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "qpOASES_e.h"

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T z_store_DSTATE[29];           /* '<Root>/z_store' */
} DW_uln_rti_linux_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: ULN_CONST_zInitial
   * Referenced by: '<Root>/z_store'
   */
  real_T z_store_InitialCondi[29];

  /* Expression: ULN_MODEL_p
   * Referenced by: '<Root>/Constant23'
   */
  real_T Constant23_Value[7];

  /* Expression: ULN_CONST_HESSIAN_COND
   * Referenced by: '<Root>/Constant12'
   */
  real_T Constant12_Value[841];

  /* Expression: ULN_CONST_vx
   * Referenced by: '<Root>/Constant13'
   */
  real_T Constant13_Value[696];

  /* Expression: ULN_CONST_vx1
   * Referenced by: '<Root>/Constant17'
   */
  real_T Constant17_Value[20];

  /* Expression: ULN_CONST_vu
   * Referenced by: '<Root>/Constant20'
   */
  real_T Constant20_Value[145];

  /* Expression: ULN_CONST_Qbar
   * Referenced by: '<Root>/Constant21'
   */
  real_T Constant21_Value[400];

  /* Expression: ULN_CONST_Rbar
   * Referenced by: '<Root>/Constant22'
   */
  real_T Constant22_Value[25];

  /* Expression: ULN_CONST_hBnx
   * Referenced by: '<Root>/Constant15'
   */
  real_T Constant15_Value[48];

  /* Expression: ULN_CONST_guA_prep
   * Referenced by: '<Root>/Constant4'
   */
  real_T Constant4_Value[20];

  /* Expression: ULN_CONST_vu_z
   * Referenced by: '<Root>/Constant7'
   */
  real_T Constant7_Value[5];

  /* Expression: ULN_CONST_vx_z
   * Referenced by: '<Root>/Constant8'
   */
  real_T Constant8_Value[20];
} ConstP_uln_rti_linux_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T x0[4];                        /* '<Root>/x0' */
} ExtU_uln_rti_linux_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T uOpt[5];                      /* '<Root>/uOpt' */
} ExtY_uln_rti_linux_T;

/* Real-time Model Data Structure */
struct tag_RTM_uln_rti_linux_T {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern DW_uln_rti_linux_T uln_rti_linux_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_uln_rti_linux_T uln_rti_linux_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_uln_rti_linux_T uln_rti_linux_Y;

/* Constant parameters (auto storage) */
extern const ConstP_uln_rti_linux_T uln_rti_linux_ConstP;

/* Model entry point functions */
extern void uln_rti_linux_initialize(void);
extern void uln_rti_linux_step(void);
extern void uln_rti_linux_terminate(void);

/* Real-time Model object */
extern RT_MODEL_uln_rti_linux_T *const uln_rti_linux_M;

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
 * '<Root>' : 'uln_rti_linux'
 * '<S1>'   : 'uln_rti_linux/RTI_expand'
 * '<S2>'   : 'uln_rti_linux/RTI_feedback'
 * '<S3>'   : 'uln_rti_linux/RTI_prepare'
 */
#endif                                 /* RTW_HEADER_uln_rti_linux_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
