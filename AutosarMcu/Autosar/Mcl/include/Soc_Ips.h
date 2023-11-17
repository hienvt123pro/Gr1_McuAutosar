/**
*   @file    Soc_Ips.h
*   @version 1.0.4
*
*   @brief   AUTOSAR Base - IP module versions.
*   @details The IP modules versions used on ARM hardware platform and 
*            IP specific defines
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : S32K1XX
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
/** 
* @page misra_violations MISRA-C:2004 violations
* 
* @section Soc_Ips_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file 
* This comes from the order of includes in the .c file and from include dependencies. As a safe 
* approach, any file must include all its dependencies. Header files are already protected against 
* double inclusions.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused. The driver needs to use defines starting with letter E.
*/

#ifndef SOC_IPS_H
#define SOC_IPS_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** 
* @file        Soc_Ips.h
* @brief Include platform types
* @violates @ref Soc_Ips_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "../../Base/Platform_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SOC_IPS_VENDOR_ID                    43
#define SOC_IPS_MODULE_ID                    0
#define SOC_IPS_AR_RELEASE_MAJOR_VERSION     4
#define SOC_IPS_AR_RELEASE_MINOR_VERSION     3
#define SOC_IPS_AR_RELEASE_REVISION_VERSION  1
#define SOC_IPS_SW_MAJOR_VERSION             1
#define SOC_IPS_SW_MINOR_VERSION             0
#define SOC_IPS_SW_PATCH_VERSION             4

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Platform_Types.h header file are of the same Autosar version */
    #if ((SOC_IPS_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
         (SOC_IPS_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Soc_Ips.h and Platform_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/**
* @brief PMC IP Version: PMC v03.00.01.00
* @details S32K1XX IP Versions
*/
#define IPV_PMC                  (0x03000100U)


/**
* @brief FTM IP Version:  v05.00.04.00
* @details S32K1XX IP Versions
*/
#define IPV_FTM                  (0x05000400U)

/**
* @brief CMU IP Version:  v00.00.00.01
* @details S32K1XX IP Versions
*/
#define IPV_CMU                  (0x00000001U)

/**
* @brief ENET IP Version:  v03.00.00.03
* @details S32K1XX IP Versions
*/
#define IPV_ENET                 (0x03000003U)
/*==================================================================================================
*                              Software Erratas for Hardware Erratas
==================================================================================================*/
/**
* @brief Hardware errata for FMC: (e10716)
* @details e10716 RTC: Timer Alarm Flag can assert erroneously
*/
#define ERR_IPV_RTC_0001            (STD_ON)

/**
* @brief Hardware errata for FTM: (e10856)
* @details e10856 FTM: Safe state is not removed from channel outputs after fault condition ends 
* if SWOCTRL is being used to control the pin
*/
#define ERR_IPV_FTM_0002            (STD_ON)

/**
* @brief Hardware errata for IPV_SCG (E10777)
* @details IPV_SCG: e10777: Corrupted status when the system clock is switching.
*/
#define ERR_IPV_SCG_0001            (STD_ON)

/**
* @brief Hardware errata for FLEXCAN: (ERR050443)
* @details FLEXCAN: ERR050443: Receive Message Buffers may have its CODE Field corrupted if the Receive FIFO function is used in Classical CAN mode
*/
#define ERR_IPV_FLEXCAN_0017  (STD_ON)

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Enable CACHE management feature
* @details Global define to enable CACHE management at runtime
*/
#define MCAL_CACHE_RUNTIME_MNGMNT (STD_ON)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/**
* @brief User Mode feature is enabled
* @details User Mode feature - MCAL is configured to run in supervisor mode, by default.
*/

#ifdef MCAL_ENABLE_SUPERVISOR_MODE
    #undef MCAL_ENABLE_USER_MODE_SUPPORT
#endif
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif


#endif /* #ifndef SOC_IPS_H*/

/** @} */
