#include <stdio.h>

#define a 77
#define b 55

void main() {
	#if a == 77
		printf("Enter to a new world.\n");
		printf("Go here.\n");
	#elif b == 6
		printf("Enter to a second new world.\n");
		printf("Go there.\n");
	#endif
}
