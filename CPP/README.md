Programming Principles and Practices Using CPP

* Fabulous display.
* Convey philosophy in a simple but powerful way. Everything is depict in detail.

Bjarne Stroustrup made a brief self introduction. 生动又丰富.

## Environment
gcc v.s g++

According to GCC's online documentation link options and how `g++` is invoked, `g++` is equivalent to `gcc -xc++ -lstdc++ -shared-libgcc` (the 1st is a compiler option, the 2nd two are linker options). This can be checked by running both with the `-v` option (it displays the backend toolchain commands being run).

```
$ gcc xx.cpp
undefined reference to `std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string()'
...
```
`cout` is present in the C++ standard library, which would need explicit linking with `-lstdc++` when using `gcc`; `g++` links the standard library by default.

The “places” in which we store data are called *objects*. To access an *object* we need a name. A named *object* is called a *variable* and has a specific type (such as `int` or `string` ) that determines what can be put into the object (e.g., 123 can go into an int and " Hello, World!\n " can go into a string ) and which operations can be applied (e.g., we can multiply `int` s using the * operator and compare strings using the `<=`
operator). The data items we put into variables are called values.
