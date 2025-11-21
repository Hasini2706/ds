//student details using fuctions and structures
/*#include<stdio.h>
struct student{
	int rollno;
	char name[30];
	float marks;
}s;
void display(struct student s)
{
	printf("%d\n%s\n%f",s.rollno,s.name,s.marks);
}
int main()
{
	struct student s={32,"hasini",43};
	display(s);
}*/
#include<stdio.h>
struct student{
	char name[50];
	int age;
};
void display(struct student s1)
{
	printf("Displaying details....");
	printf("Name:%s\n",s1.name);
	printf("Age:%d\n",s1.age);
}
int main()
{
	struct student s1;
	scanf("%[^\n]s",s1.name);
	scanf("%d",&s1.age);
	display(s1);
	printf("This is aiml 6");
	return 0;
}
