/**
 * @file
 * 
 * The C library function int rand(void) returns a pseudo-random number in the range of 0 to RAND_MAX
 * 
 * bug need to be fixed: https://stackoverflow.com/a/14067742/7583919
 * 
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

static char geneSet[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!.";

char *generateAString(size_t lenOfGeneSet, size_t lenOfPW){
    char *p = calloc(lenOfPW, sizeof(char));

    int randomNumber;
    for(int i = 0; i < lenOfPW; i++) {
        randomNumber = rand()% lenOfGeneSet;
        *(p + i) = geneSet[randomNumber];
    }
    return p;
}


void Mutate(char* ptrToTarget, size_t lenOfPW, size_t lenOfGeneSet){
    int r1, r2;

    r1 = rand()%lenOfPW;
    r2 = rand()%lenOfGeneSet;
    while(*(ptrToTarget+r1) == geneSet[r2]){
        r2 = rand()%lenOfGeneSet;
    }
    *(ptrToTarget+r1) = geneSet[r2];    
}


int getFitness(char *ptrToTarget, char *password, size_t lenOfPW ){
    int mark = 0;
    for( int i = 0; i < lenOfPW; i++){
        mark += (*(password+i) == *(ptrToTarget+i)) ? 1 : 0;
    }
    return mark;
}


int main(){
    char password[] = "Hello World!";
    char *pw = password;
    
    size_t lenOfPW = sizeof(password)/sizeof(password[0]);
    size_t lenOfGeneSet = sizeof(geneSet)/sizeof(geneSet[0]);

    char *ptrToTarget = NULL;

    srand(time(NULL));

    ptrToTarget =  generateAString(lenOfGeneSet, lenOfPW);
    printf("First string generated: %s\n", ptrToTarget);

    int mark = getFitness(ptrToTarget, pw, lenOfPW);
    printf("Before Mutation, string is: %s, mark is %d\n", ptrToTarget, mark);
    Mutate(ptrToTarget, lenOfPW, lenOfGeneSet);
    mark = getFitness(ptrToTarget, password, lenOfPW);
    printf("After Mutation, string is : %s, mark is %d\n", ptrToTarget, mark);

    free(ptrToTarget);
    return 0;
}
