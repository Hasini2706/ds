//student details using union
#include<stdio.h>
union student
{
	int rollno;
	char name[20];
	float marks;
}s,s1,s2;
int main()
{
	
	scanf("%d%s%f",&s.rollno,&s1.name,&s2.marks);
	printf("%d\n%s\n%f",s.rollno,s1.name,s2.marks);

	return 0;
}
