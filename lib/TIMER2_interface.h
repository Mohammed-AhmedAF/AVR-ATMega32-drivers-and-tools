#ifndef _TIMER2_INTERFACE_H
#define _TIMER2_INTERFACE_H


void TIMER2_vidInit(u8,u8,u8);
void TIMER2_vidSetTCRegister(u8);
void TIMER2_vidSetOCRegister(u8);

#define TIMER2_WGM_NORMAL 0
#define TIMER2_WGM_CTC 1
#define TIMER2_WGM_PWM 2
#define TIMER2_WGM_FPWM 3

#define TIMER2_COM_NORMAL 0
#define TIMER2_COM_TOGGLE 1
#define TIMER2_COM_CLEAR 2
#define TIMER2_COM_SET 3

#define TIMER2_CLK_NO_CLK 0
#define TIMER2_CLK_1 1
#define TIMER2_CLK_8 2
#define TIMER2_CLK_32 3
#define TIMER2_CLK_64 4
#define TIMER2_CLK_128 5
#define TIMER2_CLK_256 6
#define TIMER2_CLK_1024 7

#endif
