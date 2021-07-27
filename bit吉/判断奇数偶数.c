#include<stdio.h>
int main()
{
	int num=0,t=0;
	scanf("%d",&num);
	t=num%2;
	if(0==t)
	{
	printf("%d是偶数\n",num);
	}
	else
	{
		printf("%d是奇数\n",num);
	}
	return 0;
}
