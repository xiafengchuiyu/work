#include<stdio.h>
int main()
{
	
	int year=0;
	int count=0;
	for(year=1000;year<=2000;year++)//[Error] C:\Users\29658\Documents\C-Free\Temp\δ����12.cpp:10: error: non-lvalue in assignment
	{//����ֵ����˼ 
		if(year%4==0&&year%100!=0)//��0�ǣ�=0�� 
	{
		printf("%d ",year);//�����ǰ������Ա�4����ȴ���ܱ�100�����������п��Ա�400�������� 
		count++;
	}
	else if(year%400==0)
	{
		printf("%d ",year);
		count++;
	}
	}
		printf("\n����%d������\n",count);
	return 0;
}
