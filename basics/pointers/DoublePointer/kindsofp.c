#include<stdio.h>

int main()
{
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
    char *s = "asd";
    char **p = &s;
    int i;
    printf("Using print formatter %%s: s = %s\n", s);
    printf("Using print formatter %%p: s = %p\n", s);
    printf("The address of variable s: &s = %p\n", &s);
    printf("The value of variable p: p = %p\n", p);
    printf("The address of p is: %p\n", &p);

    for(i =0; i < 3; i++){
	      printf("&s[%d] = %p; *(s+%d) = %c \n", i, &s[i], i, *(s+i));
    }

    return 0;
}
