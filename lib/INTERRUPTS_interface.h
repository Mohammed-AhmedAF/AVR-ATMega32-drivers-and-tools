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

/*External Interrupts Sense Control definitions*/
#define INTERRUPTS_SC_LOWLEVEL 0
#define INTERRUPTS_SC_ANYCHANGE 1
#define INTERRUPTS_SC_FALLING 2
#define INTERRUPTS_SC_RISING 3


//Defininitions of ISR switches go under here
#define EXTERNAL_INTERRUPT_0

//

void INTERRUPTS_vidSetInterruptEnable(u8);
void INTERRUPTS_vidPutISRFunction(void (*ptrFunc) (void));
void INTERRUPTS_vidSetInterruptEnable(u8);
void INTERRUPTS_vidSetGlobalInterruptFlag(void);
void INTERRUPTS_vidClearGlobalInterruptFlag(void);
void INTERRUPTS_vidSetSenseControl(u8,u8);

#endif
