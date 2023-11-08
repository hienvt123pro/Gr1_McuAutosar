/**
*   @file    Mcu_EXE.h
*   @implements Mcu_EXE.h_Artifact
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - Midle layer interface for Higher layer.
*   @details File contains function prototypes used by HLD only.
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

#ifndef MCU_INCLUDE_MCU_EXE_H_
#define MCU_INCLUDE_MCU_EXE_H_

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/

#include "Mcal.h"
#include "Mcu_Types.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

FUNC( void, MCU_CODE) Mcu_Exe_DepProsInit(P2CONST( Mcu_DepProsConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pDepProsConfigPtr);
FUNC( void, MCU_CODE) Mcu_Exe_ResetConfigInit(P2CONST( Mcu_ResetConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pResetConfigPtr);

#if (MCU_INIT_CLOCK == STD_ON)
FUNC( void, MCU_CODE) Mcu_Exe_InitClock(P2CONST( Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pClockConfigPtr);
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#ifdef __cplusplus
}
#endif

#endif /* MCU_INCLUDE_MCU_EXE_H_ */

/** @} */
