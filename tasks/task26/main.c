#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "RTO_interface.h"
#include "SevenSegment_interface.h"
#include <util/delay.h>
#include <avr/io.h>


void vidCount(void);
void vidToggleLED1(void);
void vidToggleLED2(void);
void vidCheckButton(void);
void vidDecreaseIntensity(void);
void vidIncreaseIntensity(void);
Task_Type Task1;
Task_Type Task2;
Task_Type Task3;
Task_Type Task4;
Task_Type Task5;
Task_Type Task6;

u8 i;
u8 u8Intensity = 0;
void main(void) {
	//Initialization

	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,STD_HIGH); //LED1
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN1,STD_HIGH); //LED2
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN3,STD_HIGH);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN2,STD_LOW); //Button for toggling LEDs
	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN2,STD_HIGH);

	//Two buttons for intensity control
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN3,STD_LOW); 
	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN3,STD_HIGH);

	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN4,STD_LOW);
	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN4,STD_HIGH);


	SevenSegment_vidInit(DIO_PORTD,DIO_PORTC);
	RTO_vidInit();


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

	Task5.periodicity = 200;
	Task5.first_delay = 0;
	Task5.state = RTO_U8TASK_RUNNING;
	Task5.ptrfun = vidDecreaseIntensity;

	Task6.periodicity = 200;
	Task6.first_delay = 0;
	Task6.state = RTO_U8TASK_RUNNING;
	Task6.ptrfun =vidIncreaseIntensity;


	RTO_vidCreateTask(&Task1,1);
	RTO_vidCreateTask(&Task2,2);
	RTO_vidCreateTask(&Task3,3);
	RTO_vidCreateTask(&Task4,4);
	RTO_vidCreateTask(&Task5,5);
	RTO_vidCreateTask(&Task6,0);
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
	TOGGLE_BIT(PORTA,0);
}

void vidCheckButton(void) {
	if (DIO_u8GetPinValue(DIO_PORTA,DIO_PIN2) == 1) {
		Task3.state = RTO_U8TASK_RUNNING;
		Task2.state = RTO_U8TASK_PAUSED;
	}
	else {
		Task3.state = RTO_U8TASK_PAUSED;
		Task2.state = RTO_U8TASK_RUNNING;
	}
}

void vidToggleLED2(void) {
	TOGGLE_BIT(PORTA,1);
}

void vidDecreaseIntensity(void) {
	if(DIO_u8GetPinValue(DIO_PORTA,DIO_PIN3) == 1) {
		u8Intensity--;
		OCR0 = u8Intensity;
	}
}

void vidIncreaseIntensity(void) {
	if (DIO_u8GetPinValue(DIO_PORTA,DIO_PIN4) == 1) {
		u8Intensity++;
		OCR0 = u8Intensity;
	}
}
