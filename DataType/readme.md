You need to compile with the flag -lm or you will get the error
`(.text+0x43): undefined reference to 'pow'`

```c
gcc fib.c -lm -o fibo
```
