#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "SETTINGS_interface.h"
#include "INTERRUPTS_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/*Array of function pointers, used to hold pointer to ISRs*/
void (*ISR_pt[INTERRUPTS_FUNCPTR_SIZE]) (void); 

/*Pointer to function*/
void (*ISRFunc) (void);

void INTERRUPTS_vidSetGlobalInterruptFlag(void) {
	SET_BIT(SREG,7);
}

void INTERRUPTS_vidClearGlobalInterruptFlag(void) {
	CLEAR_BIT(SREG,7);
}

/*Callback registerer*/
void INTERRUPTS_vidPutISRFunction(u8 u8InterruptIDCpy, void (*ptrFunc) ()) {
	ISR_pt[u8InterruptIDCpy] = ptrFunc;
}

#ifdef ST_MC_ATMEGA128
void INTERRUPTS_vidEnableInterrupt(const u8 u8InterruptID) {
	switch(u8InterruptID) {
		case INTERRUPTS_INT_0:
		SET_BIT(EIMSK,0);
		break;
		case INTERRUPTS_INT_1:
		SET_BIT(EIMSK,1);
		break;
		case INTERRUPTS_INT_2:
		SET_BIT(EIMSK,2);
		break;
		case INTERRUPTS_INT_3:
		SET_BIT(EIMSK,3);
		break;
		case INTERRUPTS_INT_4:
		SET_BIT(EIMSK,4);
		break;
		case INTERRUPTS_INT_5:
		SET_BIT(EIMSK,5);
		break;
		case INTERRUPTS_INT_6:
		SET_BIT(EIMSK,6);
		break;
		case INTERRUPTS_INT_7:
		SET_BIT(EIMSK,7);
		break;
		case INTERRUPTS_TIMER0_OVF:
		SET_BIT(TIMSK,0);
		break;
		case INTERRUPTS_TIMER0_OC:
		SET_BIT(TIMSK,1);
		break;
		case INTERRUPTS_TIMER1_OVF:
		SET_BIT(TIMSK,2);
		break;
		case INTERRUPTS_TIMER1_OC_B:
		SET_BIT(TIMSK,3);
		break;
		case INTERRUPTS_TIMER1_OC_A:
		SET_BIT(TIMSK,4);
		break;
		case INTERRUPTS_TIMER1_ICP:
		SET_BIT(TIMSK,5);
		break;
		case INTERRUPTS_TIMER2_OVF:
		SET_BIT(TIMSK,6);
		break;
		case INTERRUPTS_TIMER2_OC:
		SET_BIT(TIMSK,7);
		break;
		
	}
}
#endif
/*Enable interrupt with a simpler name*/
#ifdef ST_MC_ATMEGA1632
void INTERRUPTS_vidEnableInterrupt(const u8 u8InterruptEnCpy) {
	switch(u8InterruptEnCpy) {
		case INTERRUPTS_INT_0:
		SET_BIT(GICR,6);
		break;
		case INTERRUPTS_INT_1:
		SET_BIT(GICR,7);
		break;
		case INTERRUPTS_INT_2:
		SET_BIT(GICR,5);
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
#endif


#ifdef ST_MC_ATMEGA128
void INTERRUPTS_vidDisableInterrupt(u8 u8InterruptID) {
	switch (u8InterruptID) {
		case INTERRUPTS_INT_0:
		CLEAR_BIT(EIMSK,0);
		break;
		case INTERRUPTS_INT_1:
		CLEAR_BIT(EIMSK,1);
		break;
		case INTERRUPTS_INT_2:
		CLEAR_BIT(EIMSK,2);
		break;
		case INTERRUPTS_INT_3:
		CLEAR_BIT(EIMSK,3);
		break;
		case INTERRUPTS_INT_4:
		CLEAR_BIT(EIMSK,4);
		break;
		case INTERRUPTS_INT_5:
		CLEAR_BIT(EIMSK,5);
		break;
		case INTERRUPTS_INT_6:
		CLEAR_BIT(EIMSK,6);
		break;
		case INTERRUPTS_INT_7:
		CLEAR_BIT(EIMSK,7);
		break;
		case INTERRUPTS_TIMER0_OVF:
		CLEAR_BIT(TIMSK,0);
		break;
		case INTERRUPTS_TIMER0_OC:
		CLEAR_BIT(TIMSK,1);
		break;
		case INTERRUPTS_TIMER1_OVF:
		CLEAR_BIT(TIMSK,2);
		break;
		case INTERRUPTS_TIMER1_OC_B:
		CLEAR_BIT(TIMSK,3);
		break;
		case INTERRUPTS_TIMER1_OC_A:
		CLEAR_BIT(TIMSK,4);
		break;
		case INTERRUPTS_TIMER1_ICP:
		CLEAR_BIT(TIMSK,5);
		break;
		case INTERRUPTS_TIMER2_OVF:
		CLEAR_BIT(TIMSK,6);
		break;
		case INTERRUPTS_TIMER2_OC:
		CLEAR_BIT(TIMSK,7);
		break;
	}
}
#endif

#ifdef ST_MC_ATMEGA1632
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
#endif

#ifdef ST_MC_ATMEGA128
void INTERRUPTS_vidSetSenseControl(u8 u8InterruptID, u8 u8SenseControl) 
{
	switch(u8InterruptID) {
		case INTERRUPTS_INT_0:
		switch(u8SenseControl) 
		{
			case INTERRUPTS_SC_LOWLEVEL:
				CLEAR_BIT(EICRA,0);
				CLEAR_BIT(EICRA,1);
				break;
			case INTERRUPTS_SC_FALLING:
				CLEAR_BIT(EICRA,0);
				SET_BIT(EICRA,1);
				break;
			case INTERRUPTS_SC_RISING:
				SET_BIT(EICRA,0);
				SET_BIT(EICRA,1);
				break;
			default:
				CLEAR_BIT(EICRA,0);
				SET_BIT(EICRA,1);
		}
		break;
		case INTERRUPTS_INT_1:
		switch(u8SenseControl)
		{
			case INTERRUPTS_SC_LOWLEVEL:
			CLEAR_BIT(EICRA,2);
			CLEAR_BIT(EICRA,3);
			break;
			case INTERRUPTS_SC_FALLING:
			CLEAR_BIT(EICRA,2);
			SET_BIT(EICRA,3);
			break;
			case INTERRUPTS_SC_RISING:
			SET_BIT(EICRA,2);
			SET_BIT(EICRA,3);
			break;
			default:
			CLEAR_BIT(EICRA,2);
			SET_BIT(EICRA,3);
		}
		break;
		case INTERRUPTS_INT_2:
			switch(u8SenseControl)
			{
				case INTERRUPTS_SC_LOWLEVEL:
				CLEAR_BIT(EICRA,4);
				CLEAR_BIT(EICRA,5);
				break;
				case INTERRUPTS_SC_FALLING:
				CLEAR_BIT(EICRA,4);
				SET_BIT(EICRA,5);
				break;
				case INTERRUPTS_SC_RISING:
				SET_BIT(EICRA,4);
				SET_BIT(EICRA,5);
				break;
				default:
				CLEAR_BIT(EICRA,4);
				SET_BIT(EICRA,5);
			}
		break;
		case INTERRUPTS_INT_3:
		switch(u8SenseControl)
		{
			case INTERRUPTS_SC_LOWLEVEL:
			CLEAR_BIT(EICRA,6);
			CLEAR_BIT(EICRA,7);
			break;
			case INTERRUPTS_SC_FALLING:
			CLEAR_BIT(EICRA,6);
			SET_BIT(EICRA,7);
			break;
			case INTERRUPTS_SC_RISING:
			SET_BIT(EICRA,6);
			SET_BIT(EICRA,7);
			break;
			default:
			CLEAR_BIT(EICRA,6);
			SET_BIT(EICRA,7);
		}
		break;
		case INTERRUPTS_INT_4:
		switch(u8SenseControl)
		{
			case INTERRUPTS_SC_LOWLEVEL:
			CLEAR_BIT(EICRB,0);
			CLEAR_BIT(EICRB,1);
			break;
			case INTERRUPTS_SC_FALLING:
			CLEAR_BIT(EICRB,0);
			SET_BIT(EICRB,1);
			break;
			case INTERRUPTS_SC_RISING:
			SET_BIT(EICRB,0);
			SET_BIT(EICRB,1);
			break;
			default:
			CLEAR_BIT(EICRB,0);
			SET_BIT(EICRB,1);
		}
		break;
		case INTERRUPTS_INT_5:
		switch(u8SenseControl)
		{
			case INTERRUPTS_SC_LOWLEVEL:
			CLEAR_BIT(EICRB,2);
			CLEAR_BIT(EICRB,3);
			break;
			case INTERRUPTS_SC_FALLING:
			CLEAR_BIT(EICRB,2);
			SET_BIT(EICRB,3);
			break;
			case INTERRUPTS_SC_RISING:
			SET_BIT(EICRB,2);
			SET_BIT(EICRB,3);
			break;
			default:
			CLEAR_BIT(EICRB,2);
			SET_BIT(EICRB,3);
		}
		break;
		case INTERRUPTS_INT_6:
		switch(u8SenseControl)
		{
			case INTERRUPTS_SC_LOWLEVEL:
			CLEAR_BIT(EICRB,4);
			CLEAR_BIT(EICRB,5);
			break;
			case INTERRUPTS_SC_FALLING:
			CLEAR_BIT(EICRB,4);
			SET_BIT(EICRB,5);
			break;
			case INTERRUPTS_SC_RISING:
			SET_BIT(EICRB,4);
			SET_BIT(EICRB,5);
			break;
			default:
			CLEAR_BIT(EICRB,4);
			SET_BIT(EICRB,5);
		}
		break;
		case INTERRUPTS_INT_7:
		switch(u8SenseControl)
		{
			case INTERRUPTS_SC_LOWLEVEL:
			CLEAR_BIT(EICRB,6);
			CLEAR_BIT(EICRB,7);
			break;
			case INTERRUPTS_SC_FALLING:
			CLEAR_BIT(EICRB,6);
			SET_BIT(EICRB,7);
			break;
			case INTERRUPTS_SC_RISING:
			SET_BIT(EICRB,6);
			SET_BIT(EICRB,7);
			break;
			default:
			CLEAR_BIT(EICRB,6);
			SET_BIT(EICRB,7);
		}
		break;
	}
}
#endif

#ifdef ST_MC_ATMEGA1632
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
#endif

#ifdef ST_MC_ATMEGA1632
u8 INTERRUPTS_u8CheckExtInterruptFlag(u8 u8ExtInterruptNumCpy) {
	switch(u8ExtInterruptNumCpy)
	{
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
#endif

void INTERRUPTS_vidToggleInterrupt(u8 u8InterruptNumCpy) 
{
	switch (u8InterruptNumCpy) {
		case INTERRUPTS_TICIE_1:
			TOGGLE_BIT(TIMSK,5);
			break;
	}
}

#ifdef ST_MC_ATMEGA1632
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
#endif

#ifdef ST_MC_ATMEGA128
void INTERRUPTS_vidClearExtInterruptFlag(u8 u8InterruptID) {
	switch(u8InterruptID) {
		case INTERRUPTS_INT_0:
		SET_BIT(EIFR,0);
		break;
		case INTERRUPTS_INT_1:
		SET_BIT(EIFR,1);
		break;
		case INTERRUPTS_INT_2:
		SET_BIT(EIFR,2);
		break;
		case INTERRUPTS_INT_3:
		SET_BIT(EIFR,3);
		break;
		case INTERRUPTS_INT_4:
		SET_BIT(EIFR,4);
		break;
		case INTERRUPTS_INT_5:
		SET_BIT(EIFR,5);
		break;
		case INTERRUPTS_INT_6:
		SET_BIT(EIFR,6);
		break;
		case INTERRUPTS_INT_7:
		SET_BIT(EIFR,7);
		break;
	}
}
#endif

void INTERRUPTS_vidClearInterruptFlag(u8 u8InterruptID) {
	switch(u8InterruptID)
	 {
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

/*Signal handlers*/
#ifdef EXTERNAL_INTERRUPT_0
ISR(INT0_vect) {
	ISR_pt[INTERRUPTS_INT_0]();
}
#endif

#ifdef EXTERNAL_INTERRUPT_1
ISR(INT1_vect) {
	ISR_pt[INTERRUPTS_INT_1]();
}
#endif

#ifdef EXTERNAL_INTERRUPT_2
ISR(INT2_vect) {
	ISR_pt[INTERRUPTS_INT_2]();
}
#endif

#ifdef ST_MC_ATMEGA128
#ifdef EXTERNAL_INTERRUPT_3
ISR(INT3_vect) {
	ISR_pt[INTERRUPTS_INT_3]();
}
#endif

#ifdef EXTERNAL_INTERRUPT_4
ISR(INT4_vect) {
	ISR_pt[INTERRUPTS_INT_4]();
}
#endif

#ifdef EXTERNAL_INTERRUPT_5
ISR(INT5_vect) {
	ISR_pt[INTERRUPTS_INT_5]();
}
#endif

#ifdef EXTERNAL_INTERRUPT_6
ISR(INT6_vect) {
	ISR_pt[INTERRUPTS_INT_6]();
}
#endif

#ifdef EXTERNAL_INTERRUPT_7
ISR(INT7_vect) {
	ISR_pt[INTERRUPTS_INT_7]();
}
#endif
#endif

#ifdef TIMER0_OVF_VECT
ISR(TIMER0_OVF_vect) {
	ISR_pt[INTERRUPTS_TIMER0_OVF]();
}
#endif

#ifdef TIMER0_COMP_VECT
ISR(TIMER0_COMP_vect) {
	ISR_pt[INTERRUPTS_TIMER0_OC]();
}
#endif

#ifdef TIMER2_OVF_VECT
ISR(TIMER2_OVF_vect) {
	ISR_pt[INTERRUPTS_TIMER2_OVF]();
}
#endif

#ifdef TIMER2_COMP_VECT
ISR(TIMER2_COMP_vect) {
	ISR_pt[INTERRUPTS_TIMER2_OC]();
}
#endif

#ifdef TIMER1_COMPA_VECT
ISR(TIMER1_COMPA_vect) {
	ISR_pt[INTERRUPTS_TIMER1_OC_A]();
}
#endif

#ifdef TIMER1_COMPB_VECT
ISR(TIMER1_COMPB_vect) {
	ISR_pt[INTERRUPTS_TIMER1_OC_B]();
}
#endif

#ifdef TIMER1_CAPT_VECT

ISR(TIMER1_CAPT_vect) {
	ISR_pt[INTERRUPTS_TIMER1_ICP]();
}
#endif

#ifdef TIMER1_OVF_VECT
ISR(TIMER1_OVF_vect) {
	ISR_pt[INTERRUPTS_TIMER1_OVF]();
}
#endif


#ifdef ST_MC_ATMEGA1632
#ifdef USART_RXC_VECT
ISR(USART_RXC_vect) {
	ISR_pt[INTERRUPTS_USART_RXC]();
}
#endif

#ifdef USART_TXC_VECT
ISR(USART_TXC_vect) {
	ISR_pt[INTERRUPTS_USART_TXC]();
}
#endif

#ifdef USART_UDRE_VECT
ISR(USART_UDRE_vect) {
	ISR_pt[INTERRUPTS_USART_UDRE]();
}
#endif
#endif

#ifdef SPI_STC_VECT
ISR(SPI_STC_vect) {
	ISR_pt[INTERRUPTS_SPI_STC]();
}
#endif

#ifdef TWI_VECT
ISR(TWI_vect) {
	ISR_pt[INTERRUPTS_TWI]();
}
#endif

#ifdef ADC_VECT
ISR(ADC_vect) 
{
	ISR_pt[INTERRUPTS_ADC_CONVCOMPLETE]();
}
#endif

#ifdef ST_MC_ATMEGA1632
#ifdef ANALOG_COMP_VECT
ISR(ANA_COMP_vect) {
	ISR_pt[INTERRUPTS_ANALOG_COMP]();
}
#endif

#ifdef EEPROM_READY_VECT
ISR(EE_RDY_vect) {
	ISR_pt[EEPROM_READY_VECT]();
}
#endif
#endif
