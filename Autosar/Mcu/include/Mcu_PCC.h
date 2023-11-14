/*
*   @file    Mcu_PCC.h
*   @implements Mcu_PCC.h_Artifact
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

#ifndef MCU_PCC_H
#define MCU_PCC_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mcu_Cfg.h"

#include "Reg_eSys_PCC.h"

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
* @brief          Initialization data for the PCC driver.
* @details        A pointer to such a structure is provided to the routine to configure register base
*                 on pheripheral address and data configuration of register.
* @implements     Mcu_PCC_RegisterConfigType_struct
*/
typedef struct
{
    /**< @brief The address for PCC register. */
    VAR(uint32, MCU_VAR) u32PeripheralAdress;
    /**< @brief data configuration for PCC register. */
    VAR(uint32, MCU_VAR) u32PeripheralDataConfiguration;
} Mcu_PCC_RegisterConfigType;

/**
* @brief          Initialization data for the PCC driver.
* @details        A pointer to such a structure is provided to the Peripheral Clock Controller (PCC) settings initialization routines for
*                 configuration.
* @implements     Mcu_PCC_ConfigType_struct
*/
typedef struct
{
    /**< @brief Number of PCC configuration. */
    VAR(uint32, MCU_VAR) Mcu_NoPeripheralClockSetting;
    /**< @brief PCC register configuration. */
    CONST(Mcu_PCC_RegisterConfigType, MCU_CONST) (*pMcu_PCC_RegisterConfig)[MCU_NUMBER_OF_PCC_REGISTERS_U32];
} Mcu_PCC_ConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

FUNC(void, MCU_CODE) Mcu_PCC_Init(P2CONST(Mcu_PCC_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);


#ifdef __cplusplus
}
#endif

#endif /* MCU_PCC_H */

/** @} */
