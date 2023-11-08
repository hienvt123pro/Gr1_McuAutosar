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

#ifndef MCU_SIM_H
#define MCU_SIM_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mcal.h"

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
* @implements     Mcu_SIM_RegisterConfigType_struct
*/
typedef struct
{
    /**< @brief The address for SIM register. */
    VAR( uint32, MCU_VAR) u32PeripheralAdress;

    /**< @brief data configuration for SIM register. */
    VAR(uint32, MCU_VAR) u32PeripheralDataConfiguration;

} Mcu_SIM_RegisterConfigType;


/**
* @brief          Initialization data for the SIM driver.
* @details        A pointer to such a structure is provided to the routine to SIM_CHIPCTL registers for configuring.
*                
* @implements     Mcu_SIM_ChipSelectionConfigType_struct
*/
typedef struct
{
    /**< @brief SIM_CHIPCTL register configuration. */
    P2CONST(Mcu_SIM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_ChipSelectionRegisterConfig;

} Mcu_SIM_ChipSelectionConfigType;

/**
* @brief          Initialization data for the PCC driver.
* @details        A pointer to such a structure is provided to the routine to SIM_CLKDIV4 registers for configuring.
*                
* @implements     Mcu_SIM_TraceClockConfigType_struct
*/
typedef struct
{
    /**< @brief SIM_CLKDIV4 register configuration. */
    P2CONST(Mcu_SIM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_TraceClockRegisterConfig;

} Mcu_SIM_TraceClockConfigType;


/**
* @brief          Initialization data for the PCC driver.
* @details        A pointer to such a structure is provided to the routine to SIM_PLATCGC registers for configuring.
*                 
* @implements     Mcu_SIM_ClockGatingConfigType_struct
*/
typedef struct
{
    /**< @brief SIM_PLATCGC register configuration. */
    P2CONST(Mcu_SIM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_ClockGatingRegisterConfig;

} Mcu_SIM_ClockGatingConfigType;


/**
* @brief          Initialization data for the PCC driver.
* @details        A pointer to such a structure is provided to the System Intergrate Module (SIM) which relating to clock
*                 configuration.
* @implements     Mcu_SIM_ClockConfigType_struct
*/
typedef struct
{

    /**< @brief SCG chip selection configuration. */
    P2CONST(Mcu_SIM_ChipSelectionConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SCG_ChipSelectionConfig;

    /**< @brief SCG system clock divider register 4. */
    P2CONST(Mcu_SIM_TraceClockConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SCG_TraceClockConfig;

    /**< @brief SIM platform clock gating control register. */
    P2CONST(Mcu_SIM_ClockGatingConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SCG_ClockGatingConfig;

} Mcu_SIM_ClockConfigType;


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif /* MCU_H */

/** @} */
