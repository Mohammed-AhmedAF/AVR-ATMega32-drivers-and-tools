#include <stdio.h>

#ifndef avr
#define avr
#define x 1
#endif

#ifdef avr
#define  x 2
#endif

void main() {
	#if x ==1
		printf("I am pic.\n");
	#elif x == 2
		printf("I am avr.\n");
	#endif
}
