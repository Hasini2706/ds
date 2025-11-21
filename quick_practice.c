#include<stdio.h>
void quicksort(int a[],int first,int last) {
	int i,j,temp,pivot;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
	 while(i<j)
	 {
	 	while(a[i]<=a[pivot]&&i<last)
	 	i++;
	 	while(a[j]>a[pivot])
	 		j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		
	 }
	 temp=a[pivot];
	 a[pivot]=a[j];
	 a[j]=temp;
	 quicksort(a,first,j-1);
	 quicksort(a,j+1,last);
	}
}
int main()
{
	int arr[25],i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		
	}quicksort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
}
