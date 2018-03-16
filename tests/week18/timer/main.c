#include "DIO_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

u32 u32ov_count = 0;
u16 led_1000ms = 0;
u16 led_500ms = 0;
void main(void) {

	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,1);

	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN1,1);


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

	while(1);
}

ISR (TIMER0_OVF_vect) {

	u32ov_count++;
	if(u32ov_count == 32) {
		u32ov_count = 0;
		TCNT0 = 192;
		led_1000ms++;
		if (led_1000ms == 1000) {
			led_1000ms = 0;
			TOGGLE_BIT(PORTA,0);
		}
		led_500ms++;
		if (led_500ms == 500) {
			led_500ms = 0;
			TOGGLE_BIT(PORTA,1);
		}

	}
}
