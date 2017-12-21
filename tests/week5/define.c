#include <stdio.h>

#define avr 1
#define pic 0

void main() {

#if avr == 1
	printf("I am avr.\n");
#elif pic == 0
	printf("I am pic.\n");
#endif


}
