#include <stdio.h>

void main(void) {
	int a = 6;
	int * pa = &a;
	int i;
	for (i =0; i < 100; i++) {
		*pa = i;
		printf("A is %d\n",a);
	}

}
