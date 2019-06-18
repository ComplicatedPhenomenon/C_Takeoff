/**
  Author: ComplicatedPhenomenon
  Modified Date: 11/29/2018
**/
#include<stdio.h>
#include<stdlib.h>

typedef struct nodestructure{
    int data;
    struct nodestructure * next;
} node;
node * head;
void display();
void freeMemory();
void insertSLL( int item);

int main(){
    head  = NULL;
    insertSLL(2);

    // check if head == NULL.
    if(!head){
        printf("Something is wrong, because head is still none after calling insertSLL\n");
    }

    if (head == NULL) {
        fprintf(stderr, "malloc failed\n");
        return(-1);
    }

    insertSLL(3);
    insertSLL(-3);
    insertSLL(13);
    insertSLL(31);
    freeMemory();

    return 0;
}


void insertSLL( int item){
    node * tail;
    if (head==NULL){
        head = (node *) malloc(sizeof(node));
        head->data = item;
        head->next = NULL;
        tail = head;
    }
    else{
        node * temp = (node *) malloc(sizeof(node));
        temp->data = item;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    display();
}

void display(){
    node * curr;
    curr = head;
    printf("%s", "Single Linked List:");
    while(curr != NULL)
    {
        printf("%d  　", curr->data);
        curr = curr->next;
    }
    printf("\n");

}

void freeMemory(){
    node * curr;
    while((curr=head) != NULL){
        head = head->next;
        free(curr);
    }
}
