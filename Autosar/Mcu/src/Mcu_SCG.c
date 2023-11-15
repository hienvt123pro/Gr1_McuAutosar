/**
*   @file    Mcu_SCG.c
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - System Clock Generator functions implementation.
*   @details Specific functions for SCG configuration and control.
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
*                                        INCLUDE FILES
==================================================================================================*/
#include "Mcu_SCG.h"
#include "Mcu_PCC.h"

#include "StdRegMacros.h"

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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
* @brief            This function will configure the SOSC clock
* @details          Called by Mcu_SCG_SOSCInit
*
* @param[in]        Mcu_SCG_ConfigType   Pointer to SCG module configuration structure.
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_SCG_SOSCInit(P2CONST(Mcu_SCG_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    VAR(uint32, AUTOMATIC) u32ConfigData = 0U;
    VAR(uint32, AUTOMATIC) u32Address = 0U;

	if (pConfigPtr->pMcu_SOSC_RegisterConfig != NULL_PTR)
	{
		/* Configure SOSCDIV register with SOSCDIV1 & SOSCDIV2 bit fields */
		u32Address = pConfigPtr->pMcu_SOSC_RegisterConfig->pMcu_SOSCDIV_RegisterConfig->u32PeripheralAdress;
		u32ConfigData = pConfigPtr->pMcu_SOSC_RegisterConfig->pMcu_SOSCDIV_RegisterConfig->u32PeripheralDataConfiguration;
		REG_WRITE32(u32Address, u32ConfigData);

		/* Configure SOSCCFG register with RANGE, HGO, EREFS bit fields */
		u32Address = pConfigPtr->pMcu_SOSC_RegisterConfig->pMcu_SOSCCFG_RegisterConfig->u32PeripheralAdress;
		u32ConfigData = pConfigPtr->pMcu_SOSC_RegisterConfig->pMcu_SOSCCFG_RegisterConfig->u32PeripheralDataConfiguration;
		REG_WRITE32(u32Address, u32ConfigData);

		/* Ensure SOSCSR is unlock */
		u32Address = pConfigPtr->pMcu_SOSC_RegisterConfig->pMcu_SOSCCSR_RegisterConfig->u32PeripheralAdress;
		u32ConfigData = pConfigPtr->pMcu_SOSC_RegisterConfig->pMcu_SOSCCSR_RegisterConfig->u32PeripheralDataConfiguration;
		while (REG_READ32(u32Address) & SCG_SOSCCSR_LK_MASK32);

		/* Configure SOSCSR register and ensure SOSCSR is unlock */
		REG_WRITE32(u32Address, u32ConfigData);

		/* Wait for SOSC Clock to be valid */
		while (!(REG_READ32(u32Address) & SCG_SOSCCSR_SOSCVLD_MASK32));
	}
}

/**
* @brief            This function will configure the SPLL clock
* @details          Called by Mcu_SCG_SPLLInit
*
* @param[in]        Mcu_SCG_ConfigType   Pointer to SCG module configuration structure.
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_SCG_SPLLInit(P2CONST(Mcu_SCG_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    VAR(uint32, AUTOMATIC) u32ConfigData = 0U;
    VAR(uint32, AUTOMATIC) u32Address = 0U;

	if (pConfigPtr->pMcu_SPLL_RegisterConfig != NULL_PTR)
	{
		/* Ensure SPLLCSR register is unlock */
		u32Address = pConfigPtr->pMcu_SPLL_RegisterConfig->pMcu_SPLLCSR_RegisterConfig->u32PeripheralAdress;
		while (REG_READ32(u32Address) & SCG_SPLLCSR_LK_MASK32);

		/* Configure SPLLDIV register */
		u32Address = pConfigPtr->pMcu_SPLL_RegisterConfig->pMcu_SPLLDIV_RegisterConfig->u32PeripheralAdress;
		u32ConfigData = pConfigPtr->pMcu_SPLL_RegisterConfig->pMcu_SPLLDIV_RegisterConfig->u32PeripheralDataConfiguration;
		REG_WRITE32(u32Address, u32ConfigData);

		/* Configure SPLLCFG register */
		u32Address = pConfigPtr->pMcu_SPLL_RegisterConfig->pMcu_SPLLCFG_RegisterConfig->u32PeripheralAdress;
		u32ConfigData = pConfigPtr->pMcu_SPLL_RegisterConfig->pMcu_SPLLCFG_RegisterConfig->u32PeripheralDataConfiguration;
		REG_WRITE32(u32Address, u32ConfigData);

		/* Configure SPLLCSG register */
		u32Address = pConfigPtr->pMcu_SPLL_RegisterConfig->pMcu_SPLLCSR_RegisterConfig->u32PeripheralAdress;
		u32ConfigData = pConfigPtr->pMcu_SPLL_RegisterConfig->pMcu_SPLLCSR_RegisterConfig->u32PeripheralDataConfiguration;
		REG_WRITE32(u32Address, u32ConfigData);

		/* Enable SPLL */
		REG_BIT_SET32(u32Address, SCG_SPLLCSR_SPLLEN_MASK32);
	}
}

