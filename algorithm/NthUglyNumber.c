/**
 * Runtime: 76 ms, faster than 5.00% of C online submissions for Ugly Number II.
 * Memory Usage: 8.3 MB, less than 37.04% of C online submissions for Ugly Number II.
 **/
#include<stdio.h>
#include<stdlib.h>

int nthUglyNumber(int n){
    int *p;
    int a=0, b=0, c=0, tem=0;
    int i;

    p = calloc(n, sizeof(int) );
    *(p+0) = 1;

    for( i= 1; i < n; ++i){
        tem = *(p+a) * 2 > *(p+b)*3 ? *(p+b) * 3 : *(p+a) * 2;
        tem = tem > *(p+c) * 5 ? *(p+c) * 5 : tem;
        *(p+i) = tem;
        if (tem == *(p+a) * 2) ++a;
        if (tem == *(p+b) * 3) ++b;
        if (tem == *(p+c) * 5) ++c;
        //printf("*(p+%d) = %d\n", i, *(p+i));
    }
    return *(p+n-1);
}

int main(){
    int n = 120;
    int x = nthUglyNumber(n);
    printf("%d\n", x);
    return 0;
}

/**
 * Runtime: 4 ms, faster than 100.00% of C online submissions for Ugly Number II.
 * Memory Usage: 8.4 MB, less than 16.67% of C online submissions for Ugly Number II.
 **/
