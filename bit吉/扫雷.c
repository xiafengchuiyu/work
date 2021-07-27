#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10
#define RAND_MAX 0x7FFF
void menu()
{
	printf("***********************\n");
	printf("**请选择：0.退出游戏***\n");
	printf("**        1.开始游戏***\n");
	printf("***********************\n");
}
void Initboard1(char board[ROWS][COLS],int rows,int cols,char set)
{
	int i=0;
	int j=0;
	for(i=0;i<=rows;i++)
	{
		for(j=0;j<=cols;j++)
		{
			board[i][j]='0';
		}
	}
}
void Initboard2(char show[ROWS][COLS],int rows,int cols,char set)
{
	int i=0;
	int j=0;
	for(i=0;i<=rows;i++)
	{
		for(j=0;j<=cols;j++)
		{
			show[i][j]='*';
		}
	}
}
void Displayboard1(char board[ROWS][COLS],int row,int col)
{
	 int i=0;
	 int j=0;
	 for(i=0;i<=row;i++)
	 {
 		printf("%d",i);
 	 }
 	 printf("\n");
 	 for(i=1;i<=row;i++)
 	 {
 	 	printf("%d",i);
 	 	for(j=1;j<=col;j++)
 	 	{
	 	 	printf("%c",board[i][j]);
 	    }
	 	 printf("\n");
 	 }
}
void Displayboard2(char show[ROWS][COLS],int row,int col)
{
	 int i=0;
	 int j=0;
	 for(i=0;i<=row;i++)
	 {
 		printf("%d",i);
 	 }
 	 printf("\n");
 	 for(i=1;i<=row;i++)
 	 {
 	 	printf("%d",i);
 	 	for(j=1;j<=col;j++)
 	 	{
	 	 	printf("%c",show[i][j]);
 	    }
	 	 printf("\n");
 	 }
}

void Setmine(char board[ROWS][COLS],int row,int col)
{
	int count=EASY_COUNT;
	while(count)
	{
		int x=rand()%ROW+1;
		int y=rand()%COL+1;
		if(board[x][y]=='0')
		{
			board[x][y]='1';
			count--;
		}
	}
}
void Displayboard3(char board[ROWS][COLS],int row,int col)
{
	 int i=0;
	 int j=0;
	 for(i=0;i<=row;i++)
	 {
 		printf("%d",i);
 	 }
 	 printf("\n");
 	 for(i=1;i<=row;i++)
 	 {
 	 	printf("%d",i);
 	 	for(j=1;j<=col;j++)
 	 	{
	 	 	printf("%c",board[i][j]);
 	    }
	 	 printf("\n");
 	 }
}
int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	return mine[x-1][y-1]+mine[x-1][y]+mine[x-1][y+1]
	+mine[x][y+1]+mine[x][y-1]+mine[x+1][y+1]
	+mine[x+1][y]+mine[x+1][y-1]-8*'0';
}
void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x=0;
	int y=0;
	int win=0;
	int count=0;
	while(win<row*col-EASY_COUNT)
	{
	printf("请输入排查雷的坐标:>\n");
	scanf("%d%d",&x,&y);
	if(x>=1&&x<=row&&y>=1&&y<=col)
	{
		if(mine[x][y]=='1')
		{
			printf("游戏结束，你已被雷炸死\a\n");
			Displayboard3(mine,ROW,COL);
			break;
		}
		else
		{
			count=get_mine_count(mine,x,y);
			show[x][y]=count+'0';
			Displayboard2(show,ROW,COL);
			win++;
		}
	}
	else
	{
		printf("\a输入非法，请重新输入:>");
	}
}
     if(win==ROW*COL-EASY_COUNT)
     {
     	printf("恭喜你游戏胜利\n");
     }
}
void game()
{
	//雷的信息存储 
	char mine[ROWS][COLS]={0};//布置好雷的信息 
	char show[ROWS][COLS]={0};//排查出雷的信息 
	//初始化 
	Initboard1(mine,ROWS,COLS,'0');
	Initboard2(show,ROWS,COLS,'*');
	//印棋盘信息 
	//Displayboard1(mine,ROW,COL);
	Displayboard2(show,ROW,COL);
	Setmine(mine,ROW,COL);
	//Displayboard3(mine,ROW,COL);
	Findmine(mine,show,ROW,COL);
}
int main()
{	
    int input=0;
    srand((unsigned int)time(NULL)); 
    do
	{
	menu();
	printf("请输入你所选的数字:>\n");
	scanf("%d",&input);
	switch(input)
	{
		case 0:
	printf("退出游戏\n");
	break;
	case 1:
	printf("欢迎进入游戏\n");
	game();
	break;
	default:
	printf("请输入菜单上有的数字!\n");
	break;	
	}
	}while(input);
	return 0;
}
