/**
 * head is determined when after calling insert, what it refers to is defined as the variable
 * allocated on heap is hehaviour defined when insert exit.
 **/
#include <stdio.h>
#include <stdlib.h>

typedef struct Cell{
    int data;
    struct Cell *next;
} tCell;

tCell *head=NULL; /* head stores the address of the first Node */

void print(){
    int i;
    tCell *curr = head;
    i = 1;
    while (curr != NULL){
        printf ("Position: %d,  data: %d \n", i, curr->data);
        i += 1;
        curr = curr->next;
  }
}

void insert(int data, int n){
    printf("Before insertion, Head node is pointing to address %p\n", head);
    tCell *temp1 = (tCell *) malloc(sizeof(tCell)); //
    temp1->data = data;
    temp1->next = NULL;

    // Initialize a single linked list
    if(n == 1){
        temp1->next = head;
        head = temp1; // it makes sense head will never change when n == 1
        return;
    }

    // The logic in 4 lines of code below makes perfect sense.
    tCell *temp2 = head;
    for(int i = 0; i < n-2; i++) temp2 = temp2->next;
    temp1->next = temp2->next; 
    temp2->next = temp1;
    
    printf("After insertion, Head node is pointing to address %p\n", head);
}

void ReleaseMemory(){
    tCell * curr;
    while( ( curr = head ) != NULL){
        head = head->next;
        free(curr);
    }
}

int main(){
    //head = NULL;
    insert(2,1);
    /**
     *  temp1->next = head;
     *  _____________________201___________
     * |201|---|---|  2  |NULL|---|201 |
     * |___|___|___|_____|____|___|____|___
     * temp1                        head
     *  head = temp1;
     *  _____________________201__________________
     * |201|---|---|  2  |NULL|---|201 |---|201 |
     * |___|___|___|_____|____|___|____|___|____|__
     * temp1                        head    temp2
     * return
     **/
    print();
    printf("Head node is pointing to address %p\n", head);
    insert(3,2);
    print();
    printf("Head node is pointing to address %p\n", head);
    insert(4,1);
    printf("Head node is pointing to address %p\n", head);
    insert(5,2);
    printf("Head node is pointing to address %p\n", head);
    insert(23,4);
    printf("Head node is pointing to address %p\n", head);
    insert(224,6);
    printf("Head node is pointing to address %p\n", head);
    printf("done!\n");
    print();
    printf("\n");
    ReleaseMemory();
    return 0;
}
