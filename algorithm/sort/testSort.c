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

    printf("Test heapSort\n");
    p = calloc(sizeOfArray, sizeof(int));
    generateAnArray(p, sizeOfArray);
    printArray(p, sizeOfArray);
    int tem =  findTheKthLargestNumber(p, sizeOfArray, 2);
    printf("second largest element in array is %d \n", tem);
    printArray(p, sizeOfArray);
    heapSort(p, sizeOfArray);
    printArray(p, sizeOfArray);
    free(p);

    printf("Test merge 2 sorted list\n");
    int *A = calloc(sizeOfArray, sizeof(int));
    int *B = calloc(sizeOfArray, sizeof(int));
    int *mergedAB  = calloc(2 * sizeOfArray, sizeof(int));
    generateAnArray(A, sizeOfArray);
    printArray(A, sizeOfArray);
    bubbleSort(A, sizeOfArray);
    printArray(A, sizeOfArray);
    generateAnArray(B, sizeOfArray);
    printArray(B, sizeOfArray);
    bubbleSort(B, sizeOfArray);
    printArray(B, sizeOfArray);
    mergeTwoSortedArray(A, sizeOfArray, B, sizeOfArray, mergedAB);
    printArray(mergedAB, 2*sizeOfArray);
    free(A);
    free(B);
    free(mergedAB);

    return 0;
}