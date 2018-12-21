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

## About OOP
Don't overcomplicate things. Don't try to make everything an object.

>I've seen that feature (banana I needed) was wrapped into the class (Gorilla) and interface (entire jungle). I just needed a function...

> this is what distinguish fan from real professional who can implement complicated logic in a maximum simple way.

[Discussion on  You wanted a banana but what you got was a gorilla holding the banana and the entire jungle.](https://news.ycombinator.com/item?id=5205441)
