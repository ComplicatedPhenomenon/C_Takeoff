#include<stdio.h>

int main(){
    int j = 3;
    int k;
    for(int i = 0; i < 8; ++i) printf("%d\n", i);
    for(j = 0; j < 8; ++j) printf("%d", j);
    printf("\n");
    for(k = 0; k < 8; ++k) printf("%d", k);
    //printf("\n%d\n", ++i); /* error: use of undeclared identifier 'i'*/
    printf("\n%d\n", ++j);
    printf("%d\n", ++k);

    return 0;
}
