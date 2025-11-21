#include<stdio.h>
struct student{
	int roll;
	char name[50];
	float marks;
}s1;
int main()
{
	printf("Enter student details: ");
	printf("Enter student roll no: ");
	scanf("%d",&s1.roll);
	printf("Enter student name: ");
	// scanf("%s",&s1.name);
	printf("Enter student marks: ");
	scanf("%f",&s1.marks);
	printf("Student details are:");
	printf("%d\n%s\n%.2f\n",s1.roll,s1.name,s1.marks);
	printf("Size of structure is: %d\n",sizeof(struct student));
	printf("Size of variable is: %d",sizeof(s1));
	return 0;
}
