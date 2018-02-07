How to use [GNU scientific library](https://github.com/ampl/gsl)?

[Documentation for GSL](https://www.gnu.org/software/gsl/doc/latex/gsl-ref.pdf)
You will come across problems through the way installing GSL by source.
```
Rather than executing `make install`
...
Making install in sys
make[1]: Entering directory '/home/wm/Softwares/gsl/sys'
make[2]: Entering directory '/home/wm/Softwares/gsl/sys'
make[2]: Nothing to be done for 'install-exec-am'.
 /bin/mkdir -p '/usr/local/include/gsl'
/bin/mkdir: cannot create directory ‘/usr/local/include/gsl’: Permission denied
...
```
Instead you should run `sudo make install`
```
Libraries have been installed in:
   /usr/local/lib

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the `-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the `LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the `LD_RUN_PATH' environment variable
     during linking
   - use the `-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to `/etc/ld.so.conf'

```
When I want first try with `gsl`, the difficulty I met is
```
./a.out: error while loading shared libraries: libgsl.so.23: cannot open shared object file: No such file or directory
```
Then I asked it on [StackOverflow](https://stackoverflow.com/q/45665878/7583919) in a rush when no one at least I knew had asked such question. I missed out for
looking up the official help documentation.
> To avoid this error, either modify the system daynamic linker configuration ordefine the shell variable `LD_LIBARY_PATH` to include the directory where the library is installed.

Again unnecessary information generated in the online world because of me.

**This should be prevented from happening as much as possible.**

Besides of adding more topics to improve the possibility of finding the right answer,
We can adjust the searching way to be more accurate to find out the right answer, that's a once for all method.


**[undefined reference to ](http://blog.csdn.net/aiwoziji13/article/details/7330333)
**
