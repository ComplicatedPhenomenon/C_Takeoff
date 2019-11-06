/**
 * 原始数组的值的顺序体现在辅助数组的指标上
 * 注意：
 * 1， 原始数组不含小于0的元素
 * 2， 原始数组中的最大元素过大造成辅助数组溢出内存
 **/

#include<stdio.h>
#include<stdlib.h>

void countingSort(int A[],  int N) {
    // find the maximum value in A    
    int maxOfA = A[0];
    for(int i = 1; i < N; i++){
        maxOfA = maxOfA > A[i]? maxOfA : A[i];
    }

    int Aux[maxOfA + 1];
    for(int i = 0; i < maxOfA + 1; i++) Aux[i] = 0;
    for(int i = 0; i < N; i++)  Aux[A[i]]++;  
    
    printf("Aux is:");
    for(int i = 0; i < maxOfA + 1; i++) printf("%d ", Aux[i]);
    printf("\n");

    /* 
       Aux stores which element occurs how many times,
       Add i in sortedA[] according to the number of times i occured in A[]
    */
    int j = 0;
    for(int i = 0; i < maxOfA + 1; i++) {
        int tmp = Aux[i];
        while(tmp-- != 0) {
            A[j] = i;
            j++;
        }
    }
}

int main() {
    int array[] = {9, 1 , 3, 12, 8, 0, 6, 2, 1};
    size_t n = sizeof(array) / sizeof(array[0]);
    int i;

    printf("Original array is:");
    for(i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    countingSort(array, n);
    
    printf("Original array after sorting is: ");
    for(i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    return 0; 
}