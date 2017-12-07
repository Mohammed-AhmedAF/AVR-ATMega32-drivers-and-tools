#include <stdio.h>
#include <stdlib.h>

int arr[100];
int num, size;	
int i;
void main() {
	printf("Enter size of array (between 1 and 100)\n");
	scanf(" %d",&size);
	for(i = 0; i < size; i++) {
		num = rand()%size+1;
		printf("%d\n",num);
	}
}
