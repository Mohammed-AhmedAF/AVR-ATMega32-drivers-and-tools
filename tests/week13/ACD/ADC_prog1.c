#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include <avr/io.h>

void ADC_vidInit(void) {
	Set_Bit(ADCSRA,7); //enabling ADC

	//prescaler
	Clear_Bit(ADCSRA,0);
	Set_Bit(ADCSRA,1);
	Set_Bit(ADCSRA,2);

	//Setting flag = 1 to get it cleared
	Set_Bit(ADCSRA,4);

	//Reference selection bits
	Clear_Bit(ADMUX,7);
	Set_Bit(ADMUX,6);

	//setting Left adjust
	Set_Bit(ADMUX,5);

	//Setting input channels
	Clear_Bit(ADMUX,4);
	Clear_Bit(ADMUX,3);
	Clear_Bit(ADMUX,2);
	Set_Bit(ADMUX,1);
	Set_Bit(ADMUX,0);
}

void ADC_vidInit_1(u8prescalerCpy,u8leftAdjustCpy,u8ADMUXselectCpy) {
	Set_Bit(ADCSRA,7);

	//Prescaler
	/switch(u8PrescalerCpy) {
		case 2:
			SET_BIT(ADCSRA,0);
			CLEAR_BIT(ADCSRA,1);
			CLEAR_BIT(ADCSRA,2);
			break;
		case 4:
			CLEAR_BIT(ADCSRA,0);
			SET_BIT(ADCSRA,1);
			CLEAR_BIT(ADCSRA,2);
			break;
		case 8:
			SET_BIT(ADCSRA,0);
			SET_BIT(ADCSRA,1);
			CLEAR_BIT(ADCSRA,2);
			break;
		case 16:
			CLEAR_BIT(ADCSRA,0);
			CLEAR_BIT(ADCSRA,1);
			SET_BIT(ADCSRA,2);
			break;
		case 32:
			SET_BIT(ADCSRA,0);
			CLEAR_BIT(ADCSRA,1);
			SET_BIT(ADCSRA,2);
			break;
		case 64:
			CLEAR_BIT(ADCSRA,0);
			SET_BIT(ADCSRA,1);
			SET_BIT(ADCSRA,2);
			break;
		case 128:
			SET_BIT(ADCSRA,0);
			SET_BIT(ADCSRA,1);
			SET_BIT(ADCSRA,2);
			break;
	}
	

	//Selecting reference
	switch(u8refSelectCpy) {
		case 0:
			CLEAR_BIT(ADMUX,7);
			CLEAR_BIT(ADMUX,6);
			break;
		case 1:
			CLEAR_BIT(ADMUX,7);
			SET_BIT(ADMUX,6);
			break;
		case 3:
			SET_BIT(ADMUX,7);
			SET_BIT(ADMUX,6);
			break;

	}

	//Set left adjust copy
	if(u8leftAdjustCpy == 1) {
		SET_BIT(ADCSRA,5);
	}

	//Set ADMUX
	switch(u8ADMUXselectCpy) {
		case 0:
			CLEAR_BIT(ADMUX,0);
			CLEAR_BIT(ADMUX,1);
			CLEAR_BIT(ADMUX,2);
			CLEAR_BIT(ADMUX,3);
			CLEAR_BIT(ADMUX,4);
			break;
		case 1:
			SET_BIT(ADMUX,0);
			CLEAR_BIT(ADMUX,1);
			CLEAR_BIT(ADMUX,2);
			CLEAR_BIT(ADMUX,3);
			CLEAR_BIT(ADMUX,4);
			break;
		case 2:
			CLEAR_BIT(ADMUX,0);
			SET_BIT(ADMUX,1);
			CLEAR_BIT(ADMUX,2);
			CLEAR_BIT(ADMUX,3);
			CLEAR_BIT(ADMUX,4);
			break;
		case 3:
			SET_BIT(ADMUX,0);
			SET_BIT(ADMUX,1);
			CLEAR_BIT(ADMUX,2);
			CLEAR_BIT(ADMUX,3);
			CLEAR_BIT(ADMUX,4);
			break;
		case 4:
			CLEAR_BIT(ADMUX,0);
			CLEAR_BIT(ADMUX,1);
			SET_BIT(ADMUX,2);
			CLEAR_BIT(ADMUX,3);
			CLEAR_BIT(ADMUX,4);
			break;
		case 5:
			SET_BIT(ADMUX,0);
			CLEAR_BIT(ADMUX,1);
			CLEAR_BIT(ADMUX,2);
			SET_BIT(ADMUX,3);
			SET_BIT(ADMUX,4);
			break;
		case 6:
			CLEAR_BIT(ADMUX,0);
			SET_BIT(ADMUX,1);
			SET_BIT(ADMUX,2);
			CLEAR_BIT(ADMUX,3);
			CLEAR_BIT(ADMUX,4);
			break;
		case 7:
			SET_BIT(ADMUX,0);
			SET_BIT(ADMUX,1);
			SET_BIT(ADMUX,2);
			CLEAR_BIT(ADMUX,3);
			CLEAR_BIT(ADMUX,4);
			break;
		default:
			CLEAR_BIT(ADMUX,0);
			CLEAR_BIT(ADMUX,1);
			SET_BIT(ADMUX,2);
			CLEAR_BIT(ADMUX,3);
			CLEAR_BIT(ADMUX,4);
	}

}

u8 ADC_u8GetValue(void) {
	Set_Bit(ADCSRA,6);
	while(GET_BIT(ADCSRA,4)==0) {
		Set_Bit(ADCSRA,4);
	}
	return ADCH;
}
