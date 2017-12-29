#include <stdio.h>
#include <stdlib.h>

void printArray(int *);
void doInsertionSort(int *);

int size;
int * current;
int * start;
int temp;

void main() {
	printf("Enter size of array?\n");
	scanf(" %d",&size);

	int * p = malloc(sizeof(int)*size);
	start = p;
	for (int i = 0; i < size; i++) {
		*p++ = rand()%size+1;
	}
	printArray(start);
	doInsertionSort(start);
	printArray(start);
}

void printArray(int * start) {
	current = start;
	for (int i = 0; i < size; i++) {
		printf("%d ",*(current++));
	}
}

void sortArray(int * start) {
	current = start;
	printf("\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (current[j] > current[j+1]) {
				temp = *(current+j+1);
				*(current+j+1) = *(current+j);
				*(current+j) = temp;
			}
		}
	}
}

void doInsertionSort(int * start) {
	current = start;
	int j=0;
	printf("\n");
	for (int i = 0; i < size; i++) {
		j = i;
		while (j >= 0){
			if (*(current+j) > *(current+j+1)) {	
				temp = *(current+j+1);
				*(current+j+1) = *(current+j);
				*(current+j) = temp;
			}
			j--;
		}
	}

}