/**
* @brief            This function will configure the SIRC clock
* @details          Called by Mcu_Exe_InitClock
*
* @param[in]        Mcu_SCG_SIRCInit   Pointer to SCG module configuration structure.
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_SCG_SIRCInit(P2CONST(Mcu_SCG_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
	if (pConfigPtr->pMcu_SIRC_RegisterConfig != NULL_PTR)
	{
		/* Disable SIRC so the rest of the register can be configured. */
		REG_BIT_CLEAR32(SCG_SIRCCSR_ADDR32, SCG_SIRCCSR_SIRCEN_MASK32);

		/* Config SCG_SIRCDIV register with SIRCDIV1, SIRCDIV2 bit fields. */
		REG_WRITE32(pConfigPtr->pMcu_SIRC_RegisterConfig->pMcu_SIRCDIV_RegisterConfig->u32PeripheralAdress, \
				pConfigPtr->pMcu_SIRC_RegisterConfig->pMcu_SIRCDIV_RegisterConfig->u32PeripheralDataConfiguration);

		/* Config SCG_SIRCCFG register with RANGE bit fields. */
		REG_WRITE32(pConfigPtr->pMcu_SIRC_RegisterConfig->pMcu_SIRCCFG_RegisterConfig->u32PeripheralAdress, \
				pConfigPtr->pMcu_SIRC_RegisterConfig->pMcu_SIRCCFG_RegisterConfig->u32PeripheralDataConfiguration);

		/* Config SCG_SIRCCSG register with LK, SIRCLPEN, SIRCSTEN, SIRCEN bit fields. */
		REG_WRITE32(pConfigPtr->pMcu_SIRC_RegisterConfig->pMcu_SIRCCSR_RegisterConfig->u32PeripheralAdress, \
				pConfigPtr->pMcu_SIRC_RegisterConfig->pMcu_SIRCCSR_RegisterConfig->u32PeripheralDataConfiguration);

		/* Check whether the mode SIRC is enable or not. */
		if ((REG_READ32(SCG_SIRCCSR_ADDR32) & SCG_SIRCCSR_SIRCEN_MASK32) == SCG_SIRCCSR_SIRCEN_MASK32)
		{
			while((REG_READ32(SCG_SIRCCSR_ADDR32) & SCG_SIRCCSR_SIRCVLD_MASK32) != SCG_SIRCCSR_SIRCVLD_MASK32);
		}
	}
}

/**
* @brief            This function will configure the FIRC clock
* @details          Called by Mcu_Exe_InitClock
*
* @param[in]        Mcu_SCG_FIRCInit   Pointer to SCG module configuration structure.
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_SCG_FIRCInit(P2CONST(Mcu_SCG_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
	if (pConfigPtr->pMcu_FIRC_RegisterConfig != NULL_PTR)
	{
		/* Disable FIRC so the rest of the register can be configured. */
		REG_BIT_CLEAR32(SCG_FIRCCSR_ADDR32, SCG_FIRCCSR_FIRCEN_MASK32);

		/* Config SCG_FIRCDIV register with FIRCDIV1, FIRCDIV2 bit fields. */
		REG_WRITE32(pConfigPtr->pMcu_FIRC_RegisterConfig->pMcu_FIRCDIV_RegisterConfig->u32PeripheralAdress, \
				pConfigPtr->pMcu_FIRC_RegisterConfig->pMcu_FIRCDIV_RegisterConfig->u32PeripheralDataConfiguration);

		/* Config SCG_FIRCCFG register with RANGE bit fields. */
		REG_WRITE32(pConfigPtr->pMcu_FIRC_RegisterConfig->pMcu_FIRCCFG_RegisterConfig->u32PeripheralAdress, \
				pConfigPtr->pMcu_FIRC_RegisterConfig->pMcu_FIRCCFG_RegisterConfig->u32PeripheralDataConfiguration);

		/* Config SCG_FIRCCSG register with LK, FIRCLPEN, FIRCSTEN, FIRCEN bit fields. */
		REG_WRITE32(pConfigPtr->pMcu_FIRC_RegisterConfig->pMcu_FIRCCSR_RegisterConfig->u32PeripheralAdress, \
				pConfigPtr->pMcu_FIRC_RegisterConfig->pMcu_FIRCCSR_RegisterConfig->u32PeripheralDataConfiguration);

		/* Check whether the mode FIRC is enable or not. */
		if ((REG_READ32(SCG_FIRCCSR_ADDR32) & SCG_FIRCCSR_FIRCEN_MASK32) == SCG_FIRCCSR_FIRCEN_MASK32)
		{
			while((REG_READ32(SCG_FIRCCSR_ADDR32) & SCG_FIRCCSR_FIRCVLD_MASK32) != SCG_FIRCCSR_FIRCVLD_MASK32);
		}
	}
}

