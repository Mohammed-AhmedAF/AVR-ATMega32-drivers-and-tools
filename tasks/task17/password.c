#include "dio.h"
#include <util/delay.h> 
#include "lcd.h"
#include "Std_Types.h"
#include "password.h"

extern u8 u8KeyPad[4][4];
s8 s8Password[4] = {'1','3','2','4'};
s8 user[16];
s8 iUser;
s8 pass, number;
extern s8 * s8Message;

void vidAskPassword(void) {
	Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
	Lcd_vidSendCommand(LCD_RETURN_HOME);
	s8Message = "Enter password: ";
	Lcd_vidInsertMessage(s8Message);
	Lcd_vidGoToXY(0,2);
	while (pass == 0) {
		for (u8 r = 0; r < 4; r++) {
			Dio_vidSetPinValue(DIO_PORTB,r,0);
			for (u8 c = 4; c <= 7; c++) {
				if (Dio_u8GetPinValue(DIO_PORTB,c) == 0) {
					if(u8KeyPad[c-4][r] == 'c') {
						Lcd_vidSendCommand(LCD_CLEAR_SCREEN); /*Clear screen*/
						number = 0;
						iUser = 0;
						break;
					}
					Lcd_vidWriteCharacter(u8KeyPad[c-4][r]);	
					vidTakeNumber(u8KeyPad[c-4][r]);
					_delay_ms(300);
				}
			}
			Dio_vidSetPinValue(DIO_PORTB,r,1);
		}
	}
}

void vidBlinkLed(u8 portNumberCpy, u8 pinNumberCpy, u8 numberCpy) {
	while (numberCpy > 0) {
		Dio_vidSetPinValue(portNumberCpy,pinNumberCpy,1);
		_delay_ms(500);
		Dio_vidSetPinValue(portNumberCpy,pinNumberCpy,0);
		_delay_ms(500);
		numberCpy--;
	}
}

void vidTakeNumber(s8 keyCpy) {
	if (keyCpy == ' ') {
		if (iUser >= 5) {
			Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
			Lcd_vidSendCommand(LCD_RETURN_HOME);
			s8Message = "Wrong Password";
			Lcd_vidBlinkMessage(s8Message,3);
			iUser = 0;
			_delay_ms(500);
			vidAskPassword();
		}
		else {
			for(s8 x = 0; x < 4; x++) {
				if (s8Password[x] == user[x]) {
					if (x == 3) {
						pass = 1;
						vidBlinkLed(DIO_PORTC,2,5);
					}
					continue;
				}
				else  {
					s8Message = "Error";
					Lcd_vidInsertMessage(s8Message);
					vidBlinkLed(DIO_PORTC,0,5);
					break;
				}
			}
		}
	}
	else {
		user[iUser] = keyCpy;
		iUser++;
	}
}

