/**
*   @file    Mcu_RCM.c
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - Reset Control module functions implementation.
*   @details Specific functions for RCM configuration and control.
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


#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mcu_RCM.h"

#include "StdRegMacros.h"

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (defined(MCU_DISABLE_RCM_INIT) && (STD_OFF == MCU_DISABLE_RCM_INIT))
/**
* @brief            This function initializes the Reset parameters.
* @details          Conigures the threshold reset value.
*                   Called by:
*                       - Mcu_Exe_ResetConfigInit()
*
* @param[in]        pRCMConfigPtr   Pointer to the RCM configuration structure.
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_RCM_Init(P2CONST(Mcu_RCM_ConfigType, AUTOMATIC, MCU_APPL_CONST) pRCMConfigPtr)
{
	VAR(uint32, AUTOMATIC) u32RPC_Address;
	VAR(uint32, AUTOMATIC) u32RPC_Config;

	/* Config RCM_RPC register with RSTFLTSEL, RSTFLTSS, RSTFLTSRW bit fields. */
	u32RPC_Address = pRCMConfigPtr->pMcu_RCM_ResetPinControlConfig->pMcu_RCM_ResetPinControlRegisterConfig->u32PeripheralAdress;
	u32RPC_Config = pRCMConfigPtr->pMcu_RCM_ResetPinControlConfig->pMcu_RCM_ResetPinControlRegisterConfig->u32PeripheralDataConfiguration;
	REG_WRITE32(u32RPC_Address, (uint32)(u32RPC_Config & RCM_RPC_RWBITS_MASK32));

	/* Config RCM_SRIE register with SACKERR, MDM_AP, SW, LOCKUP, JTAG, GIE, PIN, WDOG, CMU_LOC, LOL, LOC, DELAY bit fields. */
	u32RPC_Address = pRCMConfigPtr->pMcu_RCM_ResetInterruptEnableConfig->pMcu_RCM_ResetInterruptEnableRegisterConfig->u32PeripheralAdress;
	u32RPC_Config = pRCMConfigPtr->pMcu_RCM_ResetInterruptEnableConfig->pMcu_RCM_ResetInterruptEnableRegisterConfig->u32PeripheralDataConfiguration;
	REG_WRITE32(u32RPC_Address, (uint32)(u32RPC_Config & RCM_SRIE_RWBITS_MASK32));
}
#endif


#ifdef __cplusplus
}
#endif

/** @} */
