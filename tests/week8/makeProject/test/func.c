#include <stdio.h>
#include "dio.h"
#include "func.h"

void sayHello(int num) {
	while (num > 0) {
		printf("Hello to you.\n");
		num--;
	}
}
void sayGoodBye(int num) {
	while(num > 0) {
		printf("Good Bye.\n");
		num--;
	}

}
