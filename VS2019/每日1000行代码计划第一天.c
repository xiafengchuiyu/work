#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p+i));
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr,sz);
//	return 0;
//}
//实现n行乘法口诀表；
//#include<stdio.h>
//void print_table(int n)
//{
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-3d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print_table(n);
//	return 0;
//}
//3.Reverse string order using library functions
//#include<stdio.h>
//#include<string.h>
//void Reverse_print(char*arr)
//{
//	int right = strlen(arr)-1;
//	int left = 0;
//	int tmp = 0;
//	while (left < right)
//	{
//		tmp = arr[right];
//		arr[right] = arr[left];
//		arr[left] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "123245436";
//	Reverse_print(arr);
//	printf("%s\n", arr);
//	return 0;
//}
//4.Use the recursive method to find the reverse order of strings
//#include<stdio.h>
//int my_strlen(char *str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;//!找数组的最后一个字符'\0';
//	}
//	return count;
//}
//void Reverse_string(char arr[])
//{
//	int len = my_strlen(arr);
//	int tmp = 0;
//	tmp = arr[0];
//	arr[0] = arr[len - 1];
//	arr[len - 1] = '\0';
//	if (my_strlen(arr+1) >= 2)
//		Reverse_string(arr + 1);
//	arr[len - 1] = tmp;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	Reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}
//#include<stdio.h>
//int Digitsum(unsigned int n)
//{
//	if (n >= 10)
//	{
//		return Digitsum(n / 10) + n % 10;
//	}
//	else
//	{
//		return n % 10;
//	}
//}
//int main()
//{
//	unsigned int n = 0;
//	scanf("%d",&n);
//	int ret=Digitsum(n);
//	printf("ret=%d", ret);
//	return 0;
//}
//5.Use the recursive method to find the K power of n
//#include<stdio.h>
//double pow(int n, int k)
//{
//	if (k > 1)
//	{
//		return pow(n, k - 1) * n;
//		k = k - 1;
//	}
//	else if (k == 1)
//	{
//		return n;
//	}
//	else if(k==0)
//		return 1;
//	else
//	{
//		return (1.0 / (pow(n, -k)));
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	double ret = pow(n, k);
//	printf("%d ^ %d = %.3lf",n,k,ret);
//	return 0;
//}
//6.Initial structure
//#include<stdio.h>
//typedef struct Stu
//{
//	char name[20];
//	char sex[5];
//	short age;
//	char id[20];
//}Stu;
//int main()
//{
//	Stu s1;
//	struct Stu s2;
//	return 0;
//}
//Nested structure initialization(嵌套结构体初始化)
//#include<stdio.h>
//struct S
//{
//	int a;
//	char b;
//	char str[20];
//	double c;
//};
//struct T
//{
//	char ch[10];
//	struct S s;
//	char *pc;
//};
//int main()
//{
//	char arr[] = "Hello world";
//	struct T t = { "Good",{3,'e',"I love you",3.14},arr};
//	printf("%s\n", t.ch);
//	printf("%d\n", t.s.a);
//	printf("%s\n", t.s.str);
//	printf("%.2lf\n", t.s.c);
//	printf("%s\n", t.pc);
//	return 0;
//}
#include<stdio.h>
typedef struct Stu
{
	char name[20];
	char sex[5];
	short age;
	char tele[12];
}Stu;
void print1(Stu s)
{
	printf("name >:%s\n", s.name);
	printf("sex  >:%s\n", s.sex);
	printf("age  >:%d\n", s.age);
	printf("tele >:%s\n", s.tele);
}
void print2(Stu*ps)
{
	printf("name >:%s\n", ps->name);
	printf("sex  >:%s\n", ps->sex);
	printf("age  >:%d\n", ps->age);
	printf("tele >:%s\n", ps->tele);
}
int main()
{
	Stu s = { "王大锤","男",18,"18992347878" };
	print1(s);
	print2(&s);
	return 0;
}