#define _CRT_SECURE_NO_WARNINGS
//1.�����������飻
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
//	short* p = (short*)arr;//ǿ������ת����short*ռ�����ֽڣ�
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
//int i;//ȫ�ֱ�������ʼ��Ĭ����ֵΪ0��
//int main()
//{
//	i--;//-1
	//10000000000000000000000000000001
	//11111111111111111111111111111110
	//11111111111111111111111111111111
//	if (i < sizeof(i))//sizeof()�ķ���ֵ�޷������ͣ�
//	{
//		printf("<\n");
//	}
//	else
//		printf(">\n");
//	return 0;
//}
//ͳ��һ����ת��Ϊ��������������һ�ĸ���
//#include<stdio.h>
//int Calculate_bit_one(unsigned int n)//unsigned int n ��������޷�������
//{
	//����1��
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
	//����2
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
	//����3
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
//	printf("����λ ��\n");
//	for (i = 30; i >= 0; i -= 2)
//	{ 
//		printf("%d ",(n >>i) & 1 );
//	}
//	printf("\n");
//	printf("ż��λ ��\n");
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