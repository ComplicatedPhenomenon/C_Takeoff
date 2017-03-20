#include<stdio.h>

void swap(int *x, int *y); 

int main()
{ 
	/* local variable defintion */
	int a = 100;
	int b = 200;

	printf("Before swp, value of a = %d\n",a);
	printf("Before swp, value of a = %d\n",b);

	/* calling funcation swp () */
	//swp(*a,*b);
	swap(&a,&b);
	/* then the function perform the task */

	/* let's see what has the function done */

	printf("After the swp, value of a = %d\n",a);
	printf("After the swp, value of b = %d\n",b);

	return 0;
}

void swap(int *x, int *y)
{
	int *temp;
        temp = *x;/* save the address of variable x  */
	*x =*y;
	*y = temp;
	
	return ;
}

/* &a=*x,&b=*y,it means the pointer x point to a,now it is the address of &a,in other words *x is a */
/* 我让x指向a变量的地址，那么*x表示变量a的值 */
