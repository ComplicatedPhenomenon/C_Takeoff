#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUMBER 12

int main(){
    int i, j;
    int *ptrToOneDArray;
    int **ptrToTwoDArray;
    int nrows = 3;
    int ncolumns=4;

    srand(time(NULL));
    ptrToOneDArray = (int*)calloc(NUMBER, sizeof(int));
    ptrToTwoDArray = (int **)malloc( nrows * sizeof(int *));  // allocate nrows int *

    //1D array initialization
    //for(i = 0; i < NUMBER; ++i) ptrToOneDArray[i]=rand()%NUMBER;
    for(i = 0; i < NUMBER; ++i){
        ptrToOneDArray[i]=rand()%NUMBER;
    }
    for(i = 0; i < NUMBER; ++i) printf("%d ", ptrToOneDArray[i]);
    printf("\n");

    // 2D array initialization
    for(i = 0; i < ncolumns; ++i) ptrToTwoDArray[i] = (int *)malloc(ncolumns * sizeof(int));
    for(i = 0; i < nrows; ++i) {
        for (j = 0; j < ncolumns; ++j){
            ptrToTwoDArray[i][j]= rand() % 100;
        }
    }
    for(i = 0; i < nrows; ++i) {
        for (j = 0; j < ncolumns; ++j){
            printf("%d ",ptrToTwoDArray[i][j]);
        }
    }
    printf("\n");


    // let's release the allocated memory properly
    free(ptrToOneDArray);
    for(i = 0; i < ncolumns; ++i)
        free(ptrToTwoDArray[i]);
    free(ptrToTwoDArray);
    return 0;
}
