#!/bin/sh

cc -Wall -c ctest1.c ctest2.c
ar -cvq libtest.a ctest1.o ctest2.o
cc -o prog prog.c libtest.a

./prog

rm  prog *.o *.a
