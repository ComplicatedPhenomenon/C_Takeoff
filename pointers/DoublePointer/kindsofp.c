#include<stdio.h>

int main()
{
    char *s = "asd";
    char **p = &s;
    int i;
    printf("s = %s\n", s);
    printf("s = %p\n", s);
    printf("*s = %c\n", *s);
    //printf("*s = %s\n", p);
    printf("&s = %p\n", &s);

    printf("p = %p\n", p);
    printf("The address of p is: %p\n", &p);

    for(i =0; i < 3; i++){
	      printf("&s[%d] = %p; *(s+%d) = %c \n", i, &s[i], i, *(s+i));
    }

    return 0;
}
