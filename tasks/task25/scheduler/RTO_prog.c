#include "Macros.h"
#include "Std_Types.h"
#include "RTO_interface.h"
#include "DIO_interface.h"
#include <avr/interrupt.h>



Task_Type * Arr_Task[RTO_U8MAXTASKNUM];

u32 OVF_count = 0;
u8 i;
void RTO_vidInit(void) {
	for (i = 0; i < RTO_U8MAXTASKNUM; i++) {
		Arr_Task[i] = RTO_NULL;

	}

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
}

//You can put safety requirements 
void RTO_vidCreateTask(Task_Type * TaskPointer, u8 TaskPriority) {
	Arr_Task[TaskPriority] = TaskPointer;
}

void RTO_vidScheduler(void) {
	//This for loob will be converted to a function
	//Called RTO_vidScheduler
	u8 i;
	for (i = 0; i <RTO_U8MAXTASKNUM; i++) { //2: The number of tasks could be defined as a macro
		if(Arr_Task[i] != RTO_NULL) {
			if(Arr_Task[i]->state == RTO_U8TASK_RUNNING) {
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
}


ISR(TIMER0_OVF_vect) {
	OVF_count++;
	if(OVF_count == 32) {
		OVF_count = 0;
		TCNT0 = 192;
		RTO_vidScheduler();
	}
}
