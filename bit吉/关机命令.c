#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char input[20]={0};
	system("shutdown-s-t60");
	again:
	printf("你的电脑将于1min内关机,如果想要取消关机，请输入:吉旭洋\n");
	scanf("%s",&input);
	if(strcmp(input,"吉旭洋")==0) 
	{
		system("shutdowm-a");
	}
	else
	{
		goto again;
	}
	return 0;
}
