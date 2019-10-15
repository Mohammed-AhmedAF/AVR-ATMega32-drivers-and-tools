/*
 * SCHEDULER_interface.h
 *
 * Created: 6/25/2019 3:00:31 PM
 *  Author: Admin
 */ 


#ifndef _SCHEDULER_INTERFACE_H_
#define _SCHEDULER_INTERFACE_H_

#define SCHEDULER_ONETICK 5
#define SCHEDULER_MAXTASKS 3
#define SCHEDULER_NULLTASK 0
#define SCHEDULER_TASKSTATE_RUNNING 1
#define SCHEDULER_TASKSTATE_STOPPED 0
#define SCHEDULER_GLOBALINTERRUPT_RAISED 1
#define SCHEDULER_GLOBALINTERRUPT_LOWERED 0

#define _SCHEDULER_GETID(Task) &Task

/*Task definitions*/
#define SCHEDULER_TASK0 0
#define SCHEDULER_TASK1 1
#define SCHEDULER_TASK2 2
#define SCHEDULER_TASK3 3
#define SCHEDULER_TASK4 4
#define SCHEDULER_TASK5 5
#define SCHEDULER_TASK6 6
#define SCHEDULER_TASK7 7
#define SCHEDULER_TASK8 8
#define SCHEDULER_TASK9 9
#define SCHEDULER_TASK10 10
#define SCHEDULER_TASK11 11

#define SCHEDULER_TIMER_MODE_NORMAL 0
#define SCHEDULER_TIMER_MODE_CTC 1

#define SCHEDULER_TIMER_CLKPRES_NOCLK 0
#define SCHEDULER_TIMER_CLKPRES_1 1
#define SCHEDULER_TIMER_CLKPRES_8 2
#define SCHEDULER_TIMER_CLKPRES_64 3 
#define SCHEDULER_TIMER_CLKPRES_256 4 
#define SCHEDULER_TIMER_CLKPRES_1024 5

typedef struct {
	u16 u16FirstDelay;
	u16  u16Periodicity; //If u16Periodicity = 0, then it will not repeat
	void (*ptrfun)(void);
	u8 u8State;
} Task_Type; 



void SCHEDULER_vidInit(u8);
void SCHEDULER_vidInitExpanded(u8 u8TimerMode, u8 u8CLKPrescaler, u8 u8OCRValue, u8 u8GlobalInterruptFlag);
void SCHEDULER_vidCountOneTick(void);
void SCHEDULER_vidSchedule(void);
void SCHEDULER_vidCreateTask(Task_Type *,u8);
void SCHEDULER_vidDeleteTask(u8);


#endif /* SCHEDULER_INTERFACE_H_ */
