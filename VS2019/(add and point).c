//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 2,3,9,1,2,8,9,2,41 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *p);
//		p = p + 1;
//	}
//	return 0;
//}
//#include<stdio.h>
//#include"add.h"
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int sum = 0;
//	scanf("%d%d", &a, &b);
//	sum = add(a, b);
//	printf("add=%d", sum);
//	return 0;
//}
#include<stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;
	**ppa = 18;
	printf("%d\n", a);
	printf("%d", *pa);
	printf("%d", **ppa);
	return 0;
}
