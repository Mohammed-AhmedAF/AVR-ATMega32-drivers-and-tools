#include<stdio.h>
#include<string.h>

int * splite_fun(int arr[], int size,int search);
int arr_return[3]={0};
int main(void)
{
	
	int arr[4]={1,2,3,4};
	int i=0;
	int * ptr = splite_fun(arr,12,4);
	for(i=0;i < 3;i++)
	{
	printf("%d\n",*ptr++);
   }

	return 0;

}

int * splite_fun(int arr[] , int size, int search)
{
	int i;
	int * ptr;
	ptr=arr_return;
	int searchIndex = 0;
	
	for(i=0;i<size;i++)
	{
		if(arr[i]==search)
		{
			searchIndex = i;
			break;
		}
    }	
	for (i = searchIndex -1; i >= 0; i--) {
		arr_return[i] = arr[i];
	}
	return ptr;
}
