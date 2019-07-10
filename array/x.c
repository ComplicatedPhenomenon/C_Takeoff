/* error: expression is not assignable*/
#include<stdio.h>
#include<stdlib.h>

int x=6;

void changex();
void changex2nd();

int main(){
    changex();
    printf("%d\n",x);
    changex2nd();
    printf("%d\n",x);
    return 0;
}

void changex(){
    x=7;
}

void changex2nd(){
    printf("%d\n",x);
    x=9;

}
