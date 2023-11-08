/**
*   @file    Mcu_SMC_Types.h
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from IPV_SMC.
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


#ifndef MCU_SMC_H
#define MCU_SMC_H


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
* @brief    SMC memory map
* @details  This structure contains information of SMC module's Registers
*
* @note
*
*/

typedef struct {

    CONST   (uint32, MCU_CONST) SMC_VERID;      /*SMC Version ID Register (SMC_VERID)*/
    CONST   (uint32, MCU_CONST) SMC_PARAM;      /*SMC Parameter Register (SMC_PARAM)*/
    VAR     (uint32, MCU_VAR)   SMC_PMPROT;     /*Power Mode Protection register (SMC_PMPROT)*/
    VAR     (uint32, MCU_VAR)   SMC_PMCTRL;     /*Power Mode Control register (SMC_PMCTRL)*/
    VAR     (uint32, MCU_VAR)   SMC_STOPCTRL;   /*Stop Control Register (SMC_STOPCTRL)*/
    CONST   (uint32, MCU_CONST) SMC_PMSTAT;     /*Power Mode Status register (SMC_PMSTAT)*/

} Mcu_SMC_ConfigType;


#ifdef __cplusplus
}
#endif

#endif /* MCU_SMC_TYPES_H*/
