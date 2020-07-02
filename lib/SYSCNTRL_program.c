#include "Macros.h"
#include "Std_Types.h"
#include "SYSCNTRL_private.h"
#include "SYSCNTRL_interface.h"

void SYSCNTRL_vidEnableSleep(u8 u8Mode)
{
	switch(u8Mode)
	{
		case SYSCNTRL_SLEEPMODE_IDLE:
		CLEAR_BIT(MCUCR,SM0);
		CLEAR_BIT(MCUCR,SM1);
		CLEAR_BIT(MCUCR,SM2);
		break;
		case SYSCNTRL_SLEEPMODE_PWDOWN:
		CLEAR_BIT(MCUCR,SM0);
		SET_BIT(MCUCR,SM1);
		CLEAR_BIT(MCUCR,SM2);
		break;

	}
}
