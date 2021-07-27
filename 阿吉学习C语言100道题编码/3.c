#include<stdio.h>
int main()
{
	float a,b,c,d,sum,average;
	scanf("%f%f%f%f",&a,&b,&c,&d);
	sum=a+b+c+d;
	average=sum/4;
	printf("sum is %.0f,average is %.2f",sum,average);
	return 0;
}
