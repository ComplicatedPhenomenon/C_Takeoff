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

void easyf1(){
    printf("Hello world\n");
}

void easyf2(){
    printf(" \n");
    printf("An advanced version of Hello World\n");
}

int main(){
    easyf0();
    foo(&easyf1);
    foo(&easyf2);
    return 1;
}
