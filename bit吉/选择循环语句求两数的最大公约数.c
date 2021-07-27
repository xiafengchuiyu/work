#include<stdio.h>
int main()
{
	int max=0;
	int min=0;
	int tmp=0;
	int i=0;
	scanf("%d%d",&max,&min);
	if(max<min)
	{
		tmp=max;
		max=min;
		min=tmp;
	}
	if(max%min==0)
	{
		printf("最大公约数是%d\n",min);
	}
	else
	{
		for(i=min;i>0;i--)
		{
			if(max%i==0)
			{
				printf("最大公约数是%d\n",i);
			}
			break;
		}
	}
	return 0;
}
