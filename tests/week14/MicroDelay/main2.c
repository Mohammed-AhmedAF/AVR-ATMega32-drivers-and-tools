#include "DIO_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>


volatile u32 u32time_var = 0;
volatile u32 u32desiredTime = 0;
volatile u8 u8endFlag = 0;
void Timer_vidDelayMicroSec(u32);
void main(void) {

	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,1);
	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN0,0);
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	SET_BIT(TCCR0,3); //enable CTC
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
	CLEAR_BIT(TCCR0,6); //enable CTC


	SET_BIT(SREG,7);

	OCR0 = 8;

	while(1) {
		TOGGLE_BIT(PORTA,0);
		Timer_vidDelayMicroSec((u32)100000);
	}

}

void Timer_vidDelayMicroSec(u32 u32timeCpy) {
	TCNT0 = 0;
	SET_BIT(TIMSK,1);
	u32desiredTime =  (u32timeCpy)/10;
	while (u32time_var != u32desiredTime) {
	}
	u32time_var = 0;
	SET_BIT(TIMSK,0);
}

ISR(TIMER0_COMP_vect) {
	u32time_var++;
}
