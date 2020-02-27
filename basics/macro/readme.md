# Macro

Differences between `header files`, `macros` and `preprocessor`?

* preprocessor

  Lines that start with `#` are \_preprocessing directives, which tell the preprocessor to do something.

  `#include`, `#if`, `#ifdef`, `#ifndef`, `#else`, `#elif`, `#endif`, `#define`, `#undef`, `#line`, `#error`, `#pragma`. 

* [Header Files](https://gcc.gnu.org/onlinedocs/gcc-3.0.2/cpp_2.html)

  example:

  Let say it in this way. If we use `sin()` without including `<math.h>` in [predifined_constants.c](predifined_constants.c), what happened when we run `gcc predifined_constants.c`?
  ```bash
  
  If we, let's say, want to define our own function `float sin()` just for fun(to satisfy our curiosity), ignoring the facts that it is a well defined problem and have been approached thousands of times and has a well defined solution. Then how we realize this idea?

* [MACRO](https://gcc.gnu.org/onlinedocs/cpp/Macros.html).[1](https://www.quora.com/What-are-macros-in-C)

  macros is created with the `#define` directive.

  By convention, macro names are written in uppercase. Programs are easier to read when it is possible to tell at a glance which names are macros.

  * `object-like macros` 
  * `function-like macros` 

## why there is `inline` function?
> `inline` instructs the compiler to attempt to embed the function content into the calling code instead of executing an actual call.

> For small functions that are called frequently that can make a big performance difference.


> Most likely you will get a bigger file, since the code to be inlined will appear multiple times throughout the program instead of just once.

> A bigger file doesn't really mean too much, particularly in the age of terabyte disks. 

I guess it is because execute an actual function call means create switch between stack frame, which means time and resources cost,

When the program executes the function call instruction:
* the CPU stores the memory address of the instruction following the function call
* copies the arguments of the function on the stack and finally transfers control to the specified function. 
* The CPU then executes the function code, stores the function return value in a predefined memory location/register and returns control to the calling function.

For functions that are large and/or perform complex tasks, the overhead of the function call is usually insignificant compared to the amount of time the function takes to run. However, for small, commonly-used functions, the time needed to make the function call is often a lot more than the time needed to actually execute the function’s code. 

## Where there is `static` function?
A static function in C is a function that has a scope that is limited to its object file. This means that the static function is only visible in its object file. 

in C++. In C, a static function is not visible outside of its translation unit, which is the object file it is compiled into. In other words, making a function static limits its scope.