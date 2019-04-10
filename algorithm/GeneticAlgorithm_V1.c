// ptrToPW points to 13 characters like kDlbwTJ!WWtv?, there always a ? sign at the end of the string.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

static char geneSet[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!.";
static char password[] = "Hello World!";
char *ptrToTarget;
char *ptrToPW;

void generateAString(size_t lenOfGeneSet, size_t lenOfPW){
    int i;
    char result[lenOfPW];
    int randomNumber;
    printf("lenOfPW = %lu\n", lenOfPW);
    ptrToTarget = malloc(strlen(result) + 1);
    srand(time(NULL));
    for(i = 0; i < lenOfPW; i++) {
        randomNumber = rand()% lenOfGeneSet;
        result[i] = geneSet[randomNumber];
    }
    strcpy(ptrToTarget, result); //Highlights!
    printf("Size of result[lenOfPW] = %lu\n", sizeof(result));
    printf("Size of *ptrToTarget = %lu\n", sizeof(ptrToTarget));
    //ptrToTarget = result;

    return;
}

int getFitness(size_t lenOfPW ){
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
    printf("Fitness: %d\n", mark);
    return mark;
}

void Mutate(size_t lenOfPW, size_t lenOfGeneSet){
    int randomNumber1, randomNumber2;

    printf("Before Mutation, string is: %s\n", ptrToTarget);
    randomNumber1 = rand()%lenOfPW;
    randomNumber2 = rand()%lenOfGeneSet;
    while(*(ptrToTarget+randomNumber1) == geneSet[randomNumber2]){
        randomNumber2 = rand()%lenOfGeneSet;
    }
    *(ptrToTarget+randomNumber1) = geneSet[randomNumber2];
    printf("After Mutation, string is : %s\n", ptrToTarget);
    return;
}

int main(){
    size_t lenOfGeneSet = strlen(geneSet);
    size_t lenOfPW = strlen(password);
    ptrToTarget = NULL;
    ptrToPW = password;

    generateAString(lenOfGeneSet, lenOfPW);
    printf("First string generated: %s\n", ptrToTarget);
    getFitness(lenOfPW);
    Mutate(lenOfPW, lenOfGeneSet);
    getFitness(lenOfPW);
    free(ptrToTarget);

    return 0;
}
