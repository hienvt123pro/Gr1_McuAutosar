/*
 * uart.h
 *
 *  Created on: Nov 17, 2023
 *      Author: hieng
 */

#ifndef UART_H_
#define UART_H_

#include "S32K144.h"

void LPUART1_Init(void);
void LPUART1_TransmitChar(char TransmitData);
void LPUART1_TransmitString(char TransmitString[]);

#endif /* UART_H_ */
