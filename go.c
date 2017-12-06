#include <stdio.h>

int main() {
	int x, y;
	printf("Enter a number:\n");
	scanf("%d",&x);
	printf("Enter the second number:\n");
	scanf("%d",&y);
	double xCast = (double) x;
	printf("%lf\n",xCast);
}
