/**
 * demonstration of basic usage of pointer
 * 
 * simplified version of ../../LeetCode/Tree/levelOrderTraversal_1.c
 **/
#include<stdio.h>
#include<stdlib.h>

void changeParameter(int i){
    i = 2;
}

void changeParameter_1(int *i){
    *i = 2;
}

void generateAnArray(int **ptrToArray, int *lengthOfArray){
    *lengthOfArray = 5;
    *ptrToArray = calloc(*lengthOfArray, sizeof(int));
    int array[] = {3, 4, 9, 3, 1};
    for(int i = 0; i < *lengthOfArray; ++i){
        (*ptrToArray)[i] = array[i];
        printf("%d\n",  (*ptrToArray)[i]);
    }
}

int main(){
    int i = 1;
    changeParameter(i);
    printf("%d\n", i);
    i = 4;
    changeParameter_1(&i);
    printf("%d\n", i);

    int *ptrToArray = NULL;
    int lengthOfArray = 0;
    generateAnArray(&ptrToArray, &lengthOfArray);
    printf("Newly generated array is: ");
    for(int k = 0; k < lengthOfArray; ++k){
        printf("%d ", ptrToArray[k]);
    }
    printf("\n");
    
    free(ptrToArray);
    return 0;
}