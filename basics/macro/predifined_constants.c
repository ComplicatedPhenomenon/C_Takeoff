#include<stdio.h>
#include<math.h>

int main() {
	printf("File: %s\n",__FILE__);
	printf("Date: %s\n",__DATE__);
	printf("Time: %s\n",__TIME__);
	printf("Line: %d\n",__LINE__);
	printf("Line: %d\n",__LINE__);
	printf("ANSI: %d\n",__STDC__);
	printf("------from the Unix98 standard, all values are type double-------------\n");
	printf("M_PI = %f M_E = %f M_SQRT2= %f\n", M_PI, M_E, M_SQRT2);
	printf("%f",sin(3.14));

	return 0;
}
