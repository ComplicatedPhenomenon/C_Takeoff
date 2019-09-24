#include<stdio.h>

/*Function to arrange the elements in the heap*/
void Adjust(int Heap_of_Numbers[], int i){
    int j;
    int tem, unsortedSize, flag = 1;
    unsortedSize = Heap_of_Numbers[0];
    while(2 * i <= unsortedSize && flag == 1){
        /* Index of root node starts at 1, therefore, the left chile of i is 2*i */
        j = 2 * i;
        /* if right child exists and the right child larger than left child*/
        if(j + 1 <= unsortedSize && Heap_of_Numbers[j+1] > Heap_of_Numbers[j]) j++;

        if( Heap_of_Numbers[j] < Heap_of_Numbers[i]) flag = 0;
        else{
            tem=Heap_of_Numbers[i];
            Heap_of_Numbers[i]=Heap_of_Numbers[j];
            Heap_of_Numbers[j]=tem;
            i = j;
        }
    }
}
void Make_Heap(int *heap){
    int i;
    int unsortedSize;
    unsortedSize = heap[0];
    for(i = unsortedSize / 2; i >= 1; i--) Adjust(heap, i);
}

int main(){
    int heap[30];
    int NumberofElements;
    int i;
    int lastElement;
    int tem;
    printf("Enter the number of elements present in the unsorted Array: ");
    scanf("%d", &NumberofElements);
    printf("nEnter the members of the array one by one: "); /* Asking for the elements of the unsorted array*/
    for(i = 1; i <= NumberofElements; i++) scanf("%d", &heap[i]);
    heap[0] = NumberofElements;  /*store the number of elements of an array in the 1st element of array-heap */
    Make_Heap(heap);
    while(heap[0] > 1) /*Loop for the Sorting process*/
    {
        lastElement=heap[0];
        tem=heap[1];
        heap[1]=heap[lastElement];
        heap[lastElement]=tem;
        heap[0]--;
        Adjust(heap,1);
    }
    printf("Sorted Array: ");/*Printing the sorted Array*/
    for(i=1;i<=NumberofElements;i++) printf("%d ",heap[i]);
    printf("\n");

    return 0;
}

/**
 take [5 1 4 2 0 9 6] as example
 调用一次 Make_Heap(heap)，可以保证heap[1]最大 并不能保证heap[1:n]为大顶堆
 **/
