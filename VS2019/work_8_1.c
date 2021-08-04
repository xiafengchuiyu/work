#define _CRT_SECURE_NO_WARNINGS
//1.交换两个数组；
 //#include<stdio.h>
//int main()
//{
//	int arr1[] = { 0,1,2,3,4 };
//	int arr2[] = { 5,6,7,8,9 };
//	int tmp = 0;
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	short* p = (short*)arr;//强制类型转换，short*占两个字节；
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		*(p + i) = 0;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0x11223344;
//	char* p = (char*)&a;
//	*p = 0;
//	printf("%x\n", a);
//	return 0;
//}
//int i;//全局变量不初始化默认其值为0；
//int main()
//{
//	i--;//-1
	//10000000000000000000000000000001
	//11111111111111111111111111111110
	//11111111111111111111111111111111
//	if (i < sizeof(i))//sizeof()的返回值无符号类型；
//	{
//		printf("<\n");
//	}
//	else
//		printf(">\n");
//	return 0;
//}
//统计一个数转换为二进制数后其中一的个数
//#include<stdio.h>
//int Calculate_bit_one(unsigned int n)//unsigned int n 代表的是无符号数；
//{
	//方法1：
	/*int count = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n=n/2;
	}*/
	//return count;
	//方法2
	/*int count = 0; 
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((n >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;*/
	//方法3
	/*int count = 0;
	while (n)
	{
		n=n& (n - 1);
		count++;
	}
	return count;
}
int main()
{
	int a = 0;
	int ret=0;
	scanf("%d", &a);
	ret = Calculate_bit_one(a);
	printf("count=%d", ret);
	return 0;
}*/
#include<stdio.h>
//void print(int n)
//{
//	int i = 0;
//	printf("奇数位 ：\n");
//	for (i = 30; i >= 0; i -= 2)
//	{ 
//		printf("%d ",(n >>i) & 1 );
//	}
//	printf("\n");
//	printf("偶数位 ：\n");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}
int main()
{
	int a = 10;
	int b = 15;
	printf("before : a=%d,b=%d\n",a,b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("after : a=%d,b=%d\n", a, b);
	return 0;
}