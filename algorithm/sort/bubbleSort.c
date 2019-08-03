/**
 * array name as pointer
 * Pass array name as parameter of function
 **/
#include<stdio.h>

void printArray(int *array, int n);
void swap(int *x, int *y);
int *bubbleSort(int *array, int n);

int main(){
    int array[] = {6, 3, 2, 3, 4, 5};
    size_t n = sizeof(array)/sizeof(array[0]);
    int *ascendingArray;

    printArray(array, n);
    swap(array, array+1);
    printArray(array, n);
    ascendingArray = bubbleSort(array, n);
    printArray(ascendingArray, n);

    return 0;

}

void swap(int *x, int *y){
  	int temp=0;
    temp = *x;
  	*x = *y;
  	*y = temp;
	return;
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

int *bubbleSort(int *array, int n){
    for (int x = n; x >1; --x){
        for(int i= 0; i<(x-1); ++i){
            if (array[i]>array[i+1]) swap(array+i, array+i+1);
        }
    }
    return array;

}
