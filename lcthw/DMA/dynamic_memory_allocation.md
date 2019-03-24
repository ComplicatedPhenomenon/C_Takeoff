### Dynamical memory allocation

DMA allows your program to obtain memory space while running, or to release it if it's not required.

[usage](https://www.programiz.com/c-programming/c-dynamic-memory-allocation):   
* `malloc`  (int \*) malloc(sizeof(size_t ))  

   >The malloc() function reserves a block of memory of the specified number of bytes. And, it returns a pointer of type void which can be casted into pointer of any form. However, if the space is insufficient, allocation fails and returns a NULL pointer.
* `calloc`

   > The malloc() function allocates a single block of memory. Whereas, calloc() allocates multiple blocks of memory and initializes them to zero.
* `realloc`
* `free`

  > Dynamically allocated memory created with either calloc() or malloc() doesn't get freed on their own. You must explicitly use free() to release the space.

### [Why do we need to free memory?](http://www.cplusplus.com/forum/beginner/186031/)

Your stupid operation might introduce some behaviour you don't know for sure.
Even if the OS take care for you when the program close, for sure you still don't want the OS  to close your out-of-control program abruptly without a warning.

[Explanation on How do free and malloc work in C](https://stackoverflow.com/a/1957125)

### Example
* `./oop/callmethod.`
* `./lcthw/LinkedList/*`

### Problem unsolved
```sh
$ gcc test_array.c
test_array.c:112:1: error: unterminated function-like macro invocation
RUN_TESTS(all_tests);
^
./../minunit.h:18:5: note: expanded from macro 'RUN_TESTS'
    debug("------RUNNING: %s", argv[0];\
    ^
./../dbg.h:11:9: note: macro 'debug' defined here
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",\
        ^
test_array.c:112:22: error: expected '}'
RUN_TESTS(all_tests);
                     ^
test_array.c:112:1: note: to match this '{'
RUN_TESTS(all_tests);
^
./../minunit.h:16:57: note: expanded from macro 'RUN_TESTS'
#define RUN_TESTS(name) int main(int argc, char *argv[]){\
                                                        ^
2 errors generated.
```
