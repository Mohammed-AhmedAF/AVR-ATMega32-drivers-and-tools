#include <stdio.h>

void main(void) {
	int a = 9;
	int * p = &a;
	printf("Pointer is %p\n",p);
	printf("Value pointed to by pointer: %d\n",*p);
	printf("Address of int variable: %p\n",&a);
	printf("Address of pointer itself: %p\n",&p);

}
