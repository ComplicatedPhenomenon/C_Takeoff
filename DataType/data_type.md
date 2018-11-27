You need to compile with the flag -lm or you will get the error
`(.text+0x43): undefined reference to 'pow'`

```c
gcc fib.c -lm -o fibo
```  
Reference
[C Programming Boot Camp](https://www.gribblelab.org/CBootCamp/)


# Print Formatter
`"%f"` is the (or at least one) correct format for a double. There is no format for a `float`, because if you attempt to pass a `float` to `printf`, it'll be promoted to double before printf receives it1. `"%lf"` is also acceptable under the current standard -- the `l` is specified as having no effect if followed by the f conversion specifier (among others).

Note that this is one place that `printf` format strings differ substantially from `scanf` (and `fscanf`, etc.) format strings. For output, you're passing a value, which will be promoted from float to `double` when passed as a variadic parameter. For input you're passing a pointer, which is not promoted, so you have to tell `scanf` whether you want to read a `float` or a `double`, so for `scanf`, `%f` means you want to read a float and `%lf` means you want to read a `double` (and, for what it's worth, for a long double, you use `%Lf` for either printf or scanf).

# Data Type
* Basic Data Types
  * integer types

| Type |Storage size|Value range|
|-------|
|char|1byte|-128 to 12 or 0 to 255|
|unsigned char| 1byte| 0 to 255|
|signed char| 1byte| -128 to 127|
|int |2 or 4 bytes| -32,678 to 32,767 or  -2,147,483,648 to 2,147,483,647|
|short|2byte|...|
|unsigned short| 2 byte| ...|
|long|4byte|...|
|unsigned long|4 byte}|  ...|

  * floating-point types

| Type |Storage size|Value range|
|-------|
|float|4byte |  |
|long |8byte | |
|long double|10 byte| | |
* Enumerated Types
* The Type Void
* Derived Data Type
  * Pointer types
  * Array types
  * Structure types
  * Union types
  * Function types

Data type correspond to a data structure, we use data type for specific purpose, but user don't know and don't to know how it's implemented, what the data structure is? for example we have been using `int`, `float`, `char` data types only with the knowledge with values that can take and operations that can be performed on them without any idea of how these types are implemented.

# Abstract Data Types
Abstract Data type (ADT) is a type (or class) for objects whose behavior is defined by a set of value and a set of operations.

The definition of ADT only mentions what operations are to be performed but not how these operations will be implemented. It does not specify how data will be organized in memory and what algorithms will be used for implementing the operations. It is called “abstract” because it gives an implementation independent view. The process of providing only the essentials and hiding the details is known as abstraction.

So a user only needs to know what a data type can do but not how it will do it. We can think of ADT as a black box which hides the inner structure and design of the data type. Now we’ll define three ADTs namely `List ADT`, `Stack ADT`, `Queue ADT`.
