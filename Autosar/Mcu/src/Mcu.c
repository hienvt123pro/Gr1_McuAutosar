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
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

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

static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckNull(P2CONST( Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);

static FUNC(void, MCU_CODE) Mcu_CheckExit(VAR(Std_ReturnType, AUTOMATIC) retStatus, VAR(uint8, AUTOMATIC) u8McuServiceID);

static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckInitClock(VAR(Mcu_ClockType, AUTOMATIC) ClockSetting);

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckDistributePllClock(VAR( void, AUTOMATIC));
#endif /* (MCU_NO_PLL == STD_OFF) */
#endif /*(MCU_INIT_CLOCK == STD_ON)*/

static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckInitRamSection(VAR( Mcu_RamSectionType, AUTOMATIC) RamSection);

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
			(void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, (uint8)u8McuServiceID, MCU_E_ALLREADY_INITIALIZED);
		}
	}
	else
	{
		/* Check if Mcu_Init was not called */
		if (MCU_UNINIT == gu8Mcu_Status)
		{
			u8Status = (Std_ReturnType)E_NOT_OK;
		    (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, (uint8)u8McuServiceID, MCU_E_UNINIT);
		}
	}
    return (Std_ReturnType) u8Status;
}

/**
* @brief Mcu_CheckPostBuild - check if configuration pointer is initialized with value
* @implements Mcu_CheckPostBuild_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckNull(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Status = (Std_ReturnType)E_OK;
    /* Check if pConfigPtr is null or not */
    if (NULL_PTR == pConfigPtr)
    {
        /* If pConfigPtr is null then Mcu_init is failed to init */
    	u8Status = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError ( (uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INIT_ID, MCU_E_INIT_FAILED);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

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
	VAR(Std_ReturnType, AUTOMATIC) u8Status = (Std_ReturnType)E_OK;
    if (ClockSetting >= (Mcu_pConfigPtr->Mcu_NumClkConfigs))
    {
    	u8Status = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITCLOCK_ID, MCU_E_PARAM_CLOCK);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    }

    return (Std_ReturnType)u8Status;
}

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
/**
* @brief Mcu_CheckDistributePllClock - checks for Mcu_DistributePllClock
* @implements Mcu_CheckDistributePllClock_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckDistributePllClock( VAR( void, AUTOMATIC))
{
   VAR(Std_ReturnType, AUTOMATIC) u8Status = (Std_ReturnType)E_OK;
    if (MCU_PLL_LOCKED != (Mcu_PllStatusType)Mcu_Exe_GetPllStatus())
    {
        u8Status = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_DISTRIBUTEPLLCLOCK_ID, MCU_E_PLL_NOT_LOCKED);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    }

    return (Std_ReturnType) u8Status;
}
#endif /* (MCU_NO_PLL == STD_OFF) */
#endif /*(MCU_INIT_CLOCK == STD_ON)*/

