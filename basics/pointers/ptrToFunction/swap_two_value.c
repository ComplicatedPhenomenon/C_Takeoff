#include<stdio.h>
#include<string.h>

void swap(int * , int * );

int main()
{
    /* local variable defintion */
    int a = 100;
    int b = 200;
/*
    char string_a[10];
    char string_b[10];
    char string_c[10];

    strcpy(string_a, "Alive");
    strcpy(string_b, "Dead");
*/

    printf("Before swap, value of    a = %d, b = %d\n",a, b);
    printf("In main,                 &a= %p, &b= %p\n", &a, &b);

    swap(&a, &b);

    printf("After the swap, value of a = %d, b = %d\n", a, b);


    /*assignment to expression with array type*/
    /*

    printf("before exchanging, string_a is : %s\n", string_a);
    printf("before exchanging, string_b is : %s\n", string_b);
    printf("---------------------------\n");

    strcpy(string_c, string_a);
    strcpy(string_a, string_b);
    strcpy(string_b, string_c);
    printf("After exchanging, string_a is : %s\n", string_a);
    printf("After exchanging, string_b is : %s\n", string_b);
    */
    return 0;
}

void swap(int *x, int *y){
  	int temp=0;
    printf("In swap,                 x=%p,  y= %p\n", x, y);
    temp = *x; /* save the contents of var x in tem */
  	*x = *y;
  	*y = temp;

	return;
}
