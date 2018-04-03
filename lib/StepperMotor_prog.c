#include "DIO_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include "StepperMotor_interface.h"
#include <util/delay.h>
u8 values[4] = {0x01,0x02,0x04,0x08};
u8 value = 0;
u8 i = 0;
void StepperMotor_vidInit() {
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN4,DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN5,DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN6,DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);
}

void StepperMotor_vidMove() {
	for (i = 0;i<4;i++) {
		value = values[i];
		DIO_vidSetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(value,0));
		_delay_ms(2);
		DIO_vidSetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(value,1));
		_delay_ms(2);
		DIO_vidSetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(value,2));
		_delay_ms(2);
		DIO_vidSetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(value,3));
		_delay_ms(2);
	}
}

