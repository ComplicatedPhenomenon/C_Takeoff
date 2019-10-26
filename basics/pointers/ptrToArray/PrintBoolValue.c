#include<stdio.h>
#include<stdbool.h>

int main(){
    bool bool_value ;
    char prompt[] = "Press Enter to explore:";
    char *ptrToString = prompt;

    bool_value = ptrToString == prompt;
    printf("%d\n", bool_value);
    printf("%s\n", bool_value ? "true" : "false");
    fputs(bool_value ? "true" : "false", stdout);
    printf("\n");

    return 0;
}
