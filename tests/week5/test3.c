#include <stdio.h>

#define val 80

#ifndef val
#define x 8
#endif

void main() {
	#if x == 8
		printf("X is defined.\n");
	#else
		printf("X is not defined.\n");
	#endif
}
