# [Data structure](https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/)

Data Structures are the programmatic way of storing data so that data can be used efficiently. Almost every enterprise application uses various types of data structures in one or the other way.

[An overview of data structures and algorithm](https://www.tutorialspoint.com/data_structures_algorithms/)

Data structure include
* Linked list
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



[Pointers and dynamic memory - stack vs heap](https://www.youtube.com/watch?v=_8-ht2AKyH4)
* stack data structure has relation with stack.
* heap data structure is irrelevant with heap. heap is a large pool of free memory.

## Undefined behavior is painful

  Local arrays are created on the stack, and have automatic storage duration -- you don't need to manually manage memory, but they get destroyed when the function they're in ends. They necessarily have a fixed size.

  Arrays created with operator new[] have dynamic storage duration and are stored on the heap (technically the "free store"). They can have any size, but you need to allocate and free them yourself since they're not part of the stack frame.

# Reference
* [mycodeschool](https://www.youtube.com/channel/UClEEsT7DkdVO_fkrBw0OTrA)

