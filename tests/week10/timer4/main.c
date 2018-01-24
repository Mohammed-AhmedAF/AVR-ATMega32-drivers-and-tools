#include "dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include <avr/interrupt.h>
volatile u8 count = 0;

void main(void) {
	Dio_vidSetPortDirection(DIO_PORTA,0b10000000);

	//enabling global interrupt
	Set_Bit(SREG,7);

	//setting prescaler in TCCR (Timer/Counter Control Register)
	Set_Bit(TCCR0,0);
	Clear_Bit(TCCR0,1);
	Set_Bit(TCCR0,2);

	//Setting the Timer Interrupt Enable in TIMSK
	Set_Bit(TIMSK,0);

	while(1) {
		if (count == 30) {
			count = 0;
			Toggle_Bit(PORTA,7);
		}
	}

}

ISR(TIMER0_OVF_vect) {
	count++;
}
