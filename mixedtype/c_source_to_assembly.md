## Machine instructions
```sh
$ gcc -S ArrayofStruct.c #or $ cc -S ArrayofStruct.c -o -
```

```sh
$ cc -g ArrayofStruct.c -o ArrayofStruct
$ objdump -d ArrayofStruct | awk -v RS= '/^[[:xdigit:]].*main/'

```

Compiler with different flags can satisfy different needs
* Visualize c/c++ source code to assembly language.

Why down to assembly language? why deal with machine instructions?

Things process at that level I used to be unaware of.

If you ask me the difference between `array` and `pointer` in C/C++, I can't give you an enough clear explanation. Nevertheless, with the assist of converting the C/C++ source code to assembly language, the difference is supposed to show clearly theoretically.
