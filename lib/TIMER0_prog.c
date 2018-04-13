/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 */

#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void TIMER0_vidInit(u8 u8WGMCpy, u8 u8COMCpy, u8 u8ClkCpy) {
	//Configuration Wave Generation Mode
	if (u8WGMCpy == TIMER0_WGM_NORMAL) {
		CLEAR_BIT(TCCR0,6);
		CLEAR_BIT(TCCR0,3);
	}
	if (u8WGMCpy == TIMER0_WGM_CTC) {
		SET_BIT(TCCR0,6);
		CLEAR_BIT(TCCR0,3);
	}
	if (u8WGMCpy == TIMER0_WGM_PWM) {
		CLEAR_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
	}
	if (u8WGMCpy == TIMER0_WGM_FPWM) {
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
	}
	//Configuring Compare Output Mode
	if (u8COMCpy == TIMER0_COM_NORMAL) {
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);		
	}
	if (u8COMCpy == TIMER0_COM_TOGGLE) {
		CLEAR_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
	}
	if (u8COMCpy == TIMER0_COM_CLEAR) {
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
	}
	if (u8COMCpy == TIMER0_COM_SET) {
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
	}
	//Configuring Clock
	if (u8ClkCpy == TIMER0_CLK_0) {
		CLEAR_BIT(TCCR0,0);
		CLEAR_BIT(TCCR0,1);
		CLEAR_BIT(TCCR0,2);
	}
	if (u8ClkCpy == TIMER0_CLK_1) {
		SET_BIT(TCCR0,0);
		CLEAR_BIT(TCCR0,1);
		CLEAR_BIT(TCCR0,2);
	}
	if (u8ClkCpy == TIMER0_CLK_8) {
		CLEAR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLEAR_BIT(TCCR0,2);
	}
	if (u8ClkCpy == TIMER0_CLK_64) {
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLEAR_BIT(TCCR0,2);
	}
	if (u8ClkCpy == TIMER0_CLK_256) {
		CLEAR_BIT(TCCR0,0);
		CLEAR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	}
	if (u8ClkCpy == TIMER0_CLK_1024) {
		SET_BIT(TCCR0,0);
		CLEAR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	}
	if (u8ClkCpy == TIMER0_CLK_EXT_F) {
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLEAR_BIT(TCCR0,2);
	}
	if (u8ClkCpy == TIMER0_CLK_EXT_R) {
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	}
}

void TIMER0_vidSetTCRegister(u8 u8TCNTCpy) {
	TCNT0 = u8TCNTCpy;
}

void TIMER0_vidSetOCRegister(u8 u8OCRCpy) {
	OCR0 = u8OCRCpy;
}
