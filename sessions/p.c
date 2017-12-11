#include <stdio.h>

struct struct_a {
	int x;
	int * ptr;
};

struct struct_b {
	int x;
	int y;
};

void main() {
	struct struct_a stra;
	stra.x = 5;
	stra.ptr= &stra.x;
	printf("value pointed to by ptr %d\n",*stra.ptr);
	printf("value of x is %d\n",stra.x);

	struct struct_b strb;
	struct struct_b * pointer2strb;
	pointer2strb = &strb;
	strb.x = 7;
	strb.y = 8;
	printf("value of x is %d\n",(*pointer2strb).x);
	printf("value of y is %d\n",pointer2strb->y);
}
