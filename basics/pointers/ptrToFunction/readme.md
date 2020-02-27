# PBR vs PBV

  ![](https://www.mathwarehouse.com/programming/images/pass-by-reference-vs-pass-by-value-animation.gif)

> Arguments are always passed to functions by value in C. In other words, when C passes control to a function, a copy of each argument is made and this copy is passed to the function - leaving the original variable unchanged.


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
## local variable vs static variable in memory


Variable `array` is declared on stack, and it will be automatically released when current block goes out of the scope.

* https://stackoverflow.com/a/34227681/7583919
* https://stackoverflow.com/a/11698458/7583919

```c
int *getArray(){
    static int array[20];
    //static int array[20];  //  address of stack memory associated with local variable
    int i;

    for (i=0; i < 10; ++i) array[i] = i;

    return array;
}
```

## Return Type
* The `return type` indicates what kind of data this function will return.  
* Some languages differentiate between `subroutines`, which do not return a value, and `functions`, which do.  In C there are no subroutines, only functions, but functions are not required to return a value.  The correct way to indicate that a function does not return a value is to use the return type `void`.  ( This is a way of explicitly saying that the function returns nothing.)
* If no return type is given, the compiler will normally assume the function returns an int.  This can cause problems if the function does not in fact return an int.

## Variable address is a virtual address
[Value of pointers in C](https://stackoverflow.com/questions/39142190/value-of-pointer-in-c), check `pointerValue.c` for detail.

> It means that its numerical value does not necessarily represent the sequential number of the byte in physical memory.

> This is something hidden from your program by a combination of the operating system and the hardware on which it is running, so there is no OS-independent way to obtain a mapping of a particular address to a physical address. Physical addresses are also meaningless outside the context of the OS virtual memory manager, because pages (allocation blocks) come in no particular order.


