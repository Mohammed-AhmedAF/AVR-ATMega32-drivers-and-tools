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
			*(arr+(size*i)+j) = count++;
		}
		printf("----\n");
	} 
	viewMatrix(arr,size);
	/*Summing diagonal*/
	/*for (i = 0; i < size; i++) {
		printf("lSum is %d\n",lSum);
		lSum += arr[step+i];
		step = size*(i+1);
		printf("Step is %d\n",step);
		}*/
	free(arr);
}
