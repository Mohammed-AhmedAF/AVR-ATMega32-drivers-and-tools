
#include "DIO_interface.h"
#include "lcd.h"
#include "Macros.h"
#include "Std_Types.h"
#include <util/delay.h>
void main(void) {

	LCD_vidInit();

		LCD_vidWriteChar('m');
		_delay_ms(400);

}
