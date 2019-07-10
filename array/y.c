#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//int *ptr = NULL;
void ptrToA();
void ptrToB();

int main(){

    ptrToA();
    sleep(10);
    int x=8;
    ptrToB();
    return 0;
}

void ptrToA(){
    //printf("In A %p\n", ptr);
    int A=3;
    printf("&A %p\n", &A);
    int *ptr = &A;  

    //printf("In A %p\n", ptr);
    //printf("A = %d\n", *ptr);
}

void ptrToB(){
    int B=-40000;
    printf("&B %p\n", &B);
    //ptr = &B;
    //printf("B = %d\n", *ptr);
}
