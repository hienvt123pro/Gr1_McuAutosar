/**
*   @file    Det.c
*   @version 1.0.4
*
*   @brief   AUTOSAR Det - module implementation
*   @details This module implements stubs for the AUTOSAR Det
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

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Det.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/


/* Variables to store last DET error */
VAR(uint8 , DET_VAR) Det_InstanceId[DET_MAX_NUMBER_OF_EVENTS];     /**< @brief DET instance ID*/
VAR(uint8 , DET_VAR) Det_ApiId[DET_MAX_NUMBER_OF_EVENTS];          /**< @brief DET API ID*/
VAR(uint8 , DET_VAR) Det_ErrorId[DET_MAX_NUMBER_OF_EVENTS];        /**< @brief DET Error ID*/
VAR(uint16, DET_VAR) Det_ModuleId[DET_MAX_NUMBER_OF_EVENTS];       /**< @brief DET module ID*/

/* Variables to store last DET runtime error */
VAR(uint8 , DET_VAR) Det_RuntimeInstanceId[DET_MAX_NUMBER_OF_EVENTS];     /**< @brief DET instance ID*/
VAR(uint8 , DET_VAR) Det_RuntimeApiId[DET_MAX_NUMBER_OF_EVENTS];          /**< @brief DET API ID*/
VAR(uint8 , DET_VAR) Det_RuntimeErrorId[DET_MAX_NUMBER_OF_EVENTS];        /**< @brief DET Error ID*/
VAR(uint16, DET_VAR) Det_RuntimeModuleId[DET_MAX_NUMBER_OF_EVENTS];       /**< @brief DET module ID*/

/* Variables to store last DET transient error */
VAR(uint8 , DET_VAR) Det_TransientInstanceId[DET_MAX_NUMBER_OF_EVENTS];     /**< @brief DET instance ID*/
VAR(uint8 , DET_VAR) Det_TransientApiId[DET_MAX_NUMBER_OF_EVENTS];          /**< @brief DET API ID*/
VAR(uint8 , DET_VAR) Det_TransientFaultId[DET_MAX_NUMBER_OF_EVENTS];        /**< @brief DET Error ID*/
VAR(uint16, DET_VAR) Det_TransientModuleId[DET_MAX_NUMBER_OF_EVENTS];       /**< @brief DET module ID*/

VAR(uint32, DET_VAR)              Det_numEventErrors;
VAR(uint32, DET_VAR)              Det_numRuntimeEventErrors;
VAR(uint32, DET_VAR)              Det_numTransientEventErrors;

VAR(uint8, DET_VAR)               Det_OverflowEvent;
VAR(uint8, DET_VAR)               Det_RuntimeOverflowEvent;
VAR(uint8, DET_VAR)               Det_TransientOverflowEvent;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* put all DET code into defined section */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*================================================================================================*/
/**
* @brief          This function initializes the DET module.
* @details        This is a function stub only. Functionality is void in this implementation
*
* @requirements   DET008
*
*/
FUNC(void, DET_CODE) Det_Init(void)
{
    
}

/*================================================================================================*/
/** 
* @brief   This function provides the service for reporting of development errors. 
* @details This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
*    
* @param[in]     ModuleId    Module ID of Calling Module
* @param[in]     InstanceId  Index of Module starting at 0
* @param[in]     ApiId       ID of API with Error
* @param[in]     ErrorId     ID of Error
*
* @requirement DET009
*/
FUNC(Std_ReturnType, DET_CODE) Det_ReportError(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) ErrorId)
{
    if(DET_MAX_NUMBER_OF_EVENTS > Det_numEventErrors )
    {
        Det_ModuleId[Det_numEventErrors] = ModuleId; 
        Det_InstanceId[Det_numEventErrors] = InstanceId;
        Det_ApiId[Det_numEventErrors] = ApiId; 
        Det_ErrorId[Det_numEventErrors] = ErrorId;
        Det_numEventErrors++;
        Det_OverflowEvent = 0U;
        if (Det_numEventErrors == DET_MAX_NUMBER_OF_EVENTS)
        {
            Det_numEventErrors = 0;
        }
    }
    else
    {
        Det_ModuleId[Det_numEventErrors-1] = ModuleId; 
        Det_InstanceId[Det_numEventErrors-1] = InstanceId;
        Det_ApiId[Det_numEventErrors-1] = ApiId; 
        Det_ErrorId[Det_numEventErrors-1] = ErrorId;
        Det_OverflowEvent = 1U;
    }
    return E_OK;
}

