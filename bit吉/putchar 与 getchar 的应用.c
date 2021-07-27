#include<stdio.h>
int main()
{
	int ch= 0;
	while((ch=getchar()) != EOF)//注意此处不是 ; 去结束语句,否则无法执行while语句下的打印内容 
	{
		putchar(ch);
	}
	return 0;
}
