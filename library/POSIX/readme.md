[Multithreading](https://complicatedphenomenon.github.io/2019/04/21/Multithreading/).

I can understand `pointer`, so can I understand `pthread`.

From Modern Operating System:

To make it possible to write *portable threaded programs*, IEEE has defined a standard for threads. The standard defines over 60 function calls, we here just describe a few of the major ones
to give an idea of how it works.

| Thread call             |Description |
|--                       |:--:            |
|pthread_t                | create a new thread|
|pthread_exit             | Terminate the calling thread|
|pthread_join             | wait for a specific thread to exit|
|pthread_yield            | Release the CPU to let another thread run|
|pthread_attr_init        | Create and initialize a thread's attribute structure|
|pthread_attr_destroy     | Remove a thread's attribute structure|


Passing Arguments to Threads (`hello_*.c`)
* The `pthread_create()` routine permits the programmer to pass one argument to the thread start routine. For cases where multiple arguments must be passed, this limitation is easily overcome by creating a structure which contains all of the arguments, and then passing a pointer to that structure in the pthread_create() routine.
* All arguments must be passed by reference and cast to (void *).
