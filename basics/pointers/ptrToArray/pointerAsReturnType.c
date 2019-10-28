#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *getRandom_1()
{
    static int array[10];
    int i;
    /**
     * makes use of the computer's internal clock to control the choice of the seed.
     * since time is continually changing, the seed is forever changing.
     **/
    srand( (unsigned)time( NULL));

    printf("Initialize an array 'array[10]' \n");
    for (i=0; i < 10; ++i){
      array[i] = rand();
      printf("array[%d] = %d\n", i, array[i]);
    }
    return array;
}


char *getAnotherString(){
    char *ptrToTarget = "Hi, ComplicatedPhenomenon";
    return ptrToTarget;
}

int main(){
    int *ptrToFunction;
    int i;

    ptrToFunction = getRandom_1();
    printf("A pointer 'ptrToFunction' pointing to initialization function\n");
    for(i=0; i < 10; i++){
      	printf ("*(ptrToFunction + %d) : %d\n",i ,*(ptrToFunction+i));
    }

    char *ptr = NULL;
    ptr  = getAnotherString();
    printf("ptrToTarget = %p\n", ptr);
    printf("ptrToTarget = %s\n", ptr);

    return 0;
}
