Compiling for run-time linking with a dynamically linked `libctest.so.1.0`:
```
gcc -Wall -I/path/to/include-files -L/path/to/libraries prog.c -lctest -o prog
```          
The compiler is smart enough to know  what `-lmoo` is.
```
gcc -o foo foo.c -L. -lmoo
```
### Static Libraries: `.a`
How to generate a static library (object code archive file):
* Compile: `cc -Wall -c ctest1.c ctest2.c`
* Create library `libctest.a`: `ar -cvq libctest.a ctest1.o ctest2.o`
* List files in library: `ar -t libctest.a`
* Linking with the library:
  * `cc -o executable-name prog.c libctest.a`
  * `cc -o executable-name prog.c -L/path/to/library-directory -lctest`

```
cc -Wall -c ctest1.c ctest2.c
ar -cvq libtest.a ctest1.o ctest2.o
cc -o prog prog.c libtest.a
./prog
rm  prog *.o *.a
```


[Problems you might encounter with using static library ](http://blog.csdn.net/aiwoziji13/article/details/7330333)
```sh
undefined reference to
```
### Dynamically Linked "Shared Object" Libraries: `.so`
* Create object code
* Create library
* Optional: create default version using a symbolic link.

```
gcc -rdynamic -o progdl progdl.c -ldl
./progdl
rm  progdl
```
