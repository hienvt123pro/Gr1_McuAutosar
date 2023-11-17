/**
*   @file    Mcu_PCC.c
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - Peripheral Clock Control functions implementation.
*   @details Specific functions for PCC configuration and control.
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
* @brief            This function will configure clock for the peripherals.
* @details          This function will configure clock for the peripherals.
*                   Called by:
*                       - Mcu_Exe_InitClock()
*
* @param[in]        pConfigPtr   Pointer to PCC configuration structure
*                   (member of 'Mcu_ConfigType' struct).
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_PCC_Init(P2CONST(Mcu_PCC_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{

    VAR(uint32, AUTOMATIC) u32Counter;
    VAR(uint32, AUTOMATIC) u8PeripheralIsPresent;

    for (u32Counter = (uint32)0u; u32Counter < (uint32)(pConfigPtr->Mcu_NoPeripheralClockSetting); u32Counter++)
    {
        /*Read the number of periphals are present*/
        u8PeripheralIsPresent = REG_READ32((*pConfigPtr->pMcu_PCC_RegisterConfig)[u32Counter].u32PeripheralAdress) & \
        PCC_PR_MASK32;

        if (PCC_PERIPHERAL_IS_PRESENT_U32 == u8PeripheralIsPresent)
        {
            if(PCC_PCS_UNAVAILABLE_U32 != ((*pConfigPtr->pMcu_PCC_RegisterConfig)[u32Counter].u32PeripheralDataConfiguration \
             & PCC_PCS_UNAVAILABLE_U32))
            {
                /* Disable Peripheral clock first to config */
                REG_BIT_CLEAR32((*pConfigPtr->pMcu_PCC_RegisterConfig)[u32Counter].u32PeripheralAdress,PCC_CGC_MASK32);

                /* Configure all parameters */
                REG_WRITE32((*pConfigPtr->pMcu_PCC_RegisterConfig)[u32Counter].u32PeripheralAdress, \
                (*pConfigPtr->pMcu_PCC_RegisterConfig)[u32Counter].u32PeripheralDataConfiguration);
            }
            else
            {
                /*Configure all parameters */
                REG_WRITE32((*pConfigPtr->pMcu_PCC_RegisterConfig)[u32Counter].u32PeripheralAdress, \
                (*pConfigPtr->pMcu_PCC_RegisterConfig)[u32Counter].u32PeripheralDataConfiguration);
            }
        }
    }
}

#ifdef __cplusplus
}
#endif

/** @} */
