#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char input[20]={0};
	system("shutdown-s-t60");
	again:
	printf("��ĵ��Խ���1min�ڹػ�,�����Ҫȡ���ػ���������:������\n");
	scanf("%s",&input);
	if(strcmp(input,"������")==0) 
	{
		system("shutdowm-a");
	}
	else
	{
		goto again;
	}
	return 0;
}
