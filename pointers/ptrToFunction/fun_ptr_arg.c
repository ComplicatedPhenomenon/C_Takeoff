/**
 *   You can't change the value (i.e., address of) a static array.
 **/

#include<stdio.h>

void easyf0(){
    printf("I am from planet Earth\n");
}

void foo(void (*a)()){
    a();
}

char *changeFirstCharacter(char *ptrToTarget){
    *ptrToTarget = 'h';
    return ptrToTarget;
}

char *changeBackFirstCharacter(char *ptrToTarget){
    *ptrToTarget = 'H';
    return ptrToTarget;
}

int main(){
    easyf0();
    foo(&easyf0);

    char target[] = "Hi, czfzdxx";
    char *ptrToTarget = target;

    printf("%c\n", *ptrToTarget);
    printf("%s\n", ptrToTarget);
    printf("%c\n", target[0]);
    printf("%s\n", target);
    ptrToTarget = changeFirstCharacter(ptrToTarget);
    printf("%s\n", ptrToTarget);
    ptrToTarget = changeBackFirstCharacter(ptrToTarget);
    printf("%s\n", ptrToTarget);

    return 0;
}
