
* https://www.hackerearth.com/practice/algorithms/sorting
----
Question:
1. stable and unstable sorting
   quick sort and select sort are unstable sort.

   The scenario of when to use stable sort and when to use unstable sort? what the difference between them?
2. Time complexity for heap sort.
3. Compare Merge sort with quick sort and merge sort
    Merge sort requires extra space, while the other two don't.

    https://stackoverflow.com/a/28522840/7583919

3.Which fit most in what situation?
  * Bucket sort 

    Bucket sort is mainly useful when the input is uniformly distributed over a range.

-----
# heap sort
`heapSort.c`

original list

```md
             heapify starts at sizeof(array)/sizeof(array[0])/2 -1, which is index 2, the node got the value as 3
      1                           
    /   \
   2     3   -> heapify(hp,2)-> doesn't change ->  heapify(hp,1)
  / \   / \
 7   4  0 -1

      1                           
    /   \    
   7     3   ->  heapify(hp,0)
  / \   / \
 2   4  0 -1

intermediate state
      7                           
    /   \    
   1     3   ->  heapify(hp,largest) #largest is 2
  / \   / \
 2   4  0 -1

      7                           
    /   \    
   4     3     maxheap is complete! postOrderTraversal to testify.
  / \   / \
 2   1  0 -1

postOrderTraversal(0)->7->postOrderTraversal(1)->4->postOrderTraversal(3)->2->postOrderTraversal(4)->1
->postOrderTraversal(2)->3->postOrderTraversal(5)->0->postOrderTraversal(6)->-1

```

Example of bad workflow, better to demonstrate in animation.


