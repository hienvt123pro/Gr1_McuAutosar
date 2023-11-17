/**
*   @file    Mcu_PMC.h
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from MC_PCU.
*   @details Public data types exported outside of the Mcu driver.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.3.1
*   Autosar Revision     : ASR_REL_4_3_REV_0001
*   Autosar Conf.Variant :
*   SW Version           : 1.0.4
*   Build Version        : S32K1XX_MCAL_1_0_4_RTM_ASR_REL_4_3_REV_0001_04-Apr-22
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc.
*       Copyright 2017-2022 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


#ifndef MCU_PMC_H
#define MCU_PMC_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mcu_Cfg.h"

#include "Reg_eSys_PMC.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/**
* @brief            Power Modes encoding.
* @details          Supported power modes for SMC hw IP.
*/
typedef enum
{
    MCU_RUN_MODE    = 0x00U,   /**< @brief Run Mode. */
    MCU_HSRUN_MODE  = 0x01U,   /**< @brief High Speed Mode. */
    MCU_VLPR_MODE   = 0x02U,   /**< @brief Very Low Power Run Mode. */
    MCU_VLPS_MODE   = 0x03U,   /**< @brief Very Low Power Stop Mode. */
    MCU_STOP1_MODE  = 0x04U,   /**< @brief Stop 1 Mode. */
    MCU_STOP2_MODE  = 0x05U,   /**< @brief Stop 2 Mode. */
} Mcu_PowerModeType;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief    PMC memory map
* @details  This structure contains information of PMC module's Registers
*
* @note
*
*/

typedef struct
{
    VAR(uint8, MCU_VAR)  u8LVDSC1;  /*Low Voltage Detect Status and Control 1 Register (LVDSC1)*/
    VAR(uint8, MCU_VAR)  u8LVDSC2;  /*Low voltage Detect Status and Control 2 Register (LVDSC2)*/
    VAR(uint8, MCU_VAR)  u8REGSC;   /*Regulator Status and Control Register (REGSC)*/
    VAR(uint8, MCU_VAR)  u8LPOTRIM; /*Low Power Oscillator Trim Register (LPOTRIM)*/
} Mcu_PMC_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#if (defined(MCU_DISABLE_PMC_INIT) && (STD_OFF == MCU_DISABLE_PMC_INIT))
FUNC(void, MCU_CODE) Mcu_PMC_Init(P2CONST(Mcu_PMC_ConfigType, AUTOMATIC, MCU_APPL_CONST) pPMCConfigPtr);
#endif


#ifdef __cplusplus
}
#endif

#endif /* MCU_PMC_H */

/** @} */
