#include <stdio.h>

void printMessage(int);
void printMessage(int n) {
	if(n > 0) {
		printf("This is %d.\n",n);
		n--;
		printMessage(n);
	}
}
void main() {
	int number;
	printf("Enter a number:\n");
	scanf(" %d",&number);
	printMessage(number);	
}

