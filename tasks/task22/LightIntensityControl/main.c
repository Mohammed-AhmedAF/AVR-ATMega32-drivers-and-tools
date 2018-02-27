/*
 * Project: LightIntensity
 * Author: Mohamed Ahmed Abd Al-Fattah Mahmoud
 * Date: 26-2-2018
 * Discription: Project that allows the user to enter a value using the keypad
 * and then this will be the intensity of light for a LED.
 */ 

#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include "Keypad_interface.h"
#include "LCD_interface.h"
#include "Keypad_interface.h"
#include "Services_interface.h"
#include <avr/io.h>
#include <util/delay.h>
extern u8 u8keyPressed;
u8 u8intensity[3];
u8 u8val = 0;
u8 i = 0;
int main(void) {
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN3,STD_HIGH);
	DIO_vidSetPinValue(DIO_PORTB,DIO_PIN3,STD_LOW);
	LCD_vidInit();
	KEYPAD_vidInit();

	/*Fast PWM*/
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

	SET_BIT(TCCR0,5);
	CLEAR_BIT(TCCR0,4);

	SET_BIT(TCCR0,0);
	OCR0 = 0;
	TCNT0=0;

	while(1) {
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		LCD_vidGoToXY(0,1);
		LCD_vidWriteString("Intensity: ");
		LCD_vidGoToXY(0,2);
		do {
			Services_vidWriteCharacter();
			u8intensity[i] = u8keyPressed;
			i++;	
		}while(u8keyPressed != '#');
		i = 0;
		u8val = (u8intensity[0]-0x30)*100;
		u8val += (u8intensity[1]-0x30)*10;
		u8val += (u8intensity[2]-0x30);
		OCR0 = u8val;
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		LCD_vidWriteString("Crnt. intensity:");
		LCD_vidGoToXY(0,2);
		LCD_vidWriteCharacter(u8intensity[0]);
		LCD_vidWriteCharacter(u8intensity[1]);
		LCD_vidWriteCharacter(u8intensity[2]);
		u8val = 0;
		do {
		}while(KEYPAD_u8GetKey() != '/');

	}

}
