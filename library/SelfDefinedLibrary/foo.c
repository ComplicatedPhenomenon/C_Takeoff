#include<stdio.h>

int addnumbers(int a, int b);
int saysomething();

int main(int arg, char* argv[]){
  int total;
  total = addnumbers(2,3);
  saysomething();
  printf("%d\n", total);

  return 0;
}
