## Implement OOP in C
If a is a pointer to a structure in which b is a member, then you access b with `(*a).b`. This is such a common  occurrence in C that a shorthand exists: `a->b`

In `call_method.c`
```c
who->name = strdup(name);
```
`who->name` must be a pointer according to the usage of `strdup`, turns out it does. `strdup` returns a pointer which at last must be passed to free to avoid a memory leak.

## About OOP
Don't overcomplicate things. Don't try to make everything an object.

>I've seen that feature (banana I needed) was wrapped into the class (Gorilla) and interface (entire jungle). I just needed a function...

> this is what distinguish fan from real professional who can implement complicated logic in a maximum simple way.

[Discussion on  You wanted a banana but what you got was a gorilla holding the banana and the entire jungle.](https://news.ycombinator.com/item?id=5205441)


If you really want to work in the way as `call_method.c`, then switch to Object oriented language like C++ or Java.
