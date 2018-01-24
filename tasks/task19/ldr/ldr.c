#include "dio.h"
#include "Std_Types.h"
#include "Macros.h"
#include <avr/interrupt.h>
volatile u8 value = 0;
void main(void) {
	//Setting pin direction for LED
	Dio_vidSetPortDirection(DIO_PORTA,0b10000000);

	//Setting Global Interrupt Enable
	Set_Bit(SREG,7);

	//Setting ADC Enable in ADCSRA
	Set_Bit(ADCSRA,7);

	//Setting Prescaler Selection bits in ADCSRA
	Clear_Bit(ADCSRA,0);
	Set_Bit(ADCSRA,1);
	Set_Bit(ADCSRA,2);

	//Selecting ADC input pin in ADMUX, the first five bit
	Set_Bit(ADMUX,0);
	Set_Bit(ADMUX,1);
	Set_Bit(ADMUX,2);
	Clear_Bit(ADMUX,3);
	Clear_Bit(ADMUX,4);
	

	//Setting ADC Start Conversion
	Set_Bit(ADCSRA,6);
		

	while(1) {
		if (ADCH !=0 ) {
			Dio_vidSetPinValue(DIO_PORTA,7);
			_delay_ms(300);
		}
		else {
			Dio_vidSetPinValue(DIO_PORTA,7);
			_delay_ms(300);
		}
	}

}

ISR(ADC_vect) {

	value = ADCH;
	//Start the next conversion	
	Set_Bit(ADCSRA,6);	
}
