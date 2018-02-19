#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include <avr/interrupt.h>
#include <avr/io.h>

u32 u32OVF_count = 0;
u32 u32time_var = 0;
u32 u32desiredTime = 0;
u8 u8endFlag = 0;
void Timer_vidInit(void) {


	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
	CLEAR_BIT(TCCR0,6);
	CLEAR_BIT(TCCR0,7);

	SET_BIT(SREG,7);
}

void Timer_vidDelayMilliSec(void) {

	while(u8endFlag == 0) {
		continue;
	}
}

ISR(TIMER0_OVF_vect) {
	u32OVF_count++;
	if (
}

