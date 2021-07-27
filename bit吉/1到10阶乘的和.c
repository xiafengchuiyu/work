#include<stdio.h>
int main()
{
	int i,j,sum,fac;
	sum=0;
	for(i=1;i<=3;i++)
	{
		fac=1;
		for(j=1;j<=i;j++)
		{
			fac=fac*j;
		}
	    sum=sum+fac;
	}
	printf("1!+2!+......+10!µÄÖµÊÇ%d\n",sum);
	return 0;
}
