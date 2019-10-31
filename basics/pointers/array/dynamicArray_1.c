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
    ptrToOneDArray = (int*) calloc(NUMBER, sizeof(int));
    ptrToTwoDArray = (int **) calloc(nrows, sizeof(int *));  

    //1D array initialization
    for (i = 0; i < NUMBER; ++i) ptrToOneDArray[i] = rand() % NUMBER;
    for (i = 0; i < NUMBER; ++i) printf("%d ", ptrToOneDArray[i]);
    printf("\nUse for loop to print &ptrToOneDArray[i]\n");
    for (i = 0; i < NUMBER; ++i) printf("%p ", &ptrToOneDArray[i]);
    printf("\n");
    
    printf("ptrToTwoDArray is %p\n", ptrToTwoDArray);
    // 2D array initialization
    for (i = 0; i < nrows; ++i) ptrToTwoDArray[i] = (int *) calloc(ncolumns, sizeof(int));
    printf("&ptrToTwoDArray[0]: %p\n", &ptrToTwoDArray[0]);
    for (i = 0; i < nrows; ++i) printf("%p ", ptrToTwoDArray[i]);
    printf("\n");
    

    for (i = 0; i < nrows; ++i) {
        for (j = 0; j < ncolumns; ++j){
            ptrToTwoDArray[i][j]= rand() % 100;
        }
    }
 
    for (i = 0; i < nrows; ++i) {
        for (j = 0; j < ncolumns; ++j){
            printf("%d  ", ptrToTwoDArray[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < nrows; ++i) {
        for (j = 0; j < ncolumns; ++j){
            printf("%p  ", &ptrToTwoDArray[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    // let's release the allocated memory properly
    free(ptrToOneDArray);
    for (i = 0; i < nrows; ++i)
        free(ptrToTwoDArray[i]);
    free(ptrToTwoDArray);
    return 0;
}

/** output
    11 11 0 6 4 10 8 8 6 8 9 10 
    Use for loop to print &ptrToOneDArray[i]
    0x51d7040 0x51d7044 0x51d7048 0x51d704c 0x51d7050 0x51d7054 0x51d7058 0x51d705c 0x51d7060 0x51d7064 0x51d7068 0x51d706c 
    ptrToTwoDArray is 0x51d70b0
    &ptrToTwoDArray[0]: 0x51d70b0
    0x51d7550 0x51d75a0 0x51d75f0 
    71  80  41  82  
    87  93  48  17  
    86  46  61  89  
    0x51d7550  0x51d7554  0x51d7558  0x51d755c  
    0x51d75a0  0x51d75a4  0x51d75a8  0x51d75ac  
    0x51d75f0  0x51d75f4  0x51d75f8  0x51d75fc     
 **/
