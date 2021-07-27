#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>

void openscene();
void readin();
void putout();
void stockin();
void stockout(); 
void display();
void search();
void changestuffwarningvalue();
void thetail();
void checkscanf(int ,int* );
void judgment(int num);
int amountoftype, warningvalue, check=0;
struct sku {
	int number;
	char name[10];
	int amount;
	double density;
	char quality[10];
	char industry[20];
}stock[100];

int main()
{

	openscene();
	return 0;
}

void openscene(void)
{
	int order;
	printf("*********************************************************************\n");
	printf("*             ��ӭ����ʵ���Ҳ��Ͽ���ʴ�����ܼ��ϵͳ                *\n");
	printf("*                                                                   *\n");
	printf("*     �����б�                                                    *\n");
	printf("*                                                                   *\n");
	printf("* 1.����������                   2.����ʴ��ģ�����ò�������     *\n");
	printf("*                                                                   *\n");
	printf("* 3.�������ݿ�                       4.��λ��һ����                 *\n");
	printf("*                                                                   *\n");
	printf("* 5.���Ŀ��Ԥ��ֵ                   6.����ʴ���ж�                *\n");
	printf("*                                                                   *\n");
	printf("*                         7.�˳�                                    *\n");
	printf("*********************************************************************\n");
	printf("*!!!ע�⣺����ǵ�һ��ʹ�ø�ģ��ϵͳ��������ִ�й���һ��������ϵͳ����!!!\n");
	printf("����������ѡ���ܶ�Ӧ�����:");
	check=scanf("%d", &order);
	checkscanf(check,&order);
	system("CLS");
	switch (order)
	{
	case 1:
		readin();
		stockin();
		putout();
		thetail();
		break;
	case 2:
		readin();
		stockout();
		putout();
		thetail();
		break;
	case 3:
		readin();
		display();
		thetail();
		break;
	case 4:
		readin();
		search();
		thetail();
		break;
	case 5:
		readin();
		changestuffwarningvalue();
		putout();
		thetail();
		break;
    case 6:
        readin();
        printf("��������Ҫ�����жϵĲ��ϱ�ţ�");
        int num;
        scanf("%d",&num);
        judgment(num);
        putout();
        thetail();
        break;
	case 7:
		exit(0);
		break;
	default:
		printf("\a\a");
		printf("�������ѡ�����������ԣ�");
		system("pause");
		openscene();
		break;
	}
}

void readin()
{
	FILE*fp = fopen("stock.txt", "r");
	int i = 0;
	if (fp)
	{
		fscanf(fp, "%d", &warningvalue);
		while (1)
		{
			fscanf(fp, "%s%d%d%s%lf%s", &stock[i].name, &stock[i].number, &stock[i].amount,&stock[i].quality,&stock[i].density,&stock[i].industry);
			if (feof(fp)) break;
			i++;
		}
		amountoftype = i;
		fclose(fp);
	}
	else printf("\033[47;31m������ǵ�һ��ʹ�ó�����Ժ��Ա��У����ļ�ʧ��\n\033[0m");//��ֹ���ļ�ʧ��
}

void putout()
{
	FILE*fp = fopen("stock.txt", "w");
	if (fp)
	{
		fprintf(fp, "%-10d\n", warningvalue);
		for (int x = 0;x < amountoftype;x++)
		{
			if (stock[x].amount != -1)
			{
				fprintf(fp, "%-10s", stock[x].name);
				fprintf(fp, "%-10d", stock[x].number);
				fprintf(fp, "%-10d\n", stock[x].amount);
				fprintf(fp, "%-10s\n", stock[x].quality);
				fprintf(fp, "%-10d\n", stock[x].density);
				fprintf(fp, "%-10s\n", stock[x].industry);
			}
		}
		fclose(fp);
	}
	else printf("\033[47;31m���ļ�ʧ��\033[0m");
}

