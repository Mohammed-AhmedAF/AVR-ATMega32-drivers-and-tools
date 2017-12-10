#include <stdio.h>

void main() {
	int a, b;
	double c;
	printf("Enter the first number:\n");
	scanf(" %d", &a);
	printf("Enter the second number:\n");
	scanf(" %d", &b);
	c = (double) a;
	printf("Result of division: %lf\n", c/b);
}
