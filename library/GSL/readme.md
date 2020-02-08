# how to get started with `gsl`?
https://www.gnu.org/software/gsl/doc/html/index.html

* temporary way
  ```sh
  $ echo $LD_LIBRARY_PATH #should not be null
  $ sudo find / -name libgsl.so.23
  $ sudo find / -name libgslcblas.so
  $ LD_LIBRARY_PATH=/usr/local/lib #store the dynamic library path to unix environment variable (printenv)
  $ LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/wm/Playground/tools/gsl/lib
  $ export LD_LIBRARY_PATH
  ```
* permanent way

  add below to `~/.bashrc`

  ```sh
  LD_LIBRARY_PATH=/usr/local/lib 
  LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/wm/Playground/tools/gsl/lib
  export LD_LIBRARY_PATH
  ```
# Apply gsl in a comprehensive way.

