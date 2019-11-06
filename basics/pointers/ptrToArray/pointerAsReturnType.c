#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUMS 10

int *getRandom_1() {
    static int array[NUMS];
    int i;

    printf("Initialize an array 'array[NUMS]' through getRandom_1()\n");
    for (i = 0; i < NUMS; i++){
        array[i] = rand() % 20;
        printf("array[%d] = %d\n", i, array[i]);
    }
    return array;
}

int *getRandom_2() {
    int *ptr = calloc(NUMS, sizeof(int));
    int i;
    printf("Initialize an array 'array[NUMS]' through getRandom_2()\n");
    for (i = 0; i < NUMS; i++){
        *(ptr+i) = rand() % 20;
        printf("*(ptr+%d) = %d\n", i, *(ptr+i));
    }
    return ptr;
}

int *getRandom_wrong() {
    int array[NUMS];
    int *ptr = array;
    int i;

    printf("Initialize an array 'array[NUMS]' through getRandom_wrong()\n");
    for (i = 0; i < NUMS; i++){
        array[i] = rand() % 20;
        printf("array[%d] = %d\n", i, array[i]);
    }
    return ptr;
}

char *getAString(){
    char *ptrToTarget = "Hi, ComplicatedPhenomenon";
    return ptrToTarget;
}

int main(){
    int *ptrToArray_1;
    int *ptrToArray_2;
    int *ptrToArray_wrong;
    int i;
    srand((unsigned)time( NULL));

    ptrToArray_1 = getRandom_1();
    printf("A pointer 'ptrToArray_1' pointing to initialization function getRandom_1()\n");
    for(i = 0; i < NUMS; i++){
      	printf ("*(ptrToArray_1 + %d) : %d\n",i ,*(ptrToArray_1+i));
    }

    ptrToArray_2 = getRandom_2();
    printf("A pointer 'ptrToArray_2' pointing to initialization function getRandom_2()\n");
    for(i = 0; i < NUMS; i++){
      	printf ("*(ptrToArray_2 + %d) : %d\n",i ,*(ptrToArray_2+i));
    }
    

    ptrToArray_wrong = getRandom_wrong();
    printf("A pointer 'ptrToArray_wrong' pointing to initialization function getRandom_wrong()\n");
    for(i = 0; i < NUMS; i++){
      	printf ("*(ptrToArray_wrong + %d) : %d\n",i ,*(ptrToArray_wrong+i));
    }

    char *ptrToString = NULL;
    ptrToString  = getAString();
    printf("ptrToTarget = %p\n", ptrToString);
    printf("ptrToTarget = %s\n", ptrToString);

    free(ptrToArray_2);
    return 0;
}
