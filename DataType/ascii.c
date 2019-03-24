/*
 * C program to print ASCII values of all characters.
 * Storing and printing 'special' characters (♠, ♣, ♥, ♦,)
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    for(int i = 249; i <= 255; i++) {
      fprintf(stdout, "[%d]: %c\n", i, i);
    }
    printf("...............\n");
    printf("%c\n", 248);
    printf("%d\n", argc);
    if (argv != 0) printf("argv == 0\n");
    else printf("What happened?");

    return 0;
}
