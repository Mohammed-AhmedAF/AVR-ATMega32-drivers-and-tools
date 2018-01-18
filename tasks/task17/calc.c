#include "calc.h"
#include "dio.h"
#include "lcd.h"
#include "Std_Types.h"
#include <util/delay.h>

s32 res;
extern u8 u8KeyPad[4][4];
extern s8 * s8Message;
u8 eq[10];
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

s32 Calc_s32ToNumber(u8 u8EqCpy[], u8 sideCpy) {
	s32 x;
	u8 i = 0;
	s32 num = 0;
	u8 size;
	if (sideCpy == 'l') {
		x = Calc_s32Power(10,lSize-1);
		i = 0;
		size = lSize;
	}
	else {
		x = Calc_s32Power(10,rSize-1);
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

s32 Calc_s32Power(u8 x, u8 y) {
	s32 res = 1;	
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

u8 u8GetSymbolPosition(u8 eq[]) {
	u8 i = 0;
	do {
		i++;
	}while ((eq[i] != '*') && (eq[i] != '+') && (eq[i] != '/') && (eq[i] != '-'));
	return i;
}

void vidPutInEquation(u8 key) {
	static s32 i = 0;
	static u8 symbolPosition;
	u8 symbol;
	if (key == ' ') {
		eq[i] = key;
		symbol = eq[u8GetSymbolPosition(eq)];
		vidPack(eq,symbol);
		switch (symbol) {
			case '+':
				res = Calc_s32ToNumber(eq,'l') + Calc_s32ToNumber(eq,'r');
				vidShowResult(0);
				break;
			case '-':
				res = Calc_s32ToNumber(eq,'l') - Calc_s32ToNumber(eq,'r');
				vidShowResult(0);
				break;
			case '*':
				res = Calc_s32ToNumber(eq,'l') * Calc_s32ToNumber(eq,'r');
				vidShowResult(0);
				break;
			case '/':
				res = Calc_s32ToNumber(eq,'l') / Calc_s32ToNumber(eq,'r');
				vidShowResult(0);
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
s8 s8GetResultSize(void) {
	s32 n = res;
	s8 count = 0;
	while(n != 0)
	{
		n /= 10;
		++count;
	}
	return count;
}
void vidShowResult(u8 callCpy) {
	u8 u8a;
	u8 resSize;
	if (callCpy == 0) {
		Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
		Lcd_vidSendCommand(LCD_RETURN_HOME);
	}
	if (res > 9) {
		resSize = s8GetResultSize();
		s32 x = Calc_s32Power(10,resSize-1);	
		for (s8 i = 1; i <= resSize; i++) {
			u8a = (res/x)+48;
			res = res - (res/x)*x;
			Lcd_vidWriteCharacter(u8a);
			_delay_ms(500);
			x = x/10;
		}
	}
	else if (0 < res) {
		u8 u8Res = res+48;
		Lcd_vidWriteCharacter(u8Res);
	}
	else {
		Lcd_vidWriteCharacter('-');
		res = res*(-1);
		vidShowResult(1);	
	}
}
