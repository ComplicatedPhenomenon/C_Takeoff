#include<stdio.h>

int main()
{	

/*-------------------------------------------------------*/
/*                            				 */
/*  use an array of pointers to character to store a 	 */
/*       list of strings         			 */
/*  指向字符数据型的指针数组构成的数组     		 */
/*							 */
/*-------------------------------------------------------*/
	int i;
	char *name[] = {"wm","complicatephenomenon"};
	for(i = 0; i < 2; i++)
	{
		printf("name[%d] = %s\n",i,name[i]);
	}
/*-------------------------------------------------------*/
/*						         */
/* 不用指针，直接用数组储存字符串怎么就行不通？          */
/*							 */
/*-------------------------------------------------------*/
        char word[] = "bufferfly";
	int parameter = sizeof word -1;
	for(i = 0; i < parameter; i++)
	{
		printf("word[%d] = %c, \n",i,word[i]);
	}
/*-------------------------------------------------------*/

	int j;
	char legacy[10][15];
	printf("Anything new? \n");
	for(j = 0; j < 10; j++){
		scanf("%s\n", legacy[j]);
	}

	printf("okay,you said :\n");
	for(j = 0; j < 10; j++){

	printf("%s\n",legacy[j]);
	}
	return 0;
}
