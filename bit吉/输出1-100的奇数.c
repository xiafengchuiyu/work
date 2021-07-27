#include<stdio.h>
int main()
{
	int num=0;
	int y=0;
	for(num=1;num<100;num++)
	{
		y=num%2;
		if(0==y)
		{
			printf(""); 
		}
		else
		printf("%d\n",num);
	}
	return 0;
}
