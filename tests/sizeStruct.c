#include <stdio.h>

struct struct_a {
	double a;
	int b;
	char c;
};

struct struct_b {
	int a;
	double b;
	char c;
};

void main(){
	struct struct_a i;
	struct struct_b y;
	printf("Size of %zd\n",sizeof(i));
	printf("Size of %zd\n",sizeof(y));
}
