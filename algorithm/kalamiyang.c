#include<stdio.h>
#include<math.h>
int nmax = 128; 
int main(void)
{
    int i;
    double total;
    total = 0;
    for(i = 1; i < nmax; i++)
    {
	total = total + 1/pow(i,2);
    }
    printf("%f\n",total);
    return 0;
}
