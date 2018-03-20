#include "Macros.h"
#include "Std_Types.h"
#include "Timer_interface.h"
#include <avr/interrupt.h>
#include <avr/io.h>

void (* funcPtr) (void);
void Timer_vidInit(void (*funcPtrCpy)(void)) {
	

	SET_BIT(TCCR1B,3); //CTC
	SET_BIT(TCCR1B,0); //Setting Clk with no prescaling
	TCNT1 = 192;
	OCR1A = 255;
	SET_BIT(TIMSK,4);

	SET_BIT(SREG,7);
	funcPtr = funcPtrCpy;

	#ifdef _TIMER0_FPWM
	//Fast PWM on Timer 0
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);	

	SET_BIT(TCCR0,5);

	//Setting Clk, no prescaling
	SET_BIT(TCCR0,0);
	OCR0 = 0;
	#endif
}

ISR(TIMER1_COMPA_vect) {
	(*funcPtr)();	
}

