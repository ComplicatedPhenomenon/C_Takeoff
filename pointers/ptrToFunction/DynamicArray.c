#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *getAnotherString(){
    char target[] = "Hi, ComplicatedPhenomenon";
    // malloc(nBytes) will allocates a block of memory cells of at least nBytes bytes that us suitably aligned for any usage.

    char *ptrToTarget = malloc(strlen(target) + 1);
    strcpy(ptrToTarget, target);

    printf("ptrToTarget                 = %p\n", ptrToTarget);
    printf("ptrToTarget                 = %s\n", ptrToTarget);
    return ptrToTarget;

}

int main(){
    char *ptrToTarget = NULL;
    ptrToTarget = getAnotherString();
    printf("ptrToTarget                 = %p\n", ptrToTarget);
    printf("ptrToTarget                 = %s\n", ptrToTarget);
    free(ptrToTarget);

    return 0;
}
