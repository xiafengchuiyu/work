//输入一个三位数，计算该数各位上的数字之和，如果在1到12之间，则输出与数和相对应的月份的英文名称，否则输出***
#include<stdio.h>
struct month
{
	int num1;
	char name1[20];
	int num2;
	char name2[20];
	int num3;
	char name3[20];
	int num4;
	char name4[20];
	int num5;
	char name5[20];
	int num6;
	char name6[20];
	int num7;
	char name7[20];
	int num8;
	char name8[20];
	int num9;
	char name9[20];
	int num10;
	char name10[20];
	int num11;
	char name11[20];
	int num12;
	char name12[20];
};
int main()
{
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	int sum=0;
	struct month m12={1,"January",2,"Feburary",3,"March",4,"April",5,"May",6,"June",7,"July",8,"August",9,"September",10,"October",11,"November",12,"December"};
	struct month*pm=&m12;
	scanf("%d",&a);
	b=a%10;
	c=(a/10)%10;
	d=a/100;
	sum=b+c+d;
	if(1<=sum&&sum<=12)
	{
	     if(sum==1)
	     {
		  printf("%d ",pm->num1);
		  printf("%s",pm->name1);
	     }	
	     if(sum==2)
	     {
		  printf("%d ",pm->num2);
		  printf("%s",pm->name2);
	     }	
	     if(sum==3)
	     {
		  printf("%d ",pm->num3);
		  printf("%s",pm->name3);
	     }	
	     if(sum==4)
	     {
		  printf("%d ",pm->num4);
		  printf("%s",pm->name4);
	     }	
	     if(sum==5)
	     {
		  printf("%d ",pm->num5);
		  printf("%s",pm->name5);
	     }	
	     if(sum==6)
	     {
		  printf("%d ",pm->num6);
		  printf("%s",pm->name6);
	     }	
	     if(sum==7)
	     {
		  printf("%d ",pm->num7);
		  printf("%s",pm->name7);
	     }	
	     if(sum==8)
	     {
		  printf("%d ",pm->num8);
		  printf("%s",pm->name8);
	     }	
	     if(sum==9)
	     {
		  printf("%d ",pm->num9);
		  printf("%s",pm->name9);
	     }	
	     if(sum==10)
	     {
		  printf("%d ",pm->num10);
		  printf("%s",pm->name10);
	     }	
	     if(sum==11)
	     {
		  printf("%d ",pm->num11);
		  printf("%s",pm->name11);
	     }	
	     if(sum==12)
	     {
		  printf("%d ",pm->num12);
		  printf("%s",pm->name12);
	     }	
	}
	else
	{
		printf("***\n");
	}
	return 0;
}
