## [What are the differences between a pointer variable and a reference variable in C++?](https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in)
### What is a reference?
An alias (an alternate name) for an object.

Look up [here](https://isocpp.org/wiki/faq/references) to explain usage of `swap` function in `variable_function_declaration.cxx`.
```c++
void swap(int &i, int &j){
    cout << "In scope of function swap, i= "<< i << ", j= " << j <<endl;
    int tem;
    tem = i;
    i = j;
    j = tem;
}
```

Here i and j are aliases for main’s x and y respectively. In other words, i is x — not a pointer to x, nor a copy of x, but x itself. Anything you do to i gets done to x, and vice versa. This includes taking the address of it. The values of &i and &x are identical.
### What is a pointer?
Above account for my confusion in `function/swap_two_number.c`.

```c
void swap(int *x, int *y)
{
    printf("In scope of function swap, x= %p, y = %p\n", x, y);
  	int temp;
    temp = *x; /* save the contents of var x in tem */
  	*x = *y;
  	*y = temp;

	return;
}
```

Here x and y are the pointer for main's x and y respectively, in other worlds, x and y store the address of main's x and y.
