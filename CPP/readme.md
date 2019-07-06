* https://zhuanlan.zhihu.com/p/72282592
* [CPP framework](https://en.cppreference.com/w/)


The "places" in which we store data are called *objects*. To access an *object* we need a name. A named *object* is called a *variable* and has a specific type (such as `int` or `string` ) that determines what can be put into the object (e.g., 123 can go into an int and " Hello, World!\n " can go into a string ) and which operations can be applied (e.g., we can multiply `int` s using the * operator and compare strings using the `<=`
operator). The data items we put into variables are called values.

## Environment
* gcc v.s g++

   `g++` is equivalent to `gcc -xc++ -lstdc++ -shared-libgcc` (the 1st is a compiler option, the 2nd two are linker options). This can be checked by running both with the `-v` option (it displays the backend toolchain commands being run).

  `cout` is present in the C++ standard library, which would need explicit linking with `-lstdc++` when using `gcc`; `g++` links the standard library by default.

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

* [LLVM](https://en.wikipedia.org/wiki/LLVM), [C++ complier](https://en.wikipedia.org/wiki/List_of_compilers#C++_compilers)

## Remove confusions
*  [Difference between header file and library file in c++](https://stackoverflow.com/questions/924485/whats-the-difference-between-a-header-file-and-a-library)

  > It's the fundamental difference between "interface" and "implementation"; the interface (header) tells you how to call some functionality (without knowing how it works), while the implementation (library) is the actual functionality.

  Explain this down to the level within my ability. It makes sense to me better that c++ just omit `.h` when including the standard library header files.

* [What are the differences between a pointer variable and a reference variable in C++?](https://isocpp.org/wiki/faq/references )

  A reference is an alias (an alternate name) for an object.

    ```c++
    void swap(int &i, int &j);
    ```

    Here i and j are aliases for main’s x and y respectively. In other words, i is x — not a pointer to x, nor a copy of x, but x itself. Anything you do to i gets done to x, and vice versa. This includes taking the address of it. The values of &i and &x are identical.
    ```c
    void swap(int *i, int *j);
    ```
    Here i and j are the pointer for main's x and y respectively, in other words, i and j store the address of main's x and y.


* [vector vs array in c++](https://www.educba.com/c-plus-plus-vector-vs-array/)

  vectors consume more memory in exchange for the ability to handle storage and growing dynamically in size.
* [namespace vs class](https://stackoverflow.com/a/3188198/7583919)
* Explanation on specifier
  Specifier instances
  * `inline`
  * `const`
    * [C++ const specifier explanation](https://stackoverflow.com/questions/4064286/c-const-keyword-explanation)

      const member functions prevent modification of any class member - const nonmember functions cannot be used.
    * [Meaning of 'const' last in a function declaration of a class?](https://stackoverflow.com/questions/751681/meaning-of-const-last-in-a-function-declaration-of-a-class)

## Referee book

* *Mastering the C++17 STL*

  ~~Make full use of standard library components in C++17~~.
* *C++17 By Example*
* Professional CPP 4th Edition 2018 by Marc Gregoire
* Programming Principles and Practices Using CPP

  * Fabulous display.
  * Convey philosophy in a simple but powerful way. Everything is depict in detail.

## Warning from Bjarne Stroustrup
> A traditional set of exercises is designed to test your initiative, cleverness, or inventiveness. In contrast, a drill requires little invention from you. Typically, sequencing is crucial, and each individual step should be easy (or even trivial). Please don’t try to be clever and skip steps; on average that will slow you down or even confuse you.

> You might think you understand everything you read and everything your Mentor or instructor told you, but repetition and practice are necessary to develop programming skills. In this regard, programming is like athletics, music, dance, or any skill-based craft. Imagine people trying to compete in any of those fields without regular practice. You know how well they would perform. Constant practice — for professionals that means lifelong constant practice — is the only way to develop and maintain a high-level practical skill.
