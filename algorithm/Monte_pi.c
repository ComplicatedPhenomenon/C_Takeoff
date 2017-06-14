/***************************************************
 * Program to compute Pi using Monte Carlo methods *
 * Not efficient enough                            *
 ***************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<time.h>
//#define SEED 35791246

int main(int argc, char* argv)
{
   int niter=0;
   double x,y;
   int i,count=0; /* # of points in the 1st quadrant of unit circle */
   double z;
   double pi;

   printf("Enter the number of iterations used to estimate pi: ");
   scanf("%d",&niter);

   /* initialize random numbers */
   srand(time(NULL));
   //srand(SEED);
   count=0;
   for ( i=0; i<niter; i++) {
      x = (double)rand()/RAND_MAX;  
/*****************************************************************************
 * When you divide an integer by an integer, you get truncating integer 
 * division. So using y = (double)rand() / RAND_MAX is absolutely the right 
 * way to get the result you want.
 * **************************************************************************/
      y = (double)rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1) count++;
      }
   pi=(double)count/niter*4;
   printf("# of trials= %d , estimate of pi is %g \n",niter,pi);
}
