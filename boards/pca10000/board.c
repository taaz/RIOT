/*
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     board_stm32f0discovery
 * @{
 *
 * @file        board.c
 * @brief       Board specific implementations for the STM32F0Discovery evaluation board
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * @}
 */

#include "board.h"
#include "nrf51.h"
#include "nrf_delay.h"
#include "nrf51_bitfields.h"

extern void SystemInit(void);
void leds_init(void);


void board_init(void)
{
	int receivedUART;
	char * receivedUARTstring = "\0";
	char charUART = '\0';
	int i = 0;
    /* initialize core clocks via STM-lib given function */
    SystemInit();

    /* initialize the CPU */
    cpu_init();

    /* initialize the boards LEDs */
    leds_init();

    /*initialize UART */
    uart_init_blocking(0, 38400); //UART_0 aus uart.h eigentlich

    char* output = "Hello World!\r\n";
    char outputchar = output[i++];
	while ( outputchar != '\0')
	{
		uart_write_blocking(0, outputchar);
		outputchar = output[i++];
	}
	i = 0;


    /* blink stuff */
    LED_RED_OFF;
    LED_GREEN_OFF;
    LED_BLUE_OFF;

    nrf_delay_ms(1000);
    nrf_delay_ms(1000);
    LED_RED_ON;  
    nrf_delay_ms(1000);
    LED_GREEN_ON;
    nrf_delay_ms(1000);
    LED_BLUE_ON;
    nrf_delay_ms(1000);
    LED_RED_OFF;
    LED_GREEN_OFF;
    LED_BLUE_OFF;
    while(1){
    	LED_GREEN_OFF;
    	nrf_delay_ms(500);
    	LED_GREEN_ON;
    	nrf_delay_ms(500);
    	uart_write_blocking(0, 'w');
    	receivedUART = uart_read_blocking(0,receivedUARTstring);
    	if(receivedUART){
    		charUART = receivedUARTstring[i++];
    		uart_write_blocking(0, 'm');
    		while (charUART != '\0')
    		{
    			uart_write_blocking(0, 'm');//charUART);
    			charUART = receivedUARTstring[i++];
    		}
       	 i=0;
    	}
    }
}

void delay(uint32_t microseconds){
    /* perform busy-waiting for specified number of microseconds  */
    uint32_t cycles = microseconds * 2; // factor has been found by measure
    for (int i = 0; i < cycles; i++) {
        asm("nop");
    }

}

/**
 * @brief Initialize the boards on-board RGB LED
 *
 * The LED initialization is hard-coded in this function.
 *
 * The LED channels are connected to the following pins:
 * - RED:   21
 * - GREEN: 22
 * - BLUE:  23
 */
void leds_init(void)
{
    /* set LED pins to function as output */
    NRF_GPIO->DIRSET = (LED_RED_PIN | LED_GREEN_PIN | LED_BLUE_PIN);

    /* turn all LEDs off */
    NRF_GPIO->OUTCLR = (LED_RED_PIN | LED_GREEN_PIN | LED_BLUE_PIN);
}
