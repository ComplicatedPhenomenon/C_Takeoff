/**
 * @file
 * \brief
 * reference: https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/ 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char *name;
    struct node *next;
} Node;

Node *createNode(char *nameArg);
Node *prependNode(Node *head, Node *newNode);
void append(Node *head, Node *newNode);
void display(Node *head);
void freeMemory(Node * head);

int main(){
    Node *head = NULL;
    head = prependNode(head, createNode("Goldfish"));
    append(head, createNode("Redfish"));
    head = prependNode(head, createNode("Blackfish"));
    append(head, createNode("Bluefish"));
    display(head);
    freeMemory(head);
    return 0;
}


/**
 * Function to create a node and return a pointer to the node.
 */ 
Node *createNode(char *name){

    Node *p = malloc(sizeof(Node));
    p->name = malloc(strlen(name) + 1);
    strcpy(p->name, name);
    p->next = NULL; 
    return p;
}

/**
 * Function to put newNode before the origin head node 
 */ 
Node* prependNode(Node *head, Node *newNode){
    newNode->next = head;
    head = newNode;
}

/**
 * Function to put the newNode behind the origin tail node
 */ 
void append(Node *head, Node *newNode){
    Node *tracer = head;
    while (tracer->next) {
        tracer = tracer->next;
    }
    tracer->next = newNode;
}

/**
 * Function display the whole linked list
 */ 
void display(Node *head){
    Node * curr;
    curr = head;
    printf("%s", "Single Linked List: ");
    while(curr->next != NULL){
        printf("%s -> ", curr->name);
        curr = curr->next;
    }
    printf("%s\n", curr->name);
}

/**
 * Function free the memory taken by the linked list
 */ 
void freeMemory(Node * head){
    Node * curr;
    while((curr=head) != NULL){
        head = head->next;
        free(curr->name);
        free(curr);
    }
}