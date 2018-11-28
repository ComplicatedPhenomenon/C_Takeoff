#include<stdio.h>
#include<stdlib.h>

typedef struct nodestructure{
    int data;
    struct nodestructure * next;
} node;

node * head;

void display(node * head);

void freeMemory(node * head);

// Implementation of single linkde list.
void insertSLL(node * head, int item){
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
    display(head);
    freeMemory(head);
}

int main(){

    insertSLL(head, 2);
    /*if(!head){
        printf("Something is wrong, because head is still none after calling insertSLL\n");
    }*/
    insertSLL(head, 3);
    insertSLL(head, -3);
    insertSLL(head, 13);
    insertSLL(head, 31);
    /*display(head);
    freeMemory(head);*/
    return 0;
}


void display(node * head){
    node * curr;
    curr = head;
    printf("%s", "Single Linked List:");
    while(curr != NULL)
    {
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");

}

void freeMemory(node * head){
    node * curr;
    while((curr=head) != NULL){
        head = head->next;
        free(curr);
    }
}
