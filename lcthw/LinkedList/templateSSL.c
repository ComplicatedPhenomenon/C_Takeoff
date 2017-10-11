/*Insert node at the end of the linked list*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;  // In the logical view, link is a pointer contains the
} wm;                   // the address of mnext node.

wm * A;                 // A is the name of linked list 
int main(){
	                               
    A = NULL; // so far, the list is empty.
    // Insert a node to the linked list.
    wm * temp = (wm *)malloc(sizeof(wm)); 
    
    (*temp).data = 100; /* de-refernce temp means to modify the value at that particular address.*/
    (*temp).link = NULL; /* now we have 1 node in the linked list*/

    A = temp;

    wm * temp1 = (wm *)malloc(sizeof(wm)); 
    temp1->data = 109;
    temp1->link = NULL;

    temp->link = temp1;        
    /* A is never to be modified, or we will lose the address of the first node */
    temp1 = A;
    while(temp1 != NULL){                //Travel the linked list
	printf("%d\n", temp1->data);
	temp1 = temp1->link;
    }

    while( (temp1=A) != NULL){
        A = A->link;
	free(temp1);
    }



   return 0;

 } 
