> Pointers allow a way to write functions that can modify their arguments' values: the C way of implementing Pass by Reference.


# Object, name
Variable name, a pointer to a reference target

[pass by assignment vs pass by reference](https://stackoverflow.com/a/986145/7583919)
* Pros and cons for each approach.
* Proper occasion to use each approach.


> In compiled languages, a variable is a memory space that is able to capture the value of the type. In Python, a variable is a name (captured internally as a string) bound to the reference variable that holds the reference value to the target object. The name of the variable is the key in the internal dictionary, the value part of that dictionary item stores the reference value to the target.


> There are no variables in Python. The key to understanding parameter passing is to stop thinking about "variables". There are names and objects in Python and together they appear like variables, but it is useful to always distinguish the three.

* Python has names and objects.
* Assignment binds a name to an object.
* Passing an argument into a function also binds a name (the parameter name of the function) to an object.


# Size of pointers
The size of a pointer depends on many factors - including the CPU architecture, compiler, Operating System etc.






## Lessons learned
* Variable in C++

  In C++, a variable is a reserved part of memory which is equal to the standard memory amount required by its datatype. You can see the standard size of different datatypes here. C++ Data Types . To provide a contrast to this concept, Python uses a different implementation. In which variable is not a reserved memory space, but an identifier tied to a value stored in memory.

* NULL Pointers

  If you are not sure about which variable's address to assign to a pointer variable while declaration, it is recommended to assign a NULL value to your pointer variable.
  * `0x0 `is just 0 written in hexadecimal notation.
  * Shorthand `if(ptr)`

    `if(ptr)` means `if (ptr != 0)` or `if (ptr != NULL)`

* `%p, %s`

  `*ptr` to deference pointer `ptr`
  > `printf()` is a variadic function and must be passed arguments of the right types. The standard says  `%p` takes `void *`

* Undefined behavior is painful

  Local arrays are created on the stack, and have automatic storage duration -- you don't need to manually manage memory, but they get destroyed when the function they're in ends. They necessarily have a fixed size.

  Arrays created with operator new[] have dynamic storage duration and are stored on the heap (technically the "free store"). They can have any size, but you need to allocate and free them yourself since they're not part of the stack frame.
