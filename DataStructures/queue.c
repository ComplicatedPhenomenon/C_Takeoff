/**
 *   Modified Date: 11/08/2019
 *   Description:  C Program to implement a queue using two stacks
 **/
 
#include <stdio.h>
#include <stdlib.h>

struct stackNode {
	int data;
	struct stackNode * next;
};

void push(struct stackNode ** topRef, int new_data);
int pop(struct stackNode ** topRef);

/* structure of queue having two stacks */
struct queue {
	struct stackNode * stack1;
	struct stackNode * stack2;
};

void enQueue(struct queue * q, int x) {
	push(&q->stack1, x);
}

/* Function to deQueue an item from queue */
int deQueue(struct queue* q) {
	int x;
	if (q->stack1 == NULL && q->stack2 == NULL) {
		printf("Queue is empty \n");
		getchar();
		exit(0);
	}

	/* Move all elements from stack1 to stack 2 only if
	stack2 is empty */
	if (q->stack2 == NULL) {
		while (q->stack1 != NULL) {
			x = pop(&q->stack1);
			push(&q->stack2, x);
		}
	}

	x = pop(&q->stack2);
	return x;
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


int main() {
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;
	q->stack2 = NULL;
	int i = 1;
	for (; i <= 1; i++) enQueue(q, i);
	
	printf("now the queue order from head to tail is: ");
	struct stackNode *tem = q->stack1;
	while(tem!=NULL) {
		printf("%d ", tem->data);
		tem = tem->next;
	}
	printf("\n");

	for (i = 0; i <= 1; i++) printf("%d\n", deQueue(q));

	return 0;
}
