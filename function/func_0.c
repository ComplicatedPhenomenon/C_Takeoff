/**
 *   Modified Date: Git will handle it.
 *   Description:  C Program to implement a queue using two stacks
 **/

#include<stdio.h>

/* function declaration */
int max(int, int, int);
/**
 * When you declare a function with an empty argument list, you invoke
 * K&R (pre-prototype) semantics and nothing is assumed about the parameter
 * list; this is so that pre-ANSI C code will still compile. If you want a
 * prototyped function with an empty parameter list, use (void) instead of ()
 **/
int main(void)
{
    int a = 100;
    int b = 200;
    int c = 419;
    int ret;

    ret = max(a, b, c);
    printf("Max value is: %d\n", ret);

    return 0;
}
/* function returning the max between two numbers */
int max(int num1,int num2, int num3)
{

    int result;
    int tem;
    if(num1 > num2){
        tem = num1;
    }
    else{
        tem = num2;
    }
    if(tem > num3){
        result = tem;
    }
    else{
        result = num3;
    }

    return result;
}
