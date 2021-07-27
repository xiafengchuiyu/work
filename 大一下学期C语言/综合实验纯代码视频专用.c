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
	printf("*             欢迎来到实验室材料抗腐蚀性性能检测系统                *\n");
	printf("*                                                                   *\n");
	printf("*     功能列表：                                                    *\n");
	printf("*                                                                   *\n");
	printf("* 1.材料入库或存放                   2.抗腐蚀性模拟所用材料数量     *\n");
	printf("*                                                                   *\n");
	printf("* 3.材料数据库                       4.定位单一材料                 *\n");
	printf("*                                                                   *\n");
	printf("* 5.更改库存预警值                   6.抗腐蚀性判断                *\n");
	printf("*                                                                   *\n");
	printf("*                         7.退出                                    *\n");
	printf("*********************************************************************\n");
	printf("*!!!注意：如果是第一次使用该模拟系统，请首先执行功能一负责会造成系统紊乱!!!\n");
	printf("请输入你所选择功能对应的序号:");
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
        printf("请输入你要进行判断的材料编号：");
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
		printf("你输入的选项有误，请重试，");
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
	else printf("\033[47;31m（如果是第一次使用程序可以忽略本行）打开文件失败\n\033[0m");//防止打开文件失败
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
	else printf("\033[47;31m打开文件失败\033[0m");
}

