/**
 *   Modified Date: 9/12/2018
 *   Description: Function pointers are useful for passing functions as parameters to other functions
 **/

#include<stdio.h>

void easyf0(){
    printf(" \n");
    printf("I am from planet Earth\n");
}
void foo(void (*a)()){
    a();
}

/*
 * This states that the parameter a will be a pointer to a function which has a void return type and which takes zero parameter.
*/
void easyf1(){
    printf("Hello world\n");
}

void easyf2(){
    printf(" \n");
    printf("An advanced version of Hello World\n");
}

int main(){
    easyf0();
    foo(&easyf0);
    easyf1();
    foo(&easyf1);
    easyf2();
    foo(&easyf2);
    return 1;
}
