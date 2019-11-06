#include<stdio.h>
/**
    original list: [9, 1, 0] 
    i = 0: [9, 1, 0] 
    i = 1, j = 1: [1, 9, 0]
    i = 2, j = 2: [1, 9, 9]
    i = 2, j = 1: [1, 1, 9]
    i = 2, j = 0: [0, 1, 9]
 **/
void insertionSort(int A[] , int n) {
    for(int i = 0; i < n ; i++) {
        for(int k = 0; k <=i; k++)printf("%d ", A[k]); printf("\n");
        int temp = A[i];    
        int j = i;
        while(j > 0 && temp < A[j -1]) {
            A[j] = A[j-1];   
            j= j - 1;
        }
        A[j] = temp;       
    }  
}

int main() {
    int array[] = {9, 1 , 3, 12, 8, 0, 6, 2, 1};
    size_t n = sizeof(array) / sizeof(array[0]);
    int i;

    printf("Original array is:");
    for(i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    insertionSort(array, n);

    printf("Insertion has bad performance when original array is in descending order\n");
    printf("Original array after sorting is:");
    for(i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");
    
    return 0; 
}