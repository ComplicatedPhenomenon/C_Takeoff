// Matain a fixed length of heap
#include<stdio.h>
#include<stdlib.h>

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

void swap(int *i, int *j){
    int tem = *i;
    *i = *j;
    *j = tem;
}

void heapify(int a[], int size, int ithNode){
    int largest;
    largest = LCHILD(ithNode) < size && a[LCHILD(ithNode)] > a[ithNode] ? LCHILD(ithNode) : ithNode; 
    largest = RCHILD(ithNode) < size && a[RCHILD(ithNode)] > a[largest] ? RCHILD(ithNode) : largest;
    if(ithNode != largest) {
        swap(&a[ithNode], &a[largest]);
        heapify(a, size, largest);
    }
}

void buildMaxHeap(int a[], int size) {
    for (int i = (size - 1) / 2; i >= 0; i--){
        heapify(a, size, i);
    }
}


int findTheKthLargestNumber(int arr[], int size, int kth) {
    buildMaxHeap(arr, size);
    int i = 1;
    // throw away the largest for (kth -1) times
    while(i < kth ) {
        swap(&arr[0], &arr[size -1] );
        heapify(arr, --size, 0);
        i++;
    }
    return arr[0];

}
int main() {
    int a[10] = {2,1,4,7,5,8,9,20,0,3};
    int len = 10;
    int i;

    printf("The original array is: ");
    for (i = 0; i < len; i++) printf("%d\t", a[i]);
    printf("\n");

    int res = findTheKthLargestNumber(a, len, 3);
    printf("The 3rd largest element is: %d\n",  res);
    res = findTheKthLargestNumber(a, len, 4);
    printf("The 4th largest element is: %d\n",  res);

    return 0;
}
