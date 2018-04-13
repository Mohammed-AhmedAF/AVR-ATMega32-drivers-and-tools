/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 */

#ifndef _TIMER0_INTERFACE_H
#define _TIMER0_INTERFACE_H
void TIMER0_vidInit(u8,u8,u8);
void TIMER0_vidPutISR(void (*ptrFunc)());
void TIMER0_vidSetTCRegister(u8);
void TIMER0_vidSetOCRegister(u8);

#define TIMER0_WGM_NORMAL 0
#define TIMER0_WGM_CTC 1
#define TIMER0_WGM_PWM 2
#define TIMER0_WGM_FPWM 3

#define TIMER0_COM_NORMAL 0
#define TIMER0_COM_TOGGLE 1
#define TIMER0_COM_CLEAR 2
#define TIMER0_COM_SET 3

#define TIMER0_CLK_0 0
#define TIMER0_CLK_1 1
#define TIMER0_CLK_8 2
#define TIMER0_CLK_64 3
#define TIMER0_CLK_256 4
#define TIMER0_CLK_1024 5
#define TIMER0_CLK_EXT_F 6
#define TIMER0_CLK_EXT_R 7


#endif
