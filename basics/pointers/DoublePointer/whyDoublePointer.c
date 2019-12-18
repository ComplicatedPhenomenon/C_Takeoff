#include<stdio.h>

int main(){
    /**
    var     s
        ----------------------------------
        |  0x32    | ........| 'asd'     |
        |__________|_________|___________|
    addr   0xf3                 0x32

    var     s                               p
        ----------------------------------------------
        |  0x32    | ........| 'asd'     | 0xf3  |
        |__________|_________|___________|_______|____
    addr   0xf3                 0x32
    **/

    char *cp = "hello";
    char **cpp;
    cpp = &cp;
    int a = sizeof("hello");
    int b = sizeof(cp);
    printf("Size of 'hello' : %d bytes\n", a);
    printf("Size of 'cp' : %d bytes\n", b);
    printf("`cp` is : %p\n", cp);
    printf("`cp` stored %s\n", cp);
    printf("Address of pointer `cp` is : %p\n",&cp);
    printf("`cpp` stored : %p\n",cpp);

    for(int i = 0; i < a-1; i++){
        printf("(cp+%d) = %p\n",i,cp+i);
	    printf("*(cp+%d) = %c\n",i,*(cp+i));
	    printf("(cpp+%d) = %p\n",i,cpp+i);
    }

    /*
    *(cp + 0) = 'H';
    printf("%s\n", cp);
    */

    return 0;
}
