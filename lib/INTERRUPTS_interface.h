#ifndef _INTERRUPTS_INTERFACE_H
#define _INTERRUPTS_INTERFACE_H

/*Interrupt Enable definitions*/
#define INTERRUPTS_TOIE_0 0
#define INTERRUPTS_OCIE_0 1

#define INTERRUPTS_TOIE_2 6
#define INTERRUPTS_OCIE_2 7

#define INTERRUPTS_TOIE_1 2
#define INTERRUPTS_OCIEB_1 3
#define INTERRUPTS_OCIEA_1 4
#define INTERRUPTS_TICIE_1 5
#define INTERRUPTS_INT_0 8
#define INTERRUPTS_INT_1 9
#define INTERRUPTS_INT_2 10
#define INTERRUPTS_INT_3 19
#define INTERRUPTS_INT_4 20
#define INTERRUPTS_INT_5 21
#define INTERRUPTS_INT_6 22
#define INTERRUPTS_INT_7 23
#define INTERRUPTS_ICF1 11

/*Clearer macro names*/
#define INTERRUPTS_TIMER0_OVF 0
#define INTERRUPTS_TIMER1_ICP 5
#define INTERRUPTS_TIMER1_OVF 2
#define INTERRUPTS_TIMER2_OVF 6
#define INTERRUPTS_TIMER2_OC 7
#define INTERRUPTS_USART_RXC 12
#define INTERRUPTS_USART_TXC 13
#define INTERRUPTS_USART_UDRE 14
#define INTERRUPTS_SPI_STC 15
#define INTERRUPTS_ADC_CONVCOMPLETE 16
#define INTERRUPTS_ANALOG_COMP 17
#define INTERRUPTS_EEPROM_READY 18
#define INTERRUPTS_TIMER0_COMP 1
#define INTERRUPTS_TIMER0_OC 1
#define INTERRUPTS_TIMER1_OC_A 24
#define INTERRUPTS_TIMER1_OC_B 25
#define INTERRUPTS_TWI 26



/*External Interrupts Sense Control definitions*/
#define INTERRUPTS_SC_LOWLEVEL 0
#define INTERRUPTS_SC_ANYCHANGE 1
#define INTERRUPTS_SC_FALLING 2
#define INTERRUPTS_SC_RISING 3


/*Definitions of ISR switches go under here*/
#define TIMER1_OVF_VECT 0
#define TIMER1_CAPT_VECT 1
#define TIMER2_OVF_VECT 2
#define TIMER2_COMP_VECT 3
#define TIMER0_OVF_VECT 4
#define TIMER0_COMP_VECT 5
#define EXTERNAL_INTERRUPT_0 6
#define EXTERNAL_INTERRUPT_1 7
#define TIMER1_COMPA_VECT 8
#define TIMER1_COMPB_VECT 9
#define USART_RXC_VECT 10
#define USART_TXC_VECT 11
#define USART_UDRE_VECT 12
#define SPI_STC_VECT 13
#define TWI_VECT 14
#define ADC_VECT 15
#define ANALOG_COMP_VECT 16
#define EEPROM_READY_VECT 17
#define TIMER1_OC_A 18
#define TIMER1_OC_B 19
#define EXTERNAL_INTERRUPT_2 20
#define EXTERNAL_INTERRUPT_3 21
#define EXTERNAL_INTERRUPT_4 22
#define EXTERNAL_INTERRUPT_5 23
#define EXTERNAL_INTERRUPT_6 24
#define EXTERNAL_INTERRUPT_7 25

/*Size of the array that holds pointer to functions*/
#define INTERRUPTS_FUNCPTR_SIZE 26

void INTERRUPTS_vidSetInterruptEnable(u8);
void INTERRUPTS_vidPutISRFunction(u8,void (*ptrFunc) (void));
void INTERRUPTS_vidSetInterruptEnable(u8);
void INTERRUPTS_vidEnableInterrupt(u8);
void INTERRUPTS_vidDisableInterrupt(u8);
void INTERRUPTS_vidSetGlobalInterruptFlag(void);
void INTERRUPTS_vidClearGlobalInterruptFlag(void);
void INTERRUPTS_vidSetSenseControl(u8,u8);
void INTERRUPTS_vidClearInterruptEnable(u8);
u8 INTERRUPTS_u8CheckExtInterruptFlag(u8);
void INTERRUPTS_vidClearExtInterruptFlag(u8);
void INTERRUPTS_vidClearInterruptFlag(u8);
void INTERRUPTS_vidToggleInterrupt(u8);

#endif
