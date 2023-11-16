/**
*   @file    Mcu_Exe.c
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
#include "Mcu_Exe.h"

/* Header files that are called from IPW layer. */
#include "Mcu_PCC.h"
#include "Mcu_PMC.h"
#include "Mcu_RCM.h"
#include "Mcu_SCG.h"
#include "Mcu_SIM.h"
#include "Mcu_SMC.h"

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define MCU_SPLL_SOURCE_CLOCK      (0x01U)
#define MCU_NO_SPLL_SOURCE_CLOCK   (0x00U)

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

static P2CONST(Mcu_ClockConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pClockConfig = NULL_PTR;

static VAR(uint8, AUTOMATIC) u8SpllSourceClock = 0x00U;

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
	Mcu_SIM_Init(Mcu_pDepProsConfigPtr->pMcu_SIM_Config);
#endif

#if (MCU_DISABLE_PMC_INIT == STD_OFF)
    /* Configure the Power Management Unit. */
	Mcu_PMC_Init(Mcu_pDepProsConfigPtr->pMcu_PMC_Config);
#endif

#if (MCU_DISABLE_SMC_INIT == STD_OFF)
	/* Configure the System Mode Controller. */
	Mcu_SMC_Init(Mcu_pDepProsConfigPtr->pMcu_SMC_Config);
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
FUNC( void, MCU_CODE) Mcu_Exe_ResetConfigInit(P2CONST(Mcu_ResetConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pResetConfigPtr)
{
#if (MCU_DISABLE_RCM_INIT == STD_OFF)
    /* Init RCM settings. */
	Mcu_RCM_Init(Mcu_pResetConfigPtr->pMcu_RCM_Config);
#endif
}

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            This function initializes the clock structure.
* @details          This function intializes the clock structure by configuring the SIM, SCG, PCC modules.
*                   Called by:
*                       - Mcu_InitClock()
*
* @param[in]        Mcu_pClockConfigPtr   Pointer to clock configuration structure
*                   (member of 'Mcu_ConfigType' struct).
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Exe_InitClock(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pClockConfigPtr)
{
	Mcu_pClockConfig = Mcu_pClockConfigPtr;

	/* Switch to trusted clock (SIRC)*/
	Mcu_SCG_SwitchToTrustedClock((uint32)SCG_SCS_SIRC_U32);

	/* Initialize SOSC clock */
	Mcu_SCG_SOSCInit(Mcu_pClockConfig->pMcu_SCG_Config);

	/* Initialize SPLL clock */
	Mcu_SCG_SPLLInit(Mcu_pClockConfig->pMcu_SCG_Config);

	/* Initialize SIRC clock */
	Mcu_SCG_SIRCInit(Mcu_pClockConfig->pMcu_SCG_Config);

	/* Initialize FIRC clock */
	Mcu_SCG_FIRCInit(Mcu_pClockConfig->pMcu_SCG_Config);

	/* Initialize SIM clock  */
	Mcu_SIM_ClockInit(Mcu_pClockConfig->pMcu_SIM_ClockConfig);

	/* Initialize PCC clock */
	Mcu_PCC_Init(Mcu_pClockConfig->pMcu_PCC_Config);

	/* Check SPLL Source Clock */
	if (Mcu_pClockConfig->u8ClockSourcesControl == MCU_SPLL_CLK_SRC)
	{
		u8SpllSourceClock = MCU_SPLL_SOURCE_CLOCK;
	}
	else
	{
		u8SpllSourceClock = MCU_NO_SPLL_SOURCE_CLOCK;
		/* Configure System Clock */
		Mcu_SCG_SrcClock(Mcu_pClockConfig->pMcu_SCG_Config);
	}

}
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
/**
* @brief              This function activates the main PLL as the system clock source.
* @details            This function sets the PLL as the system clock and also enables monitoring.
*                     Called by:
*                       - Mcu_DistributePllClock()
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Exe_DistributePllClock(VAR(void, AUTOMATIC))
{
    /* Check if SPLL is configured as source clock, which is called by Mcu_InitClock() */
	if (u8SpllSourceClock == MCU_SPLL_SOURCE_CLOCK)
	{
		/* Remove the current clock source before configure PLL as source clock  */
		Mcu_SCG_SwitchToTrustedClock((uint32)SCG_SCS_SIRC_U32);

		/* Configure System Clock as PLL clock */
		Mcu_SCG_SrcClock(Mcu_pClockConfig->pMcu_SCG_Config);
	}
	else
	{
		/* Error: Mcu_InitClock() was not called before */
	}
}
#endif /* (MCU_NO_PLL == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#if (MCU_NO_PLL == STD_OFF)
/**
* @brief            This function returns the lock status of the PLL.
* @details          The user takes care that the PLL is locked by executing Mcu_GetPllStatus.
*                   If the MCU_NO_PLL is TRUE the MCU_GetPllStatus has to return
*                   MCU_PLL_STATUS_UNDEFINED.
*                   Called by:
*                       - Mcu_GetPllStatus()
*
* @return           Provides the lock status of the PLL.
* @retval           MCU_PLL_STATUS_UNDEFINED   PLL Status is unknown.
* @retval           MCU_PLL_LOCKED             PLL is locked.
* @retval           MCU_PLL_UNLOCKED           PLL is unlocked.
*
*/
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_Exe_GetPllStatus(VAR(void, AUTOMATIC))
{
	/* Pll status variable */
	VAR(Mcu_PllStatusType, AUTOMATIC) ePllStatus = MCU_PLL_STATUS_UNDEFINED;

    /* Get the status from each peripheral */
    if (Mcu_SCG_GetPLLStatus() == MCU_PLL_LOCKED)
    {
        ePllStatus = MCU_PLL_LOCKED;
    }
    else
    {
        ePllStatus = MCU_PLL_UNLOCKED;
    }

	return (Mcu_PllStatusType)ePllStatus;
}
#endif /* (MCU_NO_PLL == STD_OFF) */


#ifdef __cplusplus
}
#endif

/** @} */
