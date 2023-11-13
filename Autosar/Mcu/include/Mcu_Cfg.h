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


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

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
#define MCU_MAX_RAMCONFIGS    ((uint32)1U)

/**
* @brief            This parameter shall be set True, if the H/W does not have a PLL or the PLL circuitry is enabled after the power on without S/W intervention.
*/
#define MCU_NO_PLL   (STD_OFF)

/**
* @brief            Clock Source for MCU
*/
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
