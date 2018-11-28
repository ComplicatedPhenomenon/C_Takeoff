>  what's the use of pointers in c?

[ref(1)](https://www.quora.com/Why-do-we-need-pointers-in-a-C-program)

We usually use pointer as a reference to another variable. For such cases, we could argue that there is no need to expose the memory address and a programming without pointers will do fine with just references (like Java)

But pointers are not there only for referencing existing variables, they are there to support direct interactions with hardware. For example, if you want to read data from a device in your program, you need to instruct the device to write n bytes in address a. Because of that, you need a data type that can store addresses and an operator that returns the address of a variable.
```c
DataType * pointer;
printf("%p \n", *pointer);

```
* An array is a block of contiguous memory that has been allocated with a specific type. You can use pointers to navigate arrays

<br>
[A simple example](https://stackoverflow.com/a/20374957/7583919)
Lets say you have these declarations:
```c
int i;
int *p = &i;
```
It would look something like this in memory:

```
+---+     +---+
| p | --> | i |
+---+     +---+
```

If you then use `&p` you get a pointer to `p`, so you have this:

```
+----+     +---+     +---+
| &p | --> | p | --> | i |
+----+     +---+     +---+
```

So the value of `p` is the address of `i`, and the value of `&p` is the address of `p`. That's why you get different values.
