/**
 * size_t strlen(const char *str)
 **/
#include<stdio.h>
#include<string.h>


bool isValid(char * s){
    size_t len = strlen(s);
    int i;
    for (i = 0; i < len; i++) {

    }


}


int main(){
    char *s = "{}[]()";
    size_t len = strlen(s);
    int i;
    for (i = 0; i < len; i++) {
        printf("%c\n", *(s+i));
    }

    return 0;
}
