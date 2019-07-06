/**
 * The C library function int rand(void) returns a pseudo-random number in the range of 0 to RAND_MAX
 **/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

static char geneSet[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!.";

char *generateAString(size_t lenOfGeneSet, size_t x){
    int i;
    char result[x];
    int randomNumber;
    char *ptrToTarget = malloc(strlen(result) + 1);

    srand(time(NULL));
    for(i = 0; i < x; i++) {
        randomNumber = rand()% lenOfGeneSet;
        result[i] = geneSet[randomNumber];
    }
    strcpy(ptrToTarget, result); //Highlights!

    return ptrToTarget;
}

int getFitness(char *ptrToTarget, char *ptrToPW, size_t lenOfPW ){
    int i;
    int mark = 0;

    //for (i = 0; i < lenOfPW; i++)printf("%c",*(ptrToTarget+i));
    //printf("\n");
    //printf("%s\n", ptrToTarget);
    for(i=0; i < lenOfPW; i++){
        if(*(ptrToPW) == *(ptrToTarget+i)){
            mark +=1;
        }
        else mark +=0;
    }
    printf("%d\n", mark);
    return mark;
}

char* Mutate(char* ptrToTarget, size_t lenOfPW, size_t lenOfGeneSet){
    int randomNumber1, randomNumber2;

    printf("Before Mutation, string is: %s\n", ptrToTarget);
    randomNumber1 = rand()%lenOfPW;
    randomNumber2 = rand()%lenOfGeneSet;
    while(*(ptrToTarget+randomNumber1) == geneSet[randomNumber2]){
        randomNumber2 = rand()%lenOfGeneSet;
    }
    *(ptrToTarget+randomNumber1) = geneSet[randomNumber2];
    printf("After Mutation, string is : %s\n", ptrToTarget);
    return ptrToTarget;
}



int main(){
    char *ptrToTarget = NULL;
    int mark;
    char password[] = "Hello World!";
    size_t lenOfPW = strlen(password);
    size_t lenOfGeneSet = strlen(geneSet);
    char *ptrToPW = password;

    ptrToTarget = generateAString(lenOfGeneSet, lenOfPW);

    printf("First string generated: %s\n", ptrToTarget);

    mark = getFitness(ptrToTarget, ptrToPW, lenOfPW);
    ptrToTarget = Mutate(ptrToTarget, lenOfPW, lenOfGeneSet);
    mark = getFitness(ptrToTarget, ptrToPW, lenOfPW);


    free(ptrToTarget);
    return 0;
}
