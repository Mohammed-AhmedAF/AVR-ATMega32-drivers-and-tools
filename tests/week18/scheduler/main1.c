#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include <avr/interrupt.h>

typedef struct {
	u32 first_delay;
	u32 periodicity; //If periodicity = 0, then it will not repeat
	void (*ptrfun)(void);
} Task_Type;


Task_Type Task1;
Task_Type Task2;

void vidLed1000(void);
void vidLed500(void);
Task_Type * Arr_Task[2];

u8 OVF_count = 0;
u8 i;
int main(void) {
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,1);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN1,1);
		
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
	CLEAR_BIT(TCCR0,6);

	TCNT0 = 192;
	SET_BIT(TIMSK,0);

	SET_BIT(SREG,7); 


	Task1.first_delay = 500; //This first_delay if changed will cause one of the tasks to start alone when the microcontrolle
	//is reset
	Task1.periodicity = 500;
	Task1.ptrfun = vidLed500;
	Task1.state = RTO_U8TASK_RUNNING;

	Task2.first_delay = 0;
	Task2.periodicity = 1000;
	Task2.ptrfun = vidLed1000;
	Task2.state = RTO_U8TASK_RUNNING;
	
	Arr_Task[0] = &Task1;
	Arr_Task[1] = &Task2;

	while(1);
}

void vidLed500(void) {
	TOGGLE_BIT(PORTA,0);
}

void vidLed1000(void) {
	TOGGLE_BIT(PORTA,1);
}

ISR(TIMER0_OVF_vect) {
	OVF_count++;
	if(OVF_count == 32) {
		OVF_count = 0;
		TCNT0 = 192;
		//This for loob will be converted to a function
		//Called RTO_vidScheduler
		for (i = 0; i <2; i++) { //2: The number of tasks could be defined as a macro
			if(Arr_Task[i]->first_delay == 0) {
				Arr_Task[i]->ptrfun();
				Arr_Task[i]->first_delay = Arr_Task[i]->periodicity-1;
			}
			else {
				Arr_Task[i]->first_delay--;
			}
		}
	}
}

//Assume 
