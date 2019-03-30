#include<stdio.h>

char *getAnotherString(){
    char *ptrToTarget = "Hi, ComplicatedPhenomenon";

    printf("ptrToTarget                 = %p\n", ptrToTarget);
    printf("ptrToTarget                 = %s\n", ptrToTarget);
    
    return ptrToTarget;
}

int main(){
    char *ptrToTarget = NULL;
    ptrToTarget = getAnotherString();
    printf("ptrToTarget                 = %p\n", ptrToTarget);
    printf("ptrToTarget                 = %s\n", ptrToTarget);

    return 0;
}
