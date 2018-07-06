Programming Principles and Practices Using CPP

* Fabulous display.
* Convey philosophy in a simple but powerful way. Everything is depict in detail.

Bjarne Stroustrup made a brief self introduction. 生动又丰富.


> A traditional set of exercises is designed to test your initiative, cleverness, or inventiveness. In contrast, a drill requires little invention from you. Typically, sequencing is crucial, and each individual step should be easy (or even trivial). Please don’t try to be clever and skip steps; on average that will slow you down or even confuse you.

> You might think you understand everything you read and everything your Mentor or instructor told you, but repetition and practice are necessary to develop programming skills. In this regard, programming is like athletics, music, dance, or any skill-based craft. Imagine people trying to compete in any of those fields without regular practice. You know how well they would perform. Constant practice — for professionals that means lifelong constant practice — is the only way to develop and maintain a high-level practical skill.

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
