Null pointers

When pointer is null

* Declare a pointer but didn't use.

* Declare and malloc but not initialize.

I think it's clear, the first situation.

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
