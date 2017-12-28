/* Let the use input the number of the 1D array*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
    printf("Enter the number of 1D array :");
    scanf("%d",&n);

	/** 
	 *  Since we cannot know during the size of the array during runtime.
	 *  We don't use int A[n] ; n cannot be a variable
	 **/
    int *A = (int *) malloc(n * sizeof(int)); /*  n integer */
    /* In C, if you want to modify your argument then you need to get passed the pointer to the value. */
	
	for(int i = 0; i < n; i++)
	{
		A[i] = i+1;
	    printf("%d\n", A[i]);	
	}

    free(A);
	return 0;
    
} 
