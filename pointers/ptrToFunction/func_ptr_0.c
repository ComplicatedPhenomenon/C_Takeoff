#include<stdio.h>
/*start with a function we will be pointing to */
int addInt(int m, int n){
    return m+n;
}

int main()
{
    int m, n;
    /* 1st, let's pointer to a function which receive 2 integers and return an integer */
    int (*functionPtr) (int, int);
    /* now we can safely point to ourfunction.*/
    functionPtr = &addInt ;

    printf("Input two integers\n");
    scanf("%d%d",&m,&n);
    printf("Adding them together we get is %d\n", addInt(m,n));
    printf("(*functionPtr)(%d, %d) is %d\n", m, n,(*functionPtr)(m,n));        
    return 0;
}
