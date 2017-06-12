#include<stdio.h>

int addInt(int a, int b)
{
    return a+b;
}

int main()
{
    int (*funcPtr)(int, int);
    funcPtr = &addInt;
    int sum = (*funcPtr)(2,3);
    printf("sum=%d\n",sum);
    /* Passing the pointer to another function is basically the same*/

    return 0;
}
