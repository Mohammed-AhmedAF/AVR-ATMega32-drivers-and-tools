
#include "DIO_interface.h"
#include "lcd.h"
#include "Macros.h"
#include "Std_Types.h"
#include <util/delay.h>
void main(void) {

	LCD_vidInit();
		u8 * message = "Hello\0";
		LCD_vidWriteString(message);
		_delay_ms(400);

}