/**
* @brief Mcu_CheckInitRamSection - checks for Mcu_InitRamSection
* @implements Mcu_CheckInitRamSection_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckInitRamSection(VAR(Mcu_RamSectionType, AUTOMATIC) RamSection)
{
	/*Check status variable*/
	VAR(Std_ReturnType, AUTOMATIC) u8Status = (Std_ReturnType)E_OK;

	/*Check number of Ram Sections*/
	if (RamSection >= (Mcu_pConfigPtr->Mcu_NumRamConfigs))
    {
        u8Status = (Std_ReturnType)E_NOT_OK;
	}
	else {
		/* Check if Ram memory configuration is valid. */
        if ( NULL_PTR == Mcu_pConfigPtr->Mcu_apRamConfig)
        {
            u8Status = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_ID, MCU_E_PARAM_RAMSECTION);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
		}
		/* Check if Ram write size is valid. */
        else if (
                    ( ((*Mcu_pConfigPtr->Mcu_apRamConfig)[RamSection]).u32Mcu_RamWriteSize != (Mcu_RamWriteSizeType)1U ) &&
                    ( ((*Mcu_pConfigPtr->Mcu_apRamConfig)[RamSection]).u32Mcu_RamWriteSize != (Mcu_RamWriteSizeType)2U ) &&
                    ( ((*Mcu_pConfigPtr->Mcu_apRamConfig)[RamSection]).u32Mcu_RamWriteSize != (Mcu_RamWriteSizeType)4U ) &&
                    ( ((*Mcu_pConfigPtr->Mcu_apRamConfig)[RamSection]).u32Mcu_RamWriteSize != (Mcu_RamWriteSizeType)8U )
                )
        {
            u8Status = (Std_ReturnType)E_NOT_OK;
            (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_ID, MCU_E_PARAM_RAMSECTION);
        }
	}
	return (Std_ReturnType) u8Status;
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
FUNC(void, MCU_CODE) Mcu_Init(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
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
		u8checkStatus = Mcu_CheckNull(Mcu_pConfigPtr);
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

/**
* @brief            This service initializes the RAM section wise.
* @details          This service initializes the RAM section wise.
*
* @param[in]        RamSection			unsigned 32 bit variable
*
* @return           Std_ReturnType		CheckRamStatus
*
*/
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitRamSection(VAR(Mcu_RamSectionType, AUTOMATIC) RamSection)
{
	/*Init check ram status*/
	VAR(Std_ReturnType, AUTOMATIC) CheckRamStatus = (Std_ReturnType)E_NOT_OK;

	/* Variable for index of RAM sections. */
    VAR(Mcu_RamIndexType, AUTOMATIC) RamIndex;

    /* Limitation of Ram Index variable. */
    VAR(Mcu_RamSizeType, AUTOMATIC) RamIndexLimit;

    /* Pointer to RAM configuration: base address, size, default value, write size. */
    P2CONST(Mcu_RamConfigType, AUTOMATIC, MCU_APPL_CONST) pRamConfigPtr;

	/* Check status of Ram Section if it is called */
	if ((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckEntry(MCU_INITRAMSECTION_ID)) {

		if ((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckInitRamSection(RamSection)) {

			CheckRamStatus = (Std_ReturnType)E_OK;

			/* Get Ram settings from the configuration structure. */
			pRamConfigPtr = &(*Mcu_pConfigPtr->Mcu_apRamConfig)[RamSection];

			/* Get number of Ram Index */
			RamIndexLimit = (Mcu_RamSizeType)((pRamConfigPtr->u32Mcu_RamSize)/(pRamConfigPtr->u32Mcu_RamWriteSize));

			for (RamIndex = (uint32)0UL; ((RamIndex < RamIndexLimit) && ((Std_ReturnType)E_OK == CheckRamStatus)); RamIndex++)
				{
					switch (pRamConfigPtr->u32Mcu_RamWriteSize)
					{
						case (Mcu_RamWriteSizeType)1U:
							/*Assign default value: 1 byte*/
							( *((uint8 (*)[1U]) (pRamConfigPtr->pu8Mcu_RamBaseAddr)) )[RamIndex]  = (uint8) pRamConfigPtr->u64Mcu_RamDefaultValue;
							break;

						case (Mcu_RamWriteSizeType)2U:
							/*Assign default value: 2 byte*/
							( *((uint16 (*)[1U]) (pRamConfigPtr->pu8Mcu_RamBaseAddr)) )[RamIndex] = (uint16) pRamConfigPtr->u64Mcu_RamDefaultValue;
							break;

						case (Mcu_RamWriteSizeType)4U:
							/*Assign default value: 4 byte*/
							( *((uint32 (*)[1U]) (pRamConfigPtr->pu8Mcu_RamBaseAddr)) )[RamIndex] = (uint32) pRamConfigPtr->u64Mcu_RamDefaultValue;
							break;

						case (Mcu_RamWriteSizeType)8U:
							/*Assign default value: 8 byte*/
							( *((uint64 (*)[1U]) (pRamConfigPtr->pu8Mcu_RamBaseAddr)) )[RamIndex] = (uint64) pRamConfigPtr->u64Mcu_RamDefaultValue;
							break;

						default:
							CheckRamStatus = (Std_ReturnType)E_NOT_OK;
							break;
					}
				}

			if ((Std_ReturnType)E_OK == CheckRamStatus)
			{
				/* Check if RAM was initialized correctly. */
				for (RamIndex = (uint32 )0UL; ((RamIndex < RamIndexLimit) && ((Std_ReturnType)E_OK == CheckRamStatus)); RamIndex++)
				{
					switch (pRamConfigPtr->u32Mcu_RamSize)
					{
						case (Mcu_RamWriteSizeType)1U:
							/*Check Ram Status for value of 1 byte*/
							if ( (uint8) pRamConfigPtr->u64Mcu_RamDefaultValue  != ( *((uint8 (*)[1U]) (pRamConfigPtr->pu8Mcu_RamBaseAddr)) )[RamIndex] )
							{
								CheckRamStatus = (Std_ReturnType)E_NOT_OK;
							}
							break;

						case (Mcu_RamWriteSizeType)2U:
							/*Check Ram Status for value of 2 byte*/
							if ( (uint16) pRamConfigPtr->u64Mcu_RamDefaultValue != ( *((uint16 (*)[1U]) (pRamConfigPtr->pu8Mcu_RamBaseAddr)) )[RamIndex] )
							{
								CheckRamStatus = (Std_ReturnType)E_NOT_OK;
							}
							break;

						case (Mcu_RamWriteSizeType)4U:
							/*Check Ram Status for value of 4 byte*/
							if ( (uint32) pRamConfigPtr->u64Mcu_RamDefaultValue != ( *((uint32 (*)[1U]) (pRamConfigPtr->pu8Mcu_RamBaseAddr)) )[RamIndex] )
							{
								CheckRamStatus = (Std_ReturnType)E_NOT_OK;
							}
							break;

						case (Mcu_RamWriteSizeType)8U:
							/*Check Ram Status for value of 8 byte*/
							if ( (uint64) pRamConfigPtr->u64Mcu_RamDefaultValue != ( *((uint64 (*)[1U]) (pRamConfigPtr->pu8Mcu_RamBaseAddr)) )[RamIndex] )
							{
								CheckRamStatus = (Std_ReturnType)E_NOT_OK;
							}
							break;

						default:
							CheckRamStatus = (Std_ReturnType)E_NOT_OK;
							break;
					}
				}
			}
		}
	}
	return (Std_ReturnType)CheckRamStatus;
}


#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
/**
* @brief            This function activates the PLL clock to the MCU clock distribution.
* @details          Function completes the PLL configuration and then activates the PLL clock to
*                       MCU. If the MCU_NO_PLL is TRUE the Mcu_DistributePllClock has to be
*                       disabled.
*                   The function will not distribute the PLL clock if the driver state does not
*                       allow it, or the PLL is not stable.
*
* @return           Std_ReturnType
* @retval           E_OK        Command has been accepted.
* @retval           E_NOT_OK    Command has not been accepted.
*
* @api
*
* @implements Mcu_DistributePllClock_Activity
*
*/
FUNC(Std_ReturnType, MCU_CODE) Mcu_DistributePllClock(VAR(void, AUTOMATIC))
{
	VAR(Std_ReturnType, AUTOMATIC) PllStatus = (Std_ReturnType)E_NOT_OK;

	if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckEntry(MCU_DISTRIBUTEPLLCLOCK_ID))
	{
        if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckDistributePllClock())
        {
            /* Set the PLL as System Clock if it is locked and enabled by the current mode.
            If the PLL0 is already selected as system clock, then this function will return without
            doing anything. */
            Mcu_Exe_DistributePllClock();
            PllStatus = (Std_ReturnType)E_OK;
        }
		Mcu_CheckExit((Std_ReturnType)E_OK, MCU_DISTRIBUTEPLLCLOCK_ID);
	}
	return (Std_ReturnType)PllStatus;
}
#endif /* (MCU_NO_PLL == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/**
* @brief            This function returns the lock status of the PLL.
* @details          The user takes care that the PLL is locked by executing Mcu_GetPllStatus.
*                       If the MCU_NO_PLL is TRUE the MCU_GetPllStatus has to return
*                       MCU_PLL_STATUS_UNDEFINED.
*                   It will also return MCU_PLL_STATUS_UNDEFINED if the driver state was invalid
*
* @return           Provides the lock status of the PLL.
* @retval           MCU_PLL_STATUS_UNDEFINED    PLL Status is unknown.
* @retval           MCU_PLL_LOCKED              PLL is locked.
* @retval           MCU_PLL_UNLOCKED            PLL is unlocked.
*
* @api
*
* @implements Mcu_GetPllStatus_Activity
*
*/
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus(VAR(void, AUTOMATIC))
{
	VAR(Mcu_PllStatusType, AUTOMATIC) ePllStatus = MCU_PLL_STATUS_UNDEFINED;
	if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckEntry(MCU_GETPLLSTATUS_ID))
	{
		#if (MCU_NO_PLL == STD_OFF)
			/* if the PLL is not used in the configuration return MCU_PLL_STATUS_UNDEFINED */
			/* Get status of the PLL (if enabled in current mode).
			   At this point the return value can be only MCU_PLL_LOCKED or MCU_PLL_UNLOCKED. */
			ePllStatus = Mcu_Exe_GetPllStatus();
		#endif /* (MCU_NO_PLL == STD_OFF) */
		Mcu_CheckExit((Std_ReturnType)E_OK ,MCU_GETPLLSTATUS_ID);
	}
	return (Mcu_PllStatusType)ePllStatus;
}

#ifdef __cplusplus
}
#endif

/** @} */
