#include "Macros.h"
#include "Std_Types.h"
#include "Timer_interface.h"
#include <avr/interrupt.h>


void (* funcPtr) (void);
void Timer_vidInit(void (*funcPtrCpy)(void)) {
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
	CLEAR_BIT(TCCR0,6);

	TCNT0 = 192;
	SET_BIT(TIMSK,0);

	SET_BIT(SREG,7);
	funcPtr = funcPtrCpy;
}

ISR(TIMER0_OVF_vect) {
	(*funcPtr)();	
}
