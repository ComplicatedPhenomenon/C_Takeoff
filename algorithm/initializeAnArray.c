#include<stdio.h>

int main(){
    int i ;
    char target[3];
    char *x;
    char stringArray[] = "dnsDNS";

    //char AString[] = 'xyz';
    target[0] = 'x';
    target[1] = '2';
    target[2] = 'z';

    x = target;
    printf("%s\n",x);
    x = stringArray;
    printf("%s\n",x);

    for(i=0; i < sizeof(target); i++ ) printf("%c, %c, %c \n", target[i], *x+i, *(x+i));
    for(i=0; i < sizeof(stringArray); i++ ) printf("%c", stringArray[i]);
    printf("\n");

    return 0;
}
