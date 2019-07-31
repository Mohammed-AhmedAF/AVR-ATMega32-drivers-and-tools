/*
 * SETTINGS_interface.h
 * Purpose: To be used as a holder of various macros that define certain
	    configurations of various microcontroller peripherals.
 * Created: 5/16/2019 11:14:43 AM
 */ 


#ifndef _SETTINGS_INTERFACE_H_
#define _SETTINGS_INTERFACE_H_

/*Macro key that will change various variables used throughout the application*/
/*A prescaler of 8 for 8 MHz F_CPU is the combination that 
yields readings with low error margins.
*/
#define ST_PRESCALER_8

/*Uncomment macro for the microcontroller used*/
//#define ST_MC_ATMEGA128
#define ST_MC_ATMEGA1632

/*Definition of various settings, only one 
*can be used at a time
*/

#define ST_UART_9600_BRH 0
#define ST_UART_9600_BRL 51

/*Switches*/

#ifdef ST_PRESCALER_256
#define ST_TIMER0_PRES TIMER0_CLK_256
#define ST_HALF_SEC 61
#define ST_SEC 122
#endif

#ifdef ST_PRESCALER_64
#define ST_TIMER0_PRES TIMER0_CLK_64
#define ST_HALF_SEC 244
#define ST_SEC 488
#endif

#ifdef ST_PRESCALER_8
	#define ST_TIMER0_PRES TIMER0_CLK_8
	#define ST_EIGHTH_SEC 488
	#define ST_HALF_SEC 1953
	#define ST_SEC 3906
#endif

#ifdef ST_PRESCALER_1
	#define ST_TIMER0_PRES TIMER0_CLK_1
	#define ST_HALF_SEC 16125
	#define ST_SEC 31250
#endif

#endif /* SETTINGS_INTERFACE_H_ */
