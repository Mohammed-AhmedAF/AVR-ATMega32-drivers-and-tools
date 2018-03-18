#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "RTO_interface.h"



Task_Type Task1;
Task_Type Task2;
Task_Type Task3;

void vidLed1000(void);
void vidLed500(void);
void vidCheckButton(void);

int main(void) {
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,1);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN1,1);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN3,0);
	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN3,1);


	RTO_vidInit();
	Task1.first_delay = 0; //This first_delay if changed will cause one of the tasks to start alone when the microcontrolle
	//is reset
	Task1.periodicity = 300;
	Task1.ptrfun = vidLed500;
	Task1.state = RTO_U8TASK_PAUSED;

	Task2.first_delay = 0;
	Task2.periodicity = 1000;
	Task2.ptrfun = vidLed1000;
	Task2.state = RTO_U8TASK_PAUSED;

	Task3.first_delay = 0;
	Task3.periodicity = 1000;
	Task3.ptrfun = vidCheckButton;
	Task3.state = RTO_U8TASK_RUNNING;



	RTO_vidCreateTask(&Task1,0);
	RTO_vidCreateTask(&Task2,1);
	RTO_vidCreateTask(&Task3,2);

	while(1);
}

void vidLed500(void) {
	TOGGLE_BIT(PORTA,0);
}

void vidLed1000(void) {
	TOGGLE_BIT(PORTA,1);
}

void vidCheckButton(void) {
	if (DIO_u8GetPinValue(DIO_PORTA,DIO_PIN3) == 1) {
		Task1.state = RTO_U8TASK_RUNNING;
		Task2.state = RTO_U8TASK_PAUSED;
	}
	else {
		Task1.state = RTO_U8TASK_PAUSED;
		Task2.state = RTO_U8TASK_RUNNING;
	}
}
