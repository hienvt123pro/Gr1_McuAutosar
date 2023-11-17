/*==================================================================================================
                                        INCLUDE FILES
==================================================================================================*/
#include "S32K144.h"
#include "Mcu.h"
#include "Gpt.h"
#include "Det.h"
#include "stdio.h"
#include "uart.h"

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

#define SetModeBypassLPTMR0   (LPTMR0->PSR |= LPTMR_PSR_PBYP_MASK)

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

VAR(Mcu_PllStatusType, AUTOMATIC) ePllStatus;
volatile int g_count = 0;

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

FUNC(void, AUTOMATIC)  ATF_McuResultsError(void);
FUNC(void, AUTOMATIC)  ATF_McuTestAssert(uint8 statusTest);
FUNC(uint8, AUTOMATIC) Det_CheckError(uint16 ModuleId, uint8 InstanceId, uint8 ServiceId, uint8 ErrorId);
FUNC(void, AUTOMATIC)  Enable_NVIC(uint8 vector_number, uint8 priority);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

FUNC(void, AUTOMATIC) ATF_McuTestAssert(uint8 statusTest){
	/* Assume this function works */
}

FUNC(uint8, AUTOMATIC) Det_CheckError(uint16 ModuleId, uint8 InstanceId, uint8 ServiceId, uint8 ErrorId){
	/* Assume this function works */
	return 0;
}

FUNC(void, AUTOMATIC) ATF_McuResultsError(void)
{
	uint8_t Error_Counter[5] = {0,0,0,0,0};
	uint32_t Counter;

	LPUART1_Init();

	for ( Counter = 0U; Counter < Det_numEventErrors; Counter++)
	{
		if ((Det_ModuleId[Counter] == MCU_MODULE_ID) && (Det_InstanceId[Counter] == MCU_INSTANCE_ID))
		{
			Error_Counter[Det_ApiId[Counter]]++;
			LPUART1_TransmitString("=================Error Detected=============\r\n");
			LPUART1_TransmitString("ModuleId: MCU_MODULE_ID\r\n");
			LPUART1_TransmitString("InstanceId: MCU_INSTANCE_ID\r\n");
			if (Det_ApiId[Counter] == MCU_INIT_ID)
			{
				LPUART1_TransmitString("ApiId: MCU_INIT_ID\r\n");
			}
			else if(Det_ApiId[Counter] == MCU_INITRAMSECTION_ID)
			{
				LPUART1_TransmitString("ApiId: MCU_INITRAMSECTION_ID\r\n");
			}
			else if(Det_ApiId[Counter] == MCU_INITCLOCK_ID)
			{
				LPUART1_TransmitString("ApiId: MCU_INITCLOCK_ID\r\n");
			}
			else if(Det_ApiId[Counter] == MCU_DISTRIBUTEPLLCLOCK_ID)
			{
				LPUART1_TransmitString("ApiId: MCU_DISTRIBUTEPLLCLOCK_ID\r\n");
			}
			else if(Det_ApiId[Counter] == MCU_GETPLLSTATUS_ID)
			{
				LPUART1_TransmitString("ApiId: MCU_GETPLLSTATUS_ID\r\n");
			}

			if (Det_ErrorId[Counter] == MCU_E_PARAM_CONFIG)
			{
				LPUART1_TransmitString("ErrorId: MCU_E_PARAM_CONFIG\r\n");
			}
			else if(Det_ErrorId[Counter] == MCU_E_PARAM_CLOCK)
			{
				LPUART1_TransmitString("ErrorId: MCU_E_PARAM_CLOCK\r\n");
			}
			else if(Det_ErrorId[Counter] == MCU_E_PARAM_MODE)
			{
				LPUART1_TransmitString("ErrorId: MCU_E_PARAM_MODE\r\n");
			}
			else if(Det_ErrorId[Counter] == MCU_E_PARAM_RAMSECTION)
			{
				LPUART1_TransmitString("ErrorId: MCU_E_PARAM_RAMSECTION\r\n");
			}
			else if(Det_ErrorId[Counter] == MCU_E_PLL_NOT_LOCKED)
			{
				LPUART1_TransmitString("ErrorId: MCU_E_PLL_NOT_LOCKED\r\n");
			}
			else if(Det_ErrorId[Counter] == MCU_E_UNINIT)
			{
				LPUART1_TransmitString("ErrorId: MCU_E_UNINIT\r\n");
			}
			else if(Det_ErrorId[Counter] == MCU_E_PARAM_POINTER)
			{
				LPUART1_TransmitString("ErrorId: MCU_E_PARAM_POINTER\r\n");
			}
			else if(Det_ErrorId[Counter] == MCU_E_INIT_FAILED)
			{
				LPUART1_TransmitString("ErrorId: MCU_E_INIT_FAILED\r\n");
			}
			else if(Det_ErrorId[Counter] == MCU_E_ALLREADY_INITIALIZED)
			{
				LPUART1_TransmitString("ErrorId: MCU_E_ALLREADY_INITIALIZED\r\n");
			}
		}
	}

	char data[50];
	/* Print Number of MCU_INIT_ID errors */
	if (Error_Counter[MCU_INIT_ID] > 0)
	{
		sprintf(data, "Mcu_Init() Error: %d\r\n", Error_Counter[MCU_INIT_ID]);
		LPUART1_TransmitString(data);
	}

	/* Print Number of MCU_INITRAMSECTION_ID errors */
	if (Error_Counter[MCU_INITRAMSECTION_ID] > 0)
	{
		sprintf(data, "Mcu_InitRamSection() Error: %d\r\n", Error_Counter[MCU_INITRAMSECTION_ID]);
		LPUART1_TransmitString(data);
	}

	/* Print Number of MCU_INITCLOCK_ID errors */
	if (Error_Counter[MCU_INITCLOCK_ID] > 0)
	{
		sprintf(data, "Mcu_InitClock() Error: %d\r\n", Error_Counter[MCU_INITCLOCK_ID]);
		LPUART1_TransmitString(data);
	}

	/* Print Number of MCU_DISTRIBUTEPLLCLOCK_ID errors */
	if (Error_Counter[MCU_DISTRIBUTEPLLCLOCK_ID] > 0)
	{
		sprintf(data, "Mcu_DistributePllClock() Error: %d\r\n", Error_Counter[MCU_DISTRIBUTEPLLCLOCK_ID]);
		LPUART1_TransmitString(data);
	}

	/* Print Number of MCU_GETPLLSTATUS_ID errors */
	if (Error_Counter[MCU_GETPLLSTATUS_ID] > 0)
	{
		sprintf(data, "Mcu_GetPllStatus() Error: %d\r\n", Error_Counter[MCU_GETPLLSTATUS_ID]);
		LPUART1_TransmitString(data);
	}
}

