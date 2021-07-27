#include<stdio.h> 
int main()
{
	int max=0;
	int min=0;
	int tmp=0;
	int mid=0;
	scanf("%d%d",&max,&min);
	if(max<min)
	{
		tmp=max;
		max=min;
		min=tmp;
	}
	while(max%min)//不是0就要执行循环 
	{
	   	max=min;//算法中的辗转相除法 
	   	min=mid;
	}
	printf("二者的最大公约数是%d\n",min);
	return 0;
}