void stockout(void)
{
	int findnumber, deductnumber, ne = 1;
	printf("��������ϱ��:");
	check=scanf("%d", &findnumber);
	checkscanf(check, &findnumber); printf("\n\n");
	for (int x = 0;x < amountoftype;x++)
	{
		if (findnumber == stock[x].number)
		{
			ne = 0;
			printf("��ȡ��������Ϊ%s,��������ϳ�����Ŀ:",stock[x].name);
			check=scanf("%d", &deductnumber);
			checkscanf(check, &findnumber);printf("\n\n");
			if (stock[x].amount == deductnumber)
			{
				printf("\033[47;31m���ϸպ�ȫ���ľ�\033[0m\n\n");
				stock[x].amount = -1;
			}
			else if (stock[x].amount < deductnumber)
			{
				printf("\033[47;31m�����������˿�棡����Ƿ�,�˴γ���ʧ��\033[0m\n\n");
				printf("\a\a");
			}
			else
			{
				stock[x].amount -= deductnumber;
				printf("�����ɹ���\n\n");
			}
			if (stock[x].amount < warningvalue && stock[x].amount>0)
			{
				printf("\033[47;31m���������Ʒ���С��Ԥ��ֵ%d,��ע��\n\n\033[0m", warningvalue);
			}
		}
	}
	if (ne == 1)
	{
		printf("\a\a");
		printf("����һ���ֿ�û�е���Ʒ!������\n\n");
		stockout();
	}
	printf("�Ƿ���������������밴1������2:  ");
	int yesorno;
	check=scanf("%d", &yesorno);
	checkscanf(check, &yesorno); printf("\n\n");
	if (yesorno == 1)
	{
		system("CLS");
		stockout();
	}
}

void stockin(void)
{
int findnumber, addnumber, ne = 1;

	printf("��������ϱ��(��������Ҳ���뽫��ӵ�еı�ż���):");
	check=scanf("%d", &findnumber);
	checkscanf(check, &findnumber); printf("\n");
	for (int x = 0;x < amountoftype;x++)
	{
		if (findnumber == stock[x].number)
		{
			ne = 0;
			printf("����Ʒ������%s,��������Ʒ�����Ŀ",stock[x].name);
			check=scanf("%d", &addnumber);
			checkscanf(check, &addnumber); printf("\n");
			stock[x].amount += addnumber;
			printf("���ɹ���\n");
			break;
		}
	}
	if (ne == 1)
	{
		printf("����һ��ʵ����û�еĲ���\n\n");
		stock[amountoftype].number = findnumber;
		printf("��Ϊ��������������ƣ�");
		scanf("%s", &stock[amountoftype].name);printf("\n");
		printf("��������ϴ洢��Ŀ��");
		check=scanf("%d", &addnumber);
		checkscanf(check, &addnumber); printf("\n\n");
		stock[amountoftype].amount = addnumber;
		amountoftype++;
		printf("���ɹ���\n");
	}
	printf("�Ƿ���п���ʴ���жϣ������밴1������2����������");
	int choice;
	check=scanf("%d", &choice);
	checkscanf(check, &choice); printf("\n\n");
	if (choice == 1)
	{
		system("CLS");
		judgment(stock[amountoftype-1].number);
	}
	printf("�Ƿ������⣿�����밴1������2����������:  ");
	int yesorno;
	check=scanf("%d", &yesorno);
	checkscanf(check, &yesorno); printf("\n\n");
	if (yesorno == 1)
	{
		system("CLS");
		stockin();
	}
}

void display()
{
	int yesorno;
	printf("�Ƿ�����Ԥ��ϵͳ��(��������������Ԥ��ֵ�Ļ�Ʒ������죩�����밴1,����2������������");
	check = scanf("%d", &yesorno);
	checkscanf(check, &yesorno); printf("\n\n");
	switch (yesorno)
	{
	case 1:
		printf("����ȫ����Ϣ���£�\n\n");
		printf("���ϱ��    ��������              ����   ����ʴ����                     ���ù�ҵ\n");
		for (int x = 0;x < amountoftype;x++)
		{
			if (stock[x].amount > warningvalue)
				printf("\033[47;32m%-12d%-22s%-8d%-22s%-25s\033[0m\n\n", stock[x].number, stock[x].name, stock[x].amount,stock[x].quality,stock[x].industry);
			else
				printf("\033[47;31m%-12d%-22s%-8d%-22s%-25s\033[0m\n\n", stock[x].number, stock[x].name, stock[x].amount,stock[x].quality,stock[x].industry);
		}
		break;
	default:
		printf("����ȫ����Ϣ���£�\n\n");
		printf("���ϱ��    ��������              ����   ����ʴ����                     ���ù�ҵ    \n");
		for (int x = 0;x < amountoftype;x++)
		{
			printf("\033[47;32m%-12d%-22s%-8d%-30s%-25s\033[0m\n\n", stock[x].number, stock[x].name, stock[x].amount,stock[x].quality,stock[x].industry);
		}
		break;

	}
}

