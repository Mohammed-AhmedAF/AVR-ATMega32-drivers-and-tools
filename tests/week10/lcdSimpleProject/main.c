#include "lcd.h"
#include "dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include <util/delay.h>

void main(void) {
	Dio_vidSetPortDirection(DIO_PORTA,0b00000111);
	Dio_vidSetPortDirection(DIO_PORTD,0b11111111);
	Lcd_vidInit();
	s8 * message = "Mona 7elwa";
	while(1) {
		Lcd_vidInsertMessage(message);
		_delay_ms(300);
		Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
		Lcd_vidSendCommand(LCD_RETURN_HOME);
}

}
