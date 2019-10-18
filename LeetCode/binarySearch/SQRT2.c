/**
 * 已知 sqrt (2)约等于 1.414，要求不用数学库，求 sqrt (2)精确到小数点后 10 位。
 * https://stackoverflow.com/questions/17837654/count-number-of-digits-after-in-floating-point-numbers
 **/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    double lower, higher, mid;

    printf("pow(1.414,2) is %lf\n", pow(1.414,2));
    printf("pow(1.415,2) is %lf\n", pow(1.415,2));

    lower = 1.41;
    higher = 1.42;
    mid = (lower + higher) / 2;

    while (higher - lower > pow(10, -10)){
        if (mid * mid > 2)
            higher = mid;
        else
            lower = mid;
        mid = (lower + higher) / 2;
    }

    printf("higher : %lf lower : %lf higer - lower : %lf \n ", higher, lower, higher - lower);

    printf("%lf\n ", mid);  //1.414214
    return 0;
}
