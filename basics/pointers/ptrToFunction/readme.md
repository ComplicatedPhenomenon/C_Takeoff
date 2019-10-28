# PBR vs PBV

  ![](https://www.mathwarehouse.com/programming/images/pass-by-reference-vs-pass-by-value-animation.gif)

> Arguments are always passed to functions by value in C. In other words, when C passes control to a function, a copy of each argument is made and this copy is passed to the function - leaving the original variable unchanged.

# local variable vs static variable in memory


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

函数指针
