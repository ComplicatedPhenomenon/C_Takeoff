/**
 * Array-number as the parameter of function-quicksort
 * https://stackoverflow.com/questions/6567742/passing-an-array-as-an-argument-to-a-function-in-c
 * pass the address of the first element of the array
 **/

#include<stdio.h>
#define maxIndex 11

void quicksort(int *number,int first, int last){
    int tem;
    int i, j, pivot, temp;
    if(first<last){
        pivot=first;
        printf("pivot is: %d\n",number[pivot]);
        i=first;
        j=last;
        while(i < j){
            /**
             * To say it explicitly, the element iterated by is less than pivot
             * vice versa for j
             **/
            while(number[i] <= number[pivot] && i<last) i++;
            while(number[j] > number[pivot]) j--;
            if(i < j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }

        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;

        printf("quicksort([");
        for(tem = 0; tem <= j - 1; tem++) printf("%d ",number[tem]);
        printf("], %d, %d)\n", first, j - 1);

        printf("Now the list is: ");
        for(i = 0; i < maxIndex; i++) printf("%d ",number[i]);
        printf("\n");

        quicksort(number,first,j-1);

        printf("quicksort([");
        for(tem = j + 1; tem <= last; tem++) printf("%d ",number[i]);
        printf("], %d, %d)\n", j + 1, last);

        quicksort(number,j+1,last);
    }
}

int main(){
    int i;
    int number[11] = {10, 1, 9, 6, 17, 11, 13, 5, 12, 14, 0 };

    printf("The Original Order is: ");
    for(i = 0; i < maxIndex; i++) printf("%d ",number[i]);
    printf("\n");

    printf("quicksort([");
    for(i = 0; i < maxIndex; i++) printf("%d ",number[i]);
    printf("], %d, %d)\n", 0, maxIndex - 1);

    quicksort(number, 0, maxIndex-1);
    printf("The Sorted Order is: ");
    for(i = 0; i < 11; i++)
    printf(" %d",number[i]);
    printf("\n");
    return 0;
}
