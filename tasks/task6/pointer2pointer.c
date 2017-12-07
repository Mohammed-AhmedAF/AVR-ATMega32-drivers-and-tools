#include <stdio.h>

void main() {
	int x = 5;
	int * ax = &x;
	int ** bx = &ax;
	

	printf("The value of x is %d, address is %p\n",x,&x);
	printf("The address held by pointer ax is %p, the address of ax is %p\n",ax,&ax);
	printf("The address held by bx is %p, the final value it points to is %d\n",bx,**bx);
}
