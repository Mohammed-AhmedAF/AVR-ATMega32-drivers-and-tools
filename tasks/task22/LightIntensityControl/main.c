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
u16 u16val = 0;
u8 i = 0;
void vidAsk(void);
u8 vidInsertValue(u8 [], u8);
int main(void) {
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN3,STD_HIGH);
	DIO_vidSetPinValue(DIO_PORTB,DIO_PIN3,STD_LOW);
	LCD_vidInit();
	KEYPAD_vidInit();

	/*Fast PWM*/
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

	SET_BIT(TCCR0,5); //Clear on compate match
	CLEAR_BIT(TCCR0,4);

	SET_BIT(TCCR0,0); //Setting the Clock with now prescaling
	OCR0 = 0;
	TCNT0=0;

	while(1) {
		vidAsk();
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		LCD_vidWriteString("Crnt. power:");
		LCD_vidGoToXY(0,2);
		LCD_vidWriteSizedString(u8intensity,i);
		do {
		}while(KEYPAD_u8GetKey() != '/');

	}
}

/*viAsk is a recursive function, it will call itself if the value
 * entered is bigger than 255.
 */
void vidAsk(void) {
	OCR0 = 0;
	i = 0;
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidGoToXY(0,1);
	LCD_vidWriteString("Power: ");
	LCD_vidGoToXY(0,2);
	do{
		Services_vidWriteCharacter();
		if (u8keyPressed != '#') {
			u8intensity[i] = u8keyPressed;
			i++;
		}	
	}while(u8keyPressed != '#');
	if (vidInsertValue(u8intensity,i) == 0) {
		vidAsk();
	}

}

/*InsertValue is will return 0 if insertion fails,
 * 1 if it succeed.
 *
 */
u8 vidInsertValue(u8 valArray[3], u8 u8sizeCpy) {
	u16val = 0;
	if (u8sizeCpy == 3) {
		u16val = (u8intensity[0]-0x30)*100;
		u16val += (u8intensity[1]-0x30)*10;
		u16val += (u8intensity[2]-0x30);
	}
	else if(u8sizeCpy == 2) {
		u16val = (u8intensity[0]-0x30)*10;
		u16val += (u8intensity[1]-0x30);
	}
	else if(u8sizeCpy == 1) {
		u16val = (u8intensity[0]-0x30);
	}
	if (i > 3 || (u16val > 255)) {
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		LCD_vidBlinkString("Value is too big!",3);
		return 0;
	}
	else {
		OCR0 = u16val;
		return 1;
	}
}
