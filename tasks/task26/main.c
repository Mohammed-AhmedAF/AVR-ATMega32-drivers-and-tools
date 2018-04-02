#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "RTO_interface.h"
#include "SevenSegment_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>
#include <avr/io.h>


void vidCount(void);
void vidToggleLED1(void);
void vidToggleLED2(void);
void vidCheckButton(void);
void vidDecreaseIntensity(void);
void vidIncreaseIntensity(void);
void vidDisplayIntensity(void);
Task_Type Task1;
Task_Type Task2;
Task_Type Task3;
Task_Type Task4;
Task_Type Task5;
Task_Type Task6;
Task_Type Task7;


u8 i;
s16 s16Intensity = 0;
void main(void) {
	//Initialization

	//	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_OUTPUT); //LED1
	//	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN1,DIO_OUTPUT); //LED2
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT); //Intensity-controlled LED

	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_LOW); //Button for toggling LEDs
	DIO_vidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);

	//Two buttons for intensity control
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN1,DIO_LOW); 
	DIO_vidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);

	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_LOW);
	DIO_vidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);


	SevenSegment_vidInit(DIO_PORTD,DIO_PORTC);
	RTO_vidInit();
	LCD_vidInit();
	Task1.periodicity = 500;
	Task1.first_delay = 0;
	Task1.state = RTO_U8TASK_RUNNING;
	Task1.ptrfun = vidCount;

	Task2.periodicity = 250;
	Task2.first_delay = 0;
	Task2.state = RTO_U8TASK_PAUSED;
	Task2.ptrfun = vidToggleLED1;

	Task3.periodicity = 500;
	Task3.first_delay = 0;
	Task3.state = RTO_U8TASK_PAUSED;
	Task3.ptrfun = vidToggleLED2;

	Task4.periodicity = 500;
	Task4.first_delay = 0;
	Task4.state = RTO_U8TASK_PAUSED;
	Task4.ptrfun = vidCheckButton;

	Task5.periodicity = 50;
	Task5.first_delay = 0;
	Task5.state = RTO_U8TASK_RUNNING;
	Task5.ptrfun = vidDecreaseIntensity;

	Task6.periodicity = 50;
	Task6.first_delay = 0;
	Task6.state = RTO_U8TASK_RUNNING;
	Task6.ptrfun =vidIncreaseIntensity;

	Task7.periodicity = 100;
	Task7.first_delay = 0;
	Task7.state = RTO_U8TASK_RUNNING;
	Task7.ptrfun = vidDisplayIntensity;

	RTO_vidCreateTask(&Task1,1);
	RTO_vidCreateTask(&Task2,2);
	RTO_vidCreateTask(&Task3,3);
	RTO_vidCreateTask(&Task4,4);
	RTO_vidCreateTask(&Task5,5);
	RTO_vidCreateTask(&Task6,6);
	RTO_vidCreateTask(&Task7,7);
	while(1);

}

void vidCount(void) {
	static u8 u8Count = 0;
	u8Count++;
	SevenSegment_vidWriteNumber(u8Count);
	if (u8Count == 99) {
		u8Count = 0;
	}
}

void vidToggleLED1(void) {
//	TOGGLE_BIT(PORTB,0);
}

void vidCheckButton(void) {
	if (DIO_u8GetPinValue(DIO_PORTB,DIO_PIN0) == 1) {
		Task3.state = RTO_U8TASK_RUNNING;
		Task2.state = RTO_U8TASK_PAUSED;
	}
	else {
		Task3.state = RTO_U8TASK_PAUSED;
		Task2.state = RTO_U8TASK_RUNNING;
	}
}

void vidToggleLED2(void) {
	TOGGLE_BIT(PORTB,1);
}

void vidDecreaseIntensity(void) {
	if(DIO_u8GetPinValue(DIO_PORTB,DIO_PIN2) == 1) {
		s16Intensity--;
		if (s16Intensity <= 0) {
			s16Intensity = 0;
		}
		else {
			OCR0 = s16Intensity;
		}
	}
}

void vidIncreaseIntensity(void) {

	if (DIO_u8GetPinValue(DIO_PORTB,DIO_PIN1) == 1) {
		s16Intensity++;
		if (s16Intensity >= 255) {
			s16Intensity = 255;
		}
		else {
			OCR0 = s16Intensity;
		}
	}
}

void vidDisplayIntensity(void) {
	u8 u8Value;
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidGoToXY(0,2);
	u8Value = s16Intensity;
	LCD_vidWriteNumber((u16)u8Value);
}
