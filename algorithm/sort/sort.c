#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *x, int *y) {
  	int temp = *x;
  	*x = *y;
  	*y = temp;
}


void printArray(int *pointerToArray, size_t sizeOfArray) {
    printf("Now array is \n");
    for(size_t i = 0; i < sizeOfArray; ++i){
        printf("%d ", *(pointerToArray+i));
    }
    printf("\n");
}

/**
 * generate pointerToArray random array 
 */ 
void generateAnArray(int *pointerToArray, size_t sizeOfArray) {
    int tem;
    for(size_t i = 0; i < sizeOfArray; i++) {
        tem = rand()% 100;
        *(pointerToArray+i) = tem;
    }
}


void bubbleSort(int *pointerToArray, size_t sizeOfArray) {
    for (size_t x = sizeOfArray; x >  1; --x){
        for(size_t i = 0; i < (x - 1); ++i){
            if (pointerToArray[i] > pointerToArray[i+1]) swap(pointerToArray+i, pointerToArray+i+1);
        }
    }
}


void selectSort(int *pointerToArray, size_t sizeOfArray) {
    int maxIndex;
    while(sizeOfArray > 1){
        maxIndex = 0;
        for(size_t x = 1; x<sizeOfArray; x++) maxIndex = pointerToArray[maxIndex] > pointerToArray[x]? maxIndex:x;
        swap(pointerToArray + maxIndex, pointerToArray + sizeOfArray -1);
        sizeOfArray --;
    }
}

/**
 * ```md
 * original list: [9, 1, 0] 
 * i = 0: [9, 1, 0] 
 * i = 1, j = 1: [1, 9, 0]
 * i = 2, j = 2: [1, 9, 9]
 * i = 2, j = 1: [1, 1, 9]
 * i = 2, j = 0: [0, 1, 9]
 * ```
 **/
void insertionSort(int *pointerToArray, size_t sizeOfArray) {
    for(size_t i = 0; i < sizeOfArray ; i++) {
        int temp = *(pointerToArray + i);    
        size_t j = i;
        while(j > 0 && temp < * (pointerToArray + j -1)) {
            *(pointerToArray + j) = *(pointerToArray + j-1);   
            j= j - 1;
        }
        *(pointerToArray + j) = temp;       
    }  
}


int partition (int *pointerToArray, int low, int high) {
    int pivot = pointerToArray[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++){
        if (pointerToArray[j] <= pivot){
            i++;
            swap(&pointerToArray[i], &pointerToArray[j]);
        }
    }
    swap(&pointerToArray[i + 1], &pointerToArray[high]);
    return (i + 1);
}


void quickSort(int *pointerToArray, int low, int high) {
    if (low < high){
        int pi = partition(pointerToArray, low, high);
        quickSort(pointerToArray, low, pi - 1);
        quickSort(pointerToArray, pi + 1, high);
    }
}

/**
 * Array-number as the parameter of function-quicksort
 * https://stackoverflow.com/questions/6567742/passing-an-array-as-an-argument-to-pointerToArray-function-in-c
 * pass the address of the first element of the array
 */
void quickSort_1(int *pointerToArray,int first, int last) {
    int i, j, pivot;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i < j){
            //To say it explicitly, the element iterated by is less than pivot vice versa for j
            while(*(pointerToArray +i ) <= *(pointerToArray + pivot) && i < last) i++;
            while(*(pointerToArray +j) > *(pointerToArray + pivot)) j--;
            if(i < j) swap(pointerToArray + i, pointerToArray + j); 
        }
        swap(pointerToArray + pivot,  pointerToArray + j);
        quickSort_1(pointerToArray,first,j-1);
        quickSort_1(pointerToArray,j+1,last);
    }
}


void merging(int *pointerToArray, int low, int mid, int high) {
    int i1, i2, i;
    int b[high]; //?

    for(i1 = low, i2 = mid + 1, i = low; i1 <= mid && i2 <= high; i++) {
        b[i] = *(pointerToArray + i1) <= *(pointerToArray + i2) ?  *(pointerToArray + i1++) : *(pointerToArray + i2++);
    }
    
    while(i1 <= mid) b[i++] = *(pointerToArray + i1++);
    while(i2 <= high)b[i++] = *(pointerToArray + i2++);

    for(i = low; i <= high; i++) *(pointerToArray + i) = b[i];

}


void mergeSort(int *pointerToArray, int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        mergeSort(pointerToArray, low, mid);
        mergeSort(pointerToArray, mid+1, high);
        merging(pointerToArray, low, mid, high);
    }
}


#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

void heapify(int *pointerToArray, int sizeOfArray, int index){
    int largest;
    largest = LCHILD(index) < sizeOfArray && *(pointerToArray + LCHILD(index)) > *(pointerToArray + index) ? LCHILD(index): index;
    largest = RCHILD(index) < sizeOfArray && *(pointerToArray + RCHILD(index)) > *(pointerToArray + largest) ? RCHILD(index) : largest;
    if (largest != index){
        swap(pointerToArray + index, pointerToArray + largest);
        heapify(pointerToArray, sizeOfArray, largest);  // largest may become index of an leaf code, that's why we set LCHILD(index) < sizeOfArray and ...
    }
}

void buildMaxHeap(int *pointerToArray, size_t sizeOfArray){
    //The elegant part is the start of i, serious bug if i has data type as size_t
    for(int i = PARENT(sizeOfArray - 1); i >= 0; i--) {
        heapify(pointerToArray, sizeOfArray, i);
    }
}

void heapSort(int *pointerToArray, size_t sizeOfArray){
    buildMaxHeap(pointerToArray, sizeOfArray);
    printf("complete building max heap \n");
    size_t newlen = sizeOfArray;
    while(newlen > 1){
        swap(pointerToArray, pointerToArray + newlen-1);
        newlen--;
        heapify(pointerToArray, newlen, 0);
    }
}

int findTheKthLargestNumber(int *pointerToArray, size_t sizeOfArray, int kth) {
    buildMaxHeap(pointerToArray, sizeOfArray);
    int i = 1;
    // throw away the largest for (kth -1) times
    while(i < kth ) {
        swap(pointerToArray, pointerToArray + sizeOfArray -1 );
        heapify(pointerToArray, --sizeOfArray, 0);
        i++;
    }
    return pointerToArray[0];
}


void mergeTwoSortedArray(int* A, size_t a, int*B, size_t b, int *mergedAB){
    int i= 0, j= 0, tem;
    for(int k = 0; k < a + b; ++k){
        if(i < a && j < b){
            tem = A[i] > B[j]? B[j] : A[i];
            mergedAB[k] = tem;
            if(tem == B[j]) ++j;
            else ++i;
        }
        else if (i == a){
            mergedAB[k] = B[j];
            ++j;
        }
        else{
            mergedAB[k] = A[i];
            ++i;
        }
    }
}