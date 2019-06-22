#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "INTERRUPTS_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>

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
		case INTERRUPTS_OCIE_0
		:
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
		break;
		case INTERRUPTS_USART_RXC:
		SET_BIT(UCSRB,7);
		break;
		case INTERRUPTS_USART_TXC:
		SET_BIT(UCSRB,6);	
		break;
		case INTERRUPTS_USART_UDRE:
		SET_BIT(UCSRB,5);
		break;
		case INTERRUPTS_SPI_STC:
		SET_BIT(SPCR,7);
		break;
		case INTERRUPTS_ADC_CONVCOMPLETE:
		SET_BIT(ADCSRA,3);
		break;
		case INTERRUPTS_ANALOG_COMP:
		SET_BIT(ACSR,3);
		break;
		case INTERRUPTS_EEPROM_READY:
		SET_BIT(EECR,3);
		break;
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
		break;
		case INTERRUPTS_USART_RXC:
		CLEAR_BIT(UCSRB,7);
		break;
		case INTERRUPTS_USART_TXC:
		CLEAR_BIT(UCSRB,6);
		break;
		case INTERRUPTS_USART_UDRE:
		CLEAR_BIT(UCSRB,5);
		break;
		case INTERRUPTS_SPI_STC:
		CLEAR_BIT(SPCR,7);
		break;
		case INTERRUPTS_ADC_CONVCOMPLETE:
		CLEAR_BIT(ADCSRA,3);
		break;
		case INTERRUPTS_ANALOG_COMP:
		CLEAR_BIT(ACSR,3);
		break;
		case INTERRUPTS_EEPROM_READY:
		CLEAR_BIT(EECR,3);
		break;
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
	ISR_pt[EXTERNAL_INTERRUPT_1]();
}
#endif

#ifdef TIMER0_OVF_VECT
ISR(TIMER0_OVF_vect) {
	ISR_pt[TIMER0_OVF_VECT]();
}
#endif

#ifdef TIMER0_COMP_VECT
ISR(TIMER0_COMP_vect) {
	ISR_pt[TIMER0_COMP_VECT]();
}
#endif

#ifdef TIMER2_OVF_VECT
ISR(TIMER2_OVF_vect) {
	ISR_pt[TIMER2_OVF_VECT]();
}
#endif

#ifdef TIMER2_COMP_VECT
ISR(TIMER2_COMP_vect) {
	ISR_pt[TIMER2_COMP_VECT]();
}
#endif

#ifdef TIMER1_COMPA_VECT
ISR(TIMER1_COMPA_vect) {
	ISR_pt[TIMER1_COMPA_VECT]();
}
#endif

#ifdef TIMER1_COMPB_VECT
ISR(TIMER1_COMPB_vect) {
	ISR_pt[TIMER1_COMPB_VECT]();
}
#endif

#ifdef TIMER1_CAPT_VECT

ISR(TIMER1_CAPT_vect) {
	ISR_pt[TIMER1_CAPT_VECT]();
}
#endif

#ifdef TIMER1_OVF_VECT
ISR(TIMER1_OVF_vect) {
	ISR_pt[TIMER1_OVF_VECT]();
}
#endif

#ifdef USART_RXC_VECT
ISR(USART_RXC_vect) {
	ISR_pt[USART_RXC_VECT]();
}
#endif

#ifdef USART_TXC_VECT
ISR(USART_TXC_vect) {
	ISR_pt[USART_TXC_VECT]();
}
#endif

#ifdef USART_UDRE_VECT
ISR(USART_UDRE_vect) {
	ISR_pt[USART_RXC_VECT]();
}
#endif

#ifdef SPI_STC_VECT
ISR(SPI_STC_vect) {
	ISR_pt[SPI_STC_VECT]();
}
#endif

#ifdef TWI_VECT
ISR(TWI_vect) {
	ISR_pt[TWI_VECT]();
}
#endif

#ifdef ADC_VECT
ISR(ADC_vect) {
	ISR_pt[ADC_VECT]();
}
#endif

#ifdef ANALOG_COMP_VECT
ISR(ANA_COMP_vect) {
	ISR_pt[ANALOG_COMP_VECT]();
}
#endif

#ifdef EEPROM_READY_VECT
ISR(EE_RDY_vect) {
	ISR_pt[EEPROM_READY_VECT]();
}
#endif