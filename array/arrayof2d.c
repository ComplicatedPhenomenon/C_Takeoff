#include<stdio.h>

int main()
{
    int a[5][2] = {{1,2},{3,4},{5,6},{0,0},{4,5}};
    int i, j;
    for (i = 0; i < 5; i++)
    {
	for (j = 0, j < 2; j++;)
	{
	    printf("array[%d][%d] = %d\n",i,j,a[i][j]);
	}
    }
    printf("what's wrong?\n");

    return 0;
}
