#include<stdio.h>
int main()
{
	int num=0,t=0;
	scanf("%d",&num);
	t=num%2;
	if(0==t)
	{
	printf("%d��ż��\n",num);
	}
	else
	{
		printf("%d������\n",num);
	}
	return 0;
}
