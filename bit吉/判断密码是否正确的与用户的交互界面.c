#include<stdio.h>
#include<string.h>
int main()
{
	int i=0;
    char password[20]={0};
    for(i=1;i<=3;i++)
   {
   printf("����������\n");
   	scanf("%s",&password);
    if(strcmp(password,"123456")==0)
    {
    	printf("������ȷ\n");
		break;
    }
	if(i==3)
    	{printf("���Ѿ�����������룬����ǿ���˳�\n");}
   }
   
    return 0;	
}
