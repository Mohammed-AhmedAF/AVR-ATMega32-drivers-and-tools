#include <stdio.h>

struct bor3y {
	int n;
	char a;
	double b;
};

void main(void) {
	struct bor3y x;
	
	x.n = 3;
	x.a = 'g';
	x.b = 3.8;

	printf("%d %c %f\n",x.n,x.a,x.b);
	scanf(" %d %c %f",&x.n,&x.a,&x.b);
	printf("integer member equals %d %c %f\n",x.n,x.a,x.b);
}
