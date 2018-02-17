#include "DIO_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>

u32 u8desiredTime = 0;
u8 u8endFlag = 0;
u32 ms_var = 0;
u32 OVF_count = 0;
void delayMS(u32);
void Timer_vidInit(void);
void main(void) {
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
	CLEAR_BIT(TCCR0,6);

	TCNT0 = 192;
	SET_BIT(TIMSK,0);

	SET_BIT(SREG,7);


	DIO_vidSetPinDirection(DIO_PORTA,0,1);
	while(1) {
		DIO_vidSetPinValue(DIO_PORTA,0,1);
		delayMS(1000);
		DIO_vidSetPinValue(DIO_PORTA,0,0);
		delayMS(1000);
	}
}

void delayMS(u32 u8timeCpy) {
	u8desiredTime = 0;
	u8endFlag = 0;
	u8desiredTime = u8timeCpy;
	while(u8endFlag == 0) {
		continue;
	}
}

ISR (TIMER0_OVF_vect) {
	OVF_count++;
	if(OVF_count == 32) {
		OVF_count = 0;
		TCNT0 = 192;
		ms_var++;
		if(ms_var == u8desiredTime) {
			ms_var = 0;
			u8endFlag = 1;
		}
	}
}
