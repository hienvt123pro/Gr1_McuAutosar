/**
*   @file    Mcu_SIM.c
*   @version 1.0.4
*
*   @brief   AUTOSAR SIM - System Integration Module functions implementation.
*   @details Specific functions for SIM configuration and control.
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
#include "Mcu_SIM.h"

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

/**
* @brief            MCU driver initialization function.
* @details          This routine initializes the SIM module that provides system controll
*                   and chip configuration register.
*
*
* @param[in]        pSIMConfigPtr   Pointer to configuration structure.
*
* @return           void
*
* @api
*
* @implements       Mcu_Init_Activity
*
*/
FUNC(void, MCU_CODE) Mcu_SIM_Init(P2CONST( Mcu_SIM_ConfigType, AUTOMATIC, MCU_APPL_CONST) pSIMConfigPtr)
{
	/* Configure SIM_CHIPCTL register with mask for general settings (ADC_INTERLEAVE_EN, PDB_BB_SEL)*/
    /* Use REG_RMW32 because SIM_CHIPCTL register has something which are configured in other functions*/
    REG_RMW32(pSIMConfigPtr->pMcu_SIM_ChipControlConfiguration->pMcu_SIM_ChipControlRegisterConfig->u32PeripheralAdress, SIM_CHIPCTL_INIT_MASK32, \
             pSIMConfigPtr->pMcu_SIM_ChipControlConfiguration->pMcu_SIM_ChipControlRegisterConfig->u32PeripheralDataConfiguration);

    /* Configure SIM_LPOCLKS register */
    REG_WRITE32(pSIMConfigPtr->pMcu_SIM_LPOClockConfiguration->pMcu_SIM_LPOCLKSRegisterConfig->u32PeripheralAdress,
                SIM_LPOCLKS_RWBITS_MASK32 & pSIMConfigPtr->pMcu_SIM_LPOClockConfiguration->pMcu_SIM_LPOCLKSRegisterConfig->u32PeripheralDataConfiguration);

    /* Configure SIM_ADCOPT register */
    REG_WRITE32(pSIMConfigPtr->pMcu_SIM_AdcOptionsConfiguration->pMcu_SIM_ADCOPTRegisterConfig->u32PeripheralAdress,
                SIM_ADCOPT_RWBITS_MASK32 & pSIMConfigPtr->pMcu_SIM_AdcOptionsConfiguration->pMcu_SIM_ADCOPTRegisterConfig->u32PeripheralDataConfiguration);

    /* Configure SIM_FTMOPT0 register */
    REG_WRITE32(pSIMConfigPtr->pMcu_SIM_FTMOPT0Configuration->pMcu_SIM_FTMOPT0RegisterConfig->u32PeripheralAdress,
                SIM_FTMOPT0_RWBITS_MASK32 & pSIMConfigPtr->pMcu_SIM_FTMOPT0Configuration->pMcu_SIM_FTMOPT0RegisterConfig->u32PeripheralDataConfiguration);

    /* Configure SIM_FTMOPT1 register */
    REG_WRITE32(pSIMConfigPtr->pMcu_SIM_FTMOPT1Configuration->pMcu_SIM_FTMOPT1RegisterConfig->u32PeripheralAdress,
                SIM_FTMOPT1_RWBITS_MASK32 & pSIMConfigPtr->pMcu_SIM_FTMOPT1Configuration->pMcu_SIM_FTMOPT1RegisterConfig->u32PeripheralDataConfiguration);

    /* Configure SIM_MISCTRL0 register */
    REG_WRITE32(pSIMConfigPtr->pMcu_SIM_MiscellaneousConfiguration0->pMcu_SIM_MISCTRL0RegisterConfig->u32PeripheralAdress,
                SIM_MISCTRL0_RWBITS_MASK32 & pSIMConfigPtr->pMcu_SIM_MiscellaneousConfiguration0->pMcu_SIM_MISCTRL0RegisterConfig->u32PeripheralDataConfiguration);

    /* Configure SIM_MISCTRL1 register */
    REG_WRITE32(pSIMConfigPtr->pMcu_SIM_MiscellaneousConfiguration0->pMcu_SIM_MISCTRL0RegisterConfig->u32PeripheralAdress,
                SIM_MISCTRL1_RWBITS_MASK32 & pSIMConfigPtr->pMcu_SIM_MiscellaneousConfiguration1->pMcu_SIM_MISCTRL1RegisterConfig->u32PeripheralDataConfiguration);
}

#ifdef __cplusplus
}
#endif

/** @} */
