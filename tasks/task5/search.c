#include <stdio.h>

void doLinearSearch(int [], int,int);
void doBinarySearch(int [], int,int);
void doInsertionSort(int [], int,char);

void search(int arr [], int size) {
	int searchType;
	int searchNumber;
	printf("Enter search type:\n");
	printf("1) Linear search\n2) Binary search\n");
	scanf(" %d", &searchType);
	printf("Enter a number to search for: \n");
	scanf(" %d",&searchNumber);
	switch(searchType){
		case 1:
			doLinearSearch(arr,size,searchNumber);
			break;
		case 2:
			doBinarySearch(arr,size,searchNumber);
			break;
		default:
			printf("Invalid answer.\n");
	}
}

void doLinearSearch(int arr[], int size,int searchNumber) {
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i] == searchNumber) 	{
			printf("Index is %d\n", i);
		}
	}
}

void doBinarySearch(int arr[], int size,int searchNumber) {
	int i, current, found = 0;
	int runs = size;
	int holder,index;
	doInsertionSort(arr,size,'a');
	current = size/2;
	while(found = runs) {	
		holder = current;
		if(searchNumber == arr[current]) {
			found = 1;
			index = current;
			break;
		}
		else if (searchNumber > arr[current]) {
			current = current + current/2;
		}
	 	else if (searchNumber < arr[current]){
			current = current - current/2;
		}
		if (current == 1 && holder == 1) {
			current = 0;
		}
		runs--;
	}
	if (found == 1) {
		printf("Index is %d.\n",index);
	}
	else {
		printf("Element is not in the array.\n");
	}
}
