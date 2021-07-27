#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	char arr1[]="welcome my world";
	char arr2[]="****************";
	int left=0;
	int right=strlen(arr1)-1;
	while(left<=right)
	{
		arr2[left]=arr1[left];
		arr2[right]=arr1[right];
		left++;
		right--;
		printf("%s\n",arr2);
		Sleep(2000);
		system("cls");
	}
	printf("welcome my world\n");
	return 0;
}
