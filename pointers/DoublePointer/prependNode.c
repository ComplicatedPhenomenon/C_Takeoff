#include<stdio.h>

typedef struct node
{
    char *name;
    struct node *next;
} Node;

Node *createNode(char *nameArg){
    Node *x = malloc(sizeof(Node));
    x->name = malloc(strlen(name) + 1)
    strcpy(p->name, nameArg);
    x->next = NULL;
    return x;
}


// The caller
NODE *head = malloc(sizeof(NODE));
head = NULL;

// Prepend node with the name "Goldfish"
prependNode(&head, createNode("Goldfish"));

void prependNode(NODE **headnode, NODE *newNode)
{
    newNode->next = *headnode;
    *headnode = newNode;
}

void append(NODE **headRef, NODE *newNode)
{
    NODE **tracer = headRef;
    while (*tracer) {
        tracer = &(*tracer)->next;
    }
    newNode->next = *tracer;
    *tracer = newNode;
}


int main(int argc, char *argv[]){
    
}
