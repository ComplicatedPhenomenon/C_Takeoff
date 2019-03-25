#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int main(){
    int i;
    int randomNumber;
    char geneset[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!.";
    char password[] = " Hello World";
    int lenOfGeneset = sizeof(geneset)/sizeof(char);
    int lenOfPW = sizeof(password)/sizeof(char);
    //for (i=0; i< length_of_geneset; i++) printf("%c\n", geneset[i]);

    srand(time(NULL));
    /**
     *for(i=0; i< lenOfPW; i++){
     *   randomNumber = rand()% lenOfPW;
     *   printf("%d\n", randomNumber);
     *}
     **/

    randomNumber = rand()% lenOfPW;




    return 0;
}
