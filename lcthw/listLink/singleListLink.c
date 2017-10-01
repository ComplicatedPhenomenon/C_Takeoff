#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int cellSeq;
    struct Cell* next; /* tCell *next will not work here */
} tCell;

int main(void) {
    int i;
    tCell *curr;
    tCell *first;
    tCell *last;

    /* Construct linked list, 100 down to 80. */
    first = malloc (sizeof (tCell));
    last = first;
    first->cellSeq = 100;
    first->next = NULL;
    for (i = 0; i < 20; i++) {
	curr = malloc (sizeof (tCell));
	curr->cellSeq = last->cellSeq - 1;
	curr->next = NULL;
	last->next = curr;
	last = curr;
    }
    
    /* Walk the list, printing sequence numbers. */
    curr = first;
    while (curr != NULL) {
	printf ("Sequence = %d\n", curr->cellSeq);
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
