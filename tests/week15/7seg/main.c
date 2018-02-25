#include "DIO_interface.h"
#include "Std_Types.h"
#include "SevenSegment_interface.h"
#include "Macros.h"
#include <util/delay.h>

int i = 0;
int main(void) {
	SevenSegment_vidInit(DIO_PORTB,DIO_PORTD);
	while (1) {
		for(i = 0; i < 100; i++) {
			SevenSegment_vidWriteNumber(i);
			_delay_ms(200);
		}
	}
}

