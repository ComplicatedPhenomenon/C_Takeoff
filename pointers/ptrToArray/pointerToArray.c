#include<stdio.h>
#include<string.h>

int main(){
    int i;

    char *x = "czfzdxx, hi";
    char prompt[] = "Press Enter to explore:";
    char *ptrToString = prompt;
    char Pixar[3]={'s', 'o' , 's'};

    char *name[] = {"Wall-E-1000000001","complicatephenomenon ","czfzdxx"};
    char *pta;

    printf("%s\n",x);
    pta = &Pixar[0];

    printf("%s\n", x);
    for(i = 0; i < strlen("czfzdxx, hi"); i++){
        printf("%c", *(x+i));
        printf("\n");
    }

    for(i = 0; i < sizeof(Pixar); i++){
        printf("Pixar[%d] = %c, *(Pixar+%d) = %c, *(pta+%d)=%c  |  ",i,  Pixar[i], i, *(Pixar + i), i,  pta[i]);
        printf("&(Pixar[%d]) = %p, *(pta+%d)   = %p\n", i,  &(Pixar[i]), i,  pta+i);
    }

    for(int i = 0; i < sizeof(name)/sizeof(name[0]); i++){
    printf("name[%d]=%s, *name[%d]=%p\n",i,name[i], i, *name+i);
    }

    return 0;
}
