#include<stdio.h>

void print(int *wm);

int main()
{
    int * IPtr;
    printf("%d\n", IPtr != NULL);
    //IP tr is a pointer which equall to true
    
    print(NULL);
    print(IPtr);
    // After executing this statement, it's supposed to print <aa> on the screen.

    int a;
    IPtr = &a;

    print(IPtr);

    return 0;
}

void print(int *wm){
    if(wm){printf("IPtr is null, therefore, you see this\n");}
    else{ printf("aa\n");}
}

/********************************************
 * if ( TRUE ) {
 *   Execute all statements inside the body
 *   }  
 ********************************************/
