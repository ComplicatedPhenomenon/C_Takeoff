### Dynamical memory allocation

DMA allows your program to obtain memory space while running, or to release it
if it's not required.
         usage    
`malloc`  (int \*) malloc(sizeof(size_t ))   
`calloc`
`realloc`
free


### [Why do we need to free memory?](http://www.cplusplus.com/forum/beginner/186031/)

Your stupid operation might introduce some behaviour you don't know for sure.
Even if the OS take care for you when the program close, for sure you still don't want the OS  to close your out-of-control program abruptly without a warning.

* > A principal problem with never freeing memory is running out of memory.
* > Associated with this is the problem of finding these memory leakage.(a "memory leak" is the term used to describe memory that you have lost the pointer to and thus cannot delete, even if you wanted to)

[Explanation](https://stackoverflow.com/a/1957125)

### Example
* `./oop/callmethod.`
* `./lcthw/LinkedList/*`
