#include "dio.h"
#include <util/delay.h>
#include "motor.h"

void vidMotor() {
	while(1) {
		Dio_vidSetPinValue(DIO_PORTA,3,1);
		_delay_ms(2000);
		Dio_vidSetPinValue(DIO_PORTA,3,0);
		_delay_ms(2000);
	}
}

