#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void printReversed(int *,int);

void printReversed(int * arr,int size) {
	int i;
	arr--;
	for(i = size; i > 1; i--) {
		printf("%d ",*(arr));
		arr--;
	}
}

int main(){
    int n; 
    scanf("%d",&n);
    int *arr = malloc(sizeof(int) * n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",arr);
	arr++;
    }
    printReversed(arr,n);
    return 0;
}

