#include<stdio.h>
void print(int n)
{
	if(n/10>9)
    {
	print(n/10);
    }
    printf("%d ",(n/10)%10);
}
int main()
{
	int n=0;
	scanf("%d",&n);
	print(n);
	printf("%d",n%10);
	return 0;
}
