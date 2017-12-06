#include <stdio.h>

void doSelectionSort(int [], int,char);
void doBubbleSort(int [], int,char);
void doInsertionSort(int [], int, char);
void showArray(int [], int);
int i, j;

#define SORT_DESC "Array sorted in descending order\n"
#define SORT_ASCEN "Array sorted in ascending order\n"

void sort(int arr[], int size,char dir) {
	int sortAlgorithm;
	if (dir == 'a') {
		doBubbleSort(arr,size,dir);
	}
	else {
		printf("------\n");
		printf("Choose sort algorithm:\n");
		printf("1) Bubble Sort\n2) Selection Sort\n3) Insertion Sort\n");
		scanf(" %d",&sortAlgorithm);
		if(sortAlgorithm == 1 || sortAlgorithm == 2 || sortAlgorithm == 3) {
			printf("Ascending or Descending?\n");
			scanf(" %c",&dir);
			switch(sortAlgorithm) {
				case 1:
					doBubbleSort(arr,size,dir);
					break;
				case 2:
					doSelectionSort(arr,size,dir);
					break;
				case 3:
					doInsertionSort(arr,size,dir);
					break;
			}
		}
		else {
			printf("Invalid answer");
		}
 	}
}

void doBubbleSort(int arr[], int size, char dir) {
	if (dir == 'a' || dir == 'A') {
		for(i = 0; i < size; i++) {
			for(j = 0; j < size-1; j++) {
				if (arr[j] > arr[j+1]) {
					int temp;
					temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j]	= temp;
				}
			}
		}
		printf(SORT_ASCEN);		
	}
	else if (dir == 'd' || dir == 'D'){
            	for(i = 0; i < size; i++) {
                         for(j = 0; j < size; j++) {
                                 if (arr[j] < arr[j+1]) {
                                      int temp;
                                         temp = arr[j+1];
                                         arr[j+1] = arr[j];
                                         arr[j]  = temp;
                                 }
                         }
                 }
		printf(SORT_DESC);
	}
	else {
		printf("Invalid answer");
	}
}

void doInsertionSort(int arr [], int size, char dir) {
	int temp, x = 0, i = 0;
	if (dir == 'a' || dir == 'A') {
		while (x < size - 1) {
			while (i >= 0 && arr[i+1] < arr[i]) {
				temp = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = temp;
				i--;
			}
			x++;
			i = x;
		}
	}
	else if (dir == 'd' || dir == 'D') {
		while (x < size - 1) {
			while (i >= 0 && arr[i+1] > arr[i]) {
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				i--;
			}
			x++;
			i = x;
		}	
	}
	else {
		printf("Invalid answer.\n");
	}
}

void doSelectionSort(int arr[], int size, char dir) {
	int min, max, index;
	if(dir == 'a' || dir == 'A') {
		for (i = 0; i < size; i++) {
			min = arr[i];
			for (j = i+1; j < size-i; j++) {
				if (min >= arr[j]) {
					min = arr[j];
					index = j;
				}				
			}
			arr[index] = arr[i];
			arr[i] = min;
		}
	}
	else if (dir == 'd' || dir =='D'){
		for(i = 0; i < size; i++) {
			max = arr[i];
			for(j = i+1; j < size-i; j++) {
			 	if (max <= arr[j]) {
					max = arr[j];
					index = arr[j];		
			}
			arr[index] = arr[i];
			arr[i] = max;
			}	
		}
	}
	else {
		printf("Invalid answer\n");
	}
}		
