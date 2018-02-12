#include "dio.h"
#include "lcd.h"
#include <util/delay.h>

void Lcd_vidInit();
void vidTakeNumber(s8);
u8 u8Shift = 0b00010100;
s8 * s8Message;
s8 number = 0;
u8 flag = 0xff;
s8 u8KeyPad[4][4] = {{'0','c','-',' '},{'1','2','3','+'},{'4','5','6','*'},{'7','8','9','/'}};
s8 s8Password[4] = {'1','3','2','4'};
s8 user[16];
s8 iUser;

void main(void)  {
	Dio_vidSetPortDirection(DIO_PORTD,0b11111111);
	Dio_vidSetPortDirection(DIO_PORTA,0b00000111);
	Dio_vidSetPortDirection(DIO_PORTB,0b00001111);
	Dio_vidSetPortValue(DIO_PORTB,0b11110000);
	Dio_vidSetPortValue(DIO_PORTD,0b00000000);
	Lcd_vidInit();
	while(1) {
		for (s8 i = 0; i < 16; i++) {	
			Lcd_vidGoToXY(i,1);
			Lcd_vidWriteCharacter('m');
			Lcd_vidGoToXY(15-i,2);
			Lcd_vidWriteCharacter('m');
			_delay_ms(500);
			Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
		}
	}
}

void vidTakeNumber(s8 key) {
	if (key == ' ') {
		if (iUser >= 5) {
			s8Message = "Longer";
			Lcd_vidInsertMessage(s8Message);
			iUser = 0;
		}
		else {
			for(s8 x = 0; x < 4; x++) {
				if (s8Password[x] == user[x]) {;
					Lcd_vidWriteCharacter('C');
				}
				else  {
					Lcd_vidWriteCharacter('E');
				}

			}

		}
	}
	else {
		user[iUser] = key;
		iUser++;
	}
}


