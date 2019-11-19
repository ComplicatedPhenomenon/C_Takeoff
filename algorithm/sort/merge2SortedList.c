#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int *array, int x);
int *bubbleSort(int *array, int n);


int main(){
    srand(time(NULL));
    int numA[32]={0};
    int numB[14]={0};
    int *num1;
    int *num2;


    size_t n1 = sizeof(numA)/sizeof(numA[0]);
    size_t n2 = sizeof(numB)/sizeof(numB[0]);

    printf("n1 = %lu, n2 = %lu\n", n1, n2);

    int mergedAB[n1+n2];

    for(int i = 0; i < n1; ++i) numA[i]  = rand()% 100;
    for(int i = 0; i < n2; ++i) numB[i]  = rand()% 100;

    printArray(numA, n1);
    printArray(numB, n2);
    num1 = bubbleSort(numA, n1);
    num2 = bubbleSort(numB, n2);
    printArray(num1, n1);
    printArray(num2, n2);

    int ind1 =0, ind2=0;
    int tem;

    for(int i = 0; i < n1+n2; ++i){
        // Make sure arrayay index won't overflow
        if(ind1 < n1 && ind2 < n2){
            tem = num1[ind1] > num2[ind2]? num2[ind2] : num1[ind1];
            mergedAB[i] = tem;
            if(tem == num2[ind2]) ++ind2;
            else ++ind1;
        }
        else if (ind1 == n1){
            mergedAB[i] = num2[ind2];
            ++ind2;
        }
        else{
            mergedAB[i] = num1[ind1];
            ++ind1;
        }
    }
    printArray(mergedAB, n1+n2);

    return 0;

}

void printArray(int *num, int x){
    printf("[");
    for(int i = 0; i < x; ++i)  printf("%d ", num[i]);
    printf("]\n");
}


int *bubbleSort(int *array, int n){
    int tem;
    for (int x = n; x > 1; --x){
        for(int i = 0; i < (x-1); ++i){
            if (array[i] > array[i+1]){
                tem = array[i];
                array[i] = array[i+1];
                array[i+1] = tem;
            }
        }
    }
    return array;

}
