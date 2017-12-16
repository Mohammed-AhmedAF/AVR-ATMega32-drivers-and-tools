#include <stdio.h>

#define x 1

void main() {
	#if x == 1
		printf("I am pic.\n");
	#error "Error"
	#endif
		printf("Hi ..\n");

}
