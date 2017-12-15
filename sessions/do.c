#include <stdio.h>

#define add(x,y) x + y
#define print() do{printf("Hello\n");\
		printf("Second\n");\
		printf("Third\n");}while(0)
void main() {
	int h = 4;
	int m = 6;
	printf("Addition :%d\n",add(h,m));
	print();

	short unsigned int x = 20;
	if (x == 20) 
		print();
	else {
		printf("Error\n");
	}
}
