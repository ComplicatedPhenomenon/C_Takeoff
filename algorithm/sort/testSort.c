/**
 * @file
 * @brief
 **/
 
#include "sort.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    size_t sizeOfArray = 10;
    int *p = calloc(sizeOfArray, sizeof(int));
    srand(time(NULL));

    printf("Test bubbleSort\n");
    generateAnArray(p, sizeOfArray);
    printArray(p, sizeOfArray);
    bubbleSort(p, sizeOfArray);
    printArray(p, sizeOfArray);
    free(p);

    printf("Test selectSort\n");
    p = calloc(sizeOfArray, sizeof(int));
    generateAnArray(p, sizeOfArray);
    printArray(p, sizeOfArray);
    selectSort(p, sizeOfArray);
    printArray(p, sizeOfArray);
    free(p);

    printf("Test insertionSort\n");
    p = calloc(sizeOfArray, sizeof(int));
    generateAnArray(p, sizeOfArray);
    printArray(p, sizeOfArray);
    insertionSort(p, sizeOfArray);
    printArray(p, sizeOfArray);
    free(p);

    printf("Test quickSort\n");
    p = calloc(sizeOfArray, sizeof(int));
    generateAnArray(p, sizeOfArray);
    printArray(p, sizeOfArray);
    quickSort(p, 0, 9);
    printArray(p, sizeOfArray);
    free(p);

    printf("Test quickSort_1\n");
    p = calloc(sizeOfArray, sizeof(int));
    generateAnArray(p, sizeOfArray);
    printArray(p, sizeOfArray);
    quickSort_1(p, 0, 9);
    printArray(p, sizeOfArray);
    free(p);

    printf("Test mergeSort\n");
    p = calloc(sizeOfArray, sizeof(int));

    generateAnArray(p, sizeOfArray);
    printArray(p, sizeOfArray);
    mergeSort(p, 0, 9);
    printArray(p, sizeOfArray);
    free(p);

    return 0;
}