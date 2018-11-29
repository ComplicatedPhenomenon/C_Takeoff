## Call by reference
```c
/**
   ________   ________   ________
   | 102  |   |  102 |   | 103  |
     temp         x         y

     ________   ________   ________
     | 102  |   |  103 |   | 103  |
       temp         x         y

       ________   ________   ________
       | 102  |   |  103 |   | 102  |
         temp         x         y

**/

void swap(int * x, int * y){
    int * temp;
    temp = x;
    x = y;
    y = temp;

    return ;
}
```
Function `swap` above doesn't work.
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

# Function pointer
```C
#include<stdio.h>

int addInt(int a, int b)
{
    return a+b;
}

int main()
{
    int (*funcPtr)(int, int);
    funcPtr = &addInt;
    int sum = (*funcPtr)(2,3);
    int result = addInt(2,3);    
    return 0;
}
```

The place in which we store data are called `objects`. To access an `object` we need a name. A named `object` is called a `variable` and has a specific type (such as `int` or `string` ) that determines what can be put into the object.

`addInt `is a function. `funcPtr` is a pointer, pointing to function `addInt`.

Maybe we only care where is a piece of memory and what's in there. Its name, variable, is something represents that piece of memory. when we print this variable, we know what this piece of memory contains.

A pointer variable represents a piece of memory containing the address of another piece of memory. Now, say about data type, we see the pointer got a type, it means the memory which the pointer refers to containing that data type of data.
