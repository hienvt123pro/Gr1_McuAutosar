/**
*   @file    Mcu_EXE.c
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - Middle layer implementation.
*   @details Layer that implements the wrapper for routing data from/to external interface
*            to IP layer.
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
extern
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
/* Header file with prototype functions defines in this layer. */
#include "Mcu_EXE.h"

/* Header files that are called from IPW layer. */
#include "Mcu_PCC.h"
#include "Mcu_PMC.h"
#include "Mcu_RCM.h"
#include "Mcu_SCG.h"
#include "Mcu_SIM.h"
#include "Mcu_SMC.h"

#include "Reg_eSys_PCC.h"
#include "Reg_eSys_SCG.h"
#include "Reg_eSys_PMC.h"
#include "Reg_eSys_SMC.h"
#include "Reg_eSys_SIM.h"
#include "Reg_eSys_RCM.h"

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
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
/**
* @brief            This function initializes the MCU module.
* @details          The function initializes the SIM, SMC, PMC modules.
*                   Called by:
*                       - Mcu_Init().
*
* @param[in]        Mcu_pDepProsConfigPtr   Pointer to Mcu Dependent Properties configuration structure.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Exe_DepProsInit(P2CONST( Mcu_DepProsConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pDepProsConfigPtr)
{
#if (MCU_DISABLE_SIM_INIT == STD_OFF)
    /* Init SIM settings. */

#endif

#if (MCU_DISABLE_PMC_INIT == STD_OFF)
    /* Configure the Power Management Unit. */

#endif

#if (MCU_DISABLE_SMC_INIT == STD_OFF)
	/* Configure the System Mode Controller. */

#endif
}

/**
* @brief            This function initializes the MCU module.
* @details          The function initializes the RCM modules.
*                   Called by:
*                       - Mcu_Init().
*
* @param[in]        Mcu_pResetConfigPtr   Pointer to Mcu Reset configuration structure.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Exe_ResetConfigInit(P2CONST( Mcu_ResetConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pResetConfigPtr)
{
#if (MCU_DISABLE_RCM_INIT == STD_OFF)
    /* Init RCM settings. */

#endif
}

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            This function initializes the clock structure.
* @details          This function intializes the clock structure by configuring the SIM, SCG, PCC modules.
*                   Called by:
*                       - Mcu_InitClock() from HLD.
*
* @param[in]        Mcu_pClockConfigPtr   Pointer to clock configuration structure
*                   (member of 'Mcu_ConfigType' struct).
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Exe_InitClock(P2CONST( Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pClockConfigPtr)
{

}
#endif /* (MCU_INIT_CLOCK == STD_ON) */