FUNC(void, AUTOMATIC) Enable_NVIC(uint8 vector_number, uint8 priority)
{
  S32_NVIC->ISER[(uint32)(vector_number) >> 5U] = (uint32_t)(1U << ((uint32)(vector_number) & (uint32)0x1FU));
  S32_NVIC->ICPR[(uint32)(vector_number) >> 5U] = (uint32_t)(1U << ((uint32)(vector_number) & (uint32)0x1FU));
  S32_NVIC->IP[vector_number] = priority;
}

int main(void) {
	/*------------MCU AUTOSAR----------------*/
	/* Api: Mcu_Init */
	Mcu_Init(&Mcu_Config);
	/* Check whether a error MCU_E_ALLREADY_INITIALIZED was reported to Det or not */
	ATF_McuTestAssert(E_OK == Det_CheckError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INIT_ID, MCU_E_ALLREADY_INITIALIZED));
	/* Check whether a error MCU_E_INIT_FAILED was reported to Det or not */
	ATF_McuTestAssert(E_OK == Det_CheckError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INIT_ID, MCU_E_INIT_FAILED));

	/* Api: Mcu_InitRamSection */
	Mcu_InitRamSection(McuRamSection_0);
	Mcu_InitRamSection(McuRamSection_1);
	/* Check whether a error MCU_E_PARAM_RAMSECTION was reported to Det or not */
	ATF_McuTestAssert(E_OK == Det_CheckError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_ID, MCU_E_PARAM_RAMSECTION));
	/* Check whether a error MCU_E_UNINIT was reported to Det or not */
	ATF_McuTestAssert(E_OK == Det_CheckError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_ID, MCU_E_UNINIT));

	/* Api: Mcu_InitClock */
	Mcu_InitClock(McuClockSettingConfig_0);
	/* Check whether a error MCU_E_PARAM_CLOCK was reported to Det or not */
	ATF_McuTestAssert(E_OK == Det_CheckError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITCLOCK_ID, MCU_E_PARAM_CLOCK));
	/* Check whether a error MCU_E_UNINIT was reported to Det or not */
	ATF_McuTestAssert(E_OK == Det_CheckError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITCLOCK_ID, MCU_E_UNINIT));

	/* Api: Mcu_GetPllStatus */
	ePllStatus = Mcu_GetPllStatus();
	/* Check whether a error MCU_E_UNINIT was reported to Det or not */
	ATF_McuTestAssert(E_OK == Det_CheckError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETPLLSTATUS_ID, MCU_E_UNINIT));

	/* Api: Mcu_DistributePllClock */
	Mcu_DistributePllClock();
	/* Check whether a error MCU_E_PLL_NOT_LOCKED was reported to Det or not */
	ATF_McuTestAssert(E_OK == Det_CheckError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_DISTRIBUTEPLLCLOCK_ID, MCU_E_PLL_NOT_LOCKED));
	/* Check whether a error MCU_E_UNINIT was reported to Det or not */
	ATF_McuTestAssert(E_OK == Det_CheckError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_DISTRIBUTEPLLCLOCK_ID, MCU_E_UNINIT));

	/*Report auto test mechanism for Mcu module*/
	ATF_McuResultsError();
	/*---------------------------------------*/


	/*---------GPT test for MCU API----------*/
	Gpt_Init(&Gpt_Config);
	SetModeBypassLPTMR0;
	Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 99);
	Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);
	/*---------------------------------------*/

	Enable_NVIC(LPTMR0_IRQn, 0);

    for (;;) {
    	/* If time remaining equal to zero, the counter will increase 1 tick */
    	if (Gpt_GetTimeRemaining(GptConf_GptChannelConfiguration_GptChannelConfiguration_0) == 0) {
    		g_count++;

    		/* After the 5th tick, we disable the notification function call-back
    		 * and re-enale it once it reaches the target 10th time.
    		 * Stop counting after 20th time.
    		 */
    		if (g_count < 5) {
				/* do nothing here */
			}
			else if (g_count < 10) {
				Gpt_DisableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);
			}
			else if (g_count < 20) {
				Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);
			}
			else {
				Gpt_StopTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);
			}
    	}
    }

    return 0;
}

void Gpt_Notification(void) {
	char data[50];
	sprintf(data, "LPUART1 running %d tick \r\n", g_count);
	LPUART1_TransmitString(data);
}
