#include<stdio.h>
#include<string.h>
int main()
{
	int i=0;
    char password[20]={0};
    for(i=1;i<=3;i++)
   {
   printf("请输入密码\n");
   	scanf("%s",&password);
    if(strcmp(password,"123456")==0)
    {
    	printf("密码正确\n");
		break;
    }
	if(i==3)
    	{printf("你已经三次输错密码，即将强制退出\n");}
   }
   
    return 0;	
}
