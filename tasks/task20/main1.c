#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include <util/delay.h>

s8 i;

void main(void) {
	LCD_vidInit();
	while(1) {
		for (i = 0; i < 16; i++) {
			LCD_vidGoToXY(i,1);
			LCD_vidWriteChar('w');
			_delay_ms(200);
		}
		for (i = 55; i >= 40;i--) {
			LCD_vidGoToXY(i,1);
			LCD_vidWriteChar('w');
			_delay_ms(150);
		}
	}
}
