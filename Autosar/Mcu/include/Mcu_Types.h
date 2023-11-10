/**
*   @file    Mcu_Types.h
*   @implements Mcu_Types.h_Artifact
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


#ifndef MCU_TYPES_H
#define MCU_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mcal.h"

#include "Mcu_Cfg.h"
#include "Mcu_PMC.h"
#include "Mcu_SMC.h"
#include "Mcu_SIM.h"
#include "Mcu_PCC.h"
#include "Mcu_SCG.h"
#include "Mcu_RCM.h"

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
* @brief          Initialization registers for Mcu dependent properties.
* @details        Pointer to structures for SMC, PMC and SIM modules.
* @implements     Mcu_DepProsConfigType_struct
*
*/
typedef struct
{
    /**< @brief Configuration for SMC hardware IP. */
    P2CONST(Mcu_SMC_ConfigType, MCU_VAR, MCU_APPL_CONST) pMcu_SMC_Config;
    /**< @brief Configuration for PMC hardware IP. */
    P2CONST(Mcu_PMC_ConfigType, MCU_VAR, MCU_APPL_CONST) pMcu_PMC_Config;
    /**< @brief Configuration for SIM hardware IP. */
    P2CONST(Mcu_SIM_ConfigType, MCU_VAR, MCU_APPL_CONST) pMcu_SIM_Config;
} Mcu_DepProsConfigType;

/**
* @brief            Initialization data for the MCU reset driver.
* @details          Pointer to structure for RCM modules.
* @implements       Mcu_ResetConfigType_struct
*/

typedef struct
{
    /**< @brief RCM configuration. */
    P2CONST(Mcu_RCM_ConfigType, MCU_VAR, MCU_APPL_CONST) pMcu_RCM_Config;
} Mcu_ResetConfigType;

/**
* @brief          Initialization data for the MCU clock driver.
* @details        A pointer to such a structure is provided to the Clock settings initialization routines for
*                 configuration.
* @implements     Mcu_ClockConfigType_struct
*/
typedef struct
{
    /**< @brief The ID for Clock configuration. */
    VAR(Mcu_ClockType, MCU_VAR) u32Mcu_ClkConfigId;

    /**< @brief SIM configuration. */
    P2CONST(Mcu_SIM_ClockConfigType, MCU_VAR, MCU_APPL_CONST) pMcu_SIM_ClockConfig;

    /**< @brief SCG configuration. */
    P2CONST(Mcu_SCG_ConfigType, MCU_VAR, MCU_APPL_CONST) pMcu_SCG_Config;

    /**< @brief PCC configuration. */
    P2CONST(Mcu_PCC_ConfigType, MCU_VAR, MCU_APPL_CONST) pMcu_PCC_Config;

    /**< @brief Clock sources and PLLs under mcu control. */
    VAR(uint8, MCU_VAR) u8ClockSourcesControl;
} Mcu_ClockConfigType;

/**
* @brief            Definition of a MCU mode section in the configuration structure.
* @details          Specifies the system behaviour during the selected target mode.
*                   Data set and configured by Mcu_SetMode call.
* @implements       Mcu_ModeConfigType_struct
*/
typedef struct
{
    /**< @brief The ID for Power Mode configuration. */
    VAR(Mcu_ModeType, MCU_VAR) u32Mcu_ModeId;
   /**< @brief Power modes control configuration */
    VAR(Mcu_PowerModeType, MCU_VAR) u32Mcu_PowerMode;
} Mcu_ModeConfigType;

/**
* @brief            Definition of a RAM section within the configuration structure.
*                   The definitions for each RAM section within the structure Mcu_ConfigType shall contain:
*                   - RAM section base address
*                   - Section size
*                   - Data pre-setting to be initialized
* @implements       Mcu_RamConfigType_struct
*/
typedef struct
{
	/**< @brief The ID for Ram Sector configuration. */
    VAR(Mcu_RamSectionType, MCU_VAR) u32Mcu_RamSectorId;
    /**< @brief RAM section base address.            */
    VAR(uint8, MCU_VAR) (*pu8Mcu_RamBaseAddr)[1U];
    /**< @brief RAM section size.                    */
    VAR(Mcu_RamSizeType, MCU_VAR) u32Mcu_RamSize;
    /**< @brief RAM default value for initialization.*/
    VAR(uint64, MCU_VAR) u64Mcu_RamDefaultValue;
    /**< @brief RAM section write size.              */
    VAR(Mcu_RamWriteSizeType, MCU_VAR) u32Mcu_RamWriteSize;
}  Mcu_RamConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_TYPES_H */

/** @} */
