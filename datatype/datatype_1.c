#include<stdio.h>
#include<math.h>

int main()
{
         int i;
         long double sum_1;
         long double sum_2;
         long double Sum1;
	 long double Sum2;
	 sum_1 = 0;
	 sum_2 = 0;
	 Sum1 = 0;
	 Sum2 = 0;
	 /*generise sum as a formula*/
/****************************************************************************+
 * 									     +
 *       sum = pow(2,0) + pow(2,-1) + pow(2,-2) + pow(2,-3) +                +
 *	       pow(2,-4) + pow(2,-5) + pow(2,-6) + pow(2,-7) +               +
 *	       pow(2,-8) + pow(2,-9) + pow(2,-10) + pow(2,-11) +             +
 *	       pow(2,-12) + pow(2,-13) + pow(2,-14) + pow(2,-15) +           + 
 *	       pow(2,-16) + pow(2,-17) + pow(2,-18) + pow(2,-19) +           +
 *	       pow(2,-20) + pow(2,-21) + pow(2,-22) + pow(2,-23) ;           +
 *	       								     +
 ****************************************************************************/
	 for (i = 0; i < 24; i++){
		 sum_1 = sum_1 +pow(2,-i);
	 }  

	 for (i = 0; i < 52; i++){
		 sum_2 = sum_2 +pow(2,-i);
	 }  
	 Sum1 = sum_1 * pow(2,pow(2,7)-1);
	 Sum2 = sum_2 * pow(2, (pow(2,10)-1));

	 printf("%LE\n",sum_1);
	 printf("%LE\n",sum_2);
	 printf("%LE\n",Sum1);
	 printf("%LE\n",Sum2);

	 return 0;
}

