#include<stdio.h>

/* function declaration */
int max(int, int, int);
/*********************************************************************
 * Parameters names are not important in function declaration,       *
 * only their type is required, so the above is a valid declaration  *
 * *******************************************************************/

int main()
{
    /* local variable defination */
    int a = 100;
    int b = 200;
    int c = 419;
    int ret;
    /* calling a function to get max value */
    ret = max(a, b, c);
	
    printf("Max value is: %d\n", ret);

    return 0;
}
/* function returning the max between two numbers */
int max(int num1,int num2, int num3)
{
    /* local variable declaration */
    int result;
    int tem;
    if(num1 > num2)
	tem = num1;
    else 
	tem = num2;
    if(tem > num3)
	result = tem;
    else
	result = num3;
    return result;
}
