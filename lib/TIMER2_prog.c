#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "TIMER2_interface.h"
#include <avr/io.h>

void TIMER2_vidInit(u8 u8WGMCpy, u8 u8COMCpy, u8 u8CLKCpy) {
	if (u8WGMCpy == TIMER2_WGM_NORMAL) {
		CLEAR_BIT(TCCR2,3);
		CLEAR_BIT(TCCR2,6);
	}
	if (u8WGMCpy == TIMER2_WGM_CTC) {
		SET_BIT(TCCR2,3);
		CLEAR_BIT(TCCR2,6);
	}
	if (u8WGMCpy == TIMER2_WGM_PWM) {
		CLEAR_BIT(TCCR2,3);
		SET_BIT(TCCR2,6);
	}
	if (u8WGMCpy == TIMER2_WGM_FPWM) {
		SET_BIT(TCCR2,3);
		SET_BIT(TCCR2,6);
	}
	//Setting Compare Output Mode
	if (u8COMCpy == TIMER2_COM_NORMAL) {
		CLEAR_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);
	}
	if (u8COMCpy == TIMER2_COM_TOGGLE) {
		CLEAR_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);
	}
	if (u8COMCpy == TIMER2_COM_CLEAR) {
		SET_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);
	}
	if (u8COMCpy == TIMER2_COM_SET) {
		SET_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);
	}
	//Configuring the clock
	if(u8CLKCpy == TIMER2_CLK_NO_CLK) {
		CLEAR_BIT(TCCR2,0);	
		CLEAR_BIT(TCCR2,1);
		CLEAR_BIT(TCCR2,2);
	}
	if(u8CLKCpy == TIMER2_CLK_1) {
		SET_BIT(TCCR2,0);
		CLEAR_BIT(TCCR2,1);
		CLEAR_BIT(TCCR2,2);
	}
	if(u8CLKCpy == TIMER2_CLK_8) {
		CLEAR_BIT(TCCR2,0);
		SET_BIT(TCCR2,1);
		CLEAR_BIT(TCCR2,2);
	}
	if(u8CLKCpy == TIMER2_CLK_32) {
		SET_BIT(TCCR2,0);
		SET_BIT(TCCR2,1);
		CLEAR_BIT(TCCR2,2);
	}
	if(u8CLKCpy == TIMER2_CLK_64) {
		CLEAR_BIT(TCCR2,0);
		CLEAR_BIT(TCCR2,1);
		SET_BIT(TCCR2,2);
	}
	if(u8CLKCpy == TIMER2_CLK_128) {
		SET_BIT(TCCR2,0);
		CLEAR_BIT(TCCR2,1);
		SET_BIT(TCCR2,2);	
	}
	if(u8CLKCpy == TIMER2_CLK_256) {
		CLEAR_BIT(TCCR2,0);
		SET_BIT(TCCR2,1);
		SET_BIT(TCCR2,2);
	}
	if(u8CLKCpy == TIMER2_CLK_1024) {
		SET_BIT(TCCR2,0);
		SET_BIT(TCCR2,1);
		SET_BIT(TCCR2,2);
	}
}

void TIMER2_vidSetTCRegister(u8 u8TCNTCpy) {
	TCNT2 = u8TCNTCpy;
}

void TIMER2_vidSetOCRegister(u8 u8OCRCpy) {
	OCR2 = u8OCRCpy;
}
