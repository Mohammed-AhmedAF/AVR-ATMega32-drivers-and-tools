#include <stdio.h>

void swap(int *, int *p);

void main() {
	int a, b;
	
	a = 5;
	b = 7;

	int * p2a = &a;
	int * p2b = &b;

	swap(p2a,p2b);
	printf("X is %d\n",a);
}

void swap(int * p2a, int * p2b) {
	int temp = *p2a;

	*p2a = *p2b;
	
	*p2b = temp;
}
