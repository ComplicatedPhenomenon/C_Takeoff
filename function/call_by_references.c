#include<stdio.h>

void swap(int * , int * );

int main()
{
    /* local variable defintion */
    int a = 100;
    int b = 200;

    printf("Before swap, value of a = %d\n",a);
    printf("Before swap, value of b = %d\n",b);

    swap(&a, &b);

    printf("After the swap, value of a = %d\n",a);
    printf("After the swap, value of b = %d\n",b);

    return 0;
}

void swap(int *x, int *y)
{
	int temp;
    temp = *x; /* save the contents of var x in tem */
	*x = *y;
	*y = temp;

	return;
}
