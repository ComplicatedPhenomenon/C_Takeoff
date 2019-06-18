#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZEOFARRAY 17

int main(){
    int a[17];
    int b[4] = {1, 2, 3, 4};
    if(sizeof(a)/sizeof(a[0])==17) printf("sizeof(a)/sizeof(a[0])==17\n");
    int c[SIZEOFARRAY];
    int randomNumber;
    srand(time(NULL));
    for(int i = 0; i< SIZEOFARRAY; ++i){
        randomNumber = rand()% SIZEOFARRAY; // There exists duplication.
        c[i] = randomNumber;
        printf("c[%d] = %d\n", i, randomNumber);
    }

    int *d;
    d[0] = 1;
    d[1] = 2;
    d[100] = 101;
    printf("d[1]=%d, d[2]=%d, d[100]=%d\n",d[1],d[2],d[100]);
    if(sizeof(d)/sizeof(d[0])==2) printf("sizeof(d)/sizeof(d[0])==2\n");



    return 0;
}
