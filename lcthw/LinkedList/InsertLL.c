#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int data;
    struct Cell* next;
} tCell;

tCell *head;

void print(){
    tCell *curr = head;
    while (curr != NULL) {
	printf ("%d ", curr->data);
	curr = curr->next;
    }
}

void insert(int data, int n){
    tCell *temp1 = (tCell *) malloc(sizeof(tCell)); // 
    temp1->data = data;
    temp1->next = NULL;
    if(n = 1){
	temp1->next = head;
	head = temp1;
	return;
    }

    tCell *temp2 = head;
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
