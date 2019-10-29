#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int data;
    struct Cell *next;
} listNode ;


void printSSL(listNode  *head);
listNode *reversePartOfASSL(listNode  *head, int m, int n);
void freeSSL(listNode  *head);

int main(){
    listNode  *head;
    listNode  *curr;
    listNode  *last;

    head = (listNode  *) malloc(sizeof (listNode ));
    last = head;                               /* last and head points to the same address */
    head -> data = 5;                            /* Initialize the value of that allocated address */
    head -> next = NULL;                         /* 1st node in the linked list */

    for (int i = 0; i < 4; i++){
        curr = (listNode  *) malloc (sizeof (listNode ));   /* create a block in the memory to store a node */
        curr -> data = last -> data - 1;            /* modify the value of this latest allocated address */
	    curr -> next = NULL;
	    last -> next = curr;                      /* link the 2nd one with the 1st one */
	    last = curr;                            /* last point to the latest node */
    }

    printf("The original single linked list is: \n");
    printSSL(head);
    printf("The reversed single linked list is: \n");
    head = reversePartOfASSL(head, 2, 4);
    printSSL(head);

    freeSSL(head);
    
    head = (listNode  *) malloc(sizeof (listNode ));
    head -> data = 5;                            
    head -> next = NULL;      
    last = head;                   
    curr = (listNode  *) malloc (sizeof (listNode ));
    curr -> data = 3;
    curr -> next = NULL;
    last -> next = curr;
    last = curr; // remove this line of code is also fine, the aim for its existence is to keep consistent


    printf("The original single linked list is: \n");
    printSSL(head);
    printf("The reversed single linked list is: \n");
    head = reversePartOfASSL(head, 1, 2);
    printSSL(head);
    freeSSL(head);

    
    head = (listNode  *) malloc(sizeof (listNode ));
    head -> data = 5;                            
    head -> next = NULL;      
    
    printf("The original single linked list is: \n");
    printSSL(head);
    printf("The reversed single linked list is: \n");
    head = reversePartOfASSL(head, 1, 1);
    printSSL(head);
    freeSSL(head);
    
    return 0;
}

listNode *reversePartOfASSL(listNode  *head, int m, int n){
    listNode *dummy = (listNode *)malloc(sizeof(listNode));
    dummy -> next = 0;
    listNode *pre = dummy;
    listNode *temp, *cur;
    dummy -> next = head;
    for (int i = 1; i < m; i++) {
       pre = pre -> next;
    }
    cur = pre -> next;
    for (int i = m; i < n; i++) {
       temp = pre -> next;
       pre -> next = cur -> next;
       cur -> next = cur -> next -> next;
       pre -> next -> next = temp;
    }
    head = dummy -> next;
    free(dummy);
    return head;
}

void printSSL(listNode  *head){
    listNode  *curr;
    curr = head;
    while (curr != NULL) {
        printf ("Sequence = %d\n", curr -> data);
        curr = curr -> next;
    }

}

void freeSSL(listNode  *head){
    listNode  *curr;
    while( (curr=head) != NULL){
        head = head -> next;
        /* clear the whole space for storing the SSL */
        free(curr);
    }
}
