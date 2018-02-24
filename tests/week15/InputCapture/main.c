/*This program is a simple frequency meter.
*/

#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include "LCD_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile u8 u8first_reading = 0; 
volatile u8 u8state = 0;
volatile u32 u32OVF_count = 0;
volatile f32 f32Ton = 0;
volatile f32 f32Toff = 0;
volatile f32 f32Ttot = 0;
volatile u16 u16freq;
volatile u8 u8duty;

int main(void) {

	/*Initialization*/
	LCD_vidInit();

	CLEAR_BIT(TCCR1A,0); /*Normal operation*/
	CLEAR_BIT(TCCR1A,1);

		/*Prescaler*/
		SET_BIT(TCCR1B,0); /*No prescaling*/
	CLEAR_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,2);


	SET_BIT(TCCR1B,6); /*Selecting rising edge for first reading*/

	SET_BIT(TIMSK,5); /*Input Capture Interrupt Enable*/
	SET_BIT(TIMSK,2); /*OVF Interrupt Enable*/

	/*Global Interrupt*/
	SET_BIT(SREG,7);


	DIO_vidSetPinDirection(DIO_PORTD,DIO_PIN6,0);

	while(1) {
		f32Ttot = f32Ton + f32Toff;
		u16freq = (u16) ((f32)1/f32Ttot);
		u8duty = (u8) ((f32)f32Ton/f32Ttot*100);
		LCD_vidGoToXY(0,1);
		LCD_vidWriteString("Freq = ");
		LCD_vidWriteCharacter((u8)(u16freq/100)+'0');
		LCD_vidWriteCharacter((u8)(u16freq%100)/10+'0');
		LCD_vidWriteCharacter((u8)((u16freq%100)%10)+'0');
		LCD_vidWriteString(" Hz.");
		LCD_vidGoToXY(0,2);
		LCD_vidWriteString("Duty = ");
		LCD_vidWriteCharacter((u8)(u8duty/100)+'0');
		LCD_vidWriteCharacter((u8)(u8duty%100)/10+'0');
		LCD_vidWriteCharacter((u8)((u8duty%100)%10)+'0');
		LCD_vidWriteString(" %");
	}
}


ISR (TIMER1_OVF_vect) {
	u32OVF_count++;
}

ISR(TIMER1_CAPT_vect) {
	if(u8first_reading == 0) {
		TCNT1=0;
		CLEAR_BIT(TCCR1B,6); /*Change edge*/
		u8first_reading = 1;
		u8state = 1;
		u32OVF_count = 0;
	}
	else {
		if(u8state == 1) {
			f32Ton = (f32) (ICR1+(u32OVF_count*65536))*(f32)((f32)1/8000000);
			u8state = 0;
			u32OVF_count = 0;
			SET_BIT(TCCR1B,6); /*Changing edge*/
			TCNT1 = 0;
		}
		else {
			f32Toff = (f32)(ICR1+(u32OVF_count*65536))*(f32)((f32)1/8000000);
			u8state = 1;
			u32OVF_count = 0;
			CLEAR_BIT(TCCR1B,6); /*Changing edge */
			TCNT1 = 0;
		}
	}
}
