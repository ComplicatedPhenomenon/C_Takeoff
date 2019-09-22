#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUMBER 100

typedef struct Cell {
    int data;
    struct Cell * next; /* tCell *next will not work here */
} tCell;

tCell *head=NULL;

void buildAnDecendingLL();
int deleteANodeAndReturnAValue(int lengthOfSLL, int nth);
void printSSL();
void freeSSL();

int main(){
    int *ptr;
    int i, nth;
    int lengthOfSLL;
    int tem;

    srand(time(NULL));

    ptr = (int*)calloc(NUMBER, sizeof(int));
    buildAnDecendingLL();
    printSSL();

    lengthOfSLL = NUMBER;
    for(i = 0; i < NUMBER; ++i){
        nth = rand() % lengthOfSLL + 1;
        tem = deleteANodeAndReturnAValue(lengthOfSLL, nth);
        ptr[i] = tem;
        //printf("%d\n",tem);
        --lengthOfSLL;
    }

    for(i = 0; i < NUMBER; ++i)printf("%d ", ptr[i]);
    printf("\n");

    free(ptr);
    freeSSL();
    return 0;
}


void buildAnDecendingLL(){
    tCell * curr;
    tCell * last;
    head = (tCell *) malloc (sizeof (tCell));
    last = head;
    head->data = 100;
    head->next = NULL;
    /* Build a sorted lisr*/
    for (int i = 0; i < 99; i++){
        curr = (tCell *) malloc (sizeof (tCell));
        curr->data = last->data - 1;
        curr->next = NULL;
        last->next = curr;
        last = curr;
    }
}


int deleteANodeAndReturnAValue(int sizeofSLL,  int nth){
    int i;
    int nthData;
    tCell *curr;

    curr = head;
    //Situation 1: Head node is changed
    if(nth == 1){
        nthData = curr->data;
        head = curr->next;
        free(curr);
    }
    // Situation 2: Delete the middle node
    else if(1 < nth && nth < sizeofSLL ){

        for(i = 0; i < nth-2; i++) curr = curr->next;
        /*suppose there exists 3 nodes, delete the 2nd node*/
        nthData = curr->next->data;
        free(curr->next);
        curr->next = curr->next->next;
    }

    // Situation 3: Delete the last node
    else{
        i = 0;
        while(i != nth-2){
            curr = curr->next;
            ++i;
        }
        nthData = curr->next->data;
        free(curr->next);
        curr->next = NULL;

    }

    return nthData;
}


void printSSL(){
    tCell *curr;
    curr = head;
    while (curr != NULL) {
        printf ("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}


void freeSSL(){
    tCell *curr;
    while( (curr=head) != NULL){
        head = head->next;
        free(curr);
    }
}
