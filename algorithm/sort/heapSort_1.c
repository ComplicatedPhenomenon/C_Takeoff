#include <stdio.h>

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

void heapify(int *a, int len, int index){
    int largest;
    int tem;
    largest = LCHILD(index) < len && a[LCHILD(index)] > a[index] ? LCHILD(index): index;
    largest = RCHILD(index) < len && a[RCHILD(index)] > a[largest] ? RCHILD(index) : largest;
    if (largest!= index){
        tem = a[index];
        a[index] = a[largest];
        a[largest] = tem;
        heapify(a, len, largest);  // largest may become index of an leaf code, that's why we set LCHILD(index) < len and ...
    }
}

int buildMaxHeap(int *a, int len){
    int i;
    
    //The elegant part is the start of i 
    for (i = PARENT(len - 1); i >= 0; i--) {
        heapify(a, len, i);
    }
    return 0;
}

int heapsort(int *a, int len){
    buildMaxHeap(a,len);
    int tem;
    int newlen = len;
    while(newlen > 1){
        //swap head with last
        tem = a[0];
        a[0] = a[newlen-1];
        a[newlen-1] = tem;
        newlen--;
        heapify(a, newlen, 0);
    }
    return 0;
}

int main(){
    int a[10] = {2,1,4,7,5,8,9,20,0,3};
    int len = 10;
    int i;

    printf("The array waiting to be sorted is: ");
    for (i = 0; i < len; i++) printf("%d\t", a[i]);
    printf("\n");
    heapsort(a, len);

    printf("The array after sorting is:        ");
    for (i = 0; i < len; i++) printf("%d\t", a[i]);
    printf("\n");

    return 0;
}
