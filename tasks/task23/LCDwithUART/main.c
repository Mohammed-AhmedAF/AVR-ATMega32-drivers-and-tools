#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include "UART_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>

u8 u8key;
u8 u8xPos = 0;
u8 u8yPos = 1;
void main(void) {
	/*Initialization*/
	LCD_vidInit();
	UART_vidInit();
	LCD_vidWriteString("Hello");
	_delay_ms(500);
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	while(1) {
		u8key = UART_u8ReceiveByte();
		if (u8key == ASCII_ESCAPE) {
			u8xPos = 0;
			u8yPos = 1;
			LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		}
		else if(u8key == '\r') {
			if (u8yPos == 1) {
				u8yPos = 2;
				LCD_vidGoToXY(0,u8yPos);
			}
			else {
				u8yPos = 1;
				LCD_vidGoToXY(0,u8yPos);
			}

		}
		else if (u8key == ASCII_BACKSPACE) {
			u8xPos--;
			LCD_vidWriteCharacter(ASCII_SPACE);
			LCD_vidGoToXY(u8xPos,u8yPos);
			if (u8xPos <= -1 && (u8yPos == 2)) {
				u8xPos = 15;
				LCD_vidGoToXY(u8xPos,1);
			}
		}
		else {
			LCD_vidWriteCharacter(u8key);
			u8xPos++;
			if(u8xPos == 16) {
				if (u8yPos == 1) {
					u8yPos = 2;
					LCD_vidGoToXY(0,u8yPos);
				}
				else {
					u8yPos = 1;
					LCD_vidGoToXY(0,u8yPos);
				}
				u8xPos = 0;
			}
		}
	}
}
