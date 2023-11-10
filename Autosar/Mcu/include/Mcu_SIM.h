/*
*   @file    Mcu_SIM.h
*   @implements Mcu_SIM.h_Artifact
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
#include "Mcu_Cfg.h"

#include "Reg_eSys_SIM.h"
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
* @brief          Initialization data for the SIM driver.
* @details        A pointer to such a structure is provided to the routine to configure register base
*                 on pheripheral address and data configuration of register.
* @implements     Mcu_SIM_RegisterConfigType_struct
*/
typedef struct
{
    /**< @brief The address for SIM register. */
    VAR(uint32, MCU_VAR) u32PeripheralAdress;
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
* @brief          Initialization data for the SIM driver.
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
* @brief          Initialization data for the SIM driver.
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
* @brief          Initialization data for the SIM driver.
* @details        A pointer to such a structure is provided to the routine to SIM_CHIPCTL registers for configuring.
*
* @implements     Mcu_SIM_ChipControlConfigType_struct
*/
typedef struct
{
    /**< @brief SIM_CHIPCTL register configuration. */
    P2CONST(Mcu_SIM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_ChipControlRegisterConfig;
} Mcu_SIM_ChipControlConfigType;

/**
* @brief          Initialization data for the SIM driver.
* @details        A pointer to such a structure is provided to the routine to SIM_FTMOPT0 registers for configuring.
*
* @implements     Mcu_SIM_FTMOPT0ConfigType_struct
*/
typedef struct
{
    /**< @brief SIM_FTMOPT0 register configuration. */
    P2CONST(Mcu_SIM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_FTMOPT0RegisterConfig;
} Mcu_SIM_FTMOPT0ConfigType;

/**
* @brief          Initialization data for the SIM driver.
* @details        A pointer to such a structure is provided to the routine to SIM_LPOCLKS registers for configuring.
*
* @implements     Mcu_SIM_LPOCLKSConfigType_struct
*/
typedef struct
{
    /**< @brief SIM_LPOCLKS register configuration. */
    P2CONST(Mcu_SIM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_LPOCLKSRegisterConfig;
} Mcu_SIM_LPOCLKSConfigType;

/**
* @brief          Initialization data for the SIM driver.
* @details        A pointer to such a structure is provided to the routine to SIM_ADCOPT registers for configuring.
*
* @implements     Mcu_SIM_ADCOPTConfigType_struct
*/
typedef struct
{
    /**< @brief SIM_ADCOPT register configuration. */
    P2CONST(Mcu_SIM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_ADCOPTRegisterConfig;
} Mcu_SIM_ADCOPTConfigType;

/**
* @brief          Initialization data for the SIM driver.
* @details        A pointer to such a structure is provided to the routine to SIM_FTMOPT1 registers for configuring.
*
* @implements     Mcu_SIM_FTMOPT1ConfigType_struct
*/
typedef struct
{
    /**< @brief SIM_FTMOPT1 register configuration. */
    P2CONST(Mcu_SIM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_FTMOPT1RegisterConfig;
} Mcu_SIM_FTMOPT1ConfigType;

/**
* @brief          Initialization data for the SIM driver.
* @details        A pointer to such a structure is provided to the routine to SIM_MISCTRL0 registers for configuring.
*
* @implements     Mcu_SIM_MISCTRL0ConfigType_struct
*/
typedef struct
{
    /**< @brief SIM_MISCTRL0 register configuration. */
    P2CONST(Mcu_SIM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_MISCTRL0RegisterConfig;
} Mcu_SIM_MISCTRL0ConfigType;

/**
* @brief          Initialization data for the SIM driver.
* @details        A pointer to such a structure is provided to the routine to SIM_FCFG1 registers for configuring.
*
* @implements     Mcu_SIM_Flash1ConfigType_struct
*/
typedef struct
{
    /**< @brief SIM_FCFG1 register configuration. */
    P2CONST(Mcu_SIM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_Flash1RegisterConfig;
} Mcu_SIM_Flash1ConfigType;

/**
* @brief          Initialization data for the SIM driver.
* @details        A pointer to such a structure is provided to the routine to SIM_MISCTRL1 registers for configuring.
*
* @implements     Mcu_SIM_MISCTRL1ConfigType_struct
*/
typedef struct
{
    /**< @brief SIM_MISCTRL1 register configuration. */
    P2CONST(Mcu_SIM_RegisterConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_MISCTRL1RegisterConfig;
} Mcu_SIM_MISCTRL1ConfigType;

/**
* @brief          Initialization data for the SIM driver.
* @details        A pointer to such a structure is provided to the System Intergrate Module (SIM) which relating to clock
*                 configuration.
* @implements     Mcu_SIM_ClockConfigType_struct
*/
typedef struct
{
    /**< @brief SIM chip selection configuration. */
    P2CONST(Mcu_SIM_ChipSelectionConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_ChipSelectionConfig;
    /**< @brief SIM system clock divider register 4. */
    P2CONST(Mcu_SIM_TraceClockConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_TraceClockConfig;
    /**< @brief SIM platform clock gating control register. */
    P2CONST(Mcu_SIM_ClockGatingConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_ClockGatingConfig;
} Mcu_SIM_ClockConfigType;

/**
* @brief          Initialization data for the SIM driver.
* @details        A pointer to such a structure is provided to the System Intergrate Module (SIM) which contains
                  information for Flash, ADC and FTM general options.
* @implements     Mcu_SIM_ConfigType_struct
*/
typedef struct
{
   /**< @brief SIM Chip control configuration. */
    P2CONST(Mcu_SIM_ChipControlConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_ChipControlConfiguration;

   /**< @brief LPO Clock Config. */
    P2CONST(Mcu_SIM_LPOCLKSConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_LPOClockConfiguration;

   /**< @brief ADC configuration. */
    P2CONST(Mcu_SIM_ADCOPTConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_AdcOptionsConfiguration;

   /**< @brief FTMOPT0 Config. */
    P2CONST(Mcu_SIM_FTMOPT0ConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_FTMOPT0Configuration;

   /**< @brief FTMOPT1 configuration. */
    P2CONST(Mcu_SIM_FTMOPT1ConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_FTMOPT1Configuration;

   /**< @brief Flash configuration. */;
    P2CONST(Mcu_SIM_Flash1ConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_FlashConfiguaration1;

   /**< @brief SIM Miscellaneous Control configuration. */
    P2CONST(Mcu_SIM_MISCTRL0ConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_MiscellaneousConfiguration0;

   /**< @brief SIM Miscellaneous Control configuration. */
    P2CONST(Mcu_SIM_MISCTRL1ConfigType, MCU_CONST, MCU_APPL_CONST) pMcu_SIM_MiscellaneousConfiguration1;
} Mcu_SIM_ConfigType;


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

FUNC(void, MCU_CODE) Mcu_SIM_Init(P2CONST(Mcu_SIM_ConfigType, AUTOMATIC, MCU_APPL_CONST) pSIMConfigPtr);

FUNC(void, MCU_CODE) Mcu_SIM_ClockInit(P2CONST(Mcu_SIM_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);

#ifdef __cplusplus
}
#endif

#endif /* MCU_H */

/** @} */
