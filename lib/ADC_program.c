/*
 * Author: Mohamed Ahmed Abd Al-Fattah
 * Purpose: ADC driver for AVR Atmega32
 *
 *
 */

#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "ADC_private.h"
#include "ADC_interface.h"


//ADC_vidInit just used to initialize basic operation
//of ADC. Other functions are used to controll certain 
//features like interrupt and auto-triggering.
void ADC_vidInit(u8 u8RefSelectCpy, u8 u8LeftAdjustCpy, u8 u8ChannelSelect, u8 u8ClkCpy) {

	//Voltage reference selection
	if (u8RefSelectCpy == ADC_REF_AREF) {
		CLEAR_BIT(ADMUX,7);
		CLEAR_BIT(ADMUX,6);
	}
	else if (u8RefSelectCpy == ADC_REF_AVCC) {
		CLEAR_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
	}
	else if (u8RefSelectCpy == ADC_REF_RESERVED) {
		SET_BIT(ADMUX,7);
		CLEAR_BIT(ADMUX,6);
	}
	else if (u8RefSelectCpy == ADC_REF_INTERNAL) {
		SET_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
	}

	//Left adjust configuration
	if (u8LeftAdjustCpy == ADC_LEFTADJUST) {
		SET_BIT(ADMUX,5);
	}
	else if (u8LeftAdjustCpy == ADC_RIGHTADJUST) {
		CLEAR_BIT(ADMUX,5);
	}

	//Channel selection
	if (u8ChannelSelect == ADC_MUX_0) {
		DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT);
		CLEAR_BIT(ADMUX,0);
		CLEAR_BIT(ADMUX,1);
		CLEAR_BIT(ADMUX,2);
		CLEAR_BIT(ADMUX,3);
		CLEAR_BIT(ADMUX,4);
	}
	else if (u8ChannelSelect == ADC_MUX_1) {
		DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_INPUT);
		SET_BIT(ADMUX,0);
		CLEAR_BIT(ADMUX,1);
		CLEAR_BIT(ADMUX,2);
		CLEAR_BIT(ADMUX,3);
		CLEAR_BIT(ADMUX,4);
	}
	else if (u8ChannelSelect == ADC_MUX_2) {
		DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_INPUT);
		CLEAR_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		CLEAR_BIT(ADMUX,2);
		CLEAR_BIT(ADMUX,3);
		CLEAR_BIT(ADMUX,4);
	}
	else if (u8ChannelSelect == ADC_MUX_3) {
		DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN3,DIO_INPUT);
		SET_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		CLEAR_BIT(ADMUX,2);
		CLEAR_BIT(ADMUX,3);
		CLEAR_BIT(ADMUX,4);
	}
	else if (u8ChannelSelect == ADC_MUX_4) {
		DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN4,DIO_INPUT);
		CLEAR_BIT(ADMUX,0);
		CLEAR_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		CLEAR_BIT(ADMUX,3);
		CLEAR_BIT(ADMUX,4);
	}
	else if (u8ChannelSelect == ADC_MUX_5) {
		DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN5,DIO_INPUT);
		SET_BIT(ADMUX,0);
		CLEAR_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		CLEAR_BIT(ADMUX,3);
		CLEAR_BIT(ADMUX,4);
	}
	else if (u8ChannelSelect == ADC_MUX_6) {
		DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN6,DIO_INPUT);
		CLEAR_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		CLEAR_BIT(ADMUX,3);
		CLEAR_BIT(ADMUX,4);
	}
	else if (u8ChannelSelect == ADC_MUX_7) {
		DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN7,DIO_INPUT);
		SET_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		CLEAR_BIT(ADMUX,3);
		CLEAR_BIT(ADMUX,4);
	}

	//Clk configuration
	if (u8ClkCpy == ADC_CLK_2) {
		SET_BIT(ADCSRA,0);
		CLEAR_BIT(ADCSRA,1);
		CLEAR_BIT(ADCSRA,2);	
	}
	else if (u8ClkCpy == ADC_CLK_4) {
		CLEAR_BIT(ADCSRA,0);
		SET_BIT(ADCSRA,1);
		CLEAR_BIT(ADCSRA,2);
	}
	else if (u8ClkCpy == ADC_CLK_8) {
		SET_BIT(ADCSRA,0);
		SET_BIT(ADCSRA,1);
		CLEAR_BIT(ADCSRA,2);
	}
	else if (u8ClkCpy == ADC_CLK_16) {
		CLEAR_BIT(ADCSRA,0);
		CLEAR_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,2);
	}
	else if (u8ClkCpy == ADC_CLK_32) {
		SET_BIT(ADCSRA,0);
		CLEAR_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,2);
	}
	else if (u8ClkCpy == ADC_CLK_64) {
		CLEAR_BIT(ADCSRA,0);
		SET_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,2);
	}
	else if (u8ClkCpy == ADC_CLK_128) {
		SET_BIT(ADCSRA,0);
		SET_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,2);
	}

	SET_BIT(ADCSRA,7); //ADC Enable

}

u8 ADC_u8GetADCH(void) {
	return ADCH;
}

u8 ADC_u8GetValue(void) {
	ADC_vidStartConversion();
	if(GET_BIT(ADCSRA,4) == 1) {
		SET_BIT(ADCSRA,4);
	}
	return ADCH;
}


u8 ADC_u8GetADCL(void) {
	return ADCL;
}

void ADC_vidSetAutoTrigger(void) {
	SET_BIT(ADCSRA,5); // Auto trigger enable	
}

void ADC_vidStartConversion(void) {
	SET_BIT(ADCSRA,6); //Start conversion bit
}
