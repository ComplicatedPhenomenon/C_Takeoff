#include <stdio.h>
#include <stdlib.h>

/*****************************************************************************************************
*  When you declare a function with an empty argument list, you invoke K&R (pre-prototype) semantics 
*  and nothing is assumed about the parameter list; this is so that pre-ANSI C code will still compile.
*  If you want a prototyped function with an empty parameter list, use (void) instead of ().
*****************************************************************************************************/
static void test(void) 
{
    printf("HERE\n");
}

int main(void) 
{
    test();
    return 0;
}
