# !/bin/sh
gcc -Wall -I ~/gsl/include -c 17.15.1.c
gcc -L ~/gsl/lib 17.15.1.o -lgsl -lgslcblas -lm

./a.out 
rm a.out
rm 17.15.1.o

