/************************************************************************
 * The math library must be linked in when building the executable. How *
 * to do this varies by environment, but in Linux/Unix, just add -lm to *
 * the command: `gcc test.c -o test -lm`                                *
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define NMAX 128
#define MMAX   8

int main()
/************************************************************
 * Example of the discrete Fourier transform with function  *
 * f(x) = x(1-x) in [0,1].  The inverse transform is also   *
 * performed for comparison.  Copyright (c) Tao Pang 1997.  *
 * **********************************************************/
{
    int i,n,m;
    double f0,h,rn,x;
    double fr[NMAX],fi[NMAX],gr[NMAX],gi[NMAX];
    void dft();

    n = NMAX;
    m = MMAX;
    h = 1.0/(n-1);
    rn = n;
    f0 = 1/sqrt(rn);

    for (i = 0; i < n; ++i)
    {
        x = h*i;
        fr[i] = x*(1-x);
        fi[i] = 0;
    }
    dft (fr,fi,gr,gi,n);

    for (i = 0; i < n; ++i)
    {
        gr[i] = f0*gr[i];
        gi[i] = f0*gi[i];
    }

/* Perform inverse Fourier transform */

    for (i = 0; i < n; ++i)
    {
        gi[i] = -gi[i];
    }
    dft (gr,gi,fr,fi,n);
    for (i = 0; i < n; ++i)
    {
        fr[i] =  f0*fr[i];
        fi[i] = -f0*fi[i];
        if (i == 0 || i%m == 0)
        {
            x = h*i;
            printf("x=%16.8lf,fr[%d]= %16.8lf,fi[%d]=%16.8lf\n", x,i, fr[i],i,fi[i]);
        }
    }
 return 0;
}

void dft (fr,fi,gr,gi,n)
/* Subroutine to perform the discrete Fourier transform with FR and
   FI as the real and imaginary parts of the input and GR and GI as
   the corresponding  output.  Copyright (c) Tao Pang 1997. */
int n;
double fr[],fi[],gr[],gi[];
{
int i,j;
double pi,x,q;

pi = 4*atan(1);
printf("pi = %f\n",pi);
x  = 2*pi/n;

for (i = 0; i < n; ++i)
  {
  gr[i] = 0;
  gi[i] = 0;
  for (j = 0; j < n; ++j)
    {
    q = x*j*i;
    gr[i] = gr[i]+fr[j]*cos(q)+fi[j]*sin(q);
    gi[i] = gi[i]+fi[j]*cos(q)-fr[j]*sin(q);
    }
    printf("gr[%d]=%16.8lf \n",i, gr[i]);
  }
}
