#include<stdio.h>
int Add(int x,int y);
int Sub(int x,int y);
int Mul(int x,int y);
float Div(int x,int y);
int main()
{
	int a=0;
	int b=0;
	int he=0;
	int cha=0;
	int ji=0;
	float s=0.0;
	scanf("%d%d",&a,&b);
	he=Add(a,b);
	printf("两数之和是%d\n",he);
	cha=Sub(a,b);
	printf("两数之差是%d\n",cha);
	ji=Mul(a,b);
	printf("两数之积是%d\n",ji);
	s=Div(a,b);
	printf("两数之商是%.2f\n",s);
	return 0;
}
int Add(int x, int y)
{
	int z=x+y;
    return z;
}
int Sub(int x,int y)
{
	int z=x-y;
	return z;
}
int Mul(int x,int y)
{
	int z=x*y;	
	return z;
}
float Div(int x,int y)
{
	float z=x/y;
	return z;
}
