`func_3.c`
```
#include <stdio.h>
int main()
{
    int n, i, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d",n);

    for(i=2; i<=n/2; ++i)
    {
        // condition for nonprime number
	if(n%i==0)					   
	{
	    flag=1;
	    break;
	}
    }
	if (flag==0)

            printf("%d is a prime number.\n",n);
	else
            printf("%d is not a prime numberi\n.",n);
    printf("%i\n",4%3);
    return 0;
}
```
So far what I used to do in a basic way

```
$ gcc func_3.c
```
And I get an warning
```
func_3.c: In function ‘main’:
func_3.c:6:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘int’ [-Wformat=]
     scanf("%d",n);
                ^
```
Also I totally know nothing about the error

```
Enter a positive integer: 4
Segmentation fault (core dumped)
```
Now, I add a `-g` option to enable built-in debugging support (which gdb needs)
```
$ gcc -g func_3.c  -o func_3
```
And I specify program `func_3` to debug.
```
GNU gdb (Ubuntu 7.11.1-0ubuntu1~16.5) 7.11.1
Copyright (C) ...
For help, type "help".
Type "apropos word" to search for commands related to "word".
(gdb) file func_3
Reading symbols from func_3...done.
(gdb) run
Starting program: /home/wm/playground/C/function/func_3
Enter a positive integer: 3

Program received signal SIGSEGV, Segmentation fault.
0x00007ffff7a6cde5 in _IO_vfscanf_internal (s=<optimized out>,
    format=<optimized out>, argptr=argptr@entry=0x7fffffffdba8,
        errp=errp@entry=0x0) at vfscanf.c:1902
	1902	vfscanf.c: No such file or directory.
	(gdb) Quit
```
