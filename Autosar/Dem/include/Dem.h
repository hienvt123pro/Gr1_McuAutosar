/**
*   @file    Dem.h
*   @version 1.0.4
*
*   @brief   AUTOSAR Dem - module interface
*   @details This file contains the functions prototypes and data types of the AUTOSAR Dem.
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup DEM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : 
*   Dependencies         : 
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
#ifndef DEM_H
#define DEM_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Dem_Types.h"  

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define DEM_VENDOR_ID        43
#define DEM_MODULE_ID        54
#define DEM_AR_RELEASE_MAJOR_VERSION        4
#define DEM_AR_RELEASE_MINOR_VERSION        3
#define DEM_AR_RELEASE_REVISION_VERSION     1
#define DEM_SW_MAJOR_VERSION 1
#define DEM_SW_MINOR_VERSION 0
#define DEM_SW_PATCH_VERSION 4
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Max length value of extended data kept by Dem when Dem_ReportErrorStatusPreExtData() API is called */
#define DEM_MAX_EXTENDED_DATA_LENGTH_U8         (uint8)(100U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern VAR(Dem_EventIdType    , DEM_VAR) Dem_EventId[256];      /**< @brief DEM event ID*/
extern VAR(Dem_EventStatusType, DEM_VAR) Dem_EventStatus[256];  /**< @brief DEM event status*/
extern VAR(Dem_EventStatusType, DEM_VAR) Dem_au8ExtendedData[DEM_MAX_EXTENDED_DATA_LENGTH_U8];  /**< @brief DEM event status*/
extern VAR(uint8, DEM_VAR)               Dem_OverflowEvent; /**< @brief DEM Overflow Event*/
 
extern VAR(uint32, DEM_VAR)              Dem_numEventErrors;  /**< @brief DEM event number of errors*/
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(VAR(Dem_EventIdType, AUTOMATIC) EventId, VAR(Dem_EventStatusType, AUTOMATIC) EventStatus);
FUNC(Std_ReturnType, DEM_CODE) Dem_ReportErrorStatusPreExtData(VAR(Dem_EventIdType, AUTOMATIC) Dem_EventIdRaw,
            VAR(Dem_EventStatusType, AUTOMATIC) Dem_EventStatusRaw,
            CONSTP2CONST(uint8, DEM_CONST, DEM_APPL_CONST) Dem_pui8_PreExtData,
            VAR(uint8, AUTOMATIC) Dem_PreExtDataSize);
             
            
#ifdef __cplusplus
}
#endif

#endif /* #ifndef DEM_H */
