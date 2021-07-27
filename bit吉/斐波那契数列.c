#include<stdio.h>
int fib(int n, int a , int b)
{
	
	int c=0;
	
	if(n<=2)
	{
		return 1;
	}
	else if(n>2)
	{
		while(n>2)
	{
	c=a+b;
	a=b;
	b=c;
	n--;	
	}
	return c;
	}	
}
int main()
{
	int n=0;
	int ret=0;
	int a=1;
	int b=1;
	scanf("%d",&n);
	ret=fib(n,a,b);
	printf("第%d个斐波那契数值是%d",n,ret);
	return 0;
}
