#include "DIO_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include "SPI_iterface.h"
#include <util/delay.h>

void main(void) {
	SPI_vidMasterInit();
	while(1) {
		SPI_u8transferData('a');
		_delay_ms(1000);
		SPI_u8transferData('b');
		_delay_ms(1000);
	}
}

