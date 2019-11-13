// source: https://leetcode.com/problems/ugly-number-ii/
/**
   Write a program to find the n-th ugly number.

   Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

   Input: n = 10
   Output: 12
   Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

 **/
#include<stdio.h>
#include<stdlib.h>

int nthUglyNumber(int n) {
    int array[n];
    int a = 0, b = 0, c = 0, tem = 0;
    int i;

    array[0] = 1;
    for(i = 1; i < n; i++) {
        tem = array[a] * 2 > array[b] * 3 ? array[b] * 3 : array[a] * 2;
        tem = tem > array[c] * 5 ? array[c] * 5 : tem;
        array[i] = tem;
        if (tem == array[a] * 2) ++a;
        if (tem == array[b] * 3) ++b;
        if (tem == array[c] * 5) ++c;
    }
    return array[n-1];
}

int main(){
    int n = 120;
    int x = nthUglyNumber(n);
    printf("The %dth ugly number is %d\n", n, x);
    return 0;
}