void stockout(void)
{
	int findnumber, deductnumber, ne = 1;
	printf("请输入材料编号:");
	check=scanf("%d", &findnumber);
	checkscanf(check, &findnumber); printf("\n\n");
	for (int x = 0;x < amountoftype;x++)
	{
		if (findnumber == stock[x].number)
		{
			ne = 0;
			printf("所取材料名称为%s,请输入材料出库数目:",stock[x].name);
			check=scanf("%d", &deductnumber);
			checkscanf(check, &findnumber);printf("\n\n");
			if (stock[x].amount == deductnumber)
			{
				printf("\033[47;31m材料刚好全部耗尽\033[0m\n\n");
				stock[x].amount = -1;
			}
			else if (stock[x].amount < deductnumber)
			{
				printf("\033[47;31m需求量超过了库存！请求非法,此次出货失败\033[0m\n\n");
				printf("\a\a");
			}
			else
			{
				stock[x].amount -= deductnumber;
				printf("出货成功！\n\n");
			}
			if (stock[x].amount < warningvalue && stock[x].amount>0)
			{
				printf("\033[47;31m出货后该商品库存小于预警值%d,请注意\n\n\033[0m", warningvalue);
			}
		}
	}
	if (ne == 1)
	{
		printf("\a\a");
		printf("这是一个仓库没有的商品!请重试\n\n");
		stockout();
	}
	printf("是否继续出货？继续请按1，否则按2:  ");
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

	printf("请输入材料编号(新增材料也输入将会拥有的编号即可):");
	check=scanf("%d", &findnumber);
	checkscanf(check, &findnumber); printf("\n");
	for (int x = 0;x < amountoftype;x++)
	{
		if (findnumber == stock[x].number)
		{
			ne = 0;
			printf("该商品名称是%s,请输入商品入库数目",stock[x].name);
			check=scanf("%d", &addnumber);
			checkscanf(check, &addnumber); printf("\n");
			stock[x].amount += addnumber;
			printf("入库成功！\n");
			break;
		}
	}
	if (ne == 1)
	{
		printf("这是一个实验室没有的材料\n\n");
		stock[amountoftype].number = findnumber;
		printf("请为这个材料输入名称：");
		scanf("%s", &stock[amountoftype].name);printf("\n");
		printf("请输入材料存储数目：");
		check=scanf("%d", &addnumber);
		checkscanf(check, &addnumber); printf("\n\n");
		stock[amountoftype].amount = addnumber;
		amountoftype++;
		printf("入库成功！\n");
	}
	printf("是否进行抗腐蚀性判断？进行请按1，否则按2或者其它键");
	int choice;
	check=scanf("%d", &choice);
	checkscanf(check, &choice); printf("\n\n");
	if (choice == 1)
	{
		system("CLS");
		judgment(stock[amountoftype-1].number);
	}
	printf("是否继续入库？继续请按1，否则按2或者其它键:  ");
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
	printf("是否启动预警系统？(启动后库存数低于预警值的货品将被标红）启动请按1,否则按2或者其他键：");
	check = scanf("%d", &yesorno);
	checkscanf(check, &yesorno); printf("\n\n");
	switch (yesorno)
	{
	case 1:
		printf("材料全部信息如下：\n\n");
		printf("材料编号    材料名称              数量   抗腐蚀性能                     适用工业\n");
		for (int x = 0;x < amountoftype;x++)
		{
			if (stock[x].amount > warningvalue)
				printf("\033[47;32m%-12d%-22s%-8d%-22s%-25s\033[0m\n\n", stock[x].number, stock[x].name, stock[x].amount,stock[x].quality,stock[x].industry);
			else
				printf("\033[47;31m%-12d%-22s%-8d%-22s%-25s\033[0m\n\n", stock[x].number, stock[x].name, stock[x].amount,stock[x].quality,stock[x].industry);
		}
		break;
	default:
		printf("材料全部信息如下：\n\n");
		printf("材料编号    材料名称              数量   抗腐蚀性能                     适用工业    \n");
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
	printf("欢迎使用定位单个材料功能\n");
	printf("编号查找请按1，名称查找请按2\n");
	check=scanf("%d", &inter);
	checkscanf(check, &inter); printf("\n\n");
	if (inter == 1)
	{
		printf("请输入要查找的材料编号：\n");
		check=scanf("%d", &searchnumber);
		checkscanf(check, &searchnumber); printf("\n\n");
		for (int x = 0;x < amountoftype;x++)
		{
			if (searchnumber == stock[x].number)
			{
				findornot = 0;
				printf("材料信息如下：\n\n");
				printf("材料编号    材料名称              数量    \n\n");
				printf("%d              %s                  %d\n", stock[x].number, stock[x].name, stock[x].amount);
				break;
			}
		}
	}
	else
	{
		printf("请输入要查找的材料名称：\n");
		scanf("%s", &searchname);
		for (int x = 0;x < amountoftype;x++)
		{
			if (strcmp(searchname, stock[x].name)==0);
			{
				findornot=0;
				printf("材料信息如下：\n");
				printf("材料编号    材料名称       数量    \n");
			    printf("%d              %s                  %d\n", stock[x].number, stock[x].name, stock[x].amount);
				break;
			}
	      }
	}
	if (findornot)
	{
		printf("\a\a");
		printf("\033[47;31m所找的材料不存在，请重试\033[0m\n");
		system("pause");
		system("CLS");
		search();
	}
	int yesorno;
	printf("是否继续查看单一材料数据，是请按1，否请按2或者其它键：");
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
	printf("当前的预警值为%d,请输入新的预警值：",warningvalue);
	check=scanf("%d", &warningvalue);
	checkscanf(check, &warningvalue); printf("\n\n");
	printf("更改完成");
}
void thetail()
{
	printf("即将返回主菜单，");
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
		printf("输入的数据类型不是数字类型，请再次输入:");
		check = scanf("%d", &newnumber);
	}
	if(r==0) *inter = newnumber;
}
void judgment(int num)
{
    int findornot=1;
    double result,area,dlatweight,time;
    printf("欢迎使用抗腐蚀性判断功能\n");
		for (int x = 0;x < amountoftype;x++)
		{
			if (num == stock[x].number)
			{
				findornot = 0;
				printf("请输入材料密度(g/cm3)\n");
				scanf("%lf",&stock[x].density);
				printf("请输入试样面积(cm2)\n");
				scanf("%lf",&area);
				printf("请输入时间(h)\n");
				scanf("%lf",&time);
				printf("请输入试样失重(g)\n");
				scanf("%lf",&dlatweight);
				result=(8.76*dlatweight)/(stock[x].density*area*time);
				if(result>=0.01&&result<=0.1)
                {
                    strcpy(stock[x].quality,"优");
                    strcpy(stock[x].industry,"重工业或保护涂层");
                }
                else if(result>0.1&&result<=1.0)
                {
                    strcpy(stock[x].quality,"良");
                    strcpy(stock[x].industry,"需要碳钢工业");
                }
                else if(result>1.0)
                {
                    strcpy(stock[x].quality,"差");
                    strcpy(stock[x].industry,"一般轻工业");
                }
                else
                {
                    printf("errors\n");
                }
                printf("这个材料的抗腐蚀性能为%s，适用于%s\n",stock[x].quality,stock[x].industry);
				break;
			}
		}
		if(findornot!=0)
        {
            printf("没有找到这个材料\n");
        }
}
