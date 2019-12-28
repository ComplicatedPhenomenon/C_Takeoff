/**
 *   Modified Date: 11/08/2019
 *   Description:
 **/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a stack
struct Stack {
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(unsigned capacity) {
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack) { 
	return stack->top == stack->capacity - 1; 
}

int isEmpty(struct Stack* stack) { 
	return stack->top == -1; 
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, int item) {
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
	printf("%d pushed to stack\n", item);
}

int pop(struct Stack* stack) {
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

void freeStack(struct Stack* stack) {
	free(stack -> array);
	free(stack);
}


int main() {
	struct Stack* stack = createStack(10);
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	printf("%d popped from stack\n", pop(stack));
	isFull(stack) != 0 ? printf("Stack is full!\n"): printf("Stack is not full!\n");

	freeStack(stack);
	return 0;
}
