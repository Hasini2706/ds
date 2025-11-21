#include<stdio.h> 
int main() {
	char str[100];
	int i,sum=0;
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
	{
		sum=sum+(int)str[i];
	}
	printf("%d",sum);
}
