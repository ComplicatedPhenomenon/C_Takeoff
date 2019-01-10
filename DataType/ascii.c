/*
 * C program to print ASCII values of all characters.
 * Storing and printing 'special' characters (♠, ♣, ♥, ♦,)
 */

#include <stdio.h>

int main()
{
    for(int i = 0; i <= 255; i++) {
      fprintf(stdout, "[%d]: %c\n", i, i);
    }
    printf("...............\n");
    printf("%c\n", 248);

    return 0;
}
