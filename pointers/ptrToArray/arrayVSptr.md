#### Array decay into pointers
Crucial points:

* In general, `x[y]` is by definition equivalent to `*(x+y)`
* The name of the array is the address of the first element, right?
```c
int v[10]
int *a[5]
a[0] = v
```
`*a` in this case is the same is `a[0]`, which is the first element in your array(which is a pointer)



