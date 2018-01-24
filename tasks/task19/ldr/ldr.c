#include "dio.h"
#include "Std_Types.h"
#include "Macros.h"
#include <avr/interrupt.h>

void main(void) {
	//Setting pin direction for LED
	Dio_vidSetPortDirection(DIO_PORTA,0b10000000);

	//Setting Global Interrupt Enable
	Set_Bit(SREG,7);

	//Setting ADC Enable in ADCSRA
	Set_Bit(ADCSRA,7);

	

	//Setting ADC Start Conversion
	Set_Bit(ADCSRA,6);
		


}

ISR(ADC_vect) {
		
}
