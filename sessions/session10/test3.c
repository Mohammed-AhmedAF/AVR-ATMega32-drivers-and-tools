#include <stdio.h>

/*Important*/

#define avr 1

#ifndef avr
#define avr
#define x 1
#endif

void main() {
	#if x == 1
		printf("I am pic.\n");
	#elif x == 2
		printf("I am avr.\n");
	#elif x == 3
		printf("I am something else.\n");
	#elif x == 4
		printf("I am not here.\n");
	#else
		printf("No controller is on.\n");
	#endif
}
