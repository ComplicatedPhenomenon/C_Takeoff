#include<stdio.h>
#include<errno.h>
#include<string.h>

extern int errno;

int main()
{
	FILE * pf;
/**
 * When accessing files through C, the first necessity is to have a way to
 * access the files. For C File I/O you need to use a FILE pointer, which 
 * will let the program keep track of the file being accessed.
 **/
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
