/**
 * @file
 * 原始数组的值的顺序体现在辅助数组的指标上
 * 注意： (requirements to use bucket sort)
 * 
 * 1. 原始数组不含小于0的元素
 * 2. 原始数组中的最大元素要小于数组的长度
 **/
#include <stdio.h>
 
void bucketSort(int array[], int n) {  
    int i, j;  
    int count[n]; 
    for (i = 0; i < n; i++) count[i] = 0;
 
    for (i = 0; i < n; i++) (count[array[i]])++;
    // index of count save the order, item of count represent the time of occurrence of index
    for (i = 0, j = 0; i < n; i++) { 
        for(;count[i] > 0; (count[i])--)
            array[j++] = i;
    }
}   

int main() {
    int array[] = {2, 1 , 3, 6, 8, 0, 6, 2, 1};
    size_t n = sizeof(array) / sizeof(array[0]);
    int i;

    printf("Original array is:");
    for(i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    bucketSort(array, n);

    printf("Original array after sorting is:");
    for(i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    return 0; 
}