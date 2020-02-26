/**
 * @file
 * 
 * The C library function int rand(void) returns a pseudo-random number in the range of 0 to RAND_MAX
 * 
 * bug need to be fixed
 * /
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

static char geneSet[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!.";

void generateAString(char *ptrToTarget, size_t lenOfGeneSet, size_t lenOfPW){
    int randomNumber;
    for(size_t i = 0; i < lenOfPW; i++) {
        randomNumber = rand()% lenOfGeneSet;
        *(ptrToTarget + i) = geneSet[randomNumber];
    }
}


void Mutate(char* ptrToTarget, size_t lenOfPW, size_t lenOfGeneSet){
    int randomNumber1, randomNumber2;

    randomNumber1 = rand()%lenOfPW;
    randomNumber2 = rand()%lenOfGeneSet;
    while(*(ptrToTarget+randomNumber1) == geneSet[randomNumber2]){
        randomNumber2 = rand()%lenOfGeneSet;
    }
    *(ptrToTarget+randomNumber1) = geneSet[randomNumber2];    
}


int getFitness(char *ptrToTarget, char *password, size_t lenOfPW ){
    int mark = 0;
    for( int i=0; i < lenOfPW; i++){
        mark += (password[i] == ptrToTarget[i]) ? 1 : 0;
    }
    return mark;
}


int main(){
    char password[] = "Hello World!";
    
    size_t lenOfPW = sizeof(password)/sizeof(password[0]);
    size_t lenOfGeneSet = sizeof(geneSet)/sizeof(geneSet[0]);

    char *ptrToTarget = calloc(lenOfPW, sizeof(char));


    srand(time(NULL));

    generateAString(ptrToTarget, lenOfGeneSet, lenOfPW);
    printf("First string generated: %s\n", ptrToTarget);

    int mark = getFitness(ptrToTarget, password, lenOfPW);
    printf("Before Mutation, string is: %s, mark is %d\n", ptrToTarget, mark);
    Mutate(ptrToTarget, lenOfPW, lenOfGeneSet);
    mark = getFitness(ptrToTarget, password, lenOfPW);
    printf("After Mutation, string is : %s, mark is %d\n", ptrToTarget, mark);

    free(ptrToTarget);
    return 0;
}
