#include<stdio.h>
int fac(int n)
{
	if(n==1)
	{
	return 1;
	}
	else if(n>1)
	{
	return n*fac(n-1);	
	}
}
int main()
{
	int n=0;
	int mul=0;
	scanf("%d",&n);
	mul=fac(n);
	printf("%d�Ľ׳���%d",n,mul);
	return 0;
}
