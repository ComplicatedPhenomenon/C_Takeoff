#include<stdio.h>

int main(){
    int a[17];
    if(sizeof(a)/sizeof(a[0])==17) printf("sizeof(a)/sizeof(a[0])==17\n");
    return 0;
}
