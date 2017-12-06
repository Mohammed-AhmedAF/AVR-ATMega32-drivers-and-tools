#include <stdio.h>

void main() {
	int x = 2, n = 1;
	char y = 'a';
	printf("y=%c \n",y);
	printf("++y=%c \n",++y);
	printf("y in dec = %d \n",y);
	printf("x \n");
	printf("x++ = %d\n",x++);
	printf("x = %d\n", x);
	printf("x + 1 = %d\n", x+1);
	printf("x = %d\n",x);
	printf("++x = %d\n",++x);
	printf("x = %d\n",x);
	n = n + x++;
	printf("n = %d\n", n);
	printf("x = %d\n",x);
}
