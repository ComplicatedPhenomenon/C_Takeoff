# Functional programming paradigm
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