#ifndef _INTERRUPTS_INTERFACE_H
#define _INTERRUPTS_INTERFACE_H

#define INTERRUPTS_TOIE_0 0
#define INTERRUTPS_OCIE_0 1

void INTERRUPTS_vidSetInterruptEnable(u8);
void INTERRUPTS_vidPutISRFunction(void (*ptrFunc) (void));

void INTERRUPTS_vidSetGlobalInterruptFlag(void);
void INTERRUPTS_vidClearGlobalInterruptFlag(void);
#endif
