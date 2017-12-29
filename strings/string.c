/**
 * version 2.0 
 * sizeof(butterfly) = 10?
 **/
#include<stdio.h>

int main()
{	

/*-------------------------------------------------------*/
/*  use an array of pointers to character to store a 	 */
/*       list of strings         			 */
/*  指向字符数据型的指针数组构成的数组     		 */
/*-------------------------------------------------------*/
    int i;
    char *name[] = {"wm","ComplicatedPhenomenon", "wangmiao"};

    for(i = 0; i < 3; i++){
	printf("name[%d] = %s\n",i,name[i]);
    }
/*-------------------------------------------------------*/
/* 不用指针，直接用数组储存字符串怎么就行不通？          */
/*-------------------------------------------------------*/
    char word[] = "butterfly";
    int parameter = sizeof(word)-1;
    printf("sizeof(butterfly) = %d\n", parameter);
    for(i = 0; i < parameter; i++){
	printf("word[%d] = %c, \n",i,word[i]);
    }

    int j;
    char legacy[10][15];
    printf("Anything new? I will store what you said in a 2 dimension array, row 10, column 15 \n");
    for(j = 0; j < 9; j++){
	scanf("%s\n", legacy[j]);
    }

    printf("okay,you said :\n");
    for(j = 0; j < 10; j++){
	printf("%s\n",legacy[j]);
    }

    return 0;
}
