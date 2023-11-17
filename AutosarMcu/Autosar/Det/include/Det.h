/**
*   @file    Det.h
*   @version 1.0.4
*
*   @brief   AUTOSAR Det - module interface.
*   @details This file contains the functions prototypes and data types of the AUTOSAR Det.
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup DET_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : 
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
#ifndef DET_H
#define DET_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define DET_MAX_NUMBER_OF_EVENTS (uint32)8U
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* Variables to store last DET error */
extern VAR(uint8 , DET_VAR) Det_InstanceId[DET_MAX_NUMBER_OF_EVENTS];     /**< @brief DET instance ID*/
extern VAR(uint8 , DET_VAR) Det_ApiId[DET_MAX_NUMBER_OF_EVENTS];          /**< @brief DET API ID*/
extern VAR(uint8 , DET_VAR) Det_ErrorId[DET_MAX_NUMBER_OF_EVENTS];        /**< @brief DET Error ID*/
extern VAR(uint16, DET_VAR) Det_ModuleId[DET_MAX_NUMBER_OF_EVENTS];       /**< @brief DET module ID*/

 /* Variables to store last DET runtime error */
extern VAR(uint8 , DET_VAR) Det_RuntimeInstanceId[DET_MAX_NUMBER_OF_EVENTS];     /**< @brief DET instance ID*/
extern VAR(uint8 , DET_VAR) Det_RuntimeApiId[DET_MAX_NUMBER_OF_EVENTS];          /**< @brief DET API ID*/
extern VAR(uint8 , DET_VAR) Det_RuntimeErrorId[DET_MAX_NUMBER_OF_EVENTS];        /**< @brief DET Error ID*/
extern VAR(uint16, DET_VAR) Det_RuntimeModuleId[DET_MAX_NUMBER_OF_EVENTS];       /**< @brief DET module ID*/
 
 /* Variables to store last DET transient error */
extern VAR(uint8 , DET_VAR) Det_TransientInstanceId[DET_MAX_NUMBER_OF_EVENTS];     /**< @brief DET instance ID*/
extern VAR(uint8 , DET_VAR) Det_TransientApiId[DET_MAX_NUMBER_OF_EVENTS];          /**< @brief DET API ID*/
extern VAR(uint8 , DET_VAR) Det_TransientFaultId[DET_MAX_NUMBER_OF_EVENTS];        /**< @brief DET Error ID*/
extern VAR(uint16, DET_VAR) Det_TransientModuleId[DET_MAX_NUMBER_OF_EVENTS];       /**< @brief DET module ID*/
 
extern VAR(uint32, DET_VAR)              Det_numEventErrors;
extern VAR(uint32, DET_VAR)              Det_numRuntimeEventErrors;
extern VAR(uint32, DET_VAR)              Det_numTransientEventErrors;
 
extern VAR(uint8, DET_VAR)               Det_OverflowEvent;
extern VAR(uint8, DET_VAR)               Det_RuntimeOverflowEvent;
extern VAR(uint8, DET_VAR)               Det_TransientOverflowEvent;


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
FUNC(void, DET_CODE) Det_Init(void);
FUNC(Std_ReturnType, DET_CODE) Det_ReportError(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) ErrorId);
#if defined(ASR_REL_4_0_REV_0003)
#else
FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) ErrorId);
FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) FaultId);
#endif /*if defined(ASR_REL_4_0_REV_0003)*/
FUNC(void, DET_CODE) Det_Start(void);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef DET_H */

/** @} */
