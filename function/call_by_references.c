#include<stdio.h>

void swap(int *x , int *y ); 

int main()
{ 
	/* local variable defintion */
	int a = 100;
	int b = 200;

	printf("Before swp, value of a = %d\n",a);
	printf("Before swp, value of a = %d\n",b);

	/* calling funcation swp () */
	swap(&a, &b);
	/* then the function perform the task */

	/* let's see what has the function done */

	printf("After the swp, value of a = %d\n",a);
	printf("After the swp, value of b = %d\n",b);

	return 0;
}

void swap(int *x, int *y)
{
	int temp;
        temp = *x; /* save the contents of var x in tem */
	*x = *y;   /* the contents of x become ys'*/
	*y = temp; /* the contents of y become xs'*/
	
	return; 
}

