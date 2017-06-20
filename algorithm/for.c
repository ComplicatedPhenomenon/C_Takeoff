#include<stdio.h>

int main(){
   for(size_t i = 9; i<=9; --i){
      printf("Hello World! %zu\n",i);}

   for(size_t i = 10;i; --i){
      for(size_t j = 1; j < i; j++){
         printf("*");
      }
      printf("\n");
   }

   for(size_t i = 0, stop = 10; i < stop; ++i){
      
      printf("__  *  __\n");}
   return 0;
}
