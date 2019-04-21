Explanations on `demo.c`.

Multi-threading Model.

Specific situation analysis.

Thread execution, how cpu execute the code snippet for each thread?

How the code connected with hardware?

What physically happens if you create a thread?

What happens when a thread is created?

Each thread has its own set of register values,

Protect the scene.


```c
pthread_t pt;
int rc1, rc2, t1, t2;
t1 = 0;
t2 = 1;
rc1 = pthread_create(&pt, NULL, func(), (void*)&t1);
rc2 = pthread_create(&pt, NULL, func(), (void*)&t2);
```
The `pthread_create` function creates a new thread (with a unique ID) and stores the ID of the new thread in the `pthread_t` passed as the first argument. That argument is an _out_ parameter, meaning the value of the `pthread_t` that you pass in is not used, a new value is stored to it for you to use after the call finishes.

What you're doing is creating two threads with different IDs, but you are overwriting the variable that holds the first ID when the second thread is created.

That means you only _know_ one of the thread IDs, but there are still two different IDs.

If you don't know the ID of the first thread (because you overwrite the variable that stored the ID) then you can't join it, or detach it, or send it a signal.

---
```c
int pthread_join(pthread_t thread, void **status);
```

`pthread_t` is the data type used to uniquely identify a thread.

`status` contains a pointer to the status argument passed by the ending thread as part of `pthread_exit()`. If the ending thread terminated with a return, status contains a pointer to the return value. If the thread was canceled, status can be set to -1.
