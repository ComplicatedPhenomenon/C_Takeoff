/*
    array name as pointer
    Pass array to function
    size of array
*/
#include<stdio.h>

void printArray(int *arr, int n);
void swap(int *x, int *y);
int *bubbleSort(int *arr, int n);

int main(){

    int arr[] = {6, 3, 2, 3, 4, 5};
    size_t n = sizeof(arr)/sizeof(arr[0]);
    int *ascendingArray;

    printArray(arr, n);

    swap(arr, arr+1);
    printArray(arr, n);

    ascendingArray = bubbleSort(arr, n);
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

void printArray(int *arr, int n){
    printf("Ascending array is \n");
    for(int i = 0; i < n; ++i){
        printf("%d ", *(arr+i));
        //printf("%d ", arr[i]);
    }
    printf("\n");
    return;

}

int *bubbleSort(int *arr, int n){
    for (int x = n; x >1; --x){
        for(int i= 0; i<(x-1); ++i){
            if (arr[i]>arr[i+1]) swap(arr+i, arr+i+1);
        }
    }
    return arr;

}
