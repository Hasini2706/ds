//book details using structure or union
#include<stdio.h>
union book{
	int nofpages;
	char author[20];
	char name[30];
}s,s1,s2;
int main()
{
	scanf("%d\n%[\^n]s\n%[\^n]s\n",&s.nofpages,&s1.author,&s2.name);
	printf("%d\n%s\n%s",s.nofpages,s1.author,s2.name);
	return 0;
}
