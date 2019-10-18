/**
 * Runtime: 104 ms, faster than 5.00% of C online submissions for Ugly Number II.
 * Memory Usage: 6.9 MB, less than 64.81% of C online submissions for Ugly Number II.
 **/
#include<stdio.h>
#include<stdlib.h>

int nthUglyNumber(int n){
    int array[n];
    int a=0, b=0, c=0, tem=0;
    int i;

    array[0] = 1;
    for( i= 1; i < n; ++i){
        tem = array[a] * 2 > array[b]*3 ? array[b]*3 : array[a] * 2;
        tem = tem > array[c] * 5? array[c] * 5 : tem;
        array[i] = tem;
        if (tem == array[a] * 2) ++a;
        if (tem == array[b] * 3) ++b;
        if (tem == array[c] * 5) ++c;
        //printf("array[%d] = %d\n", i, array[i]);
    }
    return array[n-1];
}

int main(){
    int n = 120;
    int x = nthUglyNumber(n);
    printf("%d\n", x);
    return 0;
}

/**
 * After comment debugging printf
 * Runtime: 8 ms, faster than 71.25% of C online submissions for Ugly Number II.
 * Memory Usage: 6.9 MB, less than 62.96% of C online submissions for Ugly Number II.
 **/
