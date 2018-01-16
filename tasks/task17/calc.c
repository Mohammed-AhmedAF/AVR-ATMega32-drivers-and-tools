#include "calc.h"
#include "dio.h"
#include "lcd.h"
#include "Std_Types.h"
#include <util/delay.h>

u8 res;
extern u8 u8KeyPad[4][4];
extern s8 * s8Message;

void calc() {
	while (1) {
		for (u8 r = 0; r < 4; r++) {
			Dio_vidSetPinValue(DIO_PORTB,r,0);
			for (u8 c = 4; c <= 7; c++) {
				if (Dio_u8GetPinValue(DIO_PORTB,c) == 0) {
					if(u8KeyPad[c-4][r] == 'c') {
						Lcd_vidSendCommand(LCD_CLEAR_SCREEN);						
						break;	
					}
					Lcd_vidWriteCharacter(u8KeyPad[c-4][r]);
					_delay_ms(500);
					vidPutInEquation(u8KeyPad[c-4][r]);
				}
			}
			Dio_vidSetPinValue(DIO_PORTB,r,1);
		}
	}
}



u8 Calc_u8ToNumber(u8 * u8EqPointerCpy, u8 u8SymbolCpy) {
	u8 x = Calc_u8Power(10,2);
	u8 num = 0;
	while (*u8EqPointerCpy != u8SymbolCpy) { 
		num = ((*u8EqPointerCpy)-48)/x + num;
		x = x/10;
		u8EqPointerCpy++;

	}
	num = ((*u8EqPointerCpy++)-48) + num;
	return num;
}

u8 Calc_u8Power(u8 x, u8 y) {
	u8 res = 1;	
	for (u8 i = 1; i <= y; i++) {
		res = res*x;
	}
	return res;
}

void vidPutInEquation(u8 key) {
	static s32 i = 0;
	static u8 eq[4];
	u8 symbol;
	if (key == ' ') {
		symbol = eq[1];
		switch (symbol) {
			case '+':
				res = Calc_u8ToNumber(eq,'+') + (eq[4]-48);
				vidShowResult();
				break;
			case '-':
				res = (eq[0]-48) - (eq[2]-48);
				vidShowResult();
				break;
			case '*':
				res = (eq[0]-48) * (eq[2]-48);
				vidShowResult();
				break;
			case '/':
				res = (eq[0]-48) / (eq[2]-48);
				vidShowResult();
				break;
			default :
				Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
				Lcd_vidSendCommand(LCD_RETURN_HOME);
				s8Message = "Invalid equation\0";
				Lcd_vidBlinkMessage(s8Message,3);

				break;
		}
	}
	else {
		eq[i] = key;
		i++;
	}
}

void vidShowResult(void) {
	Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
	Lcd_vidSendCommand(LCD_RETURN_HOME);
	s8 s8a;
	u8 x = Calc_u8Power(10,2);
	if (res > 9) {
		for (u8 i = 1; i <= 2; i++) {
			s8a = (res/x)+48;
			Lcd_vidWriteCharacter(s8a);
			x = x/10;
		}
	}
	else {
		s8 s8Res = res+48;
		Lcd_vidWriteCharacter(s8Res);
	}
	_delay_ms(1000);
}

