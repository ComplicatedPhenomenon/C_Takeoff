/**
 *   Modified Date:
 *   Description:
 **/

#include<stdio.h>

typedef struct oop
{
   void (*method)(void);
   int x;
   int y;
} oop;

void f()
{
   printf("hey.\n");
}

oop new_oop(void)
{
   oop o;
   o.method = &f;
   o.y = 4;
   o.x = 2;
   return o; // return an object, with an object, you can apply method and data.
}

int main(int argc, char ** argv)
{
   oop a = new_oop(); //Instantiate an object a
   printf("%d.\n",a.x+a.y);
   a.method();
   return 0;
}
