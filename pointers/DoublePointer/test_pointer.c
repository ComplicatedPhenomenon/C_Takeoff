#include<stdio.h>

int main(){
    char *cp = "hello";
    char **cpp;
    cpp = &cp;
    int a = sizeof("hello");
    int b = sizeof(cp);

    printf("Size of 'hello' : %d bytes\n",a);
    printf("Size of 'cp' : %d bytes\n", b);
    printf("Address of 'hello' is :  %p\n",&("hello"));
    printf("Address of pointer `cp` is : %p\n",&cp);
    printf("Address of pointer `cpp` is : %p\n",&cpp);

    int i;
    for(i = 0; i < a-1; i++){
        printf("(cp+%d) = %p\n",i,cp+i);
	      printf("*(cp+%d) = %c\n",i,*(cp+i));
	      printf("(cpp+%d) = %p\n",i,cpp+i);
    }
}
