#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"
#include <util/delay.h>

u16 res = 0;
u8 x;
u32 Calc_s32Power(u8,u8);
void main(void) {
	LCD_vidInit();	
	ADC_vidInit();
	DIO_vidSetPortDirection(DIO_PORTC,1);
	LCD_vidWriteString("Hello");
	while(1) {
		x = ADC_u8GetValue();
		res = (u16) (x*5)/256;	
		DIO_vidSetPortValue(DIO_PORTC,res);
		LCD_vidWriteNumber(res);
		_delay_ms(1000);
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);

	}

}

