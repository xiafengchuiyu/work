#include<stdio.h>
int main()
{
	
	int year=0;
	int count=0;
	for(year=1000;year<=2000;year++)//[Error] C:\Users\29658\Documents\C-Free\Temp\未命名12.cpp:10: error: non-lvalue in assignment
	{//无左值的意思 
		if(year%4==0&&year%100!=0)//非0是！=0； 
	{
		printf("%d ",year);//闰年是包括可以被4整除却不能被100整除的数还有可以被400整除的数 
		count++;
	}
	else if(year%400==0)
	{
		printf("%d ",year);
		count++;
	}
	}
		printf("\n共有%d个闰年\n",count);
	return 0;
}
