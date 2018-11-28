#include<stdio.h>

void foo(int i){
    i = 20;/* the change is local to the function*/
    printf("The address of i in function foo is %p\n", &i);
}
void oop(int *j){
    *j = 4; /* The change is visible in the calling of the function*/
    printf("The address of j in function oops is %p\n", &j);
}

void bar()
{
    int i = 10;
    int j = 8;
    printf("I got two integers i=%d, j=%d\n",i ,j);
    printf("The address of i and j in function main are :&i=%p, &j=%p\n",&i ,&j);
    foo(i);
    printf("Call by value. now &i=%p\n", &i);
    oop(&j);
    printf("Call by reference. now &j=%p\n", &j);
    printf("call by value\n");
    printf("i = %d \n", i);
    printf("call by reference\n");
    printf("j = %d \n", j);
}

int main()
{
 bar();
 
 return 0;
}
