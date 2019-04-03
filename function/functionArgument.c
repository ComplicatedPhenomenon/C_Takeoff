/**
 * Unfineshed tsask:
 * When and how will the memory will be released?
 **/
#include<stdio.h>

void foo(int k){
    k = 20;
}
void oop(int *kk){
    *kk = 4;
}

void bar(){
    int i = 10;
    int j = 8;
    printf("I got two integers i = %d, j = %d, &i = %p, &j = %p\n",i ,j, &i, &j);
    foo(i);
    printf("Execute foo(i). &i = %p, i = %d\n", &i, i);
    oop(&j);
    printf("Execute oop(&j).&j = %p, j = %d\n", &j, j);
}

int main(){
    bar();

    return 0;
}
