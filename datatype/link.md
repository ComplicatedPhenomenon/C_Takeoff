You need to compile with the flag -lm, like this:
```c
gcc fib.c -lm -o fibo
```
This will tell gcc to link your code against the math lib. Just be sure to put the flag after the objects you want to link.

