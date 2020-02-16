/**
 * @file
 * 
 * Modified Date: 11/08/2019
 * Description:  C Program to implement a queue using two stacks
 **/
 
#include <stdio.h>
#include <stdlib.h>

/**
 * basic building block of stack
 */ 
struct stackNode {
	int data;
	struct stackNode * next;
};

void push(struct stackNode ** topRef, int new_data);
int pop(struct stackNode ** topRef);
void freeSLL(struct stackNode *head);

/**
 * structure of queue having two stacks 
 */
struct queue {
	struct stackNode * stack1;
	struct stackNode * stack2;
};

void enQueue(struct queue * q, int x) {
	while(q->stack2){
		push(&q -> stack1, pop(&q->stack2));
	}
	push(&q->stack1, x);
}

/**
 * Function to deQueue an item from queue 
 */
int deQueue(struct queue* q) {
	int x;
	if (q->stack1 == NULL && q->stack2 == NULL) {
		printf("Queue is empty \n");
		getchar();
		exit(0);
	}

	/* Move all elements from stack1 to stack 2 only if stack2 is empty*/
	if (q->stack2 == NULL) {
		while (q->stack1 != NULL) {
			x = pop(&q->stack1);
			push(&q->stack2, x);
		}
	}

	x = pop(&q->stack2);
	return x;
}

/**
 * Function to free a stack
 */
void freeQueue(struct queue *q){
	freeSLL(q->stack1);
	freeSLL(q->stack2);
	free(q);
}

int main() {
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;
	q->stack2 = NULL;

	int i;
	for (i = 1; i <= 5; i++) enQueue(q, i);
	
	printf("now the queue order from top to bottom is: ");
	struct stackNode *tem = q->stack1;
	while(tem!=NULL) {
		printf("%d ", tem->data);
		tem = tem->next;
	}
	printf("\n");

	for (i = 0; i <= 3; i++) printf("%d\n", deQueue(q));

	for (i = 1; i <= 5; i++) enQueue(q, i*i);
	printf("now the queue order from top to bottom is: ");
	tem = q->stack1;
	while(tem!=NULL) {
		printf("%d ", tem->data);
		tem = tem->next;
	}
	printf("\n");

	freeQueue(q);
	return 0;
}

void freeSLL(struct stackNode *head) {
    struct stackNode *curr;
    while( (curr=head) != NULL) {
        head = head -> next;
        free(curr);
    }
}

/* Function to push an item to stack*/
void push(struct stackNode** topRef, int new_data) {
	struct stackNode* newNode = (struct stackNode*)malloc(sizeof(struct stackNode));
	if (newNode == NULL) {
		printf("Stack overflow \n");
		getchar();
		exit(0);
	}
	newNode->data = new_data;
	newNode->next = (*topRef);
	(*topRef) = newNode;
}

int pop(struct stackNode** topRef) {
	int res;
	struct stackNode* top;

	if (*topRef == NULL) {
		printf("Stack underflow \n");
		getchar();
		exit(0);
	}
	else {
		top = *topRef;
		res = top->data;
		*topRef = top->next;
		free(top);   
		return res;
	}
}