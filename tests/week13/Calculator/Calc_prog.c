#include "Calc_interface.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Std_Types.h"
#include <util/delay.h>

s32 res;
u8 eq[10];
u8 lSize;
u8 rSize;
/*vidPutInEquation(u8KeyPad[c-4][r] */
extern s8 * s8Message;
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
	}while (eqCpy[i] != '=');
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
	if (key == '=') {
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
				LCD_vidSendCommand(LCD_CLEAR_SCREEN);
				LCD_vidSendCommand(LCD_RETURN_HOME);
				s8Message = "Invalid equation\0";
				LCD_vidBlinkString(s8Message,3);
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
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		LCD_vidSendCommand(LCD_RETURN_HOME);
	}
	if (res > 9) {
		resSize = s8GetResultSize();
		s32 x = Calc_s32Power(10,resSize-1);	
		for (s8 i = 1; i <= resSize; i++) {
			u8a = (res/x)+48;
			res = res - (res/x)*x;
			LCD_vidWriteCharacter(u8a);
			_delay_ms(500);
			x = x/10;
		}
	}
	else if (0 < res) {
		u8 u8Res = res+48;
		LCD_vidWriteCharacter(u8Res);
	}
	else {
		LCD_vidWriteCharacter('-');
		res = res*(-1);
		vidShowResult(1);	
	}
}
