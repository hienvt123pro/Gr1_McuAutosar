/*
 * uart.c
 *
 *  Created on: Nov 17, 2023
 *      Author: hieng
 */

#include "uart.h"

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
