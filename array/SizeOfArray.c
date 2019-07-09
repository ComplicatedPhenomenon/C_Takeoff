#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZEOFARRAY 17

int main(){
    int a[17]; // a is not initialized
    printf("sizeof(a)/sizeof(a[0])==17 is %s\n", sizeof(a)/sizeof(a[0])==17? "True":"False");
    int twoDArray[3][5]; // declared a static 2D array of 3 rows, 5 cols
    printf("sizeof(twoDArray[3][5]): %lu, sizeof(twoDArray[3]): %lu", sizeof(twoDArray), sizeof(twoDArray[3]));
    int c[SIZEOFARRAY];
    srand(time(NULL));
    for(int i = 0; i< SIZEOFARRAY; ++i) c[i]  = rand()% SIZEOFARRAY; // There exists duplication.
    printf("\n");
    for(int i = 0; i< SIZEOFARRAY; ++i) printf("%d ", c[i]);
    printf("\n");

    int *d=NULL;
    int b = 1;
    d = &b;
    printf("%d\n", *d);

    return 0;
}
