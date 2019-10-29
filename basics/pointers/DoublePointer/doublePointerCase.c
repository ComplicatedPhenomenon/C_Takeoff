/* https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/ */
#include<stdio.h>

typedef struct node{
    char *name;
    struct node *next;
} Node;

Node *createNode(char *nameArg);

Node *head = (Node *) malloc(sizeof(Node));
head = NULL;

void prependNode(Node **headnode, Node *newNode); // headnode save the address of a pointer which refer to a Node
// Node *newNode = createNode("Goldfish") newNode to capture what createNode just returned
prependNode(&head, createNode("Goldfish"));
void append(Node **headRef, Node *newNode);

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

/** Why not
    void prependNode(Node *headnode, Node *newNode){
        newNode->next = headnode;
        headnode = newNode;
    }
 **/

void append(Node **headRef, Node *newNode){
    Node **tracer = headRef;
    while (*tracer) {
        tracer = &(*tracer)->next;
    }
    newNode->next = *tracer;
    *tracer = newNode;
}

/** Why not 

    void append(Node *headnode, Node *newNode){
        Node *tracer = headnode;
        while (tracer) {
            tracer = tracer->next;
        }
        newNode->next = tracer; // newNode->next = NULL;
        tracer = newNode;
}
 **/