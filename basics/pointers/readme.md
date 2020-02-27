# Data types
Data types is used for declaring variable or functions of different types.
```c
int i;
```
The type of a variable determines how much space it occupies in storage and how the bit pattern stored is interpreted.

## Pointers
Usage
* 向OS申请一块内存，然后用指针处理这块内存，这块内存存储字符串等基本数据类型和结构体。
* 获取函数的地址用于动态调用。
* 通过指针向函数传递大块内存，这样可以不必把全部数据传递过去。
...等等。

### The intention of inventing pointer and its usage
* [Why do we need pointers in C program?](https://www.quora.com/Why-do-we-need-pointers-in-a-C-program)
* [How do function pointers work in C work?](https://stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work)

* https://stackoverflow.com/questions/162941/why-use-pointers
* https://www.quora.com/What-is-the-pointer-in-Python-Does-a-pointer-exist-in-Python



### Pointer as reference to another variable
通常我们说的指针变量是指向一个整型、字符型或数组等变量.

We usually use pointer as a reference to another variable. For such cases, we could argue that there is no need to expose the memory address and a programming without pointers will do fine with just references (like Java)

```c
int * functionPtr(int,int);
```

```c
int sum(int *, int *);
int main(){
    int a, b;
    a = 3;
    b = 4;
    sum（&a,&b）
}
```
It is `call by reference`. When executing main function, it pause at `b = 4`, and go to another stack frame to execute sum function, when done, this stack frame collapse.

#### `NULL` pointers

When a pointer is `NULL`

* Declare a pointer but didn't use.
* Declare and malloc but not initialize.

Some of the most common use cases for `NULL` are
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

- To pass a `NULL` pointer to a function argument when we don’t want to pass any valid memory address.
  ```c
  int fun(int *ptr) {
      /*Fun specific stuff is done with ptr here*/
      return 10;
  }
  fun(NULL);
  ```

### Pointer to refer to function

而函数指针是指向函数,  函数指针可以像一般函数一样，用于调用函数、传递参数。
But pointers are not there only for referencing existing variables, they are there to support direct interactions with hardware. For example, if you want to read data from a device in your program, you need to instruct the device to write n bytes in address a. Because of that, you need a data type that can store addresses and an operator that returns the address of a variable.


```C
#include<stdio.h>

int addInt(int a, int b) {
    return a+b;
}

int main() {
    int (*funcPtr)(int, int);
    funcPtr = &addInt;
    int sum = (*funcPtr)(2,3);
    int result = addInt(2,3);    
    return 0;
}
```

`addInt `is a function. `funcPtr` is a pointer, pointing to function `addInt`.


## Reference and deference
* The dereference Operator `*` operates on an address (an unsigned integer !) and returns the value stored at that address

https://www.youtube.com/watch?v=LW8Rfh6TzGg



### Figure out storage of string
```c
char *string = "hello";
```
Will it work or not? Yes.

In the above line `hello` is stored in a shared read only location, but pointer `string` is stored in a read-write memory. You can change `string` to point something else but cannot change value at present `string`. So this kind of `string` should only be used when we don’t want to modify `string` at a later stage in program.

```c
int *ptr[NUM];
```
It declares **ptr** as an array of NUM integer pointers.( In other words. a series of pointers which point to integer data were stored in an array)

`ptr` is an array, also a pointer, its datatype is pointer, that means the object is address of another variables.

## Array vs Pointer
```c
char str[4] = "GfG"; /*One extra for string terminator*/
/* OR */
char str[4] = {‘G’, ‘f’, ‘G’, '\0'}; /* '\0' is string terminator */
char *ptrToString = str;
```

`sizeof(str)` won't equal to `sizeof(ptrToString)`.
Besides, you can do pointer arithmatic.

## How do pointer to pointer works in C
Below is a part of memory(the number at the top is the address)
```c
 54   55   56   57   58   59   60   61   62   63   64   65   66   67   68   69
+---+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|   | 58 |    |    | 63 |    | 55 |    |    | h  | e  | l  | l  | o  | \0 |    |
+---+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
      cp              c        cpp
```
what you can see here, is that at address 63 the string "hello" starts. So in this case, if this is the only occurrence of "hello" in memory then,
```c
const  char *c = "hello";
```
defines `c` to be a pointer to the only string "hello", and thus contains the value 63
C must it self be stored some where. In the example above at location 58. Of course we can not only point to characters, but also to other pointers. E.g:
```c
const char **cp = &c;
```
Now `cp` point to `c`, that is , it contains the address of `c`(which is 58). We can go even further
```c
const *** cpp = &cp
```
Now `cpp`stores the address of `cp`, so it has value 55(based on the example above),and you guessed it, itself stored at address 60
