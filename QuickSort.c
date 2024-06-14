#include<stdio.h>
int comp=0;

void swap(int arr[],int a,int b)
{
	int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	
	int i=low-1;
	for(int j=low;j<=high-1;j++)
	{
		comp++;
		if(arr[j]<pivot)
		{
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,high);
	return(i+1);

}
void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);
		
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}
void printArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[]={10,7,8,9,1,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	printf("Original Array:\n");
	printArray(arr,n);
	
	quickSort(arr,0,n-1);
	
	printf("Sorted Array:\n");
	printArray(arr,n);
	
	printf("\n Comparisons:%d",comp);
}
