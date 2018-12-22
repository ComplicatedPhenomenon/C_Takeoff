## CPP entities
The entities of a C++ program are `values`, `objects`, `references`, `structured bindings` (since C++17), `functions`, `enumerators`, `types`, `class members`, `templates`, `template specializations`, `namespaces`, and `parameter packs`. `Preprocessor macros` are not C++ entities.

## [Difference between header file and library file in c++](https://stackoverflow.com/questions/924485/whats-the-difference-between-a-header-file-and-a-library)

> It's the fundamental difference between "interface" and "implementation"; the interface (header) tells you how to call some functionality (without knowing how it works), while the implementation (library) is the actual functionality.

Explain this down to the level within my ability. It makes me better, that c++ just omit `.h` when including the standard library header files.

standard library header file

```c++
g++ -stdlib=<value> <input file>
```

```cpp
#include<array>
#include 'xx.h'
```
Header files include declaration, instead of implementation.

### [What does '#include<iostream\>'  do?](https://stackoverflow.com/questions/22645097/what-does-include-iostream-do)

---

Try it, try to tell me your understanding.

It knows what to do with `std::cout`, it makes sure preprocessor knows it too. If cam't be a header file, since the implementation part should also be included during running time.

A program contains
* `a.h`
* `a.cpp`
* `c.cpp`

in `c.cpp`
```cpp
#include 'a.h'
#include 'xx.h'
```
---
> That is a C++ standard library header file for input output streams. It includes functionality to read and write from streams. You only need to include it if you wish to use streams.

### Where are c++ the standard library on Mac.

## Programming Principles and Practices Using CPP

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

## Complier
```sh
$ g++ -v
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include/c++/4.2.1
Apple LLVM version 10.0.0 (clang-1000.11.45.5)
Target: x86_64-apple-darwin18.2.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
$ gcc -v
$ clang -v
Apple LLVM version 10.0.0 (clang-1000.11.45.5)
Target: x86_64-apple-darwin18.2.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
$ c++ -v
$ cc --version
```

* [LLVM](https://en.wikipedia.org/wiki/LLVM)
* [C++ complier](https://en.wikipedia.org/wiki/List_of_compilers#C++_compilers)
## Template in CPP

## [CPP reference](https://en.cppreference.com/w/)
* Language
  - Basic concepts
  - C++ Keywords
  - Preprocessor
  - Expressions
  - Declaration
  - Initialization
  - Functions
  - Statements
  - Classes
  - Templates
  - Exceptions
Library for different area
* Language support library
* String library
* Numeric library
  - Common math functions
  - Special math functions (C++17)
  - Numeric algorithms
  - Pseudo-random number generation
  - Floating-point environment (C++11)
* Container library
* Ranges library (C++20)

* Algorithms library
* Input/output library
  - Stream-based I/O
  - Synchronized output (C++20)
  - I/O manipulators
* Localizations library
  - Regular expressions library (C++11)
  - basic_regex  −  algorithms
  - Atomic operations library (C++11)
  - atomic  −  atomic_flag
* Thread support library (C++11)
* Filesystem library (C++17)

## Referee book

* *Mastering the C++17 STL*

  ~~Make full use of standard library components in C++17~~.
* *C++17 By Example*
