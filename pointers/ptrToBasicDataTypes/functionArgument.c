/**
 * When and how will the memory will be released?
 **/
#include<stdio.h>

void foo(int k){
    k = 20;/* the change is local to the function*/
    printf("The adress of k in `void foo(int k)` is %p, k = %d\n", &k, k);
}
void oop(int *l){
    *l = 4; /* The change is visible in the calling of the function*/
    printf("The address for pointer l in `void oop(int *l)` is %p, *l = %d\n", &l, *l);
}

void bar(){
    int i = 10;
    int j = 8;
    printf("I got two integers i=%d, j=%d\n",i ,j);
    printf("Meanwhile, &i=%p, &j=%p\n",&i ,&j);
    foo(i);
    printf("`Execute foo(i)`. now i = %d,  &i=%p\n", i, &i);
    oop(&j);
    printf("`Execute oop(&j)`. now j = %d,  &j=%p\n",j, &j);
}

int main(){
    bar();

    return 0;
}
