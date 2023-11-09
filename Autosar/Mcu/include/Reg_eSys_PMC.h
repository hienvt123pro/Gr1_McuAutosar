/**
*   @file    Reg_eSys_PMC.h
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - Macros for memory access.
*   @details Macros/Defines used for registry and memory read/write.
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


#ifndef REG_ESYS_PMC_H
#define REG_ESYS_PMC_H


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Reg_eSys.h"


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/***************************************************************************************************/
/***                                        PMC Registers                                        ***/
/***************************************************************************************************/

#if (IPV_PMC == IPV_PMC_03_00_01_00)
    /* PMC - Low Power Oscillator Trim Register 32 bits */
    #define PMC_LPOTRIM_ADDR32                 ((uint32)(PMC_BASEADDR + (uint32)0x00000004U)) 
    /* PMC - Low Voltage Reset Flags Register (LVRFLG)*/
    #define PMC_LVRFLG_ADDR8                  ((uint32)(PMC_BASEADDR + (uint32)0x00000003U))    
#endif


/***************************************************************************************************/
/***                                        PMC BitFields                                        ***/
/***************************************************************************************************/

#if (IPV_PMC == IPV_PMC_03_00_01_00)

    #define PMC_LVDSC1_NOT_SUPPORTED_U8        ((uint8)(0x00))
    #define PMC_LVDSC1_LVD_ENABLE_U8           ((uint8)(0x20))
    #define PMC_LVDSC1_LVD_DISABLE_U8          ((uint8)(0x00))

    #define PMC_LVDSC1_LVDRE_ENABLE_U8         ((uint8)(0x10))
    #define PMC_LVDSC1_LVDRE_DISABLE_U8        ((uint8)(0x00))

    #define PMC_LVDSC2_LVW_ENABLE_U8           ((uint8)(0x20))
    #define PMC_LVDSC2_LVW_DISABLE_U8          ((uint8)(0x00))
    
    #define PMC_LVDSC1_2_LVDACK_LVWACK_MASK32  ((uint32)(0x4040))
    #define PMC_LVDSC1_2_LVDIE_LVWIE_MASK32    ((uint32)(0x2020))
    #define PMC_LVDSC1_2_LVDF_LVWF_MASK32      ((uint32)(0x8080))
    #define PMC_LVDSC1_LVDF_MASK32             ((uint32)(0x80))
    #define PMC_LVDSC2_LVWF_MASK32             ((uint32)(0x8000))
    #define PMC_LVDSC1_LVDIE_MASK32            ((uint32)(0x20))
    #define PMC_LVDSC2_LVWIE_MASK32            ((uint32)(0x2000))
    
    #define PMC_REG_LVRFLG_MASK8               ((uint8)(0xDF))
    
    #define PMC_LVDSC1_LVDIE_MASK8             (PMC_LVDSC1_LVD_ENABLE_U8)
    #define PMC_LVDSC1_LVDF_MASK8              ((uint8)(0x80))
    #define PMC_LVDSC1_LVDACK_MASK8            ((uint8)(0x40))

    #define PMC_REG_RWBITS_MASK32              ((uint32)(0x1F832030))

    #define PMC_LVDSC1_LVDSC2_RWBITS_MASK32    ((uint32)(0x30200000))

    #define PMC_REGSC_LPO_ENABLE_U8            ((uint8)(0x00))
    #define PMC_REGSC_LPO_DISABLE_U8           ((uint8)(0x80))

    #define PMC_REGSC_BIAS_ENABLE_U8           ((uint8)(0x01))
    #define PMC_REGSC_BIAS_DISABLE_U8          ((uint8)(0x00))

    #define PMC_REGSC_CLKBIAS_DISABLE_U8       ((uint8)(0x02))
    #define PMC_REGSC_CLKBIAS_ENABLE_U8        ((uint8)(0x00))
    
    #define PMC_REGSC_LPOSTAT_MASK8            ((uint8)(0x40))
    #define PMC_REGSC_REGFPM_MASK8             ((uint8)(0x04))

    #define PMC_LPOTRIM_RWBITS_MASK8           ((uint8)(0x1F))
    /** @violates @ref Reg_eSys_PMC_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
    #define PMC_LPOTRIM_LPOTRIM_U8(value)      ((uint8)((uint8)(value) & PMC_LPOTRIM_RWBITS_MASK8))
#endif /* (IPV_PMC == IPV_PMC_03_00_01_00) */


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_PMC_H */

/** @} */
