#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define RAND_MAX 0x7FFF
void menu()
{
	printf("***********************\n");
	printf("**��ѡ��0.�˳���Ϸ***\n");
	printf("**        1.��ʼ��Ϸ***\n");
	printf("***********************\n");
}
void game()
{   
    int ret=0;
	int guess=0;
	ret=rand()%100+1;
	while(1)
	{
	printf("�����������µ�����>:\n");
	scanf("%d",&guess);
	if(guess==ret)
	{
		printf("����������ȷ\n");
		break;
	}
	else if(guess>ret)
	{
		printf("�������ֽϴ�\n");
	}
	else if(guess<ret)
	{
		printf("�������ֽ�С\n");
	}
	}
}
int main()
	{
	srand((unsigned int)time(NULL));
	int input=0;
	do{
	menu();
	scanf("%d",&input);
	switch(input)
	{
		case 0:
		printf("���˳���Ϸ\n");
		break;
		case 1:
		printf("ף����Ϸ���\n");
		game();
		break;
		default:
		printf("error\n");
		 
	}
	} while(input);
	return 0;
}


  
    