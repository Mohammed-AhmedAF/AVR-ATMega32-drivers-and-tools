
/*
 * Auther : Mohamed Ahmed
 * Date : 5-12-2018
 * Omar task
 */

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include <util/delay.h>

s8 i;
s8 x = 0;
void main(void) {

	LCD_vidInit();
	s8 * message = "Omar";	
	while(1) {
		for (i = 0; i < 13; i++) {
			if(i%2 !=0) {
				LCD_vidGoToXY(i,2);
				LCD_vidWriteString(message);
				_delay_ms(500);
			}
			else {
				LCD_vidGoToXY(i,1);
				LCD_vidWriteString(message);
				_delay_ms(500);
			}
		}
	}
}
