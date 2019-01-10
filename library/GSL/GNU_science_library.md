# Install GNU scientific library by source.
1. `./configure`
  `./configure' to configure the package for your system.

  Running `configure' might take a while.  While running, it prints some messages telling which features it is checking for.

2. `make`

   Compile the package
3. `$ sudo make install`

  ```sh

  Libraries have been installed in:
     /usr/local/lib

  If you ever happen to want to link against installed libraries
  in a given directory, LIBDIR, you must either use libtool, and
  specify the full pathname of the library, or use the -LLIBDIR
  flag during linking and do at least one of the following:
     - add LIBDIR to the LD_LIBRARY_PATH environment variable
       during execution
     - add LIBDIR to the LD_RUN_PATH environment variable
       during linking
     - use the -Wl,-rpath -Wl,LIBDIR linker flag
     - have your system administrator add LIBDIR to /etc/ld.so.conf

  ```

# Usage of `gsl`
When I tried with `gsl`, the difficulty I met was
```
./a.out: error while loading shared libraries: libgsl.so.23: cannot open shared object file: No such file or directory
```
Then I asked it on [StackOverflow](https://stackoverflow.com/q/45665878/7583919) in a rush when no one at least I knew had asked such question. I missed out for
looking up the official help documentation.
> To avoid this error, either modify the system dynamic linker configuration or define the shell variable `LD_LIBARY_PATH` to include the directory where the library is installed.

Again unnecessary information generated in the online world because of me.


## Reference
* [GNU scientific library](https://github.com/ampl/gsl)
* [Documentation for GSL](https://www.gnu.org/software/gsl/doc/latex/gsl-ref.pdf)
