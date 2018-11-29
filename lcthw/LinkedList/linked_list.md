[Single Linked List](http://btechsmartclass.com/DS/U1_T10.html)

[self referential struct definition?](https://stackoverflow.com/a/588631)

> Clearly a Cell cannot contain another Cell as it becomes a never-ending recursion.

> However a Cell can contain a pointer to another Cell
```
typedef struct Cell {
  bool isParent;
  struct Cell* child;
} Cell;
```


> In C (as opposed to C++ where it may be possible, I haven't checked), you cannot reference the `typedef` that you're creating within the structure itself. You have to use the structure name, as in the following test program:

`singleListLink.c`


> Although it's probably a lot more complicated than this in the standard, you can think of it as the compiler knowing about struct Cell on the first line of the typedef but not knowing about tCell until the last line :-) That's how I remember that rule.


#### Basic

What is a linked list? Or when do we need a linked list.

It about dynamic memory allocation. When we work with unknown number of data values, we use a linked list. It is a *linear data structure* that contains sequence of elements such that each element links to its next element in the sequence. Each element in a linked list is called as **Node**.

Every **Node** contains 2 field, **data** and **next**, the data field is used to actual value of that node and next field is used to store the address of the next node in the sequence. (So **next** is a pointer)

* In a single linked list, **the address of the first node** is always stored
in a reference node known as "front" (some times it is also known as *head*)
* Always next part(reference part) of the last node must be *NULL*.

#### Operations with SLL

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

### Data structure
Data Structures are the programmatic way of storing data so that data can be used efficiently. Almost every enterprise application uses various types of data structures in one or the other way.

[An overview of data structures and algorithm](https://www.tutorialspoint.com/data_structures_algorithms/)

Data structure include
* Linked List
* Stack & Heap
* Queues
* Tree Data structure
* Graph Data structure

To understand the list implementation. What variable sits what section of the memory. **What goes where?**
* Stack is used to store all the information about function call executions , to store all the local variables,
* Static/Globe store the global values that lives the entire lifetime of the program of that application.
* Code(Text) is to store all the instructions to be executed.

These three sections of the memory is decided at compile time.

* Heap is not fixed, we can request memory from heap during run time. And that's what we do when we use `malloc()` or new operator etc.
[linked list implementation in C/C++](https://m.youtube.com/watch?v=vcQIFT79_50)


### Priority queue
### Binary tree
### Hash table
### Sorting Algorithm
### Memory Leak
Dynamic memory is allocated from heap. You allocate it using `malloc` ...

**Remember each block of memory that was allocated, must be freed again.**
```c
#include<stdio.h>
#include<stdlib.h>

typedef struct nodestructure{
    int data;
    struct nodestructure * next;
} node;
node * head;
// Implementation of single linkde list.
node * insertSLL(node * head, int item){
    head = NULL;
    node * tail;
    if (head==NULL){
        head = (node *) malloc(sizeof(node));
        head->data = item;
        head->next = NULL;
        tail = head;
    }
    else{
        node * temp = (node *) malloc(sizeof(node));
        temp->data = item;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    return head;
}

void display(node * head){
    node * curr;
    curr = head;
    printf("%s", "Single Linked List:");
    while(curr != NULL)
    {
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");

}


void freeMemory(node * head){
    node * curr;
    while((curr=head) != NULL){
        head = head->next;
        free(curr);
    }
}


int main(){
    insertSLL(head, 2);
    if(!head){
        printf("Something is wrong, because head is still none after calling insertSLL\n");
    }
    /*insertSLL(head, 3);
    insertSLL(head, -3);
    insertSLL(head, 13);
    insertSLL(head, 31);*/
    display(head);
    freeMemory(head);
    return 0;
}

```
It's not working, head is NULL out side of `insertSLL`.
<br>
`inserttoSSL.c` has a similar situation as `pointers/ptrToBasicDataType/difference.c`

```sh
wm@vampire:$ gcc ImplementStackbySLL.c
wm@vampire:$ valgrind ./a.out
==7155== Memcheck, a memory error detector
==7155== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7155== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7155== Command: ./a.out
==7155==
Single Linked List:2  　
==7155== Use of uninitialised value of size 8
==7155==    at 0x108885: insertSLL (in /home/wm/Playground/GH/C_Takeoff/lcthw/LinkedList/a.out)
==7155==    by 0x1087DA: main (in /home/wm/Playground/GH/C_Takeoff/lcthw/LinkedList/a.out)
==7155==
Single Linked List:2  　3  　
==7155== Use of uninitialised value of size 8
==7155==    at 0x108885: insertSLL (in /home/wm/Playground/GH/C_Takeoff/lcthw/LinkedList/a.out)
==7155==    by 0x1087E4: main (in /home/wm/Playground/GH/C_Takeoff/lcthw/LinkedList/a.out)
==7155==
Single Linked List:2  　3  　-3  　
==7155== Use of uninitialised value of size 8
==7155==    at 0x108885: insertSLL (in /home/wm/Playground/GH/C_Takeoff/lcthw/LinkedList/a.out)
==7155==    by 0x1087EE: main (in /home/wm/Playground/GH/C_Takeoff/lcthw/LinkedList/a.out)
==7155==
Single Linked List:2  　3  　-3  　13  　
==7155== Use of uninitialised value of size 8
==7155==    at 0x108885: insertSLL (in /home/wm/Playground/GH/C_Takeoff/lcthw/LinkedList/a.out)
==7155==    by 0x1087F8: main (in /home/wm/Playground/GH/C_Takeoff/lcthw/LinkedList/a.out)
==7155==
Single Linked List:2  　3  　-3  　13  　31  　
==7155==
==7155== HEAP SUMMARY:
==7155==     in use at exit: 0 bytes in 0 blocks
==7155==   total heap usage: 6 allocs, 6 frees, 1,104 bytes allocated
==7155==
==7155== All heap blocks were freed -- no leaks are possible
==7155==
==7155== For counts of detected and suppressed errors, rerun with: -v
==7155== Use --track-origins=yes to see where uninitialised values come from
==7155== ERROR SUMMARY: 4 errors from 4 contexts (suppressed: 0 from 0)
```
