[Header Files](http://www.techcrashcourse.com/2015/06/c-programming-header-files.html)

Let say it in this way. If we use `sin()` without including `math,h`, what happened then?
```bash
wm@vampire:~/playground/C/macro$ gcc predifined_constants.c 
predifined_constants.c: In function ‘main’:
predifined_constants.c:14:14: warning: implicit declaration of function ‘sin’ [-Wimplicit-function-declaration]
  printf("%f",sin(3.14));
                ^
predifined_constants.c:14:14: warning: incompatible implicit declaration of built-in function ‘sin’
predifined_constants.c:14:14: note: include ‘<math.h>’ or provide a declaration of ‘sin’
```
If we, let's say, want to declare `float sin()` and define it just for fun(satisfy our ambition), ignoring the facts that it is a well defined problem and have been approached thousands of times and has a well defined solution. Then how we realize this idea?

You don't have to figure the value of `size_max` out yourself to write *portable code*, the standard header `stdlib` provides it.
