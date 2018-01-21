/*
The purpose of this program is to illustrate the fact that when
AVR returns from an interrupt to the main program it will always execute one
istruction from the main program before any pending interrupt could be served.
*/
#include "dio.h"
#include <util/delay.h>
#include "Std_Types.h"
#include "Macros.h"
#include <avr/interrupt.h>

void LED_vidLightLED();

void main(void) {

	Dio_vidSetPortDirection(DIO_PORTA,0b00000011);	//Setting port direction for leds
	Dio_vidSetPortDirection(DIO_PORTD,0b00000000); //PD2 set as input

	
	//Setting the interrupt sense control bits in MCUCR
	//Any logical change on INTO will generate an interrupt request
	Clear_Bit(MCUCR,0);
	Clear_Bit(MCUCR,1);

	//Setting the external interupt request enable int GICR
	Set_Bit(GICR,6);

	//Setting the GIE bit in SREG
	Set_Bit(SREG,7);


	while(1) {
		//	LED_vidLightLED();	
	}
}
void LED_vidLightLED() {
	Clear_Bit(PORTA,1);
	_delay_ms(1000);
}
ISR(INT0_vect) {
	Toggle_Bit(PORTA,1);
	_delay_ms(500);
}
