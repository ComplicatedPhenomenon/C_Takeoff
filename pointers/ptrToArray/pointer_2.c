#include<stdio.h>

const int max = 3;
const int min = 4;

int main()
{
	int var[] = {10,20,30}; 
	int *pt[max]; /*each element in pt holds a pointer to an int value */
	int i;

	for(i=0; i < max; i++)
	{
		pt[i] = &var[i];
	
	
		printf("%d\n",*pt[i]);
	}
	char *name[] = {"wm","wangmiao","complicatephenomenon","czfzdxx"};
	for(int i = 0; i < min; i++)
	{
		printf("name[%d]=%s\n",i,name[i]);
	}


	for(int i = 0; i < min; i++)
	{
		printf("name[%d]=%p\n",i,*name+i);
	}
	return 0;
}
