>  what's the use of pointers in c?

[*ref(1)*](https://www.quora.com/Why-do-we-need-pointers-in-a-C-program)

We usually use pointer as a reference to another variable. For such cases, we could argue that there is no need to expose the memory address and a programming without pointers will do fine with just references (like Java)

But pointers are not there only for referencing existing variables, they are there to support direct interactions with hardware. For example, if you want to read data from a device in your program, you need to instruct the device to write n bytes in address a. Because of that, you need a data type that can store addresses and an operator that returns the address of a variable.

* An array is a block of contiguous memory that has been allocated with a specific type. You can use pointers to navigate arrays
