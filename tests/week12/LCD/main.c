
#include "dio.h"
#include "LCD_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include <util/delay.h>

s8 i = 0;

void main(void) {

	LCD_vidInit();
	u8 * message = "Hello";
	while (1) {		
		for (i = 0; i < 10; i++) {
			LCD_vidGoToXY(i,1);
			LCD_vidWriteString(message);
			_delay_ms(500);
		}
		for (i = 0; i < 10; i++) {
			LCD_vidGoToXY(i,2);
			LCD_vidWriteChar('w');
			_delay_ms(500);
		}
	}
}

