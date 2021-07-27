#include<stdio.h>
enum color
{
	RED,
	YELLOW,
	BLUE
};
int main()
{
	enum color a = RED;
	enum color b = YELLOW;
	enum color c = BLUE;
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",c);
	return 0; 
}
