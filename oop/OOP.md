[strdup usage](https://stackoverflow.com/a/252802/7583919)

In `call_method.c`
```c
who->name = strdup(name);
```
`who->name` must be a pointer according to the usage of `strdup`, turns out it does. `strdup` returns a pointer which at last must be passed to free to avoid a memory leak.

Something is wrong with
```c
printf("joe->name : %c\n",*(joe->name));
```
Go back to review the pointer to string.
