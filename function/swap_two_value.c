#include<stdio.h>
#include<string.h>

void swap(int * , int * );

int main()
{
    /* local variable defintion */
    int a = 100;
    int b = 200;
    char string_a[10];
    char string_b[10];
    char string_c[10];

    strcpy(a, "Alive");
    strcpy(b, "Dead");

    printf("Before swap, value of a = %d\n",a);
    printf("Before swap, value of b = %d\n",b);

    swap(&a, &b);

    printf("After the swap, value of a = %d\n",a);
    printf("After the swap, value of b = %d\n",b);


    /*assignment to expression with array type*/

    printf("before exchanging, string_a is : %s\n", string_a);
    printf("before exchanging, string_b is : %s\n", string_b);
    printf("---------------------------\n");

    strcpy(string_c, string_a);
    strcpy(string_a, string_b);
    strcpy(string_b, string_c);
    printf("After exchanging, string_a is : %s\n", string_a);
    printf("After exchanging, string_b is : %s\n", string_string_b);

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
