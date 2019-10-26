## The intention of inventing pointer and its usage
* [Why do we need pointers in C program?](https://www.quora.com/Why-do-we-need-pointers-in-a-C-program)
* [How do function pointers work in C work?](https://stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work)

We usually use pointer as a reference to another variable. For such cases, we could argue that there is no need to expose the memory address and a programming without pointers will do fine with just references (like Java)

But pointers are not there only for referencing existing variables, they are there to support direct interactions with hardware. For example, if you want to read data from a device in your program, you need to instruct the device to write n bytes in address a. Because of that, you need a data type that can store addresses and an operator that returns the address of a variable.

## Null pointers

When pointer is null

* Declare a pointer but didn't use.

* Declare and malloc but not initialize.

I think the first situation is straightforward.

Some of the most common use cases for NULL are
- To initialize a pointer variable when that pointer variable isn’t assigned any valid memory address yet.
  ```c
  int * pInt = NULL;
  ```
- To check for null pointer before accessing any pointer variable. By doing so, we can perform error handling in pointer related code e.g. dereference pointer variable only if it’s not NULL.
  ```c
  if(pInt != NULL) /*We could use if(pInt) as well*/
    { /*Some code*/}
  else
    { /*Some code*/}
  ```

- To pass a null pointer to a function argument when we don’t want to pass any valid memory address.
  ```c
  int fun(int *ptr)
  {
      /*Fun specific stuff is done with ptr here*/
      return 10;
  }
  fun(NULL);
  ```
[Differences between for loop and while loop in C](https://www.quora.com/Difference-between-while-loops-and-for-loops-in-c-programming-language)

## Reference and deference
* The dereference Operator `*` operates on an address (an unsigned integer !) and returns the value stored at that address

https://www.youtube.com/watch?v=LW8Rfh6TzGg
# Why use pointers?

https://stackoverflow.com/questions/162941/why-use-pointers

https://www.quora.com/What-is-the-pointer-in-Python-Does-a-pointer-exist-in-Python
