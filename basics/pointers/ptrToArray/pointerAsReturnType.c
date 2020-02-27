/**
 * @file
 * generate random array via
 * 
 * * static array
 *    
 *   They are not local to the function when goes out of lifetime 
 *   when the function finish execution
 * * `calloc`
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUMS 10

int *passAroundStaticArray() {
    static int array[NUMS];
 
    for (int i = 0; i < NUMS; i++){
        array[i] = rand() % 20;
    }
    
    return array;
}

int *passAroundpointerReferToArrayOnHeap() {
    int *ptr = calloc(NUMS, sizeof(int));
    for (int i = 0; i < NUMS; i++){
        *(ptr+i) = rand() % 20;
    }
    return ptr;
}

/*
int *getRandom_wrong() {
    int array[NUMS];
    int *ptr = array;

    for (int i = 0; i < NUMS; i++){
        array[i] = rand() % 20;
    }
    return ptr;
}
*/

char *getAString(){
    char *ptrToTarget = "Hi, ComplicatedPhenomenon";
    return ptrToTarget;
}

int main(){
    int i;
    srand((unsigned)time( NULL));

    int *ptrToArray_1 = passAroundStaticArray();
    printf("A pointer 'ptrToArray_1' pointing to initialization function passAroundStaticArray()\n");
    for(i = 0; i < NUMS; i++){
      	printf ("*(ptrToArray_1 + %d) : %d\n",i ,*(ptrToArray_1+i));
    }
    
    int *ptrToArray_2 = passAroundpointerReferToArrayOnHeap();
    printf("A pointer 'ptrToArray_2' pointing to initialization function passAroundpointerReferToArrayOnHeap()\n");
    for(i = 0; i < NUMS; i++){
      	printf ("*(ptrToArray_2 + %d) : %d\n",i ,*(ptrToArray_2+i));
    }
    
    /*
    int *ptrToArray_wrong = getRandom_wrong();
    printf("A pointer 'ptrToArray_wrong' pointing to initialization function getRandom_wrong()\n");
    for(i = 0; i < NUMS; i++){
      	printf ("*(ptrToArray_wrong + %d) : %d\n",i ,*(ptrToArray_wrong+i));
    }*/

    char *ptrToString = NULL;
    ptrToString  = getAString();
    printf("ptrToTarget = %p\n", ptrToString);
    printf("ptrToTarget = %s\n", ptrToString);

    free(ptrToArray_2);
    return 0;
}
