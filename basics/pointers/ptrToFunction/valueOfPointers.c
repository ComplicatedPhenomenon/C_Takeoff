/*https://stackoverflow.com/questions/39142190/value-of-pointer-in-c*/
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

int main(){
    char c = 'c';
    printf("c address = %" PRIuPTR "\n", (uintptr_t)&c);
}
