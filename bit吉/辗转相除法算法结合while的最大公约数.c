#include<stdio.h> 
int main()
{
	int max=0;
	int min=0;
	int tmp=0;
	int mid=0;
	scanf("%d%d",&max,&min);
	if(max<min)
	{
		tmp=max;
		max=min;
		min=tmp;
	}
	while(max%min)//����0��Ҫִ��ѭ�� 
	{
	   	max=min;//�㷨�е�շת����� 
	   	min=mid;
	}
	printf("���ߵ����Լ����%d\n",min);
	return 0;
}
