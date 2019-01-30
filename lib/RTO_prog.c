/*
 * Author: Mohamed Ahmed Abd Al-Fattah
 * Purpose: A simple Real Time OS kernel
 *
 */


#include "Macros.h"
#include "Std_Types.h"
#include "RTO_interface.h"
#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "INTERRUPTS_interface.h"
#include <avr/interrupt.h>



Task_Type * Arr_Task[RTO_U8MAXTASKNUM];

u32 OVF_count = 0;
u8 i;
void RTO_vidInit(void) {
	for (i = 0; i < RTO_U8MAXTASKNUM; i++) {
		Arr_Task[i] = RTO_NULL;

	}
	TIMER0_vidInit(TIMER0_WGM_NORMAL,TIMER0_COM_NORMAL,TIMER0_CLK_1);
	INTERRUPTS_vidSetInterruptEnable(INTERRUPTS_TOIE_0);
	INTERRUPTS_vidSetGlobalInterruptFlag();
	INTERRUPTS_vidPutISRFunction(RTO_vidOVFCount);
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
void RTO_vidOVFCount(void) {
	OVF_count++;
	if(OVF_count == 32) {
		OVF_count = 0;
		TIMER0_vidSetTCRegister(192);
		RTO_vidScheduler();
	}
}
