> A process with two threads of execution, running on a single processor. Thread #1 is executed first, eventually starts Thread #2, and waits for a response. When Thread #2 finishes, it signals Thread #1 to resume execution to completion and then finishes.

In computer architecture, multithreading is the ability of a central processing unit (CPU) (or a single core in a multi-core processor) to execute multiple processes or threads concurrently, supported by the operating system


# Single-processor system
# 多线程



对于单核系统，不可能出现一个时刻运行多余一个线程（进程）的情况， 多个线程（进程）只能交替运行，一个在运行，其余在等待。

![](https://upload.wikimedia.org/wikipedia/commons/a/a5/Multithreaded_process.svg)


A process with two threads of execution, running on a single processor. From wikipedia on <a href =" https://en.wikipedia.org/wiki/Multithreading_(computer_architecture)">multithreading </a>

# 进程调度
CPU在进程之间的切换速率高到让用户以为多个进程在同时运行。


Scheduling Queue(调度队列)
Job Queue and Ready Queue
# Multiple-processor system