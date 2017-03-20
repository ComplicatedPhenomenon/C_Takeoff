#include<stdio.h>
int main()
{
	char my_name[9]  = {'w','a','n','g','m','i','a','o'};
	int i;
	printf("myname is consist of :\n");
	for(i = 0; i < 8; i++)
	{
		printf("%c\n",my_name[i]);
	}
	printf("%c%c%c%c%c%c%c%c\n",'w','a','n','g','m','i','a','o');

	printf("%s\n","wangmiao");

	return 0;
}
