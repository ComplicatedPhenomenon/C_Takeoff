#include<stdio.h>
#include<limits.h>

int main()
{
    int age[] = {2, 4, 1455, 1334566};
    char letters[] = {'W','M'};
    /*initialization or assignment ?*/
    char *strings[] = {"I","Love","You"}; 	
    int i;

    for(i = 0; i < 4; i++){
	printf("age[%d] = %d\n",i,age[i])
    }
	
    printf("-----------------------------------------------\n");
    printf("The maximum number of integer type is %d\n",INT_MAX); 
    printf("The size of integer number is %lu %s\n",sizeof(int),"bytes");
    printf("The length of age is %lu bytes\n", sizeof(age));
    printf("-----------------------------------------------\n");
    printf("                                               \n");

    for(i = 0; i< 2; i++){
	printf("letter[%d] is :%c\n",i,letters[i]);
    }

    printf("                                               \n");
    printf("                                               \n");
    printf("string is a pointer to an array\n");
    for(i = 0; i < 3; i++){
	printf("strings[%d] = %s\n",i,strings[i]);
    }


}
