#include<stdio.h>
#include<stddef.h>
#include<stdbool.h>
#include<string.h>

int main(){
   size_t a1 = 3; //argument has type ‘size_t {aka long unsigned int}’ 
   size_t a2 = 4;
   int  a;
   double b = 3;
   bool c ;
   c = 2;
   a = a1-a2;
   printf("a1 :%zu\n\n",a1);
   printf("a2 :%zu\n\n",a2);
   printf("a1-a2 = %d\n\n",a);
   printf("%e\n\n",b);
   printf("%d\n", c);
   return 0;
}


//[size_t](https://stackoverflow.com/questions/2550774/what-is-size-t-in-c)
// `echo | gcc -E -xc -include 'stddef.h' - | grep size_t`
