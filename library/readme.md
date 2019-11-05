## [Implementation of C header files](https://stackoverflow.com/questions/5955309/implementation-of-c-header-files/5955370#5955370)


when `#include<stdio.h>` is included,  how `gcc` know the implementation of the function?

> Those are called function prototypes. They tell the compiler that the function exists, but not where (yet). The compiler uses this to make sure that you're calling the function correctly, but that's it.

> Once the compiler is done, the linker gets called. This is where the magic happens. The linker determines which library has the actual implementation of the function. In this case it's probably going to be in the standard library, which is automatically pulled in. The linker does its thing, and your calls to that function are handled by the library.

> On Linux system, library files are under `/usr/lib`.   


To get a better complete understanding, [visit here](http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html)

* Static Library.
* Dynamically Linked Shared Object Library.
* Library Path.
  In order for an executable to find the required libraries to link with during run time, one must configure the system so that the libraries can be found.
  * Specify the environment variable `LD_LIBRARY_PATH` to the directory paths containing the shared object library.
  * Add library directories to be included during dynamic linking to the file `/etc/ld.so.conf`.
* Library Versions.  

I used to write a command thousands of times without know the mechanism behind. It's a bad behavior, since it prevent me from knowing the foundation of how things work.


