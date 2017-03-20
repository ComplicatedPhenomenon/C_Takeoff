#include<stdio.h>
#include<float.h>

int main(void)
{       

	printf("Storage size for float: %zu \n", sizeof(long double));
	printf("Minimum float positive value: %E\n", FLT_MIN);
	printf("Maximum float positive value: %E\n", FLT_MAX);
	printf("Precision value: %d\n", FLT_DIG);
	printf("Storage size for long double: %zu byte \n",sizeof(double));
	printf("char=%zu\n",sizeof(char));
	printf("float=%zu byte\n",sizeof(float));
	printf("long int=%zu\n",sizeof(float));
	
	return 0;
}
