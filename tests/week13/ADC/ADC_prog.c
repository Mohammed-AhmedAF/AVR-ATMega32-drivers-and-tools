#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include <avr/io.h>

void ADC_vidInit(void) {
	SET_BIT(ADCSRA,7); //enabling ADC

	//prescaler
	CLEAR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);

	//Setting flag = 1 to get it cleared
	SET_BIT(ADCSRA,4);

	//Reference selection bits
	CLEAR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	
	//setting Left adjust
	SET_BIT(ADMUX,5);

	CLEAR_BIT(ADMUX,4);
	CLEAR_BIT(ADMUX,3);
	SET_BIT(ADMUX,2);
	SET_BIT(ADMUX,1);
	SET_BIT(ADMUX,0);
}

u8 ADC_u8GetValue(void) {
	SET_BIT(ADCSRA,6); //Start conversion
	while(GET_BIT(ADCSRA,4)==1) {
		SET_BIT(ADCSRA,4);
	}
	return ADCH;
}
