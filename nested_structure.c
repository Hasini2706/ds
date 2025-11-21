//employee details using nested structure
#include<stdio.h>
struct student{
	int roll;
	char *name;
	struct DOB{
		int dd;
		int mm;
		int yyyy;
	}d;
}s;
int main()
{
	s.roll=223;
	s.name="hasini";
	s.d.dd=27;
	s.d.mm=06;
	s.d.yyyy=2007;
	printf("%d\n%s\n%d-%d-%d",s.roll,s.name,s.d.dd,s.d.mm,s.d.yyyy);
	return 0;
}