void search()
{
	char searchname[10];
	int searchnumber, inter;
	int findornot = 1;
	printf("��ӭʹ�ö�λ�������Ϲ���\n");
	printf("��Ų����밴1�����Ʋ����밴2\n");
	check=scanf("%d", &inter);
	checkscanf(check, &inter); printf("\n\n");
	if (inter == 1)
	{
		printf("������Ҫ���ҵĲ��ϱ�ţ�\n");
		check=scanf("%d", &searchnumber);
		checkscanf(check, &searchnumber); printf("\n\n");
		for (int x = 0;x < amountoftype;x++)
		{
			if (searchnumber == stock[x].number)
			{
				findornot = 0;
				printf("������Ϣ���£�\n\n");
				printf("���ϱ��    ��������              ����    \n\n");
				printf("%d              %s                  %d\n", stock[x].number, stock[x].name, stock[x].amount);
				break;
			}
		}
	}
	else
	{
		printf("������Ҫ���ҵĲ������ƣ�\n");
		scanf("%s", &searchname);
		for (int x = 0;x < amountoftype;x++)
		{
			if (strcmp(searchname, stock[x].name)==0);
			{
				findornot=0;
				printf("������Ϣ���£�\n");
				printf("���ϱ��    ��������       ����    \n");
			    printf("%d              %s                  %d\n", stock[x].number, stock[x].name, stock[x].amount);
				break;
			}
	      }
	}
	if (findornot)
	{
		printf("\a\a");
		printf("\033[47;31m���ҵĲ��ϲ����ڣ�������\033[0m\n");
		system("pause");
		system("CLS");
		search();
	}
	int yesorno;
	printf("�Ƿ�����鿴��һ�������ݣ����밴1�����밴2������������");
	check=scanf("%d", &yesorno);
	checkscanf(check, &yesorno); printf("\n\n");
	if (yesorno == 1)
	{
		system("CLS");
		search();
	}
}
void changestuffwarningvalue()
{
	printf("��ǰ��Ԥ��ֵΪ%d,�������µ�Ԥ��ֵ��",warningvalue);
	check=scanf("%d", &warningvalue);
	checkscanf(check, &warningvalue); printf("\n\n");
	printf("�������");
}
void thetail()
{
	printf("�����������˵���");
	system("pause");
	system("CLS");
	openscene();
}
void checkscanf(int check,int* inter)
{
	int r=1,newnumber;
	while (check != 1) 
	{
		r = 0;
		while (getchar() != '\n');	
		printf("\a\a");
		printf("������������Ͳ����������ͣ����ٴ�����:");
		check = scanf("%d", &newnumber);
	}
	if(r==0) *inter = newnumber;
}
void judgment(int num)
{
    int findornot=1;
    double result,area,dlatweight,time;
    printf("��ӭʹ�ÿ���ʴ���жϹ���\n");
		for (int x = 0;x < amountoftype;x++)
		{
			if (num == stock[x].number)
			{
				findornot = 0;
				printf("����������ܶ�(g/cm3)\n");
				scanf("%lf",&stock[x].density);
				printf("�������������(cm2)\n");
				scanf("%lf",&area);
				printf("������ʱ��(h)\n");
				scanf("%lf",&time);
				printf("����������ʧ��(g)\n");
				scanf("%lf",&dlatweight);
				result=(8.76*dlatweight)/(stock[x].density*area*time);
				if(result>=0.01&&result<=0.1)
                {
                    strcpy(stock[x].quality,"��");
                    strcpy(stock[x].industry,"�ع�ҵ�򱣻�Ϳ��");
                }
                else if(result>0.1&&result<=1.0)
                {
                    strcpy(stock[x].quality,"��");
                    strcpy(stock[x].industry,"��Ҫ̼�ֹ�ҵ");
                }
                else if(result>1.0)
                {
                    strcpy(stock[x].quality,"��");
                    strcpy(stock[x].industry,"һ���Ṥҵ");
                }
                else
                {
                    printf("errors\n");
                }
                printf("������ϵĿ���ʴ����Ϊ%s��������%s\n",stock[x].quality,stock[x].industry);
				break;
			}
		}
		if(findornot!=0)
        {
            printf("û���ҵ��������\n");
        }
}
