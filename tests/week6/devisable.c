#include <stdio.h>
#include <stdlib.h>

void displayArray(int *);
int count (int *, int, int);

int n, k;
int i,j;

void main() {
	printf("Enter size and k:\n");
	scanf("%d %d",&n,&k);
	int * a = malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	displayArray(a);
	int c = count(a,n,k);
	printf("\nCount is %d\n",c);
}

void displayArray(int * a) {
	for(i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
}

int count(int * a,int n,int k) {
	int count = 0;
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if((a[i]+a[j])%k == 0) {
				count++;
			}
		}
	}
	return count;
}
