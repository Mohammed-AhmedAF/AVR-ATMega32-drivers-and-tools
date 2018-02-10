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

	Clear_Bit(ADMUX,4);
	Clear_Bit(ADMUX,3);
	Clear_Bit(ADMUX,2);
	Set_Bit(ADMUX,1);
	Set_Bit(ADMUX,0);
}

u8 ADC_u8GetValue(void) {
	Set_Bit(ADCSRA,6);
	while(GET_BIT(ADCSRA,4)==0) {
		Set_Bit(ADCSRA,4);
	}
	return ADCH;
}
