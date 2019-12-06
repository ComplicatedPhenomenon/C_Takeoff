> 学习并行计算不仅仅是学会使用 OpenMP，Cilk，TBB 等这些库的接口，更重要的是，应该怎么去写一个程序。计算机语言和编程工具是不断发展更迭的，而算法的核心思想总体来说是一致的，一脉相承的。即便未来的并行语言变成了OpenABCDEFG，TAA, TCC, TDD，只要算法的思想对了，你也一样会把并行程序写好。


[Multithreading](https://complicatedphenomenon.github.io/2019/04/21/Multithreading/).

From Modern Operating System:

> To make it possible to write *portable threaded programs*, IEEE has defined a standard for threads. The standard defines over 60 function calls, we here just describe a few of the major ones
to give an idea of how it works.

| Thread call             |Description |
|--                       |:--:            |
|pthread_t                | create a new thread|
|pthread_exit             | Terminate the calling thread|
|pthread_join             | wait for a specific thread to exit|
|pthread_yield            | Release the CPU to let another thread run|
|pthread_attr_init        | Create and initialize a thread's attribute structure|
|pthread_attr_destroy     | Remove a thread's attribute structure|

# `pthread_create(...)`
Passing Arguments to Threads (`hello_*.c`)
* The `pthread_create()` routine permits the programmer to pass **one argument** to the thread start routine. For cases where multiple arguments must be passed, this limitation is easily overcome by creating a structure which contains all of the arguments, and then passing a pointer to that structure in the `pthread_create()` routine.
* All arguments must be passed by reference and cast to `(void *)`.

protype function
```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg); //pthread_t is the data type used to uniquely identify a thread
```

An Concrete example

![](../../figures/pthread.svg)



**Questions:**
* How the code connected with hardware?
* What physically happens if you create a thread?
* What happens when a thread is created?
* How os Protect the current setup?

# `pthread_join(...)`

需要注意的是一个线程仅允许唯一的一个线程使用 `pthread_join()`等待它的终止，并且被等待的线程应该处于可join状态，即非DETACHED状态。

在任何一个时间点上，线程是可结合的（joinable）或者是分离的（detached）。一个可结合的线程能够被其他线程收回其资源和杀死。在被其他线程回收之前，它的存储器资源（例如栈）是不释放的。相反，一个分离的线程是不能被其他线程回收或杀死的，它的存储器资源在它终止时由系统自动释放。

默认情况下，线程被创建成可结合的。为了避免存储器泄漏，每个可结合线程都应该要么被显示地回收，即调用pthread_join；要么通过调用pthread_detach函数被分离。

```c
int pthread_join(pthread_t thread, void **status);
```


`status` contains a pointer to the status argument passed by the ending thread as part of `pthread_exit()`. If the ending thread terminated with a return, status contains a pointer to the return value. If the thread was canceled, status can be set to -1.


有时候主线程创建子线程后，如果不使用pthread_join将自己阻塞，自己会先退出而程序结束，
```c
int pthread_join(pthread_t tid, void**thread_return);
```
若成功则返回0，若出错则为非零。

如果一个可结合线程结束运行但没有被join，则它的状态类似于进程中的Zombie Process，即还有一部分资源没有被回收，所以创建线程者应该调用`pthread_join`来等待线程运行结束，并可得到线程的退出代码，回收其资源。

由于调用pthread_join后，如果该线程没有运行结束，调用者会被阻塞，在有些情况下我们并不希望如此。例如，在Web服务器中当主线程为每个新来的连接请求创建一个子线程进行处理的时候，主线程并不希望因为调用`pthread_join`而阻塞（因为还要继续处理之后到来的连接请求），这时可以在子线程中加入代码`pthread_detach(pthread_self())` 或者父线程调用 `pthread_detach(thread_id`)（非阻塞，可立即返回）
这将该子线程的状态设置为分离的（detached），如此一来，该线程运行结束后会自动释放所有资源。

[reference](https://cloud.tencent.com/developer/article/1392916)
