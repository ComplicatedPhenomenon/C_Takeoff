/**
 * condition is a pointer
 * if(condition) means condition != NULL, why? NULL means false
 * condition should be true,
 **/
#include<stdio.h>
#include<stdlib.h>

typedef struct nodestructure{
    int data;
    struct nodestructure * next;
} node;

// Implementation of single linkde list.
node * insertSLL(node * head, int item){

    node * tail;
    if (head==NULL){
        head = (node *) malloc(sizeof(node));
        head->data = item;
        head->next = NULL;
    }
    else{
        node * temp = (node *) malloc(sizeof(node));
        temp->data = item;
        temp->next = NULL;
        tail = head;
        // find the tail of linked list
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = temp;
    }
    return head;
}

void display(node * head){
    node * curr;
    curr = head;
    printf("Single Linked List:");
    while(curr != NULL)
    {
        printf("%d, %p ", curr->data, curr);
        curr = curr->next;
        printf("\n");
    }
}


void freeMemory(node * head){
    node * curr;
    while((curr=head) != NULL){
        head = head->next;
        free(curr);
    }
}


int main(){
    node * head = NULL;
    head = insertSLL(head, 2);
    if(!head)printf("Something is wrong, because head is still none after calling insertSLL\n");
    head = insertSLL(head, 3);
    head = insertSLL(head, -3);
    head = insertSLL(head, 13);
    head = insertSLL(head, 31);
    display(head);
    freeMemory(head);
    return 0;
}
