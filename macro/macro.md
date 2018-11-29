Differences between `header files` , `macros` and `preprocessor`?

* preprocessor

  Lines that start with `#` are \_preprocessing directives_.  They are directives that tell the preprocessor to do something.

  `#include`, `#if`, `#ifdef`, `#ifndef`, `#else`, `#elif`, `#endif`, `#define`, `#undef`, `#line`, `#error`, and `#pragma` are all preprocessing directives.  (A line containing only `#` is also a preprocessing directive, but it has no effect.)

  `#define blah 8` is a preprocessing directive, it is not a macro.  `blah` is a macro.  This `#define` preprocessing directive defines the macro named `blah` as an object-like macro replaced by the token `8`.

* [Header Files](https://gcc.gnu.org/onlinedocs/gcc-3.0.2/cpp_2.html)

  example:

  Let say it in this way. If we use `sin()` without including `<math.h>`, what happened then?
  ```bash
  gcc predifined_constants.c
  predifined_constants.c: In function ‘main’:
  predifined_constants.c:14:14: warning: implicit declaration of function ‘sin’ [-Wimplicit-function-declaration]
  printf("%f",sin(3.14));
                ^
  predifined_constants.c:14:14: warning: incompatible implicit declaration of built-in function ‘sin’
  predifined_constants.c:14:14: note: include ‘<math.h>’ or provide a declaration of ‘sin’
  ```
If we, let's say, want to declare `float sin()` and define it just for fun(satisfy our ambition), ignoring the facts that it is a well defined problem and have been approached thousands of times and has a well defined solution. Then how we realize this idea?

You don't have to figure the value of `size_max` out yourself to write *portable code*, the standard header `stdlib` provides it.

* [MACRO](https://gcc.gnu.org/onlinedocs/cpp/Macros.html).[1](https://www.quora.com/What-are-macros-in-C)

  * `object-like macros` (Several object-like macros are predefined; you use them without supplying their definitions. They fall into three classes: `standard`, `common`, and `system-specific`. )
  * `function-like macros` (Is it like a prototype?)
