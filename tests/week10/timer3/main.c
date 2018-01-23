#include "dio.h"
#include "Std_Types.h"
#include "Macros.h"
#include <avr/interrupt.h>

volatile u8 count = 0;

void main(void) {

	Dio_vidSetPortDirection(DIO_PORTA,0b10000001);


	//enabling global interrupt
	Set_Bit(SREG,7);

	//Setting prescaler
	Set_Bit(TCCR0,0);
	Clear_Bit(TCCR0,1);
	Set_Bit(TCCR0,2);

	//Set Timer Enable in Timer/Counter Interrupt Mask Register
	Set_Bit(TIMSK,0);


	while(1) {
		if (count == 30) {
			if (TCNT0 == 170) {
				Toggle_Bit(PORTA,7);
				count = 0;
			}
		}
	}

}

ISR (TIMER0_OVF_vect) {
	count++;
}
