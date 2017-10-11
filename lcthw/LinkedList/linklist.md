###[Single Linked List](http://btechsmartclass.com/DS/U1_T10.html)

#### Basic

What is a linked list? Or when do we need a linked list.

It about dynamic memory allocation. When we work with unknown number of data
values, we use a linked list. It is a *linear data structure* that contains
sequence of elements such that each element links to its next element in the
sequence. Each element in a linked list is called as **Node**.

Every **Node** contains 2 field, **data** and **next**, the data field is 
used to actual value of that node and next field is used to store the
address of the next node in the sequence. (So **next** is a pointer)

* In a single linked list, the address of the first node is always stored
in a reference node known as "front"(some times it is also known as *head*)
* Always next part(reference part) of the last node must be *NULL*.

#### Operations with SLL

* Insertion
* Deletion
* Display
    * 1. Check whether list is **Empty** (head == NULL)
    * 2. If it is **Empty** then display `list is empty` and terminate the function
    * 3. If it is **Not Empty** then define a Node pointer `temp` and initialize with `head`.
    * 4. Keep displaying `temp->data` with an arrow until `temp` reached to the last node,
    * 5. Finally display `temp->data` with arrow pointing to `NULL`.

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
To understand the list implementation. What variable sits what section of the memory. **What goes where?**
* Stack is used to store all the information about function call executions , to store all the local variables,
* Static/Globe store the global values that lives the entire lifetime of the program of that application.
* Code(Text) is to store all the instructions to be executed.

These three sections of the memory is decided at compile time.

* Heap is not fixed, we can request memory from heap during run time. And that's what we do when we use `malloc()` or new operator etc.
[linked list implementation in C/C++](https://m.youtube.com/watch?v=vcQIFT79_50)
