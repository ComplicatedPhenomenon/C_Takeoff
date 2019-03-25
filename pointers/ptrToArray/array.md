An Array is a collection of similar data type value in a single variable. An array is a derived data type in C, which is constructed from fundamental data type of C language.

* Array declaration
* Array initialization

## Something against intuition
```c
char x = "czfzdxx";
char name[] = {"Wall-E-1000000001","complicatephenomenon","czfzdxx"};

```
```sh
pointerToArray.c:7:10: warning: incompatible pointer to integer conversion initializing
      'char' with an expression of type 'char [8]' [-Wint-conversion]
    char x = "czfzdxx";
         ^   ~~~~~~~~~

pointerToArray.c:10:11: error: redefinition of 'name' with a different type: 'char *[]' vs
       'char [18]'
    char *name[] = {"Wall-E-1000000001","complicatephenomenon","czfzdxx"};

```
[Is array name a pointer?](https://stackoverflow.com/questions/1641957/is-an-array-name-a-pointer)


### Array decay into pointers

Crucial points:

* In general, `x[y]` is by definition equivalent to `*(x+y)`
* The name of the array is the address of the first element, right?
  ```c
  int v[10]
  int *a[5]
  a[0] = v
  ```
  `*a` in this case is the same is `a[0]`, which is the first element in your array(which is a pointer)

### Char array declaration and initialization in C
So far I have been initializing an array like
```c
char array_c[3] = {'s', 'o', 's'};
```
something like below is illegal,
```c
char array_c[3];
array_c = {'s','o','s'};
```
the first statement is not performing *initialization*, but *assignment*:

```sh    
char myarray[4] = "abc";  // Initialization.
myarray = "abc";          // Assignment.
```
And **arrays are not directly assignable in C**.

The name `myarray` actually resolves to the address of its first element (`&myarray[0]`), which is not a `value`, and as such cannot be the target of an assignment.

The `=` in `myarray = "abc";` is assignment (which won't work as the array is basically a kind of constant pointer), whereas in `char myarray[4] = "abc";`, it's an initialization of the array. There's no way for late initialization.

If you want to fill the `myarray` buffer manually, without strcpy(), you can use:
```sh
myarray[0] = 'a', myarray[1] = 'b', myarray[2] = 'c', myarray[3] = 0;
```
or
```sh
char *ptr = myarray;
*ptr++ = 'a', *ptr++ = 'b', *ptr++ = 'c', *ptr = 0;
```

`" "` is a string (`char *`) literal. You want `''` for a single char.

### [What is a printf formatter for bool](What is the printf format specifier for bool?)
