#### About Printing pointers
 format `%x` expects argument of type `unsigned int`, but argument 3 has type `char \*`

 To refer, C11 standard, chapter §7.21.6.1

>  o,u,x,X  
The unsigned int argument is converted to unsigned octal (o), unsigned decimal (u), or unsigned hexadecimal notation (x or X) in the style dddd; [...]

Supplying invalid argument invokes undefined behavior.

You should be using `%p` to print the address

> p The argument shall be a pointer to void.[...]

and cast the argument to `void *`, because for pointer types no default argument promotion takes place.

Having said that,

1. main() should be int main(void), at least, to conform to the standard.
2. You need to forward declare your function bo() because implicit declarations are bad and non-standard now.

#### Rules of Using Pointers
A string is composed of characters

A sentence is composed of strings. `char *strings[]`can be used to store sentences. so strings here is a 1D array and a pointer   

A paragraph is composed of sentences

As 1D array can only store strings, then how to store asentence to an array?

A  string could be stored in 1D dimension array

```c
int *ptr[NUM]
```
It declares **ptr** as an array of NUM integer pointers.( In other words. a series of pointers which point to integer data were stored in an array)

##### how do pointer to pointer work in C
Below is a part of memory(the number at the top is the address)
```c
 54   55   56   57   58   59   60   61   62   63   64   65   66   67   68   69 
+---+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|   | 58 |    |    | 63 |    | 55 |    |    | h  | e  | l  | l  | o  | \0 |    |
+---+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
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
