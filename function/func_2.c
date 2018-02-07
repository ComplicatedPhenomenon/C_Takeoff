#include<stdio.h>

int addInt(int a, int b)
{
    return a+b;
}

int main()
{
    int (*funcPtr)(int, int);
    funcPtr = &addInt;
    /* The unary address-of C operator & allows us to refer to an object through its address */
    /* The type that the address-of operator returns is a pointer type */
    int sum = (*funcPtr)(2,3);
    printf("sum=%d\n",sum);
    /* Passing the pointer to another function is basically the same*/

    return 0;
}
