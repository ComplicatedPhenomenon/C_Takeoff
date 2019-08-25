/**
 * 已知 sqrt (2)约等于 1.414，要求不用数学库，求 sqrt (2)精确到小数点后 10 位。
 **/
#include<stdio.h>
#include<math.h>

int main(){
    double left, right, mid;
    /*The C library function double pow(double x, double y) returns x raised to the power of y i.e. xy.*/

    printf("%lf\n", pow(1.414,2));
    printf("%lf\n", pow(1.415,2));
    left = 1.414;
    right = 1.415;

    mid = (left+right)/2;
    printf("%lf\n", pow(mid, 2));
    /*
    while (True){
            (pow(mid,2)>2)? right = mid :left = mid;
            mid = (left+right)/2;
    }
    */



    return 0;
}

int countDecimalDigits(){
    int count = 0;
    num = abs(num);
    num = num - int(num);
    while (num != 0){
        num = num * 10
        count = count + 1
        num = num - int(num)
    }

    return count;

}
