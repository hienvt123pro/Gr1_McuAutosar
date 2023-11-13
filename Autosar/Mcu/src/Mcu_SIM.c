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

/**
* @brief            MCU driver initialization function.
* @details          This routine initializes the SIM module that provides clock configuration
*
* @param[in]        pSIMClockConfigPtr   Pointer to SIM clock configuration structure.
*
* @return           void
*
* @api
*
* @implements       Mcu_SIM_ClockInit_Activity
*
*/
FUNC(void, MCU_CODE) Mcu_SIM_ClockInit(P2CONST( Mcu_SIM_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pSIMClockConfigPtr)
{
    /* Configure SIM_PLATCGC register */
    /* Masking with 0x0000001F (bit 0->4)*/
    REG_WRITE32(pSIMClockConfigPtr->pMcu_SIM_ClockGatingConfig->pMcu_SIM_ClockGatingRegisterConfig->u32PeripheralAdress,
                (SIM_PLATGC_RWBITS_MASK32 & (uint32)pSIMClockConfigPtr->pMcu_SIM_ClockGatingConfig->pMcu_SIM_ClockGatingRegisterConfig->u32PeripheralDataConfiguration));

    /* SIM_CHIPCTL_CLKOUT should be cleared before configuring */
    /* Disable SIM_CHIPCTL_CLKOUT by masking with ~(0x0x00000800U) (bit 11)*/
    REG_RMW32(pSIMClockConfigPtr->pMcu_SIM_ChipSelectionConfig->pMcu_SIM_ChipSelectionRegisterConfig->u32PeripheralAdress,
                SIM_CHIPCTL_CLKOUTEN_MASK32, SIM_CHIPCTL_CLKOUT_DISABLE_U32);

    /* Configure SIM_CHIPCTL clock settings (TRACECLK_SEL, CLKOUTEN, CLKOUTDIV, CLKOUT_SEL) */
    /* Masking with 0x00000FF0 (bit 4->11) */
    REG_RMW32(pSIMClockConfigPtr->pMcu_SIM_ChipSelectionConfig->pMcu_SIM_ChipSelectionRegisterConfig->u32PeripheralAdress, SIM_CHIPCTL_CLOCK_MASK32,
                ((uint32)pSIMClockConfigPtr->pMcu_SIM_ChipSelectionConfig->pMcu_SIM_ChipSelectionRegisterConfig->u32PeripheralDataConfiguration & (~SIM_CHIPCTL_CLKOUTEN_MASK32)));

    /*Enable SIM_CHIPCTL_CLKOUT */
    /* Masking with (0x0x00000800U) (bit 11) to enable clock out */
    REG_WRITE32(pSIMClockConfigPtr->pMcu_SIM_ChipSelectionConfig->pMcu_SIM_ChipSelectionRegisterConfig->u32PeripheralAdress,
                ((uint32)pSIMClockConfigPtr->pMcu_SIM_ChipSelectionConfig->pMcu_SIM_ChipSelectionRegisterConfig->u32PeripheralDataConfiguration & SIM_CHIPCTL_CLKOUTEN_MASK32 ));

    /*Configure Trace Clock settings */
    /*Masking with 0x1000000F (bit 0->3, bit 28)*/
    REG_WRITE32(pSIMClockConfigPtr->pMcu_SIM_TraceClockConfig->pMcu_SIM_TraceClockRegisterConfig->u32PeripheralAdress,
                ((uint32)pSIMClockConfigPtr->pMcu_SIM_TraceClockConfig->pMcu_SIM_TraceClockRegisterConfig->u32PeripheralDataConfiguration & SIM_CLKDIV4_RWBITS_MASK32));
}

#ifdef __cplusplus
}
#endif

/** @} */
