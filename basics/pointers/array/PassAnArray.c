/**
 * @file
 * 
 * Objects 
 * - Create an array in a function.
 * - call this function in main and manage with this array
 * 
 * reference: https://stackoverflow.com/q/766893/7583919
 **/
#include<stdio.h>

int *getArray(){
    static int array[20];
    //static int array[20];  //  address of stack memory associated with local variable
    int i;
    for (i=0; i < 10; ++i) array[i] = i;

    return array;
}


void getArray_1(){
    int array[10];
    int i;

    for (i=0; i < 10; ++i) array[i] = i;
    for (i=0; i < 10; ++i) printf("%d\n", array[i]);
    printf("You can do nothing with this array in getArray_1\n");
}


int main(){
    int *ptrToFunction;
    int i;

    ptrToFunction = getArray();
    for(i=0; i < 10; i++){
        printf ("*(ptrToFunction + %d) : %d\n",i ,*(ptrToFunction+i));
    }
    getArray_1();

    return 0;
}
