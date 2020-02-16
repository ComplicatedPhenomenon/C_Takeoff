/**
 * @file
 * You need to compile this program with the flag -lm or you will get the error
 * (.text+0x43): undefined reference to 'pow'
 */

#include<stdio.h>
#include<float.h>
#include<limits.h>
#include<math.h>


int main() {
    printf("CHAR_BIT     : %d\n", CHAR_BIT);
    printf("SHRT_MIN     : %d\n", SHRT_MIN);
    printf(" SHRT_MAX    : %d\n", SHRT_MAX);
    printf("CHAR_MIN     : %d\n", CHAR_MIN);
    printf("CHAR_MAX     : %d\n", CHAR_MAX);
    printf("USHRT_MAX    : %d\n", USHRT_MAX);
    printf("UCHAR_MAX    : %d\n", UCHAR_MAX);
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
    printf("%d\n", sum);

    long double sum_1 = 0;
    long double sum_2 = 0;

    for (i = 0; i < 24; i++) sum_1 += pow(2,-i);
    sum_1 *= pow(2, pow(2, 7) - 1);
    printf("%LE\n",sum_1);
    
    for (i = 0; i < 52; i++) sum_2 += pow(2,-i);
    sum_2 *= pow(2, pow(2,10) - 1);
    printf("%LE\n",sum_2);

    printf("9 is %o in octonary number system\n", 9);
    printf("16 is %x in hexadecimal form\n", 16);

    return 0;

}


