#include <stdio.h>

/*We can have the increment of decrement part of the for loop empty
The compiler willn't complain*/

void main() {
	int i;	
	for(i = 0; i <5 ;) {
		printf("counting.\n");
		i++;
	}
}
