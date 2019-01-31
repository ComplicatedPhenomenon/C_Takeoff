

```sh
$ gcc --help
...
  -C                      Include comments in preprocessed output
  -c                      Only run preprocess, compile, and assemble steps
  -std=<value>            Language standard to compile for
  -stdlib=<value>         C++ standard library to use
  -S                      Only run preprocess and compilation steps
  -o <file>               Write output to <file>
...
$ g++ --help > compiler.md
OVERVIEW: clang LLVM compiler

USAGE: clang [options] <inputs>

OPTIONS:
  -###                    Print (but do not run) the commands to run for this compilation
  -I <dir>                Add directory to include search path
  -L <dir>                Add directory to library search path

  -std=<value>            Language standard to compile for
  -stdlib=<value>         C++ standard library to use

  -v                      Show commands to run and use verbose output
```
## Compilers for c++17
