/*Importance of initialization*/

#include<stdio.h>

char *getAnotherString(){

    static char target[] = "Hi, ComplicatedPhenomenon";
    char *ptrToTarget =  target;
    printf("target                      = %s\n", target);
    printf("sizeof(target)              = %lu\n",sizeof(target));
    printf("&Target                     = %p\n", &target);
    printf("ptrToTarget                 = %s\n", ptrToTarget);
    printf("ptrToTarget                 = %p\n", ptrToTarget);
    return ptrToTarget;

}

int main(){
    char *ptrToTarget = NULL;
    if(ptrToTarget != NULL) printf("WTF?\n");
    printf("ptrToTarget                 = %p\n", ptrToTarget);
    ptrToTarget = getAnotherString();
    printf("ptrToTarget                 = %p\n", ptrToTarget);
    printf("ptrToTarget                 = %s\n", ptrToTarget);

    return 0;
}
