/**
 * https://stackoverflow.com/questions/572547/what-does-static-mean-in-c
 * https://stackoverflow.com/questions/5110055/scope-of-a-variable-outside-main-in-c
 * A static variable inside a function keeps its value between invocations.
 **/

#include<stdio.h>
#include <float.h>
int x;  //  in C, all global variables initialize to 0
float y;
double z = 0.0000011; // https://stackoverflow.com/posts/50661315/edit
/*  it is not code which gets ever executed, the variable will just be set up to initially contain the 0.0000011 */

int main(){
    printf("%d\n", x); //0

    printf("%f\n", y); // 0.00000000
    printf("%f\n", z); // 0.00000110

    printf("Storage size: %lu bytes\n"
         "Minimum float value: %E\n"
         "Maximum float value: %E\n"
         "Precision: %d decimal digits\n",
         sizeof(float),
         FLT_MIN,
         FLT_MAX,
         FLT_DIG);

    return 0;
}
