#include "dio.h"
#include "Std_Types.h"
#include "Macros.h"
#include <avr/interrupt.h>
#include <util/delay.h>
volatile u8 value = 0;
const u8 vals[9] = {0b00000000,0b00000001,0b00000011,0b00000111,0b00001111,0b00011111,0b00111111,0b01111111,0b11111111};
void main(void) {
	//Setting pin direction for LED
	Dio_vidSetPortDirection(DIO_PORTA,0b00000000);
	Dio_vidSetPortDirection(DIO_PORTB,0b11111111);

	//Setting Global Interrupt Enable
	Set_Bit(SREG,7);

	//Setting ADC Enable in ADCSRA
	Set_Bit(ADCSRA,7);

	//Setting Prescaler Selection bits in ADCSRA
	Set_Bit(ADCSRA,0);
	Set_Bit(ADCSRA,1);
	Set_Bit(ADCSRA,2);

	//Setting ADC Interrupt enable
	Set_Bit(ADCSRA,3);

	//Selecting ADC input pin in ADMUX, the first five bit
	Set_Bit(ADMUX,0);
	Set_Bit(ADMUX,1);
	Set_Bit(ADMUX,2);
	Clear_Bit(ADMUX,3);
	Clear_Bit(ADMUX,4);

	//Adjusting right	
	Set_Bit(ADMUX,5);

	//Setting Reference Channel in ADMUX
	Clear_Bit(ADMUX,7);
	Set_Bit(ADMUX,6);

	//Setting ADC Start Conversion
	Set_Bit(ADCSRA,6);
		

	while(1) {
		PORTB = value;
	}

}

ISR(ADC_vect) {

	value = ADCH;
	//Start the next conversion	
	Set_Bit(ADCSRA,6);	
}
