/*
 * UART.h
 *
 *  Created on: Nov 2, 2020
 *      Author: root
 */

#ifndef UART_H_
#define UART_H_

#include "MKL25Z4.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define UART_OVERSAMPLE_RATE 	(15)
#define BUS_CLOCK 				(24e6)
#define SYS_CLOCK				(24e6)

// critical section macro functions
#define START_CRITICAL()	__disable_irq()
#define END_CRITICAL(x)	__set_PRIMASK(x)


/*
 * Initializing the UART for BAUD_RATE: 38400, Data Size: 8, Parity: None, Stop Bits: 2
 *
 * Parameters:
 *   baud_rate: uint32_t for the requested baud rate
 *
 * Returns:
 *   void
 */
void Init_UART0(uint32_t baud_rate);


/*
 * Transmits String over to UART
 *
 * Parameters:
 *   str: String to Transmit over UART
 *	 count: The Length of the String to transmit
 * Returns:
 *   void
 */
void Send_String(const void* str, size_t count);


/*
 * Receive the Data from UART to Receive Buffer to store
 *
 * Parameters:
 *   str: String to Transmit over UART
 *	 count: The Length of the String to transmit
 * Returns:
 *   void
 */
size_t Receive_String(void* str, size_t count);


/*
 * Application Mode which handles the coordination between UART and Command line interface
 *
 * Parameters:
 *   void
 * Returns:
 *   void
 */
void application_mode();

#endif /* UART_H_ */
