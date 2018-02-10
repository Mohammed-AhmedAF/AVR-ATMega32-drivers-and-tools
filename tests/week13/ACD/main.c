#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include "LCD_interface.h"
#include "ADC_interface.h"
#include <util/delay.h>

s8 s8GetResultSize(void);
void vidShowResult(void);

u8 res = 0;
u8 x;
s32 Calc_s32Power(u8,u8);
void main(void) {
	LCD_vidInit();	
	DIO_vidSetPortDirection(DIO_PORTC,0b11111111);
		ADC_vidInit();
	while(1) {
		x = ADC_u8GetValue();
		res = (x*5)/256;	
		DIO_vidSetPortValue(DIO_PORTC,res);
		vidShowResult();
		_delay_ms(200);
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
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

s32 Calc_s32Power(u8 x, u8 y) {
	s32 res = 1;	
	for (u8 i = 1; i <= y; i++) {
		res = res*x;
	}
	return res;
}

void vidShowResult(void) {
	u8 u8a;
	u8 resSize;
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
		vidShowResult();	
	}
}
