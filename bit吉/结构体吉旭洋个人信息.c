#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 struct Student
	{
		char name[20];
		int   age;
		char id[20];
		int height;
		int weight;
	};
int main()
{
	struct Student  s1={"¼ªÐñÑó",18,"2020108104",172,165};
	struct Student* ps=&s1;
	printf("%s ",ps->name);
	printf("%d ",ps->age);
	printf("%s ",ps->id);
	printf("%d ",ps->height);
	printf("%d\n",ps->weight);
	return 0;
}
