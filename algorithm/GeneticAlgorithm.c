#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char *generateAString(size_t x){
    int i;
    char geneSet[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!.";
    size_t lenOfGeneSet = strlen(geneSet);
    char result[x];
    int randomNumber;
    char *ptrToTarget;

    //printf("%s\n", ptrToTarget);
    srand(time(NULL));

    for(i = 0; i < x; i++) {
        randomNumber = rand()% lenOfGeneSet;
        result[i] = geneSet[randomNumber];
    }
    ptrToTarget = result; //Highlights!
    return ptrToTarget;
}

int Fitness(char *ptrToTarget){
    char password[] = "Hello World!";
    size_t lenOfPW = strlen(password);
    int i;
    int mark = 0;
    for(i=0; i < lenOfPW; i++){
        if(password[i] == *(ptrToTarget+i)){
            mark +=1;
        }
        else mark +=0;
    }
    printf("%d\n", mark);
    return mark;
}

int main(){
    char password[] = "Hello World!";
    char *ptrToTarget;
    size_t lenOfPW = strlen(password);
    int mark;

    ptrToTarget = generateAString(lenOfPW);
    printf("%s\n", ptrToTarget);

    mark = Fitness(ptrToTarget);
    printf("%d\n", mark);
    return 0;
}
