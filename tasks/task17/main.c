#include "dio.h"
#include "lcd.h"
#include <util/delay.h>

void Lcd_vidInit();
void vidTakeNumber(s8);
void vidAskPassword(void);
void vidChoose(void);
s8 s8GetChoise(void);

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
	Dio_vidSetPortDirection(DIO_PORTA,0b00001111);
	Dio_vidSetPortDirection(DIO_PORTB,0b00001111);
	Dio_vidSetPortValue(DIO_PORTB,0b11110000);
	Dio_vidSetPortValue(DIO_PORTD,0b00000000);
	Lcd_vidInit();
	while(1) {
		vidChoose();
		_delay_ms(10000);
	}
}

void vidChoose(void) {
	s8 s8Choise;
	s8Message = "1. Calc 2. Motor\0";
	Lcd_vidInsertMessage(s8Message);
	Lcd_vidSendCommand(LCD_RETURN_HOME); /*If I don't add this, there will be a delay in showing the third option*/
	Lcd_vidGoToXY(0,2);
	s8Message = "3. Farah\0";
	Lcd_vidInsertMessage(s8Message);
	_delay_ms(1000);
	Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
	s8Choise = s8GetChoise();
	switch (s8Choise) {
		case '1':
			s8Message = "Calc\0";
			Lcd_vidInsertMessage(s8Message);
			break;
		case '2':
			s8Message = "Motor\0";
			Lcd_vidInsertMessage(s8Message);
			vidMotor();
			break;
		case '3':
			s8Message = "Farah\0";
			Lcd_vidInsertMessage(s8Message);
			break;
		default :
			s8Message = "Invalid ans.\0";
			Lcd_vidInsertMessage(s8Message);
	}
}

void vidMotor() {
	while(1) {
		Dio_vidSetPinValue(DIO_PORTA,3,1);
		_delay_ms(2000);
		Dio_vidSetPinValue(DIO_PORTA,3,0);
		_delay_ms(2000);
	}
}
void vidAskPassword(void) {
	while (1) {
		for (u8 r = 0; r < 4; r++) {
			Dio_vidSetPinValue(DIO_PORTB,r,0);
			for (u8 c = 4; c <= 7; c++) {
				if (Dio_u8GetPinValue(DIO_PORTB,c) == 0) {
					if(u8KeyPad[c-4][r] == 'c') {
						Lcd_vidSendCommand(0b00000001); /*Clear screen*/
						number = 0;
						iUser = 0;
						break;
					}
					Lcd_vidWriteCharacter(u8KeyPad[c-4][r]);	
					vidTakeNumber(u8KeyPad[c-4][r]);
				}
			}
			Dio_vidSetPinValue(DIO_PORTB,r,1);
		}
	}
}
void vidTakeNumber(s8 key) {
	if (key == ' ') {
		if (iUser >= 5) {
			s8Message = "Wrong Password";
			Lcd_vidInsertMessage(s8Message);
			iUser = 0;
		}
		else {
			for(s8 x = 0; x < 4; x++) {
				if (s8Password[x] == user[x]) {;
					continue;
				}
				else  {
					s8Message = "Error";
					Lcd_vidInsertMessage(s8Message);
					break;
				}
			}

		}
	}
	else {
		user[iUser] = key;
		iUser++;
	}
}

s8 s8GetChoise (void) {
	while (1) {
		for (u8 r = 0; r < 4; r++) {
			Dio_vidSetPinValue(DIO_PORTB,r,0);
			for (u8 c = 4; c <= 7; c++) {
				if (Dio_u8GetPinValue(DIO_PORTB,c) == 0) {
					if(u8KeyPad[c-4][r] == 'c') {
						Lcd_vidSendCommand(0b00000001); /*Clear screen*/
						number = 0;
						iUser = 0;
						break;
					}
					return u8KeyPad[c-4][r];
				}
			}
			Dio_vidSetPinValue(DIO_PORTB,r,1);
		}
	}
}

