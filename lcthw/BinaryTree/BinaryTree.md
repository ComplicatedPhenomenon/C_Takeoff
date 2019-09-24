# Time Complexity?

**Time complexity** is a description of the asymptotic behavior(渐进行为) of running time as input size tends to infinity.

If you had a function that takes:

    1 millisecond to complete if you have 2 elements.
    2 milliseconds to complete if you have 4 elements.
    3 milliseconds to complete if you have 8 elements.
    4 milliseconds to complete if you have 16 elements.
    ...
    n milliseconds to complete if you have 2**n elements.

Then it takes log<sub>2</sub>(n) time. The [Big O notation](https://stackoverflow.com/questions/487258/what-is-a-plain-english-explanation-of-big-o-notation), loosely speaking, means that the relationship only needs to be true for large n, and that constant factors and smaller terms can be ignored.

![](https://i.stack.imgur.com/ZsiDW.png)

[Big O ](http://bigocheatsheet.com/)

![](http://bigocheatsheet.com/img/big-o-cheat-sheet-poster.png)

* [How to find time complexity of an algorithm？](https://stackoverflow.com/questions/11032015/how-to-find-time-complexity-of-an-algorithm)

* 逻辑严密， 陈述简洁，形象易理解的典范

# Binary tree
There is a difference between a STRICT and FULL BINARY TREE.

**1) FULL BINARY TREE:** A binary tree of height h that contains exactly (2^h)-1 elements is called a full **binary tree**. (Ref: Pg 427, **Data Structures, Algorithms and Applications in C++** [University Press], Second Edition by Sartaj Sahni).

or in other words

In a FULL BINARY TREE each node has exactly 0 or 2 children and all leaf nodes are on the same level.


**For Example:** The following is a FULL BINARY TREE:

              18
           /      \   
         15       30    
        /  \     /   \   
      40    50  100  40



**2) STRICT BINARY TREE:** Each node has exactly 0 or 2 children.

**For example:** The following is a STRICT BINARY TREE:

             18
           /     \   
         15       30    
        /  \          
      40    50



I think there's no confusion in the definition of a Complete Binary Tree, still for the completeness of the post I would like to tell what a Complete Binary Tree is.


**3) COMPLETE BINARY TREE:** A Binary Tree is complete Binary Tree if all levels are completely filled except possibly the last level and the last level has all keys as left as possible.


**For Example:** The following is a COMPLETE BINARY TREE:

               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40
     /  \   /
    8   7  9

**Note:** The following is also a Complete Binary Tree:


             18
           /     \   
         15       30    
        /  \     /   \   
      40    50  100  40

# [Binary search tree](https://www.cs.usfca.edu/~galles/visualization/BST.html)
* https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/tutorial/

  To understand `Tansversal.c`, read the material listed above.

               CT(0)
             /      \   
           CT(1)     CT(2)    
          /    \     /    \   
        CT(3) CT(4) CT(5) CT(6)
              /
            CT(9)

* [Free memory of a binary tree in C](https://stackoverflow.com/questions/9181146/freeing-memory-of-a-binary-tree-c)
