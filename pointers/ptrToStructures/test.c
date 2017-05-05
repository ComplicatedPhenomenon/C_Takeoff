#include <stdio.h>
#define MAX_COLORS  256

typedef struct {
    char *name;
    int  red;
    int  green;
    int  blue;
} Color;

Color Colors[MAX_COLORS];
/*Array of structure variables and single structure variable Color color*/

void eachColor (void (*fp)(Color *c)) {
    int i;
    for (i=0; i<MAX_COLORS; i++)
        (*fp)(&Colors[i]);
}

void printColor(Color* c) {
    if (c->name)
        printf("%s = %i,%i,%i\n", c->name, c->red, c->green, c->blue);
}

int main() 
{
    Colors[0].name = "red";
    Colors[0].red = 255;
    Colors[0].green = 0;
    Colors[0].blue = 0;

    Colors[1].name = "blue";
    Colors[1].red = 0;
    Colors[1].green = 0;
    Colors[1].blue = 255;

    Colors[2].name = "black";
    Colors[2].red = 0;
    Colors[2].green = 0;
    Colors[2].blue = 0;
    eachColor(printColor);
}i
