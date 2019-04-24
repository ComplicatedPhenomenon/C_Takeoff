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

```c
include <pthread.h>
int pthread_create(pthread_t *restrict tidp,
                   const pthread_attr_t *restrict attr,
                   void *(*start_rtn)(void),
                   void *restrict arg
);
```

C99 中新增加了 restrict 修饰的指针： 由 restrict修饰的指针是最初唯一对指针所指向的对象进行存取的方法，仅当第二个指针基于第一个时，才能对对象进行存取。对对象的存取都限定于基于由restrict 修饰的指针表达式中。 由 restrict 修饰的指针主要用于函数形参，或指向由 malloc()分配的内存空间。restrict 数据类型不改变程序的语义。 编译器能通过作出 restrict修饰的指针是存取对象的唯一方法的假设，更好地优化某些类型的例程。

第一个参数为指向线程标识符的指针。

第二个参数用来设置线程属性。

第三个参数是线程运行函数的起始地址。

最后一个参数是运行函数的参数。


需要注意的是一个线程仅允许唯一的一个线程使用 `pthread_join()`等待它的终止，并且被等待的线程应该处于可join状态，即非DETACHED状态。

在任何一个时间点上，线程是可结合的（joinable）或者是分离的（detached）。一个可结合的线程能够被其他线程收回其资源和杀死。在被其他线程回收之前，它的存储器资源（例如栈）是不释放的。相反，一个分离的线程是不能被其他线程回收或杀死的，它的存储器资源在它终止时由系统自动释放。


默认情况下，线程被创建成可结合的。为了避免存储器泄漏，每个可结合线程都应该要么被显示地回收，即调用pthread_join；要么通过调用pthread_detach函数被分离。
---
```c
int pthread_join(pthread_t thread, void **status);
```

`pthread_t` is the data type used to uniquely identify a thread.

`status` contains a pointer to the status argument passed by the ending thread as part of `pthread_exit()`. If the ending thread terminated with a return, status contains a pointer to the return value. If the thread was canceled, status can be set to -1.


有时候主线程创建子线程后，如果不使用pthread_join将自己阻塞，自己会先退出而程序结束，
```c
int pthread_join(pthread_t tid, void**thread_return);
```
What it returns:
若成功则返回0，若出错则为非零。

如果一个可结合线程结束运行但没有被join，则它的状态类似于进程中的Zombie Process，即还有一部分资源没有被回收，所以创建线程者应该调用pthread_join来等待线程运行结束，并可得到线程的退出代码，回收其资源。

由于调用pthread_join后，如果该线程没有运行结束，调用者会被阻塞，在有些情况下我们并不希望如此。例如，在Web服务器中当主线程为每个新来的连接请求创建一个子线程进行处理的时候，主线程并不希望因为调用pthread_join而阻塞（因为还要继续处理之后到来的连接请求），这时可以在子线程中加入代码

pthread_detach(pthread_self())
或者父线程调用
    pthread_detach(thread_id)（非阻塞，可立即返回）
这将该子线程的状态设置为分离的（detached），如此一来，该线程运行结束后会自动释放所有资源。

[](https://cloud.tencent.com/developer/article/1392916)
