#include<stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int (* ptr[4]) (int x, int y);
int main(void){
    int result;
    int i, j, op;

    ptr[0] = sum;
    ptr[1] = subtract;
    ptr[2] = mul;
    ptr[3] = div;

    printf("Enter 2 numbers : \n");
    scanf("%d %d", &i, &j);
    printf("0: Add, 1: Subtract, 2: Mul, 3: Div\n");

    do {
	      printf("Enter number of operation: ");
	      scanf("%d", &op);
    } while(op<0 || op>3);


    result = (*ptr[op]) (i , j);
    printf ("result : %d\n",result);

    return 0;
}

int sum(int a, int b){
    return a + b;
}

int subtract(int a, int b){
    return a - b;
}

int mul(int a, int b){
	  return a * b;
}

int div(int a, int b){
    if (b)
	  return a / b ;
    else
	  return 0;
}
