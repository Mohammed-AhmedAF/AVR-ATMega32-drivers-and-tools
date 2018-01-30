#include <stdio.h>

void main(void) {
	int a = 1025;
	int * p = &a;

	printf("Address of pointer: %p\n", p, *p);

	char * p0 = (char *) p;
	printf("Address of pointer: %p, value: %d\n", p0, *p0);
	void * pV = p;
	printf("Address of void pointer: %p, value: %d\n",pV);
}
