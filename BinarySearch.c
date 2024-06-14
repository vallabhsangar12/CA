//Binary Search Program using Iterative methods

#include<stdio.h>
int comp=0;
int binarySearch(int arr[],int left,int right,int target)
{
  while(left<=right)
  {
    int mid=left+(right-left)/2;

    if(arr[mid]==target)
    {
      comp++;
      return mid;
    }
    else if(arr[mid]<target)
    {
      comp++;
      left=mid+1;
    }
    else{
      comp++;
      right=mid-1;
    }
  }
  return -1;
}
int main()
{
  int arr[]={2,3,4,10,12};
  int n=sizeof(arr)/sizeof(arr[0]);
  int target=17;
  int result=binarySearch(arr,0,n-1,target);
  if(result==-1)
  {
    printf("Element is not present in array!");
  }
  else{
    printf("Element is found at index %d",result);
  }

  printf("\nComparisons:%d",comp);
  return 0;
}
