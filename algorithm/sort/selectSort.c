#include<stdio.h>

void printArray(int *array, int n);
int *selectSort(int *array, int n);

int main(){
    int array[] = {-1, 10, 12, 6, 3, 2, 3, 4, 5};
    size_t n = sizeof(array)/sizeof(array[0]);
    int *ascendingArray;

    printArray(array, n);
    ascendingArray = selectSort(array, n);
    printArray(ascendingArray, n);

    return 0;
}

void printArray(int *array, int n){
    printf("Now array is \n");
    for(int i = 0; i < n; ++i){
        printf("%d ", *(array+i));
        //printf("%d ", array[i]);
    }
    printf("\n");
    return;

}

int *selectSort(int *array, int n){
    size_t x;
    int maxIndex;
    int tem;
    while(n>1){
        maxIndex = 0;
        for(x = 1; x<n; x++) maxIndex = array[maxIndex] > array[x]? maxIndex:x;
        tem = array[maxIndex];
        array[maxIndex] = array[n-1];
        array[n-1] = tem;
        n --;
    }

    return array;
}
