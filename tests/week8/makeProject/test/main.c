#include <stdio.h>
#include "dio.h"
#include "func.h"

void main() {
	int num;
	printf("Enter number:\n");
	scanf("%d", &num);
	sayHello(num);
	sayGoodBye(num);
}
