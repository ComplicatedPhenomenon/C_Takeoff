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
    *ptrToTarget = 'x';
    return ptrToTarget;
}

int increseOne(int a){
    ++a;
    printf("In function increseOne, a now is %d\n", a);
    printf("Address of a in function increseOne is %p\n", &a);
    return a;
}

void increment(int a){
    ++a;
    printf("In function increment, a now is %d\n", a);
    printf("Address of a in function increment is %p\n", &a);
}


int main(){
    easyf0();
    foo(&easyf0);

    char target[] = "Hi, czfzdxx";
    char *ptrToTarget = target;

    printf("target is : %s\n", target);

    target[0] = 'n';
    printf("After target[0] = 'n', ptrToTarget is %s\n", ptrToTarget);

    ptrToTarget = changeFirstCharacter(target);
    printf("After changeFirstCharacter, ptrToTarget is: %s\n",  ptrToTarget);

    int a = 10;
    a = increseOne(a);
    printf("In main after increseOne(a), a is %d\n", a);
    printf("Address of a in main, a now is %p\n", &a);

    increment(a);
    printf("In main, a is %d\n", a);
    printf("Address of a in main, a now is %p\n", &a);


    return 0;
}

/*
I am from planet Earth
I am from planet Earth
target is : Hi, czfzdxx
After target[0] = 'n', ptrToTarget is ni, czfzdxx
After changeFirstCharacter, ptrToTarget is: xi, czfzdxx
In function increseOne, a now is 11
Address of a in function increseOne, a now is 0x7ffee52be7ec
In main after increseOne(a), a is 11
Address of a in main, a now is 0x7ffee52be81c
In function increment, a now is 12
Address of a in function increment, a now is 0x7ffee52be7ec
In main, a is 11
Address of a in main, a now is 0x7ffee52be81c
*/
