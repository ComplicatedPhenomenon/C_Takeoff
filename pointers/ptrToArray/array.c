#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *getRandom_1()
{
    static int array[10];
    int i;

    // makes use of the computer's internal clock to control the choice of the seed.  Since time is continually changing, the seed is forever changing.
    srand( (unsigned)time( NULL));

    printf("Initialize an array 'array[10]' \n");
    for (i=0; i < 10; ++i){
      array[i] = rand();
      printf("array[%d] = %d\n", i, array[i]);
    }

    return array;
}


int main()
{
    int *ptrToFunctionPointer;
    int i;
    // assign function pointer to a variable
    ptrToFunctionPointer = getRandom_1();


    printf("A pointer 'ptrToFunctionPointer' pointing to initialization function\n");
    for(i=0; i < 10; i++){
      	printf ("*(ptrToFunctionPointer + %d) : %d\n",i ,*(ptrToFunctionPointer+i));
    }

    return 0;
}
