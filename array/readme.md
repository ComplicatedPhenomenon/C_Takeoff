http://pages.tacc.utexas.edu/~eijkhout/istc/html/language.html

## Dynamic array declaration and initialization
Dynamically declared 2D arrays can be allocated in one of two ways. For a NxM 2D array:
* Allocate a single chunk of NxM heap space
* Allocate an array of arrays: allocate 1 array of N pointers to arrays, and allocate N M bucket array of values (on for each row). You could also allocate each column independently and have an array of column arrays.

  array is a pointer-to-pointer-to-int: at the first level, it points to a block of pointers, one for each row. That first-level pointer is the first one we allocate; it has nrows elements, with each element big enough to hold a pointer-to-int, or `int *`. If we successfully allocate it, we then fill in the pointers (all nrows of them) with a pointer (also obtained from malloc) to ncolumns number of ints, the storage for that row of the array. If this isn't quite making sense, a picture should make everything clear:

  ![](http://c-faq.com/~scs/cclass/int/fig23.1.gifm)


  [ Dynamically Allocating Multidimensional Arrays](http://c-faq.com/~scs/cclass/int/sx9b.html)

The C library function void `*calloc(size_t nitems, size_t size)` allocates the requested memory and returns a pointer to it. The difference in `malloc` and `calloc` is that` malloc` does not set the memory to zero where as calloc sets allocated memory to zero.

* [How to implement Set data structure](https://stackoverflow.com/q/2630738/7583919)


The C library function void `*realloc(void *ptr, size_t size)` attempts to resize the memory block pointed to by ptr that
was previously allocated with a call to malloc or calloc.


```c
int* test = (int*) malloc(20 * sizeof(int));
printf("Size: %d\n", sizeof(test)); //8
```
The C language will only keep track of buffer sizes for statically allocated buffers (stack arrays) because the size of the array is available at compile time.


## Static array initialization
[Array initialization](https://stackoverflow.com/a/2589751/7583919)

```c
char ZEROARRAY[1024] = {0};
// Alternatively
memset(ZEROARRAY, 0, 1024);
```

The C library function void `*memset(void *str, int c, size_t n)` copies the character c (an unsigned char) to the first
n characters of the string pointed to, by the argument str.

## Generate a random list without duplicated elements
* `noDuplicatedRandomNumber.c`. very likely generating  repeated number
* `effcientNonDuplicateRandomNumberGenerator.c` generate a unique number at each time.

[How to return multiple values from a function in C](https://stackoverflow.com/questions/2620146/how-do-i-return-multiple-values-from-a-function-in-c)

## Heap allocation
* `x.c`
* `y.c`
