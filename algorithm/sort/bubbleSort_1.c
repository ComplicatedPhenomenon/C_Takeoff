/**
 * array name as pointer
 * Pass array name as parameter of function
 **/
#include<stdio.h>

void printArray(int *array, int n);
int *bubbleSort(int *array, int n);

int main(){
    int array[] = {6, 3, 2, 3, 4, 5};
    size_t n = sizeof(array)/sizeof(array[0]);
    int *ascendingArray;

    printArray(array, n);

    ascendingArray = bubbleSort(array, n);
    printArray(ascendingArray, n);

    return 0;

}

void printArray(int *array, int n){
    printf("Ascending arrayay is \n");
    for(int i = 0; i < n; ++i){
        printf("%d ", *(array+i));
        //printf("%d ", array[i]);
    }
    printf("\n");
    return;

}

int *bubbleSort(int *array, int n){
    int tem;
    for (int x = n; x >1; --x){
        for(int i= 0; i<(x-1); ++i){
            if (array[i]>array[i+1]){
                tem = array[i];
                array[i] = array[i+1];
                array[i+1] = tem;
            }
        }
    }
    return array;

}
