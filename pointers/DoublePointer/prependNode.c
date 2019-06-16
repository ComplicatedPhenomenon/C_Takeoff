#include<stdio.h>

/* single linked list*/
typedef struct node
{
    char *name;
    struct node *next;
} Node;

Node *createNode(char *nameArg);

Node *head = (Node *) malloc(sizeof(Node));
head = NULL;

// Prepend node with the name "Goldfish"
void prependNode(Node **headnode, Node *newNode);
prependNode(&head, createNode("Goldfish"));
void append(Node **headRef, Node *newNode);

int main(int argc, char *argv[]){

}

Node *createNode(char *nameArg){
    Node *x = (Node *)malloc(sizeof(Node));
    //x->name = (char *)malloc(strlen(name) + 1)
    strcpy(x->name, nameArg);
    x->next = NULL;
    return x;
}

void prependNode(Node **headnode, Node *newNode){
    newNode->next = *headnode;
    *headnode = newNode;
}

void append(Node **headRef, Node *newNode){
    Node **tracer = headRef;
    while (*tracer) {
        tracer = &(*tracer)->next;
    }
    newNode->next = *tracer;
    *tracer = newNode;
}
