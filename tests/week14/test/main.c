#include "DIO_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>

u32 u32time_var = 0;
u32 u32desiredTime = 0;
u8 u8endFlag = 0;
void Timer_vidDelayMicroSec(u32);
void main(void) {

	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,1);

	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
	CLEAR_BIT(TCCR0,6);


	SET_BIT(TIMSK,0);

	SET_BIT(SREG,7);

	while(1) {
		TOGGLE_BIT(PORTA,0);
		Timer_vidDelayMicroSec((u32)10000);
	}

}

void Timer_vidDelayMicroSec(u32 u32timeCpy) {
	u32desiredTime = u32timeCpy/10;
	while(u8endFlag == 0) {
		continue;
	}
	u8endFlag = 0;
}

ISR(TIMER0_OVF_vect) {
	TCNT0 = 248;
	u32time_var++;
	if(u32time_var == u32desiredTime) {
		u8endFlag = 1;
		u32time_var = 0;
	}
}
