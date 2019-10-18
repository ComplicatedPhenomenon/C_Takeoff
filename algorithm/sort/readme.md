```c
int arr[] = {6, 3, 2, 3, 4, 5};
size_t n = sizeof(arr)/sizeof(arr[0]);
int *ascendingArray;
ascendingArray = bubbleSort(arr, n); //Why is n necessary?
```
Because `arr` as a pointer only store the address of the array.

* https://www.hackerearth.com/practice/algorithms/sorting
----
Question:
1. stable and unstable sorting
   quick sort and select sort are unstable sort.

   The scenario of when to use stable sort and when to use unstable sort? what the difference between them?
2. Time complexity for heap sort.
-----
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
   4     3     maxheap is complete! postorderTraversal to testify.
  / \   / \
 2   1  0 -1

postorderTraversal(0)->7->postorderTraversal(1)->4->postorderTraversal(3)->2->postorderTraversal(4)->1
->postorderTraversal(2)->3->postorderTraversal(5)->0->postorderTraversal(6)->-1

7, 3, 2, 1, 3, 0, -1
```

Example of bad workflow, better to demonstrate in animation.
