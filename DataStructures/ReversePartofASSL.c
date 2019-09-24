#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int data;
    struct Cell *next;
} tCell;
tCell *head;

void printSSL(tCell *head);
void reversePartOfASSL(tCell *head, int m, int n);
void freeSSL(tCell *head);

int main(){
    tCell *curr;
    tCell *last;

    head = (tCell *) malloc(sizeof (tCell));
    last = head;                               /* last and head points to the same address */
    head->data = 100;                          /* Initialize the value of that allocated address */
    head->next = NULL;                         /* 1st node in the linked list */

    for (int i = 0; i < 20; i++){
        curr = (tCell *) malloc (sizeof (tCell));   /* create a block in the memory to store a node */
        curr->data = last->data - 1;            /* modify the value of this latest allocated address */
	    curr->next = NULL;
	    last->next = curr;                      /* link the 2nd one with the 1st one */
	    last = curr;                            /* last point to the latest node */
    }

    printf("The original single linked list is: \n");
    printSSL(head);
    printf("The reversed single linked list is: \n");
    reversePartOfASSL(head, 11, 15);
    printSSL(head);

    freeSSL(head);
    return 0;
}

void reversePartOfASSL(tCell *head, int m, int n){
    int i;
    tCell * curr = head;
    tCell * next;

    for(i = 1; i < m; ++i ) curr = curr->next;
    tCell *beforemthNode =  curr;
    tCell *mthNode =  curr->next;

    curr = head;
    for(i = 1; i <= n; ++i ) curr = curr->next;
    tCell *nthNode =  curr;
    tCell *afternthNode = curr->next;

    beforemthNode->next = nthNode;

    tCell *prev = afternthNode; // reverse the SSL from here
    curr = mthNode;
    for(i = m; i <= n; ++i){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
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
