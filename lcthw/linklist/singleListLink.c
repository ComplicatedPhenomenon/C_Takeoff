#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int data;
    struct Cell* next; /* tCell *next will not work here */
} tCell;

int main(void) {
    int i;
    tCell *curr;                               // curr is a pointer point to a tCell type or another Node 
    tCell *first;
    tCell *last;

    /* Construct linked list, 100 down to 80. */
    first = (tCell *) malloc (sizeof (tCell));  // first points to the newly allocated memory.
    last = first;                               // last also points to it 
    first->data = 100;
    printf("%d\n",last->data);
    first->next = NULL;                         // The SSL now contains only 1 Node
    printf("%d\n",last->next != NULL);
    for (i = 0; i < 20; i++) {                  // We create an SSL contains 20 Nodes
	curr = malloc (sizeof (tCell));  
	curr->data = last->data - 1;
	curr->next = NULL;
	last->next = curr;
	last = curr;
    } 
    
    /* Walk the list, printing sequence numbers. */
    curr = first;
    while (curr != NULL) {
	printf ("Sequence = %d\n", curr->data);
	curr = curr->next;
    }

    while (curr != NULL) {
        free(curr);
	curr = curr->next;
    }
    
    return 0;
}

/***********************************************
 * self referential struct?
 * singly-linked list?
 * 
 * Clearly a struct cannot contain another cell as it becomes a never-ending recursion.
 * but it can contain a pointer refer to another struct
 *************************************************************/
