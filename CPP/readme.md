* [CPP framework](https://en.cppreference.com/w/)

## Choose a compiler
* gcc v.s g++

   `g++` is equivalent to `gcc -xc++ -lstdc++ -shared-libgcc` (the 1st is a compiler option, the 2nd two are linker options). This can be checked by running both with the `-v` option (it displays the backend toolchain commands being run).

  `cout` is present in the C++ standard library, which would need explicit linking with `-lstdc++` when using `gcc`; `g++` links the standard library by default.

  ```sh
  $ g++ -v
  $ gcc -v
  $ clang -v
  $ c++ -v
  $ cc --version
  ```

* [LLVM](https://en.wikipedia.org/wiki/LLVM), [C++ complier](https://en.wikipedia.org/wiki/List_of_compilers#C++_compilers)

## Remove confusions
*  [Difference between header file and library file in c++](https://stackoverflow.com/questions/924485/whats-the-difference-between-a-header-file-and-a-library)

    > It's the fundamental difference between "interface" and "implementation"; the interface (header) tells you how to call some functionality (without knowing how it works), while the implementation (library) is the actual functionality.

    Explain this down to the level within my ability. It makes sense to me better that c++ just omit `.h` when including the standard library header files.



## Referee book

* *Mastering the C++17 STL*

  ~~Make full use of standard library components in C++17~~.
* *C++17 By Example*
* Professional CPP 4th Edition 2018 by Marc Gregoire
* Programming Principles and Practices Using CPP

  * Fabulous display.
  * Convey philosophy in a simple but powerful way. Everything is depict in detail.

## Warning from `Bjarne Stroustrup`
> A traditional set of exercises is designed to test your initiative, cleverness, or inventiveness. In contrast, a drill requires little invention from you. Typically, sequencing is crucial, and each individual step should be easy (or even trivial). Please don’t try to be clever and skip steps; on average that will slow you down or even confuse you.

> You might think you understand everything you read and everything your Mentor or instructor told you, but repetition and practice are necessary to develop programming skills. In this regard, programming is like athletics, music, dance, or any skill-based craft. Imagine people trying to compete in any of those fields without regular practice. You know how well they would perform. Constant practice — for professionals that means lifelong constant practice — is the only way to develop and maintain a high-level practical skill.

