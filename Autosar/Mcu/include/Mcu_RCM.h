/*
*   @file    Mcu_RCM.h
*   @implements Mcu.h_Artifact
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - Driver external interface.
*   @details Contains all the public functions and data types that are used by the higher layer.
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

#ifndef MCU_RCM_H
#define MCU_RCM_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mcu_Cfg.h"

#include "Reg_eSys_RCM.h"

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
* @brief          Initialization data for the RCM driver.
* @details        A pointer to such a structure is provided to the routine to configure register base
*                 on pheripheral address and data configuration of register.
* @implements     Mcu_RCM_RegisterConfigType_struct
*/
typedef struct
{
    /**< @brief The address for R register. */
    VAR(uint32, MCU_VAR) u32PeripheralAdress;
    /**< @brief data configuration for R register. */
    VAR(uint32, MCU_VAR) u32PeripheralDataConfiguration;
} Mcu_RCM_RegisterConfigType;

/**
* @brief          Initialization data for the RCM driver.
* @details        A pointer to such a structure is provided to the routine to RCM_RPC registers for configuring.
*
* @implements     Mcu_RCM_ResetPinControlConfigType_struct
*/
typedef struct
{
    /**< @brief RCM_CHIPCTL register configuration. */
    P2CONST(Mcu_RCM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_RCM_ResetPinControlRegisterConfig;
} Mcu_RCM_ResetPinControlConfigType;

/**
* @brief          Initialization data for the RCM driver.
* @details        A pointer to such a structure is provided to the routine to RCM_SRIE registers for configuring.
*
* @implements     Mcu_RCM_ResetInterruptEnableConfigType_struct
*/
typedef struct
{
    /**< @brief RCM_CHIPCTL register configuration. */
    P2CONST(Mcu_RCM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_RCM_ResetInterruptEnableRegisterConfig;
} Mcu_RCM_ResetInterruptEnableConfigType;

/**
* @brief          Initialization data for the RCM driver.
* @details        A pointer to such a structure is provided to the Reset Control Module (RCM) which relating to reset
*                 functions of the chip.
* @implements     Mcu_RCM_ConfigType_struct
*/
typedef struct
{
    /**< @brief RCM chip selection configuration. */
    P2CONST(Mcu_RCM_ResetPinControlConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_RCM_ResetPinControlConfig;
    /**< @brief RCM system clock divider register 4. */
    P2CONST(Mcu_RCM_ResetInterruptEnableConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_RCM_ResetInterruptEnableConfig;
} Mcu_RCM_ConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

FUNC(void, MCU_CODE) Mcu_RCM_Init(P2CONST(Mcu_RCM_ConfigType, AUTOMATIC, MCU_APPL_CONST) pRCMConfigPtr);


#ifdef __cplusplus
}
#endif

#endif /* MCU_RCM_H */

/** @} */
