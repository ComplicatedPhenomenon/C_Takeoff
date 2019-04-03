/**
 *   Modified Date: Git will handle it.
 *   Description:  C Program to implement a queue using two stacks
 **/

#include<stdio.h>

int maxImplementation_1(int, int, int);
int minImplementation_2(int, int, int);

int main(void)
{
    int a = 100;
    int b = 200;
    int c = 419;
    int ret;

    ret = maxImplementation_1(a, b, c);
    printf("Maximum value is: %d\n", ret);
    ret = minImplementation_2(a, b, c);
    printf("Minimum value is: %d\n", ret);

    return 0;
}
/* function returning the max between two numbers */
int maxImplementation_1(int num1,int num2, int num3){

    int result;
    int tem;
    tem = (num1 > num2 ? num1 : num2);
    tem = (tem > num3  ? tem  : num3);

    return result;
}

int minImplementation_2(int a1, int a2, int a3){
    int tem;
    tem =  (a1 < a2 ? a1 : a2);
    tem =  (a3 < tem ? a3 : tem);

    return tem;
}
