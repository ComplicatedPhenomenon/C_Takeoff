/*
 * You need to compile this program with the flag -lm or you will get the error
 * (.text+0x43): undefined reference to 'pow'
 *  1 byte = 8 bits
 */

#include<stdio.h>
#include<float.h>
#include<limits.h>
#include<math.h>


int main() {
    printf("-------------Datatype: float---------------------------\n");
    printf("Size of float       : %lu \n",sizeof(float));
    printf("Size of double      : %lu \n",sizeof(double));
    printf("Size of long double : %lu \n",sizeof(long double));


    printf("-------------Datatype: integer ------------------------\n");
    printf("Size of int                : %lu \n", sizeof(int));
    printf("Size of short              : %lu \n", sizeof(short));
    printf("Size of long               : %lu \n", sizeof(long));
    printf("Size of long long          : %lu \n", sizeof(long long));

    printf("-------------limitation of char------------------------\n");
    printf("number of bits in a char: \d\n", CHAR_BIT);
    printf("The minimum of short : %d\n",SHRT_MIN);
    printf("The maximum of short : %d\n",SHRT_MAX);
    printf("The minimum of char  : %d\n",CHAR_MIN);
    printf("The maximum of char  : %d\n",CHAR_MAX);
    printf("USHRT_MAX            : %d\n", USHRT_MAX);
    printf("UCHAR_MAX            : %d\n", UCHAR_MAX);
 
    printf("----------------limitation  of int and float -------------\n");
    printf("INT_MAX      : %d\n", INT_MAX);
    int tem = INT_MAX + 1;
    printf("What happens when a integer greater than INT_MAX? like %d\n", tem);
    printf("INT_MIN      : %d\n", INT_MIN);
    printf("UINT_MAX     : %d\n", UINT_MAX);
    printf("LONG_MAX     : %ld\n", (long) LONG_MAX);
    printf("LONG_MIN     : %ld\n", (long) LONG_MIN);
    printf("SCHAR_MAX    : %d\n", SCHAR_MAX);
    printf("SCHAR_MIN    : %d\n", SCHAR_MIN);
    printf("SHRT_MAX     : %d\n", SHRT_MAX);
    printf("SHRT_MIN     : %d\n", SHRT_MIN);
    printf("UINT_MAX     : %u\n", (unsigned int) UINT_MAX);
    printf("ULONG_MAX    : %lu\n", (unsigned long) ULONG_MAX);
    printf("USHRT_MAX    : %d\n", (unsigned short) USHRT_MAX);
    printf("FLT_MAX      : %g\n", (float) FLT_MAX);
    printf("FLT_MIN      : %g\n", (float) FLT_MIN);
    printf("DBL_MAX      : %g\n", (double) DBL_MAX);
    printf("DBL_MIN      : %g\n", (double) DBL_MIN);
    printf("-DBL_MAX     : %g\n", (double) -DBL_MAX);

    printf("-----------------------  precision ---------------------\n");
    printf("precision value float      : %d\n", FLT_DIG);
    printf("precision value double long: %d\n", DBL_DIG);

    printf("--------------------------------------------------------\n");

    int i;
    int sum = 0;
    // one bit represent the sign
    for (i = 0; i < 31; i++) {
      sum += pow(2, i);
    }
    printf("sum of pow(2, i) as i from 0 to 31 is: %d\n", sum);
    
    long int item = pow(2,32); 
    printf("long int pow(2,32) = %ld\n", item);

    long double sum_1;
    long double sum_2;
    long double Sum1;
    long double Sum2;

    sum_1 = 0;
    sum_2 = 0;
    Sum1 = 0;
    Sum2 = 0;
    for (i = 0; i < 24; i++) sum_1 += pow(2,-i);
    for (i = 0; i < 52; i++) sum_2 += pow(2,-i);
    

    Sum1 = sum_1 * pow(2, pow(2, 7) - 1);
    Sum2 = sum_2 * pow(2, pow(2,10) - 1);

    printf("%LE\n",sum_1);
    printf("%LE\n",sum_2);
    printf("%LE\n",Sum1);
    printf("%LE\n",Sum2);
    fflush(stdout);

    printf("9 is %o in octonary number system\n", 9);
    printf("16 is %x in hexadecimal form\n", 16);

    return 0;

}

/**
 * You can make use of limits.h that contains the definition of the limits 
 * for the decimal/float types
 * http://www.csse.uwa.edu.au/programming/ansic-library.html#float
 * */

