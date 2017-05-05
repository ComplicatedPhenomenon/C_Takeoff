#include<stdio.h>
void foo(int i)
{
	i = 20;/* the change is local to the function*/
}

void oop(int *j)
{
       *j = 4; /* The change is visible in the calling of the function*/
}

void bar()
{
	int i = 10;
	int j = 8;
	printf("I got two integers i=%d, j=%d\n",i ,j);
	foo(i);
	oop(&j);
	printf("call by value\n");
	printf("i = %d \n", i);
	printf("call by reference\n");
	printf("j = %d \n", j);
}

int main()
{
	bar();
	return 0;
}
