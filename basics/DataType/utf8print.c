/*
 * print all utf-8 characters on terminal
 *
 */

#include <stdio.h>

void utf8print(unsigned int cp) {
    if (cp < 0x80)
        printf("%c", cp);
    else if (cp < 0x800)
        printf("%c%c", 0xC0 + cp / 0x40, 0x80 + cp % 0x40);

}

int main() {
    // characters below 32 are "not printable"
    for (unsigned int i = 32; i != 2048; ++i) {
        printf("U+%04X: ", i);
        utf8print(i);
        fputc('\n', stdout);
    }
}
