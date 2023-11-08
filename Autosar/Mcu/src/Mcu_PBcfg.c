/**
*   @file    Mcu_PBcfg.c
*   @implements Mcu_PBcfg.c_Artifact
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - Data structures for the Mcu driver.
*   @details Postbuild structure configurations for the driver initalization.
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
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu.h"

#include "Reg_eSys_PCC.h"
#include "Reg_eSys_PMC.h"
#include "Reg_eSys_RCM.h"
#include "Reg_eSys_SCG.h"
#include "Reg_eSys_SIM.h"
#include "Reg_eSys_SMC.h"

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL MACROS
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

/**
* @brief        Definition of MCU mode sections in the configuration structure.
* @details      Specifies the system behaviour during the selected target mode.
*               Configuration set by calling Mcu_SetMode() API.
*/
static CONST( Mcu_ModeConfigType, MCU_CONST) Mcu_Mode_ConfigPB0[1] =
{
    /* Start of Mcu_ModeConfig[0]*/
    {
        /* The ID for Power Mode configuration. */
        (uint8)0U,

        /* Power Mode */
        (Mcu_PowerModeType)MCU_RUN_MODE
    }
    /* end of Mcu_Mode_ConfigPB0[0]. */

};


#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief        Clock settings from the SIM IP.
* @details      Configures SIM_CHIPCTL[TRACECLK_SEL], SIM_CHIPCTL[CLKOUTSEL] bits and SIM_PLATGC and SIM_CLKDIV4 registers.
*               Configuration set by calling Mcu_InitClock API.
*/
static CONST( Mcu_SIM_ClockConfigType, MCU_CONST) SIM_ClockConfigPB0_0 =
{
    /* SIM_CHIPCTL settings. */
    (
        SIM_CHIPCTL_TRACECLK_CORE_CLK_U32 |
        SIM_CHIPCTL_CLKOUT_DISABLE_U32 |
        SIM_CHIPCTL_CLKOUTDIV_U32((uint32)0U) |
        SIM_CHIPCTL_CLKOUTSEL_SCG_CLKOUT_U32
    ),
    /* SIM_CLKDIV4 settings. */
    (
        SIM_DEBUG_TRACE_DIVIDER_ENABLED_U32 |
        SIM_CLKDIV4_TRACEDIV_U32((uint32)1U) |
        SIM_CLKDIV4_TRACEFRAC_0_U32
    ),
    /* SIM_PLATGC settings. */
    (
        SIM_PLATGC_EIM_CLK_ENABLE_U32 |
        SIM_PLATGC_ERM_CLK_ENABLE_U32 |
        SIM_PLATGC_DMA_CLK_ENABLE_U32 |
        SIM_PLATGC_MPU_CLK_ENABLE_U32 |
        SIM_PLATGC_MSCM_CLK_ENABLE_U32

    )
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) SOSC_ClockConfigPB0_0[MCU_NUMBER_OF_SOSC_REGISTERS_U32] =
{
    /* SCG_SOSCCFG settings. */
    {
        SCG_SOSCCFG_ADDR32,
        (
            SCG_SOSCCFG_HIGH_FREQ_RANGE_U32 |
            SCG_SOSCCFG_INTERNAL_OSCILLATOR_U32 |
            SCG_SOSCCFG_LOW_POWER_OPERATION_U32
        )
    },
    /* SCG_SOSCDIV settings. */
    {
        SCG_SOSCDIV_ADDR32,
        (
            SCG_SOSCDIV_SOSCDIV2_U32((uint32)1U) |
            SCG_SOSCDIV_SOSCDIV1_U32((uint32)1U)
        )
    },
    /* SCG_SOSCCSR settings. */
    {
        SCG_SOSCCSR_ADDR32,
        (
             SCG_SOSCCSR_SOSC_ENABLE_U32 |
             SCG_SOSCCSR_SOSCCMRE_ISR_U32 |
             SCG_SOSCCSR_SOSCCM_DIS_U32
         )
    }
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) SPLL_ClockConfigPB0_0[MCU_NUMBER_OF_SPLL_REGISTERS_U32] =
{
    /* SCG_SPLLCFG settings. */
    {
        SCG_SPLLCFG_ADDR32,
        (
            SCG_SPLLCFG_PREDIV_U32((uint32)0U) |
            SCG_SPLLCFG_MULT_U32((uint32)8U) |
            SCG_SPLLCFG_SOURCE_SOSC_U32
        )
    },
    /* SCG_SPLLDIV settings. */
    {
        SCG_SPLLDIV_ADDR32,
        (
            SCG_SPLLDIV_SPLLDIV2_U32((uint32)2U) |
            SCG_SPLLDIV_SPLLDIV1_U32((uint32)1U)
        )
    },
    /* SCG_SPLLCSR settings. */
    {
        SCG_SPLLCSR_ADDR32,
        (
             SCG_SPLLCSR_SPLL_ENABLE_U32 |
             SCG_SPLLCSR_SPLLCMRE_RESET_U32 |
             SCG_SPLLCSR_SPLLCM_ENA_U32
        )
    }
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */



#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            SCG clock configuration.
* @details          This structure contains information for SOSC, SIRC, FIRC, SPLL, ClockOut and System Clock
*
*/
/** @violates @ref Mcu_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_ClockConfigType, MCU_CONST) SCG_ClockConfigPB0_0 =
{

    /* Run Clock Config(SCG_RCCR) */
    (
        SCG_SCS_SPLL_U32 |
        SCG_DIVCORE_U32((uint32)3U) |
        SCG_DIVBUS_U32((uint32)3U) |
        SCG_DIVSLOW_U32((uint32)7U)
    ),
    /* VLPR Clock Config(SCG_VCCR) */
    (
        SCG_SCS_SIRC_U32 |
        SCG_DIVCORE_U32((uint32)7U) |
        SCG_DIVBUS_U32((uint32)0U) |
        SCG_DIVSLOW_U32((uint32)3U)
    ),
    /* High Speed Run Clock Config(SCG_HCCR) */
    (
        SCG_SCS_FIRC_U32 |
        SCG_DIVCORE_U32((uint32)0U) |
        SCG_DIVBUS_U32((uint32)0U) |
        SCG_DIVSLOW_U32((uint32)1U)
    ),


    /* SCG ClockOut Config */
    SCG_CLKOUTCNFG_CLKOUTSEL_SCG_SLOW_CLK_U32,

    /* SOSC Config */
   &SOSC_ClockConfigPB0_0,

    /* SIRC Config */

    (NULL_PTR),

    /* FIRC Config */

    (NULL_PTR),

    /* SPLL Config */
    &SPLL_ClockConfigPB0_0

};
#endif /* (MCU_INIT_CLOCK == STD_ON) */





