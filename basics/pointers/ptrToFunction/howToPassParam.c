#include<stdio.h>

int addOneBV(int);
int addOneBR(int *x);

int main(){
    int input = 0;
    printf("Now output = %d\n", addOneBV(input));
    printf("After calling addOneBR, input = %d\n", input);
    printf("Now output = %d\n", addOneBR(&input));
    printf("After calling addOneBR, input = %d\n", input);

    return 0;
}

int addOneBV(int x){
    printf("In addOneBV, now x = %d\n", x);
    x = 8;
    printf("In addOneBV, now x = %d\n", x);
    return x+1;
}

int addOneBR(int *x){
    printf("In addOneBR, now *x= %d\n", *x);
    *x = 8;
    printf("In addOneBR, now *x= %d\n", *x);
    return *x+1;
}
