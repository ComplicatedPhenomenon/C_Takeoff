#include<stdio.h>

int main()
{
    char name[] = "ComplicatedPhenomenon";
    int i ;
    i = 0;

    printf("------------------------------\n");
    printf("The lenth of name is %lu\n bytes",sizeof(name));
    printf("------------------------------\n");
    for(i = 0;i < sizeof(name) - 1; i++){
	printf("name[%d] = %c \n",i,name[i]);
    }

    while(i < sizeof(name) - 1 ){
	printf("name[%d] = %c \n",i,name[i]);
	i ++;
    }
    printf("------------------------------\n");

    char *cp ;
    cp = name;
    /* it need explaination! a pointer cp point to an array */
    for(i = 0; i < sizeof(name) - 1; i++){
	printf("name[%d] = %p \n",i,cp+i);
	printf("name[%d] = %c \n",i,*(cp+i));
    }

    printf("------------------------------\n");
    printf("---here is a more difficult example---\n"); 
    printf("--- a pointer point to an array    ---\n");
    printf("------------------------------\n");


    char *names[] = {"Harry","Ron","Hermione","Harry Potter"};
   /************************************************
    *  Array of pointers is abstracted.            
    *  names here is an arry of 4 char * pointers. 
    ***********************************************/
    int len = sizeof(names) / sizeof(char);
    char *char_pointer;
	

    printf("length of names is %d  bytes\n", len);
    printf("sizeof names is %lu  bytes\n", sizeof(names));
    printf("sizeof char is %lu  bytes\n", sizeof(char));
    printf("sizeof char_pointer is %lu  bytes\n", sizeof(char_pointer));
    printf("------------------------------\n");
    for(i = 0; i < 4; i++){
	printf("names[%d] = %s\n",i, names[i]);
    }
    printf("------------------------------\n");

    char **HP;
    HP = names;
    /* **********************************************
     *  HP is a pointer pointed to a pointer        *
     *  but it's still a pointer *HP represents     *
     *  the contents it contained                   *
     ************************************************/
    for(i = 0; i < 4; i++){
	printf("&names[%d] = %p\n",i,&names[i]);
	printf("HP[%d] = %p \n",i,HP+i);
    }
    printf("&HP = %p\n",&HP);
    /*************************************************
     * I want to know the contents of an pointer and *
     *                its address                    *
     *************************************************/
    printf("------------------------------\n");
    for(i = 0; i < 4; i++){
	printf("*(HP+%d) = %s \n",i,*(HP+i));
	printf("names[%d] = %s\n",i,names[i]);
    }
    printf("------------------------------\n");

    return 0;
}
