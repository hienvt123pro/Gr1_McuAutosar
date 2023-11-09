/**
*   @file    Mcu_PMC.c
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - Power Management Controller module functions implementation.
*   @details Specific functions for PMC configuration and control.
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
#include "Mcu_PMC.h"

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

#if (defined(MCU_DISABLE_PMC_INIT) && (STD_OFF == MCU_DISABLE_PMC_INIT))
/**
* @brief            This function configure the Power Management Controller
* @details          The operating voltages are monitored by a set of on-chip supervisory circuits
*                   to ensure that this device works within the correct voltage range.
*                   Called by:
*                       - Mcu_Exe_DepProsInit()
*
* @param[in]        pConfigPtr   Pointer to PMC configuration structure.
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_PMC_Init(P2CONST(Mcu_PMC_ConfigType, AUTOMATIC, MCU_APPL_CONST) pPMCConfigPtr)
{
	VAR(uint32, AUTOMATIC) u32Temp;
	u32Temp = (uint32)pPMCConfigPtr->u8LVDSC1 | ((uint32)pPMCConfigPtr->u8LVDSC2 << 8) \
			| ((uint32)pPMCConfigPtr->u8REGSC << 16) | ((uint32)pPMCConfigPtr->u8LPOTRIM << 24);
	/* Configure LVDSC1, LVDSC2, REGSC, LPOTRIM registers */
	REG_RMW32(PMC_BASEADDR, PMC_REG_RWBITS_MASK32, u32Temp);
}
#endif


#ifdef __cplusplus
}
#endif

/** @} */
