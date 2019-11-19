## Functional programming paradigm
There are several [programming paradigm](https://en.wikipedia.org/wiki/Programming_paradigm), including
* Declarative programming
    * Functional programming (Mathematica)
* Imperative programming (contrast: Declarative)
* Procedure programming (Fortran. c)
* Object-oriented programming
* Generic programming
*  ...

Some programming language support multiple paradigm.

<span style="color:red">
Which does C belong to then?
</span>

C follows the procedural paradigm.

> C functions are not first-class objects. You cannot return a function from a function, store a function in a variable, or pass a function to another function. You cannot nest functions, and you cannot create anonymous functions. The workaround is that C does allow you to use pointers to functions, so you can write a function that takes a pointer to a function as an argument, but this is not as clean as what you can do in a language oriented towards functional programming.


<span style="color:red">
Is it wise to use C for functional programming?
</span>

Even it can be used as a functional paradigm programming language, it doesn't make too much sense, and drag you into tricky situation.

### Proof with sample code
In order to make the above statement clear, the sample program is simple enough but not too simple and include complete features of my problem.
* `pointers/pointerToArray/array.c`

   Return function from a function.


   ```c
   
   ```
* `pointers/ptrToFunction/fun_ptr_arg.c`

   Pass function to another function.

   ```c
   void foo(void (*a)()){
       a();
   }
   ```

*  `call_by_reference_1.c`

  Store a function in a variable.

  ```c
  int (* ptr[4]) (int x, int y);
  ```

[A good explanation on CBV & CBR](http://www.mathcs.emory.edu/~cheung/Courses/561/Syllabus/3-C/param-passing.html)
* In the pass-by-value method, the value of the actual parameter is copied into the (formal) parameter variable (when the parameter variable is created)

  ![](http://www.mathcs.emory.edu/~cheung/Courses/561/Syllabus/3-C/FIGS/low-level.gif)
* In the pass-by-reference method, the address of the actual parameter is copied into the (formal) parameter variable (when the parameter variable is created)

  Check `swap_two_value.c` for detail.

  ![](http://www.mathcs.emory.edu/~cheung/Courses/561/Syllabus/3-C/FIGS/low-level2.gif)



```c

...
int main(void){
    int x = 3, y = 4;
    swap(&x, &y, sizeof(int));
    ...
}
void Swap (void * x, void * y, size_t bytes){
    void * tmp = malloc(bytes);
    memcpy(tmp, x, bytes);
    memcpy(x, y, bytes);
    memcpy(y, tmp, bytes);
    free(tmp);
}

```

### Return Type
* The `return type` indicates what kind of data this function will return.  
* Some languages differentiate between `subroutines`, which do not return a value, and `functions`, which do.  In C there are no subroutines, only functions, but functions are not required to return a value.  The correct way to indicate that a function does not return a value is to use the return type `void`.  ( This is a way of explicitly saying that the function returns nothing.)
* If no return type is given, the compiler will normally assume the function returns an int.  This can cause problems if the function does not in fact return an int.

## Variable address is a virtual address
[Value of pointers in C](https://stackoverflow.com/questions/39142190/value-of-pointer-in-c), check `pointerValue.c` for detail.

> It means that its numerical value does not necessarily represent the sequential number of the byte in physical memory.

> This is something hidden from your program by a combination of the operating system and the hardware on which it is running, so there is no OS-independent way to obtain a mapping of a particular address to a physical address. Physical addresses are also meaningless outside the context of the OS virtual memory manager, because pages (allocation blocks) come in no particular order.
