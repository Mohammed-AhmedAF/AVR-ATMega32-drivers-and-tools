#include <stdio.h>
#include "types.h"
void funCalPower(u32,u32);
void funPrintPower(void);

u32 x = 3;
u32 y = 1;

void main() {
	while (fun() < 20) {
		funCalPower(x,y+fun());
		funPrintPower();
	}
}
