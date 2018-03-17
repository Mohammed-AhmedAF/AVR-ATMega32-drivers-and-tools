#ifndef _RTO_INTERFACE_H
#define _RTO_INTERFACE_H
#define RTO_NULL  0
#define RTO_U8MAXTASKNUM 20
#define RTO_U8TASK_RUNNING 1
#define RTO_U8TASK_PAUSED 0

typedef struct {
	u32 first_delay;
	u32 periodicity; //If periodicity = 0, then it will not repeat
	void (*ptrfun)(void);
	u8 state;
} Task_Type;

void RTO_vidInit(void);
void RTO_vidCreateTask(Task_Type *, u8 Task_Priority);
void RTO_vidScheduler(void);

#endif
