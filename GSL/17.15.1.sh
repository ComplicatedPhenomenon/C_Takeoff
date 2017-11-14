# !/bin/sh
gcc -Wall  -c 17.15.1.c
gcc 17.15.1.o -lgsl -lgslcblas -lm

./a.out
rm a.out
rm 17.15.1.o
