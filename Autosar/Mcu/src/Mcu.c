/**
*   @file    Mcu.c
*   @implements Mcu.c_Artifact
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - Implementation of external interface.
*   @details High level validation of the data managed to/from high level.
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
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcu.h"

/* Get the prototypes of Execute functions. */
#include "Mcu_Exe.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/**
* @brief            Local copy of the pointer to the configuration data
*/
P2CONST( Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pConfigPtr = NULL_PTR;





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
* @details          This routine initializes the MCU Driver.
*                   The intention of this function is to make the configuration setting for power
*                   down, clock and Ram sections visible within the MCU Driver.
*
* @param[in]        pConfigPtr   Pointer to configuration structure.
*
* @return           void
*
* @api
*
* @implements       Mcu_Init_Activity
*
*/
FUNC(void, MCU_CODE) Mcu_Init( P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
	/* lom com*/

	Mcu_pConfigPtr = pConfigPtr;


	Mcu_Exe_DepProsInit(Mcu_pConfigPtr->Mcu_pDepProsConfig);
	Mcu_Exe_ResetConfigInit(Mcu_pConfigPtr->Mcu_pResetConfig);


	/* lom com*/

}


