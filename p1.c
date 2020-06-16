//demo program to understand struct
#include<stdio.h>
struct student s1=
{
	s1.name="AAA";
	s1.marks=90;
};
int main()
{
	struct student s1;
	printf("The name of studnt is %s",s1.name);
	printf("The marks is %d",s1.marks);
}

