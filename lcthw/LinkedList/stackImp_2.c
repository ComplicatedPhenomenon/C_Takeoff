#include<stdio.h>
#define STACK_MAX 100
struct Stack {
    int     data[STACK_MAX];
    int     size;
};
typedef struct Stack Stack;


void Stack_Init(Stack *S)
{
    S->size = 0;
}

int Stack_Top(Stack *S)
{
    if (S->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    }

    return S->data[S->size-1];
}

// construct a data type which implement stack with an array and track the size of the stack.
void Stack_Push(Stack *S, int d)
{
    if (S->size < STACK_MAX)
        S->data[S->size++] = d;
    else
        fprintf(stderr, "Error: stack full\n");
}

void Stack_Pop(Stack *S)
{
    if (S->size == 0)
        fprintf(stderr, "Error: stack empty\n");
    else
        S->size--;
}

int main()
{
    /*
     * I demonstrate the usage of these functions automatically instead of
     * interact with the user through input.
     */
     Stack *S;
     int data;

     Stack_Init(S);
     for(data < 0; data < STACK_MAX; data++)
     {
         Stack_Push(S, data);
     }
     printf("%d\n",Stack_Top(S));

     return 0;
}
