#ifndef _INTERRUPTS_INTERFACE_H
#define _INTERRUPTS_INTERFACE_H

#define INTERRUPTS_TOIE_0 0
#define INTERRUPTS_OCIE_0 1

#define INTERRUPTS_TOIE_2 6
#define INTERRUPTS_OCIE_2 7

#define INTERRUPTS_TOIE_1 2
#define INTERRUPTS_OCIEB_1 3
#define INTERRUPTS_OCIEA_1 4
#define INTERRUPTS_TICIE_1 5

void INTERRUPTS_vidSetInterruptEnable(u8);
void INTERRUPTS_vidPutISRFunction(void (*ptrFunc) (void));
void INTERRUPTS_vidSetInterruptEnable(u8);
void INTERRUPTS_vidSetGlobalInterruptFlag(void);
void INTERRUPTS_vidClearGlobalInterruptFlag(void);
#endif
