### Char array declaralization and initialization in C
It's because your first code snippet is not performing *initialization*, but *assignment*:
```sh    
char myarray[4] = "abc";  // Initialization.

myarray = "abc";          // Assignment.
```
And arrays are not directly assignable in C.

The name `myarray` actually resolves to the address of its first element (`&myarray[0]`), which is not a `value`, and as such cannot be the target of an assignment.

The "=" in `myarray = "abc"`; is assignment (which won't work as the array is basically a kind of constant pointer), whereas in `char myarray[4] = "abc"`; it's an initialization of the array. There's no way for "late initialization".

If you want to fill the myarray buffer manually, without strcpy(), you can use:
```sh
myarray[0] = 'a', myarray[1] = 'b', myarray[2] = 'c', myarray[3] = 0;
```
or
```sh
char *ptr = myarray;
*ptr++ = 'a', *ptr++ = 'b', *ptr++ = 'c', *ptr = 0;
```

`" "` is a string (`char \*`) literal. You want `' '` for a single char.

### creat an array of string in C
There are several ways to creat an array of strings in c, of coure not like thecodes below
```sh
char array[] = {"string_1","string_2","..."}
```
If all strings are going to be the same length (or at least have the same maximum length),you simply declare a 2-d array of char and assign as necessary:
```sh
char str[NUMBER_OF_STRINGS][STRING_LENGTH+1];
...
strcpy(strs[0], aString); // where aString is either an array or pointer to char

strcpy[str[1],"foo");
```
