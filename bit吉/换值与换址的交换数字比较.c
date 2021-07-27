#include<stdio.h>
void swap1(int x,int y)
{
	int tmp=0;
	tmp=x;
	x=y;
	y=tmp;
}
void swap2(int*px,int*py)
{
	int tmp=0;
	tmp=*px;
	*px=*py;
	*py=tmp;
}
int main()
{
	int num1=10;
	int num2=20;
	int*pnum1=&num1;
	int*pnum2=&num2;
	printf("num1=%d,num2=%d\n",num1,num2);
	swap1(num1,num2);
	printf("num1=%d,num2=%d\n",num1,num2);
	swap2(&num1,&num2);
	printf("num1=%d,num2=%d\n",num1,num2);
	return 0;
} 
