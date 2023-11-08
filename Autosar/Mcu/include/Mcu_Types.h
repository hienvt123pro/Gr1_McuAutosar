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

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                             ENUMS
==================================================================================================*/
/**
* @brief            Power Modes encoding.
* @details          Supported power modes for SMC hw IP.
*/
typedef enum
{
    MCU_RUN_MODE    = 0x00U,   /**< @brief Run Mode. */
    MCU_HSRUN_MODE  = 0x01U,   /**< @brief High Speed Mode. */
    MCU_VLPR_MODE   = 0x02U,   /**< @brief Very Low Power Run Mode. */
    MCU_VLPS_MODE   = 0x03U,   /**< @brief Very Low Power Stop Mode. */
    MCU_STOP1_MODE  = 0x04U,   /**< @brief Stop 1 Mode. */
    MCU_STOP2_MODE  = 0x05U,   /**< @brief Stop 2 Mode. */
} Mcu_PowerModeType;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief
* @details
*
* @note
*
*/
typedef struct
{

} Mcu_DepProsConfigType;

/**
* @brief
* @details
*
* @note
*
*/
typedef struct
{

} Mcu_ClockConfigType;

/**
* @brief            Definition of a MCU mode section in the configuration structure.
* @details          Specifies the system behaviour during the selected target mode.
*                   Data set and configured by Mcu_SetMode call.
*/
typedef struct
{
    /**< @brief The ID for Power Mode configuration. */
    VAR( Mcu_ModeType, MCU_VAR) Mcu_ModeConfigId;
   /**< @brief Power modes control configuration */
    VAR (Mcu_PowerModeType, MCU_VAR)  u32PowerMode;
} Mcu_ModeConfigType;

/**
* @brief
* @details
*
* @note
*
*/
typedef struct
{
    VAR(Mcu_RamSectionType, MCU_VAR) Mcu_RamSectorId;      /**< @brief The ID for Ram Sector configuration. */
    VAR(uint8, MCU_VAR) (*Mcu_pu8RamBaseAddr)[1U];         /**< @brief RAM section base address.            */
    VAR(Mcu_RamSizeType, MCU_VAR) Mcu_RamSize;             /**< @brief RAM section size.                    */
    VAR(uint64, MCU_VAR) Mcu_u64RamDefaultValue;           /**< @brief RAM default value for initialization.*/
    VAR(Mcu_RamWriteSizeType, MCU_VAR) Mcu_RamWriteSize;   /**< @brief RAM section write size.              */
}  Mcu_RamConfigType;

typedef struct
{

}  Mcu_RamConfigType;

typedef struct
{

}  Mcu_ResetConfigType;
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
