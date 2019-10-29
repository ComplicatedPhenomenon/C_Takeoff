/** 
    WorkToDo: Testify listNode *reverseASSL_2(listNode *head)
 **/
#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int data;
    struct Cell * next;
} listNode;
listNode *head;  // head is a global variable, it exists all the life time of main stack frame

void printSSL();
void reverseASSL_1();
//listNode *reverseASSL_2(listNode *head);
void freeSSL();

int main(){
    listNode * curr;
    listNode * last;

    head = (listNode *) malloc (sizeof(listNode));
    last = head;
    head -> data = 10;                          /* modify the value of that allocated address */
    head -> next = NULL;                         /* 1st node in the linked list */

    for (int i = 1; i < 6; i++) {
        curr = (listNode *) malloc (sizeof(listNode));   /* create a block in the memory to store a node */
        curr -> data = last -> data - 1;            /* modify the value of this latest allocated address */
	    curr -> next = NULL;
	    last -> next = curr;                      /* link the 2nd one with the 1st one */
	    last = curr;                            /* last point to the latest node */
    }

    printf("The original single linked list is: \n");
    printSSL();
    printf("The reversed single linked list is: \n");
    reverseASSL_1();
    printSSL();
    freeSSL();

    head = NULL;
    printf("The original single linked list is: \n");
    printSSL();
    printf("The reversed single linked list is: \n");
    reverseASSL_1();
    printSSL();

    freeSSL();

    return 0;
}

//implement in a non-recursive way
void reverseASSL_1(){
    listNode * tem = head;
    listNode * prev = NULL;
    listNode * nexttem; 
    // what if head is NULL? omitting the below LoC cause Segmentation fault
    if (tem == NULL || tem -> next == NULL) {}
    else{
        while(tem -> next != NULL){
            nexttem = tem -> next; 
            tem -> next = prev;
            prev = tem;
            tem = nexttem;
        }
        tem -> next = prev;
        head = tem;
    }
}
/**
    // recursive method
    listNode *reverseASSL_2(listNode *head){
        if (head == NULL || head  ->  next == NULL) {}
        else {
            listNode *newhead = reverseASSL_2(head -> next);
            head -> next -> next = head;
            head -> next = NULL;
            return newhead;
        }
    }
 **/

void printSSL(){
    listNode *curr;
    curr = head;
    while (curr != NULL) {
        printf ("Sequence = %d\n", curr -> data);
        curr = curr -> next;
    }
}


void freeSSL(){
    listNode *curr;
    while( (curr=head) != NULL){
        head = head -> next;
        free(curr);
    }
}
