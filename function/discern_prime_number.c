/**
 *  Task
 *  1. if you define the input as int, then it should has a range
 *  2.  make a data structure to store `i` which makes `flag = 1`.
 **/
#include <stdio.h>
int main()
{
    int n, i, flag = 0;
    printf("Input a number:\n");
    scanf("%d",&n); // Careful with scanf
    for(i=2; i<=n/2; ++i){
        //remainder is 0
    	if(n%i==0){
            flag=1;
            break;
        }
    }

  	flag==0 ? printf("%d is a prime number.\n", n):printf("%d is not a prime number\n", n);

    return 0;
}
