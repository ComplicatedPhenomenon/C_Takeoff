#include<stdio.h>
#include<stdlib.h>

void print(int *wm);

int main()
{
    int *IPtr;
    //IPtr is a pointer which equall to non-NULL.

    printf("Whether the pointer IPtr is NULL(0) or non-NULL(1) : %d\n", IPtr != NULL);
    printf("I want to print NULL out : %p\n",NULL);
    print(IPtr);

    IPtr = NULL;
    print(IPtr);

    int a;
    IPtr = &a;
    print(IPtr);

    char *ptr = malloc(1);
    if( ptr == NULL) printf("Out of memory\n");
    else printf("Remember to free the space previously allocated\n");
    free(ptr);

    return 0;
}

void print(int *wm){
    if(wm!=NULL){printf("IPtr now is non-NULL\n");}
    else{ printf("IPtr now is NULL\n");}
}

/********************************************
 * if ( TRUE ) {
 *   Execute all statements inside the body
 *   }  
 *
 * !Pointer Initialization
 * http://en.cppreference.com/w/c/io/fprintf
 ********************************************/
