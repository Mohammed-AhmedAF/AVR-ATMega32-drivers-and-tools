/*
 * SCHEDULER_interface.h
 *
 * Created: 6/25/2019 3:00:31 PM
 *  Author: Admin
 */ 


#ifndef _SCHEDULER_INTERFACE_H_
#define _SCHEDULER_INTERFACE_H_

#define SCHEDULER_ONETICK 31
#define SCHEDULER_MAXTASKS 20
#define SCHEDULER_NULLTASK 0
#define SCHEDULER_TASKSTATE_RUNNING 1
#define SCHEDULER_TASKSTATE_STOPPED 0
#define SCHEDULER_GLOBALINTERRUPT_RAISED 1
#define SCHEDULER_GLOBALINTERRUPT_LOWERED 0


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

typedef struct {
	u16 u16FirstDelay;
	u16  u16Periodicity; //If u16Periodicity = 0, then it will not repeat
	void (*ptrfun)(void);
	u8 u8State;
} Task_Type; 



void SCHEDULER_vidInit(u8);
void SCHEDULER_vidCountOneTick(void);
void SCHEDULER_vidSchedule(void);
void SCHEDULER_vidCreateTask(Task_Type *,u8);


#endif /* SCHEDULER_INTERFACE_H_ */