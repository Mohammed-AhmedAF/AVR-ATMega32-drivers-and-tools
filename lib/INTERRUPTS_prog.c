/*
 *
 * Status: Deprecated, use INTERRUPTS_program.c
 *
 */

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
	//External Interrupts
	if (u8InterruptEnCpy == INTERRUPTS_INT_0) {
		SET_BIT(GICR,6);
	}
	else if (u8InterruptEnCpy == INTERRUPTS_INT_1) {
		SET_BIT(GICR,7);
	}
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

void INTERRUPTS_vidClearInterruptEnable(u8 u8InterruptEnCpy) {
	//External Interrupts
	if (u8InterruptEnCpy == INTERRUPTS_INT_0) {
		CLEAR_BIT(GICR,6);
	}
	else if (u8InterruptEnCpy == INTERRUPTS_INT_1) {
		CLEAR_BIT(GICR,7);
	}
	//TIMER0 Interrupts
	if (u8InterruptEnCpy == INTERRUPTS_TOIE_0) {
		CLEAR_BIT(TIMSK,0);
	}
	else if (u8InterruptEnCpy == INTERRUPTS_OCIE_0) {
		CLEAR_BIT(TIMSK,1);
	}
	//TIMER2 Interrupts
	if (u8InterruptEnCpy == INTERRUPTS_TOIE_2) {
		CLEAR_BIT(TIMSK,6);
	}
	else if (u8InterruptEnCpy == INTERRUPTS_OCIE_2) {
		CLEAR_BIT(TIMSK,7);
	}
	//TIMER1 Interrupts
	if (u8InterruptEnCpy == INTERRUPTS_TOIE_1) {
		CLEAR_BIT(TIMSK,2);
	}
	if (u8InterruptEnCpy == INTERRUPTS_OCIEB_1) {
		CLEAR_BIT(TIMSK,3);
	}
	if (u8InterruptEnCpy == INTERRUPTS_OCIEA_1) {
		CLEAR_BIT(TIMSK,4);
	}
	if (u8InterruptEnCpy == INTERRUPTS_TICIE_1) {
		CLEAR_BIT(TIMSK,5); //Input Capture Interrupt Enable
	}

}

void INTERRUPTS_vidSetSenseControl(u8 u8ExtInterruptNumCpy,u8 u8SenseControlCpy) {
	switch(u8ExtInterruptNumCpy) {
		case INTERRUPTS_INT_1:
			if (u8SenseControlCpy == INTERRUPTS_SC_LOWLEVEL) {
				CLEAR_BIT(MCUCR,3);
				CLEAR_BIT(MCUCR,2);
			}
			else if (u8SenseControlCpy == INTERRUPTS_SC_ANYCHANGE) {
				CLEAR_BIT(MCUCR,3);
				SET_BIT(MCUCR,2);
			}
			else if (u8SenseControlCpy == INTERRUPTS_SC_FALLING) {
				SET_BIT(MCUCR,3);
				CLEAR_BIT(MCUCR,2);
			}
			else if (u8SenseControlCpy == INTERRUPTS_SC_RISING) {
				SET_BIT(MCUCR,3);
				SET_BIT(MCUCR,2);
			}
			break;
		case INTERRUPTS_INT_0:
			if (u8SenseControlCpy == INTERRUPTS_SC_LOWLEVEL) {
				CLEAR_BIT(MCUCR,1);
				CLEAR_BIT(MCUCR,0);
			}
			else if (u8SenseControlCpy == INTERRUPTS_SC_ANYCHANGE) {
				CLEAR_BIT(MCUCR,1);
				SET_BIT(MCUCR,0);
			}
			else if (u8SenseControlCpy == INTERRUPTS_SC_FALLING) {
				SET_BIT(MCUCR,1);
				CLEAR_BIT(MCUCR,0);
			}
			else if (u8SenseControlCpy == INTERRUPTS_SC_RISING) {
				SET_BIT(MCUCR,1);
				SET_BIT(MCUCR,0);
			}
			break;
	}

}

u8 INTERRUPTS_u8CheckExtInterruptFlag(u8 u8ExtInterruptNumCpy) {
	switch(u8ExtInterruptNumCpy) {
		case INTERRUPTS_INT_0:
			return GET_BIT(GIFR,6);
			break;
		case INTERRUPTS_INT_1:
			return GET_BIT(GIFR,7);
			break;
		case INTERRUPTS_INT_2:
			return GET_BIT(GIFR,5);
			break;
	}
}

void INTERRUPTS_vidClearExtInterruptFlag(u8 u8ExtInterruptNumCpy) {
	switch(u8ExtInterruptNumCpy) {
		case INTERRUPTS_INT_0:
			SET_BIT(GIFR,6);
			break;
		case INTERRUPTS_INT_1:
			SET_BIT(GIFR,7);
			break;
		case INTERRUPTS_INT_2:
			SET_BIT(GIFR,5);
			break;
	}
}

#ifdef EXTERNAL_INTERRUPT_0
ISR(INT0_vect) {
	ISRFunc();
}
#endif

#ifdef EXTERNAL_INTERRUPT_1
ISR(INT1_vect) {
	ISRFunc();
}
#endif

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
