#include "types.h"
#include <stdio.h>
u32 power;
void funCalPower(u32 x,u32 y) {
	u32 i;
	power = 1;
	for(i = 0; i < y; i++) {
		power *= x;
	}
}
