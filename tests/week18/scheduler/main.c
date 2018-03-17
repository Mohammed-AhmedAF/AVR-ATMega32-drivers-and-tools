#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "RTO_interface.h"



Task_Type Task1;
Task_Type Task2;

void vidLed1000(void);
void vidLed500(void);

int main(void) {
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,1);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN1,1);

	RTO_vidInit();
	Task1.first_delay = 0; //This first_delay if changed will cause one of the tasks to start alone when the microcontrolle
	//is reset
	Task1.periodicity = 500;
	Task1.ptrfun = vidLed500;
	Task1.state = RTO_U8TASK_RUNNING;

	Task2.first_delay = 0;
	Task2.periodicity = 1000;
	Task2.ptrfun = vidLed1000;
	Task2.state = RTO_U8TASK_RUNNING;

	RTO_vidCreateTask(&Task1,0);
	RTO_vidCreateTask(&Task2,1);

	while(1);
}

void vidLed500(void) {
	TOGGLE_BIT(PORTA,0);
}

void vidLed1000(void) {
	TOGGLE_BIT(PORTA,1);
}
