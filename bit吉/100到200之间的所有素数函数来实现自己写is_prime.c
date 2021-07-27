#include<stdio.h>
#include<math.h>
int is_prime(int num1)
{
	int num2;
	for(num2=2;num2<=sqrt(num1);num2++)
	{
		if(num1%num2==0)
		{
			return 0;
		}
	}
}
int main()

{
	int i=0;
	for(i=100;i<=200;i++)
	{
		is_prime(i);
		if(is_prime(i)==0)
		{
			printf("");
		}
		else
		{
		printf("%d ",i);	
		}
	}
	return 0;
} 
