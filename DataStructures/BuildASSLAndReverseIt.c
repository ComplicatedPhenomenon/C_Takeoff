#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int data;
    struct Cell * next;
} tCell;
tCell *head;

void printSSL(tCell *head);
tCell *reverseASSL(tCell *head);
void freeSSL(tCell *head);

int main(){
    tCell * curr;
    tCell * last;

    head = (tCell *) malloc (sizeof (tCell));
    last = head;                               /* last and head points to the same address */
    head->data = 100;                          /* modify the value of that allocated address */
    head->next = NULL;                         /* 1 node in the linked list */

    for (int i = 0; i < 20; i++) {
        curr = (tCell *) malloc (sizeof (tCell));   /* create a block in the memory to store a node */
        curr->data = last->data - 1;            /* modify the value of this latest allocated address */
	    curr->next = NULL;
	    last->next = curr;                      /* link the 2nd one with the 1st one */
	    last = curr;                            /* last point to the latest node */
    }

    printf("The original single linked list is: \n");
    printSSL(head);
    printf("The reversed single linked list is: \n");
    head = reverseASSL(head);
    printSSL(head);

    freeSSL(head);
    return 0;
}


tCell *reverseASSL(tCell *head){
    tCell * curr = head;
    tCell * prev = NULL;
    tCell * next;
    while(curr->next != NULL){
        next = curr->next; /* find the next node behind node curr1 */
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    head = curr;

    return head;
}

void printSSL(tCell *head){
    tCell *curr;
    curr = head;
    while (curr != NULL) {
        printf ("Sequence = %d\n", curr->data);
        curr = curr->next;
    }

}


void freeSSL(tCell *head){
    tCell *curr;
    while( (curr=head) != NULL){
        head = head->next;
        /* clear the whole space for storing the SSL */
        free(curr);
    }
}
