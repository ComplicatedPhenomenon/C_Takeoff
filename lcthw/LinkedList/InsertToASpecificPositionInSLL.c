#include <stdio.h>
#include <stdlib.h>

typedef struct Cell{
  int data;
  struct Cell* next;
} tCell;

tCell *head; /* head stores the address of the first Node */

void print(){
  tCell *curr = head;
  while (curr != NULL){
    printf ("%d ", curr->data);
    curr = curr->next;
  }
}

void insert(int data, int n){
  tCell *temp1 = (tCell *) malloc(sizeof(tCell)); //
  temp1->data = data;
  temp1->next = NULL;
  /**
   *  ________________201______________ --- The address of the variable
   * |201|---|---|data |NULL|---        --- The contents of the variable
   * |___|___|___|_____|____|__________
   * temp1                              --- The name of variable
   * */

  if(n == 1){
    temp1->next = head;
    head = temp1;
    return;
  }
  tCell *temp2 = head;

  /**
   *  temp1->next = head;
   *  _____________________201___________
   * |201|---|---|data |NULL|---|NULL|
   * |___|___|___|_____|____|___|____|___
   * temp1                        head
   *  head = temp1;
   *  ________________201________________
   * |NULL|---|---|data |NULL|---|201 |
   * |____|___|___|_____|____|___|____|___
   * temp1                        head
   *
   *   tCell *temp2 = head;
   *  __________________201______________________
   * |NULL|---|---|data1|NULL|---|201 |---|201 |
   * |____|___|___|_____|____|___|____|___|____|__
   * temp1                        head     temp2
   * */


  for(int i = 0; i < n-2; i++){
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}

int main(){
  head = NULL;
  insert(2,1);
  insert(3,2);
  insert(4,1);
  insert(5,2);
  insert(23,4);
  insert(224,6);
  print();
  printf("\n");
}
