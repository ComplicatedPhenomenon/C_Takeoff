# About Printing pointers
```sh
format `%x` expects argument of type `unsigned int`, but argument 3 has type `char \*`
```

We use `* pointer_name` to serve the purpose of dereferencing a pointer

# Rules of Using Pointers
A string is composed of characters. A sentence is composed of strings. `char *strings[]`can be used to store sentences. so strings here is an array of pointers pointer pointing to a int 1D array.   

```c
int *ptr[NUM];
```
It declares **ptr** as an array of NUM integer pointers.( In other words. a series of pointers which point to integer data were stored in an array)

ptr is an array, also a pointer, its datatype is pointer, that means the object is address of another variables.
## Differentiate string storage
At the beginning, I was stubborn with
```c
char string = 'hello';
```
The compiler thrown an error to me,
```sh
initializing 'char' with an expression of type 'char [6]'
```
You can't assign a string to a char type.

How about below?
```c
char *string = "hello";
```
Will it work or not? Yes.

In the above line "hello" is stored in a shared read only location, but pointer "string" is stored in a read-write memory. You can change "string" to point something else but cannot change value at present "string". So this kind of string should only be used when we don’t want to modify string at a later stage in program.

### Right usage
```c
char str[4] = "GfG"; /*One extra for string terminator*/
/* OR */
char str[4] = {‘G’, ‘f’, ‘G’, '\0'}; /* '\0' is string terminator */
```
##### how do pointer to pointer works in C
Below is a part of memory(the number at the top is the address)
```c
 54   55   56   57   58   59   60   61   62   63   64   65   66   67   68   69
+---+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|   | 58 |    |    | 63 |    | 55 |    |    | h  | e  | l  | l  | o  | \0 |    |
+---+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
      cp              c        cpp
```
what you can see here, is that at address 63 the string "hello" starts. So in this case, if this is the only occurrence of "hello" in memory then,
```c
const  char *c = "hello";
```
defines `c` to be a pointer to the only string "hello", and thus contains the value 63
C must it self be stored some where. In the example above at location 58. Of course we can not only point to characters, but also to other pointers. E.g:
```c
const char **cp = &c;
```
Now `cp` point to `c`, that is , it contains the address of `c`(which is 58). We can go even further
```c
const *** cpp = &cp
```
Now `cpp`stores the address of `cp`, so it has value 55(based on the example above),and you guessed it, itself stored at address 60

#### Data types
Data types is used for declaring variable or functions of different types.
The type of a variable determines how much space it occupies in storage and how the bit pattern stored is interpreted.

The type of a function determines? (how much space the return value occupies in storage) and ?
#### Variable
A  variable is nothing but a name given to a storage area that our programs can manipulate.

# Pointer as function argument.
```c
int sum(int *, int *);
int main(){
    int a, b;
    a = 3;
    b = 4;
    sum{&a,&b}
}
```
It is `call by reference`. When executing main function, it pause at `b = 4`, and go to another stack frame to execute sum function, when done, this stack frame collapse.
