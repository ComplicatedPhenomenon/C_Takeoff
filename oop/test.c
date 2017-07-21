#include<stdio.h>
#include<stdlib.h>

typedef struct Cell
{
    int tCellSeq;
    struct Cell *next; /*tCell will not work here*/
} tCell;

int main(void)
{
    int i;
    tCell *curr;
    tCell *first;
    tCell *last;

    /* Construct liked list*/

    first = malloc(sizeof( tCell));
    last = first;
    first->tCellSeq = 100;
    first->next = NULL;
    for(i = 0; i < 20; i++)
    {
        curr = malloc(sizeof(tCell));
	curr->tCellSeq = last->tCellSeq-1;
	curr-> next = NULL;
	last->next = curr;
	last = curr;
    }

    curr = first;
    while(curr != NULL){
	printf("Sequence = %d\n",curr->tCellSeq);
	curr = curr->next;
    }
    
    return 0;
}
