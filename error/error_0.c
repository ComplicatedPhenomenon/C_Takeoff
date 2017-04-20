#include<stdio.h>
#include<errno.h>
#include<string.h>

extern int errno;

int main()
{
	FILE * pf;
	int errnum;
	pf = fopen("exist.txt","rb");
	if (pf == NULL)
	{
		errnum = errno;
		fprintf(stderr, "Value of errno: %d\n", errno);
		perror("Error printed by perror");
		fprintf(stderr,"Error opening file: %s\n", strerror(errnum));
	}
	else{
		fclose(pf);
		printf("It's doing well\n");
	}
	return 0;
}















/*
 * FILE type, It's a typedef to a structure containing data about the file 
 * handle. The exact contents if the stucture are system specific.
 *
 * meaning it's typically declared as a simple structure, and then internally
 * in the OS libiriary the FILE pointer is cast to the actual data-type of 
 * the data-structure that the OS will use access from a file
 */
