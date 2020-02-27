# Linked list 

[C dynamic memory allocation](https://en.wikipedia.org/wiki/C_dynamic_memory_allocation)

```c
int *ptr;
ptr = malloc(10 * sizeof(*ptr));		/* without a cast */
ptr = (int *)malloc(10 * sizeof(*ptr));	/* with a cast */
```

The advantage and disadvantage of type cast.

* Under the C standard, the cast is redundant.
* Including the cast may allow a C program or function to compile as C++.

## Insert at a specific position
```c
tCell *temp2 = head; // compare with tCell *temp1 = (tCell *) malloc(sizeof(tCell));
for(int i = 0; i < n-2; i++) temp2 = temp2->next;
temp1->next = temp2->next;
temp2->next = temp1;
```
Explain the idea with words not visualization.

* Insert at 1st node:
* Insert at other nodes:
    Broke up the (n-1)th node.

## Allocation of stack
```c
typedef struct{
    int capacity;
    int size;
    int *elements;
}Stack;

Stack *createStack(int maxElements){
    Stack *S;
    S = (Stack *)malloc(sizeof(Stack));
    S->elements = (int *)malloc(sizeof(int)*maxElements);
    S->size = 0;
    S->capacity = maxElements;
    return S;
}
```

## [Single Linked List](http://btechsmartclass.com/DS/U1_T10.html)

### [self referential struct definition?](https://stackoverflow.com/a/588631)

```
typedef struct Cell {
  bool isParent;
  struct Cell* child;
} Cell;
```
Clearly a Cell cannot contain another Cell as it becomes a never-ending recursion.

> In C (as opposed to C++ where it may be possible, I haven't checked), you cannot reference the `typedef` that you're creating within the structure itself. You have to use the structure name, as in the following test program:

`singleListLink.c`


> Although it's probably a lot more complicated than this in the standard, you can think of it as the compiler knowing about struct Cell on the first line of the typedef but not knowing about tCell until the last line :-) That's how I remember that rule.


### Basic

What is a linked list? Or when do we need a linked list.

It about dynamic memory allocation. When we work with unknown number of data values, we use a linked list. It is a *linear data structure* that contains sequence of elements such that each element links to its next element in the sequence. Each element in a linked list is called as **Node**.

Every **Node** contains 2 field, **data** and **next**, the data field is used to actual value of that node and next field is used to store the address of the next node in the sequence. (So **next** is a pointer)

* In a single linked list, **the address of the first node** is always stored
in a reference node known as "front" (some times it is also known as *head*)
* Always next part(reference part) of the last node must be *NULL*.

### Operations on SLL

* Insertion
* Deletion
* Display
  1. Check whether list is **Empty** (head == NULL)
  2. If it is **Empty** then display `list is empty` and terminate the function
  3. If it is **Not Empty** then define a Node pointer `temp` and initialize with `head`.
  4. Keep displaying `temp->data` with an arrow until `temp` reached to the last node,
  5. Finally display `temp->data` with arrow pointing to `NULL`.

Before we implement actual operations, first we need to set up empty list.
* **Step1** Define a **Node** structure with 2 members **data** and **next**
* **Step2** Define a Node pointer `head` and set it to `NULL`
* **Step3** Implement the **main** method by displaying operations menu
and make suitable function calls in the main method to perform user selected
operations.
```C
struct Node
{
    int data;
    struct Node *next;
}*  head = NULL;
```

[singlelist.c](https://stackoverflow.com/a/588729/7583919)


### Memory Leak
Dynamic memory is allocated from heap. You allocate it using `malloc` ...

**Remember each block of memory that was allocated, must be freed again.**

## stack and heap
>As you can see, using malloc() to allocate memory on the heap and then using free() to deallocate it, is no big deal, but is a bit cumbersome.

Some programming has built in garbage collector, so all the cumbersome work will be removed accordingly.
