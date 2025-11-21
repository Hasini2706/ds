#include<stdio.h>
int getmax(int a[],int n) {
	int max=a[0],i;
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		max = a[i];
	}
	return max;
}

void radixsort(int a[],int n) {
	int big,nod=0,steps,count[10],i,j,k,bucket[10][n],loc,div=1;
	big=getmax(a,n);
	while(big>0)
	{
		nod++;
		big=big/10; //number of digits in max
	}
	for(steps=1;steps<=nod;steps++) { //initialize elements into count array
		for(j=0;j<10;j++) {
			count[j]=0;
		}
		for(i=0;i<n;i++) {
			loc=(a[i]/div)%10;
			bucket[loc][count[loc]++]=a[i];
		}
		k=0;
		for(j=0;j<10;j++) {
			for(i=0;i<count[j];i++) {
				a[k]=bucket[j][i];
				k++;
			}
		}
		div=div*10;
	}
}
void printarray(int a[],int n) {
	int i;
	for(i=0;i<n;++i) {
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Array elements\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\nbefore soting\n");
	printarray(arr,n);
	radixsort(arr,n);
	printf("sorted elements\n");
	printarray(arr,n);
	return 0;
}


