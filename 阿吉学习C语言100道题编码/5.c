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
   printf("��1��1/%d�ĺ���%lf",n,sum);
   return 0; 	
}
