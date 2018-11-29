/*Memory leak definitely lost: 16 bytes in 1 blocks*/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
/*
 * Stack has three properties:
 * capacity stands for the maximum number of elements stack can hold.
 * Size stands for the current size of the stack
 * elements is the array of elements
 */
typedef struct Stack
{
    int capacity;
    int size;
    int *elements;
}Stack;
/*
 * crate Stack function takes argument the maximum number of elements the stack * can hold, creates a stack according to it and returns a pointer to the
 * stack.
 */
Stack *createStack(int maxElements)
{
    Stack *S;
    S = (Stack *)malloc(sizeof(Stack));
    S->elements = (int *)malloc(sizeof(int)*maxElements);
    S->size = 0;
    S->capacity = maxElements;
    return S;
}

void pop(Stack *S)
{
    if(S->size==0){
    printf("Stack is Empty\n");
    return;
    }
    else{
        S->size--;
    }
    return;
}

int top(Stack *S)
{
    if(S->size==0){
    printf("Stack is Empty\n");
    exit(0);
    }

    return S->elements[S->size-1];
}

void push(Stack *S,int element)
{
    if(S->size == S->capacity){
    printf("Stack is Full\n");
    }
    else{
    S->elements[S->size++] = element; //Implement stack using array.
  }
  return;
}

int main()
{
    Stack *S = createStack(5);
    push(S,7);
    push(S,5);
    push(S,21);
    push(S,-1);
    printf("Top element is %d\n",top(S));
    pop(S);
    printf("Top element is %d\n",top(S));
    pop(S);
    printf("Top element is %d\n",top(S));
    pop(S);
    printf("Top element is %d\n",top(S));

    assert(S != NULL);
    free(S->elements);
    free(S);
    return 0;
}
