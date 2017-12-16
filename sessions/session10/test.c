#include <stdio.h>

#define avr 1
#define pic 0

void main() {
#if pic == 1
	printf("I am pic\n");
#elif avr == 1
	printf("I am avr");
#else
	printf("No controller is on.\n");
#endif
}
