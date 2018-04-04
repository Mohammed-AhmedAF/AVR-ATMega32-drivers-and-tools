#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "INTERRUPTS_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void (* ISRFunc) (void);

void INTERRUPTS_vidSetGlobalInterruptFlag(void) {
	SET_BIT(SREG,7);
}

void INTERRUPTS_vidClearGlobalInterruptFlag(void) {
	CLEAR_BIT(SREG,7);
}

//The function vidPutISR will take code that
//will be executed inside the ISR.
void INTERRUPTS_vidPutISRFunction(void (*ptrFunc) ()) {
	ISRFunc = ptrFunc;
}
//also be responsible for setting the timer/counter
//OFV or Compare flags
void INTERRUPTS_vidSetInterruptEnable(u8 u8InterruptEnCpy) {
	//TIMER0 Interrupts
	if (u8InterruptEnCpy == INTERRUPTS_TOIE_0) {
		SET_BIT(TIMSK,0);
	}
	else if (u8InterruptEnCpy == INTERRUPTS_OCIE_0) {
		SET_BIT(TIMSK,1);
	}
	//TIMER2 Interrupts
	if (u8InterruptEnCpy == INTERRUPTS_TOIE_2) {
		SET_BIT(TIMSK,6);
	}
	else if (u8InterruptEnCpy == INTERRUPTS_OCIE_2) {
		SET_BIT(TIMSK,7);
	}
	//TIMER1 Interrupts
	if (u8InterruptEnCpy == INTERRUPTS_TOIE_1) {
		SET_BIT(TIMSK,2);
	}
	if (u8InterruptEnCpy == INTERRUPTS_OCIEB_1) {
		SET_BIT(TIMSK,3);
	}
	if (u8InterruptEnCpy == INTERRUPTS_OCIEA_1) {
		SET_BIT(TIMSK,4);
	}
	if (u8InterruptEnCpy == INTERRUPTS_TICIE_1) {
		SET_BIT(TIMSK,5); //Input Capture Interrupt Enable
	}

}

#ifdef TIMER0_OVF_VECT
ISR(TIMER0_OVF_vect) {
	ISRFunc();
}
#endif

#ifdef TIMER0_COMP_VECT
ISR(TIMER0_COMP_vect) {
	ISRFunc();
}
#endif

#ifdef TIMER2_OVF_VECT
ISR(TIMER2_OVF_vect) {
	ISRFunc();
}
#endif

#ifdef TIMER2_COMP_VECT
ISR(TIMER2_COMP_vect) {
	ISRFunc();
}
#endif

#ifdef TIMER1_COMPA_VECT
ISR(TIMER1_COMPA_vect) {
	ISRFunc();
}
#endif

#ifdef TIMER1_COMPB_VECT
ISR(TIMER1_COMB_vect) {
	ISRFunc();
}
#endif

#ifdef TIMER1_CAPT_VECT
ISR(TIMER1_CAPT_vect) {
	ISRFunc();
}
#endif

#ifdef TIMER1_OVF_VECT
ISR(TIMER1_OVF_vect) {
	ISRFunc();
}
#endif
