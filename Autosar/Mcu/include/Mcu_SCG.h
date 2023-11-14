/*
*   @file    Mcu_SCG.h
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

#ifndef MCU_SCG_H
#define MCU_SCG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mcu_Cfg.h"

#include "Reg_eSys_SCG.h"

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
* @brief          Initialization data for the SCG driver.
* @details        A pointer to such a structure is provided to the routine to configure register base
*                 on pheripheral address and data configuration of register.
* @implements     Mcu_SCG_RegisterConfigType_struct
*/
typedef struct
{
    /**< @brief The address for SCG register. */
    VAR(uint32, MCU_VAR) u32PeripheralAdress;
    /**< @brief data configuration for SCG register. */
    VAR(uint32, MCU_VAR) u32PeripheralDataConfiguration;
} Mcu_SCG_RegisterConfigType;


/**
* @brief          Initialization data for the SCG driver.
* @details        A pointer to such a structure is provided to the routine to SOSC registers for configuring.
*
* @implements     Mcu_SCG_SOSC_RegisterConfigType_struct
*/
typedef struct
{
    /**< @brief The address for SCG register. */
    P2CONST(Mcu_SCG_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SOSCCSR_RegisterConfig;
    /**< @brief data configuration for SCG register. */
    P2CONST(Mcu_SCG_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SOSCDIV_RegisterConfig;
    /**< @brief data configuration for SCG register. */
    P2CONST(Mcu_SCG_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SOSCCFG_RegisterConfig;
} Mcu_SCG_SOSC_RegisterConfigType;


/**
* @brief          Initialization data for the SCG driver.
* @details        A pointer to such a structure is provided to the routine to SIRC registers for configuring.
*
* @implements     Mcu_SCG_SIRC_RegisterConfigType_struct
*/
typedef struct
{
    /**< @brief The address for SCG register. */
    P2CONST(Mcu_SCG_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIRCCSR_RegisterConfig;
    /**< @brief data configuration for SCG register. */
    P2CONST(Mcu_SCG_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIRCDIV_RegisterConfig;
    /**< @brief data configuration for SCG register. */
    P2CONST(Mcu_SCG_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIRCCFG_RegisterConfig;
} Mcu_SCG_SIRC_RegisterConfigType;


/**
* @brief          Initialization data for the SCG driver.
* @details        A pointer to such a structure is provided to the routine to FIRC registers for configuring.
*
* @implements     Mcu_SCG_FIRC_RegisterConfigType_struct
*/
typedef struct
{
    /**< @brief The address for SCG register. */
    P2CONST(Mcu_SCG_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_FIRCCSR_RegisterConfig;
    /**< @brief data configuration for SCG register. */
    P2CONST(Mcu_SCG_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_FIRCDIV_RegisterConfig;
    /**< @brief data configuration for SCG register. */
    P2CONST(Mcu_SCG_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_FIRCCFG_RegisterConfig;
} Mcu_SCG_FIRC_RegisterConfigType;


/**
* @brief          Initialization data for the SCG driver.
* @details        A pointer to such a structure is provided to the routine to SPLL registers for configuring
*
* @implements     Mcu_SCG_SPLL_RegisterConfigType_struct
*/
typedef struct
{
    /**< @brief The address for SCG register. */
    P2CONST(Mcu_SCG_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SPLLCSR_RegisterConfig;
    /**< @brief data configuration for SCG register. */
    P2CONST(Mcu_SCG_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SPLLDIV_RegisterConfig;
    /**< @brief data configuration for SCG register. */
    P2CONST(Mcu_SCG_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SPLLCFG_RegisterConfig;
} Mcu_SCG_SPLL_RegisterConfigType;


/**
* @brief          Initialization data for the SCG driver.
* @details        A pointer to such a structure is provided to the System Clock Generator (SCG) settings initialization routines for
*                 configuration.
* @implements     Mcu_SCG_ConfigType_struct
*/
typedef struct
{
    /**< @brief The variable for RUN mode configuration. (SCG_RCCR register) */
    /**< @brief Contain the selection of system clock source. */
    /**< @brief Contain the value of Core clock divide ratio, Bus clock divide ratio, Slow clock divide ratio. */
    VAR(uint32, MCU_VAR) Mcu_RUNModeConfig;

    /**< @brief The variable for HSRUN mode configuration. (SCG_HCCR register)*/
    /**< @brief Contain the selection of system clock source. */
    /**< @brief Contain the value of Core clock divide ratio, Bus clock divide ratio, Slow clock divide ratio. */
    VAR(uint32, MCU_VAR) Mcu_HSRUNModeConfig;

    /**< @brief The variable for VLPR mode configuration. (SCG_VCCR register)*/
    /**< @brief Contain the selection of system clock source. */
    /**< @brief Contain the value of Core clock divide ratio, Bus clock divide ratio, Slow clock divide ratio. */
    VAR(uint32, MCU_VAR) Mcu_VLPRModeConfig;

    /**< @brief The variable for clock out configuration. (SCG_CLKOUTCNFG)*/
    VAR(uint32, MCU_VAR) Mcu_ClockOutSelection;

    /**< @brief The pointer to structure configuring SOSC registers. (SCG_SOSCCSR, SCG_SOSCDIV, SCG_SOSCCFG)*/
    P2CONST(Mcu_SCG_SOSC_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SOSC_RegisterConfig;

    /**< @brief The pointer to structure configuring SIRC registers. (SCG_SIRCCSR, SCG_SIRCDIV, SCG_SIRCCFG)*/
    P2CONST(Mcu_SCG_SIRC_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIRC_RegisterConfig;

    /**< @brief The pointer to structure configuring FIRC registers. (SCG_SOSCCSR, SCG_SOSCDIV, SCG_SOSCCFG)*/
    P2CONST(Mcu_SCG_FIRC_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_FIRC_RegisterConfig;

    /**< @brief The pointer to structure configuring SPLL registers. (SCG_SIRCCSR, SCG_SIRCDIV, SCG_SIRCCFG)*/
    P2CONST(Mcu_SCG_SPLL_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SPLL_RegisterConfig;
} Mcu_SCG_ConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

FUNC(void, MCU_CODE) Mcu_SCG_SOSCInit(P2CONST(Mcu_SCG_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
FUNC(void, MCU_CODE) Mcu_SCG_SPLLInit(P2CONST(Mcu_SCG_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
FUNC(void, MCU_CODE) Mcu_SCG_SIRCInit(P2CONST(Mcu_SCG_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
FUNC(void, MCU_CODE) Mcu_SCG_FIRCInit(P2CONST(Mcu_SCG_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
FUNC(void, MCU_CODE) Mcu_SCG_SrcClock(P2CONST(Mcu_SCG_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr, VAR(uint8, MCU_VAR) u8ClockSourcesControl);
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_SCG_GetPLLStatus(VAR(void, AUTOMATIC));
#ifdef __cplusplus
}
#endif

#endif /* MCU_H */

/** @} */
