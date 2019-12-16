# Free memory allocated from heap
To free memory allocated from heap by 
```c
struct TreeNode *t = (struct TreeNode *)calloc(3, sizeof(struct TreeNode));
free(t);
```

![](https://www.geeksforgeeks.org/wp-content/uploads/Free-function-in-c.png)

# Demo of part code from `sametree.c`
![](TreeNode.svg)

# AVL tree
![https://www.geeksforgeeks.org/avl-tree-set-1-insertion/](https://media.geeksforgeeks.org/wp-content/uploads/AVL-Insertion1-1.jpg)


# `BTLevelOrderTraversal_1.c`
When you think you know well enough about pointers, boom, here comes `BTLevelOrderTraversal.c` to improve you are wrong.

Review how to implement a heap by 2 stacks to help understand the more complex usage of pointers.

![](../../figures/implementAHeap.svg)

# `BTLevelOrderTraversal_2.cpp`
![](../../figures/levelOrderTraversal.svg)

# Makefile
Compare to a [bash script](generateABST.sh), you just collect all the bash commands into a file, nothing more. it is feasible when the dependency relation is easy,

with [`Makefile`](Makefile)
* you can generate multiple executable once for all.
* ...

## Reference
* http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
* https://makefiletutorial.com/