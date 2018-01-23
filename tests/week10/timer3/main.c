#include "dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include <avr/interrupt.h>

volatile u8 count = 0;

void main(void) {
	Dio_vidSetPortDirection(DIO_PORTA,0B10000000);
	

	//Setting global interrupt
	Set_Bit(SREG,7);

	//Setting prescaler in TCCR0
	Set_Bit(TCCR0,2);
	Clear_Bit(TCCR0,1);
	Set_Bit(TCCR0,0);

	//Setting Timer Interrupt Mask in TIMSK
	Set_Bit(TIMSK,0);

	while(1) {
		if (count == 30) {
			Toggle_Bit(PORTA,7);
			count = 0;
		}
	}

	
}

ISR (TIMER0_OVF_vect) {
	count++;
}