#if defined(ASR_REL_4_0_REV_0003)
#else
/*================================================================================================*/
/** 
* @brief   This function provides the service for reporting of runtime errors. 
* @details This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
*    
* @param[in]     ModuleId    Module ID of Calling Module
* @param[in]     InstanceId  Index of Module starting at 0
* @param[in]     ApiId       ID of API with Error
* @param[in]     ErrorId     ID of Error
*
* @requirement SWS_Det_01001
*/
FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) ErrorId)
{
    if(DET_MAX_NUMBER_OF_EVENTS > Det_numRuntimeEventErrors)
    {
        Det_RuntimeModuleId[Det_numRuntimeEventErrors] = ModuleId; 
        Det_RuntimeInstanceId[Det_numRuntimeEventErrors] = InstanceId;
        Det_RuntimeApiId[Det_numRuntimeEventErrors] = ApiId; 
        Det_RuntimeErrorId[Det_numRuntimeEventErrors] = ErrorId;
        Det_numRuntimeEventErrors++;
        Det_RuntimeOverflowEvent = 0U;
        if (Det_numRuntimeEventErrors == DET_MAX_NUMBER_OF_EVENTS)
        {
            Det_numRuntimeEventErrors =0;
        }
    }
    else
    {
        Det_RuntimeModuleId[Det_numRuntimeEventErrors-1] = ModuleId; 
        Det_RuntimeInstanceId[Det_numRuntimeEventErrors-1] = InstanceId;
        Det_RuntimeApiId[Det_numRuntimeEventErrors-1] = ApiId; 
        Det_RuntimeErrorId[Det_numRuntimeEventErrors-1] = ErrorId;
        Det_RuntimeOverflowEvent = 1U;
    }
    return E_OK;
}

/*================================================================================================*/
/** 
* @brief   This function provides the service for reporting of transient errors. 
* @details This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
*    
* @param[in]     ModuleId    Module ID of Calling Module
* @param[in]     InstanceId  Index of Module starting at 0
* @param[in]     ApiId       ID of API with Error
* @param[in]     FaultId     ID of Fault
*
* @requirement SWS_Det_01001
*/
FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) FaultId)
{
    if(DET_MAX_NUMBER_OF_EVENTS > Det_numTransientEventErrors)
    {
        Det_TransientModuleId[Det_numTransientEventErrors] = ModuleId; 
        Det_TransientInstanceId[Det_numTransientEventErrors] = InstanceId;
        Det_TransientApiId[Det_numTransientEventErrors] = ApiId; 
        Det_TransientFaultId[Det_numTransientEventErrors] = FaultId;
        Det_numTransientEventErrors++;
        Det_TransientOverflowEvent = 0U;
        if (Det_numEventErrors == DET_MAX_NUMBER_OF_EVENTS)
        {
            Det_numTransientEventErrors =0;
        }
    }
    else
    {
        Det_TransientModuleId[Det_numTransientEventErrors-1] = ModuleId; 
        Det_TransientInstanceId[Det_numTransientEventErrors-1] = InstanceId;
        Det_TransientApiId[Det_numTransientEventErrors-1] = ApiId; 
        Det_TransientFaultId[Det_numTransientEventErrors-1] = FaultId;
        Det_numTransientEventErrors++;
        Det_TransientOverflowEvent = 1U;
    }
    return E_OK;
}
#endif /*if defined(ASR_REL_4_0_REV_0003)*/

/*================================================================================================*/
/** 
* @brief   This function provides the starting after the Det_Init has been called. 
* @details This is a function stub only.  Det_Init and Det_Start shall always be available. 
*          Functionality is void in this implementation
*    
* @requirement DET010   
*/
FUNC(void, DET_CODE) Det_Start(void)
{
    
}


#ifdef __cplusplus
}
#endif

/** @} */
