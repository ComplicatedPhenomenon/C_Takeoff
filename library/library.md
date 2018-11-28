[Implementation of C header files](https://stackoverflow.com/questions/5955309/implementation-of-c-header-files/5955370#5955370)


I can only see the header file such as `stdio.h` is included, I don't know how `gcc` know the implementation of the function.

> Those are called function prototypes. They tell the compiler that the function exists, but not where (yet). The compiler uses this to make sure that you're calling the function correctly, but that's it.

> Once the compiler is done, the linker gets called. This is where the magic happens. The linker determines which library has the actual implementation of the function. In this case it's probably going to be in the standard library, which is automatically pulled in. The linker does its thing, and your calls to that function are handled by the library.

On Linux system, library files are under `/usr/lib`.   

---
[To get a better complete understanding](http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html)

* Static Library.
* Dynamically Linked Shared Object Library.
* Library Path.
  In order for an executable to find the required libraries to link with during run time, one must configure the system so that the libraries can be found.
  * Specify the environment variable `LD_LIBRARY_PATH` to the directory paths containing the shared object library.
  * Add library directories to be included during dynamic linking to the file `/etc/ld.so.conf`.
* Library Versions.  

I am growing used to write a command thousands of times without know the principles behind. It's a bad behaviour, since it prevent me from improving my ability to work on something.

[wget manual](https://www.gnu.org/software/wget/manual/wget.html)

* wget
  * `foo.tar.gz`.

    If you would like to see the files being extracted during unpacking, add v:
    ```
    tar xzvf file.tar.gz
    ```
    * ./configure
    * make
    * sudo make install

    Install Lapack

    * Install from software center
      ```
      sudo apt install liblapack-dev
      gcc -llapack dgels.c dgels.c:2:9: fatal error: lapacke.h: No such file or directory
      #include<lapacke.h>
            ^~~~~~~~~~~
      compilation terminated.
      dpkg -L liblapack-dev/.
      /usr
      /usr/lib
      /usr/lib/x86_64-linux-gnu
      /usr/lib/x86_64-linux-gnu/lapack
      /usr/lib/x86_64-linux-gnu/lapack/liblapack.a
      /usr/lib/x86_64-linux-gnu/pkgconfig
      /usr/lib/x86_64-linux-gnu/pkgconfig/lapack-netlib.pc
      /usr/share
      /usr/share/doc
      /usr/share/doc/liblapack-dev
      /usr/share/doc/liblapack-dev/copyright
      /usr/lib/x86_64-linux-gnu/lapack/liblapack.so
      /usr/share/doc/liblapack-dev/changelog.Debian.gz
      ```
    * Install from source
    * Install from a binary packages

      [Hints but I didn't have a clue](https://gcc.gnu.org/testing/testing-lapack.html)

The solution to solve
  * `lapacke.h: No such file or directory`
    ```
    sudo apt-get install liblapacke-dev
    ```
    (note the extra e!).

    gcc -llapack lapack_example.c

    ```
    dpkg -L liblapacke-dev
    /.
    /usr
    /usr/include
    /usr/include/lapacke.h
    /usr/include/lapacke_config.h
    /usr/include/lapacke_mangling.h
    /usr/include/lapacke_utils.h
    /usr/lib
    /usr/lib/x86_64-linux-gnu
    /usr/lib/x86_64-linux-gnu/liblapacke.a      /usr/share
    /usr/share/doc
    /usr/share/doc/liblapacke-dev
    /usr/share/doc/liblapacke-dev/copyright
    /usr/lib/x86_64-linux-gnu/liblapacke.so
    /usr/share/doc/liblapacke-dev/changelog.Debian.gz   
    ```

* `dgels.c:(.text+0x201): undefined reference to LAPACKE_dgels`
