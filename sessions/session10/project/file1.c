#include "types.h"
u8 fun(void) {
	static counter = 0;
	counter++;
	return counter;
}
