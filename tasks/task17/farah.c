#include "dio.h"
#include "lcd.h"
#include "farah.h"
#include <util/delay.h>

void vidFarah() {
	PORTC = 0b00000001;
	Lcd_vidInit();
	Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
	while(1) {
		for (u8 i = 0; i < 6; i++) {
			_delay_ms(100);
			PORTC = PORTC << 1;
			_delay_ms(100);
			vidTraverse();
		}
		PORTC = 0b00000001;
	}
}

void vidTraverse(void) {
	static s8 i = 0;
	Lcd_vidGoToXY(i,1);
	Lcd_vidWriteCharacter('m');
	Lcd_vidGoToXY(15-i,2);
	Lcd_vidWriteCharacter('m');
	_delay_ms(100);
	Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
	i++;
	if (i == 15) {
		i = 0;
	}
}


