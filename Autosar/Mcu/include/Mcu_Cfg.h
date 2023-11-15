/**
*   @file    Mcu_Cfg.h
*   @implements Mcu_Cfg.h_Artifact
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


#ifndef MCU_CFG_H
#define MCU_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mcal.h"

#include "Std_Types.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
/**
* @brief            Create defines with the IDs assigned to Mcu Clock configurations.
*                   These IDs will be transmitted as input parameters for Mcu_InitClock() API.
*/
#define McuClockSettingConfig_0   ((Mcu_ClockType)0U)

/**
* @brief            Create defines with the IDs assigned to Mcu RAM configurations.
*                   These IDs will be transmitted as input parameters for Mcu_InitRamSection() API.
*/
#define McuRamSection_0   ((Mcu_RamSectionType)0U)

/**
* @brief            Create defines with the IDs assigned to Mcu RAM configurations.
*                   These IDs will be transmitted as input parameters for Mcu_InitRamSection() API.
*/
#define McuRamSection_1   ((Mcu_RamSectionType)1U)

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define MCU_MODULE_ID        101

/**
* @brief      Specifies the InstanceId of this module instance.
*/
#define MCU_INSTANCE_ID                 ((uint8)0x0U)

/**
@{
* @brief            Default error values are of type uint8.
*                   The following errors and exceptions shall be detectable by the MCU module depending on its
*                   build version (default/production mode).
*
*/
#define MCU_E_PARAM_CONFIG              ((uint8)0x0AU)
#define MCU_E_PARAM_CLOCK               ((uint8)0x0BU)
#define MCU_E_PARAM_MODE                ((uint8)0x0CU)
#define MCU_E_PARAM_RAMSECTION          ((uint8)0x0DU)
#define MCU_E_PLL_NOT_LOCKED            ((uint8)0x0EU)
#define MCU_E_UNINIT                    ((uint8)0x0FU)
#define MCU_E_PARAM_POINTER             ((uint8)0x10U)
#define MCU_E_INIT_FAILED               ((uint8)0x11U)
#define MCU_E_ALLREADY_INITIALIZED      ((uint8)0x13U)
#define MCU_E_CMU_INDEX_OUT_OF_RANGE    ((uint8)0x22U)

/**
@{
* @brief            Service Ids for MCU APIs.
*/
#define MCU_INIT_ID                     ((uint8)0x00U)
#define MCU_INITRAMSECTION_ID           ((uint8)0x01U)
#define MCU_INITCLOCK_ID                ((uint8)0x02U)
#define MCU_DISTRIBUTEPLLCLOCK_ID       ((uint8)0x03U)
#define MCU_GETPLLSTATUS_ID             ((uint8)0x04U)
/**
* @brief            If this parameter is set to FALSE, the clock initialization has to be disabled from the MCU driver.
*/
#define MCU_INIT_CLOCK    (STD_ON)

/**
* @brief            Pre-processor switch for enabling the development error detection and reporting to the DET.
*                   The detection of development errors is configurable (ON / OFF) at pre-compile time.
*/
#define MCU_DEV_ERROR_DETECT   (STD_ON)

/**
* @brief            If this parameter is set to TRUE, the System Integration Module (SIM) initialization has to be disabled from the MCU driver.
*/
#define MCU_DISABLE_SIM_INIT   (STD_OFF)

/**
* @brief            If this parameter is set to TRUE, the Reset Control Module (RMC) initialization has to be disabled from the MCU driver.
*/
#define MCU_DISABLE_RCM_INIT   (STD_OFF)

/**
* @brief            If this parameter is set to TRUE, the Power Management Controller (PMC) initialization has to be disabled from the MCU driver.
*/
#define MCU_DISABLE_PMC_INIT   (STD_OFF)

/**
* @brief            If this parameter is set to TRUE, the System Mode Controller (SMC) initialization has to be disabled from the MCU driver.
*/
#define MCU_DISABLE_SMC_INIT   (STD_OFF)

/**
* @brief            Maximum number of MCU Clock configurations.
*/
#define MCU_MAX_CLKCONFIGS    ((uint32)1U)

/**
* @brief            Maximum number of MCU Mode configurations.
*/
#define MCU_MAX_MODECONFIGS   ((uint32)1U)

/**
* @brief            Maximum number of MCU Ram configurations.
*/
#define MCU_MAX_RAMCONFIGS    ((uint32)2U)

/**
* @brief            This parameter shall be set True, if the H/W does not have a PLL or the PLL circuitry is enabled after the power on without S/W intervention.
*/
#define MCU_NO_PLL   (STD_OFF)

/**
* @brief            Clock Source for MCU
*/
#define MCU_CLK_SRC_BIT_SHIFT  24
#define MCU_SOSC_CLK_SRC  (0x01U)
#define MCU_SIRC_CLK_SRC  (0x02U)
#define MCU_FIRC_CLK_SRC  (0x03U)
#define MCU_SPLL_CLK_SRC  (0x06U)
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/**
* @brief            Type of the return value of the function Mcu_GetPllStatus.
* @details          The type of Mcu_PllStatusType is an enumeration with the following values:
*                       MCU_PLL_LOCKED, MCU_PLL_UNLOCKED, MCU_PLL_STATUS_UNDEFINED.
*
* @implements     Mcu_PllStatusType_enumeration
*
*/
typedef enum
{
    MCU_PLL_LOCKED = 0x33U,   /**< @brief PLL is locked. */
    MCU_PLL_UNLOCKED = 0xCCU,   /**< @brief PLL is unlocked. */
    MCU_PLL_STATUS_UNDEFINED = 0x5AU   /**< @brief PLL Status is unknown. */
} Mcu_PllStatusType;


/**
* @brief            Pre-Compile structure from Mcu_Cfg.c file.
*/
#define MCU_CONF_PB \
 extern CONST(Mcu_ConfigType, MCU_CONST) Mcu_Config;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief            The Mcu_ModeType specifies the identification (ID) for a MCU mode, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
*
* @implements     Mcu_ModeType_typedef
*
*/
typedef uint32 Mcu_ModeType;

/**
* @brief            The Mcu_RamSectionType specifies the identification (ID) for a RAM section, configured via the configuration structure.
*                   The type shall be uint8, uint16 or uint32, based on best performance.
* @implements Mcu_RamSectionType_typedef
*/
typedef uint32 Mcu_RamSectionType;

/**
* @brief            The Mcu_RamSizeType specifies the RAM section size.
*                   The type shall be uint8, uint16 or uint32, based on best performance.
*
*/
typedef uint32 Mcu_RamSizeType;

/**
* @brief            The Mcu_RamWriteSizeType specifies the RAM section write size.
*                   The type shall be uint8, uint16 or uint32, based on best performance.
*
*/
typedef uint32 Mcu_RamWriteSizeType;


#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief          Defines the identification (ID) for clock setting configured via the configuration structure.
* @details        The type shall be uint8, uint16 or uint32, depending on uC platform.
*
* @implements Mcu_ClockType_typedef
*/
typedef uint32 Mcu_ClockType;
#endif

/**
* @brief Defines the maximum value of the registers - these values is hardware/platform dependent.
*/
/* This define specifies the number of PCC registers */
#define MCU_NUMBER_OF_PCC_REGISTERS_U32         ((uint32)32U)


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_CFG_H */

/** @} */
