#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include "UART_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>

u8 u8key;
s8 s8xPos = 0;
s8 s8yPos = 1;
void main(void) {
	/*Initialization*/
	LCD_vidInit();
	UART_vidInit();
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN0,STD_HIGH);
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN1,STD_HIGH);
	LCD_vidWriteString("Hello");
	_delay_ms(500);
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	while(1) {
		u8key = UART_u8ReceiveByte();
		if (u8key == ASCII_ESCAPE) {
			s8xPos = 0; //You will need to reinitialize x,y variables
			s8yPos = 1; //or else backspace will not work correctly
			LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		}
		else if(u8key == '\r') {
			if (s8yPos == 1) {
				s8yPos = 2;
				LCD_vidGoToXY(0,s8yPos);
			}
			else {
				s8yPos = 1;
				LCD_vidGoToXY(0,s8yPos);
			}

		}
		else if (u8key == ASCII_BACKSPACE) {
			s8xPos--;
			if ((s8xPos < 0) && (s8yPos == 2)) {
				s8xPos = 15;
				s8yPos = 1;
				TOGGLE_BIT(PORTB,1);
				LCD_vidWriteCharacter(ASCII_SPACE);
				LCD_vidGoToXY(s8xPos,s8yPos);
			}
			else {
				LCD_vidWriteCharacter(ASCII_SPACE);
				LCD_vidGoToXY(s8xPos,s8yPos);
			}
		}
		else {
			LCD_vidWriteCharacter(u8key);
			s8xPos++;
			if(s8xPos == 16) {
				if (s8yPos == 1) {
					s8xPos = 0;
					s8yPos = 2;
					LCD_vidGoToXY(s8xPos,s8yPos);
				}
				else {
					s8xPos = 0;
					s8yPos = 1;
					LCD_vidGoToXY(s8xPos,s8yPos);
				}
				s8xPos = 0;
			}
		}
	}
}
