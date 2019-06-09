#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "INTERRUPTS_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "SERVICES_interface.h"

/*Array of function pointers, used to hold pointer to ISRs*/
void (*ISR_pt[INTERRUPTS_FUNCPTR_SIZE]) (void); 

void (*ISRFunc) (void);

void INTERRUPTS_vidSetGlobalInterruptFlag(void) {
	SET_BIT(SREG,7);
}

void INTERRUPTS_vidClearGlobalInterruptFlag(void) {
	CLEAR_BIT(SREG,7);
}

void INTERRUPTS_vidPutISRFunction(u8 u8InterruptIDCpy, void (*ptrFunc) ()) {
	ISR_pt[u8InterruptIDCpy] = ptrFunc;
}

/*Enable interrupt with a simpler name*/
void INTERRUPTS_vidEnableInterrupt(u8 u8InterruptEnCpy) {
	switch(u8InterruptEnCpy) {
		case INTERRUPTS_INT_0:
		SET_BIT(GICR,6);
		break;
		case INTERRUPTS_INT_1:
		SET_BIT(GICR,7);
		break;
		case  INTERRUPTS_TOIE_0:
		SET_BIT(TIMSK,0);
		break;
		case INTERRUPTS_OCIE_0:
		SET_BIT(TIMSK,1);
		break;
		case INTERRUPTS_TOIE_2:
		SET_BIT(TIMSK,6);
		break;
		case INTERRUPTS_OCIE_2:
		SET_BIT(TIMSK,7);
		break;
		case INTERRUPTS_TOIE_1:
		SET_BIT(TIMSK,2);
		break;
		case INTERRUPTS_OCIEB_1:
		SET_BIT(TIMSK,3);
		break;
		case INTERRUPTS_OCIEA_1:
		SET_BIT(TIMSK,4);
		break;
		case INTERRUPTS_TICIE_1:
		SET_BIT(TIMSK,5);
		
	}
}

void INTERRUPTS_vidDisableInterrupt(u8 u8InterruptEnCpy) {
	switch(u8InterruptEnCpy) {
		case INTERRUPTS_INT_0:
		CLEAR_BIT(GICR,6);
		break;
		case INTERRUPTS_INT_1:
		CLEAR_BIT(GICR,7);
		break;
		case  INTERRUPTS_TOIE_0:
		CLEAR_BIT(TIMSK,0);
		break;
		case INTERRUPTS_OCIE_0:
		CLEAR_BIT(TIMSK,1);
		break;
		case INTERRUPTS_TOIE_2:
		CLEAR_BIT(TIMSK,6);
		break;
		case INTERRUPTS_OCIE_2:
		CLEAR_BIT(TIMSK,7);
		break;
		case INTERRUPTS_TOIE_1:
		CLEAR_BIT(TIMSK,2);
		break;
		case INTERRUPTS_OCIEB_1:
		CLEAR_BIT(TIMSK,3);
		break;
		case INTERRUPTS_OCIEA_1:
		CLEAR_BIT(TIMSK,4);
		break;
		case INTERRUPTS_TICIE_1:
		CLEAR_BIT(TIMSK,5);
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
		default:
			return 0;
		break;
	}
}

void INTERRUPTS_vidToggleInterrupt(u8 u8InterruptNumCpy) 
{
	switch (u8InterruptNumCpy) {
		case INTERRUPTS_TICIE_1:
			TOGGLE_BIT(TIMSK,5);
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

void INTERRUPTS_vidClearInterruptFlag(u8 u8InterruptFlagIDCpy) {
	switch(u8InterruptFlagIDCpy) {
		case INTERRUPTS_TOIE_0:
			SET_BIT(TIFR,0);
			break;
		case INTERRUPTS_TOIE_1:
			SET_BIT(TIFR,2);
			break;
		case INTERRUPTS_TOIE_2:
			SET_BIT(TIFR,6);
			break;
		case INTERRUPTS_ICF1:
			SET_BIT(TIFR,5);
			break;
	}
}

#ifdef EXTERNAL_INTERRUPT_0
ISR(INT0_vect) {
	ISR_pt[EXTERNAL_INTERRUPT_0]();
}
#endif

#ifdef EXTERNAL_INTERRUPT_1
ISR(INT1_vect) {
	ISRFunc();
}
#endif

#ifdef TIMER0_OVF_VECT
ISR(TIMER0_OVF_vect) {
	ISR_pt[TIMER0_OVF_VECT]();
}
#endif

#ifdef TIMER0_COMP_VECT
ISR(TIMER0_COMP_vect) {
	ISRFunc();
}
#endif

#ifdef TIMER2_OVF_VECT
ISR(TIMER2_OVF_vect) {
	ISR_pt[TIMER2_OVF_VECT]();
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
	ISR_pt[TIMER1_CAPT_VECT]();
}
#endif

#ifdef TIMER1_OVF_VECT
ISR(TIMER1_OVF_vect) {
	ISRFunc();
}
#endif