/**
* @brief            This function will configure the system clock for all modes
* @details          This function will configure the system clock for all modes
*                   Called by:
*                       - Mcu_Exe_InitClock()
*
* @param[in]        pConfigPtr   Pointer to SCG configuration structure
*                   (member of 'Mcu_ConfigType' struct).
* @param[in]        u8ClockSourcesControl Hold clock source that needs to config
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_SCG_SrcClock(P2CONST(Mcu_SCG_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr, VAR(uint8, MCU_VAR) u8ClockSourcesControl)
{
    VAR(uint32, AUTOMATIC) u32TimeOut = 0U;
    VAR(uint32, AUTOMATIC) u32RegValue = 0U;

    /***************************************************SECTION 1**************************************************/

    /*Config clock source for System Clock at Normal Running Mode*/
    REG_WRITE32(SCG_RCCR_ADDR32, u8ClockSourcesControl << MCU_CLK_SRC_BIT_SHIFT);

    /*May not need*/
    u32RegValue = REG_READ32(SCG_RCCR_ADDR32) & SCG_RCCR_SCS_MASK32;

    /***************************************************SECTION 2**************************************************/

    /*Timeout representing the number of loops for preventing to lock inside am infinite while/for.*/
    u32TimeOut = 50000u /*MCU_TIMEOUT_LOOPS*/;    /*This variable is stored in Mcu_Cfg.h*/
    do
    {
        u32TimeOut--;

        u32RegValue = REG_READ32(SCG_RCCR_ADDR32) & SCG_RCCR_SCS_MASK32;
    }
    while (((pConfigPtr->Mcu_RUNModeConfig & SCG_RCCR_SCS_MASK32) != u32RegValue) && ((uint32)0x00U < u32TimeOut));

    /***************************************************SECTION 3**************************************************/

    /*Config Very Low Power Mode*/
    REG_WRITE32(SCG_VCCR_ADDR32, pConfigPtr->Mcu_VLPRModeConfig);

    /* Wait for switching system clock source done. */
    u32TimeOut = 50000u /*MCU_TIMEOUT_LOOPS*/;    /*This variable is stored in Mcu_Cfg.h*/
    do
    {
        u32TimeOut--;
        /** @violates @ref Mcu_SCG_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
        u32RegValue = REG_READ32(SCG_VCCR_ADDR32) & SCG_VCCR_SCS_MASK32;
    }
    while (((pConfigPtr->Mcu_VLPRModeConfig & SCG_VCCR_SCS_MASK32) != u32RegValue) && ((uint32)0x00U < u32TimeOut));

    /***************************************************SECTION 4**************************************************/

    /*Clock out Selection*/
    REG_WRITE32(SCG_CLKOUTCNFG_ADDR32, pConfigPtr->Mcu_ClockOutSelection);
}


#if (MCU_NO_PLL == STD_OFF)
/**
* @brief            This function returns the lock status of the PLL.
* @details          Check PLL validation bit field
*                   Called by:
*                       - Mcu_Exe_GetPllStatus()
*
* @return           Provides the lock status of the PLL.
* @retval           MCU_PLL_STATUS_UNDEFINED   PLL Status is unknown.
* @retval           MCU_PLL_LOCKED             PLL is locked.
* @retval           MCU_PLL_UNLOCKED           PLL is unlocked.
*
*/
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_SCG_GetPLLStatus(VAR(void, AUTOMATIC))
{
	/* Pll status variable */
	VAR(Mcu_PllStatusType, AUTOMATIC) ePllStatus = MCU_PLL_STATUS_UNDEFINED;

	/* Get the status from each peripheral */
	if (SCG_SPLLCSR_SPLLVLD_MASK32 == (REG_READ32(SCG_SPLLCSR_ADDR32) & SCG_SPLLCSR_SPLLVLD_MASK32))
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
