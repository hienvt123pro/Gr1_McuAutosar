/*
*   @file    Mcu.h
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

#ifndef MCU_H
#define MCU_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mcal.h"

#include "Mcu_Types.h"
#include "Mcu_Cfg.h"

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
* @brief          Initialization data for the MCU driver.
* @details        A pointer to such a structure is provided to the MCU initialization routines for
*                 configuration.
* @implements     Mcu_ConfigType_struct
*/
typedef struct
{
    /**< @brief Total number of RAM sections. */
    VAR(Mcu_RamSectionType, MCU_VAR) Mcu_NumRamConfigs;
    /**< @brief Total number of  MCU modes. */
    VAR(Mcu_ModeType, MCU_VAR) Mcu_NumModeConfigs;

#if (MCU_INIT_CLOCK == STD_ON)
    /**< @brief Total number of MCU clock configurations. */
    VAR(Mcu_ClockType, MCU_VAR) Mcu_NumClkConfigs;
#endif

    /**< @brief RAM data configuration. */
    CONST(Mcu_RamConfigType, MCU_CONST) (*Mcu_apRamConfig)[MCU_MAX_RAMCONFIGS];

    /**< @brief Power Modes data configuration. */
    CONST(Mcu_ModeConfigType, MCU_CONST) (*Mcu_apModeConfig)[MCU_MAX_MODECONFIGS];

#if (MCU_INIT_CLOCK == STD_ON)
    /**< @brief Clock data configuration. */
    CONST(Mcu_ClockConfigType, MCU_CONST) (*Mcu_apClockConfig)[MCU_MAX_CLKCONFIGS];
#endif

    /**< @brief Mcu Dependent Properties configuration. */
    P2CONST(Mcu_DepProsConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pDepProsConfig;

    /**< @brief Mcu Reset configuration. */
    P2CONST(Mcu_ResetConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pResetConfig;
} Mcu_ConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

MCU_CONF_PB

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

FUNC(void, MCU_CODE) Mcu_Init(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitRamSection(VAR(Mcu_RamSectionType, AUTOMATIC) RamSection);

#if (MCU_INIT_CLOCK == STD_ON)
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClock(VAR(Mcu_ClockType, AUTOMATIC) ClockSetting);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
FUNC(Std_ReturnType, MCU_CODE) Mcu_DistributePllClock(VAR(void, AUTOMATIC));
#endif /* (MCU_NO_PLL == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */

FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus(VAR( void, AUTOMATIC));


#ifdef __cplusplus
}
#endif

#endif /* MCU_H */

/** @} */
