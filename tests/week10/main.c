#include "Std_Types.h"
#include "dio.h"
#include "Macros.h"
#include <avr/interrupt.h>
#include <util/delay.h>
void main(void) {
	Set_Bit(SREG,7);
	Set_Bit(GICR,6);
	Set_Bit(MCUCR,1);
	Clear_Bit(MCUCR,1);

	Dio_vidSetPortDirection(DIO_PORTA,0xFF);
	Dio_vidSetPortDirection(DIO_PORTD,0b00000000);
	Dio_vidSetPinValue(DIO_PORTD,2,1);
	while(1) {
		Dio_vidSetPortValue(DIO_PORTA,0b11111111);

	}
}

ISR (INT0_vect) {
	Dio_vidSetPortValue(DIO_PORTA,0x00);
	_delay_ms(1000);
}
