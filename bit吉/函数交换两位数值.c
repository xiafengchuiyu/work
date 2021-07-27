#include<stdio.h>
void swap(int*pa,int*pb)
{
	int tmp=0;
	tmp=*pa;
	*pa=*pb;
	*pb=tmp;
}
int main()
{
	int a=10;
	int b=20;
	int*pa=&a;
	int*pb=&b;
	printf("a=%d,b=%d\n",*pa,*pb);
	swap(&a,&b);
	printf("a=%d,b=%d\n",*pa,*pb);
	return 0;
}
