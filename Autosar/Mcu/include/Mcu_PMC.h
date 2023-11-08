/**
*   @file    Mcu_PMC_Types.h
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
#include "Compiler.h"

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
/**
* @brief    PMC memory map
* @details  This structure contains information of PMC module's Registers
*
* @note
*
*/

typedef struct {

    VAR  (uint8, MCU_VAR)  LVDSC1;  /*Low Voltage Detect Status and Control 1 Register (LVDSC1)*/
    VAR  (uint8, MCU_VAR)  LVDSC2;  /*Low voltage Detect Status and Control 2 Register (LVDSC2)*/
    VAR  (uint8, MCU_VAR)  REGSC;   /*Regulator Status and Control Register (REGSC)*/
    VAR  (uint8, MCU_VAR)  LPOTRIM; /*Low Power Oscillator Trim Register (LPOTRIM)*/

} Mcu_PMC_ConfigType;


#ifdef __cplusplus
}
#endif

#endif /* MCU_PMC_H */
