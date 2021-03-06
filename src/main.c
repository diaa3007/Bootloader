/*
 * main.c
 *
 *  Created on: Dec 30, 2019
 *      Author: DiaaEldeen
 */

#ifndef DEBUG
#define DEBUG
#endif

#include "UART.h"

#include "CLI.h"


uint32_t F_SysClk = 82000000;


extern volatile uint8_t newOp;

int main(){

	F_SysClk = SysCtlClockFreqSet(SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480
									| SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN, F_SysClk);
		delay_us(1);

	LEDs_EK_setup();
	UART0_init_interrupts();

	UART_put_strLine("Hello");

	command_help("");

	// Even while the application is loading and performing its duties, it 
	// should be designed so that it can accept a command to enter the boot-loader. 

	// Check valid application

	// If valid, start a timer with interrupt (0.5 sec and continue)
	// Inside the timer interrupt set a global variable jumpToApp


	// If not valid continue


	while(1){

		if(newOp){
			process_CLI_command();
		}
		// Else if jump to app jump then while(1)
		else{
			LED_EK_blink(200);
		}



	}
}



void GPIOJ_Handler(){
//	if (interruptStatus == P0)
//	{
//		GPIO_button->ICR |= P0;
//		//maybe you should read ICR to force it to clear the flag
//		LED1_ON;
//		delay_ms(1000);
//		LED1_OFF;
//
//	}
//	else if (interruptStatus == P1)
//	{
//		GPIO_button->ICR |= P1;
//		LED4_ON;
//		delay_ms(1000);
//		LED4_OFF;
//	}
//	else if (interruptStatus == (P0 | P1) )
//		GPIO_button->ICR |= P0 | P1;
//
//
//	GPIO_button->ICR |= P0 | P1;
	while(1){

	}
}



