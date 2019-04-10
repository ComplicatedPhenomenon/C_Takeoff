#include<stdio.h>

struct node{
    int data;
    struct node *next;
}

typedef struct node Node;


int CalculateLengthOfSLL(Node *head);
Node *NodeInfoAtPositionX(Node *head, int x);


int CalculateLengthOfSLL(Node *head){
    int NumberOfNodes = 0;
    Node *x;
    x = head;
    while(x != Null){
        NumberOfNodes += 1;
        x = x->next;
    }

    return NumberOfNodes;
}


Node *NodeInfoAtPositionX(Node *head, int x, Node *new){
    Node *curr;
    curr = head;
    int i ;
    for(i = 0; i++; i < x){
        curr = curr->next;
    }
    curr = new;
    new->next = curr->next;
    return head
}
