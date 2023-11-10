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

/**
* @brief  This enumerated type contains the Mcu driver's possible states.
*/
typedef enum
{
    MCU_UNINIT = 0x0U,  /**< @brief = 0x00 The Mcu driver is not uninitialized. */
    MCU_IDLE,           /**< @brief = 0x01 The Mcu driver is currently idle. */
    MCU_BUSY            /**< @brief = 0x02 The Mcu driver is currently busy. */
} Mcu_StatusType;

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
* @brief Local copy of the pointer to the configuration data.
*/
P2CONST(Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pConfigPtr = NULL_PTR;

/**
* @brief Variable that indicated the state of the driver.
*/
static VAR(Mcu_StatusType, MCU_VAR)  gu8Mcu_Status = MCU_UNINIT;

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckEntry(VAR( uint8, AUTOMATIC) u8McuServiceID);

static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckNullPtr(P2CONST( Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);

static FUNC(void, MCU_CODE) Mcu_CheckExit(VAR(Std_ReturnType, AUTOMATIC) retStatus, VAR(uint8, AUTOMATIC) u8McuServiceID);

static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckInitClock(VAR(Mcu_ClockType, AUTOMATIC) ClockSetting);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/**
* @brief Mcu_CheckEntry - check if Mcu_Init is initialized before.
* @implements Mcu_CheckEntry_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckEntry(VAR(uint8, AUTOMATIC) u8McuServiceID)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Status = (Std_ReturnType)E_OK;

    /* Check Service ID */
	if (MCU_INIT_ID == u8McuServiceID)
	{
		/* Check if Mcu_Init was already called */
		if (MCU_UNINIT != gu8Mcu_Status)
		{
			u8Status = (Std_ReturnType)E_NOT_OK;
		}
	}
	else
	{
		/* Check if Mcu_Init was not called */
		if (MCU_UNINIT == gu8Mcu_Status)
		{
			u8Status = (Std_ReturnType)E_NOT_OK;
		}
	}
    return (Std_ReturnType) u8Status;
}

/**
* @brief Mcu_CheckPostBuild - check if configuration pointer is initialized with value
* @implements Mcu_CheckPostBuild_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckNullPtr(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Status = (Std_ReturnType)E_OK;
    /* Check if pConfigPtr is null or not */
    if (NULL_PTR == pConfigPtr)
    {
        /* If pConfigPtr is null then Mcu_init is failed to init */
    	u8Status = (Std_ReturnType)E_NOT_OK;
    }
    return (Std_ReturnType) u8Status;
}

/**
* @brief Mcu_ChecksExit - checks for invalid mode transitions
* @implements Mcu_CheckExit_Activity
*/
static FUNC(void, MCU_CODE) Mcu_CheckExit(VAR(Std_ReturnType, AUTOMATIC) u8retStatus, VAR(uint8, AUTOMATIC) u8McuServiceID)
{
	/* Check Service ID */
	if (MCU_INIT_ID == u8McuServiceID)
	{
		if ((Std_ReturnType)E_OK == (Std_ReturnType)u8retStatus)
		{
			gu8Mcu_Status = MCU_IDLE;
		}
		else
		{
			gu8Mcu_Status = MCU_UNINIT;
		}
	}
	else
	{
		gu8Mcu_Status = MCU_IDLE;
	}
}

/**
* @brief Mcu_CheckInitClock - checks for Mcu_InitClock
* @implements Mcu_CheckInitClock_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckInitClock(VAR(Mcu_ClockType, AUTOMATIC) ClockSetting)
{
	VAR(Std_ReturnType, AUTOMATIC) u8Status = (Std_ReturnType)E_NOT_OK;
    if (ClockSetting == (Mcu_pConfigPtr->Mcu_NumClkConfigs))
    {
    	u8Status = (Std_ReturnType)E_OK;
    }

    return (Std_ReturnType)u8Status;
}

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
    VAR(Std_ReturnType, AUTOMATIC) u8checkStatus;

    Mcu_pConfigPtr = pConfigPtr;

    /* Check status of mcu if it is called */
    u8checkStatus = (Std_ReturnType)Mcu_CheckEntry(MCU_INIT_ID);
    if((Std_ReturnType)E_OK == u8checkStatus)
    {
    	/* Check status is now E_OK */

		/* Post-Build is used the input parameter 'pConfigPtr' is mandatory to be different than NULL_PTR.
		 * Check the configuration. in case of error, do nothing. the Check function will report errors.
		 */
		u8checkStatus = Mcu_CheckNullPtr(Mcu_pConfigPtr);
		if((Std_ReturnType)E_OK == u8checkStatus)
		{
			Mcu_Exe_DepProsInit(Mcu_pConfigPtr->Mcu_pDepProsConfig);
			Mcu_Exe_ResetConfigInit(Mcu_pConfigPtr->Mcu_pResetConfig);
		}
		else
		{
			/* Clean the init pointer in case of an error */
			Mcu_pConfigPtr = NULL_PTR;
		}

		/* The driver was initialized, set the proper status.
		 * The below functions can only be called if Mcu checks exit function returns IDLE.
		 */
		Mcu_CheckExit(u8checkStatus, MCU_INIT_ID);
    }
}

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            MCU driver clock initialization function.
* @details          This function initializes the PLL and MCU specific clock options. The clock
*                       setting is provided from the configuration structure.
*
* @param[in]        ClockSetting   Clock setting ID from config structure to be used.
*
* @return           Command has or has not been accepted.
* @retval           E_OK        The driver state allowed the execution of the function and the
*                                   provided parameter was in range
* @retval           E_NOT_OK    The driver state did not allowed execution or the parameter was
*                                   invalid
*
* @api
*
* @implements Mcu_InitClock_Activity
*
*/
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClock(VAR(Mcu_ClockType, AUTOMATIC) ClockSetting)
{
	VAR(Std_ReturnType, AUTOMATIC) ClockStatus = (Std_ReturnType)E_NOT_OK;

	if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckEntry(MCU_INITCLOCK_ID))
	{
		/* Check if Clock configuration is valid. */
		if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckInitClock(ClockSetting))
		{
			Mcu_Exe_InitClock(&(*Mcu_pConfigPtr->Mcu_apClockConfig)[ClockSetting]);
			/* Command has been accepted. */
			ClockStatus = (Std_ReturnType)E_OK;
		}
		Mcu_CheckExit((Std_ReturnType)E_OK, MCU_INITCLOCK_ID);
	}
	return (Std_ReturnType)ClockStatus;
}
#endif /* (MCU_INIT_CLOCK == STD_ON) */
