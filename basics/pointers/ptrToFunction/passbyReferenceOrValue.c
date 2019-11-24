/**
 *  Pointers allow a way to write functions that can modify their arguments' values: 
 *  the C way of implementing Pass by Reference.
 *  When and how will the memory will be released?
 **/
#include<stdio.h>

/**
 * 1. This means that changes in the parameter, intentional or accidental,
 *    cannot affect the argument. 
 * 2. the cost of copying: Copying all bytes of the argument can be costly 
 *    if the object to be copied is large
 **/
void foo(int k){
    k = 20;
}
void oop(int *k){
    *k = 4;
}

int modifyArgumentByValue(int k){
    ++k;
    return k;
}

void bar(){
    int i = 10;
    int j = 8;

    printf("I got two integers i = %d, j = %d, &i = %p, &j = %p\n",i ,j, &i, &j);
    foo(i);
    printf("Execute foo(i). &i = %p, i = %d\n", &i, i);
    modifyArgumentByValue(i);
    printf("Execute modifyArgumentByValue(i). &i = %p, i = %d\n", &i, i);
    oop(&j);
    printf("Execute oop(&j).&j = %p, j = %d\n", &j, j);
}

int main(){
    bar();
    return 0;
}
