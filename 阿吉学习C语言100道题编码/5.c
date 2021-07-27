#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
   int n,i;
   float sum;
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
   	sum=sum+1.0/i;
   }
   printf("从1到1/%d的和是%lf",n,sum);
   return 0; 	
}
