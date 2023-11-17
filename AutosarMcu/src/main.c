
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "S32K144.h"
#include "Mcu.h"
#include "Gpt.h"
#include "Det.h"
#include "stdio.h"
#include "Gpt_Lptmr.h"

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define SWITCH_LED(x)          (x == 0 ? 15 : ( x == 1 ? 16 : 0 ))
#define SetModeBypass_LPTMR0   (LPTMR0->PSR |= LPTMR_PSR_PBYP_MASK)

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

void LPUART1_Init(void);
void LPUART1_TransmitChar(char TransmitData);
void LPUART1_TransmitString(char TransmitString[]);
void ATF_McuReadError(void);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

void LPUART1_Init(void){
	/* Init PCC for LPUART1, PORTC */
	PCC->PCCn[PCC_LPUART1_INDEX] |= (3u << 24u);
	PCC->PCCn[PCC_LPUART1_INDEX] |= (1u << 30u);
	PCC->PCCn[PCC_PORTC_INDEX ] |= PCC_PCCn_CGC_MASK;

	/*Enable FIRC clock for LPUART1*/
	SCG->FIRCDIV = ((1u << 8) | (1u << 0));		/*Clock divider distribute 1 and 2*/
	SCG->FIRCCSR |= (1u << 0u);				    /*Clock Enable*/
	while(!(SCG->FIRCCSR & (1U << 24)));		/*Wait to confirm status*/

	/*Config ALT function for LPUART1 module*/
	PORTC->PCR[6]|=PORT_PCR_MUX(2);	       /* Port C6: MUX = ALT2, UART1 TX */
	PORTC->PCR[7]|=PORT_PCR_MUX(2);        /* Port C7: MUX = ALT2, UART1 RX */

	/*Config baudrate for LPUART1*/
	LPUART1->BAUD = (312u << 0);           /*Baud rate = baud clock / ((OSR+1) * SBR)*/
	LPUART1->BAUD |= ((16u - 1u) << 24);   /*Oversampling ratio*/
	LPUART1->BAUD |= (0U << 13);	       /*Setting one stop bit - config 1U if want 2 stop bit*/
	LPUART1->CTRL |= ( 1u << 18);	       /*Enable Receiver*/
	LPUART1->CTRL |= ( 1u << 19);	       /*Enable Transmiter*/
}

void LPUART1_TransmitChar(char TransmitData) {
	while (!(LPUART1->STAT & (1U << 23)));	/*Wait until the buffer is empty*/
	LPUART1->DATA = TransmitData;				/*Send data*/
}

void LPUART1_TransmitString(char TransmitString[]){
	int i = 0;
	while (TransmitString[i] != '\0'){
		LPUART1_TransmitChar(TransmitString[i]);
		i++;
	}
}

void ATF_McuReadError(void)
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
		sprintf(data, "Mcu_init() Error: %d\r\n", Error_Counter[MCU_INIT_ID]);
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

int main(void) {
	/*------------MCU AUTOSAR----------------*/
	Mcu_Init(&Mcu_Config);
	Mcu_InitRamSection(McuRamSection_0);
	Mcu_InitRamSection(McuRamSection_1);
	Mcu_InitClock(McuClockSettingConfig_0);
	ePllStatus = Mcu_GetPllStatus();
	Mcu_DistributePllClock();

	/*Auto test mechanism for Mcu module*/
	ATF_McuReadError();

	/*---------------------------------------*/

	/*---------GPT test for MCU API----------*/
	Gpt_Init(&Gpt_Config);
	SetModeBypass_LPTMR0;
	Gpt_StartTimer(LPTMR_0_CH_0, 99);
	Gpt_EnableNotification(LPTMR_0_CH_0);
	/*---------------------------------------*/

    for (;;) {
    	Gpt_Lptmr_ProcessCommonInterrupt();
    }

    return 0;
}

void Gpt_Notification(void) {
	g_count++;
}
