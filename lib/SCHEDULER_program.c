/*
 * SCHEDULER_program.c
 *
 * Created: 6/25/2019 2:49:18 PM
 *  Author: Admin
 */ 

#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "INTERRUPTS_interface.h"
#include "SCHEDULER_interface.h"


Task_Type * Tasks_Array[SCHEDULER_MAXTASKS];

volatile u8 u8OVFCount;

void SCHEDULER_vidInit(u8 u8GlobalInterruptFlag) {
	TIMER0_vidInit(TIMER0_WGM_NORMAL,TIMER0_COM_NORMAL,TIMER0_CLK_1);
	
	INTERRUPTS_vidEnableInterrupt(INTERRUPTS_TIMER0_OVF);
	INTERRUPTS_vidPutISRFunction(TIMER0_OVF_VECT,SCHEDULER_vidCountOneTick);
	
	if (u8GlobalInterruptFlag == SCHEDULER_GLOBALINTERRUPT_RAISED) {
		INTERRUPTS_vidSetGlobalInterruptFlag();
	}
	else {
	}
	
}

void SCHEDULER_vidCreateTask(Task_Type * task, u8 u8TaskPriority) {
	Tasks_Array[u8TaskPriority] = task;
}

void SCHEDULER_vidSchedule(void) {
	u8 u8TaskIndex = 0;
	for (u8TaskIndex = 0; u8TaskIndex < SCHEDULER_MAXTASKS; u8TaskIndex++) {
		if (Tasks_Array[u8TaskIndex] != SCHEDULER_NULLTASK) {
			if (Tasks_Array[u8TaskIndex]->u8State == SCHEDULER_TASKSTATE_RUNNING) {
				if (Tasks_Array[u8TaskIndex]->u16FirstDelay == 0) {
					Tasks_Array[u8TaskIndex]->ptrfun();
					Tasks_Array[u8TaskIndex]->u16FirstDelay = Tasks_Array[u8TaskIndex]->u16Periodicity-1;					
				}
				else {
					Tasks_Array[u8TaskIndex]->u16FirstDelay--;
				}
			}
		}
	}
}

void SCHEDULER_vidCountOneTick(void) {
	u8OVFCount++;
	if (u8OVFCount == SCHEDULER_ONETICK) {
		u8OVFCount = 0;
		SCHEDULER_vidSchedule();
	}
}

