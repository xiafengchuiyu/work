#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define RAND_MAX 0x7FFF
void menu()
{
	printf("***********************\n");
	printf("**请选择：0.退出游戏***\n");
	printf("**        1.开始游戏***\n");
	printf("***********************\n");
}
void game()
{   
    int ret=0;
	int guess=0;
	ret=rand()%100+1;
	while(1)
	{
	printf("请输入你所猜的数字>:\n");
	scanf("%d",&guess);
	if(guess==ret)
	{
		printf("所猜数字正确\n");
		break;
	}
	else if(guess>ret)
	{
		printf("所猜数字较大\n");
	}
	else if(guess<ret)
	{
		printf("所猜数字较小\n");
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
		printf("已退出游戏\n");
		break;
		case 1:
		printf("祝您游戏愉快\n");
		game();
		break;
		default:
		printf("error\n");
		 
	}
	} while(input);
	return 0;
}


  
    