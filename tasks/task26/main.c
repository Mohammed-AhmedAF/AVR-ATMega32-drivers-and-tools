#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "RTO_interface.h"
#include "SevenSegment_interface.h"
#include <util/delay.h>

void vidCount(void);
void vidToggleLED1(void);
void vidToggleLED2(void);
void vidCheckButton(void);

Task_Type Task1;
Task_Type Task2;
Task_Type Task3;
Task_Type Task4;

u8 i;
void main(void) {
	//Initialization

	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,STD_HIGH);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN1,STD_HIGH);

	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN2,STD_LOW);
	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN2,STD_HIGH);


	SevenSegment_vidInit(DIO_PORTB,DIO_PORTC);
	RTO_vidInit();


	Task1.periodicity = 500;
	Task1.first_delay = 0;
	Task1.state = RTO_U8TASK_RUNNING;
	Task1.ptrfun = vidCount;

	Task2.periodicity = 500;
	Task2.first_delay = 0;
	Task2.state = RTO_U8TASK_PAUSED;
	Task2.ptrfun = vidToggleLED1;

	Task3.periodicity = 500;
	Task3.first_delay = 0;
	Task3.state = RTO_U8TASK_PAUSED;
	Task3.ptrfun = vidToggleLED2;

	Task4.periodicity = 500;
	Task4.first_delay = 0;
	Task4.state = RTO_U8TASK_RUNNING;
	Task4.ptrfun = vidCheckButton;


	RTO_vidCreateTask(&Task1,1);
	RTO_vidCreateTask(&Task2,2);
	RTO_vidCreateTask(&Task3,3);
	RTO_vidCreateTask(&Task4,4);
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
