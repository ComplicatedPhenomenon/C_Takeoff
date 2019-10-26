/*Importance of initialization*/

#include<stdio.h>

char *getAnotherString(){

    //static char target[] = "Hi, ComplicatedPhenomenon";
    char target[] = "Hi, ComplicatedPhenomenon";
    char *ptrToTarget =  target;
    printf("ptrToTarget                 = %p\n", ptrToTarget);
    return ptrToTarget;

}



int main(){
    char *ptrToTarget = NULL;
    if(ptrToTarget != NULL) printf("WTF?\n");
    printf("ptrToTarget                 = %p\n", ptrToTarget);

    ptrToTarget = getAnotherString();
    printf("ptrToTarget                 = %p\n", ptrToTarget);

    return 0;
}

/*
ptrToTarget                 = 0x0
ptrToTarget                 = 0x10b32e020
ptrToTarget                 = 0x10b32e020
*/
