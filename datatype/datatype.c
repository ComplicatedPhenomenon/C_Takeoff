#include<stdio.h>
#include<float.h>
#include<limits.h>


int main()
{
	printf("Size of float :%lu \n",sizeof(float));
	printf("Size of long :%lu \n",sizeof(long));
	printf("Size of double :%lu \n",sizeof(long double));
	printf("%E\n",FLT_MIN);
	printf("%E\n",FLT_MIN);
	printf("precision value : %d\n", FLT_DIG);
	printf("------------------------------------------------\n");	

	printf("Size of unsigned int : %lu \n", sizeof(unsigned int));
	printf("Size of unsigned long long : %lu \n", sizeof(unsigned long long));
	printf("Size of unsigned short : %lu \n", sizeof(unsigned short));
	printf("Size of short : %lu \n", sizeof(short));
	printf("Size of long : %lu \n", sizeof(double));
	printf("------------------------------------------------\n");	
	printf("The minimum of short %d\n",SHRT_MIN);
	printf("The maximum of short %d\n",SHRT_MAX);
	printf("The minimum of int %d\n",INT_MIN);
	printf("The maximum of int %d\n",INT_MAX);
	printf("The minimum of char %d\n",CHAR_MIN);
	printf("The maximum of char %d\n",CHAR_MAX);

	printf("================================================-\n");	
	printf("CHAR_BIT    :   %d\n", CHAR_BIT);
	printf("CHAR_MAX    :   %d\n", CHAR_MAX);
	printf("CHAR_MIN    :   %d\n", CHAR_MIN);
	printf("INT_MAX     :   %d\n", INT_MAX);
        printf("INT_MIN     :   %d\n", INT_MIN);
	printf("UINT_MAX    :   %d\n", UINT_MAX);
	printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
 	printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
	printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
	printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
        printf("SHRT_MAX    :   %d\n", SHRT_MAX);
	printf("SHRT_MIN    :   %d\n", SHRT_MIN);
        printf("USHRT_MAX   :   %d\n", USHRT_MAX);
	printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
	printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
	printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
	printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);
	printf("FLT_MAX     :   %g\n", (float) FLT_MAX);
	printf("FLT_MIN     :   %g\n", (float) FLT_MIN);
	printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
	printf("DBL_MIN     :   %g\n", (double) DBL_MIN);
	printf("-DBL_MAX     :  %g\n", (double) -DBL_MAX);
	
	return 0;

}


/*You can make use of limits.h that contains the definition of the limits for the decimal/float types:*/
/* http://www.csse.uwa.edu.au/programming/ansic-library.html#float */
