#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
  int data;
  struct Cell * next; /* tCell *next will not work here */
} tCell;

int main(void) {
  int i;
  tCell * curr;
  tCell * first;
  tCell * last;

  /* Construct linked list, 100 down to 80. */
  first = (tCell *) malloc (sizeof (tCell));
  last = first;                               /* last and first points to the same address */
  first->data = 100;                          /* modify the value of that allocated address */
  first->next = NULL;                         /* 1 node in the linked list */

  for (i = 0; i < 20; i++) {
    curr = (tCell *) malloc (sizeof (tCell));         /* create a block in the memory to store a node */
    curr->data = last->data - 1;            /* modify the value of this latest allocated address */
	  curr->next = NULL;
	  last->next = curr;                      /* link the 2nd one with the 1st one */
	  last = curr;                            /* last point to the latest node */
  }
  /* *
   * From the logical view, it becme easy to understand
   * Flowchart helps a lot. there objects you need to notice
   * The variable name, the contents and the address of the variable
   * first is a variable which has data type `pointer`,
   * which points to a variable has a data type `tCell`
   *            0 represents NULL
   *
   *  ______________________201______________ --- The address of the variable
   * |201|---|201|---|---|100 | 0 |---        --- The contents of the variable
   * |___|___|___|___|___|________|__________
   * first    last                            --- The name of variable
   *
   * curr = malloc (sizeof (tCell));...   curr->next = NULL;
   *  _____________________201__________223________________
   * |201|---|223|---|---|100 | 0 |---|99  | 0 |---|223|---
   * |___|___|___|___|___|________|___|________|___|___|____
   * first    last                                  curr
   *
   *  last->next = curr; last = curr;
   *  _____________________201__________223__________239________________
   * |201|---|239|---|---|100 |223|---|99  |239|---|98 | 0 |---|239|---
   * |___|___|___|___|___|________|___|________|___|_______|___|___|____
   * first    last                                              curr
   *
   * */

   curr = first;
  /* *
   * curr now point to the head node, first can never be modified.
	 * first can be interpreted as the name of the linked list at present time
   * */
   /**********************************************************************
    *
    *  _____________________201__________223__________239________________
    * |201|---|239|---|---|100 |223|---|99  |239|---|98 | 0 |---|201|---
    * |___|___|___|___|___|________|___|________|___|_______|___|___|____
    * first    last                                              curr
    *
    * *********************************************************************/
    while (curr != NULL) {
      printf ("Sequence = %d\n", curr->data);
      curr = curr->next;
    }

    /**
     * while(first->next != NULL){
     *	 printf ("%d\n",first->data);
     *	 first=first->next;
     * }
     *
     * Head is changed by it, the list has no head now!
     **/

    while( (curr=first) != NULL){
      first = first->next;
     /* clear the whole space for storing the SSL */
      free(curr);
    }


    return 0;
}
