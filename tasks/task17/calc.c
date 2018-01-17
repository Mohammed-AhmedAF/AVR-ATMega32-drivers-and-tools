#include "calc.h"
#include "dio.h"
#include "lcd.h"
#include "Std_Types.h"
#include <util/delay.h>

u32 res;
extern u8 u8KeyPad[4][4];
extern s8 * s8Message;
u8 lSize;
u8 rSize;

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

u32 Calc_u32ToNumber(u8 u8EqCpy[], u8 sideCpy) {
	u32 x;
	u8 i = 0;
	u32 num = 0;
	u8 size;
	if (sideCpy == 'l') {
		x = Calc_u32Power(10,lSize-1);
		i = 0;
		size = lSize;
	}
	else {
		x = Calc_u32Power(10,rSize-1);
		i = lSize+1;
		size = rSize;
	}
	for (u8 j = 0; j < size; j++) {
		if (x == 1) {
			num = (u8EqCpy[i]-48) + num;
			break;
		}
		num = (u8EqCpy[i]-48)*x + num;
		x = x/10;
		i++;
	}
	return num;

}

u32 Calc_u32Power(u8 x, u8 y) {
	u32 res = 1;	
	for (u8 i = 1; i <= y; i++) {
		res = res*x;
	}
	return res;
}

void vidPack(u8 eqCpy[],u8 u8SymbolCpy) {
	u8 i = 0;
	u8 j = 0;
	do {
		i++;
	}while (eqCpy[i] != u8SymbolCpy);
	lSize = i;
	do {
		i++;
	}while (eqCpy[i] != ' ');
	rSize = i-lSize-1;
}

void vidPutInEquation(u8 key) {
	static s32 i = 0;
	static u8 eq[10];
	u8 symbol;
	if (key == ' ') {
		eq[i] = key;
		symbol = eq[3];
		switch (symbol) {
			case '+':
				vidPack(eq,'+');
				res = Calc_u32ToNumber(eq,'l') + Calc_u32ToNumber(eq,'r');
				vidShowResult();
				break;
			case '-':
				vidPack(eq,'-');
				res = Calc_u32ToNumber(eq,'l') - Calc_u32ToNumber(eq,'l');
				vidShowResult();
				break;
			case '*':
				res = Calc_u32ToNumber(eq,symbol) * (eq[2]-48);
				vidShowResult();
				break;
			case '/':
				res = Calc_u32ToNumber(eq,symbol) / (eq[4]-48);
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
	u8 u8a;
	u32 x = Calc_u32Power(10,rSize-1);
	if (res > 9) {
		for (u8 i = 1; i <= rSize; i++) {
			u8a = (res/x)+48;
			res = res - (res/x)*x;
			Lcd_vidWriteCharacter(u8a);
			_delay_ms(500);
			x = x/10;
		}
	}
	else {
		u8 u8Res = res+48;
		Lcd_vidWriteCharacter(u8Res);
	}
	_delay_ms(1000);
}
