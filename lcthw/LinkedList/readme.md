
```c
return 0;
return -1;
return;
```

[C dynamic memory allocation](https://en.wikipedia.org/wiki/C_dynamic_memory_allocation)

```c
int *ptr;
ptr = malloc(10 * sizeof(*ptr));		/* without a cast */
ptr = (int *)malloc(10 * sizeof(*ptr));	/* with a cast */ 
```

The advantage and disadvantage of type cast.

* Under the C standard, the cast is redundant.
* Including the cast may allow a C program or function to compile as C++. 

### Insert at a specific positon
```c
tCell *temp2 = head; // compare with tCell *temp1 = (tCell *) malloc(sizeof(tCell));
for(int i = 0; i < n-2; i++) temp2 = temp2->next;
temp1->next = temp2->next; 
temp2->next = temp1;
```
Explain the idea with words not visualiation.

* Insert at 1st node:
* Insert at other nodes:
    Broke up the (n-1)th node.
    