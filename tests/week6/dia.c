#include <stdio.h>
#include <stdlib.h>

void viewMatrix(int *,int);
void viewMatrix(int * arr,int size) {
	for (int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			printf("%d ",*(arr+(size*i)+j));
		}
		printf("\n");
	}
}

int i, j;
int size;
int lSum = 0, rSum;
int step = 0;
void main() {
	printf("Enter size:\n");
	scanf(" %d", &size);
	fflush(stdin);
	int count = 0;
	int * arr = (int * ) malloc(sizeof(int)*size*size);
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			*(arr+(size*i)+j) = rand()%(size*size);
		}
		printf("----\n");
	} 
	viewMatrix(arr,size);
	/*Summing left diagonal*/
	for (i = 0; i < size; i++) {
		lSum += arr[step+i];
		step = size*(i+1);
		}
	/*Summing right diagonal*/
	step = size-1;
	for (i = 0; i <size;i++) {
		rSum +=arr[step];
		step +=(size-1);
	}
	printf("lSum is %d, rSum is %d\n",lSum,rSum);
	printf("absolute diff is %d\n",rSum - lSum);
	free(arr);
}
