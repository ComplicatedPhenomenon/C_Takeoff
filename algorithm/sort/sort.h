#include<stdlib.h>
#ifndef SORT_H
#define SORT_H

void printArray(int *pointerToArray, size_t sizeOfArray);
void generateAnArray(int *pointerToArray, size_t sizeOfArray);
void bubbleSort(int *pointerToArray, size_t sizeOfArray);
void selectSort(int *pointerToArray, size_t sizeOfArray);
void countingSort(int *pointerToArray, size_t sizeOfArray);
void insertionSort(int *pointerToArray, size_t sizeOfArray);
void quickSort(int *pointerToArray, int low, int high);
void quickSort_1(int *pointerToArray, int low, int high);
void mergeSort(int *pointerToArray, int low, int high);
void heapSort(int *pointerToArray, size_t sizeOfArray);
int findTheKthLargestNumber(int *pointerToArray, size_t sizeOfArray, int kth);
void mergeTwoSortedArray(int* A, size_t a, int*B, size_t b, int *mergedAB);
#endif
