#include<stdio.h>

int saysomething(){
  printf("%s\n","This is a shared library example!" );
  return 0;
}

int addnumbers(int a, int b){
  int sum;

  sum = a + b;

  return sum;
}

/* *
 * A dynamical shared library contains a function that can be used by another
 * program for performing routines in that functions
 * */
