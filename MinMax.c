2#include<stdio.h>
int min,max;
int a[50];
int comp=0;
void minmax(int i,int j)
{
	int max1,min1,mid;
	if(i==j)
	{
		min=max=a[i];
		comp++;
	}
	else
	{
		if(i==j-1)
		{
			if(a[i]<a[j])
			{
				max=a[j];
				min=a[i];
				comp++;
			}
			else
			{
				max=a[i];
				min=a[j];
				comp++;
			}
		}
		else
		{
			mid=(i+j)/2;
			minmax(i,mid);
			max1=max;
			min1=min;
			minmax(mid+1,j);
			if(max<max1)
			{
				max=max1;
				comp++;
			}
			if(min>min1)
			{
			     min=min1;
			     comp++;
			}
		}
	}
}
int main()
{
	int i,num;
	printf("\n Enter the total number of numbers:");
	scanf("%d",&num);
	printf("Enter the Numbers:\n");
	for(i=1;i<=num;i++)
	{
		scanf("%d",&a[i]);
	}
	min=a[0];
	max=a[0];
	minmax(1,num);
	printf("Minimum element in an array:%d\n",min);
	printf("Maximum element in an array:%d\n",max);
	printf("\n Comparisons:%d",comp);
	return 0;
	
}
