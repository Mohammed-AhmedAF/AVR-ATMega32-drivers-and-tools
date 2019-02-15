#ifndef  _CLOCK_INTERFACE_H
#define _CLOCK_INTERFACE_H

void CLOCK_vidInit(void);
void CLOCK_vidCount(void);
void CLOCK_vidCheckAlarm(void);

/*This macro will be changed according to 
 *the clock source provided to timer and
 *the timer MAX count.
 * */
#define CLOCK_SEC_OVFCOUNT 31250

/*This macro, if defined, will cause AM/PM to 
 *be displayed on LCD next to the digits
 * */
#define CLOCK_AMPM_SWITCH

#define CLOCK_ALARM_SET 1
#define CLOCK_ALARM_CLEARED 0

#endif
