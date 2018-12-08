[**Objected-Oriented Programming in C**](https://www.codementor.io/michaelsafyan/object-oriented-programming-in-c-du1081gw2)
<hr>

`->` in **C**
```c
struct foo
{
    int x;
    float y;
}

struct foo var;
struct foo *pvar;

var.x = 5;
(&var)->y = 1.3
pvar->y = 3.2 // It's just the dot version when you want to access elements of a struct/class that is a pointer instead of a reference.
(*pvar).x = 6
```
<hr>

> In C, you can't reference to the typedef that you're creating within the structure itself, You have to use the structure name, as in the following this program

```c
#include<stdio.h>
#include<stdlib.h>

typedef struct Cell
{
    int cellSeq;
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
    first->cellSeq = 100;
    first->next = NULL;
    for(i = 0; i < 20; i++){
        curr = malloc(sizeof(tCell));
	      curr->cellSeq = last->cellSeq-1;
	      curr-> next = NULL;
	      last->next = curr;
	      last = curr;
    }

    curr = first;
    while(curr != NULL){
	      printf("Sequence = %d\n",curr->cellSeq);
	      curr = curr->next;
    }

    return 0;
}
```
<hr>
[With C, you have to pass your "object" explicitly as the first parameter of the method, there is no automatism for OOP. And you only need to make it a member as function pointer when you want to implement virtual methods.](https://stackoverflow.com/questions/45230835/call-method-in-c-oop)
