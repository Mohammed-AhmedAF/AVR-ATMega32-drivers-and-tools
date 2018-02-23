#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include <util/delay.h>
u8 val[4] = {0x01,0x02,0x04,0x08};
u8 v = 0;
u8 i = 0;
void main(void) {
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,1);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN1,1);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN2,1);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN3,1);
	while(1) {
		for (i = 0;i<4;i++) {
		v = val[i];
		DIO_vidSetPinValue(DIO_PORTA,DIO_PIN0,GET_BIT(v,0));
		_delay_ms(2);
		DIO_vidSetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(v,1));
		_delay_ms(2);
		DIO_vidSetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(v,2));
		_delay_ms(2);
		DIO_vidSetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(v,3));
		_delay_ms(2);
		}
	}
}
