#include<stdio.h>
int main()
{
	int i=0;
	while(i<10)
	{
		i++;
		if(5==i) continue;
		printf("%d ",i);
	}
	return 0;
}
